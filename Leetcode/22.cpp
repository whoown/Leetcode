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

void dfs(int n, int left, int right, string path, vector<string>& output){
    if(left == n){
        output.push_back(path+string(n-right, ')'));
        return;
    }
    dfs(n, left+1, right, path+"(", output);
    if(right+1 <= left)
        dfs(n, left, right+1, path+")", output);
}

vector<string> generateParenthesis(int n) {
    vector<string> res = vector<string>();
    if(n<=0)
        return res;
    dfs(n, 0, 0, "", res);
    return res;
}

/*
 ( (
 ( ) 
 
 ( ( (
 ( ( )
 */

// "((()))", "(()())", "(())()", "()(())", "()()()"

void test(){
    for(int i=0; i<100; i++){
        time_t t1 = clock();
        vector<string> res = generateParenthesis(i);
        time_t t2 = clock();
        cout<<i<<' '<<(t2-t1)<<endl;
        //for(int j=0; j<res.size(); j++)
        //    cout<<res[j]<<',';
//        cout<<endl;
        
    }
}

int main(int argc, const char * argv[]) {
    test();
    cout<<"GOOD\n";
    return 0;
}

#endif
