//
//  84.cpp  [?]
//  Leetcode
//
//  Created by Zhang Yan on 16/1/14.
//  Copyright (c) 2016年 yan zhang. All rights reserved.
/* 这是一个“并查集”思路的问题，更严格来说是集合归并的问题。其实用不到并查集这么复杂的数据结构，这是依赖于问题本身的特殊性的。
 在想到合并思路之后，没有更进一步精炼，导致加入了并查集操作，使得复杂度从 n*log(n) + n 变成了 n*log(n) + n*log(n) . 
 
 
 */


#include <stdio.h>
#include "tools.h"
#include "run.h"

using namespace std;

#ifdef __RUN__

#define max(x,y) (x>y ? x : y)
#define min(x,y) (x<y ? x : y)

struct Nd{
    int height, index;
    Nd(int h, int i){
        height = h;
        index = i;
    }
    Nd(){}
};

struct Seg{
    int left, right, height;
    Seg(){left=right=height=-1;}

    Seg(int l, int r, int h){
        left = l, right = r, height = h;
    }
};

void sort(vector<Nd>& a, int st, int ed){
    if(st >= ed) {
        return;
    }
    int div = a[st].height, l = st+1, r = ed;
    // adjust to [>div][div][<=div]
    while(l < r){
        while(a[l].height > div && l < r) ++l; // finally nums[l] <= div
        while(a[r].height<= div && l < r) --r;
        swap(a[l], a[r]);
    }
    if(a[l].height <= div) {
        --l;
    }
    swap(a[l], a[st]);
    sort(a, st, l-1);
    sort(a, l+1, ed);
}


int comp(const void*b,const void*a){
    return ((Nd*)a)->height-((Nd*)b)->height;
}

Seg merge(Seg* segs, int left, int right, int height) {
    Seg ret = Seg(left, right, height);
    segs[left] = segs[right] = ret;
    return ret;
}

int largestRectangleArea(vector<int>& height) {
    int ret = 0;
    int len = height.size();
    Nd* bars = new Nd[len];
    for(int i=0; i<len; i++) {
        bars[i] = Nd(height[i], i);
    }
    //sort(bars, 0, len-1);
    qsort(bars,len,sizeof(Nd),comp);

    for(int i=0; i<len; i++){
        cout<<bars[i].height<<' ';
    }
    cout<<endl;
    
    // prepare the segements set
    Seg* segs = new Seg[len];
    
    // insert every bar into existed segements.
    for(int i=0; i<len; i++) {
        Nd bar = bars[i];
        int idx = bar.index, h = bar.height;
        int left = idx, right = idx;
        if(idx>0 && segs[idx-1].height >= 0){ //merge with lefts
            left = segs[idx-1].left;
        }
        if(idx+1<len && segs[idx+1].height >=0 ){ // merge with right
            right = segs[idx+1].right;
        }
        Seg newSeg = merge(segs, left, right, h);
        int area = newSeg.height*(newSeg.right - newSeg.left + 1);
        ret = max(ret, area);
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    int a[] = {1,8,2,1,11,1,1,9};
    vector<int> v;
    for(int i=0; i<sizeof(a)/sizeof(a[0]); i++) {
        v.push_back(a[i]);
    }
    
    cout<<largestRectangleArea(v)<<endl;
    
    cout<<"FIN"<<endl;
    return 0;
}

#endif

