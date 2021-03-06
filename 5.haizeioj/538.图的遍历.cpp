/*************************************************************************
	> File Name: 538.图的遍历.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月25日 星期三 18时13分30秒
 ************************************************************************/

#include <iostream>
using namespace std;

int n, num[25][25], check[25], flag;

void func(int x) {
    if (flag == 1) {
        cout << "-";
    }
    flag = 1;
    cout << x;
    for (int i = 1; i <= n; i++) {
        //1和其他边连上
        if (num[x][i] == 1 && check[i] == 0) {
            check[i] = 1;//标记走没走过
            func(i);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1;j <= n; j++) {
            cin >> num[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (check[i] == 0) {
            //没走过
            check[i] = 1;
            func(i);
        }
    }

    return 0;
}
