module {
  hw.module @add(in %a : !esi.channel<i32>, in %b : !esi.channel<i32>, in %clk : !seq.clock {dc.clock}, in %rst : i1 {dc.reset}, out out0 : !esi.channel<i32>) {
    %rawOutput, %valid = esi.unwrap.vr %a, %ready : i32
    %c0_i0 = hw.constant 0 : i0
    %chanOutput, %ready = esi.wrap.vr %c0_i0, %valid : i0
    %rawOutput_0, %valid_1 = esi.unwrap.vr %b, %ready_4 : i32
    %c0_i0_2 = hw.constant 0 : i0
    %chanOutput_3, %ready_4 = esi.wrap.vr %c0_i0_2, %valid_1 : i0
    %rawOutput_5, %valid_6 = esi.unwrap.vr %chanOutput, %1 : i0
    %rawOutput_7, %valid_8 = esi.unwrap.vr %chanOutput_3, %1 : i0
    %c0_i0_9 = hw.constant 0 : i0
    %chanOutput_10, %ready_11 = esi.wrap.vr %c0_i0_9, %0 : i0
    %0 = comb.and %valid_6, %valid_8 : i1
    %1 = comb.and %ready_11, %0 : i1
    %2 = comb.add %rawOutput, %rawOutput_0 : i32
    %rawOutput_12, %valid_13 = esi.unwrap.vr %chanOutput_10, %ready_15 : i0
    %chanOutput_14, %ready_15 = esi.wrap.vr %2, %valid_13 : i32
    hw.output %chanOutput_14 : !esi.channel<i32>
  }
}

