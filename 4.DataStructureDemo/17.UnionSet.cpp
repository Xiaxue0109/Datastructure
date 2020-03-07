/*************************************************************************
	> File Name: 17.UnionSet.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月22日 星期六 20时19分24秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct UnionSet {
    int *color;
    int n;
} UnionSet;

UnionSet *init(int n) {
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
    u->color = (int *)malloc(sizeof(int) * (n + 1));
    u->n = n;
    for (int i = 1; i <= n; i++) {
        u->color[i] = i;
    }
    return u;
}

// 查找
int find(UnionSet *u, int x) {
    return u->color[x];
}

//联通操作
int merge(UnionSet *u, int a, int b) {
    if (find(u, a) == find(u, b)) return 0; //已经联通
    int color_a = u->color[a];
    for (int i = 1; i <= u->n; i++) {
        if (u->color[i] != color_a) continue;
        u->color[i] = u->color[b];
    }
    return 1;
}

//合并操作


void clear(UnionSet *u) {
    if (u == NULL) return ;
    free(u->color);
    free(u);
    return ;
}

int main() {
    int n, m;
    scanf("%d%d",&n, &m);
    UnionSet *u = init(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        switch (a) {
            case 1: merge(u, b, c); break;
            case 2: printf("%s\n", find(u, b) == find(u, c) ? "YES" : "NO"); break;
        }
    }
    clear(u);
    return 0;
}
