//
//  81.cpp  [2.5]
//  Leetcode
//
//  Created by yan zhang on 16/1/12.
//  Copyright (c) 2016年 yan zhang. All rights reserved.
/* 循环数组中二分查找target值；循环数组中可能存在重复元素。
两种思路：1. 首先找到分界点，再做一次二分；  2. 直接进行二分查找，但需要对重复元素进行处置；
以思路1为例：如果数组左边界，和右边界 值不相同，那么就可以直接找到分界点；但如果值相同，则需要左端or右端做线性遍历，找到一个不相同的点为止，再开始二分寻找分界点。
思路2也是类似，最坏情况下算法复杂度为O(n)。

 */

#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__

bool search(vector<int>& nums, int target) {
    int len = nums.size();
    if(len == 0)
        return false;
    
    int left_edge = 0, right_edge = len-1;
    while(right_edge >= 0 && nums[right_edge] == nums[0]){ // adjust right edge
        --right_edge;
    }
    
    if(right_edge < 0){ // all elements are same.
        return target == nums[0];
    }else if(nums[right_edge] < nums[0]){ // still a rotate array.
        // search the divider[the left divider] and adjust the edges.
        int left = 0, right = right_edge, mid;
        while(left < right){
            mid = (left + right) >> 1;
            if(nums[mid] > nums[mid+1])
                break;
            if(nums[mid] >= nums[left])
                left = mid+1;
            else
                right = mid;
        }
//        cout<<"mid:"<< mid<<endl;

        if(target >= nums[0])
            right_edge = mid;
        else
            left_edge = mid+1;
    }
    
    
    // final search
    int left = left_edge, right = right_edge, mid;
//    cout<<"final search "<<left<<' '<<right<<endl;
    while(left <= right){
        mid = (left+right)>>1;
        if(nums[mid] == target)
            return true;
        if(left == right)
            break;
        else if(nums[mid] < target)
            left = mid+1;
        else
            right = mid;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    int a[] = {3,4,5,1};
    vector<int> v;
    for(int i=0; i<sizeof(a)/sizeof(a[0]); i++)
    v.push_back(a[i]);
    cout<<search(v, 1)<<endl;
    
    cout<<"FIN"<<endl;
    return 0;
}

#endif

