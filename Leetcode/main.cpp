//
//  main.cpp
//  Leetcode
//
//  Created by yan zhang on 15/4/7.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
//

#include "stdio.h"
#include <vector>

#ifdef __RUN__

using namespace std;

#define MAXN 99997

struct node{
    int v;
    int k;
    node(int key, int value){
        k = key;
        v = value;
    }
};

vector<node> hashtable[MAXN];

int p(int value){
    return ((value % MAXN) + MAXN) % MAXN;
}

void put(int key, int value){
    int i = p(value);
    hashtable[i].push_back(node(key, value));
}

int search(int value, int preKey){
    int i = p(value);
    for(int j=0; j<hashtable[i].size(); j++)
        if(hashtable[i][j].v == value && hashtable[i][j].k < preKey)
            return hashtable[i][j].k;
    return -1;
}

vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> res = vector<int>();
    unsigned long len = numbers.size();
    int num, hope;
    for(int i=0, j = 0; i<len; i++){
        num = numbers[i];
        hope = target - num;
        put(i, num);
        j = search(hope, i);
        if(j >= 0){ // find it.
            res.push_back(j+1);
            res.push_back(i+1);
        }
    }
    return res;
};



int main(int argc, const char * argv[]) {
    // insert code here..
    int a[6] = {0, 7, 11, 15, 1, 0};
    vector<int> v;
    for(int i=0; i<6; i++){
        v.push_back(a[i]);
    }
    vector<int> ret = twoSum(v, 0);
    printf("Index1=%d, Index2=%d", ret[0], ret[1]);
    return 0;
}

#endif
