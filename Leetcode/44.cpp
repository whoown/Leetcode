//
//  44.cpp
//  Leetcode
//
//  Created by Zhang Yan on 15/6/13.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
/*
 文件名匹配：*代表任意长度字符串，？代表任意字符，检查字符串匹配。
 比较水的DP。这毕竟是leetcode，所以我用一个O(len(s)*len(p))的算法应该可以了。。
 以匹配串为核心进行考虑即可。 1Y~
 */

#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__

bool isMatch(string s, string p) {
    int lens = s.size(), lenp = p.size();
    if(lens == 0 && lenp == 0)
        return true;
    if(lenp == 0)
        return false;
    
    vector<int> idxs; // should be matched string length not the index. whitch means length could be 0 ( the index will be -1 ...)
    if(p[0] == '?'){ // Init the first position match result.
        if(lens == 0)
            return false;
        idxs.push_back(1);
    }
    else if(p[0] == '*'){
        for(int i=0; i<=lens; i++)
            idxs.push_back(i);
    }
    else{
        if(lens == 0 || s[0] != p[0])
            return false;
        idxs.push_back(1);
    }
    
    for(int i=1; i<lenp; i++){
        vector<int> tmp;
        if(p[i] == '?'){
            for(int j=0; j<idxs.size(); j++){
                if(idxs[j] < lens)
                    tmp.push_back(idxs[j] + 1);
            }
        }else if(p[i] == '*') {
            for(int j=idxs[0]; j<=lens; j++)
                tmp.push_back(j);
        }else{
            for(int j=0; j<idxs.size(); j++){
                if(idxs[j] < lens && s[idxs[j]] == p[i])
                    tmp.push_back(idxs[j] + 1);
            }
        }
        /*cout<<p[i]<<endl;
        for(int k=0; k<tmp.size(); k++)
            cout<<tmp[k]<<'-';
        cout<<endl;
         */
        if(tmp.size() <= 0)
            return false;
        idxs = tmp;
    }
    
    for(int i=0; i<idxs.size(); i++)
        if(idxs[i] == lens)
            return true;
    return false;
}

int main(int argc, const char * argv[]) {
    cout<<isMatch("oofsfsfs","*?*?*d*")<<endl;
    cout<<"FIN"<<endl;
    return 0;
}

#endif
