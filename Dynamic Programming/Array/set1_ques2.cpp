#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, sum=0;
    cout << "Enter size of array : ";
    cin >> n;
    vector<int> arr;

    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 90 + 10;
    }
    cout << "\nArray : ";
    // traversing
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " + ";
        sum  =  sum + arr[i];
    }

    cout << "\nSum of all element: " << sum;

    return 0;
}