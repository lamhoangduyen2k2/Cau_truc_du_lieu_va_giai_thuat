#include <iostream>
template<class vol, class vol1>
void Insertion(vol A[], vol1 n, vol1 choose)
{
    int i, pos;
    vol x;
    for (i = 1; i < n; i++)
    {
        x = A[i];
        pos = i - 1;
        if (choose != 0)
        {
            while (pos >= 0 && A[pos] > x)
            {
                A[pos + 1] = A[pos];
                pos--;
            }
            A[pos + 1] = x;
        }
        else
        {
            while (pos >= 0 && A[pos] < x)
            {
                A[pos + 1] = A[pos];
                pos--;
            }
            A[pos + 1] = x;
        }
        
    }
}
template<class vol, class vol1>
void Print(vol A[], vol1 n)
{
    int i;
    for (i = 0; i < n; i++)
        std::cout << A[i] << " ";
}
int main()
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

    Insertion(A, n, choose);
    Print(A, n);
}