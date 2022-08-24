//
// Created by MisakaBit on 2022/8/24.
//
#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int a[1000] = {0};
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int max = 1 * a[0];
    for (int i = 0; i < n; ++i) {
        int left = i, right = i;
        while (left > 0) {
            if (a[left - 1] >= a[i])
                left--;
            else
                break;
        }
        while (right < n - 1) {
            if (a[right + 1] >= a[i])
                right++;
            else
                break;
        }
//        cout << i << ": " << left << " " << right << endl;
        int s = (right - left + 1) * a[i];
        if (s > max)
            max = s;

    }
    cout << max << endl;
    return 0;
}