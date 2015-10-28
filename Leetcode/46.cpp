//
//  46.cpp
//  Leetcode
//
//  Created by yan zhang on 15/10/28.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
/* Leetcode Medium 的题目：输出所有排列。。 还能更水否？*/

#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__

void dfs(vector<int>& nums, bool* visit, vector<int>& stack, vector<vector<int>>& output){
    int len = nums.size();
    if(stack.size() == len) {
        vector<int> item(stack);
        output.push_back(item);
        return;
    }
    for(int i=0; i<len; i++){
        if(!visit[i]){
            visit[i] = true;
            stack.push_back(nums[i]);
            dfs(nums, visit, stack, output);
            stack.pop_back();
            visit[i] = false;
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    int n = nums.size();
    if(n <= 0)
        return res;
    
    bool *visit = new bool[n];
    memset(visit, 0, sizeof(bool)*n);
    vector<int> stack;
    dfs(nums, visit, stack, res);
    return res;
}


int main(int argc, const char * argv[]) {
    int a[] = {};
    vector<int> v;
    for(int i=0; i<sizeof(a)/sizeof(int); i++)
        v.push_back(a[i]);
    
    vector<vector<int>> res = permute(v);
    for(int i=0; i<res.size(); i++) {
        for(int j=0; j<res[i].size(); j++)
            cout<<res[i][j]<<' ';
        cout<<endl;
    }

    
    cout<<"FIN"<<endl;
    return 0;
}



#endif