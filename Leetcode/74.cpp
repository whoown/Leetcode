//
//  74.cpp
//  Leetcode
//
//  Created by yan zhang on 15/11/10.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
/* 逐行有序的矩阵上进行二分搜索，大水题。
 */

#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__


bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n = mat.size();
    if(n<=0)
        return false;
    int m = mat[0].size();
    if(m<=0)
        return false;
    int left = 0, right = n*m-1, mid=0, i=0, j=0;
    while(left <= right){
        mid = (left+right) >> 1;
        i = mid / m;
        j = mid % m;
        if(mat[i][j] == target){
            return true;
        }
        if(mat[i][j] > target){
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    return false;
}


int main(int argc, const char * argv[]) {
    
    int n = 1, m = 1, t=1;
    vector<vector<int>> v;
    for(int i=1; i<=n; i++){
        vector<int> tmp;
        for(int j=1; j<=m; j++)
            tmp.push_back(t*t++);
        v.push_back(tmp);
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cout<<v[i][j]<<(v[i][j] < 10 ? "  ": " ");
        cout<<endl;
    }
    
    cout<<searchMatrix(v, 1)<<endl;
    
    
    cout<<"FIN"<<endl;
    return 0;
}

#endif
