//  70.cpp
//  Leetcode
//
//  Created by Zhang Yan on 15/11/3.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
//  Hello-kitty 一样的大水dp
#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__

int climbStairs(int n){
    int* ans = new int[n];
    memset(ans, 0, sizeof(int)*n);
    ans[0] = 1, ans[1] = 2;
    for(int i=2; i<n; i++){
        ans[i] = ans[i-1] + ans[i-2];
    }
    return ans[n-1];
}

int main(int argc, const char * argv[]) {
    cout<<climbStairs(10)<<endl;
    cout<<"FIN"<<endl;
    return 0;
}

#endif
