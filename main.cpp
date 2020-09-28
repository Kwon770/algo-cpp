// https://www.acmicpc.net/problem/14003
// DP and Shortest path reverse tracking(6), 13913 숨바꼭질4

#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iostream>
#include <utility>
#include <vector>

#define endl "\n"
#define MAX 200000
using namespace std;

deque<int> queue;
vector<int> previous(200001);
vector<int> fastestTime(200001);
int n, k;

bool sol(int cur, int prev) {
    if (cur > MAX || cur < 0 || ((fastestTime[cur] != -1) && (fastestTime[cur] < fastestTime[prev] + 1))) {
        return false;
    }

    previous[cur] = prev;
    fastestTime[cur] = fastestTime[prev] + 1;
    if (cur == k) {
        return true;
    }
    queue.push_back(cur);
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    fill(fastestTime.begin(), fastestTime.end(), -1);
    fastestTime[n] = 0;
    previous[n] = n;

    queue.push_back(n);
    while (n != k) {
        int idx = queue.front();
        queue.pop_front();

        if (sol(idx * 2, idx)) break;
        if (sol(idx + 1, idx)) break;
        if (sol(idx - 1, idx)) break;
    }

    cout << fastestTime[k] << endl;

    deque<int> output;
    output.push_front(k);
    int idx = k;
    for (int i = 0; i < fastestTime[k]; i++) {
        output.push_front(previous[idx]);
        idx = previous[idx];
    }
    while (!output.empty()) {
        cout << output.front() << " ";
        output.pop_front();
    }

    return 0;
}