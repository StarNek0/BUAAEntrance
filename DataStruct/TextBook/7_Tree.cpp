#include "7_Tree.hpp"
#include<queue>

//打印每个元素
void PrintTreeNode(char c, int h, int index) {
    //基础空格
    int blank = 3;

    //用于标记是否为每行第一个元素
    bool flag = false;
    //确定元素所在行
    int line = 1;
    for (; line <= h; line++) {
        if (index <= pow(2, line - 1)) {
            if (index == pow(2, line - 1)) {
                flag = true;
            }
            else {
                line--;
            }
            break;
        }
    }

    //每个字母的空格倍数
    int itemblank = blank;
    for (int i = 1; i < h - line + 1; i++) {
        itemblank = itemblank * 2 + 1;
    }

    //每行开头字母的空格倍数
    int headblank = (itemblank - 1) / 2 - 1;
    if (flag) {
        //新的一行的回车数
        int changelinenum = (itemblank - 1) / 4;
        if (changelinenum < 1) {
            changelinenum = 1;
        }
        if (line == 1) {
            changelinenum = 1;
        }

        //先回车换行
        for (int j = 0; j < changelinenum; j++) {
            printf("\n");
        }
        //在打印空格到正确的位置
        for (int i = 0; i < headblank; i++) {
            printf(" ");
        }

        //最后打印每行的第一个元素
        printf("%c", c);
    }
    else {
        //先打印空格到正确的位置
        for (int i = 0; i < itemblank; i++) {
            printf(" ");
        }
        //打印元素
        printf("%c", c);
    }
}
//h为二叉树的高度
void PrintTree(BinTree T, int h) {
    printf("\n");

    //二叉树元素序号
    int index = 0;

    queue<BinTree> Q;

    //第一个元素先入队
    Q.push(T);

    //总数大于满二叉树最大值则退出循环
    while (index < pow(2, h) - 1) {
        BinNode* node = Q.front();
        Q.pop();
        index++;
        //将空的子树也入队，这样方便计算
        if (node == NULL) {
            Q.push(NULL);
            Q.push(NULL);
            //打印第index个元素
            PrintTreeNode(' ', h, index);
        }
        else {
            Q.push(node->lchild);
            Q.push(node->rchild);
            //打印第index个元素
            PrintTreeNode(node->data, h, index);
        }
    }

    printf("\n");
}

// <数据结构教程>p160 从字符串创建
BinTree CreateBinTree(string s) {
	BinTree stack[100] = {}, p = NULL, T = NULL;
	char ch = 0;
	int flag = 0, top = -1;
	for(char ch : s)
	{
		switch (ch)
		{
		case '@':
			return T;
		case ' ':
			break;
		case '(':
			stack[++top] = p;
			flag = 1;
			break;
		case ')':
			top--;
			break;
		case ',':
			flag = 2;
			break;
		default:
			p = (BinTree)malloc(sizeof(BinNode));
			p->data = ch;
			p->lchild = NULL;
			p->rchild = NULL;
			if (T == NULL)
				T = p;
			else if (flag == 1)
				stack[top]->lchild = p;
			else
				stack[top]->rchild = p;
			break;
		}
	}
}
void CreateBinTreeTest() {
	BinTree t= CreateBinTree("A(B(D, E(G)), C(F(, H)))@");
    PrintTree(t, 4);
}

// <数据结构教程>p161 从数组创建树
BinTree BuildBinTree(int BT[]) {

    BinTree T = (BinTree)malloc(sizeof(BinNode));
    T->data = BT[0];
    T->lchild = NULL;
    T->rchild = NULL;

    BinTree PTR[100] = { T };

    for (int i = 1; i < 100; i++) {
        if (BT[i] != 0) {
            PTR[i] = (BinTree)malloc(sizeof(BinNode));
            T->data = BT[i];
            T->lchild = NULL;
            T->rchild = NULL;

            int j = (i - 1) / 2;
            if (i - 2 * j - 1 == 0)
                PTR[j]->lchild = PTR[i];
            else
                PTR[j]->rchild = PTR[i];
        }
    }
    return T;
}

