//  71.cpp
//  Leetcode
//
//  Created by Zhang Yan on 15/11/3.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
//  Hello-kitty 简单的链表大水题
#include <stdio.h>
#include "tools.h"
#include "run.h"

using namespace std;

#ifdef __RUN__

string simplifyPath(string s) {
    s += "/";
    vector<int> idxs;
    for(int i=0; i<s.size(); i++)
        if(s[i] == '/')
            idxs.push_back(i);
    vector<string> path;
    for(int i=0; i<idxs.size()-1; i++){
        if(idxs[i+1] - idxs[i] > 1){
            string file = s.substr(idxs[i]+1, idxs[i+1]-idxs[i]-1);
            if(file == ".")
                continue;
            if(file == "..") {
                if(path.size() > 0)
                path.pop_back();
            }
            else
                path.push_back(file);
        }
    }
    string res = "/";
    for(int i=0; i<path.size(); i++)
        res += path[i]+(i<path.size()-1 ? "/":"");
    
    return res;
}

int main(int argc, const char * argv[]) {
    cout<<simplifyPath("/../../..")<<endl;
    cout<<"FIN"<<endl;
    return 0;
}

#endif
