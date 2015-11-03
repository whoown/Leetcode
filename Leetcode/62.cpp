//
//  62.cpp
//  Leetcode
//
//  Created by Zhang Yan on 15/11/3.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
//  水的一笔，高中时的排列组合问题，1Y。

#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__


int uniquePaths(int m, int n) {
    // calc C(m+n-2, n-1) or C(m+n-2, m-1);
    int k = m+n-2;
    int t = m < n ? m-1 : n-1;
    double res = 1; // 防溢出
    for(int i=0; i<t; i++)
        res *= (k-i);
    for(int i=0; i<t; i++)
        res /= (i+1);
    return (int)(res+0.5);
}

int main(int argc, const char * argv[]) {
    
    cout<<uniquePaths(3, 4)<<endl;
    
    cout<<"FIN"<<endl;
    return 0;
}

#endif
