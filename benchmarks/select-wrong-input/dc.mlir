module {
  hw.module @add(in %input : !dc.value<i1>, out out0 : !dc.token) {
    %c20 = hw.constant 20 : i32
    %c30 = hw.constant 30 : i32
    %true, %false = dc.branch %sel
    %packtrue= dc.pack %true, %c20 : i32
    %packfalse = dc.pack %ffalse, %c30 : i32
    %out= dc.select %input, %packtrue, %packfalse : !dc.token
    hw.output %out : !dc.value<i32>
  }
}

