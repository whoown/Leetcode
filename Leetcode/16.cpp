//
//  Leetcode
//
//  Created by yan zhang on 15/4/8.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
//
#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__

#define min(x,y) (x<y?x:y)
#define abs(x) ((x)<0?(x)*-1:(x))

int threeSumClosest(vector<int>& nums, int value) {
    if(nums.size() < 3) {
            return 0;
    }
    quick_sort(nums, 0, (int)nums.size()-1);
    int len = nums.size(), target = 0, min_delta = 2147483647, res = 0;
    for(int i=0; i<len-2; i++){
        if(i == 0){
            target = value - nums[i];
        }else if(target == value - nums[i]){
            continue;
        }else{
            target = value - nums[i];
        }
        
        int l = i+1, r = len-1, val = 0, delta = 0;
        while(l < r){
            val = nums[l] + nums[r];
            delta = abs(val - target);
            if(delta == 0)
                return value;
            if(delta < min_delta){
                min_delta = delta;
                res = val + nums[i];
            }
            
            if(val > target)
                --r;
            else if(val < target)
                ++l;
        }
    }
    return res;
}

int test[] = {-1,2,1,-4,-1};  // -1,0 ,1 ,2 ,-1, -4


int main(int argc, const char * argv[]) {
    vector<int> v = vector<int>();
    for(int i=0; i<sizeof(test)/sizeof(int); i++)
        v.push_back(test[i]);
    
    cout<<threeSumClosest(v, -100)<<endl;
    cout<<"GOOD\n";
    return 0;
}

#endif
