//
//  53.cpp
//  Leetcode
//
//  Created by yan zhang on 15/10/28.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
/*水到不能忍~ 最大字段和 */

#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__


int maxSubArray(vector<int>& nums) {
    int len = nums.size();
    if(len <= 0)
        return 0;
    int* ans = new int[len];
    ans[0] = nums[0];
    for(int i=1; i<len; i++){
        ans[i] = ans[i-1] < 0 ? nums[i] : ans[i-1]+nums[i];
    }
    int res = ans[0];
    for(int i=1; i<len; i++)
        res = max(res, ans[i]);
    return res;
}

int main(int argc, const char * argv[]) {
    
    int arr[] ={-2,-1,-3,-1,-1,-1,-1,-5,-1};
    vector<int> v;
    for(int i=0; i<sizeof(arr)/sizeof(int); i++) {
        v.push_back(arr[i]);
    }
    cout<<maxSubArray(v)<<endl;
    
    
    cout<<"FIN"<<endl;
    return 0;
}


#endif