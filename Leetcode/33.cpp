//
//  33.cpp
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


int search(vector<int>& nums, int target) {
    int len = (int)nums.size();
    int left = 0, right = len-1, mid;
    int div = -1;
    while (left <= right) {
        mid = (left + right) >> 1;
        if(mid+1<len && nums[mid] > nums[mid+1]){ // find
            div = mid;
            break;
        }
        if(nums[mid] >= nums[0]) { // in left
            left = mid+1;
        }else{ // in right
            right = mid-1;
        }
    }
    
    if(div == -1) // sorted.
        left = 0, right = len-1;
    else if(target >= nums[0])
        left = 0, right = div;
    else
        left = div + 1, right = len-1;
    
    
    int index = -1;
    while (left <= right && index < 0) {
        mid = (left + right) >> 1;
        if(nums[mid] == target)
            index = mid;
        else if(nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return index;
}

// 根据二分的原则，直接可以进行区间减半的操作，不如上一份代码更加清晰，对数据结构进行了解析。
// 但是，唯一需要确定的其实就是二分的本质：每一次搜索，区间折半。
// 所以，构造二分的唯一核心就在于，确认下一次的搜索区间。
int search2(vector<int>& nums, int target) {
    int len = (int)nums.size();
    if(len <= 0)
        return -1;
    int left = 0, right = len-1, mid;
    bool searchRight = target <= nums[len-1];
    
    while (left <= right) {
        mid = (left + right) >> 1;
        if(nums[mid] == target)
            return mid;
        if(nums[mid] > nums[len-1]){// mid in left
            if(searchRight)
                left = mid + 1;
            else if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }else{// mid in right
            if(!searchRight)
                right = mid - 1;
            else if(nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
    }
    return -1;
}


void test(){
    int arr[] = {5};
    int target = 5, ans = -1;
    vector<int> v;
    for(int i=0; i<sizeof(arr)/sizeof(int); i++) {
        if(arr[i] == target)
            ans = i;
        v.push_back(arr[i]);
    }
    int res = search2(v, target);
    cout<<"Ans="<<ans<<" Res="<<res<<endl;
}


int main(int argc, const char * argv[]) {
    test();
    cout<<"GOOD\n";
    return 0;
}

#endif
