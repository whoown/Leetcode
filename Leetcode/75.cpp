//
//  75.cpp 【3】
//  Leetcode
//
//  Created by yan zhang on 15/11/10.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
/* 这种双指针题目，思维难度其实很大，但是因为代码确实简单，所以没办法算作Hard。但其实很不错的题目。
 */

#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__


void sortColors(vector<int>& nums) {
    int pr = nums.size()-1, pl = 0, p = 0;
    
    while(p <= pr){
        if (nums[p] == 0) {
            swap(nums[pl++], nums[p++]);
        }else if(nums[p] == 1){
            ++p;
        }else if(nums[p] == 2){
            swap(nums[pr--], nums[p]); // without --p
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int a[] = {0,2,1,1,2,1,0,0,0,1,2,0};
    vector<int> v;
    for(int i=0; i<sizeof(a)/sizeof(int);i++)
        v.push_back(a[i]);
    sortColors(v);
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<' ';
    
    cout<<"FIN"<<endl;
    return 0;
}

#endif
