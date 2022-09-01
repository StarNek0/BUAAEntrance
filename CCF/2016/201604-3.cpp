//
// Created by MisakaBit on 2022/9/1.
// 10分。。。理解错题意了, 题目举的文件系统例子和输入完全无关, 而是要根据第一行字符串来处理
/*
Sample Input
7
/d2/d3
/d2/d4/f1
../d4/f1
/d1/./f1
/d1///f1
/d1/
///
/d1/../../d2
*/
#include<bits/stdc++.h>

using namespace std;

class Node{
public:
    string name;
    bool is_root;
    Node *parent;
    Node *childs[3];
    int childs_count;
    bool is_dir;
    string abspath();
    Node* next(string dir);
};

string Node::abspath(){
    vector<string> dirs = {name};

    Node* p = parent;
    while(p != nullptr){
        dirs.push_back(p->name);
        p = p->parent;
    }
    string res = "";
    for(int i = dirs.size() - 1; i >= 0; --i)
        if (i == dirs.size() - 1 || i == 0)
            res += dirs[i];
        else
            res += dirs[i] + "/";
    return res;
}
Node* Node::next(string dir){
    if (dir == ".")
        return this;
    if (dir == ".."){
        if (is_root)
            return this;
        return parent;
    }
    for(int i = 0; i < childs_count; ++i)
        if (childs[i]->name == dir)
            return childs[i];
    return this;
}

vector<string> split(string str, string split){
    vector<string> res;
    regex re(split);
    sregex_token_iterator end;
    for(sregex_token_iterator iter(str.begin(), str.end(), re, -1); iter != end; iter++){
        if (iter->str() != "")
            res.push_back(iter->str());
    }
    return res;
}

int main() {
    // init
    Node root = {"/", true, nullptr, {}, 2, true};
    Node d1 = {"d1", false, &root, {}, 2, true};
    Node d2 = {"d2", false, &root, {}, 3, true};
    Node f1 = {"f1", false, &d1, {}, 0, false};
    Node f2 = {"f2", false, &d1, {}, 0, false};
    Node d3 = {"d3", false, &d2, {}, 1, true};
    Node d4 = {"d4", false, &d2, {}, 1, true};
    Node f4 = {"f4", false, &d2, {}, 1, false};
    Node f3 = {"f3", false, &d3, {}, 0, false};
    Node d4f1 = {"f1", false, &d4, {}, 0, false};
    root.childs[0] = &d1;
    root.childs[1] = &d2;
    d1.childs[0] = &f1;
    d1.childs[1] = &f2;
    d2.childs[0] = &d3;
    d2.childs[1] = &d4;
    d2.childs[2] = &f4;
    d3.childs[0] = &f3;
    d4.childs[0] = &d4f1;

    int n;
    string init_path;
    // string paths[10] = {
        // "/d2/d4/f1", 
        // "../d4/f1",
        // "/d1/./f1",
        // "/d1///f1",
        // "/d1/",
        // "///",
        // "/d1/../../d2",
    // };

    // input
    cin >> n;  // n = 7;
    cin >> init_path;  // init_path = "/d2/d3";
    getchar();
    // for(int i = 0; i < n; ++i)
    //     cin >> paths[i];
    // cout << d4f1.abspath() << endl;
    // cout << d4f1.next("..")->next("..")->next("..") << endl;

    // solve
    vector<string> init_ops = split(init_path, "/");
    Node* init_node = &root;
    for(int i = 0; i < init_ops.size(); ++i)
        init_node = init_node->next(init_ops[i]);

    // cout << init_node->abspath() << endl;  // check front
    
    for(int i = 0; i < n; i++){
        string path; // = paths[i];
        getline(cin, path);
        vector<string> ops = split(path, "/"); 
        
        // cout << "o: ";
        if(path.length() == 0)
            cout << init_node->abspath() << endl;
        else if (ops.size() == 0)
            cout << root.abspath() << endl;
        else{
            Node* p;
            if (path[0] == '/')
                p = &root;
            else
                p = init_node;
 
            for(int i = 0; i < ops.size(); ++i){
                p = p->next(ops[i]);
            }
            cout << p->abspath() << endl;
        }
        // cout << "----" << endl;        
    }

    return 0;
}