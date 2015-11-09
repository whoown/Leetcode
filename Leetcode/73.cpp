//  73.cpp
//  Leetcode
//
//  Created by Zhang Yan on 15/11/3.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
/* 矩阵中，如果某个元素=0，则将其所处行&列都置为零。常数空间。
 比较水，不需要太久思考。控制好扫描方向，避免干扰后续数据即可。扫描两次，一次只置空左上方的点，一次只置空右下方的点。
 */
#include <stdio.h>
#include "tools.h"
#include "run.h"

using namespace std;

#ifdef __RUN__

void setZeroes(vector<vector<int>>& mat) {
    int n = mat.size();
    if(n <= 0)
        return;
    int m = mat[0].size();
    if(m <= 0)
        return;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(!mat[i][j]) { // set left and top regions
                for(int k=0; k<i && mat[k][j]; k++) // optimize
                    mat[k][j] = 0;
                for(int k=0; k<j && mat[i][k]; k++)
                    mat[i][k] = 0;
            }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cout<<mat[i][j]<<(mat[i][j] < 10 ? "  ": " ");
        cout<<endl;
    }
    cout<<"----------------\n";

    
    
    for(int i=n-1; i>=0; i--)
        for(int j=m-1; j>=0; j--){
            if(!mat[i][j] && ( i==n-1||mat[i+1][j]) && (j==m-1||mat[i][j+1])){
                for(int k=n-1; k>i; k--)
                    mat[k][j] = 0;
                for(int k=m-1; k>j; k--)
                    mat[i][k] = 0;
            }
        }
}

int main(int argc, const char * argv[]) {
    int n = 3, m = 3, t=1;
    vector<vector<int>> v;
    for(int i=1; i<=n; i++){
        vector<int> tmp;
        for(int j=1; j<=m; j++)
            tmp.push_back(t++);
        v.push_back(tmp);
    }
    
    v[0][0] = v[1][1] = 0;
    
    setZeroes(v);
    
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cout<<v[i][j]<<(v[i][j] < 10 ? "  ": " ");
        cout<<endl;
    }
    
    cout<<"FIN"<<endl;
    return 0;
}

#endif
