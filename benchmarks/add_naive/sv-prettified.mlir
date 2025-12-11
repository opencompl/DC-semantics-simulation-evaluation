module {
  hw.module @add(in %a : i32, in %a_valid : i1, in %b : i32, in %b_valid : i1, in %clk : !seq.clock, in %rst : i1, in %out0_ready : i1, out a_ready : i1, out b_ready : i1, out out0 : i32, out out0_valid : i1) {
    %false = hw.constant false
    %false_0 = hw.constant false
    %true = hw.constant true
    %0 = comb.xor %12, %true : i1
    %1 = comb.and %5, %0 : i1
    %emitted_0 = seq.compreg sym @emitted_0 %1, %clk reset %rst, %false_0 : i1  
    %2 = comb.xor %emitted_0, %true : i1
    %3 = comb.and %2, %a_valid : i1
    %4 = comb.and %16, %3 : i1
    %5 = comb.or %4, %emitted_0 {sv.namehint = "done0"} : i1
    %6 = comb.xor %12, %true : i1
    %7 = comb.and %11, %6 : i1
    %emitted_1 = seq.compreg sym @emitted_1 %7, %clk reset %rst, %false_0 : i1  
    %8 = comb.xor %emitted_1, %true : i1
    %9 = comb.and %8, %a_valid : i1
    %10 = comb.and %16, %9 : i1
    %11 = comb.or %10, %emitted_1 {sv.namehint = "done1"} : i1
    %12 = comb.and %5, %11 {sv.namehint = "allDone"} : i1
    %13 = comb.extract %a from 0 : (i32) -> i31
    %14 = comb.concat %13, %false : i31, i1
    %15 = comb.and %b_valid, %9, %3 : i1
    %16 = comb.and %out0_ready, %15 : i1
    %17 = comb.add %14, %b : i32
    hw.output %12, %16, %17, %15 : i1, i1, i32, i1
  }
}

