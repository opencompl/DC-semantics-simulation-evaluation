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

def run_verilator(folder_path):


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