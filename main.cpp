// https://www.acmicpc.net/problem/7579
// Dynamic Programming2 (5), 앱
// NUMBER 7579

#include <cstring>
#include <iostream>
#define endl "\n"
using namespace std;

const int MAX = 100 + 1;
const int MAXCOST = 10000 + 1;

int task[MAX][MAXCOST];  // index, cost
int memory[MAX], cost[MAX];
int n, m;

int maxMemory(int idx, int totalCost) {
    if (idx > n) return 0;

    int &result = task[idx][totalCost];
    if (result != -1) return result;

    // 현재 idx의 앱을 비활상화 하지 않을 경우
    result = maxMemory(idx + 1, totalCost);

    // totalCost 보다 현재 idx의 앱의 비활성화 코스트가 같거나 작다면
    // 비활성화 안 했을 때(result)와 했을 때를 비교해서 메모리가 더 큰 쪽을 선택
    if (cost[idx] <= totalCost) result = max(result, memory[idx] + maxMemory(idx + 1, totalCost - cost[idx]));
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> memory[i];
    for (int i = 1; i <= n; i++) cin >> cost[i];
    memset(task, -1, sizeof(task));

    for (int i = 0; i <= MAXCOST; i++) {
        if (maxMemory(0, i) >= m) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}