//
//  64.cpp
//  Leetcode
//
//  Created by Zhang Yan on 15/11/3.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
//  大水题，超级简单的DP,hello-world级别
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

int minPathSum(vector<vector<int>>& map) {
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
    ans[0][0] = map[0][0];
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int v1 = -1, v2 = -1;
            if(i-1 >=0)
                v1 = ans[i-1][j];
            if(j-1 >=0)
                v2 = ans[i][j-1];
            if(v1 >= 0 || v2 >= 0){
                ans[i][j] = map[i][j] + (v1<0? v2 : (v2<0 ? v1 : (v1<v2?v1:v2)));
            }
        }
    }
    
    //print(ans, n, m);
    
    return ans[n-1][m-1];
}

int main(int argc, const char * argv[]) {
    
    int a[3][3] = {
        {2, 3, 1},
        {0, 0, 0},
        {0, 6, 2}
    };
    
    vector<vector<int>> v;
    for(int i=0; i<3; i++){
        vector<int> tmp;
        for(int j=0; j<3; j++)
            tmp.push_back(a[i][j]);
        v.push_back(tmp);
    }
    
    cout<<minPathSum(v)<<endl;
    
    cout<<"FIN"<<endl;
    return 0;
}

#endif
