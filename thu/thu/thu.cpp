#include <iostream>
#include <time.h>
#include <stdlib.h>
//////your code here/////
#include <string>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include <fstream>
using namespace std;
template <class T>
void insertionSortGeneral(T arr[], int n, bool check)
{
    int i, j;
    T key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        if (check == false)
        {
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
        else
        {
            while (j >= 0 && arr[j] < key)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }

    }
}
template <class T>
void swapGeneral(T* x, T* y)
{
    T temp = *x;
    *x = *y;
    *y = temp;
}
template <class T>
void bubbleSortGeneral(T arr[], int n, bool check)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (check == false)
            {
                if (arr[j] > arr[j + 1])
                    swapGeneral(&arr[j], &arr[j + 1]);
            }
            else
            {
                if (arr[j] < arr[j + 1])
                    swapGeneral(&arr[j], &arr[j + 1]);
            }

}

template <class T>
void mergeGeneral(T array[], int const left, int const mid, int const right, bool check)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
    auto* leftArray = new T[subArrayOne],
        * rightArray = new T[subArrayTwo];
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0,
        indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (check == false)
        {
            if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
                array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
            else {
                array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
            indexOfMergedArray++;
        }
        else
        {
            if (leftArray[indexOfSubArrayOne] >= rightArray[indexOfSubArrayTwo]) {
                array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
            else {
                array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
            indexOfMergedArray++;
        }

    }
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}
template <class T>
void mergeSortGeneral(T array[], int const begin, int const end, bool check)
{
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSortGeneral(array, begin, mid, check);
    mergeSortGeneral(array, mid + 1, end, check);
    mergeGeneral(array, begin, mid, end, check);
}
template <class T>
int partitionGeneral(T arr[], int low, int high, bool check)
{
    T pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (check == false)
        {
            if (arr[j] < pivot)
            {
                i++;
                swapGeneral(&arr[i], &arr[j]);
            }
        }
        else
        {
            if (arr[j] > pivot)
            {
                i++;
                swapGeneral(&arr[i], &arr[j]);
            }
        }

    }
    swapGeneral(&arr[i + 1], &arr[high]);
    return (i + 1);
}
template <class T>
void quickSortGeneral(T arr[], int low, int high, bool check)
{
    if (low < high)
    {
        int pi = partitionGeneral(arr, low, high, check);
        quickSortGeneral(arr, low, pi - 1, check);
        quickSortGeneral(arr, pi + 1, high, check);
    }
}

void merge(int array[], int const left, int const mid, int const right, unsigned int& step)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
    auto* leftArray = new int[subArrayOne],
        * rightArray = new int[subArrayTwo];
    step += 4;
    for (auto i = 0; i < subArrayOne; i++)
    {
        leftArray[i] = array[left + i];
        step++;
    }

    for (auto j = 0; j < subArrayTwo; j++)
    {
        rightArray[j] = array[mid + 1 + j];
        step++;
    }


    auto indexOfSubArrayOne = 0,
        indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            step += 3;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            step += 2;
        }
        indexOfMergedArray++;
        step += 2;
    }
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
        step += 4;
    }
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
        step += 4;
    }
}

void mergeSort(int array[], int const begin, int const end, unsigned int& step)
{
    if (begin >= end)
    {
        step++;
        return;
    }
    auto mid = begin + (end - begin) / 2;
    step++;
    mergeSort(array, begin, mid, step);
    step++;
    mergeSort(array, mid + 1, end, step);
    step++;
    merge(array, begin, mid, end, step);
    step++;
}

void QuickSort(int a[], int l, int r, unsigned int& step)
{
    int p = a[(l + r) / 2];
    int i = l, j = r;
    step += 2;
    while (i < j) {
        step++;
        while (a[i] < p) {
            i++;
            step += 2;
        }
        while (a[j] > p) {
            j--;
            step += 2;
        }
        if (i <= j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
            step += 6;
        }
    }
    if (i < r) {
        QuickSort(a, i, r, step);
        step += 2;
    }
    if (l < j) {
        QuickSort(a, l, j, step);
        step += 2;
    }
}
////// end your code /////

//// 20110174

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

