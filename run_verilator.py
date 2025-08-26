import os 
import subprocess 
import argparse

TIMEOUT_SEC = 1800

VERILOG_SIM_FOLDER_NAME = "obj_dir/"

def run_command(cmd, log_file, timeout=TIMEOUT_SEC):
    try:
        print(cmd)
        ret_code = subprocess.Popen(
            cmd, stdout=log_file, stderr=log_file, shell=True
        ).wait(timeout=timeout)
        return ret_code
    except subprocess.TimeoutExpired:
        log_file.truncate(0)
        log_file.write(f"timeout of {timeout} seconds reached\n")
        print(f"{log_file} - timeout of {timeout} seconds reached")

def generate_testbench(folder_path):
    testbench_file = open(os.path.join(folder_path, "main.cpp"), "w")
    testbench_file.write('#include "Vmodule.h"\n')
    testbench_file.write('#include "verilated.h"\n')
    testbench_file.write('#include <stdio.h>\n\n')
    testbench_file.write('int main(int argc, char** argv) {\n')
    testbench_file.write('    VerilatedContext* contextp = new VerilatedContext;\n')
    testbench_file.write('    contextp->commandArgs(argc, argv);\n')
    testbench_file.write('    Vmodule* top = new Vmodule{contextp};\n')
    testbench_file.write('    for (int i = 0; i < 10; i++){\n')
    testbench_file.write('        printf("Evaluating circuit with input %d\\n", i);\n')
    testbench_file.write('        if (top->a_ready) {\n')
    testbench_file.write('            top->a = i;\n')
    testbench_file.write('            top->a_valid = 1;\n')
    testbench_file.write('            top->eval(); \n')
    testbench_file.write('            printf("Output: %d\\n", top->out0);\n')
    testbench_file.write('        }\n')
    testbench_file.write('        else {\n')
    testbench_file.write('            top->eval();\n')
    testbench_file.write('            printf("Output: %d\\n", top->out0);\n')
    testbench_file.write('        }\n')
    testbench_file.write('    }\n')
    testbench_file.write('    delete top;\n')
    testbench_file.write('    delete contextp;\n')
    testbench_file.write('    return 0;\n')
    testbench_file.write('}\n')
    testbench_file.close()



# #include "Vadd__02dno__02dpack__02dexport.h"
# #include "verilated.h"
# #include <stdio.h>

# int main(int argc, char** argv) {
#     VerilatedContext* contextp = new VerilatedContext;
#     contextp->commandArgs(argc, argv);
#     Vadd__02dno__02dpack__02dexport* top = new Vadd__02dno__02dpack__02dexport{contextp};
#     for (int i = 0; i < 10; i++){
#         printf("Evaluating circuit with input %d\n", i);
#.      if (a -> a_ready]) {
#           top->a = i;
#           top->a_valid = 1;
#           top->eval(); 
#         
#         printf("Output: %d\n", top->out0);
#     }
#     delete top;
#     delete contextp;
#     return 0;
# }

def run_verilator(folder_path):
    
    generate_testbench(folder_path)
    cmd = f"cd {folder_path}; verilator --cc -exe -build module.v main.cpp"
    print(cmd)
    log_file = open(os.path.join(folder_path, "log_files/verilator.log"), "w")
    ret_code = run_command(cmd, log_file)
    log_file.close()
    if ret_code != 0:
        print(f"Verilator failed, see {folder_path}/verilator.log for details")
        return  

def main():
    parser = argparse.ArgumentParser()

    parser.add_argument(
        "-i",
        "--input",
        type=str,
        required = True,
        help="Name of the folder containing the file to lower and simulate.",
    )

    args = parser.parse_args()

    run_verilator(args.input)


if __name__ == "__main__":
    main()