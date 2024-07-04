#include <bits/stdc++.h>
using namespace std;

int arr[21];
int n, totalSum;
long long minDiff = 1e9 + 1;

void f(int idx, long long s1) {
    if (idx == n) { // Base case when all elements are considered
        long long s2 = totalSum - s1;
        minDiff = min(minDiff, abs(s1 - s2));
        return;
    }
    f(idx + 1, s1 + arr[idx]); // Include current element in the first subset
    f(idx + 1, s1); // Exclude current element from the first subset
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    totalSum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        totalSum += arr[i];
    }
    f(0, 0);
    cout << minDiff;
    return 0;
}
