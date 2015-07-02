//
//  Leetcode
//
//  Created by yan zhang on 15/4/8.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
//  明白一点足矣：罗马数字是 十进制 计数法
//
#include <stdio.h>
#include "tools.h"
// #include "run.h"

using namespace std;

#ifdef __RUN__


string decStr = "IXCM";
string halfStr = "VLD";

string intToRoman(int val) {
    string res = "";
    for(int i=3, e=1000; i>=0; i--, e/=10){ // from 1 to 1000
        int num = (val % (10*e)) / e;
        if(num <= 0)
            continue;
        if(num <= 3)
            res += string(num, decStr[i]);
        else if(num == 4)
            res += decStr[i] + string(1, halfStr[i]);
        else if(num <= 8)
            res += halfStr[i] + string(num-5, decStr[i]);
        else
            res += string(10-num, decStr[i]) + decStr[i+1];
        
        //cout<<i<<' '<<num<<' '<<res<<endl;
    }
    return res;
}


int test[]  = {29, 30, 34, 35, 39, 40 , 50, 1000, 1100, 1400, 1666, 1984, 3999, 1888
};

int main(int argc, const char * argv[]) {
    for(int i=1; i<20; i++)
    cout<<intToRoman(i)<<endl;
    for(int i=0; i<sizeof(test)/sizeof(test[0]); i++)
        cout<<test[i]<<' '<<intToRoman(test[i])<<endl;
    cout<<"something\n";
    return 0;
}

#endif
