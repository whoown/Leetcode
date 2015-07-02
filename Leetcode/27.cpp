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

int removeElement(vector<int>& nums, int val) {
    int len = nums.size();
    for(int i=len-1; i>=0; i--)
        if(nums[i] == val)
            nums.erase(nums.begin()+i);
    return nums.size();
}

void test(){
    int a[] = {};
    vector<int> v;
    for(int i=0; i<sizeof(a)/sizeof(int); i++)
        v.push_back(a[i]);
    cout<<removeElement(v, 1)<<endl;
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
