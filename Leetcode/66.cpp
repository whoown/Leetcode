//
//  Leetcode
//
//  Created by Zhang Yan on 15/11/3.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
//  水到无话可说。。
#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__

vector<int> plusOne(vector<int>& d) {
    int carry = 1;
    for(int i=d.size()-1; i>=0 ;i--){
        d[i] += carry;
        carry = (d[i])/10;
        d[i] %= 10;
    }
    vector<int> res;
    if(carry)
        res.push_back(1);
    for(int i=0; i<d.size(); i++)
        res.push_back(d[i]);
    return res;
}

int main(int argc, const char * argv[]) {
    int a[] = {9};
    vector<int> v;
    for(int i=0; i<sizeof(a)/sizeof(int); i++)
        v.push_back(a[i]);
    v = plusOne(v);
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<' ';
    cout<<endl;
    
    cout<<"FIN"<<endl;
    return 0;
}

#endif
