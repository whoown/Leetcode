//
//  39.cpp
//  Leetcode
//
//  Created by Zhang Yan on 15/6/13.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
/*
 一个正整数数组，从中挑出所有和=sum的组合，不限使用次数。看着就是简单的递归大水，毕竟leetcode，乐扣乐扣，太难了不好。
*/

#include <stdio.h>
#include "tools.h"
#include <iostream>
#include <vector>
//#include "run.h"

using namespace std;

#ifdef __RUN__

void dfs(vector<int> nums, vector<vector<int>>& output, vector<int>& stack, int sum, int index, int target){
    if(sum == target){
        vector<int> ans(stack);
        output.push_back(ans);
        return;
    }
    if(sum > target){
        return;
    }
    int preValue = -1;
    for(int i=index; i<nums.size(); i++){
        if(nums[i] == preValue)
            continue;
        preValue = nums[i];
        stack.push_back(nums[i]);
        dfs(nums, output, stack, sum+nums[i], i, target);
        stack.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    vector<int> stack;
    
    qsort(nums, 0, nums.size()-1);
    dfs(nums, res, stack, 0, 0, target);
    
    return res;
}


int main(int argc, const char * argv[]) {
    int a[] = {22,3,5,1,4,9,5,6};
    vector<int> v;
    for(int i=0; i<sizeof(a)/sizeof(int); i++)
        v.push_back(a[i]);
    
    vector<vector<int>> res = combinationSum(v, 7);
    for(int i=0; i<res.size(); i++) {
        for(int j=0; j<res[i].size(); j++)
            cout<<res[i][j]<<' ';
        cout<<endl;
    }
    
    cout<<"FIN"<<endl;
    return 0;
}

#endif
