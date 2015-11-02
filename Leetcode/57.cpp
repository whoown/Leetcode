//
//  57.cpp
//  Leetcode
//
//  Created by yan zhang on 15/10/28.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
/* 按左端排序的线段数组中（无重叠），插入某个线段，再输出合并后的结果。明显的二分。必然水。
*/
#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> res;
    
    return res;
}

int main(int argc, const char * argv[]) {
    int a[][2] = {{1,3} , {1,6}, {1,16}, {11,18}};
    vector<Interval> v;
    for(int i=0; i<4; i++)
        v.push_back(Interval(a[i][0], a[i][1]));
    vector<Interval> res = insert(v, Interval());
    for(int i=0; i<res.size(); i++)
        cout<<res[i].start<<' '<<res[i].end<<endl;
    
    cout<<"FIN"<<endl;
    return 0;
}


#endif