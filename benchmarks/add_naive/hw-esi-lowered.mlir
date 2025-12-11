module {
  hw.module @add(in %a : i32, in %a_valid : i1, in %b : i32, in %b_valid : i1, in %clk : !seq.clock, in %rst : i1, in %out0_ready : i1, out a_ready : i1, out b_ready : i1, out out0 : i32, out out0_valid : i1) {
    %chanOutput, %ready = esi.wrap.vr %b, %b_valid : i32
    %chanOutput_0, %ready_1 = esi.wrap.vr %a, %a_valid : i32
    %false = hw.constant false
    %rawOutput, %valid = esi.unwrap.vr %chanOutput_0, %ready_3 : i32
    %c0_i0 = hw.constant 0 : i0
    %chanOutput_2, %ready_3 = esi.wrap.vr %c0_i0, %valid : i0
    %rawOutput_4, %valid_5 = esi.unwrap.vr %chanOutput_2, %12 : i0
    %c0_i0_6 = hw.constant 0 : i0
    %chanOutput_7, %ready_8 = esi.wrap.vr %c0_i0_6, %3 : i0
    %c0_i0_9 = hw.constant 0 : i0
    %chanOutput_10, %ready_11 = esi.wrap.vr %c0_i0_9, %9 : i0
    %false_12 = hw.constant false
    %true = hw.constant true
    %0 = comb.xor %12, %true : i1
    %1 = comb.and %5, %0 : i1
    %emitted_0 = seq.compreg sym @emitted_0 %1, %clk reset %rst, %false_12 : i1  
    %2 = comb.xor %emitted_0, %true : i1
    %3 = comb.and %2, %valid_5 : i1
    %4 = comb.and %ready_8, %3 : i1
    %5 = comb.or %4, %emitted_0 {sv.namehint = "done0"} : i1
    %6 = comb.xor %12, %true : i1
    %7 = comb.and %11, %6 : i1
    %emitted_1 = seq.compreg sym @emitted_1 %7, %clk reset %rst, %false_12 : i1  
    %8 = comb.xor %emitted_1, %true : i1
    %9 = comb.and %8, %valid_5 : i1
    %10 = comb.and %ready_11, %9 : i1
    %11 = comb.or %10, %emitted_1 {sv.namehint = "done1"} : i1
    %12 = comb.and %5, %11 {sv.namehint = "allDone"} : i1
    %13 = comb.extract %rawOutput from 0 : (i32) -> i31
    %14 = comb.concat %13, %false : i31, i1
    %rawOutput_13, %valid_14 = esi.unwrap.vr %chanOutput, %ready_17 : i32
    %c0_i0_15 = hw.constant 0 : i0
    %chanOutput_16, %ready_17 = esi.wrap.vr %c0_i0_15, %valid_14 : i0
    %rawOutput_18, %valid_19 = esi.unwrap.vr %chanOutput_16, %16 : i0
    %rawOutput_20, %valid_21 = esi.unwrap.vr %chanOutput_10, %16 : i0
    %rawOutput_22, %valid_23 = esi.unwrap.vr %chanOutput_7, %16 : i0
    %c0_i0_24 = hw.constant 0 : i0
    %chanOutput_25, %ready_26 = esi.wrap.vr %c0_i0_24, %15 : i0
    %15 = comb.and %valid_19, %valid_21, %valid_23 : i1
    %16 = comb.and %ready_26, %15 : i1
    %17 = comb.add %14, %rawOutput_13 : i32
    %rawOutput_27, %valid_28 = esi.unwrap.vr %chanOutput_25, %ready_30 : i0
    %chanOutput_29, %ready_30 = esi.wrap.vr %17, %valid_28 : i32
    %rawOutput_31, %valid_32 = esi.unwrap.vr %chanOutput_29, %out0_ready : i32
    hw.output %ready_1, %ready, %rawOutput_31, %valid_32 : i1, i1, i32, i1
  }
}

