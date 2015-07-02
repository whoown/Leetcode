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


bool isValid(string s) {
    vector<char> stack = vector<char>();
    int len = s.size();
    char ch = 0;
    for(int i=0; i<len; i++){
        ch = s[i];
        if(ch == '(')
            stack.push_back(')');
        else if(ch == '[')
            stack.push_back(']');
        else if(ch == '{')
            stack.push_back('}');
        else{
            if(stack.size() <= 0 || ch != stack[stack.size()-1])
                return false;
            stack.pop_back();
        }
    }
    return stack.size() == 0;
}

void test(){
    string s = "";
    cout<<isValid(s)<<endl;
}

int main(int argc, const char * argv[]) {
    test();
    cout<<"GOOD\n";
    return 0;
}

#endif
