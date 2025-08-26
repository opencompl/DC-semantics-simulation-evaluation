#include "Vmodule.h"      
#include "verilated.h"    
#include <iostream>       

#define TIME_BOUND 25

vluint64_t main_time = 0;

double sc_time_stamp() {
    return main_time;
}

int main(int argc, char** argv) {
    VerilatedContext* contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
    Vmodule* top = new Vmodule{contextp};

    std::cout << "Simulation starting..." << std::endl;

   // reset circuit
    top->rst = 1;
    top->clk = 0;
    top->eval();

    int data_to_send = 0;
    bool is_sending = false; 

    while (main_time < TIME_BOUND) {
        // only check positive clock edge
        if ((main_time % 2) == 1) {
            
            // Check if a successful transaction just happened
            if (is_sending && top->a_ready) {
                std::cout << "Cycle " << main_time / 2 
                          << ": Handshake successful for value " << (data_to_send -1) << "." << std::endl;
                is_sending = false; 
                top->a_valid = 0;   
            }
            
            // Start a new transaction if not sending already
            if (!is_sending) {
                std::cout << "Cycle " << main_time / 2 
                          << ": Presenting value " << data_to_send << " and asserting valid." << std::endl;
                top->a = data_to_send;
                top->a_valid = 1;
                is_sending = true;
                data_to_send++; 
            }
            // wait if circuit is not ready
            else if (is_sending && !top->a_ready) {
                 std::cout << "Cycle " << main_time / 2 << ": Waiting for ready..." << std::endl;
            }
            // print output if ready
            if (top->out0_valid) {
                 std::cout << "Cycle " << main_time / 2 
                           << ": Output valid with value: " << top->out0 << std::endl;
            }
        }
        
        top->clk = !top->clk;
        top->eval();
        main_time++;
    }

    top->final();
    delete top;
    delete contextp;
    return 0;
}