
#include "Center.h"

/**
 * Initializes `Center` variable.
 *
 * @param[in] Vec the dataset generated.
 * @param[in, out] old_Center the random centroids generated in the beginning of the K-means algorithm.
 *
 * @remark [<random> Engines and Distributions](https:///<docs.microsoft.com/en-us/cpp/standard-library/random?view=msvc-160#engdist)
 */
void init_centers(std::vector<std::array<float, Nv>>& old_Center)
{
	std::random_device rd_Center;                                            ///< Initializes a random generator
	std::mt19937 mt_Center(rd_Center());                                     ///< Uses the mt19937 engine
	std::uniform_real_distribution<float> dist_Center(0.0, MAX_LIMIT + 0.0); ///< Generates a uniform distribution bounded by the `MAX_LIMIT` set in `Common.h` to prevent number overflow
	for (int i = 0; i < Nc; i += 1)
	{
		std::array<float, Nv> Elements;                                        ///< Declares a vector `Elements` that temporarily holds the vector that is to be inserted to `old_Center`
#pragma omp simd
		for (int j = 0; j < Nv; j += 1)
		{
			Elements[j] = dist_Center(mt_Center);                                ///< Updates contents of `Elements`
		}
		old_Center.emplace_back(Elements);                                     ///< Moves `Elements` to `old_Center`
	}
}