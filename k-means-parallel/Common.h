/**
 * Common.h
 *
 * In this header file, we define the constants
 * used throughout the K-means algorithm. We also
 * include all the header files necessary to make
 * the implementation work.
 */

#pragma once

#include <iostream>										///< std::cout
#include <vector>										///< std::vector
#include <iomanip>										///< std::setw
#include <limits>										///< std::numeric_limits
#include <chrono>										///< std::chrono
#include <array>										///< std::array    
#include <algorithm>									///< std::copy
#include <utility>										///< std::pair
#include <string>										///< std::string
#include <cstdlib>										///< std::abs
#include <random>										///< std::random_device
#include <fstream>										///< std::ofstream
#include <omp.h>										///< OpenMP Multiprocessing Programming Framework

constexpr int TEST_MODE = 0;							///< Set it equal to 1 to enter test mode, otherwise set it to 0 
constexpr int NUM_THR = 12;								///< Set it to the Number of threads
constexpr int CHUNK_SIZE = (int) (1000/NUM_THR) + 1;	///< Set it to the \ceil{\frac{Nv}{NUM_THR}}
constexpr int VERBOSITY = 3;							///< Sets K-means' iterface verbosity level
constexpr int MAX_LIMIT = TEST_MODE == 1 ? 1023 : 63;	///< Upper bound used in the randomly generated dataset of reals
constexpr int N = TEST_MODE == 1 ? 50 : 100000;			///< Elements in our dataset
constexpr int Nv = TEST_MODE == 1 ? 2 : 1000;			///< Dimentions of each element
constexpr int Nc = TEST_MODE == 1 ? 5 : 100;			///< Number of clusters, also known as `K`
constexpr double THR_KMEANS = 0.000001;					///< Threshold used to indicate K-means convergence