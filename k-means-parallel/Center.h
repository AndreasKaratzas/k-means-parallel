/**
 * Center.h
 *
 * In this header file, we define a function that helps
 * in the random initialization of the variable `Center`.
 * This function is only used in the beginning of the
 * K-means algorithm.
 */

#pragma once

#include "Common.h"
#include "Distance.h"

void init_centers(std::vector<std::array<float, Nv>>& old_Center);