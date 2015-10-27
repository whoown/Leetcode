//
//  42.cpp
//  Leetcode
//
//  Created by Zhang Yan on 15/6/13.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
/*
 
 */

#include <stdio.h>
#include "tools.h"
#include "run.h"

using namespace std;

#ifdef __RUN__

int firstMissingPositive(vector<int>& nums) {
    int n = (int)nums.size(), t;
    for(int i=0; i<n; i++) {
        t = nums[i];
        if(t<= 0 || t > n || nums[t-1] == t)
            continue;
        else{
            //swap(nums[i], nums[t - 1]);
            nums[i]^=nums[t-1]^=nums[i]^=nums[t-1];
            --i;
        }
    }
    
    for(int i=0; i<n; i++)
        if(nums[i] != i+1)
            return i+1;
    return n+1;
}


int main(int argc, const char * argv[]) {
    int a[] = {1,1,1};
    vector<int> v;
    for(int i=0; i<sizeof(a)/sizeof(int); i++)
        v.push_back(a[i]);
    
    cout<<firstMissingPositive(v)<<endl;
    cout<<"FIN"<<endl;
    return 0;
}

#endif
