//
//  Leetcode
//
//  Created by yan zhang on 15/4/8.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
//

#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__

string trim(string str, char ch){
    int len=(int)str.length(), i=0, j=(int)str.length()-1;
    while(i<len && str[i]==ch) i++;
    while(j>=0 && str[j]==ch) j--;
    if(j<i)
        return "";
    return str.substr(i, j-i+1);
}

int str_to_int(string str, int sign){
    double res = 0, e = 1;
    int len = (int)str.length();
    for(int i=len-1; i>=0; i--, e*=10){
        res += (str[i]-'0')*e;
    }
    res *= sign;
    if(res > 2147483647)
        return 2147483647;
    if(res < -2147483648)
        return -2147483648;
    return (int)res;
}

int atoi2(string str) {
    str = trim(str, ' ');
    str = trim(str, '\n');
    str = trim(str, '\r');
    int len = (int)str.length();
    
    if(len <= 0)
        return 0;
    int sign = 0, start = -1, end = len-1;
    char ch;
    
    for(int i=0; i<len; i++){
        ch = str[i];
        if(i == 0 && (ch == '-' || ch == '+')){
            sign = ch == '-' ? -1 : 1;
            continue;
        }
        if(ch < '0' || ch > '9'){
            end = i-1;
            break;
        }else if(start < 0){
            start = i;
        }
    }
    
    //cout<<start<<'#'<<end<<endl;
    
    if(start < 0 || end < start)
        return 0;
    str = str.substr(start, end-start+1);
    return str_to_int(str, sign?sign:1);
}

const char* test_cases[] = {
    "", "   ", "+", "-",".",
    "123.456", ".4567", "0.345",
    "++345", "--345", "3423-987", "..345","+-87","893####",
    "10000", "00009999", "9", "2147483647", "-2147483648",
    "2147483648", "-2147483649", "-100000000000000", "4535352352525255"
};

void test(){
    int len = sizeof(test_cases) / sizeof(test_cases[0]);
    for(int i=0; i<len; i++){
        const char* s = test_cases[i];
        string ss = string(s);
        int res1 = atoi(s);
        int res2 = atoi2(ss);
        cout<<"test"<<i<<": "<<ss<<endl<<res1<<" : "<<res2<<endl;
        if(res1!=res2){
            cout<<"fuck\n";
            return;
        }
    }
    cout<<"ok!!\n";
}

void test2(){
    int times = 10000;
    srand(time(0));
    while(times--){
        int n = rand();
        int m = n;
        string s = "";
        while(m){
            s = (char)('0'+(m%10))+s;
            m/=10;
        }
        if(atoi2(s) != n){
            cout<<n<<' '<<s<<' '<<atoi2(s)<<endl<<"fucking\n";
            return;
        }
    }
    cout<<"ok!!\n";
}


int main(int argc, const char * argv[]) {
    test2();
    return 0;
}

#endif
