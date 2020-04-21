// https://www.acmicpc.net/problem/1654
// Binaray Search(3), 랜선 자르기
// NUMBER 1654

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> input(n);
    for (int i = 0; i < n; i++)
        cin >> input[i];

    long long left = 1,
              right = *max_element(input.begin(), input.end()),
              max = 0;
    while (left <= right) {
        long long mid = (left + right) / 2;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += input[i] / mid;
        }
        if (cnt >= k) {
            max = max > mid ? max : mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << max << endl;
    return 0;
}