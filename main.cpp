// https://www.acmicpc.net/problem/14003
// DP and Shortest path reverse tracking(3), 14003 가장 긴 증가하는 부분 수열 5

#include <algorithm>
#include <array>
#include <cmath>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>
#define endl "\n"
using namespace std;

const int MOD = 1000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= n; i++) {
        dp[i][1] = 1;
        dp[i][2] = i + 1;
    }
    for (int i = 0; i <= k; i++) {
        dp[0][i] = 1;
    }

    for (int i = 3; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k <= n; k++) {
                if (j - k < 0) continue;

                dp[j][i] += dp[j - k][i - 1];
                dp[j][i] %= MOD;
            }
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     vector<vector<int>> dp(31, vector<int>(31, 0));
//     for (int i = 1; i <= 30; i++) {
//         dp[1][i] = i;
//     }
//     for (int i = 2; i <= 30; i++) {
//         for (int j = i; j <= 30; j++) {
//             for (int k = j - 1; k >= i - 1; k--) dp[i][j] += dp[i - 1][k];
//         }
//     }

//     int t, n, m;
//     cin >> t;
//     for (int i = 0; i < t; i++) {
//         cin >> n >> m;
//         cout << dp[n][m] << endl;
//     }

//     return 0;
// }