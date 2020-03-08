/*************************************************************************
	> File Name: 7.thread_tree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月15日 星期六 19时13分17秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NORMAL 0
#define THREAD 1

typedef struct Node {
    int data;
    struct Node *lchild, *rchild;
    int ltag, rtag;
} Node;

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->lchild = p->rchild = NULL;
    p->ltag = NORMAL;
    p->rtag = NORMAL;
    return p;
}

Node *insert(Node *root, int val) {
    if (root == NULL) return getNewNode(val);
    if (root->data == val) return root;
    if (val < root->data) root->lchild = insert(root->lchild, val);
    else root->rchild = insert(root->rchild, val);
    return root;
}

//创建线索
void build_thread(Node *root) {
    if (root == NULL) return ;
    static Node *pre = NULL;
    build_thread(root->lchild); //左子树建立线索
    if (root->lchild == NULL) {
        root->lchild = pre;   // 前驱
        root->ltag = THREAD;
    }
    if (pre != NULL && pre->rchild == NULL) {
        pre->rchild = root;    //后继
        pre->rtag = THREAD;
    }
    pre = root;    //关键
    build_thread(root->rchild);
    return ;
}

Node *most_left(Node *p) { //传地址
    while (p && p->ltag == NORMAL && p->lchild != NULL) p = p->lchild;
    return p;
}

void output(Node *root) {
    Node *p = most_left(root);  //走到根结点
    while (p) {
        printf("%d ", p->data);
        if (p->rtag == THREAD) {  //是不是线索
            p = p->rchild;
        } else {
            p = most_left(p->rchild);
        }
    }
    return ;
} 

void in_order(Node *root) {
    if (root == NULL) return ;
    if (root->ltag == NORMAL) in_order(root->lchild);
    printf("%d ", root->data);
    if (root->rtag == NORMAL) in_order(root->rchild);
    return ;
}

void clear(Node *root) {
    if (root == NULL) return ;
    if (root->ltag == NORMAL) clear(root->lchild);
    if (root->rtag == NORMAL) clear(root->rchild);
    free(root);
    return ;
}


int main() {
    srand(time(0));
    #define max_op 20
    Node *root = NULL;
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        root = insert(root, val);
    }
    build_thread(root);
    output(root), printf("\n");
    in_order(root), printf("\n");
    clear(root);
    return 0;
}