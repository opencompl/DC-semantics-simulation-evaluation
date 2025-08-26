// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vmodule__pch.h"

//============================================================
// Constructors

Vmodule::Vmodule(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vmodule__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , a_valid{vlSymsp->TOP.a_valid}
    , b_valid{vlSymsp->TOP.b_valid}
    , rst{vlSymsp->TOP.rst}
    , out0_ready{vlSymsp->TOP.out0_ready}
    , a_ready{vlSymsp->TOP.a_ready}
    , b_ready{vlSymsp->TOP.b_ready}
    , out0_valid{vlSymsp->TOP.out0_valid}
    , a{vlSymsp->TOP.a}
    , b{vlSymsp->TOP.b}
    , out0{vlSymsp->TOP.out0}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vmodule::Vmodule(const char* _vcname__)
    : Vmodule(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vmodule::~Vmodule() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vmodule___024root___eval_debug_assertions(Vmodule___024root* vlSelf);
#endif  // VL_DEBUG
void Vmodule___024root___eval_static(Vmodule___024root* vlSelf);
void Vmodule___024root___eval_initial(Vmodule___024root* vlSelf);
void Vmodule___024root___eval_settle(Vmodule___024root* vlSelf);
void Vmodule___024root___eval(Vmodule___024root* vlSelf);

void Vmodule::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmodule::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vmodule___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vmodule___024root___eval_static(&(vlSymsp->TOP));
        Vmodule___024root___eval_initial(&(vlSymsp->TOP));
        Vmodule___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vmodule___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vmodule::eventsPending() { return false; }

uint64_t Vmodule::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vmodule::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vmodule___024root___eval_final(Vmodule___024root* vlSelf);

VL_ATTR_COLD void Vmodule::final() {
    Vmodule___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vmodule::hierName() const { return vlSymsp->name(); }
const char* Vmodule::modelName() const { return "Vmodule"; }
unsigned Vmodule::threads() const { return 1; }
void Vmodule::prepareClone() const { contextp()->prepareClone(); }
void Vmodule::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vmodule::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vmodule::trace()' called on model that was Verilated without --trace option");
}
