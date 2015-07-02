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

int removeDuplicates(vector<int>& nums) {
    int len = nums.size();
    if(len <= 1)
        return len;
    int res = 1, val = nums[len-1];
    for(int i=len-2; i>=0; i--){
        if(nums[i] == val){
            nums.erase(nums.begin()+(i+1));
        }else{
            ++res;
            val = nums[i];
        }
    }
    return res;
}

void test(){
    int a[] = {1,1};
    vector<int> v;
    for(int i=0; i<sizeof(a)/sizeof(int); i++)
        v.push_back(a[i]);
    cout<<removeDuplicates(v)<<endl;
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
