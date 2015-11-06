//
//  Leetcode
//
//  Created by Zhang Yan on 15/11/3.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
//  leetcode hard级别的题，就是像这样的模拟题，垃圾无趣！！
#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__

bool is_full(vector<string> v, int w){
    int len = v.size()-1;
    for(int i=0; i<v.size(); i++)
        len += v[i].size();
    return len > w;
}

string process(vector<string> v, int w){
    if(v.size() == 1) {
        return v[0] + string(w-v[0].size(), ' ');
    }
    int wlen = 0;
    for(int i=0; i<v.size(); i++)
        wlen += v[i].size();
    int div = (w - wlen) / (v.size()-1);
    int app = (w - wlen) % (v.size()-1);
    
    string res = v[0];
    for(int i=1; i<v.size(); i++){
        res += string(i<=app ? div+1 : div, ' ') + v[i];
    }
    return res;
}

vector<string> fullJustify(vector<string>& words, int w) {
    int len = words.size();
    vector<string> res, tmp;
    int st = 0, ed = 0, sum = 0;
    for(int i=0; i<len; i++){
        tmp.push_back(words[i]);
        if(is_full(tmp, w)){
            tmp.pop_back();
            res.push_back(process(tmp, w));
            tmp = vector<string>();
            --i;
        }
    }
    if(tmp.size() > 0){
        string str = tmp[0];
        for(int i=1; i<tmp.size(); i++)
            str += " "+tmp[i];
        str += string(w-str.size(), ' ');
        res.push_back(str);
    }
    
    return res;
}


int main(int argc, const char * argv[]) {
    //string dict[] = {"This", "is", "1234567812345678","an", "1234567812345678","example", "of", "text", "justification.", "1234567812345678", "ha", "ab", "er", "fuc"};
    string dict[] = {""};
    
    vector<string> v;
    for(int i=0; i<sizeof(dict)/sizeof(string); i++)
        v.push_back(dict[i]);
    
    v = fullJustify(v, 16);
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<endl;
    
    cout<<"FIN"<<endl;
    return 0;
}

#endif
