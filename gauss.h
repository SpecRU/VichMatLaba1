#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class gauss {
public:
	gauss();
	std::vector <double> lesSol(std::vector<std::vector<double>> matrix, std::vector<double> koef);
	void lesOut(std::vector<double> res, std::string path);
};