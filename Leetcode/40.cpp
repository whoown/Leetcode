//
//  40.cpp
//  Leetcode
//
//  Created by Zhang Yan on 15/6/13.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
/*
 一个正整数数组，从中挑出所有和=sum的组合，数字仅限使用一次（数组元素可能有重复）。换着法的水题，毕竟locklock。
 */

#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__

void dfs(vector<int> nums, vector<int> cnts, vector<vector<int>>& output, vector<int>& stack, int sum, int index, int target){
    if(sum == target){
        vector<int> ans(stack);
        output.push_back(ans);
        return;
    }
    if(sum > target || index >= nums.size()){
        return;
    }
    
    dfs(nums, cnts, output, stack, sum, index+1, target);
    for(int i=1; i<=cnts[index]; i++){
        stack.push_back(nums[index]);
        dfs(nums, cnts, output, stack, sum + i*nums[index], index+1, target);
    }
    for(int i=1; i<=cnts[index]; i++)
        stack.pop_back();
}


vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
    vector<vector<int>> res;
    vector<int> stack;
    
    qsort(nums, 0, nums.size()-1);
    
    int p=-1;
    vector<int> v;
    vector<int> cnt;
    for(int i=0; i<nums.size(); i++){
        p = v.size() - 1;
        if(p < 0 || nums[i] != v[p]){
            v.push_back(nums[i]);
            cnt.push_back(1);
        }else{
            cnt[p]++;
        }
    }
    
    dfs(v, cnt, res, stack, 0, 0, target);
    
    return res;
}


int main(int argc, const char * argv[]) {
    int a[] = {1,1,1,1,3,5,1,4,9,5,6};
    vector<int> v;
    for(int i=0; i<sizeof(a)/sizeof(int); i++)
        v.push_back(a[i]);
    
    vector<vector<int>> res = combinationSum2(v, 7);
    for(int i=0; i<res.size(); i++) {
        for(int j=0; j<res[i].size(); j++)
            cout<<res[i][j]<<' ';
        cout<<endl;
    }
    
    cout<<"FIN"<<endl;
    return 0;
}

#endif
