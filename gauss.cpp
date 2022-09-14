#include "gauss.h"

gauss::gauss(){
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
        // Поиск строки с максимальным matrix.at(i)[iter]
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
        // Перестановка строк
        if (max < acc)
        {
            // Нет ненулевых диагональных элементов
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
        // Нормализация уравнений (создание треугольника + 1-чной диагонали)
        for (int i = iter; i < matrix.size(); ++i)
        {
            //делим на диагональное число для 1
            double temp = matrix.at(i)[iter];
            if (abs(temp) < acc) continue; // для нулевого коэффициента пропустить
            for (int k = 0; k < matrix.size(); ++k) matrix.at(i)[k] /= temp; 
            koef[i] /= temp;
            //вычитаем текущую линию (iter) из остальных для 0 (1 - 1)
            if (i == iter) continue; // уравнение не вычитать само из себя
            for (int k = 0; k < matrix.size(); ++k) matrix.at(i)[k] -= matrix.at(iter)[k]; 
            koef[i] -= koef[iter];
        }
        iter++;
    }
    // обратная подстановка
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
