//
//  56.cpp
//  Leetcode
//
//  Created by yan zhang on 15/10/28.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
/* 将一组零散线段合并为几个线段。57题：在一组线段中，插入某个线段，再输出合并后的结果。
 56 线段可能有重叠，也没必要用到线段树，简单的双指针即可 1Y。线段按左端点排序后，不断扩展右端端点，即可找到一段合并后的线段了。*/

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


void qsort(vector<Interval>& v, int st, int ed){
    if(st >= ed)
        return;
    int div = v[st].start;
    int i = st+1, j = ed;
    while(i < j){ //[<div] [div] [>=div]
        while(v[i].start < div && i < j) ++i;
        while(v[j].start >=div && i < j) --j;
        swap(v[i], v[j]);
    }
    if(v[i].start >= div)
        --i;
    swap(v[i], v[st]);
    qsort(v, st, i-1);
    qsort(v, i+1, ed);
}


vector<Interval> merge(vector<Interval>& v) {
    vector<Interval> res;
    int len = v.size();
    if(len <= 0)
        return res;
    qsort(v, 0, len-1);
    
    int start = v[0].start, end = v[0].end;
    for(int i=1; i<len; i++){
        if(v[i].start > end){ // new segment
            res.push_back(Interval(start, end));
            start = v[i].start;
            end = v[i].end;
        }else{
            if(v[i].end > end)
                end = v[i].end;
        }
    }
    res.push_back(Interval(start, end));
    
    return res;
}

int main(int argc, const char * argv[]) {
    int a[][2] = {{1,3} , {1,6}, {1,16}, {11,18}};
    vector<Interval> v;
    for(int i=0; i<4; i++)
        v.push_back(Interval(a[i][0], a[i][1]));
    vector<Interval> res = merge(v);
    for(int i=0; i<res.size(); i++)
        cout<<res[i].start<<' '<<res[i].end<<endl;
    
    cout<<"FIN"<<endl;
    return 0;
}


#endif