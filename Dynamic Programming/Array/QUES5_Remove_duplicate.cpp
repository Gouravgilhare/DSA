// QUESTION : 5
// REMOVE DUPLICATE FROM ARRAY

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{

    int arr[] = {72, 28, 41, 41, 13, 89, 24, 89, 85, 75};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n);

    cout << "Array before : " << endl;

    for (auto a : arr)
        cout << a << " ";


    // two pointers
    int i = 0;
    for (int j = 1; j < n; j++)
    {

        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
    }

    n = i + 1;

    cout << "\nArray after: " << endl;

    for (int j = 0; j < n; j++)
        cout << arr[j] << " ";

    return 0;
}