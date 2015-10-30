//
//  50.cpp
//  Leetcode
//
//  Created by yan zhang on 15/10/28.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
/* 简直水死。。hello-world级别。。
 */

#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__

double myPow(double x, int n) {
    if(n == 0)
        return 1;
    if(n == 1)
        return x;
    bool neg = false;
    if(n < 0) {
        n *= -1;
        neg = true;
    }
    double r = myPow(x, n/2);
    double res = r*r*(n&1 ? x : 1);
    return neg ? 1/res : res;
}

int main(int argc, const char * argv[]) {
    cout<<myPow(34,-3)<<endl;
    cout<<"FIN"<<endl;
    return 0;
}



#endif