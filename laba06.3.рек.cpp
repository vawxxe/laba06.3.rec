
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;


// 1. ЗВИЧАЙНІ РЕКУРСИВНІ ФУНКЦІЇ


// Створення масиву
void Create(int a[], int n, int i = 0)
{
    if (i >= n)
        return;

    a[i] = rand() % 101 - 50;

    Create(a, n, i + 1);
}

// Виведення масиву
void Print(const int a[], int n, int i = 0)
{
    if (i >= n)
    {
        cout << endl;
        return;
    }

    cout << setw(5) << a[i];

    Print(a, n, i + 1);
}

// Підрахунок непарних елементів
int CountOdd(const int a[], int n, int i = 0)
{
    if (i >= n)
        return 0;

    int count = (a[i] % 2 != 0) ? 1 : 0;

    return count + CountOdd(a, n, i + 1);
}


// 2. ШАБЛОННІ РЕКУРСИВНІ ФУНКЦІЇ


// Створення масиву
template <typename T>
void CreateTemplate(T a[], int n, int i = 0)
{
    if (i >= n)
        return;

    a[i] = static_cast<T>(rand() % 101 - 50);

    CreateTemplate<T>(a, n, i + 1);
}

// Виведення масиву
template <typename T>
void PrintTemplate(const T a[], int n, int i = 0)
{
    if (i >= n)
    {
        cout << endl;
        return;
    }

    cout << setw(5) << a[i];

    PrintTemplate<T>(a, n, i + 1);
}

// Підрахунок непарних елементів
template <typename T>
int CountOddTemplate(const T a[], int n, int i = 0)
{
    if (i >= n)
        return 0;

    int count = (a[i] % 2 != 0) ? 1 : 0;

    return count + CountOddTemplate<T>(a, n, i + 1);
}


// 3. ГОЛОВНА ФУНКЦІЯ


int main()
{
    const int n = 10;

    srand(static_cast<unsigned int>(time(nullptr)));

    // Звичайні рекурсивні функції
    int a[n];

    cout << "Ordinary recursive functions:" << endl;

    Create(a, n);
    Print(a, n);

    cout << "CountOdd = "
        << CountOdd(a, n) << endl;

    // Шаблонні рекурсивні функції для int
    int b[n];

    cout << endl
        << "Template recursive functions (int):"
        << endl;

    CreateTemplate<int>(b, n);
    PrintTemplate<int>(b, n);

    cout << "CountOddTemplate<int> = "
        << CountOddTemplate<int>(b, n) << endl;

    // Шаблонні рекурсивні функції для long
    long c[n];

    cout << endl
        << "Template recursive functions (long):"
        << endl;

    CreateTemplate<long>(c, n);
    PrintTemplate<long>(c, n);

    cout << "CountOddTemplate<long> = "
        << CountOddTemplate<long>(c, n) << endl;

    return 0;
}
