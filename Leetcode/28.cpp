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



int* getNext(string p){
    int len = (int)p.size();
    int* next = new int[len];
    memset(next, -1, sizeof(int)*len);
    
    for(int i=1; i<len; i++){
        int j = next[i-1];
        while(j >= 0 && p[j] != p[i-1])
            j = next[j];
        if(j < 0)
            next[i] = 0;
        else
            next[i] = j + 1; // p[j] == p[i-1]
    }
    
    return next;
}

// ababcdxyz  <-  ababd
int kmp(string s, string p){
    int* next = getNext(p);
    int i=0, j=0, slen = (int)s.size(), plen = (int)p.size();
    while(i < slen && j<plen){
        if(s[i] == p[j] || j == -1){
            ++i, ++j;
        }else{
            j = next[j];
        }
    }
    
    return j == plen ? i-plen : -1;
}

// search p in str
int strStr(string str, string p) {
    if(p.size() == 0)
        return 0;
    return kmp(str, p);
}

int std_case(string str, string p){
    for(int i=0; i<str.size(); i++){
        int j = 0;
        for(j=0; j<p.size(); j++){
            if(i+j<str.size() && str[i+j] == p[j])
                continue;
            else
                break;
        }
        if(j == p.size())
            return i;
    }
    return -1;
}


void test(){
    int cnt = 10000;
    srand(time(0));
    while(--cnt){
    string s = random_string(1000, "abc");
    string p = random_string(10, "ab");
        //cout<<s<<endl<<p<<endl;
        int a = std_case(s, p);
        int b = kmp(s,p);
        if(a != b){
            cout<<a<<' '<<b<<endl;
            break;
        }else{
            cout<<cnt<<" ok!"<<a<<endl;
            //if(a>0)
            //cin>>b;
        }
    }
}

int main(int argc, const char * argv[]) {
    test();
    cout<<"GOOD\n";
    return 0;
}

#endif
