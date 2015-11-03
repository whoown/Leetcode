//
//  Leetcode
//
//  Created by yan zhang on 15/10/28.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
/* 水到不能忍。。还是螺旋遍历矩阵 1y*/
#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__


int d[][2] = {{0,1}, {1,0}, {0,-1}, {-1, 0}};

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res;
    if(n <= 0)
        return res;
        
    for(int i=0; i<n; i++) {
        vector<int> tmp(n);
        res.push_back(tmp);
    }
    
    res[0][0] = 1;
    int top=0, right = n-1, bottom = n-1, left = 0;
    int x = 0, y = 0, k=1;
    int orientation = 0;
    
    while(x>=top&&x<=bottom&&y>=left&&y<=right){
        if(orientation == 0){
            if(y+1 <= right){
                y = y + 1;
            }else{
                ++top;
                y = right;
                x = x + 1;
                orientation = (orientation+1)%4;
            }
        }
        else if(orientation == 1){
            if(x+1 <= bottom){
                x = x + 1;
            }else{
                --right;
                y = y - 1;
                x = bottom;
                orientation = (orientation+1)%4;
            }
        }
        else if(orientation == 2){
            if(y-1 >= left){
                y = y - 1;
            }else{
                --bottom;
                y = left;
                x = x - 1;
                orientation = (orientation+1)%4;
            }
        }
        else if(orientation == 3){
            if(x-1 >= top){
                x = x - 1;
            }else{
                left++;
                y = y + 1;
                x = top;
                orientation = (orientation+1)%4;
            }
        }
        
        if(x>=top&&x<=bottom&&y>=left&&y<=right)
           res[x][y] = ++k;
    }
    
    return res;
}


int main(int argc, const char * argv[]) {
    vector<vector<int>> res =generateMatrix(4);
    for(int i=0; i<res.size(); i++) {
        for(int j=0; j<res[0].size(); j++)
            cout<<res[i][j]<<' ';
        cout<<endl;
    }
    cout<<"FIN"<<endl;
    return 0;
}


#endif