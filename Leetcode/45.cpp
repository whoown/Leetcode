//
//  45.cpp
//  Leetcode
//
//  Created by Zhang Yan on 15/6/13.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
/* [2,3,1,1,4] 每一个元素代表可以向后走的最大步数，问最少基本走到末尾。
 O(n^2)的大水做法会TLE.
 更直观理解下题意，其实就是有一组线段（按左边界排序），问最少几条线段可以覆盖整个数轴。
 在纸上画一画就知道，其实是个双指针问题，可以线性扫一遍得到结论。O(n) 
 这一类题，不在乎怎样高级的算法和数据结构，而在于答题者着意的分析和思考，不错。
*/

#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__

int jump(vector<int>& nums) {
    int len = nums.size();
    if(len <= 1)
        return 0;

    int start = 0, end = nums[0], step=1;
    while(end < len-1){
        int next_end = 0, dist=0;
        for(int i=start+1; i<=end; i++){
            if(i + nums[i] > next_end){
                next_end = i + nums[i];
            }
        }
        start = end;
        end = next_end;
        ++step;
    }
    
    return step;
}

int main(int argc, const char * argv[]) {
    int a[] = {3,1,3,1,1,1,1,1};
    vector<int> v;
    for(int i=0; i<sizeof(a)/sizeof(int); i++)
        v.push_back(a[i]);
    cout<<jump(v)<<endl;

    
    cout<<"FIN"<<endl;
    return 0;
}

#endif
