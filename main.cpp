// https://www.acmicpc.net/problem/7576
// NUMBER 7576

#include <algorithm>
#include <iostream>
#include <queue>
#define endl "\n"
using namespace std;

typedef struct {
    int x;
    int y;
} node;

const int MAX = 1000 + 1;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int graph[MAX][MAX], n, m, cnt = 0;
queue<node> Queue;

void bfs(int p) {
    int prev = p, cur = 0;
    while (!Queue.empty()) {
        node Node = Queue.front();
        Queue.pop();
        cur++;

        for (int i = 0; i < 5; i++) {
            int cx = Node.x + dx[i];
            int cy = Node.y + dy[i];
            if (cx > 0 && cx <= m && cy > 0 && cy <= n && graph[cy][cx] == 0) {
                Queue.push({cx, cy});
                graph[cy][cx] = 1;
            }
        }

        if (cur == prev) {
            cnt++;
            cur = 0;
            prev = Queue.size();
        }
    }
}

int main() {
    int initCnt = 0;
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        for (int o = 1; o <= m; o++) {
            cin >> graph[i][o];
            if (graph[i][o] == 1) {
                Queue.push({o, i});
                initCnt++;
            };
        }
    }
    bfs(initCnt);
    for (int i = 1; i <= n; i++) {
        for (int o = 1; o <= m; o++) {
            if (graph[i][o] == 0) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << cnt - 1 << endl;
    return 0;
}