//
//  Leetcode
//
//  Created by yan zhang on 15/4/8.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__

void nextPermutation(vector<int>& nums) {
    int len = (int)nums.size();
    if(len <= 1)
        return;
    int i = len-1, prefixMaxValue = -1;
    while(i>=0 && nums[i] >= prefixMaxValue){
        if(nums[i] > prefixMaxValue)
            prefixMaxValue = nums[i];
        --i;
    }
    
    if(i >= 0){
        int j=i+1, minLargeValue = 2147483647, tar=0;
        while(j<len){
            if(nums[j] > nums[i] && nums[j] < minLargeValue){
                minLargeValue = nums[j];
                tar = j;
            }
            ++j;
        }
        swap(nums[i], nums[tar]);
    }
    quick_sort(nums, i+1, len-1);
}

void test(){
    int a[] = {4,3,2,1};
    vector<int> v;
    for(int i=0; i<sizeof(a)/sizeof(int); i++)
        v.push_back(a[i]);
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<' ';
    cout<<endl;
    nextPermutation(v);
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<' ';
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    test();
    cout<<"GOOD\n";
    return 0;
}

#endif