template<typename T>
void printArray(T arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}
void merge(int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
    auto* leftArray = new int[subArrayOne],
        * rightArray = new int[subArrayTwo];
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0,
        indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//////your code here/////
void sortingFile(string A, string B)
{
    fstream input, output;
    input.open(A, fstream::in);
    output.open(B, fstream::out);
    string s;
    vector <string> v;
    while (input >> s)
    {
        v.push_back(s);
    }
    for (int i = 0; i < v.size(); i++)
    {
        transform(v[i].begin(), v[i].end(), v[i].begin(), ::tolower);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        output << v[i] << "\n";
    }
}
////// end your code /////


void printStatic(unsigned int arr[], int N)
{
    unsigned int min, max;
    unsigned int sum = 0;
    float mean;
    //////your code here/////
    min = arr[0];
    for (int i = 0; i < N; i++)
        if (arr[i] < min)
            min = arr[i];
    max = arr[0];
    for (int i = 0; i < N; i++)
        if (arr[i] > max)
            max = arr[i];
    for (int i = 0; i < N; i++)
        sum += arr[i];
    mean = (float)sum / N;
    ////// end your code /////
    std::cout << "min:" << min << "\nmax:" << max << "\nmean:" << mean << std::endl;
}

void insertionSortComplexity(int num_simulation)
{
    unsigned int* STEP;
    STEP = new unsigned int[num_simulation];
    int N;
    int* arr;
    srand(time(NULL));
    for (int i = 0; i < num_simulation; i++) {
        N = rand() % 1000 + 50;
        arr = new int[N];
        for (int j = 0; j < N; j++) {
            arr[j] = rand();
        }
        unsigned int step = 0;
        //////your code here/////
        int key, j;
        for (int i = 1; i < N; i++)
        {
            key = arr[i];
            j = i - 1;
            step += 2;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
                step += 4;
            }
            arr[j + 1] = key;
            step++;
        }
        ////// end your code /////

        STEP[i] = step;
        delete[] arr;
    }
    printStatic(STEP, num_simulation);
}

void bubbleSortComplexity(int num_simulation)
{
    unsigned int* STEP;
    STEP = new unsigned int[num_simulation];
    int N;
    int* arr;
    srand(time(NULL));
    for (int i = 0; i < num_simulation; i++) {
        N = rand() % 1000 + 50;
        arr = new int[N];
        for (int j = 0; j < N; j++) {
            arr[j] = rand();
        }
        unsigned int step = 0;
        //////your code here/////
        int k, j;
        for (k = 0; k < N - 1; k++)
        {
            step++;
            for (j = 0; j < N - i - 1; j++)
            {
                step++;
                if (arr[j] > arr[j + 1])
                {
                    swap(&arr[j], &arr[j + 1]);
                    step += 4;
                }
            }
        }
        ////// end your code /////

        STEP[i] = step;
        delete[] arr;
    }
    printStatic(STEP, num_simulation);
}

void mergeSortComplexity(int num_simulation)
{
    unsigned int* STEP;
    STEP = new unsigned int[num_simulation];
    int N;
    int* arr;
    srand(time(NULL));
    for (int i = 0; i < num_simulation; i++) {
        N = rand() % 1000 + 50;
        arr = new int[N];
        for (int j = 0; j < N; j++) {
            arr[j] = rand();
        }
        unsigned int step = 0;
        //////your code here/////
        mergeSort(arr, 0, N - 1, step);
        ////// end your code /////

        STEP[i] = step;
        delete[] arr;
    }
    printStatic(STEP, num_simulation);
}

void quickSortComplexity(int num_simulation)
{
    unsigned int* STEP;
    STEP = new unsigned int[num_simulation];
    int N;
    int* arr;
    srand(time(NULL));
    for (int i = 0; i < num_simulation; i++) {
        N = rand() % 1000 + 50;
        arr = new int[N];
        for (int j = 0; j < N; j++) {
            arr[j] = rand();
        }
        unsigned int step = 0;
        //////your code here/////
        QuickSort(arr, 0, N - 1, step);
        ////// end your code /////

        STEP[i] = step;
        delete[] arr;
    }
    printStatic(STEP, num_simulation);
}

int main()
{
    insertionSortComplexity(10);
    bubbleSortComplexity(10);
    mergeSortComplexity(10);
    quickSortComplexity(10);

    float Farr[] = { 2.1,-1,9.5 };
    int Iarr[] = { 1,10,2 };
    bool descending = true;

    //insertionSortGeneral(Farr, 3, descending);
    //insertionSortGeneral(Iarr, 3, false);
    //bubbleSortGeneral(Farr, 3, descending);
    //bubbleSortGeneral(Iarr, 3, false);
    //mergeSortGeneral(Farr, 0, 2, descending);
    //mergeSortGeneral(Iarr, 0, 2, false);
    //quickSortGeneral(Farr, 0, 2, descending);
    //quickSortGeneral(Iarr, 0, 2, false);
    //printArray(Farr, 3);
    //printArray(Iarr, 3);
    //external sort
    sortingFile("./data.txt", "./dictionary.txt");

}