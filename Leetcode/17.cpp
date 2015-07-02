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

string dig_alphas[10] = {"","","abc","def","ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void dfs(string str, int index, string path, vector<string>& output){
    if(index >= str.size()) {
        if(path.size() > 0)
            output.push_back(path);
        return;
    }
    int k = str[index] - '0';
    if(k < 2 || k > 9) {
        dfs(str, index+1, path, output);
        return;
    }
    string alpha = dig_alphas[k];
    
    for(int i=0; i<alpha.size(); i++){
        dfs(str, index+1, path+alpha[i], output);
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> res = vector<string>();
    res.clear();
    dfs(digits, 0, "", res);
    return res;
}


int main(int argc, const char * argv[]) {
    vector<string> res = letterCombinations("1");
    for(int i=0; i<res.size(); i++)
        cout<<res[i]<<' ';
    cout<<endl;
    cout<<"GOOD\n";
    return 0;
}

#endif
