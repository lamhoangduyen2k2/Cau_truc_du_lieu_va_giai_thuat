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
void Partition(vol A[], vol1 left, vol1 right, vol1 choose)
{
	// Ki?m tra xem n?u m?ng c� 1 ph?n t? th� kh�ng c?n s?p x?p
	if (left >= right)
	{
		return;
	}

	vol pivot = A[(left + right) / 2]; // Ch?n th�nh ph?n t? ch�nh gi?a d�y l�m ch?t
	// i l� v? tr� ??u v� j l� v? tr� cu?i
	vol1 i = left, j = right;

	while (i < j)
	{
		if (choose != 0)
		{
			while (A[i] < pivot) // N?u ph?n t? b�n tr�i nh? h?n pivot th� ok, b? qua
			{
				i++;
			}

			while (A[j] > pivot) // N?u ph?n t? b�n ph?i l?n h?n pivot th� ok, b? qua
			{
				j--;
			}
		}
		else
		{
			while (A[i] > pivot) // N?u ph?n t? b�n tr�i nh? h?n pivot th� ok, b? qua
			{
				i++;
			}

			while (A[j] < pivot) // N?u ph?n t? b�n ph?i l?n h?n pivot th� ok, b? qua
			{
				j--;
			}
		}
		
		// Sau khi k?t th�c hai v�ng while ? tr�n th� ch?c ch?n
		// v? tr� A[i] ph?i l?n h?n pivot v� A[j] ph?i nh? h?n pivot
		// n?u i < j
		if (i <= j)
		{
			if (i < j) // n?u i != j (t?c kh�ng tr�ng th� m?i c?n ho�n ??i)
			{
				swap(A[i], A[j]); // Th?c hi?n ??i ch? ta ???c A[i] < pivot v� A[j] > pivot
			}
			i++;
			j--;
		}
	}
	// G?i ?? quy s?p x?p d�y b�n tr�i pivot
	Partition(A, left, j, choose);
	// G?i ?? quy s?p x?p d�y b�n ph?i pivot
	Partition(A, i, right, choose);
}
template <class vol, class vol1>
void Print(vol A[], vol1 n)
{
	int i;
	for (i = 0; i < n; i++)
		std::cout << A[i] << " ";
}
// H�m s?p x?p ch�nh
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
	Partition(A, 0, n - 1, choose);
	Print(A, n);
}