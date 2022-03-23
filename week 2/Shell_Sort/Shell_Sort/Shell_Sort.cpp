#include <iostream>
template <class vol, class vol1>
void ShellSort(vol A[], vol1 n, vol1 choose)
{
    int i, j, interval;
    vol temp;
    for (interval = n / 2; interval > 0; interval /= 2)
    {
        for (i = interval; i < n; i++)
        {
            temp = A[i];
            if (choose != 0)
            {
                for (j = i; j >= interval && A[j - interval] > temp; j -= interval)
                {
                    A[j] = A[j - interval];
                }
            }
            else
            {
                for (j = i; j >= interval && A[j - interval] < temp; j -= interval)
                {
                    A[j] = A[j - interval];
                }
            }
            
            A[j] = temp;
        }
    }
}
template <class vol, class vol1>
void Print(vol A[], vol1 n)
{
    int i;
    for (i = 0; i < n; i++)
        std::cout << A[i] << " ";
}

void main()
{
    double A[1000];
    int n, i, choose;
    std::cout << "n = ";
    std::cin >> n;
    std::cout << "Nhap 1 de sap xep mang tang hoac nhap 0 de sap xep mang giam: ";
    std::cin >> choose;
    for (i = 0; i < n; i++)
    {
        std::cout << "A[" << i << "]= ";
        std::cin >> A[i];
    }

    ShellSort(A, n, choose);
    Print(A, n);
}