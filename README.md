# Optimizing-Performance-of-Matrix-Multiplication-Using-Performance-Counters

Implemented six different versions of matrix multiplication programs and compared there performance in terms of L1/L2/L3
Cache misses, TLB misses, Page Faults, Branch Misses, CPI (Cycles Per Instruction), etc.

These metrics were obtained using hardware performance counters (via perf).

Implemented tiled/blocked versions of the program to optimize memory access pattern and improve performance.
