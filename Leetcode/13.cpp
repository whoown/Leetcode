//
//  Leetcode
//
//  Created by yan zhang on 15/4/8.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
//  明白一点足矣：罗马数字是 十进制 计数法
//
#include <stdio.h>
#include "tools.h"
//#include "run.h"

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

// Ⅰ,1 】Ⅱ，2】 Ⅲ，3】 Ⅳ，4 】Ⅴ，5 】Ⅵ，6】Ⅶ，7】 Ⅷ，8 】Ⅸ，9 】

int getValue(char c){
    for(int i=0,e=1; i<4; i++,e*=10)
        if(c == decStr[i])
            return e;
    for(int i=0,e=5; i<3; i++,e*=10)
        if(c == halfStr[i])
            return e;
    return -1;
}

int romanToInt(string s) {
    int res = 0, len = (int)s.size();
    int i=0, v = 0, nextV = 0;
    while(i < len){
        v = getValue(s[i]);
        nextV = i+1<len ? getValue(s[i+1]) : v;
        if(v >= nextV){
            res += v;
            i+=1;
        }else{
            res += nextV - v;
            i+=2;
        }
    }
    
    return res;
}


int test[]  = {29, 30, 34, 35, 39, 40 , 50, 1000, 1100, 1400, 1666, 1984, 3999, 1888
};

int main(int argc, const char * argv[]) {
    int cnt = 1000;
    srand(time(0));
    while(cnt--){
        int num = rand()%3999+1;
        if(num != romanToInt(intToRoman(num))) {
            cout<<"Fail: "<<num<<endl;
            break;
        }
    }
    cout<<"GOOD\n";
    return 0;
}

#endif
