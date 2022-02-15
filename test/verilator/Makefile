MODULE = sram

run: obj_dir/V$(MODULE)
	@obj_dir/V$(MODULE)

obj_dir/V$(MODULE):
	verilator --cc -Wno-fatal --trace --exe  --build $(MODULE)_tb.cpp ../../src/*.v  --top-module $(MODULE)

clean: 
	rm -rf obj_dir
	rm *.vcd