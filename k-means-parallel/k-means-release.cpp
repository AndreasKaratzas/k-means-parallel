#include "kmeans.h"

/**
 * Implements K-means clustering algorithm.
 *
 * @return 0, if the executable was terminated normally.
 *
 */
int main(void)
{
	std::chrono::time_point<std::chrono::system_clock> loop_benchmark, prev_loop_benchmark, start;			///< Initializes loop-wise benchmark variables
	std::cout.precision(std::numeric_limits<float>::max_digits10);											///< Sets output precision for long doubles
	prev_loop_benchmark = start = init_benchmark();															///< Starts custom benchmark
	std::vector<std::array<float, Nv>> Vec;																	///< Initializes the `Vec` variable
	std::array<std::vector<int>, Nc> Classes;																///< Initializes `Classes` variable, which holds all cluster pointers
	std::vector<std::array<float, Nv>> old_Center;															///< Initializes `old_Center` variable, which holds centroids
	std::vector<std::array<float, Nv>> new_Center(Nc);														///< Initializes the `new_Center` variable, which holds optimized centroids
	long double iter_conv = std::numeric_limits<double>::infinity();										///< Initializes `iter_conv` variable, which holds the sum of distances betweens `Vec` and `new_Center`
	long double norm_iter_conv = std::numeric_limits<double>::infinity();									///< Initializes `norm_iter_conv` variable, which holds the normalized value of `iter_conv`
#pragma omp parallel num_threads(2)
	{
#pragma omp master
		{
			Vec.reserve(N);																					///< Reserves `N` blocks of memory to increase speed
			vec_init(Vec);																					///< Fills `Vec` with random real numbers
		}
#pragma omp single
		{
			old_Center.reserve(Nc);																			///< Reserves `Nc` blocks of memory to increase speed
			init_centers(old_Center);																		///< Fills `old_Center` with random vectors from `Vec`
		}
	}
	std::chrono::time_point<std::chrono::system_clock> optimization_benchmark = init_benchmark();			///< K-means optimization loop benchmark 
	for (int iter_counter = 1; norm_iter_conv > THR_KMEANS; iter_counter += 1)								///< K-means optimazation loop
	{
		std::chrono::duration<double> bench_res =
			bench_loop(prev_loop_benchmark, loop_benchmark = init_benchmark());								///< Benchmarks loop
		kmeans_progress(iter_counter, iter_conv, norm_iter_conv, bench_res, VERBOSITY);						///< Outputs K-means progress
		compute_classes(Vec, old_Center, Classes);															///< Re-computes `Classes` contents
		optimize_center(Vec, new_Center, Classes);															///< Computes error of current clusters and stores it to the variable `new_Center`
		long double prev_iter_conv = iter_conv;																///< Stores previous `iter_conv` to use it to normalize convergence
		iter_conv = convergence(new_Center, old_Center);													///< Computes convergence of current K-means loop
		norm_iter_conv = normalize_convergence(iter_conv, prev_iter_conv, iter_counter);					///< Normalizes `iter_conv` to avoid overfitting
		old_Center.swap(new_Center);																		///< Swaps `old_Center` with `new_Center` to start the next loop
	}
	std::chrono::time_point<std::chrono::system_clock> end = terminate_bench();								///< Initializes the endpoint of K-means benchmark
	std::pair<std::chrono::duration<double>, std::chrono::duration<double>> bench_res =
		benchmark_results(start, optimization_benchmark, end);												///< Stores benchmark results
	kmeans_termination(bench_res, norm_iter_conv);															///< Outputs benchmark results
	return 0;
}