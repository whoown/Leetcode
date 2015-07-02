//
//  3.cpp
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

#define max(x,y) x > y ? x : y

struct Node{
    int idx;
    Node* next;
    Node(int index){
        idx = index;
        next = 0;
    }
};

Node* alpha[257];
Node* tails[257];

int lengthOfLongestSubstring(string s) {
    memset(alpha, 0, 257*sizeof(Node*));
    memset(alpha, 0, 257*sizeof(Node*));
    unsigned long len = s.length();
    int ch = 0;
    for(int i=0; i<len; i++){
        ch = s[i];
        Node *node = new Node(i);
        if(!alpha[ch]){
            alpha[ch] = tails[ch] = node;
        }else{
            tails[ch]->next = node;
            tails[ch] = node;
        }
    }
    int left = 0, right = 0, max_len = len ? 1 : 0, current_index;
    while(++right < len){
        ch = s[right];
        current_index = alpha[ch]->idx;
        if(current_index < right){ // occurs before.
            if(current_index + 1 > left)
                left = current_index + 1;
            alpha[ch] = alpha[ch]->next;
        }
        max_len = max(max_len, right - left + 1);
    }
    
    return max_len;
}


bool check_duplicate(string s, int i, int j){
    for(int x = i; x <= j; x++)
        for(int y = x+1; y <= j; y++)
            if(s[x] == s[y])
                return true;
    return false;
}

string alphas = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

string random_string2(int len){
    int alpha_len = alphas.length();
    string res = "";
    for(int i=0; i<len; i++){
        int idx = rand() % alpha_len;
        res += alphas[idx];
    }
    return res;
}

void fucking_test(){
    int TEST_TIMES = 10000;
    srand(time(0));
    while(--TEST_TIMES > 0){
        string s = random_string2(100);
        int max_len1 = lengthOfLongestSubstring(s);
        
        int max_len2 = 1;
        for(int i=0; i<s.length(); i++)
            for(int j=i; j<s.length(); j++){
                if(!check_duplicate(s, i, j)){
                    max_len2 = max(max_len2, j-i+1);
                }
            }
        
        cout<<s<<endl;
        if(max_len1 != max_len2){
            cout<<"FUCKING!!"<<max_len1<<"   "<< max_len2<<endl;
            break;
        }
        
        
    }
    if(TEST_TIMES <= 0)
    cout<<"OK!!!"<<endl;
}

int main(int argc, const char * argv[]) {
    string s = "";
    cout<<lengthOfLongestSubstring(s)<<endl;
    //fucking_test();
    return 0;
}

#endif
