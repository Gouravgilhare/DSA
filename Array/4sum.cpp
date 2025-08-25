// 4sum.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {-1, -2, -4, 0, 7, 3, 9, 1, 4, 6, 5, -6, 3};
    int size = arr.size();
    int target = 15;
    vector<vector<int>> ans;

    // Step 1: Sort array
    sort(arr.begin(), arr.end());

    // Step 2: Fix two elements and use two-pointer
    for (int i = 0; i < size - 3; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) continue; // skip duplicates for i
        for (int j = i + 1; j < size - 2; j++) {
            if (j > i + 1 && arr[j] == arr[j - 1]) continue; // skip duplicates for j

            int tar = target - arr[i] - arr[j];
            int l = j + 1, k = size - 1;

            while (l < k) {
                int sum = arr[l] + arr[k];

                if (sum == tar) {
                    ans.push_back({arr[i], arr[j], arr[l], arr[k]});

                    // skip duplicates for l and k
                    while (l < k && arr[l] == arr[l + 1]) l++;
                    while (l < k && arr[k] == arr[k - 1]) k--;

                    l++;
                    k--;
                }
                else if (sum < tar) {
                    l++;
                }
                else {
                    k--;
                }
            }
        }
    }

    // Print result
    cout << "Quadruplets are:\n";
    for (auto &quad : ans) {
        cout << "[" << quad[0] << ", " << quad[1] << ", " 
             << quad[2] << ", " << quad[3] << "]\n";
    }

    return 0;
}
