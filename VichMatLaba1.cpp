#include "les.h"
#include "gauss.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    les a(3, 3, "input.txt");
    a.lesOut("output.txt");
    gauss b;
    b.lesOut(b.lesSol(a.matrixOut(), a.koefOut()), "output.txt");
}