//
//  Leetcode
//
//  Created by yan zhang on 15/10/28.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
/* 水到不能忍。。hello world。。*/
#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__

int lengthOfLastWord(string s) {
    string preWord="";
    string buf="";
    for(int i=0; i<s.size(); i++){
        if(s[i] == ' '){
            if(buf.size() > 0)
                preWord = buf;
            buf = "";
        }else{
            buf += s[i];
        }
    }
    if(buf.size() > 0)
        preWord = buf;
    return preWord.size();
}

int main(int argc, const char * argv[]) {
    cout<<lengthOfLastWord("   ")<<endl;
    cout<<"FIN"<<endl;
    return 0;
}


#endif