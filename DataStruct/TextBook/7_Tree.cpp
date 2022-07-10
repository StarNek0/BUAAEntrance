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
BinTree CreateBinTree() {
	BinTree stack[100] = {}, p = NULL, T = NULL;
	char ch = 0;
	int flag = 0, top = -1;
	while (true)
	{
		scanf_s("%c", &ch);
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
	BinTree b = CreateBinTree();//输入: A(B(D, E(G)), C(F(, H)))@
    PrintTree(b, 4);
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

int main() {
	CreateBinTreeTest();
}

