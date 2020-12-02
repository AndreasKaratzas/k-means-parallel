/**
 * Optimize.h
 *
 * In this header file, we define a function which
 * computes the error of the `Center` variable with
 * respect to the `Vec` variable.
 */

#pragma once

#include "Common.h"

void optimize_center(const std::vector<std::array<float, Nv>>& Vec, std::vector<std::array<float, Nv>>& new_Center, const std::array<std::vector<int>, Nc>& Classes);