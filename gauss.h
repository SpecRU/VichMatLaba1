#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class gauss {
public:
	gauss() = default;
	std::vector <double> lesIterSol(std::vector<std::vector<double>> matrix, std::vector<double> koef);
	std::vector <double> lesGaussSol(std::vector<std::vector<double>> matrix, std::vector<double> koef);
	void lesOut(std::vector<double> res, std::string path);
};