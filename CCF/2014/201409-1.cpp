//
// Created by MisakaBit on 2022/8/30.
//
#include<bits/stdc++.h>

using namespace std;

int main() {
    unordered_map<int, bool> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        m[val] = true;
    }
    int ans = 0;
    for (auto item = m.begin(); item != m.end(); ++item) {
        if (m.count(item->first + 1))
            ans++;
    }
    cout << ans << endl;
}