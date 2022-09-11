#include "les.h"

les::les(int a, int b, std::string path)
{
	std::ifstream inp(path);
	matrix.resize(a);
	double dtmp;

	if (inp.is_open()) {
		for (int i = 0; i < a; ++i) {
			for (int k = 0; k < b; ++k) {
				inp >> dtmp;
				matrix.at(i).push_back(dtmp);
			}
			inp >> dtmp;
			koef.push_back(dtmp);
		}
	}
	else;
	inp.close();
}

void les::lesOut(std::string path)
{
	std::ofstream out(path);
	if (out.is_open()) {
		for (int i = 0; i < matrix.size(); ++i) {
			for (int k = 0; k < matrix.at(i).size(); ++k) {
				out << "x" << k << "*(" << matrix.at(i)[k] << ") ";
				if (k + 1 < matrix.at(i).size()) out << "+ ";
			}
			out << "= " << koef[i] << std::endl;
		}
	}
	out.close();
}

std::vector<std::vector<double>> les::matrixOut()
{
	return matrix;
}

std::vector<double> les::koefOut()
{
	return koef;
}
