//
//  51.cpp
//  Leetcode
//
//  Created by yan zhang on 15/10/28.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
/* N后问题，输出所有可行解。。水到无法直视。。 1Y~
 52题，N后问题，不要求输出可行解，只要求可行解个数。数学不好的同学，把数列打出来，猜猜规律。。
 */

#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__

void dfs(int row, int n, int* stack, bool* cols, bool* diag1, bool* diag2, vector<vector<string>>& output){
    
    if(row >= n){
        vector<string> ans;
        for(int i=0; i<n; i++){
            string s(n, '.');
            s[stack[i]] = 'Q';
            ans.push_back(s);
        }
        output.push_back(ans);
        return;
    }
    
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
        stack[row] = i;
        dfs(row+1, n, stack, cols, diag1, diag2, output);
        cols[i] = false;
        diag1[row-i+n-1] = false;
        diag2[row+i] = false;
    }
}

vector<vector<string>> solveNQueens(int n) {
    bool* cols = new bool[n]; // column from 0 to n-1
    bool* diag1 = new bool[2*n-1]; // diagonal from x-y+n-1 = 0 to 2n-2
    bool* diag2 = new bool[2*n-1]; // diagonal form x+y = 0 to 2n-2
    int* stack = new int[n];
    memset(cols, 0, n);
    memset(diag1, 0, 2*n-1);
    memset(diag2, 0, 2*n-1);
    memset(stack, 0, sizeof(int)*n);
    vector<vector<string>> res;
    dfs(0, n, stack, cols, diag1, diag2, res);
    return res;
}

int main(int argc, const char * argv[]) {
    vector<vector<string>> res = solveNQueens(5);

    for(int i=0; i<res.size(); i++){
        for(int j=0;j<res[i].size(); j++)
            cout<<res[i][j]<<endl;
        cout<<endl<<endl;
    }
    
    for(int i=1; i<20; i++){
        cout<<i<<' '<<solveNQueens(i).size()<<endl;
    }
    
    cout<<"FIN"<<endl;
    return 0;
}


#endif