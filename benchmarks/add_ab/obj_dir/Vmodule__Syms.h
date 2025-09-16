// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VMODULE__SYMS_H_
#define VERILATED_VMODULE__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vmodule.h"

// INCLUDE MODULE CLASSES
#include "Vmodule___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vmodule__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vmodule* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vmodule___024root              TOP;

    // CONSTRUCTORS
    Vmodule__Syms(VerilatedContext* contextp, const char* namep, Vmodule* modelp);
    ~Vmodule__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
