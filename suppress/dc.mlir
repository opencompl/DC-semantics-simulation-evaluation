module {
  hw.module @test_suppress(in %arg0 : !dc.value<i32>, in %arg1 : !dc.value<i1>, in %clk : !seq.clock {dc.clock}, in %rst : i1 {dc.reset}, out out0 : !dc.value<i32>) {
    %token, %output = dc.unpack %arg1 : !dc.value<i1>
    %token_0, %output_1 = dc.unpack %arg0 : !dc.value<i32>
    %0 = dc.join %token, %token_0
    %1 = dc.pack %0, %output : i1
    %trueToken, %falseToken = dc.branch %1
    %2 = dc.pack %trueToken, %output_1 : i32
    %3 = dc.pack %falseToken, %output_1 : i32
    %token_2, %output_3 = dc.unpack %2 : !dc.value<i32>
    dc.sink %token_2
    hw.output %3 : !dc.value<i32>
  }
}

