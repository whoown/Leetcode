//  60.cpp
//  Leetcode
//
//  Created by yan zhang on 15/10/28.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
/* 输出n的排列的第K个排列序列。 小心算算就好。 1Y~ */
#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__

int f[11];

int getKth(int bits, int n, int k){
    for(int i=1, j=0; i<= n; i++){
        if((bits & (1<<i)) == 0)
            ++j;
        if(j == k)
            return i;
    }
    return 1;
}

string getPermutation(int n, int k) {
    if(n == 1)
        return "1";
    string res = "";
    f[1] = 1;
    for(int i=2; i<=9; i++) {
        f[i] = f[i-1] * i;
    }
    
    int bits = 0;
    
    for(int i=n; i>=2; i--){
        int t = k / f[i-1];
        if(t > 0){
            t -= k % f[i-1] ? 0 : 1;
            k -= t*f[i-1];
        }
        int b = getKth(bits, n, t <= 0 ? 1 : t+1);
        bits |= (1<<b);
        res += (char)(b+'0');
    }
    
    res += (char)('0'+getKth(bits, n, 1));
    
    return res;
}


int main(int argc, const char * argv[]) {
    for(int i=1; i<=1; i++)
        cout<<getPermutation(1, i)<<endl;
    cout<<"FIN"<<endl;
    return 0;
}


#endif