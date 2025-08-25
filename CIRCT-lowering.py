import os 
import subprocess 
import argparse

TIMEOUT_SEC = 1800

CIRCT_DIR_PATH = "~/build/circt/build/bin"

class LoweringPass:
    def __init__(self, name, command, output_name):
        self.name = name
        self.command = command
        self.output_name = output_name

LOWERING_PASSES = [
    LoweringPass("handshake_to_dc", "--lower-handshake-to-dc", "dc.mlir"),
    LoweringPass("materialize_forks_sinks", "--dc-materialize-forks-sinks", "dc-materialized.mlir"),
    LoweringPass("canonicalize", "--canonicalize", "dc-canonicalized.mlir"),
    LoweringPass("dc_to_hw", "--lower-dc-to-hw", "hw.mlir"),
    LoweringPass("lower_esi_ports", "--lower-esi-ports", "hw-esi-lowered.mlir"),
    LoweringPass("lower_esi_to_hw", "--lower-esi-to-hw", "hw-esi-hw.mlir"),
    LoweringPass("hw_to_sv", "--lower-hw-to-sv", "sv.mlir"),
    LoweringPass("prettify_verilog", "--prettify-verilog", "sv-prettified.mlir"),
    LoweringPass("seq_to_sv", "--lower-seq-to-sv", "sv-seq-lowered.mlir"),
    LoweringPass("export_verilog", "--export-verilog", "module.v"),
]

def clear_lowering_directory(folder_path, input_file): 
    """
    Create clean directories to store the lowered files.
    """
    for fname in os.listdir(folder_path):
        file_path = os.path.join(folder_path, fname)
        if fname != input_file and os.path.isfile(file_path):
            os.remove(file_path)

def run_command(cmd, log_file, timeout=TIMEOUT_SEC):
    try:
        print(cmd)
        ret_code = subprocess.Popen(
            cmd, cwd=CIRCT_DIR_PATH, stdout=log_file, stderr=log_file, shell=True
        ).wait(timeout=timeout)
        return ret_code
    except subprocess.TimeoutExpired:
        log_file.truncate(0)
        log_file.write(f"timeout of {timeout} seconds reached\n")
        print(f"{log_file} - timeout of {timeout} seconds reached")

def lower(folder_path, entry): 
    if entry == "handshake": 
        current_file = "handshake.mlir"
        start = 0
    elif entry == "dc": 
        start = 1
        current_file = "dc.mlir"
    else:
        raise ValueError("Unknown entry point " + entry)

    for i in range(start, len(LOWERING_PASSES)):
        lowering_pass = LOWERING_PASSES[i]
        input_path = os.path.join(folder_path, current_file)
        cmd = f"circt-opt {input_path} {lowering_pass.command} -o {folder_path}/{lowering_pass.output_name}" 
        log_file = os.path.join(folder_path, f"{lowering_pass.name}.log")
        ret_code = run_command(cmd, open(log_file, "w"))
        if ret_code != 0:
            print(f"Lowering failed at pass {lowering_pass.name}, see {log_file} for details")
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

    group = parser.add_mutually_exclusive_group(required=True)
    group.add_argument(
        "--dc",
        action="store_const",
        dest="entry",
        const="dc",
        help="Set entry point for the lowering to `dc`.",
    )
    group.add_argument(
        "--handshake",
        action="store_const",
        dest="entry",
        const="handshake",
        help="Set entry point for the lowering to `handshake`.",
    )

    args = parser.parse_args()

    lower(args.input, args.entry)


if __name__ == "__main__":
    main()