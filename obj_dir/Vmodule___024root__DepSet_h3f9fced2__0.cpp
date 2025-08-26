// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmodule.h for the primary calling header

#include "Vmodule__pch.h"
#include "Vmodule___024root.h"

VL_INLINE_OPT void Vmodule___024root___ico_sequent__TOP__0(Vmodule___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmodule__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmodule___024root___ico_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ add__DOT___GEN_0;
    add__DOT___GEN_0 = 0;
    CData/*0:0*/ add__DOT___GEN_1;
    add__DOT___GEN_1 = 0;
    CData/*0:0*/ add__DOT___GEN_2;
    add__DOT___GEN_2 = 0;
    // Body
    vlSelf->out0 = (VL_SHIFTL_III(32,32,32, vlSelf->a, 1U) 
                    + vlSelf->a);
    add__DOT___GEN_0 = ((~ (IData)(vlSelf->add__DOT__emitted_0)) 
                        & (IData)(vlSelf->a_valid));
    add__DOT___GEN_2 = ((~ (IData)(vlSelf->add__DOT__emitted_2)) 
                        & (IData)(vlSelf->a_valid));
    add__DOT___GEN_1 = ((~ (IData)(vlSelf->add__DOT__emitted_1)) 
                        & (IData)(vlSelf->a_valid));
    vlSelf->out0_valid = ((IData)(add__DOT___GEN_0) 
                          & ((IData)(vlSelf->b_valid) 
                             & ((IData)(add__DOT___GEN_2) 
                                & (IData)(add__DOT___GEN_1))));
    vlSelf->b_ready = ((IData)(vlSelf->out0_ready) 
                       & (IData)(vlSelf->out0_valid));
    vlSelf->add__DOT__done0 = (((IData)(vlSelf->b_ready) 
                                & (IData)(add__DOT___GEN_0)) 
                               | (IData)(vlSelf->add__DOT__emitted_0));
    vlSelf->add__DOT__done1 = (((IData)(vlSelf->b_ready) 
                                & (IData)(add__DOT___GEN_1)) 
                               | (IData)(vlSelf->add__DOT__emitted_1));
    vlSelf->add__DOT__done2 = (((IData)(vlSelf->b_ready) 
                                & (IData)(add__DOT___GEN_2)) 
                               | (IData)(vlSelf->add__DOT__emitted_2));
    vlSelf->a_ready = ((IData)(vlSelf->add__DOT__done0) 
                       & ((IData)(vlSelf->add__DOT__done1) 
                          & (IData)(vlSelf->add__DOT__done2)));
}

void Vmodule___024root___eval_ico(Vmodule___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmodule__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmodule___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vmodule___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vmodule___024root___eval_triggers__ico(Vmodule___024root* vlSelf);

bool Vmodule___024root___eval_phase__ico(Vmodule___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmodule__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmodule___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vmodule___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vmodule___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vmodule___024root___eval_act(Vmodule___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmodule__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmodule___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vmodule___024root___nba_sequent__TOP__0(Vmodule___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmodule__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmodule___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ add__DOT___GEN_0;
    add__DOT___GEN_0 = 0;
    CData/*0:0*/ add__DOT___GEN_1;
    add__DOT___GEN_1 = 0;
    CData/*0:0*/ add__DOT___GEN_2;
    add__DOT___GEN_2 = 0;
    // Body
    vlSelf->add__DOT__emitted_2 = ((~ (IData)(vlSelf->rst)) 
                                   & ((IData)(vlSelf->add__DOT__done2) 
                                      & (~ (IData)(vlSelf->a_ready))));
    vlSelf->add__DOT__emitted_1 = ((~ (IData)(vlSelf->rst)) 
                                   & ((IData)(vlSelf->add__DOT__done1) 
                                      & (~ (IData)(vlSelf->a_ready))));
    vlSelf->add__DOT__emitted_0 = ((~ (IData)(vlSelf->rst)) 
                                   & ((IData)(vlSelf->add__DOT__done0) 
                                      & (~ (IData)(vlSelf->a_ready))));
    add__DOT___GEN_2 = ((~ (IData)(vlSelf->add__DOT__emitted_2)) 
                        & (IData)(vlSelf->a_valid));
    add__DOT___GEN_1 = ((~ (IData)(vlSelf->add__DOT__emitted_1)) 
                        & (IData)(vlSelf->a_valid));
    add__DOT___GEN_0 = ((~ (IData)(vlSelf->add__DOT__emitted_0)) 
                        & (IData)(vlSelf->a_valid));
    vlSelf->out0_valid = ((IData)(add__DOT___GEN_0) 
                          & ((IData)(vlSelf->b_valid) 
                             & ((IData)(add__DOT___GEN_2) 
                                & (IData)(add__DOT___GEN_1))));
    vlSelf->b_ready = ((IData)(vlSelf->out0_ready) 
                       & (IData)(vlSelf->out0_valid));
    vlSelf->add__DOT__done0 = (((IData)(vlSelf->b_ready) 
                                & (IData)(add__DOT___GEN_0)) 
                               | (IData)(vlSelf->add__DOT__emitted_0));
    vlSelf->add__DOT__done1 = (((IData)(vlSelf->b_ready) 
                                & (IData)(add__DOT___GEN_1)) 
                               | (IData)(vlSelf->add__DOT__emitted_1));
    vlSelf->add__DOT__done2 = (((IData)(vlSelf->b_ready) 
                                & (IData)(add__DOT___GEN_2)) 
                               | (IData)(vlSelf->add__DOT__emitted_2));
    vlSelf->a_ready = ((IData)(vlSelf->add__DOT__done0) 
                       & ((IData)(vlSelf->add__DOT__done1) 
                          & (IData)(vlSelf->add__DOT__done2)));
}

void Vmodule___024root___eval_nba(Vmodule___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmodule__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmodule___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vmodule___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vmodule___024root___eval_triggers__act(Vmodule___024root* vlSelf);

bool Vmodule___024root___eval_phase__act(Vmodule___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmodule__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmodule___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vmodule___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vmodule___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vmodule___024root___eval_phase__nba(Vmodule___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmodule__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmodule___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vmodule___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmodule___024root___dump_triggers__ico(Vmodule___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vmodule___024root___dump_triggers__nba(Vmodule___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vmodule___024root___dump_triggers__act(Vmodule___024root* vlSelf);
#endif  // VL_DEBUG

void Vmodule___024root___eval(Vmodule___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmodule__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmodule___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vmodule___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("benchmarks/add/module.v", 2, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vmodule___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vmodule___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("benchmarks/add/module.v", 2, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vmodule___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("benchmarks/add/module.v", 2, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vmodule___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vmodule___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vmodule___024root___eval_debug_assertions(Vmodule___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmodule__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmodule___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->a_valid & 0xfeU))) {
        Verilated::overWidthError("a_valid");}
    if (VL_UNLIKELY((vlSelf->b_valid & 0xfeU))) {
        Verilated::overWidthError("b_valid");}
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->out0_ready & 0xfeU))) {
        Verilated::overWidthError("out0_ready");}
}
#endif  // VL_DEBUG
