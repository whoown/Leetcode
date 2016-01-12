//
//  78.cpp [1]
//  Leetcode
//
//  Created by Zhang Yan on 16/1/11.
//  Copyright (c) 2016年 yan zhang. All rights reserved.
//
/* 将一个集合所有排列输出。大水。
 */


#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__



void sort(vector<int>& v, int st, int ed){
    if(st >= ed)
        return;
    int div = v[st];
    int i = st+1, j = ed;
    while(i<j){ // [<div][div][>=div]
        while(v[i]<div  && i<j) ++i; // i stops at [>=div]
        while(v[j]>=div && i<j) --j;
        swap(v[i], v[j]);
    }
    if(v[i] >= div)
        --i;
    swap(v[st], v[i]);
    sort(v,st,i-1);
    sort(v, i+1, ed);
}

void dfs(vector<int>nums, vector<vector<int>>& ans, vector<int>& stk, int n, int start, int k){
    if(k == 0){
        ans.push_back(vector<int>(stk));
        return;
    }
    for(int i=start; i<n-k+1; i++){
        stk.push_back(nums[i]);
        dfs(nums, ans, stk, n, i+1, k-1);
        stk.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums, 0, nums.size()-1);
    
    vector<int> temp;
    for(int i=0; i<=nums.size();i++){
        temp.clear();
        dfs(nums, ans, temp, nums.size(), 0, i);
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    int a[] = {3,2,1,4,5};
    vector<int> v;
    for(int i=0; i<sizeof(a)/sizeof(int);i++)
        v.push_back(a[i]);
    vector<vector<int>> ans = subsets(v);
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
