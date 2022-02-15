#include "Vsram.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <stdio.h>

#define MAX_SIM_TIME 500

int main(int argc, char** argv, char** env){
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    VerilatedVcdC *gtkw = new VerilatedVcdC;

    Vsram* sram = new Vsram;
    sram->trace(gtkw, 90);
    gtkw->open("sram.vcd");
    int i = 0;
    int j = 0;
    int clk, addra, dina;
    clk = 0;
    addra = 0;
    sram->clka = 0;
    while(addra <= 100 && j < MAX_SIM_TIME){
        if(j % 2 == 0 && j != 0 && clk > 2){
            addra += 4;
        }
        sram->addra = addra;
        sram->ena = 1;
        sram->wea = 0;
        sram->clka = !sram->clka;
        sram->eval();
        gtkw->dump(clk);
        if(j % 2){
            printf("[Test] addr: 0x%x, data: 0x%x\n", sram->addra, sram->douta);
        }
        j++;
        clk++;
    }
    if(Verilated::gotFinish())
        exit(0);
    gtkw->close();
    exit(0);

    return 0;
}