#include <iostream>
#include <math.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;


// Задание 1
// Написать перегруженные шаблоны функций для нахождения корней линейного(a * x + b = 0) 
// и квадратного(a * x^2 + b * x + c = 0) уравнений.
// Замечание: в функции передаются коэффициенты уравнений.
template<typename T>
void calcEquation(T a, T b)
{
    if (a == 0)
    {
        if (b == 0) { cout << "Ошибка: Уравнение имеет бесконечное множество решений!" << endl; }
        else { cout << "Ошибка: Уравнение не имеет решений!" << endl; }
    }
    else 
    {
        T x = -b / a;
        cout << "x = " << x << endl;
    }
}

template<typename T>
void calcEquation(T a, T b, T c)
{
    if (a == 0)
    {
        calcEquation(b, c);
        return;
    }

    T D = pow(b, 2) - 4 * a * c;

    if (D < 0) { cout << "Нет решения." << endl; }
    else if (D == 0)
    {
        T x = -b / (2 * a);
        cout << "x = " << x << endl;
    }
    else
    {
        T x1 = (-b + sqrt(D)) / (2 * a);
        T x2 = (-b - sqrt(D)) / (2 * a);
        cout << "x1 = "   << x1 
             << "\nx2 = " << x2 << endl;
    }
}


// Задание 2
// Напишите шаблон функции, которая возвращает максимум из двух переданных параметров.
template<typename T>
T getMax(T a, T b)
{
    return (a > b) ? a : b;
}


// Задание 3
// Напишите шаблон функции, которая находит минимальное значение в массиве 
// и возвращает одновременно найденное минимальное значение и его позицию в массиве.
template<typename T>
int findMin(const T* arr, int size, T& min)
{
    int idx = 0;
    min = INT_MAX;

    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            idx = i;
        }
    }
    return idx;
}


int main()
{
    int a = 2, b = 4;
    double a1 = 1, b1 = 10.2, c1 = 2;
    cout << "Задание 1." << endl;
    calcEquation(a, b);             // 2x + 4 = 0
    calcEquation(a1, b1, c1);       // x^2 + 10.2x + 2 = 0
    cout << endl;

    cout << "--------------------------------------------------" << endl;
    cout << "Задание 2." << endl;
    double num1 = 5.123, num2 = 18.78;
    cout << getMax(num1, num2) << endl;
    cout << endl;

    cout << "--------------------------------------------------" << endl;
    cout << "Задание 3." << endl;
    int arr[] = { 5, 2, 8, 4, 3, 1, 9, 6, 7 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int min;
    int pos = findMin(arr, size, min);

    cout << "Минимальное значение:\t" << min << endl;
    cout << "Позиция в массиве:\t" << pos << endl;
}