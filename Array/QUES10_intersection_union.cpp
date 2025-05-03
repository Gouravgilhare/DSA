#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr1, arr2, unArr, inArr;
    int n;
    cout << "enter size of array : ";
    cin >> n;

    arr1.resize(n);
    arr2.resize(n);

    for (int i = 0; i < n; i++)
    {
        arr1[i] = rand() % 90 + 10;
        arr2[i] = rand() % 90 + 10;
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    cout << "\nArray 1: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << "\nArray 2: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr2[i] << " ";
    }

    int i = 0, j = 0;
    //  union
    while (i < n && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            if (unArr.empty() || unArr.back() != arr1[i])                
            unArr.push_back(arr1[i]);
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            if (unArr.empty() || unArr.back() != arr2[j])
                unArr.push_back(arr2[j]);
            j++;
        }
        else
        {
            if (unArr.empty() || unArr.back() != arr1[i])
            unArr.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    while (i < n)
    {
        if (unArr.empty() || unArr.back() != arr1[i])
            unArr.push_back(arr1[i]);
        i++;
    }
    while (j < n)
    {
        if (unArr.empty() || unArr.back() != arr2[j])
            unArr.push_back(arr2[j]);
        j++;
    }

    // INTERSECTION

    i = 0;
    j = 0;
    while (i < n && j < n)
    {
        if (arr1[i] == arr2[j])
        {
            if (inArr.empty() || inArr.back() != arr1[i])
                inArr.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    cout << "\nAFTER Intersection: " << endl;

    for (int i = 0; i < inArr.size(); i++)
    {
        cout << inArr[i] << " ";
    }
    cout << "\nAFTER Union: " << endl;

    for (int i = 0; i < unArr.size(); i++)
    {
        cout << unArr[i] << " ";
    }

    return 0;
}

// OUTPUT:
// enter size of array : 10

// Array 1:
// 35 44 45 51 58 62 67 71 71 99
// Array 2:
// 27 28 46 50 51 72 74 75 84 97
// AFTER Intersection:
// 51
// AFTER Union:
// 27 28 35 44 45 46 50 51 58 62 67 71 72 74 75 84 97 99
