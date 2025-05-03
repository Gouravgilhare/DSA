// QUESTION : 6
// MOVE ZEROES TO END OF THE ARRAY

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int arr[] = {45, 0, 79, 0, 1,0,52,0, 32, 16};
    int n = sizeof(arr) / sizeof(arr[0]);

    // cout << "array Before  : " << endl;
    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << " ";

    int i = 0;
    for (int j = 0; j < n; j++)
    {
        if (arr[j] != 0)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    // cout << "\narray after  : " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

//OUTPUT: 
// array Before  : 
// 45 0 79 0 1 0 52 0 32 16
// array after  :
// 45 79 1 52 32 16 0 0 0 0