//
// Created by MisakaBit on 2022/8/31.
// 本题的一个典型错误就是从底部直接出现, 向上移动
/*
Sample Input
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 1 0 0 0
1 1 1 0 0 0 1 1 1 1
0 0 0 0 1 0 0 0 0 0
0 0 0 0
0 1 1 1
0 0 0 1
0 0 0 0
3
*/
#include<bits/stdc++.h>

using namespace std;

int main() {
    // init
    int world[20][10] = {0};
    int acter[4][4] = {0};
    int offset = 0;

    // input
    for(int i = 0; i < 15; ++i)
        for(int j = 0; j < 10; ++j)
            cin >> world[i][j];
    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j)
            cin >> acter[i][j];
    cin >> offset;
    offset--;

    // solve
    int space_top = 0, space_bottom = 0; // 方块边缘距离4x4边界的距离
    for(int i = 0; i < 4; ++i){
        int flag = 0;
        for(int j = 0; j < 4; ++j)
            if (acter[i][j]!=0)
                flag = 1;
        if (flag == 1)
            break;
        space_top++;
    }
    for(int i = 3; i >= 0; --i){
        int flag = 0;
        for(int j = 0; j < 4; ++j)
            if (acter[i][j]!=0)
                flag = 1;
        if (flag == 1)
            break;
        space_bottom++;
    }
    int insert_k = -1;
    for(int k = 0; k <= 14; ++k){
        for(int i = space_top; i < 4-space_bottom; ++i)
            for(int j = 0; j < 4; ++j){
                if ((k+i-space_top) > 14)
                    goto final;
                if (acter[i][j] + world[k+i-space_top][offset+j] == 2)
                    goto final;
            }
        insert_k = k;
        continue;

        final:break;
    }
    if (insert_k != -1)
        for(int i = space_top; i<4-space_bottom; ++i)
            for(int j = 0; j < 4; ++j)
                world[insert_k+i-space_top][offset+j] += acter[i][j];


    // output
    for(int i = 0; i < 15; ++i){
        for(int j = 0; j < 10; ++j){
            cout << world[i][j];
            if (j!=14)
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}