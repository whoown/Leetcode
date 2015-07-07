//
//  34.cpp
//  Leetcode
//
//  Created by Zhang Yan on 15/6/13.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
//  水

#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res;
    int len = (int)nums.size();
    int left = 0, right = len-1, mid;
    int leftBorder = -1, rightBorder=-1;
    while(left <= right){ // search left border
        mid = (left + right) >> 1;
        
        if(nums[mid] == target){
            if(mid == 0 || nums[mid-1] != target){// find.
                leftBorder = mid;
                break;
            }else
                right = mid-1;
        }
        else if(nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    if(leftBorder == -1) {
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }
    
    left = 0, right = len-1;
    while(left <= right){ // search right border
        mid = (left + right) >> 1;
        if(nums[mid] == target){
            if(mid == len-1 || nums[mid+1] != target){// find.
                rightBorder = mid;
                break;
            }else
                left = mid + 1;
        }
        else if(nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    res.push_back(leftBorder);
    res.push_back(rightBorder);
    
    return res;
}

void test(){
    int arr[] = {8, 8,10};
    int target = 8, ans = -1;
    vector<int> v;
    for(int i=0; i<sizeof(arr)/sizeof(int); i++) {
        if(arr[i] == target)
            ans = i;
        v.push_back(arr[i]);
    }
    vector<int> res = searchRange(v, target);
    cout<<res[0]<<' '<<res[1]<<endl;
}


int main(int argc, const char * argv[]) {
    test();
    cout<<"GOOD\n";
    return 0;
}

#endif
