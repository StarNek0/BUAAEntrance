//
// Created by MisakaBit on 2022/8/31.
//
#include<bits/stdc++.h>

using namespace std;

int main() {
    int n = 0;
    int a[1000] = {}; // 5, 4, 1, 2, 3, 6, 4
    int ans = 0;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    for(int i = 0; i < n; ++i){
        if (i==0 || i==n-1)
            continue;
        if (a[i-1] < a[i] && a[i] > a[i+1])
            ans++;
        if (a[i-1] > a[i] && a[i] < a[i+1])
            ans++;
    }
    cout << ans << endl;

    return 0;
}