all:
	cmake -B build -DDESIGNAR_INCLUDE_DIR=/Users/frank/Documents/ULA/COMPB2026/DeSiGNAR/include
	cmake --build build --parallel

run: all
	./build/ccirc examples/rc_circuit.ccirc

clean:
	rm -rf build test_*.ccirc