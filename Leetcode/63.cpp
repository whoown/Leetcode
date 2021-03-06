//
//  63.cpp
//  Leetcode
//
//  Created by Zhang Yan on 15/11/3.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
//  简直日狗！这题居然用DP做，想了好久的数学解法，发现好难好难。。居然不是。。

#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__

void print(int** ary, int n, int m){
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++)
            cout<<ary[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl;
}

int uniquePathsWithObstacles(vector<vector<int>>& map) {
    int n = map.size();
    if(n <= 0)
        return 0;
    int m = map[0].size();
    if(m <= 0)
        return 0;
    
    int **ans = new int* [n];
    for(int i=0; i<n; i++){
        ans[i] = new int[m];
        memset(ans[i], 0, m*sizeof(int));
    }
    ans[0][0] = map[0][0] ? 0 : 1;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j]) // ans[i][j] will be 0
                continue;
            if(i-1>=0)
                ans[i][j] += ans[i-1][j];
            if(j-1>=0)
                ans[i][j] += ans[i][j-1];
        }
    }
    
    return ans[n-1][m-1];
}

int main(int argc, const char * argv[]) {
    
    int a[1][1] = {
        {1}    };
    
    vector<vector<int>> v;
    for(int i=0; i<1; i++){
        vector<int> tmp;
        for(int j=0; j<1; j++)
            tmp.push_back(a[i][j]);
        v.push_back(tmp);
    }
    
    cout<<uniquePathsWithObstacles(v)<<endl;
    
    cout<<"FIN"<<endl;
    return 0;
}

#endif
