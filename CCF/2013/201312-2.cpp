//
// Created by MisakaBit on 2022/8/23.
//
#include<bits/stdc++.h>

using namespace std;

int main() {
    char c[13];
    int a[13] = {0};
    for (int i = 0; i < 13; ++i) {
        cin >> c[i];
        if(c[i] == 'X'){ // 注意题干中对X的描述
            a[i] = 10;
            break;
        }
        if (c[i] != '-')
            a[i] = c[i] - '0';
    }
    int ans = (a[0] * 1 + a[2] * 2 + a[3] * 3 + a[4] * 4 + a[6] * 5 + a[7] * 6 + a[8] * 7 + a[9] * 8 + a[10] * 9) % 11;

    if (ans == a[12])
        cout << "Right" << endl;
    else {
        if (ans == 10)
            c[12] = 'X';
        else
            c[12] = '0' + ans;
        for (char item: c)
            cout << item;
        cout << endl;
    }

    return 0;
}