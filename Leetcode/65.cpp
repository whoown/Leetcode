//
//  Leetcode
//
//  Created by Zhang Yan on 15/11/3.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
//  这种无脑的问题，最适合在这个办公室里处理。头晕，深呼吸。
#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__


bool is_number(char ch){
    return ch>='0' && ch<='9';
}

bool is_hex(char ch){
    return
    (ch >= '0' && ch <= '9') ||
    (ch >= 'a' && ch <= 'f') ||
    (ch >= 'A' && ch <= 'F');
}

bool is_oct(char ch){
    return ch>='0' && ch<='7';
}

bool start_with(string str, string prefix){
    if(str.size() < prefix.size())
        return false;
    for(int i=0; i<prefix.size(); i++)
        if(str[i] != prefix[i])
            return false;
    return true;
}

string trim(string s){
    int st = -1, ed = -1;
    for(int i=0; i<s.size() && s[i]==' '; i++)
        st = i;
    for(int i=s.size()-1; i>=0 && s[i]==' '; i--)
        ed = i;
    st = st < 0 ? 0 : st+1;
    ed = ed < 0 ? s.size()-1 : ed-1;
    if(st > ed)
        return "";
    return s.substr(st, ed-st+1);
}

bool is_integer(string s, bool withOct){
    if(s.size() <= 0)
        return false;
    for(int i=0; i<s.size(); i++) {
        if(withOct && s[0] =='0'){
            if(!is_oct(s[i]))
                return false;
        }else if(!is_number(s[i]))
            return false;
    }
    return true;
}


bool is_float(string s){
    int len = s.size();
    if(len <=0)
        return false;
    int idx = s.find('.'); //3.14
    if(idx < 0)
        return is_integer(s, false);
    
    string num1 = s.substr(0, idx);
    string num2 = idx+1<len ? s.substr(idx+1) : "";
    
    if(num1.size()<=0 && num2.size()<=0)
        return false;
    if(num1.size() > 0 && !is_integer(num1, false))
        return false;
    if(num2.size() > 0 && !is_integer(num2, false))
        return false;
    return true;
}


bool isNumber(string s) {
    s = trim(s);
    if(s.size() <= 0)
        return false;
    if(s[0] == '-' || s[0] == '+') //
        s = s.substr(1);
    if(s.size() <= 0)
        return false;
    
    if(start_with(s, "0x") || start_with(s, "0X")){ //
        s = s.substr(2);
        if(s.size() <= 0)
            return false;
        for(int i=0; i<s.size(); i++)
            if(!is_hex(s[i]))
                return false;
        return true;
    }
    
    int eindex = s.find('e');
    if(eindex == -1)
        eindex = s.find('E');
    if(eindex < 0){
        if(s.find('.') < 0)
            return is_integer(s, true);
        return is_float(s);
    }
    
    if(s[0] == 'e' || s[0] == 'E' || s[s.size()-1] == 'e' || s[s.size()-1] == 'E')
        return false;
    
    string num1 = s.substr(0, eindex);
    string num2 = s.substr(eindex+1);
    if(num2[0] == '-' || num2[0]=='+')
        num2 = num2.substr(1);
    if(!is_integer(num2, false))
        return false;
    if(!is_float(num1))
        return false;
    
    return true;
}


int main(int argc, const char * argv[]) {
    
    int a=  1.e009;
    
    string s[] = {"0 0", "0076","0987","0","0x", "0xfFe0e1", "0XfA0R", "-9e-10", "09e+98", "e+", "1e+", "1e1", ".", ".8", "8.", "8.e10", ".8e-10"};
    for(int i=0; i<sizeof(s)/sizeof(string); i++)
        cout<<s[i]<<' '<<isNumber(s[i])<<endl;
    
    
    cout<<is_float(".8.")<<endl;
    cout<<"FIN"<<endl;
    return 0;
}

#endif
