//
//  43.cpp
//  Leetcode
//
//  Created by Zhang Yan on 15/6/13.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
/*
高精乘法，大水
*/

#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__

string multiply(string num1, string num2) {
    int len1 = num1.size(), len2 = num2.size();
    int len = len1 + len2 + 1;
    int* a = new int[len];
    memset(a, 0, sizeof(int)*len);
    
    for(int i=0; i<len1; i++) {
        for(int j=0; j<len2; j++){
            a[i+j] += (num1[len1-1-i]-'0') * (num2[len2-1-j]-'0');
        }
    }
    
    for(int i=0; i<len-1; i++){
        a[i+1] += a[i] / 10;
        a[i] %= 10;
    }
    
    string res = "";
    for(int i=len-1, start=0; i>=0; i--){
        start = start || a[i] ? 1 : 0;
        if(start)
            res += ('0'+a[i]);
    }
    if(res.size() == 0)
        res += "0";
    return res;
}

int main(int argc, const char * argv[]) {
    cout<<multiply("10","100000")<<endl;
    cout<<"FIN"<<endl;
    return 0;
}

#endif
