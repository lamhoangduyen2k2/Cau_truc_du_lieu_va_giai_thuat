#include <iostream>
template <class vol>
void swap(vol& x, vol& y)
{
	vol temp;
	temp = x;
	x = y;
	y = temp;
}
template <class vol, class vol1>
void InterchangeSort(vol A[], vol1 n, vol1 choose)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (choose != 0)
            {
                if (A[i] > A[j])
                {
                    swap(A[i], A[j]);
                }
            }
            else
            {
                if (A[i] < A[j])
                {
                    swap(A[i], A[j]);
                }
            }
            
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

    InterchangeSort(A, n, choose);
    Print(A, n);
}