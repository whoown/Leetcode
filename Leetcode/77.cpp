//
//  77.cpp 【1】
//  Leetcode
//
//  Created by yan zhang on 15/11/10.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
/*
 输出所有组合序列，水题；
 */


#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__



void dfs(vector<vector<int>>& ans, vector<int>& stk, int n, int start, int k){
    if(k==0){
        ans.push_back(vector<int>(stk));
        return;
    }
    for(int i=start; i<=n-k+1; i++){
        stk.push_back(i);
        dfs(ans, stk, n, i+1, k-1);
        stk.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> stk;
    dfs(ans, stk, n, 1, k);
    return ans;
}


int main(int argc, const char * argv[]) {
    vector<vector<int>> ans = combine(4, 2);
    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<' ';
        }
        cout<<endl;
    }

    cout<<"FIN"<<endl;
    return 0;
}

#endif
