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
	// Ki?m tra xem n?u m?ng có 1 ph?n t? thì không c?n s?p x?p
	if (left >= right)
	{
		return;
	}

	vol pivot = A[(left + right) / 2]; // Ch?n thành ph?n t? chính gi?a dãy làm ch?t
	// i là v? trí ??u và j là v? trí cu?i
	vol1 i = left, j = right;

	while (i < j)
	{
		if (choose != 0)
		{
			while (A[i] < pivot) // N?u ph?n t? bên trái nh? h?n pivot thì ok, b? qua
			{
				i++;
			}

			while (A[j] > pivot) // N?u ph?n t? bên ph?i l?n h?n pivot thì ok, b? qua
			{
				j--;
			}
		}
		else
		{
			while (A[i] > pivot) // N?u ph?n t? bên trái nh? h?n pivot thì ok, b? qua
			{
				i++;
			}

			while (A[j] < pivot) // N?u ph?n t? bên ph?i l?n h?n pivot thì ok, b? qua
			{
				j--;
			}
		}
		
		// Sau khi k?t thúc hai vòng while ? trên thì ch?c ch?n
		// v? trí A[i] ph?i l?n h?n pivot và A[j] ph?i nh? h?n pivot
		// n?u i < j
		if (i <= j)
		{
			if (i < j) // n?u i != j (t?c không trùng thì m?i c?n hoán ??i)
			{
				swap(A[i], A[j]); // Th?c hi?n ??i ch? ta ???c A[i] < pivot và A[j] > pivot
			}
			i++;
			j--;
		}
	}
	// G?i ?? quy s?p x?p dãy bên trái pivot
	Partition(A, left, j, choose);
	// G?i ?? quy s?p x?p dãy bên ph?i pivot
	Partition(A, i, right, choose);
}
template <class vol, class vol1>
void Print(vol A[], vol1 n)
{
	int i;
	for (i = 0; i < n; i++)
		std::cout << A[i] << " ";
}
// Hàm s?p x?p chính
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