//  72.cpp
//  Leetcode
//
//  Created by Zhang Yan on 15/11/3.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
/* 两个单词word1, word2，允许三种操作：删除某个字母；插入某个字母；替换某个字母；问从word1变换到word2的最小操作步数。
 这个还稍微有点意思。<人的脑子就是时而不时的会抽风；这个问题其实很简单的DP；但是一旦陷入“缺乏条理”的细节中，你就完了！>
 */
#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__


#define max(a,b) (a>b ? a : b)
#define min(a,b) (a<b ? a : b)

/*
 设d[i][j]，表示字串 s1(0-i), s2(0-j) 之间的编辑距离，并且只编辑s1字符串。那么，d[i][j]有如下三种转化途径：
 d[i][j] = d[i-1][j-1] + s1[i]==s2[j] ? 1 : 0  // 不相同 则s1做一次替换
 d[i][j] = d[i-1][j] + 1                       // s1 需要进行一次删除
 d[i][j] = d[i][j-1] + 1                       // s1 需要进入一次插入
 d[i][j] 则为三种转化途径得到的最小结果~
 */

int minDistance(string word1, string word2) {
    int len1 = word1.length();
    int len2 = word2.length();
    vector<vector<int>> d;
    for(int i=0; i<len1+1; i++)
        d.push_back(vector<int>(len2+1));
    for(int i=0; i<=len1; i++)
        d[i][0] = i;
    for(int i=0; i<=len2; i++)
        d[0][i] = i;
    
    for(int i=1; i<=len1; i++)
        for(int j=1; j<=len2; j++) {
            d[i][j] = d[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0 : 1);
            d[i][j] = min(d[i][j], d[i-1][j] + 1);
            d[i][j] = min(d[i][j], d[i][j-1] + 1);
        }
    
    /*
    for(int i=0; i<=len1; i++) {
        for(int j=0; j<=len2; j++)
            cout<<d[i][j]<<' ';
        cout<<endl;
    }
     */
    
    return d[len1][len2];
}

int main(int argc, const char * argv[]) {
    cout<<minDistance("abcd", "axbxcxdx")<<endl;
    cout<<"FIN"<<endl;
    return 0;
}

#endif
