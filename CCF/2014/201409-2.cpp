//
// Created by MisakaBit on 2022/8/30.
//
#include<bits/stdc++.h>

using namespace std;

class Rectangle {
public:
    int x1, y1, x2, y2;
};

int main() {
    int n;
    cin >> n;
    int square[101][101] = {};

    for (int i = 0; i < n; ++i) {
        Rectangle r{};
        cin >> r.x1 >> r.y1 >> r.x2 >> r.y2;
        for (int j = r.x1; j < r.x2; ++j) {
            for (int k = r.y1; k < r.y2; ++k) {
                square[j][k] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 101; ++i) {
        for (int j = 0; j < 101; ++j) {
            if (square[i][j] == 1)
                ans++;
        }
    }
    cout << ans << endl;
}