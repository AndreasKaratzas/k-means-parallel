/**
 * Benchmark.h
 *
 * In this header file, we define some functions that help us
 * benchmark some crucial parts of the K-means algorithm. Using
 * these functions, we can benchmark the K-means runtime, as well as
 * how long did it take for our implementation to converge.
 */

#pragma once

#include "Common.h"

std::chrono::time_point<std::chrono::system_clock> init_benchmark(void);
std::chrono::time_point<std::chrono::system_clock> bench_convergence(void);
std::chrono::duration<double> bench_loop(std::chrono::time_point<std::chrono::system_clock>, std::chrono::time_point<std::chrono::system_clock>);
std::chrono::time_point<std::chrono::system_clock> terminate_bench(void);
std::pair<std::chrono::duration<double>, std::chrono::duration<double>> benchmark_results(std::chrono::time_point<std::chrono::system_clock> start, std::chrono::time_point<std::chrono::system_clock> loop_benchmark, std::chrono::time_point<std::chrono::system_clock> end);