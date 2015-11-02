//
//  55.cpp
//  Leetcode
//
//  Created by yan zhang on 15/10/28.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
/* 弱化版的 最少线段覆盖问题。水之 */

#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__

bool canJump(vector<int>& nums) {
    int len = nums.size();
    if(len <= 0)
        return false;
    
    int start = 0, end = nums[0];
    if(end >= len-1)
        return true;
    
    while(start < end){
        //cout<<start<<'-'<<end<<endl;
        
        int next_start = -1, next_idx =-1;
        for(int i=start+1; i<=end; i++){
            if(i+nums[i] > next_idx){
                next_idx = i+nums[i];
                next_start = i;
            }
        }
        if(next_idx >= len-1)
            return true;
        start = next_start < end ? end : next_start;
        end = next_idx;
        //cout<<start<<'+'<<end<<endl;
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    
    int a[] = {10,0,0,0,0,0,10};
    vector<int> v;
    for(int i=0; i<sizeof(a)/sizeof(int); i++)
        v.push_back(a[i]);
    cout<<canJump(v)<<endl;
    
    cout<<"FIN"<<endl;
    return 0;
}


#endif