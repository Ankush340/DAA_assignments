#include <iostream>
using namespace std;
void merge(int A[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[q + j + 1];
    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        A[k] = L[i];
        i++;k++;
    }
    while (j < n2)
    {
        A[k] = R[j];
        j++;k++;
    }
}
void mergesort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = p + (r - p) / 2;
        mergesort(A, p, q);
        mergesort(A, q + 1, r);
        merge(A, p, q, r);
    }
}
int main()
{
    int A[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(A) / sizeof(A[0]);
    mergesort(A, 0, size - 1);
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    return 0;
}

