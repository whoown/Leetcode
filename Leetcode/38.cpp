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

string countAndSay(int n) {
    string res = "";
    if(n == 0)
        return res;
    vector<char> *pre = new vector<char>();
    vector<char> *next = new vector<char>();
    vector<char> *stack = new vector<char>();
    vector<char> *tmp;
    pre->push_back('1');
    while(--n){
        pre->push_back('#');
        int ch = 0, cnt = 0;
        for(int i=0, cnt=0; i<pre->size(); i++){
            if((*pre)[i] != ch){
                if(ch){ // store into 'next'
                    stack->clear();
                    while(cnt){
                        stack->push_back(cnt%10);
                        cnt /= 10;
                    }
                    for(int j=stack->size()-1; j>=0; j--)
                        next->push_back('0'+(*stack)[j]);
                    next->push_back(ch);
                }
                ch = (*pre)[i];
                cnt = 1;
            }else{
                ++cnt;
            }
        }
        tmp = pre;
        pre = next;
        next = tmp;
        next->clear();
    }
    
    res = string(pre->size(), '0');
    for(int i=0; i<pre->size(); i++)
        res[i] = (*pre)[i];
    
    return res;
}

void test(){
    for(int i=0; i<200;i++)
    cout<<countAndSay(i)<<endl;
}

int main(int argc, const char * argv[]) {
    test();
    cout<<"GOOD\n";
    return 0;
}

#endif
