//
//  54.cpp
//  Leetcode
//
//  Created by yan zhang on 15/10/28.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
/*将一个mxn矩阵螺旋输出。。画一画找找规律即可发现，螺旋遍历时的规律路径。水题 1Y*/

#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__

int d[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}}; //right down left up

bool is_valid(int x, int y, int top, int right, int bottom, int left){
    return x>=top && x<=bottom && y>=left && y<=right;
}

vector<int> spiralOrder(vector<vector<int>>& mat) {
    vector<int> res;
    int n = mat.size();
    if(n == 0)
        return res;
    int m = mat[0].size();
    int top = 0, right = m-1, bottom = n-1, left = 0;

    int x=0, y=0, orientation = 0;
    while(is_valid(x,y, top, right, bottom, left)){
        res.push_back(mat[x][y]);
        
        //cout<<"x="<<x<<", y="<<y<<" NUM="<<mat[x][y]<<endl;
        //cout<<top<<' '<<right<<' '<<bottom<<' '<<left<<endl;
        
        if(orientation == 0){
            if(y+1 <= right){
                y = y+1;
            }else{
                ++top;
                x = x+1;
                y = right;
                orientation = (orientation+1)%4;
            }
        }
        else if(orientation ==1){
            if(x+1 <= bottom){
                x = x+1;
            }else{
                --right;
                y = y-1;
                x = bottom;
                orientation = (orientation+1)%4;
            }
        }
        else if(orientation ==2){
            if(y-1 >= left){
                y = y-1;
            }else{
                --bottom;
                y = left;
                x = x-1;
                orientation = (orientation+1)%4;
            }
        }
        else if(orientation ==3){
            if(x-1 >= top){
                x = x-1;
            }
            else{
                ++left;
                x = top;
                y = y+1;
                orientation = (orientation+1)%4;
            }
        }
    }
    
    return res;
}

int main(int argc, const char * argv[]) {
    
    int n = 4, m=3;
    vector<vector<int>> mat;
    for(int i=0; i<n; i++){
        vector<int> r;
        for(int j=0; j<m; j++){
            r.push_back(i*n+1+j);
        }
        mat.push_back(r);
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++)
            cout<<mat[i][j]<<' ';
        cout<<endl;
    }

    vector<int> res = spiralOrder(mat);
    
    for(int i=0; i<res.size(); i++)
        cout<<res[i]<<'-';
    cout<<endl;
    
    
    cout<<"FIN"<<endl;
    return 0;
}


#endif