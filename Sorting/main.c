#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int max(int *start, int *end)
{
    int maxx = *(start);
    for (int *i = start+1; i < end; i++)
    {
        if (*i > maxx)
            maxx = *i;
    }
    return maxx;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
// bubble sort      time complixty :  big O(n^2)
void bubble_sort(int arr[], int n)
{
    bool flag = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                flag = 1;
            }
        }
        if (!flag)
            break;
    }
}
// insertion sort    time complixty :  big O(n^2)
void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int x = arr[i];
        int j = i - 1;
        while (j > -1 && arr[j] > x)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
}

// partitioning for quicksort implemention
int partiton(int arr[], int l, int h)
{
    int i = l, j = h;
    int pivot = arr[l];
    do
    {
        do
        {
            i++;
        } while (arr[i] <= pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i < j)
            swap(&arr[i], &arr[j]);

    } while (i < j);
    swap(&arr[l], &arr[j]);
    return j;
}

// quicksort implemintion  tine complixty, best case : big O(nlog(n))     worst case : big O(n^2)
void quick_sort(int arr[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partiton(arr, l, h);
        quick_sort(arr, l, j);
        quick_sort(arr, j + 1, h);
    }
}

// merging for mergesort    time complixty: big O(n)
void merge(int a[], int l, int m, int h)
{
    int i, j, k;
    i = l, j = m + 1, k = l;
    int c[h];
    while (i <= m && j <= h)
    {
        if (a[i] < a[j])
            c[k++] = a[i++];
        else
            c[k++] = a[j++];
    }
    while (i <= m)
        c[k++] = a[i++];
    while (j <= h)
        c[k++] = a[j++];
    for (int i = l; i <= h; i++)
        a[i] = c[i];
}

// itreative mergesort     time complixty: big O(nlog(n))  space complixty : big O(nlog(n))
void imergesort(int arr[], int n)
{
    int p, i, l, h, mid;
    for (p = 2; p <= n; p *= 2)
    {
        for (i = 0; i + p - 1 < n; i += p)
        {
            l = i;
            h = i + p - 1;
            mid = (h + l) / 2;
            merge(arr, l, mid, h);
        }
        if (n - i > p / 2)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge(arr, l, mid, n - 1);
        }
    }
    if (p / 2 < n)
        merge(arr, 0, p / 2 - 1, n - 1);
}

// recursive mergesort     time complixty: big O(nlog(n))  space complixty : big O(n+nlog(n))
void rmergesort(int arr[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        rmergesort(arr, l, mid);
        rmergesort(arr, mid + 1, h);
        merge(arr, l, mid, h);
    }
}

// count sort        time complixty : big O(n)   but have issues with consuming alot of space
void countsort(int arr[], int n)
{
    int j = 0, k = 0;
    int maxx = max(arr, arr + n) + 1;
    int *c = malloc(maxx*sizeof(int));
    for (int i = 0; i < maxx; i++)
    {
        c[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        c[arr[i]]++;
    }
    while (j < maxx)
    {
        if (c[j] > 0)
        {
            arr[k++] = j;
            c[j]--;
        }
        else
        {
            j++;
        }
    }
    free(c);
}

// bucket/bin sort
void bucketsort(int arr[], int n)
{

}
int main()
{
    int arr[] = {20, 40, 70, 30, 50, 80, 10, 9, 12}, n = 9;
    countsort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%i ", arr[i]);
    }
    return 0;
}
