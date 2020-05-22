// https://www.acmicpc.net/problem/11724
// NUMBER 11724, 연결 요소의 개수

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

int node[1001][1001], visited[1001], n;

void dfs(int i) {
    for (int o = 1; o <= n; o++) {
        if (node[i][o] && !visited[o]) {
            visited[o] = 1;
            dfs(o);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(node, 0, sizeof(node));
    memset(visited, 0, sizeof(visited));
    int m, cnt = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        node[tmp1][tmp2] = 1;
        node[tmp2][tmp1] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i])
            continue;
        else {
            cnt++;
            visited[i] = 1;
            dfs(i);
        }
    }
    cout << cnt << endl;
    return 0;
}