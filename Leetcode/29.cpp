//
//  Leetcode
//
//  Created by yan zhang on 15/4/8.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__

// a / b
int divide(int a, int b) {
    if(b == 0)
        return INT_MAX;
    if(a == 0 || b == 1)
        return a;
    if(a == INT_MIN){
        if(b == -1)
            return INT_MAX;
        else if(!(b & 1)){
            a = a >> 1, b = b >> 1;
        }else{
            ++a;
        }
    }else if(b == INT_MIN){
        return 0;
    }
    
    bool positive = (a < 0) == (b < 0);
    a = abs(a);
    b = abs(b);
    
    int num = a, half = (num>>1) + (num&1), res = 0, i;
    while(num >= b){
        for(i=0; i<32; i++){
            if( (b<<i) >= half) // next double will exceed or reach the limit.
                break;
        }
        num -= (b<<i);
        half = (num>>1) + (num&1);
        res += (1<<i);
    }
    
    return positive ? res: -res;
}

void test(){
    int cnt = 100000;
    srand(time(0));
    while(cnt--){
        int a = rand();
        int b = rand();
        int res = a / b;
        if(res != divide(a, b)){
            cout<<a<<' '<<b<<endl;
            break;
        }else{
            cout<<cnt<<"ok\n";
        }
    }
    cout<<"done\n";
}

int main(int argc, const char * argv[]) {
    cout<<"go:"<<divide(1, -1)<<endl<<(671729623/438241482)<<endl;
    //test();
    cout<<"GOOD\n";
    return 0;
}

#endif
