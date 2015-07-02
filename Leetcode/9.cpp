//
//  Leetcode
//
//  Created by yan zhang on 15/4/8.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
//  扯淡的题目，要求不用额外空间，和O(1)空间可是不一样的！
//

#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__

int e(int d){
    if(d < 0)
        return 0;
    else if(d == 0)
        return 1;
    else if(d  == 1)
        return 10;
    else if(d == 2)
        return 100;
    else if(d == 3)
        return 1000;
    else if(d == 4)
        return 10000;
    else if(d == 5)
        return 100000;
    else if(d == 6)
        return 1000000;
    else if(d == 7)
        return 10000000;
    else if(d == 8)
        return 100000000;
    else if(d == 9)
        return 1000000000;
    return 0;
}

int len(int x){
    if(x < 0)
        x*=-1;
    
    if(x < 10)
        return 1;
    else if(x / 10 < 10)
        return 2;
    else if(x / 100 < 10)
        return 3;
    else if(x / 1000 < 10)
        return 4;
    else if(x / 10000 < 10)
        return 5;
    else if(x / 100000 < 10)
        return 6;
    else if(x / 1000000 < 10)
        return 7;
    else if(x / 10000000 < 10)
        return 8;
    else if(x / 100000000 < 10)
        return 9;
    else if(x / 1000000000 < 10)
        return 10;
    return 0;
}

int getDigit(int x, int index){ // index from 0
    if(index == 9)
        return x / e(9);
    return (x % e(index+1)) / e(index);
}

bool checkDigit(int x, int len , int d){
    return getDigit(x, d) == getDigit(x, len-1-d);
}

bool check(int x, int len, int now){
    if(now >= len)
        return true;
    //cout<<"check "<<x<<' '<<len<<' '<<now<<endl;
    return checkDigit(x,len,now) && check(x, len, now+1);
}

bool isPalindrome(int x) {
    if(x == -2147483648)
        return false;
    if(x < 0)
        return false;
    return check(x, len(x), 0);
}

int datas[] = {1, 345543, 100001, 100021, INT_MAX, INT_MIN, 1001001};

int main(int argc, const char * argv[]) {
    
//    for(int i=0;i<len(datas[0]);i++){
//        cout<<getDigit(datas[0], i)<<endl;
//    }
//
    for(int i=0; i<sizeof(datas)/sizeof(int); i++){
        cout<<datas[i]<<' '<<len(datas[i])<<' '<<isPalindrome(datas[i])<<endl;
    }
    
    return 0;
}

#endif
