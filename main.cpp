// https://www.acmicpc.net/problem/21869
// 21869 Maximub bishop
//
// ...

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long
#define pq priority_queue

int N, Q, k, v, cnt = 0;
vector<vector<pair<int, int>>> usado;
vector<bool> visited;
queue<int> q;

void bfs() {
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        visited[cur] = true;

        for (auto connect : usado[cur]) {
            int next = connect.first;
            int usa = connect.second;

            if (visited[next]) {
                continue;
            }

            if (usa >= k) {
                q.push(next);
                cnt++;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> Q;
    usado.resize(N + 1);
    visited.resize(N + 1, false);
    for (int i = 1; i <= N - 1; i++) {
        int p, q, r;
        cin >> p >> q >> r;
        usado[p].push_back({q, r});
        usado[q].push_back({p, r});
    }

    for (int i = 1; i <= Q; i++) {
        cin >> k >> v;

        q.push(v);
        bfs();
        cout << cnt << endl;

        fill(visited.begin(), visited.end(), false);
        cnt = 0;
    }
    return 0;
}