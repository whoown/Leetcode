//
//  52.cpp
//  Leetcode
//
//  Created by yan zhang on 15/10/28.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
/* N后问题，输出所有可行解。。水到无法直视。。 1Y~
 52题，N后问题，不要求输出可行解，只要求可行解个数。数学不好的同学，把数列打出来，猜猜规律。。/// 然后并不是。。直接搜就1Y~
 */

#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__

int dfs(int row, int n, bool* cols, bool* diag1, bool* diag2){
    if(row >= n){
        return 1;
    }
    
    int res = 0;
    for(int i=0; i<n; i++){
        if(cols[i])
            continue;
        if(diag1[row - i + n-1])
            continue;
        if(diag2[row + i])
            continue;
        cols[i] = true;
        diag1[row-i+n-1] = true;
        diag2[row+i] = true;
        res += dfs(row+1, n, cols, diag1, diag2);
        cols[i] = false;
        diag1[row-i+n-1] = false;
        diag2[row+i] = false;
    }
    return res;
}

int totalNQueens(int n) {
    bool* cols = new bool[n]; // column from 0 to n-1
    bool* diag1 = new bool[2*n-1]; // diagonal from x-y+n-1 = 0 to 2n-2
    bool* diag2 = new bool[2*n-1]; // diagonal form x+y = 0 to 2n-2
    memset(cols, 0, n);
    memset(diag1, 0, 2*n-1);
    memset(diag2, 0, 2*n-1);
    return dfs(0, n, cols, diag1, diag2);
}

int main(int argc, const char * argv[]) {
    
    for(int i=1; i<20; i++){
        cout<<i<<' '<<totalNQueens(i)<<endl;
    }
    
    cout<<"FIN"<<endl;
    return 0;
}


#endif