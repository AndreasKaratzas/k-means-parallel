/**
 * Vec.h
 *
 * In this header file, we define a function that
 * executes only in the beginning of the algorithm.
 * This function is used to generate a random dataset
 * for the K-means algorithm.
 */

#pragma once

#include "Common.h"

void vec_init(std::vector<std::array<float, Nv>>& Vec);