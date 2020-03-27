// https://www.acmicpc.net/problem/12865
//
// NUMBER

#include <iostream>
#include <vector>
#include <utility>

using namespace std;
int bag[101][100001];
vector<pair<int, int>> item;

void solve(int N, int K)
{
    for (int i = 0; i < N; i++)
        for (int o = 0; o <= K; o++)
            bag[i][o] = 0;

    for (int i = 0; i < N; i++)
    {
        for (int o = 0; o <= K; o++)
        {
            if (i == 0)
            {
                if (item[i].first <= o)
                {
                    bag[i][o] = item[i].second;
                }
                continue;
            }
            if (item[i].first <= o)
                bag[i][o] = max(bag[i - 1][o], item[i].second + bag[i - 1][o - item[i].first]);
            else
                bag[i][o] = bag[i - 1][o];
        }
    }
    cout << bag[N - 1][K] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K, w, v;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> w >> v;
        item.push_back(make_pair(w, v));
    }

    solve(N, K);
    return 0;
}