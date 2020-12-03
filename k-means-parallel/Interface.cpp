
#include "Interface.h"

/**
 * Prints the contents of a vector of arrays.
 *
 * @param[in] Obj the vector of arrays.
 * @param[in] obj_name the name of the variable.
 *
 * @note This function helps in printing the contents of the variables `Vec`, `old_Centers` and `new_Centers`.
 */
void multidimentional_float_vector_interface(const std::vector<std::array<float, Nv>>& Obj, std::string Obj_name)
{
	for (int i = 0; i < Obj.size(); i += 1)
	{
		for (int j = 0; j < Obj.at(i).size(); j += 1)
		{
			std::cout << std::setw(11) << Obj_name << "[" << i << "][" << j << "]:\t" << std::setw(18) << Obj.at(i)[j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;
}

/**
 * Prints the contents of an array of vectors.
 *
 * @param[in] Obj the array of vectors.
 * @param[in] obj_name the name of the variable.
 *
 * @note This function helps in printing the contents of the variable `Classes`.
 */
void multidimentional_int_array_interface(const std::array<std::vector<int>, Nc>& Obj, std::string Obj_name)
{
	for (int i = 0; i < Obj.size(); i += 1)
	{
		for (int j = 0; j < Obj[i].size(); j += 1)
		{
			std::cout << Obj_name << "[" << i << "][" << j << "]: " << std::setw(4) << Obj[i].at(j) << " ";
			if (j % 6 == 0 && j != 0)
			{
				std::cout << std::endl;
			}
		}
		std::cout << std::endl << std::endl;
	}
	std::cout << std::endl << std::endl;
}

/**
 * Prints the progress of the K-means algorithm.
 *
 * @param[in] iter_counter the current loop number.
 * @param[in] iter_conv the current loop error.
 * @param[in] norm_iter_conv the current normalized loop error.
 * @param[in] loop_benchmark the current loop benchmark
 */
void progress_interface(const int iter_counter, const long double iter_conv, const long double norm_iter_conv, const std::chrono::duration<double> loop_benchmark)
{
	std::cout << "Iteration: " << std::setw(2) << iter_counter
		<< "\tError: " << std::setw(std::numeric_limits<float>::max_digits10) << iter_conv
		<< "\tNormalized error: " << std::setw(std::numeric_limits<float>::max_digits10) << norm_iter_conv
		<< "\tLoop checkpoint: " << std::setw(std::numeric_limits<double>::max_digits10) << loop_benchmark.count();
	TEST_MODE == 1 ? (std::cout << std::endl << std::endl << std::endl) : std::cout << std::endl;
}

/**
 * Calls `progress_interface` function to print K-means progress.
 *
 * @param[in] iter_counter the current loop number.
 * @param[in] norm_iter_conv the current normalized loop error.
 * @param[in] iter_conv the current loop error.
 * @param[in] loop_benchmark the current loop benchmark
 * @param[in] verbose the frequency used for activating the interface
 *		if equal to 0, then `progress_interface` is called every 4 loops
 *		if equal to 1, then `progress_interface` is called every 3 loops
 *		if equal to 2, then `progress_interface` is called every 2 loops
 *		if equal to 3, then `progress_interface` is called in every loop
 *
 * @see `progress_interface`
 */
void kmeans_progress(const int iter_counter, const long double iter_conv, const long double norm_iter_conv, const std::chrono::duration<double> loop_benchmark, const int verbose)
{
	switch (verbose)
	{
	case 0: if (iter_counter % 4 == 0) { progress_interface(iter_counter, iter_conv, norm_iter_conv, loop_benchmark); }
		  break;
	case 1: if (iter_counter % 3 == 0) { progress_interface(iter_counter, iter_conv, norm_iter_conv, loop_benchmark); }
		  break;
	case 2: if (iter_counter % 2 == 0) { progress_interface(iter_counter, iter_conv, norm_iter_conv, loop_benchmark); }
		  break;
	case 3: if (iter_counter % 1 == 0) { progress_interface(iter_counter, iter_conv, norm_iter_conv, loop_benchmark); }
		  break;
	default:
		break;
	}
}

/**
 * Prints the resuts of the K-means algorithm.
 *
 * @param[in] bench_results the benchmarking results.
 * @param[in] iter_conv the final normalized K-means error.
 *
 * @see `Benchmark.h`
 */
void kmeans_termination(const std::pair<std::chrono::duration<double>, std::chrono::duration<double>> bench_results, const long double iter_conv)
{
	std::cout << std::endl
		<< std::setw(18) << "[TOTAL TIME] " << std::setw(15) << bench_results.first.count()
		<< " {IN SECONDS}" << std::endl
		<< std::setw(18) << "[K-MEANS BENCH] " << std::setw(15) << bench_results.second.count()
		<< " {IN SECONDS}" << std::endl
		<< std::setw(18) << "[CONVERGENCE] " << std::setw(15) << iter_conv << std::endl;
}
