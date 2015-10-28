//
//  42.cpp
//  Leetcode
//
//  Created by Zhang Yan on 15/6/13.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
/*
 这个题不涉及什么算法，考验的单纯就是分析和表述能力。你随意画一段接雨器的图案，人工总会轻易找到最大的储雨量，如何把这种“轻易”的感觉量化为一个逻辑的过程，表达为计算机的算法，就是这一类问题的趣旨所在。在这道题而言，我使用了如下一些思路：
 1. 归纳法：先分析2根雨柱，3根雨柱的情况。早3根雨柱的情形下，添加第4根，尝试观察影响。不难发现，其实任意两根较高柱子之间的所有柱子都可以被删除掉，毫无影响。
 2. 逆向思维：如上的结论会立刻催生这样一种想象。最终，有效储雨的柱子们构成了怎样的排列？不难理解，在最完整情况下，一定是先单调增高，再单调降低的排列顺序。否则就与结论1不符。
 3. 如此一来，就比较容易设计算法了。先排个序，把最高的柱子1，找出来，接下来安排2.3.4..各个次高的柱子，向两边延伸。而如果一个柱子，跑到了两边以内的间隙里，则直接可以忽略掉。
 4. 仔细看题意之后，算法可以不变，但是跑到两个高柱之间的柱子，会占据雨水的空间，因此需要减去他们的体积。这个调整并不复杂。
 5. 1Y ~~
 */

#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__

#define min(x,y) (x < y ? x : y)

struct Pillar{
    int height, idx;
    Pillar(int a, int b){
        height = a;
        idx = b;
    }
};

void qsort(vector<Pillar>& v, int st, int ed){
    if(st >= ed)
        return;
    int div = v[st].height;
    int i = st+1, j = ed;
    while(i < j){// [>=div][div][<div]
        while(v[i].height>= div && i < j) ++i; // i will ends to j.
        while(v[j].height < div && i < j) --j;
        swap(v[i], v[j]);
    }
    if(v[i].height < div)
        --i;
    swap(v[st], v[i]);
    qsort(v, st, i-1);
    qsort(v, i+1, ed);
}

int trap(vector<int>& height) {
    int len = height.size();
    if(len <= 1)
        return 0;
    
    vector<Pillar> v;
    for(int i=0; i<len; i++)
        v.push_back(Pillar(height[i], i));
    qsort(v, 0, len-1);
    
    int mid = v[0].idx, mid_height = v[0].height;
    int left_border = mid, right_border = mid;
    int occupation = 0;
    vector<Pillar> lstack, rstack;
    
    for(int i=1, pos; i<len; i++) {
        pos = v[i].idx;
        if(pos > mid && pos < right_border) {
            occupation += v[i].height;
        }
        else if(pos > mid && pos > right_border){
            right_border = pos;
            rstack.push_back(v[i]);
        }
        else if(pos < mid && pos > left_border){
            occupation += v[i].height;
        }
        else if(pos < mid && pos < left_border){
            left_border = pos;
            lstack.push_back(v[i]);
        }
    }
    int res = 0;
    
    if(lstack.size() > 0){
        res += lstack[0].height * (mid - lstack[0].idx - 1);
        for(int i=0; i<lstack.size()-1; i++){
            res += lstack[i+1].height * (lstack[i].idx - lstack[i+1].idx - 1);
        }
    }
    if(rstack.size() > 0){
        res += rstack[0].height * (rstack[0].idx - mid -1);
        for(int i=0; i<rstack.size()-1; i++){
            res += rstack[i+1].height * (rstack[i+1].idx - rstack[i].idx - 1);
        }
    }
    
    return res - occupation;
}


int main(int argc, const char * argv[]) {
    int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> v;
    for(int i=0; i<sizeof(a)/sizeof(int); i++)
        v.push_back(a[i]);
    
    cout<<trap(v)<<endl;
    cout<<"FIN"<<endl;
    return 0;
}

#endif
