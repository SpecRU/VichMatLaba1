#pragma once
#include <vector>
#include <fstream>
#include <string>

class les {
	std::vector <std::vector <double>> matrix;
	std::vector <double> koef;
public:
	les(int a, std::string path);
	void lesOut(std::string path);
	std::vector <std::vector <double>> matrixOut();
	std::vector<double> koefOut();
};