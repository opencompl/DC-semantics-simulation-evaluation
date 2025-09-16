module {
  hw.module @add(in %a : i32, in %a_valid : i1, in %b : i32, in %b_valid : i1, in %clk : !seq.clock, in %rst : i1, in %out0_ready : i1, out a_ready : i1, out b_ready : i1, out out0 : i32, out out0_valid : i1) {
    %chanOutput, %ready = esi.wrap.vr %b, %b_valid : i32
    %chanOutput_0, %ready_1 = esi.wrap.vr %a, %a_valid : i32
    %rawOutput, %valid = esi.unwrap.vr %chanOutput_0, %ready_3 : i32
    %c0_i0 = hw.constant 0 : i0
    %chanOutput_2, %ready_3 = esi.wrap.vr %c0_i0, %valid : i0
    %rawOutput_4, %valid_5 = esi.unwrap.vr %chanOutput, %ready_8 : i32
    %c0_i0_6 = hw.constant 0 : i0
    %chanOutput_7, %ready_8 = esi.wrap.vr %c0_i0_6, %valid_5 : i0
    %rawOutput_9, %valid_10 = esi.unwrap.vr %chanOutput_2, %1 : i0
    %rawOutput_11, %valid_12 = esi.unwrap.vr %chanOutput_7, %1 : i0
    %c0_i0_13 = hw.constant 0 : i0
    %chanOutput_14, %ready_15 = esi.wrap.vr %c0_i0_13, %0 : i0
    %0 = comb.and %valid_10, %valid_12 : i1
    %1 = comb.and %ready_15, %0 : i1
    %2 = comb.add %rawOutput, %rawOutput_4 : i32
    %rawOutput_16, %valid_17 = esi.unwrap.vr %chanOutput_14, %ready_19 : i0
    %chanOutput_18, %ready_19 = esi.wrap.vr %2, %valid_17 : i32
    %rawOutput_20, %valid_21 = esi.unwrap.vr %chanOutput_18, %out0_ready : i32
    hw.output %ready_1, %ready, %rawOutput_20, %valid_21 : i1, i1, i32, i1
  }
}

