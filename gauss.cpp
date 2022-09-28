#include "gauss.h"

std::vector<double> gauss::lesIterSol(std::vector<std::vector<double>> matrix, std::vector<double> koef)
{
    //https://ru.stackoverflow.com/questions/1040332/Метод-итераций-вычисления-СЛАУ-объяснение-реализации-алгоритма
    const double acc = 0.000001;
    double x[matrix.size()];
    double x0[matrix.size()];
    double E[matrix.size()];
    double max = 0;

    for (int i = 0; i < matrix.size(); i++)
        x0[i] = koef[i];
    int counter = 0;
    do
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            x[i] = 0;
            for (int j = 0; j < matrix.size(); j++)
            {
                x[i] += matrix.at(i)[j] * x0[j];
            }
            x[i] += koef[i];
            E[i] = fabs(x[i] - x0[i]);
        }
        max = 0;
        int i;
        for (i = 0; i < matrix.size(); i++)
        {
            if (max < E[i]) max = E[i];
            x0[i] = x[i];
        }
        counter++;
    } while (max > acc);
    for (int i = 0; i < matrix.size(); i++)
        std::cout << "x" << i + 1 << "=" << x[i] << " " << std::endl;
}

std::vector <double> gauss::lesSol(std::vector<std::vector<double>> matrix, std::vector <double> koef)
{
    std::vector <double> res;
    res.resize(matrix.size());

    int lpos, iter = 0;
    double max;
    const double acc = 0.000001;
    while (iter < matrix.size())
    {
        max = abs(matrix.at(iter)[iter]);
        lpos = iter;
        for (int i = iter + 1; i < matrix.size(); ++i)
        {
            if (abs(matrix.at(i)[iter]) > max)
            {
                max = abs(matrix.at(i)[iter]);
                lpos = i;
            }
        }
        if (max < acc)
        {
            std::cout << "Решение СЛАУ невозможно из-за нулевого столбца " << lpos << " матрицы" << std::endl;
            return { 0 };
        }
        for (int i = 0; i < matrix.size(); ++i)
        {
            double temp = matrix.at(iter)[i];
            matrix.at(iter)[i] = matrix.at(lpos)[i];
            matrix.at(lpos)[i] = temp;
        }
        double temp = koef[iter];
        koef[iter] = koef[lpos];
        koef[lpos] = temp;
        for (int i = iter; i < matrix.size(); ++i)
        {
            double temp = matrix.at(i)[iter];
            if (abs(temp) < acc) continue;
            for (int k = 0; k < matrix.size(); ++k) matrix.at(i)[k] /= temp; 
            koef[i] /= temp;
            if (i == iter) continue;
            for (int k = 0; k < matrix.size(); ++k) matrix.at(i)[k] -= matrix.at(iter)[k]; 
            koef[i] -= koef[iter];
        }
        iter++;
    }
    for (int i = matrix.size() - 1; i >= 0; --i)
    {
        res[i] = koef[i];
        for (int k = 0; k < i; k++) koef[k] -= matrix.at(k)[i] * res[i]; 
    }   
    return res;
}

void gauss::lesOut(std::vector <double> res, std::string path)
{
    if (res.size() > 1) {
        std::ofstream out(path, std::ios_base::app);
        if (out.is_open()) {
            out << std::endl;
            for (int i = 0; i < res.size(); ++i) out << "x" << i << " = " << res[i] << std::endl;
        }
        out.close();
    }
}
