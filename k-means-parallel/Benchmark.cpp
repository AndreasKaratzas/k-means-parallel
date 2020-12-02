
#include "Benchmark.h"

/**
 * Launches benchmark.
 *
 * @return the starting timepoint of the K-means algorithm.
 */
std::chrono::time_point<std::chrono::system_clock> init_benchmark(void)
{
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	return start;
}

/**
 * Launches K-means optimization loop benchmark.
 *
 * @return the starting timepoint of the K-means optimization loop.
 *
 * @see kmeans.cpp
 */
std::chrono::time_point<std::chrono::system_clock> bench_convergence(void)
{
	std::chrono::time_point<std::chrono::system_clock> loop_benchmark = std::chrono::system_clock::now();
	return loop_benchmark;
}

/**
 * Computes per-loop benchmark.
 *
 * @param[in] startpoint loop starting time point
 * @param[in] endpoint loop ending time point
 *
 * @return optimization loop benchmark.
 *
 * @see kmeans.cpp
 */
std::chrono::duration<double> bench_loop(std::chrono::time_point<std::chrono::system_clock> startpoint, std::chrono::time_point<std::chrono::system_clock> endpoint)
{
	return endpoint - startpoint;
}

/**
 * Stops K-means benchmark.
 *
 * @return the ending timepoint of the K-means algorithm.
 */
std::chrono::time_point<std::chrono::system_clock> terminate_bench(void)
{
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	return end;
}

/**
 * Computes K-means benchmarking results.
 *
 * @param[in] start the starting timepoint of the K-means algorithm.
 * @param[in] loop_benchmark the starting timepoint of the K-means optimization loop.
 * @param[in] end the ending timepoint of the K-means algorithm.
 *
 * @return a pair with the total execution time of the K-means algorithm in seconds
 *		and the total time in seconds that the algorithm needed to converge.
 */
std::pair<std::chrono::duration<double>, std::chrono::duration<double>> benchmark_results(
	const std::chrono::time_point<std::chrono::system_clock> start,
	const std::chrono::time_point<std::chrono::system_clock> loop_benchmark,
	const std::chrono::time_point<std::chrono::system_clock> end)
{
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::chrono::duration<double> k_means_benchmark = end - loop_benchmark;
	std::pair<std::chrono::duration<double>, std::chrono::duration<double>> bench_res;
	bench_res.first = elapsed_seconds;
	bench_res.second = k_means_benchmark;
	return bench_res;
}
