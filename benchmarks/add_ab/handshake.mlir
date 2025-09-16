handshake.func @add(%a : i32, %b : i32) -> i32{
    %add = comb.add %a, %b : i32
    return %add: i32
}