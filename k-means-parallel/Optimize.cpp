
#include "Optimize.h"

/**
 * Computes `Center` variable after `Classes` correction.
 *
 * @param[in] Vec the dataset.
 * @param[in] Classes the classes corresponding to the dataset.
 * @param[in, out] new_Center the new clusters of the K-means algorithm.
 */
void optimize_center(const std::vector<std::array<float, Nv>>& Vec, std::vector<std::array<float, Nv>>& new_Center, const std::array<std::vector<int>, Nc>& Classes)
{
#pragma omp parallel for num_threads(NUM_THR) schedule(dynamic, 10)
	for (int i = 0; i < Nc; i += 1)															///< Loops through all clusters
	{
		std::array<float, Nv> Element = { 0.0 };											///< Initializes `Element` array which holds a cluster vector
		for (int j = 0; j < Classes[i].size(); j += 1)										///< Loops through `Vec` vectors
		{
#pragma omp simd
			for (int k = 0; k < Nv; k += 1)													///< Loops through vector elements
			{
				Element[k] += (float)(Vec.at(Classes[i].at(j))[k] / Classes[i].size());		///< Computes vector element
			}
		}
		new_Center.at(i) = Element;															///< Updates `new_Center` variable											
	}
}