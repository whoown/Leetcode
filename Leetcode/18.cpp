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

#define MAXN 9997
#define min(x,y) (x<y?x:y)

struct node{
    int x, y;
    node* next;
    node(){
        x = y;
        next = 0;
    }
    node(int a, int b){
        x=a;
        y=b;
        next = 0;
    }
};

node* hash_tb[MAXN];

int hash_code(int x){
    return ((x%MAXN) + MAXN) % MAXN;
}

void put(int k, int x, int y){
    int p = hash_code(k);
    node* t = hash_tb[p];
    if(!t){
        hash_tb[p] = new node(x, y);
    }else{
        while(t->next)
            t = t->next;
        t->next = new node(x, y);
    }
}


vector<vector<int>> fourSum(vector<int>& nums, int sum) {
    vector<vector<int>> res = vector<vector<int>> ();
    if(nums.size() < 4)
        return res;
    memset(hash_tb, 0, sizeof(node*)*MAXN);
    int len = (int)nums.size();
    quick_sort(nums, 0, len-1);
    
    for(int i=0; i<len; i++){
        for(int j=i+1; j<len; j++){
            put(nums[i]+nums[j], i, j);
        }
    }
    
    int preX=0, preY=0, target, p =0, preLeftNum = 0;
    for(int i=0; i<len; i++){
        if(i != 0 && preX == nums[i])
            continue;
        else
            preX = nums[i];
        
        for(int j=i+1; j<len; j++){
            if(j != i+1 && preY == nums[j])
                continue;
            else
                preY = nums[j];
            
            target = sum - nums[i] - nums[j];
            p =hash_code(target);
            node* t = hash_tb[p];
            preLeftNum = t ? nums[t->x]-1 : 0;
            while(t){
                if(t->x > j && nums[t->x] + nums[t->y] == target && nums[t->x] != preLeftNum){
                    // deteced
                    vector<int> v = vector<int>();
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[t->x]);
                    v.push_back(nums[t->y]);
                    res.push_back(v);
                    preLeftNum = nums[t->x];
                }
                t = t->next;
            }
        }
    }
    
    return res;
}

int arr[] = {5,7,7,7,7};

void test(){
    vector<int> nums = vector<int>();
    for(int i=0; i<sizeof(arr)/sizeof(int); i++)
        nums.push_back(arr[i]);
    vector<vector<int>> res = fourSum(nums, 28);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            cout<<res[i][j]<<' ';
        }
        cout<<endl;
    }
}

int main(int argc, const char * argv[]) {
    test();
    cout<<"GOOD\n";
    return 0;
}

#endif
