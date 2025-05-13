// SumOfDigits Recursively

#include <iostream>
using namespace std;

void sumFunc(int n, int *sum)
{
    if (n == 0) return;
    *sum += n % 10;
    n = n / 10;
    sumFunc(n, sum);
}

int main()
{
    int n = 4561;
    int sum = 0;
    sumFunc(n, &sum);
    cout <<"Sum of all digits of "<<n<<" is "<< sum;
    return 0;
}

//Sum of all digits of 4561 is 16