#include <iostream>
#include <limits.h>
#include <stdlib.h>
using namespace std;
int getRandomTwoDigitNumber();

int main()
{
    int n;
    cout << "Enter size of array :";
    cin >> n;
    cout << endl;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = getRandomTwoDigitNumber();
    }

    cout << "array : \n";
    for (int i = 0; i < n; i++)
    {
            cout << arr[i] << " ";
    }

    int sum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxSum = max(maxSum, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }

    cout << "\n MaxSum = : " << maxSum;
    delete[] arr; 
    return 0;
}



int getRandomTwoDigitNumber() {
    // int num;
    int num;
    if (rand() % 2) {  // 50% chance for positive or negative
        num = (rand() % 90) + 10;   // Generates 10 to 99
    } else {
        num = -(rand() % 90 + 10);  // Generates -10 to -99
    }
    return num;

}
