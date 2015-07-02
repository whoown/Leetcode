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

string convert(string s, int nRows) {
    if(s.length() == 0 || nRows <= 1)
        return s;
    int len = (int)s.length();
    string res(len, '#');
    if(nRows == 2){
        for(int i=0, p=0; i<2 && p<len; i++){
            for(int j=0; 2*j+i<len && p<len; j++){
                res[p++] = s[2*j+i];
            }
        }
        return res;
    }
    
    int group_size = 2*nRows - 2;
    int group_count = (len + group_size-1) / group_size;
    
    //cout<<group_size<<' '<<group_count<<endl;
    
    for(int i=0, p=0; i<nRows && p<len; i++){
        for(int j=0; j<group_count && p<len; j++){
            if(group_size*j + i >= len)
                continue;
            //cout<<"------"<<i<<' '<<j<<endl;
            res[p++] = s[group_size*j + i];
            //cout<<group_size*j + i<<'+'<<res[p-1]<<'+'<<p<<endl;

            if(p >= len)
                break;
            if(i == 0 || i == nRows - 1 || group_size*j+(group_size-i) >=len)
                continue;
            res[p++] = s[group_size*j + (group_size - i)];
            //cout<<res[p-1]<<' '<<p<<endl;
        }
    }
    return res;
}

// "PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"
int main(int argc, const char * argv[]) {
    cout<<convert("ABCDEF", 3)<<endl;
}

#endif
