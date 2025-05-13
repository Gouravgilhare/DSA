// Q2A: 
// Steph wants to improve her knowledge of algorithms over winter break. She has a total of X (1 ≤ X ≤ 10^4 ) minutes to dedicate to learning algorithms. There are N (1 ≤ N ≤ 100) algorithms, and each one of them requires ai (1 ≤ ai ≤ 100) minutes to learn. Find the maximum number of algorithms she can learn.
// Example:
// N = 6, X = 15
// a = {4, 3, 8, 4, 7, 3}
// Result = 4


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, X;
    cout << "Enter total time available (X) and number of algorithms (N): ";
    cin >> X >> N;

    vector<int> a(N);
    cout << "Enter time required for each algorithm: ";
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());  // Sorting to prioritize smaller times

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (X >= a[i]) {
            X -= a[i];
            count++;
        } else {
            break;
        }
    }

    cout << "Total algorithms she can learn: " << count << endl;
    return 0;
}
