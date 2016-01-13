//
//  81.cpp  []
//  Leetcode
//
//  Created by yan zhang on 16/1/12.
//  Copyright (c) 2016年 yan zhang. All rights reserved.
//

#include <stdio.h>
#include "tools.h"
#include "run.h"

using namespace std;

#ifdef __RUN__

bool search(vector<int>& nums, int target) {
    return true;
}

int main(int argc, const char * argv[]) {
    int a[] = {7,8,10,15,27,1,3,4,5,7};
    vector<int> v;
    for(int i=0; i<sizeof(a)/sizeof(a[0]); i++)
    v.push_back(a[i]);
    cout<<search(v, 3)<<endl;
    
    cout<<"FIN"<<endl;
    return 0;
}

#endif


/*
 Follow up for "Search in Rotated Sorted Array":
 What if duplicates are allowed?
 
 Would this affect the run-time complexity? How and why?
 
 Write a function to determine if a given target is in the array.
 
 Subscribe to see which companies asked this question
 
 */