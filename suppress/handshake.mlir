handshake.func @test_suppress(%arg0: i32, %arg1: i1) -> (i32) {
    %0:2 = cond_br %arg1, %arg0 : i32
    sink %0#0 : i32
    return %0#1 : i32
}