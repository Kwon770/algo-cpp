// https://www.acmicpc.net/problem/1912
// Dynamic Programming (15), 연속합
// NUMBER 1912

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int n)
{
    vector<string> vec;
    string wear, kind;
    int kinds[30];
    fill(kinds, kinds + 30, 0);
    for (int i = 0; i < 30; i++)
    {
        cout << kinds[i] << endl;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> wear >> kind;
        vector<string>::iterator iter = find(vec.begin(), vec.end(), kind);
        if (iter != vec.end())
        {
            kinds[distance(vec.begin(), iter)]++;
        }
        else
        {
            kinds[vec.size()]++;
            vec.push_back(kind);
        }
    }

    int calculation = (kinds[0] + 1);
    for (int i = 1; kinds[i]; i++)
        calculation *= (kinds[i] + 1);
    cout << calculation - 1 << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        solve(n);
    }

    return 0;
}