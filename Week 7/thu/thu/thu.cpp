#include <iostream>
#include <stdio.h>
#include <stdlib.h>
///20110174
struct Element {
    int i, j;
    int value;
};

struct  SparseMatrix
{
    int M;  // row
    int N;  // column
    int num;  // num so phan tu khac 0
    struct Element* element;
};


SparseMatrix convertArr2Sparse(int** arr, int M, int N) {
    int num = 0;
    //dem so luong phan tu khac 0
    int i, j;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            if (arr[i][j] != 0)
                num += 1;
        }
    }
    SparseMatrix result;
    result.M = M;
    result.N = N;
    result.num = num;
    result.element = new Element[num];
    int k = 0;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            if (arr[i][j] != 0) {
                result.element[k].i = i;
                result.element[k].j = j;
                result.element[k].value = arr[i][j];
                k += 1;
            }
        }
    }
    return result;

}
void printSparse(const SparseMatrix& S) {
    int k;
    printf("[%d]x[%d]: [%d]\n", S.M, S.N, S.num);
    for (k = 0; k < S.num; k++) {
        printf("[row %d, col %d]: %d\n", S.element[k].i,
            S.element[k].j, S.element[k].value);
    }
}

SparseMatrix* add(SparseMatrix s1, SparseMatrix s2)
{
    SparseMatrix* result;
    if (s1.M != s2.M || s1.N != s2.N) {
        return nullptr;
    }
    result = new SparseMatrix;
    int i, j, k;
    i = j = k = 0;

    result->M = s1.M;
    result->N = s2.N;

    result->num = s1.num + s2.num;
    result->element = new Element[result->num];

    while (i < s1.num && j < s2.num) {
        if (s1.element[i].i < s2.element[j].i)
            result->element[k++] = s1.element[i++];
        else if (s1.element[i].i > s2.element[j].i)
            result->element[k++] = s2.element[j++];
        else {
            if (s1.element[i].j < s2.element[j].j)
                result->element[k++] = s1.element[i++];
            else if (s1.element[i].j > s2.element[j].j)
                result->element[k++] = s2.element[j++];
            else {
                result->element[k] = s1.element[i];
                result->element[k++].value = s1.element[i++].value + s2.element[j++].value;
            }
        }
    }
    SparseMatrix* finalresult;
    finalresult = new SparseMatrix;
    finalresult->M = s1.M;
    finalresult->N = s2.N;

    finalresult->num = k;
    finalresult->element = new Element[finalresult->num];
    for (i = 0; i < k; i++) {
        finalresult->element[i] = result->element[i];
    }
    delete result;
    return finalresult;

}

SparseMatrix* mul(SparseMatrix s1, SparseMatrix s2)
{
    //////your code here/////
    int** result;
    if (s1.N != s2.M) {
        return nullptr;
    }
    int i, j, k;

    result = new int* [s1.M];
    for (i = 0; i < s1.M; i++) {
        result[i] = new int[s2.N];
    }
    for (i = 0; i < s1.M; i++) {
        for (j = 0; j < s2.N; j++) {
            result[i][j] = 0;
        }
    }
    i = j = k = 0;
    while (i < s1.num) {
        for (j = 0; j < s2.num; j++)
        {
            if (s2.element[j].i == s1.element[i].j)
            {
                result[s1.element[i].i][s2.element[j].j] += s1.element[i].value * s2.element[j].value;
            }
        }
        i++;
    }
    int num = 0;

    for (i = 0; i < s1.M; i++) {
        for (j = 0; j < s2.N; j++) {
            if (result[i][j] != 0)
            {
                num++;
            }
        }
    }

    SparseMatrix* finalresult;
    finalresult = new SparseMatrix;
    finalresult->M = s1.M;
    finalresult->N = s2.N;

    finalresult->num = num;
    finalresult->element = new Element[finalresult->num];
    for (i = 0; i < s1.M; i++) {
        for (j = 0; j < s2.N; j++) {
            if (result[i][j] != 0)
            {
                finalresult->element[k].i = i;
                finalresult->element[k].j = j;
                finalresult->element[k].value = result[i][j];
                k++;
            }
        }
    }
    return finalresult;
    ////// end your code /////
}





int main()
{

    int** Array, ** Array2;
    int M = 1000;
    int N = 2000;
    int num = 100;
    int k, i, j;
    Array = new int* [M];
    for (i = 0; i < M; i++) {
        Array[i] = new int[N];
    }
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            Array[i][j] = 0;
        }
    }
    for (k = 0; k < num; k++) {
        i = rand() % M;
        j = rand() % N;
        Array[i][j] = rand(); // khác 0
    }

    struct SparseMatrix A, B, C;

    A = convertArr2Sparse(Array, M, N);
    num = 200;
    M = 2000;
    N = 3000;
    Array2 = new int* [M];
    for (i = 0; i < M; i++) {
        Array2[i] = new int[N];
    }
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            Array2[i][j] = 0;
        }
    }
    for (k = 0; k < num; k++) {
        i = rand() % M;
        j = rand() % N;
        Array2[i][j] = rand(); // khác 0
    }
    B = convertArr2Sparse(Array2, M, N);

    C = *(mul(A, B));

    // chỉ có 100 phần tử khác 0

    //Xuat thông tin
    printSparse(C);






}
