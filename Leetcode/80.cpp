//
//  80.cpp   [0]
//  Leetcode
//
//  Created by yan zhang on 16/1/12.
//  Copyright (c) 2016年 yan zhang. All rights reserved.
//  Hello world ... 

#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__

int removeDuplicates(vector<int>& nums) {
    if(nums.size() <= 2)
        return nums.size();
    vector<int>::iterator itr = nums.begin()+2;
    while (itr != nums.end()) {
        if(*itr == *(itr-1) && *itr == *(itr-2)) {
            itr = nums.erase(itr);
        }else{
            itr++;
        }
    }
    return nums.size();
}

int main(int argc, const char * argv[]) {
    int a[] = {1,1};
    vector<int> v;
    for(int i=0; i<sizeof(a)/sizeof(a[0]); i++)
    v.push_back(a[i]);
    cout<<removeDuplicates(v)<<endl;
    for(int i=0; i<v.size(); i++)
    cout<<v[i]<<' ';
    cout<<endl;
    
    cout<<"FIN"<<endl;
    return 0;
}

#endif