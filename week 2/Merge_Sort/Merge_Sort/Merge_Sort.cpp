#include <iostream>
template <class vol, class vol1>
void Merge(vol A[], vol1 left, vol1 mid, vol1 right, vol1 choose)
{
    vol1 n1 = mid - left + 1;    // Số phần tử của mảng con thứ nhất
    vol1 n2 = right - mid;       // Số phần tử của mảng con thứ hai
    // Tạo hai mảng tạm để lưu hai mảng con
    vol LeftArr[100];
    vol RightArr[100];

    //Sao chép phần tử hai mảng con vào mảng tạm
    for (int i = 0; i < n1; i++)
        LeftArr[i] = A[left + i];
    for (int i = 0; i < n2; i++)
        RightArr[i] = A[mid + 1 + i];

    // current là vị trí hiện tại trong mảng A
    int i = 0, j = 0, current = left;

    // Trộn hai mảng vào nhau theo đúng thứ tự
    while (i < n1 && j < n2)
        if (choose != 0)
        {
            if (LeftArr[i] <= RightArr[j])
                A[current++] = LeftArr[i++];
            else
                A[current++] = RightArr[j++];
        }
        else
        {
            if (LeftArr[i] >= RightArr[j])
                A[current++] = LeftArr[i++];
            else
                A[current++] = RightArr[j++];
        }
        

    // Nếu mảng thứ nhất còn phần tử thì coppy nó vào mảng A
    while (i < n1)
        A[current++] = LeftArr[i++];
    while (j < n2)
        A[current++] = RightArr[j++];

    // Xóa hai mảng tạm đi
}

template <class vol, class vol1>
// Hàm chia đôi mảng và gọi hàm trộn
void MergeSort(vol A[], vol1 left, vol1 right, vol1 choose)
{
    // Kiểm tra xem còn chia đôi mảng được nữa không
    if (left < right)
    {
        // Tìm phần tử chính giữa 
        // left + (right - left)/2 tương đương với (left + right)/2
        // việc này giúp tránh bị tràn số với left, right quá lớn
        vol1 mid = left + (right - left) / 2;
        // Săp xếp mảng thứ hai
        MergeSort(A, left, mid, choose);

        // Sắp xếp mảng thứ nhất
        MergeSort(A, mid + 1, right, choose);

        // Trộn hai mảng đã sắp xếp
        Merge(A, left, mid, right, choose);
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
    MergeSort(A, 0, n - 1, choose);
    Print(A, n);
}
