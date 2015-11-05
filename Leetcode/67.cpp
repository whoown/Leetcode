//
//  Leetcode
//
//  Created by Zhang Yan on 15/11/3.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
//  二进制加法。。。水到无话可说。。
#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__

string addBinary(string a, string b) {
    string res = "";
    int i=a.size()-1, j=b.size()-1, v1=0, v2=0, carry=0;
    while(i>=0 || j>=0){
        v1 = i>=0 ? a[i]-'0' : 0;
        v2 = j>=0 ? b[j]-'0' : 0;
        v1 += v2 + carry;
        
        carry = v1 / 2;
        v1 %= 2;
        res = (char)(v1+'0')+res;
        --i, --j;
    }
    if(carry)
        res = "1"+res;
    
    return res;
}

int main(int argc, const char * argv[]) {
    cout<<addBinary("1111", "1")<<endl;
    cout<<"FIN"<<endl;
    return 0;
}

#endif
