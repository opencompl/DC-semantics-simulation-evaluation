module {
  hw.module @add(in %a : !esi.channel<i32>, in %b : !esi.channel<i32>, in %clk : !seq.clock {dc.clock}, in %rst : i1 {dc.reset}, out out0 : !esi.channel<i32>) {
    %false = hw.constant false
    %rawOutput, %valid = esi.unwrap.vr %a, %ready : i32
    %c0_i0 = hw.constant 0 : i0
    %chanOutput, %ready = esi.wrap.vr %c0_i0, %valid : i0
    %rawOutput_0, %valid_1 = esi.unwrap.vr %chanOutput, %12 : i0
    %c0_i0_2 = hw.constant 0 : i0
    %chanOutput_3, %ready_4 = esi.wrap.vr %c0_i0_2, %3 : i0
    %c0_i0_5 = hw.constant 0 : i0
    %chanOutput_6, %ready_7 = esi.wrap.vr %c0_i0_5, %9 : i0
    %false_8 = hw.constant false
    %true = hw.constant true
    %0 = comb.xor %12, %true : i1
    %1 = comb.and %5, %0 : i1
    %emitted_0 = seq.compreg sym @emitted_0 %1, %clk reset %rst, %false_8 : i1  
    %2 = comb.xor %emitted_0, %true : i1
    %3 = comb.and %2, %valid_1 : i1
    %4 = comb.and %ready_4, %3 : i1
    %5 = comb.or %4, %emitted_0 {sv.namehint = "done0"} : i1
    %6 = comb.xor %12, %true : i1
    %7 = comb.and %11, %6 : i1
    %emitted_1 = seq.compreg sym @emitted_1 %7, %clk reset %rst, %false_8 : i1  
    %8 = comb.xor %emitted_1, %true : i1
    %9 = comb.and %8, %valid_1 : i1
    %10 = comb.and %ready_7, %9 : i1
    %11 = comb.or %10, %emitted_1 {sv.namehint = "done1"} : i1
    %12 = comb.and %5, %11 {sv.namehint = "allDone"} : i1
    %13 = comb.extract %rawOutput from 0 : (i32) -> i31
    %14 = comb.concat %13, %false : i31, i1
    %rawOutput_9, %valid_10 = esi.unwrap.vr %b, %ready_13 : i32
    %c0_i0_11 = hw.constant 0 : i0
    %chanOutput_12, %ready_13 = esi.wrap.vr %c0_i0_11, %valid_10 : i0
    %rawOutput_14, %valid_15 = esi.unwrap.vr %chanOutput_12, %16 : i0
    %rawOutput_16, %valid_17 = esi.unwrap.vr %chanOutput_6, %16 : i0
    %rawOutput_18, %valid_19 = esi.unwrap.vr %chanOutput_3, %16 : i0
    %c0_i0_20 = hw.constant 0 : i0
    %chanOutput_21, %ready_22 = esi.wrap.vr %c0_i0_20, %15 : i0
    %15 = comb.and %valid_15, %valid_17, %valid_19 : i1
    %16 = comb.and %ready_22, %15 : i1
    %17 = comb.add %14, %rawOutput_9 : i32
    %rawOutput_23, %valid_24 = esi.unwrap.vr %chanOutput_21, %ready_26 : i0
    %chanOutput_25, %ready_26 = esi.wrap.vr %17, %valid_24 : i32
    hw.output %chanOutput_25 : !esi.channel<i32>
  }
}

