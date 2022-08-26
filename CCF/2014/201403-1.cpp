//
// Created by MisakaBit on 2022/8/26.
//
#include<bits/stdc++.h>

using namespace std;

int main() {
    unordered_map<int, bool> m;

    int n = 0;
    int items[500]; // n<=500
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> items[i];
    }

    for (int i = 0; i < n; i++) {
        int item = items[i];
        int item_abs = abs(item);
        if (m.find(item_abs) == m.end())
            m[item_abs] = false; // false 代表绝对值出现了1次
        else
            m[item_abs] = true; // true 代表绝对值出现了2次, 又因为每个数只能出现一次, 所以绝对值最多出现2次, 所以有一对相反数
    }

    int ans = 0;
    for (auto kv: m) {
        // cout << kv.first << ":" << kv.second << endl;
        if (kv.second)
            ans++;
    }
    cout << ans << endl;

    return 0;
}