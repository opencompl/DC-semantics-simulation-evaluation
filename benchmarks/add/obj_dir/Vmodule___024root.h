// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmodule.h for the primary calling header

#ifndef VERILATED_VMODULE___024ROOT_H_
#define VERILATED_VMODULE___024ROOT_H_  // guard

#include "verilated.h"


class Vmodule__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vmodule___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(a_valid,0,0);
    VL_IN8(b_valid,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(out0_ready,0,0);
    VL_OUT8(a_ready,0,0);
    VL_OUT8(b_ready,0,0);
    VL_OUT8(out0_valid,0,0);
    CData/*0:0*/ add__DOT__done2;
    CData/*0:0*/ add__DOT__done1;
    CData/*0:0*/ add__DOT__done0;
    CData/*0:0*/ add__DOT__emitted_0;
    CData/*0:0*/ add__DOT__emitted_1;
    CData/*0:0*/ add__DOT__emitted_2;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(a,31,0);
    VL_IN(b,31,0);
    VL_OUT(out0,31,0);
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vmodule__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vmodule___024root(Vmodule__Syms* symsp, const char* v__name);
    ~Vmodule___024root();
    VL_UNCOPYABLE(Vmodule___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
