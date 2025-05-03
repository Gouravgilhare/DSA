#include <iostream>
#include<stdlib.h>
#include <math.h>
#include <vector>
using namespace std;

// traversing in array
int main()
{

    int n;
    cout << "Enter size of array : ";
    cin >> n;
    vector<int> arr;

    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 90 + 10;
    }
    cout << "\nArray : ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}