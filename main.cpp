// https://www.acmicpc.net/problem/1520
// Dynamic Programming2 (3), 내리막길
// NUMBER 1520

// Dynamic Programming, https://www.notion.so/sckwon770/Dynamic-Programming-0bca6ee333b14aea913f74133a868b0c

#include <algorithm>
#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

int m, n;
int map[501][501], dp[501][501];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int dpf(int x, int y) {
    if (x == n && y == m) {
        return 1;
    }

    if (dp[x][y] == -1) {
        dp[x][y] = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && map[x][y] > map[nx][ny]) {
                dp[x][y] += dpf(nx, ny);
            }
        }
    }
    return dp[x][y];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n;
    for (int o = 1; o <= m; o++) {
        for (int i = 1; i <= n; i++) {
            cin >> map[i][o];
            dp[i][o] = -1;
        }
    }
    cout << dpf(1, 1) << endl;
    return 0;
}