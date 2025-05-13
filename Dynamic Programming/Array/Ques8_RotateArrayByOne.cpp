#include <bits/stdc++.h>
using namespace std;

void reverse(int *arr, int start, int end);

int main()
{
    int arr[] = {7, 1, 9, 3, 6, 8, 10, 2, 5, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k;

    cout << "reversing array by k ";
    cout << "\nEnter K : ";
    cin >> k;
    k %= n;

    cout << "\narray before : \n";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    if (k != 0)
    {
        reverse(arr, 0, k - 1);
        reverse(arr, k, n - 1);
        reverse(arr, 0, n - 1);
    }
    cout << "\narray After : \n";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

void reverse(int *arr, int start, int end)
{
    while (start < end)
    {
        arr[start] += arr[end];
        arr[end] = arr[start] - arr[end];
        arr[start] = arr[start] - arr[end];
        start++;
        end--;
    }
}

// OUTPUT:
//  reversing array by k
//  enter K : 5
//  array before :
//  7 1 9 3 6 8 10 2 5 0
//  array After :
//  10 2 5 0 7 1 9 3 6 8