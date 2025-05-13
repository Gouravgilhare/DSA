#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {45, 7, 34, 1, 79, 46, 94, 12};
    int size = sizeof(arr) / sizeof(arr[0]);

    if (size == 0)
        return 0;

    int minElement = INT_MAX;
    int maxElement = INT_MIN;

    for (int i = 0; i < size; i++)
    {

        if (arr[i] < minElement)
            minElement = arr[i];

        if (arr[i] > maxElement)
            maxElement = arr[i];
    }

    cout << "Largest ELement : " << maxElement << endl;
    cout << "Smallest ELement : " << minElement << endl;

    return 0;
}
