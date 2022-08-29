//
// Created by MisakaBit on 2022/8/29.
// 得了90分, 不知道哪里出错了...
//
#include<bits/stdc++.h>

using namespace std;

vector<string> split(const string &input, const char *delim) {
    vector<string> res;

    char *cmdline_c = const_cast<char *>(input.c_str());

    char *token = strtok(cmdline_c, delim);
    while (token != nullptr) {
        res.emplace_back(token);
        token = strtok(nullptr, delim);
    }

    return res;
}

int main() {
    string standard;
    cin >> standard;
    unordered_map<char, bool> has_arg;
    for (int i = 0; i < standard.length(); ++i) {
        if (standard[i] == ':')
            has_arg[standard[i - 1]] = true;
        else
            has_arg[standard[i]] = false;
    }

    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; ++i) {
        string cmdline;
        getline(cin, cmdline);
        unordered_map<char, string> ans_map;

        vector<string> cmds = split(cmdline, " ");
        for (int j = 1; j < cmds.size();) {
            if (cmds[j][0] != '-') // 没有-
                break;
            if (cmds[j].length() > 2) { // -abcd
                break;
            }
            if (has_arg.find(cmds[j][1]) == has_arg.end()) // 不在选项列表里
                break;

            if (has_arg[cmds[j][1]]) {
                if (j == cmds.size()-1) // 最后一个, 肯定没有参数
                    break;
                string next = cmds[j+1];
                if (next[0] == '-')
                    break;
                ans_map[cmds[j][1]] = next;
                j+=2;
            }
            else{
                ans_map[cmds[j][1]] = " ";
                ++j;
            }
        }
        cout << "Case " << i + 1 << ": ";
        int m=0;
        for (char j = 'a'; j < 'z'; ++j) {
            if (ans_map.find(j) != ans_map.end()) {
                if (m!=0)
                    cout << " ";
                m++;
                if (has_arg[j])
                    printf("-%c %s", j, ans_map[j].c_str());
                else
                    printf("-%c", j);
            }

        }
        cout << endl;
    }

    return 0;
}