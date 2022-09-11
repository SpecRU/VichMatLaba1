#include "gauss.h"

gauss::gauss(){
}

std::vector <double> gauss::lesSol(std::vector<std::vector<double>> matrix, std::vector <double> koef)
{
    std::vector <double> res;
    res.resize(matrix.size());

    int pos, iter = 0;
    double max;
    const double acc = 0.0001;
    while (iter < matrix.size())
    {
        // ����� ������ � ������������ matrix.at(i)[iter]
        max = abs(matrix.at(iter)[iter]);
        pos = iter;
        for (int i = iter + 1; i < matrix.size(); ++i)
        {
            if (abs(matrix.at(i)[iter]) > max)
            {
                max = abs(matrix.at(i)[iter]);
                pos = i;
            }
        }
        // ������������ �����
        if (max < acc)
        {
            // ��� ��������� ������������ ���������
            std::cout << "������� ���� ���������� ��-�� �������� ������� " << pos << " �������" << std::endl;
            return { 0 };
        }
        for (int j = 0; j < matrix.size(); ++j)
        {
            double temp = matrix.at(iter)[j];
            matrix.at(iter)[j] = matrix.at(pos)[j];
            matrix.at(pos)[j] = temp;
        }
        double temp = koef[iter];
        koef[iter] = koef[pos];
        koef[pos] = temp;
        // ������������ ���������
        for (int i = iter; i < matrix.size(); ++i)
        {
            double temp = matrix.at(i)[iter];
            if (abs(temp) < acc) continue; // ��� �������� ������������ ����������
            for (int j = 0; j < matrix.size(); ++j)
                matrix.at(i)[j] = matrix.at(i)[j] / temp;
            koef[i] = koef[i] / temp;
            if (i == iter)  continue; // ��������� �� �������� ���� �� ����
            for (int j = 0; j < matrix.size(); ++j)
                matrix.at(i)[j] = matrix.at(i)[j] - matrix.at(iter)[j];
            koef[i] = koef[i] - koef[iter];
        }
        iter++;
    }
    // �������� �����������
    for (iter = matrix.size() - 1; iter >= 0; --iter)
    {
        res[iter] = koef[iter];
        for (int i = 0; i < iter; i++)
        koef[i] = koef[i] - matrix.at(i)[iter] * res[iter];
    }
    return res;
}

void gauss::lesOut(std::vector <double> res, std::string path)
{
    if (res.size() > 1) {
        std::ofstream out(path, std::ios_base::app);
        if (out.is_open()) {
            out << std::endl;
            for (int i = 0; i < res.size(); ++i) {
                out << "x" << i << " = " << res[i] << std::endl;
            }
        }
        out.close();
    }
}
