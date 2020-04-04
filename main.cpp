// https://www.acmicpc.net/problem/2164
// Queue_Deque_(2), 카드 2
// NUMBER 2164

#include <iostream>
#include <deque>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    deque<int> deque;
    int t, n, m, temp;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int cnt = 0;
        deque.clear();
        cin >> n >> m;
        for (int o = 0; o < n; o++)
        {
            cin >> temp;
            deque.push_back(temp);
        }
        while (true)
        {
            bool redo = false;
            for (int o = 1; o < deque.size(); o++)
            {
                if (deque.front() < deque[o])
                {
                    redo = true;
                    break;
                }
            }
            if (redo)
            {
                m--;
                deque.push_back(deque.front());
                deque.pop_front();
                if (m == -1)
                    m = deque.size() - 1;
            }
            else
            {
                cnt++;
                m--;
                deque.pop_front();
                if (m == -1)
                {
                    cout << cnt << endl;
                    break;
                }
            }
        }
    }

    return 0;
}