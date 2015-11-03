//
//  57.cpp
//  Leetcode
//
//  Created by yan zhang on 15/10/28.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
/* 按左端排序的线段数组中（无重叠），插入某个线段，再输出合并后的结果。明显的二分。必然水。
 这个题的二分在处理的过程里，搞的复杂了一点，但总归是1Y.
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

struct SearchRes {
    int type; // 0: Left End, 1: Between Intervals, 2: In Interval, 3: Right End
    int lidx, ridx;
    SearchRes(int t, int ld, int rd){
        type = t, lidx = ld, ridx = rd;
    }
};


SearchRes bsearch(vector<Interval> v, int idx){
    int len = v.size();
    int left = 0, right = len-1, mid;
    while(left <= right){
        mid = (left + right) >> 1;
        if(idx < v[mid].start){
            if(mid == 0)
                return SearchRes(0, -1, 0);
            else if(idx > v[mid-1].end)
                return SearchRes(1, mid-1, mid);
            else{
                right = mid-1;
            }
        }
        else if(idx > v[mid].end){
            if(mid == len-1)
                return SearchRes(3, len-1, -1);
            else if(idx < v[mid+1].start)
                return SearchRes(1, mid, mid+1);
            else{
                left = mid+1;
            }
        }
        else {
            return SearchRes(2, mid, mid);
        }
    }
    return SearchRes(-1,-1,-1);
    
}


vector<Interval> insert(vector<Interval>& v, Interval interval) {
    vector<Interval> tmp, res;
    int len = v.size();
    
    int preX = -1, preY = -1;
    for(int i=0; i<len; i++){
        if(preX < 0){
            preX = v[i].start, preY = v[i].end;
        }else{
            if(v[i].start == preY){
                preY = v[i].end;
            }else{
                tmp.push_back(Interval(preX, preY));
                preX = v[i].start, preY =v[i].end;
            }
        }
    }
    if(preX >= 0)
        tmp.push_back(Interval(preX, preY));
    
    v = tmp;
    len = v.size();
 
//    for(int i=0; i<tmp.size(); i++)
//        cout<<tmp[i].start<<'#'<<tmp[i].end<<endl;
//    cout<<"---------\n";
    
    SearchRes lres = bsearch(v, interval.start);
    SearchRes rres = bsearch(v, interval.end);
    
//    cout<<lres.type<<' '<<lres.lidx<<' '<<lres.ridx<<endl;
//    cout<<rres.type<<' '<<rres.lidx<<' '<<rres.ridx<<endl;
    
    int ax = lres.type == 2 ? v[lres.ridx].start : interval.start;
    int ay = rres.type == 2 ? v[rres.ridx].end : interval.end;
    
    int del_x = lres.ridx, del_y = rres.lidx;
    if(lres.type == 0 && rres.type == 0)
        del_x = del_y = -1;
    if(lres.type == 3 && rres.type == 3)
        del_x = del_y = len;
    
//    cout<<del_x<<"==="<<del_y<<endl;

    
    for(int i=0; i<del_x; i++)
        res.push_back(v[i]);
    res.push_back(Interval(ax, ay));
    for(int i=del_y+1; i<len; i++)
        res.push_back(v[i]);
    
    return res;
}

int main(int argc, const char * argv[]) {
    int a[][2] = {{0,9}};
    vector<Interval> v;
    for(int i=0; i<1; i++)
        v.push_back(Interval(a[i][0], a[i][1]));
    vector<Interval> res = insert(v, Interval(14,5));
    for(int i=0; i<res.size(); i++)
        cout<<res[i].start<<' '<<res[i].end<<endl;
    
    cout<<"FIN"<<endl;
    return 0;
}


#endif