
#include "Class.h"

/**
 * Computes `Class` variable.
 *
 * @param[in] Vec the dataset generated.
 * @param[in] old_Center the current centroids.
 * @param[in, out] Classes the classes corresponding to the dataset.
 *
 * @note This function calls `eucl_diff` from Distance.h
 *
 * @see [K-means clustering Algorithm](https:///<medium.com/@jaredchilders_38839/k-means-clustering-algorithm-4334db89bdf3)
 */
void compute_classes(const std::vector<std::array<float, Nv>>& Vec, const std::vector<std::array<float, Nv>>& old_Center, std::array<std::vector<int>, Nc>& Classes)
{
#pragma omp parallel for num_threads(NUM_THR) schedule(dynamic, 10)
	for (int i = 0; i < Nc; i += 1)                                                     ///< Clears contents of `Classes` variable
	{
		Classes[i].clear();                                                         ///< Prevents garbage processing
		Classes[i].reserve((int)N / Nc);                                            ///< Optimizes array with high probability
	}
	int argmin_idx = -1;                                                                ///< Initializes \argmin index
	long double argmin_val = std::numeric_limits<long int>::max() + 0.0;                ///< Initializes \argmin value
#pragma omp parallel for simd num_threads(NUM_THR) firstprivate(argmin_idx, argmin_val) schedule(dynamic, 1000) 
	for (int i = 0; i < N; i += 1)                                                      ///< Loop through `Vec`
	{
		for (int j = 0; j < Nc; j += 1)                                             ///< Loop through `old_Center`
		{
			long double temp_eucl_dist = eucl_diff(Vec.at(i), old_Center.at(j));///< Compute Euclidean distance between parsed `Vec` element and parsed `old_Center` element
			if (argmin_val > temp_eucl_dist)                                    ///< Checks if this Euclidean distance is so far the smallest 
			{
				argmin_val = temp_eucl_dist;                                ///< Updates \argmin value
				argmin_idx = j;                                             ///< Updates \argmin index
			}
		}
#pragma omp critical
			Classes[argmin_idx].emplace_back(i);
		argmin_idx = -1;                                                            ///< Sets \argmin index for the next loop
		argmin_val = std::numeric_limits<unsigned long int>::max();                 ///< Sets \argmin value for the next loop
	}
}
