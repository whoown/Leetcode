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
#define MAXN 2010

int r[MAXN];

string longestPalindrome(string str) {
    memset(r, 0, MAXN*sizeof(int));
    r[0] = 1;
    int len = (int)str.length()*2+1, range_right = 0, range_center = 0;
    char *s = new char[len+1];
    char *p = s;
    for(int i=0; i<str.length(); i++){
        *(p++) = '#';
        *(p++) = str[i];
    }
    *p = '#';

    for(int i=1, j=0; i<len; i++, j=0){
        if(i < range_right){
            int i2 = 2*range_center - i;
            if(r[i2] < range_right - i + 1){
                r[i] = r[i2];
                continue; // this's impossible exceed the right border
            }
            j = range_right - i + 1;
        }
        
        for(; i-j>=0 && i+j<len && s[i-j] == s[i+j]; j++);
        r[i] = --j + 1;
        
        if(i + r[i] - 1 > range_right){
            range_right = i + r[i] - 1;
            range_center = i;
        }
    }
    
    int res_r = 0, res_left = 0;
    for(int i=0; i<len; i++) {
        if(res_r < r[i]){
            res_r = r[i];
            res_left = i - r[i] + 2; // #..a..#
        }
    }
    
    delete[] s;
    return str.substr((res_left-1)/2, res_r-1);
}

int search2(string s){
    int len = s.length(), max_len = 1, left = 0, right = 0;
    for(int i=0; i<len; i++){
        int r = 0;
        while(i-r>=0 && i+r<len && s[i-r] == s[i+r]){
            ++r;
        }
        if(2*r-1 > max_len){
            max_len = 2*r - 1;
            left = i-(r-1);
            right = i+(r-1);
        }
        if(i == 0 || s[i] != s[i-1])
            continue;
        r = 0;
        while(i-1-r>=0 && i+r<len && s[i-1-r] == s[i+r]){
            ++r;
        }
        if((i+r-1) - (i-1 - (r-1)) + 1 > max_len){
            max_len = (i+r-1) - (i-1 - (r-1)) + 1;
            left = i-1 - (r-1);
            right = i+(r-1);
        }
    }
    //cout<<max_len<<' '<<left<<' '<<right;
    return max_len;
}

void test(){
    int test_times = 20;
    srand(time(0));
    while(--test_times){
        string s = random_string(200, 1);
        cout<<s<<endl;
        int res1 =  search2(s);
        string res = longestPalindrome(s);
        int res2 = res.length();
        cout<<res1<<' '<<res2<<' '<<res<<endl;
        if(res1 != res2){
            cout<<"Fucking!!! "<<s<<endl;
            break;
        }
    }
    
    cout<<"OK!!!"<<endl;
    
}

int main(int argc, const char * argv[]) {
    char* s = new char[10];
    char* str = s;
    s[2] = 0;
    *s = 'a';
    *(++s) = 'b';
    cout<<str<<endl;
    test();
    return 0;
}

#endif
