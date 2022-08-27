//
// Created by MisakaBit on 2022/8/27.
//
#include<bits/stdc++.h>

using namespace std;

class Window {
public:
    bool click(int x, int y);

    int origin_order;
    int x1, y1;
    int x2, y2;
};

bool Window::click(int x, int y) {
    if (x1 <= x && x <= x2)
        if (y1 <= y && y <= y2)
            return true;
    return false;
}

int main() {
    Window windows[10];
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        Window window{i + 1};
        cin >> window.x1 >> window.y1 >> window.x2 >> window.y2;
        windows[i] = window;
    }

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        for (int j = m - 1; j >= 0; --j) {
            if (windows[j].click(x, y)) {
                cout << windows[j].origin_order << endl;
                // 且放到最后
                Window tmp = windows[j];
                for (int k = j; k < m - 1; ++k) {
                    windows[k] = windows[k + 1];
                }
                windows[m - 1] = tmp;

                break;
            } else {

                if (j == 0)
                    cout << "IGNORED" << endl;
            }

        }
    }

    return 0;
}