//
//  Leetcode
//
//  Created by yan zhang on 15/4/8.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
//  将Pattern拆成N个独立的匹配单元，每个单元匹配0~M个字符。按顺序搜索这N个单元，就是这样一个搜索问题。用深搜，还可以有剪枝的余地。
//  Result 1Y
//

#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__

const int UNIT_CHAR = 0;
const int UNIT_CHAR_ARRAY = 2;

struct Unit{
    int type;
    char ch;
    Unit(){
        type = ch = 0;
    }
    Unit(int t, char c){
        type = t;
        ch = c;
    }
};

Unit* mUnits = NULL;
int mUnitNum;

void parsePattern(string p){
    if(mUnits != NULL){
        delete[] mUnits;
    }
    mUnitNum = 0;
    int len = (int)p.size(), i =0;
    mUnits = new Unit[len];
    while(i < len){
        char ch = p[i];
        if(i+1<len && p[i+1] == '*') {
            mUnits[mUnitNum++] = Unit(UNIT_CHAR_ARRAY, ch);
            i+=2;
        }
        else {
            mUnits[mUnitNum++] = Unit(UNIT_CHAR, ch);
            i+=1;
        }
    }
}

bool matchComplete = false;

void dfs(string s, int index, int patIndex){
    int len = (int)s.length();
    if(matchComplete)
        return;
    if(patIndex >= mUnitNum){
        if(index >= s.length())
            matchComplete = true;
        return;
    }
    Unit u = mUnits[patIndex];
    
    if(u.type == UNIT_CHAR){
        if(index >= len)
            return;
        if(u.ch == '.' || u.ch == s[index]){
            dfs(s, index+1, patIndex+1);
        }
        return;
    }
    
    if(u.type == UNIT_CHAR_ARRAY){
        if(index >= len) {
            dfs(s, index, patIndex+1);
            return;
        }
        dfs(s, index, patIndex+1); // jump over current pat unit.
        
        char firstChar = s[index];
        for(int i=0; index+i<len; i++){
            if(u.ch == '.'){
                dfs(s, index+i+1, patIndex+1);
            } else if(u.ch == firstChar && s[index+i] == firstChar){
                dfs(s, index+i+1, patIndex+1);
            } else{
                return; // dismatch
            }
        }
    }
}

struct T{
    string s;
    string p;
    T(string s1, string s2){
        s = s1;
        p = s2;
    }
};

/*
 T("aab", "c*a*b"), T("aba","abc*a"), T("fasfkldsjljxlfjsldfja", ".*"), T("cccccbc", "c*b*c*"), T("abccba", "abccba")
 
 */

T datas[] = {T("aaaab", "a*aaaaab"), T("aaaaab", "a*aaaaab"),  T("aaaaaaaab", "a*aaaaab")};

bool isMatch(string s, string p) {
    parsePattern(p);
//    for(int i=0; i<mUnitNum; i++)
//        cout<<"unit"<<i<<' '<<mUnits[i].type << ' '<<mUnits[i].ch<<endl;

    matchComplete = false;
    dfs(s, 0, 0);
    return matchComplete;
}


int main(int argc, const char * argv[]) {
    
    for(int i=0; i<sizeof(datas)/sizeof(datas[0]); i++)
        cout<<sizeof(datas[i])<<' '<<datas[i].s<<' '<<datas[i].p<<'\n'<<isMatch(datas[i].s, datas[i].p)<<endl;
    
//    cout<<isMatch("", "212*dsf*..*..*......*.");
    
    cout<<"Good\n";
    return 0;
}

#endif
