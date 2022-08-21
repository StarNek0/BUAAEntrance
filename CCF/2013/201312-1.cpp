//
// Created by MisakaBit on 2022/8/21.
//
#include<bits/stdc++.h>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    int input[1024] = {0}; // 存储输入(非必要)
    int freq[10010] = {0}; // 存储每个数的频率
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    for (int item: input) {
        freq[item]++;
    }

    int max = 0;
    int max_index;
    for (int i = 1; i < 10001; i++) {
        if (freq[i] != 0 && freq[i] > max) {
            max = freq[i];
            max_index = i;
        }
    }
    cout << max_index << endl;
    return 0;
}