// <数据结构教程>p162 递归求二叉树叶节点数目
int CountLeaf(BinTree t) {
    if (t == NULL)
        return 0;
    if (t->lchild == NULL && t->rchild == NULL)
        return 1;
    return CountLeaf(t->lchild) + CountLeaf(t->rchild);
}

// <数据结构教程>p162 递归求二叉树深度
int BinTreeDepth(BinTree t) {
    int leftdep = 0, rightdep = 0;
    if (t == NULL)
        return 0;
    else
    {
        leftdep = BinTreeDepth(t->lchild);
        rightdep = BinTreeDepth(t->rchild);
        if (leftdep > rightdep)
            return leftdep + 1;
        else
            return rightdep + 1;
    }
}

// <数据结构教程>p163 二叉树的三种遍历方式
void PreOrder(BinTree t) {
    if (t != NULL) {
        cout << t->data << " ";
        PreOrder(t->lchild);
        PreOrder(t->rchild);
    }
}
void InOrder(BinTree t) {
    if (t != NULL) {
        InOrder(t->lchild);
        cout << t->data << " ";
        InOrder(t->rchild);
    }
}
void PostOrder(BinTree t) {
    if (t != NULL) {
        PostOrder(t->lchild);
        PostOrder(t->rchild);
        cout << t->data << " ";
    }
}
void OrderTest() {
    BinTree t = CreateBinTree("A(B(D, E(G)), C(F(, H)))@");
    PrintTree(t, 4);
    cout << endl;
    PreOrder(t);
    cout << endl;
    InOrder(t);
    cout << endl;
    PostOrder(t);
    cout << endl;
}

// <数据结构教程>p165 二叉树的非递归中序遍历
void InOrderNonRecursive(BinTree t) {
    BinTree stack[100] = {}, p = t;
    int top = -1;
    if (t != NULL) {
        while (!(p == NULL && top == -1)) {
            while (p != NULL) { // 首先一路进到左子树的尽头
                stack[++top] = p;
                p = p->lchild;
            }
            p = stack[top--]; // 取出栈顶
            cout << p->data << " "; // 栈顶作为没有child的中间节点输出
            p = p->rchild; // 进入右子树
        }
    }
}
// <数据结构教程>p167 二叉树的非递归后序遍历
void PostOrderNonRecursive(BinTree t) {
    BinTree stack[100] = {}, p = t;
    int flag_stack[100], flag = 0, top = -1;
    if (t != NULL) {
        while (!(p == NULL && top == -1)) {
            while (p != NULL) { // 首先一路进到左子树的尽头
                stack[++top] = p;
                flag_stack[top] = 0;
                p = p->lchild;
            }
            p = stack[top]; // 取出栈顶
            flag = flag_stack[top--];
            if (flag == 0) {
                stack[++top] = p;
                flag_stack[top] = 1;
                p = p->rchild;
            }
            else
            {
                cout << p->data << " ";
                p = NULL;
            }
        }
    }
}

// <数据结构教程>p169 二叉树的非递归层次遍历
void LayerOrder(BinTree t) {
    if (t == NULL) 
        return;

    BinTree q[100] = {t}, p=NULL;
    int front = -1, rear = 0;
    while (front < rear) {
        p = q[++front];
        cout << p->data << " ";
        if (p->lchild != NULL)
            q[++rear] = p->lchild;
        if (p->rchild != NULL)
            q[++rear] = p->rchild;
    }
}

void OrderNonRecursiveTest() {
    BinTree t = CreateBinTree("A(B(D, E(G)), C(F(, H)))@");
    PrintTree(t, 4);
    cout << endl;
    InOrder(t);
    cout << endl;
    InOrderNonRecursive(t);
    cout << endl;
    PostOrderNonRecursive(t);
    cout << endl;
    LayerOrder(t);
    cout << endl;
}

// <数据结构教程>p172 树的相似或等价的判定
bool Similar(BinTree t1, BinTree t2) {
    if (t1 == NULL && t2 == NULL)
        return true;
    if (t1 && t2 && Similar(t1->lchild, t2->lchild) && Similar(t1->rchild, t2->rchild))
        return true;
    return false;
}

int main() {
    OrderNonRecursiveTest();
}

