
# Matrix Multiplication Performance Evaluation

This project contains multiple C files implementing different versions of a standard O(n^3) matrix multiplication program. 

The objective of this project is to evaluate the performance of three different versions of a standard matrix multiplication algorith. These versions are tested on two matrix sizes: 2048x2048 and 8192x8192, with variations in memory management (using large pages) and tiling (blocked multiplication).

We measure performance using performance counters, focusing on cache misses, TLB misses, page faults, and more. This helps in correlating execution time with memory hierarchy performance. The experiments involve:

## Files
- **mul_ijk.c, mul_jik.c, mul_kij.c**: Implements matrix multiplication using the `i,j,k`, `j,i,k`, and `k,i,j` loop orders, respectively.

- **mul_ijk8192.c, mul_jik8192.c, mul_kij8192.c**: Same as above, but optimized for matrices of size `8192x8192`.

- **mul_ijk_b.c, mul_jik_b.c, mul_kij_b.c**: Making use of large pages (2MB) for the matrix multiplication using the `i,j,k`, `j,i,k`, and `k,i,j` loop orders, respectively.

- **mul_ijk_b8192.c, mul_jik_b8192.c, mul_kij_b8192.c**: Same as above, but optimized for matrices of size `8192x8192`.

- **mul_ijk_c.c, mul_jik_c.c, mul_kij_c.c**: Implements blocked (tiled) matrix multiplication with a tile size of 64.

- **mul_ijk_c8192.c, mul_jik_c8192.c, mul_kij_c8192.c**: Blocked matrix multiplication for 8192x8192 matrices.

## Compilation and Execution

To compile all the matrix multiplication versions, a Makefile is provided.

- Open a terminal and navigate to the project folder:

	cd /path/to/multiply
	
- Use the following command to compile the source files:

	make
	
- To run the executables files, run the following command

	./mul_ijk.out

Below are the available targets:

- `make`: Compiles all versions of matrix multiplication.
- `make clean`: Cleans the object files and executables.
- `make <version>`: Compiles a specific version of matrix multiplication, where `<version>` can be:
  - `ijk`, `jik`, `kij`
  - `ijk_b`, `jik_b`, `kij_b`
  - `ijk_c`, `jik_c`, `kij_c`
  - `ijk8192`, `jik8192`, `kij8192`
  - `ijk_b8192`, `jik_b8192`, `kij_b8192`
  - `ijk_c8192`, `jik_c8192`, `kij_c8192`
  
## Performance Evaluation

The performance of each version can be evaluated using performance monitoring tools like perf to measure events like cache misses, TLB misses, and page faults. 
These measurements are key to correlating the memory hierarchy performance with the execution time of each version.

## Author
- Piyush Kumar
- Ritika 

