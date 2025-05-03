#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int sec_largest(int *arr, int n);
int main()
{
    int arr[] = {46, 35, 4, 4, 43, 46, 7, 1, 79, 34};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Second Largest value is : " << sec_largest(arr, n);

    return 0;
}

int sec_largest(int *arr, int n)
{
    if (n < 2)
    {
        return -1;
    }

    int secLargest = INT_MIN;
    int largest = INT_MIN;
    for (int i = 0; i < n; i++)
    {

        if (arr[i] > largest)
        {
            secLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secLargest && arr[i] != largest)
        {
            secLargest = arr[i];
        }
    }

    return (secLargest == INT_MIN) ? -1 : secLargest;
}