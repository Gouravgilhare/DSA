// 3sum.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {-1, -2, -4, 0, 7, 3, 9, 1, 4, 6, 5, -6, 3};
    int size = arr.size();
    vector<vector<int>> ans;

    // Step 1: Sort array
    sort(arr.begin(), arr.end());

    // Step 2: Fix one element and use two-pointer
    for (int i = 0; i < size; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) continue; // skip duplicates for i

        int tar = -arr[i];
        int j = i + 1, k = size - 1;

        while (j < k) {
            int sum = arr[j] + arr[k];

            if (sum == tar) {
                ans.push_back({arr[i], arr[j], arr[k]});

                // skip duplicates for j and k
                while (j < k && arr[j] == arr[j + 1]) j++;
                while (j < k && arr[k] == arr[k - 1]) k--;

                j++;
                k--;
            }
            else if (sum < tar) {
                j++;
            }
            else {
                k--;
            }
        }
    }

    // Print result
    cout << "Triplets are:\n";
    for (auto &triplet : ans) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]\n";
    }

    return 0;
}
