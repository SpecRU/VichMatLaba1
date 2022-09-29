#include "les.h"
#include "gauss.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    //https://www.youtube.com/watch?v=l0DG4keob-8
    les a(5, "input.txt");
    a.lesOut("output.txt");
    gauss b;
    b.lesOut(b.lesIterSol(a.matrixOut(), a.koefOut()), "output.txt");
}