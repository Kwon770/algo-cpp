#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

int n, maxPretty = 0;
vector<int> rooms;

int getGcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int getVectorGcd(vector<int> vec) {
    if (vec.size() == 1) {
        return vec.front();
    }

    int gcd = vec.front();
    for (int ele : vec) {
        gcd = getGcd(gcd, ele);
    }
    return gcd;
}

void recursiveSolve(vector<int> newRooms, int pretty) {
    if (newRooms.size() <= 1) {
        pretty += newRooms.front();
        maxPretty = max(maxPretty, pretty);
        return;
    }

    vector<int> leftRooms;
    for (int i = 0; i < newRooms.size() / 2; i++) {
        leftRooms.push_back(newRooms[i]);
    }
    int leftGcd = getVectorGcd(leftRooms);

    vector<int> rightRooms;
    for (int i = newRooms.size() / 2; i < newRooms.size(); i++) {
        rightRooms.push_back(newRooms[i]);
    }
    int rightGcd = getVectorGcd(rightRooms);

    recursiveSolve(leftRooms, pretty + rightGcd);
    recursiveSolve(rightRooms, pretty + leftGcd);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    rooms.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> rooms[i];
    }

    recursiveSolve(rooms, 0);

    cout << maxPretty;
    return 0;
}