
#include "Distance.h"

/**
 * Computes Euclidean distance between 2 arrays of size `Nv`.
 *
 * @param[in] A the first array.
 * @param[in] B the second array.
 *
 * @return Euclidean distance.
 */
long double eucl_diff(const std::array<float, Nv>& A, const std::array<float, Nv>& B)
{
	long double eucl_diff = 0;
#pragma omp parallel for simd num_threads(NUM_THR) reduction(+: eucl_diff) schedule(dynamic, CHUNK_SIZE)
	for (int i = 0; i < Nv; i += 1)													///< Loops through all `Nv` elements of the given arrays
	{
		long double point_diff = A[i] - B[i];										///< Computes element-wise difference
		if (point_diff > std::numeric_limits<float>::max())							///< Checks for data overflow
		{
			point_diff = std::numeric_limits<float>::max();							///< Prevents data overflow
		}
		long double point_diff_squared = point_diff * point_diff;					///< Squares difference
		eucl_diff += point_diff_squared;											///< Adds difference to `eucl_diff`
	}
	return eucl_diff;
}

/**
 * Checks if K-means has converged.
 *
 * @param[in] curr_Center the current `Center` variable .
 * @param[in] prev_Center the old `Center` variable.
 *
 * @return Euclidean distance between the 2 vectors.
 *
 * @note if the Euclidean distance between 2 points is not greater than 1.0, then it is normalized to 0.
 *		This is to optimize speed, prevent overfitting, and solve the precision error carried throughout the $Nc \times Nv = 1,000,000$ additions.
 */
long double convergence(const std::vector<std::array<float, Nv>>& curr_Center, const std::vector<std::array<float, Nv>>& prev_Center)
{
	long double convergence_sum = 0;												///< Initializes `convergence_sum` variable used to store the total additive difference between `curr_Center` and `prev_Center`
	for (int i = 0; i < Nc; i += 1)													///< Loops through all centers
	{
		long double tmp_eucl_d = eucl_diff(curr_Center.at(i), prev_Center.at(i));	///< Computes element-wise Euclidean distance
		convergence_sum += tmp_eucl_d > 1.0 ? tmp_eucl_d : 0.0;						///< Optimizes Convergence if error is close to defined threshold
		if (convergence_sum > std::numeric_limits<double>::max())					///< Checks for number overflow
		{
			convergence_sum = std::numeric_limits<double>::max();					///< Prevents number overflow
		}
	}
	return convergence_sum;
}

/**
 * Normalizes the error between current `Center` variable and old `Center` variable.
 *
 * @param[in] curr_iter_conv the current `Center` error.
 * @param[in] prev_iter_conv the old `Center` error.
 * @param[in] iter_counter the loop number.
 *
 * @return normalized Euclidean distance between centers.
 *
 * @note The computation of the normalization formula is explained below:
 *		if the current loop error is less or equal to the number of clusters, then $normalized = 0.0$
 *		if the current iteration of the optimization loop is less or equal to 2, then $normalized = 1.0$
 *		else, $normalized = \frac{\abs{curr_iter_conv - prev_iter_conv}}{\argmax{curr_iter_conv, prev_iter_conv}}$
 */
long double normalize_convergence(const long double curr_iter_conv, const long double prev_iter_conv, const int iter_counter)
{
	return curr_iter_conv > Nc && iter_counter > 2 ? std::abs(curr_iter_conv - prev_iter_conv) / std::max(curr_iter_conv, prev_iter_conv) :
		iter_counter <= 2 ? 1.0 : 0.0;
}