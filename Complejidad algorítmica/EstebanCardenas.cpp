#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int maxSum(vector<int> v, int s, int e) {
    int maxSum = INT_MIN, maxNow = 0;
    for (int i = s; i <= e; i++) {
        maxNow += v[i];
        if (maxSum < maxNow) {
            maxSum = maxNow;
        }
        if (maxNow < 0) {
            maxNow = 0;
        }
    }
    return maxSum;
}

int kMaxSum(vector<int> v, int idx, int k) {
    if (k == 1) return maxSum(v, idx, v.size() - 1);
    int ans = INT_MIN;
    int maxSum = INT_MIN, maxNow = 0;
    for (int i = idx; i <= v.size() - k; i++) {
        maxNow += v[i];
        if (maxSum < maxNow) {
            maxSum = maxNow;
        }
        if (maxNow < 0) {
            maxNow = 0;
        }
        int rightSum = kMaxSum(v, i + 1, k - 1);
        ans = max(ans, maxSum + rightSum);
    }
    return ans;
}

// Funciona pero con TLE :'(
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v[i] = num;
    }
    cout << kMaxSum(v, 0, k) << endl;
    return 0;
}
