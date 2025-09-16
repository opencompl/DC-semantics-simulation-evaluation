module {
  hw.module @add(in %a : i32, in %a_valid : i1, in %b : i32, in %b_valid : i1, in %clk : !seq.clock, in %rst : i1, in %out0_ready : i1, out a_ready : i1, out b_ready : i1, out out0 : i32, out out0_valid : i1) {
    %0 = comb.and %a_valid, %b_valid : i1
    %1 = comb.and %out0_ready, %0 : i1
    %2 = comb.add %a, %b : i32
    hw.output %1, %1, %2, %0 : i1, i1, i32, i1
  }
}

