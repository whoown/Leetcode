//
//  47.cpp
//  Leetcode
//
//  Created by yan zhang on 15/10/28.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
/* 存在重复数字的数组，输出所有排列。。 反过来想，之前是枚举位置，这一次其实可以枚举元素。先把1都用尽，各种位置的组合都用尽，在安排下一个数字2.... 依然很水，1Y~
 [1,1,2] have the following unique permutations:
 [1,1,2], [1,2,1], and [2,1,1]
 */

#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__

void dfs(vector<int>& num, vector<int>& cnt, vector<int>& buf, bool* visit, int index, int startIndex, vector<vector<int>>& output){
    int num_len = num.size();
    if(index >= num_len){
        vector<int> ans(buf);
        output.push_back(ans);
        return;
    }
    
    for(int i=startIndex; i<buf.size(); i++){
        if(!visit[i]){
            visit[i] = true;
            cnt[index]--;
            buf[i] = num[index];
            dfs(num, cnt, buf, visit, cnt[index] > 0? index : index+1, cnt[index] > 0 ? i+1 : 0, output);
            cnt[index]++;
            visit[i] = false;
        }
    }
    
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    int len = nums.size();
    if(len <= 0)
        return res;
    qsort(nums, 0, len-1);
    vector<int> num, cnt;
    
    int preValue = nums[0]-1;
    for(int i=0; i<len; i++){
        if(nums[i] != preValue){
            preValue = nums[i];
            num.push_back(nums[i]);
            cnt.push_back(1);
        }else{
            cnt[cnt.size()-1]++;
        }
    }
    
    bool* visit = new bool[len];
    memset(visit, 0, sizeof(bool)*len);
    vector<int> buf(len);
    
    dfs(num, cnt, buf, visit, 0, 0, res);
    return res;
}


int main(int argc, const char * argv[]) {
    int a[] = {1,1,1,2};
    vector<int> v;
    for(int i=0; i<sizeof(a)/sizeof(int); i++)
        v.push_back(a[i]);
    
    vector<vector<int>> res = permuteUnique(v);
    for(int i=0; i<res.size(); i++) {
        for(int j=0; j<res[i].size(); j++)
            cout<<res[i][j]<<' ';
        cout<<endl;
    }
    
    cout<<"FIN"<<endl;
    return 0;
}



#endif