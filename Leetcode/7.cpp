//
//  Leetcode
//
//  Created by yan zhang on 15/4/8.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
//

#include <stdio.h>
#include "tools.h"
// #include "run.h"

using namespace std;

#ifdef __RUN__

int reverse(int x) {
    if(x ==-2147483648)
        return 0;
    int d[50], p = -1, sign=x>0?1:-1;
    memset(d, 0, sizeof(int)*50);
    x = x > 0 ? x : -x;
    while(x){
        d[++p] = x%10;
        x/=10;
    }
    double res = 0, e = 1;
    for(int i=p; i>=0;i--,e*=10) {
//        cout<<d[i] << '-' <<d[i]*e<<"  "<<res<<endl;
        res += d[i] * e;
    }
    
    if(res > 2147483647)
        return 0;
    
    return (int)res * sign;
}

int main(int argc, const char * argv[]) {
    int a = 1534236469;
    int b = 9600000000;
    int c = -2147483648;
    cout<<a<<endl<<b<<endl<<c<<endl;
    cout<<reverse(1000);
    return 0;
}

#endif
