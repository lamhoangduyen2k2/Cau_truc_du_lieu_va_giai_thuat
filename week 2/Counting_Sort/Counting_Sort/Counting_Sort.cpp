#include <iostream>
template <class vol, class vol1>
void CountingSort(vol A[], vol1 n)
{
    vol output[1000];
    vol max = A[0];
    vol min = A[0];

    for (int i = 1; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
        else if (A[i] < min)
        {
            min = A[i];
        }
    }

    vol k = max - min + 1;

    vol1 count_array[1000];
    
    for  (int i = 0; i < k ; i++)
    {
        count_array[i] = 0;
    }

    for (int i = 0; i < n ; i++)
    {
        count_array[int(A[i] - min)] ++;
    }

    for (int i = 1; i < k; i++)
    {
        count_array[i] += count_array[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        output[count_array[int(A[i] - min)] - 1] = A[i];
        count_array[int(A[i] - min)]--;
    }

    for (int i = 0; i < n; i++)
    {
        A[i] = output[i];
    }
}
template <class vol, class vol1>
void Print(vol A[], vol1 n)
{
    int i;
    for (i = 0; i < n; i++)
        std::cout << A[i] << " ";
}
int main()
{
    double A[100];
    int n, i;
    std::cout << "n = ";
    std::cin >> n;
    for (i = 0; i < n; i++)
    {
        std::cout << "A[" << i << "]= ";
        std::cin >> A[i];
    }
    CountingSort(A, n);
    Print(A, n);
}