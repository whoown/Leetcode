//
//  32.cpp
//  Leetcode
//
//  Created by Zhang Yan on 15/6/13.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
/*
 1. 进行常规的匹配过程，没找到一对匹配组，记录其位置，例如[0,1] [4,10]。
 2. 新找到的一个匹配组，与过往所有匹配组之间，绝对没有相交，只可能是：相离、相切、或包含。
 3. 将所有匹配组，维护在一个边界有序递增的栈里。
 4. 对新发现的匹配组[x,y]，与过往匹配组进行合并。这需要：
 4.a: 二分寻找x的位置，则处于x之后的所有元素出栈。栈顶变为[x,y]
 4.b: 查看x左侧的元素[a, b]，如果b = x-1, 则[a,b]出栈，栈顶变为[a, y]
 */

#include <stdio.h>
#include "tools.h"
#include "run.h"

using namespace std;

#ifdef __RUN__

struct Seg{
    int x=0, y=0;
    Seg(){
    }
    
    Seg(int a, int b){
        x = a;
        y = b;
    }
};

void adjustSegments(Seg* segs, int &segNum, Seg newSeg){
    
    int left = 0, right = segNum-1, mid, tar=-1;
    while(left <= right){
        mid = (left+right) >> 1;
        if(segs[mid].x > newSeg.x){
            if(mid == 0 || segs[mid-1].x <newSeg.x){ // found
                tar = mid;
                break;
            }else{
                right = mid;
            }
        }else{
            left = mid+1;
        }
    }
    
    if(tar < 0)
        tar = segNum;
    
    if(tar == 0 || segs[tar-1].y != newSeg.x - 1){
        segs[tar] = newSeg;
        segNum = tar+1;
    }else{
        Seg res = Seg(segs[tar-1].x, newSeg.y);
        segs[tar - 1] = res;
        segNum = tar;
    }
    
//    cout<<segNum<<"  ====";
//    for(int i=0; i<segNum; i++){
//        cout<<"("<<segs[i].x<<","<<segs[i].y<<")  ";
//    }
//    cout<<endl;
}



int longestValidParentheses(string s) {
    int len = (int)s.size();
    vector<int> stack = vector<int>();
    Seg *segs = new Seg[len/2];
    int segNum = 0;
    
    for(int i=0; i<len; i++){
        if(s[i] == '('){
            stack.push_back(i); // '('
        }else{ // ')'
            if(stack.size() == 0)
                continue;
            int leftBracketPos = stack[stack.size()-1];
            stack.pop_back();
            Seg newSeg = Seg(leftBracketPos, i);
            adjustSegments(segs, segNum, newSeg);
        }
    }
    
    int res = 0;
    for(int i=0; i<segNum; i++){
        if(segs[i].y - segs[i].x + 1 > res)
            res = segs[i].y - segs[i].x + 1;
    }
    return res;
}

void test(){
    string s = "(((((((()()((((((((())()((()))))))))))))))))"; // 6
    cout<<longestValidParentheses(s)<<endl;
}

int main(int argc, const char * argv[]) {
    test();
    cout<<"GOOD\n";
    return 0;
}

#endif
