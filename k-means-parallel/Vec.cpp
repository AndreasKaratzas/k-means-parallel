
#include "Vec.h"

/**
 * Initializes `Vec` variable.
 *
 * @param[in, out] Vec the random dataset generated for clustering using the K-means algorithm.
 *
 * @see Common.h
 *
 * @remark [<random> Engines and Distributions](https://docs.microsoft.com/en-us/cpp/standard-library/random?view=msvc-160#engdist)
 */
void vec_init(std::vector<std::array<float, Nv>>& Vec)
{
	std::random_device rd_Vec;												///< Initializes a random generator
	std::mt19937 mt_Vec(rd_Vec());											///< Uses the mt19937 engine
	std::uniform_real_distribution<float> dist_Vec(0.0, MAX_LIMIT + 0.0);	///< Generates a uniform distribution bounded by the `MAX_LIMIT` set in `Common.h` to prevent number overflow
	for (int i = 0; i < N; i += 1)
	{
		std::array<float, Nv> Elements;										///< Declares a vector `Elements` that temporarily holds the vector that is to be inserted to `Vwc`
#pragma omp simd
		for (int j = 0; j < Nv; j += 1)
		{
			Elements[j] = dist_Vec(mt_Vec);									///< Updates contents of `Elements`
		}
		Vec.emplace_back(Elements);											///< Moves `Elements` to `Vec`
	}
}