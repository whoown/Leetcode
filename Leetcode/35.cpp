//
//  35.cpp
//  Leetcode
//
//  Created by Zhang Yan on 15/6/13.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
//  水题

#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__

int searchInsert(vector<int>& nums, int target) {
    int len = (int)nums.size();
    int left = 0, right = len-1, mid;
    while(left <= right){
        mid = (left+right) >> 1;
        if(nums[mid] == target) // find target
            return mid;
        if(nums[mid] > target){
            if(mid == 0 || nums[mid-1] < target)
                return mid;
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    return len;
}

void test(){
    int arr[] = {1};
    int target = 2, ans = -1;
    vector<int> v;
    for(int i=0; i<sizeof(arr)/sizeof(int); i++) {
        if(arr[i] == target)
            ans = i;
        v.push_back(arr[i]);
    }
    cout<<searchInsert(v, target)<<endl;
}


int main(int argc, const char * argv[]) {
    test();
    cout<<"GOOD\n";
    return 0;
}

#endif
