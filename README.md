# DC-semantics-simulation-evaluation
In this repository we simulate the semantics of the DC dialect with verilator and (1) compare it against the semantics we mechanize with Lean-MLIR (2) assess the verification efforts at Handshake vs. DC level.  

## Dependencies

### Verilator 
If verilator is not in your path, you can install it with `apt-get install verilator`. 

### Lowering `handshake` to `DC` with CIRCT

To lower one of the tests: 
```python
python3 CIRCT-lowering.py <input_folder>
```

