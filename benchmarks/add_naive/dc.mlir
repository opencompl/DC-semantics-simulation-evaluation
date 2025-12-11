module {
  hw.module @add(in %a : !dc.value<i32>, in %b : !dc.value<i32>, in %clk : !seq.clock {dc.clock}, in %rst : i1 {dc.reset}, out out0 : !dc.value<i32>) {
    %token, %output = dc.unpack %a : !dc.value<i32>
    %token_0, %output_1 = dc.unpack %a : !dc.value<i32>
    %0 = dc.join %token, %token_0
    %1 = comb.add %output, %output_1 : i32
    %2 = dc.pack %0, %1 : i32
    %token_2, %output_3 = dc.unpack %2 : !dc.value<i32>
    %token_4, %output_5 = dc.unpack %b : !dc.value<i32>
    %3 = dc.join %token_2, %token_4
    %4 = comb.add %output_3, %output_5 : i32
    %5 = dc.pack %3, %4 : i32
    hw.output %5 : !dc.value<i32>
  }
}

