
#include "Validation.h"

static std::vector<std::pair<int, long double>> kmeans_progress;             ///< Variable used to store K-means progress

/**
 * Exports the contents of a vector of arrays to a CSV file.
 *
 * @param[in] Obj the vector of arrays.
 * @param[in] filename the name of file.
 *
 * @note This function helps in exporting the contents of the variables `Vec`, `old_Centers` and `new_Centers`.
 */
void export_multidimentional_float_vector(const std::vector<std::array<float, Nv>> Obj, std::string filename)
{
	std::ofstream export_stream;                                               ///< Defines an output file stream
	export_stream.open("./data/" + filename + ".csv");                         ///< Associates `export_stream` with a CSV file named after the `filename` variable
	for (int i = 0; i < Obj.size(); i += 1)                                    ///< Loops through `Obj`
	{
		for (int j = 0; j < Obj.at(i).size(); j += 1)                            ///< Loops through the elements of the array inside `Obj` that is being parsed
		{
			export_stream << Obj.at(i)[j] << (j < Obj.at(i).size() - 1 ? "," : "");///< Exports element of that array to the `export_stream` file stream
		}
		export_stream << std::endl;
	}
	export_stream.close();                                                     ///< Closes file stream
}

/**
 * Exports the contents of an array of vectors into a CSV file.
 *
 * @param[in] Obj the array of vectors.
 * @param[in] filename the name of file.
 *
 * @note This function helps in printing the contents of the variable `Classes`.
 */
void export_multidimentional_integer_array(const std::array<std::vector<int>, Nc> Obj, std::string filename)
{
	std::ofstream export_stream;                                               ///< Defines an output file stream
	export_stream.open("./data/" + filename + ".csv");                         ///< Associates `export_stream` with a CSV file named after the `filename` variable
	for (int i = 0; i < Obj.size(); i += 1)                                    ///< Loops through `Obj`
	{
		for (int j = 0; j < Obj[i].size(); j += 1)                               ///< Loops through the elements of the vector inside `Obj` that is being parsed
		{
			export_stream << Obj[i].at(j) << (j < Obj.at(i).size() - 1 ? "," : "");///< Exports element of that vector to the `export_stream` file stream
		}
		export_stream << std::endl;
	}
	export_stream.close();                                                     ///< Closes file stream
}

/**
 * Updates `kmeans_progress` variable, which will be used to export data about K-means progress.
 *
 * @param[in] iter_counter the current loop number.
 * @param[in] norm_iter_conv the current normalized loop error.
 */
void track_kmeans_progress(int iter_counter, long double norm_iter_conv)
{
	kmeans_progress.push_back(std::make_pair(iter_counter, norm_iter_conv));
}

/**
 * Exports the contents of the `kmeans_progress` variable into a CSV file.
 *
 * @param[in] filename the name of file.
 */
void export_kmeans_progress(std::string filename)
{
	std::ofstream export_stream;                                               ///< Defines an output file stream
	export_stream.open("./data/" + filename + ".txt");                         ///< Associates `export_stream` with a CSV file named after the `filename` variable
	for (int i = 0; i < kmeans_progress.size(); i += 1)                        ///< Loops through `kmeans_progress`
	{
		export_stream <<
			"Iteration: " << kmeans_progress.at(i).first <<
			"Convergence: " << kmeans_progress.at(i).second << std::endl;          ///< Exports an element of `kmeans_progress` vector to the `export_stream` file stream
	}
	export_stream.close();                                                     ///< Closes file stream
}