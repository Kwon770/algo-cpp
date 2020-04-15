// https://www.acmicpc.net/problem/10830
// Divide_and_conquer(7), 행렬 제곱
// NUMBER 10830

#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vector<long long>> Result(6, vector<long long>(6, 0));
    vector<vector<long long>> Origin(6, vector<long long>(6, 0));
    long long b;
    cin >> n >> b;
    for (int i = 1; i <= n; i++)
        for (int o = 1; o <= n; o++)
        {
            cin >> Result[i][o];
            Origin[i][o] = Result[i][o];
        }

    if (b > 1)
        divide(b, Result, Origin);

    for (int i = 1; i <= n; i++)
    {
        for (int o = 1; o <= n; o++)
            cout << Result[i][o] % MOD << " ";
        cout << endl;
    }
    return 0;
}