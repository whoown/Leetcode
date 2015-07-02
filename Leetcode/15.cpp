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


vector<vector<int>> threeSum(vector<int>& nums) {
    quick_sort(nums, 0, nums.size()-1);
    
    vector<vector<int>> res = vector<vector<int>>();
    if(nums.size() < 3)
        return res;
    int len = nums.size(), target = 0;
    for(int i=0; i<len-2; i++){
        if(i == 0){
            target = nums[i] * -1;
        }else if(nums[i] * -1 == target){
            continue;
        }else{
            target = nums[i] * -1;
        }
        
        //cout<<i<<' '<<target<<endl;
        bool detected = false;
        int l = i+1, r = len-1, lnum=nums[i+1];
        while(l < r){
            if(nums[l] + nums[r] > target){
                --r;
                detected = false;
            }else if(nums[l] + nums[r] < target){
                ++l;
                detected = false;
            }else{
                if(!detected || nums[l] != lnum){
                    vector<int> node = vector<int>();
                    node.push_back(-1*target);
                    node.push_back(nums[l]);
                    node.push_back(nums[r]);
                    res.push_back(node);
                }
                --r;
                detected = true;
                lnum = nums[l];
            }
        }
    }
    return res;
}


int test[] = {0,0,0,0,0};  // -1,0 ,1 ,2 ,-1, -4


int main(int argc, const char * argv[]) {
    vector<int> v = vector<int>();
    for(int i=0; i<sizeof(test)/sizeof(int); i++)
        v.push_back(test[i]);
    
    vector<vector<int>> res = threeSum(v);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[0].size(); j++){
            cout<<res[i][j]<<' ';
        }
        cout<<endl;
    }
    
    cout<<"GOOD\n";
    return 0;
}

#endif
