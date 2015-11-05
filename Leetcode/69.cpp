//  69.cpp
//  Leetcode
//
//  Created by Zhang Yan on 15/11/3.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
//  Hello-kitty 一样的大水二分。还不错，会有溢出的陷阱~
#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__

#define div2(a,b) (a>>1)+(b>>1)+((a&1)&&(b&1))

int mySqrt(int x) {
    if(x<=0)
        return 0;
    double left = 1, right =x, mid = 0;
    while(left < right){
        mid = (int)((left + right)/2);
        if(mid*mid <= x && x<(mid+1)*(mid+1)){
            left = mid;
            break;
        }
        else if(x < mid*mid){
            right = mid;
        }
        else {
            left = mid+1;
        }
    }
    return (int)left;
}

int main(int argc, const char * argv[]) {
    //for(int i=0; i<100; i++)
    //cout<<i<<' '<<mySqrt(i)<<endl;
    cout<<mySqrt(2147395599)<<endl;
    cout<<"FIN"<<endl;
    return 0;
}

#endif
