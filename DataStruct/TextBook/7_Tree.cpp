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
	BinTree b = CreateBinTree();// A(B(D, E(G)), C(F(, H)))@
    PrintTree(b, 4);
}

int main() {
	CreateBinTreeTest();
}

