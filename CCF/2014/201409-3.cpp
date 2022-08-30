//
// Created by MisakaBit on 2022/8/30.
//
#include<bits/stdc++.h>

using namespace std;

int main() {
    string substr;
    cin >> substr;
    bool is_strict;
    cin >> is_strict;

    int n;
    cin >> n;
    while (n--) {
        string str;
        cin >> str;

        if (str.length() < substr.length())
            continue;

        for (int i = 0; i < str.length();) {
            for (int j = 0; j < substr.length(); ++j) {
                if (!is_strict) {
                    if (toupper(substr[j]) != toupper(str[i + j]))
                        goto next;
                } else if (substr[j] != str[i + j])
                    goto next;
            }
            cout << str << endl;
            break;
            next:
            i++;
        }

    }
    return 0;
}