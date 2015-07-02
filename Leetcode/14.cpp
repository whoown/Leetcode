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


string longestCommonPrefix(vector<string>& strs) {
    int len = (int)strs.size();
    if(len <= 0)
        return "";
    if(len <= 1)
        return strs[0];
    
    string res="";
    int p = 0, ch = 0;
    while(1){
        for(int i=0; i<len; i++){
            //cout<<i<<' '<<strs[i]<<' '<<strs[i].size()<<endl;
            if(p >= strs[i].size())
                return res;
            if(!ch){
                ch = strs[i][p];
            }else if(ch != strs[i][p]){
                return res;
            }
        }
        //cout<<p<<' '<<ch<<endl;
        res += (char)ch;
        ch = 0;
        ++p;
    }
    
    return res;
}

string test[] = {"abcd", "abbbc", "abder", "aaa", "a"};

int main(int argc, const char * argv[]) {
    vector<string> v = vector<string>();
    for(int i=0; i<sizeof(test)/sizeof(test[0]); i++)
        v.push_back(test[i]);
    cout<<longestCommonPrefix(v)<<endl;
    cout<<"GOOD\n";
    return 0;
}

#endif
