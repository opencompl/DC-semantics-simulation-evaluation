module {
  hw.module @add(in %a : !dc.value<i32>, in %b : !dc.value<i32>, in %clk : !seq.clock {dc.clock}, in %rst : i1 {dc.reset}, out out0 : !dc.value<i32>) {
    %token, %output = dc.unpack %a : !dc.value<i32>
    %0:2 = dc.fork [2] %token 
    %1 = dc.pack %0#0, %output : i32
    %2 = dc.pack %0#1, %output : i32
    %token_0, %output_1 = dc.unpack %2 : !dc.value<i32>
    %token_2, %output_3 = dc.unpack %1 : !dc.value<i32>
    %3 = dc.join %token_0, %token_2
    %4 = comb.add %output_1, %output_3 : i32
    %5 = dc.pack %3, %4 : i32
    %token_4, %output_5 = dc.unpack %5 : !dc.value<i32>
    %token_6, %output_7 = dc.unpack %b : !dc.value<i32>
    %6 = dc.join %token_4, %token_6
    %7 = comb.add %output_5, %output_7 : i32
    %8 = dc.pack %6, %7 : i32
    hw.output %8 : !dc.value<i32>
  }
}

