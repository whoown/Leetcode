//
//  49.cpp
//  Leetcode
//
//  Created by yan zhang on 15/10/28.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
/* 原位-顺时针方向旋转矩阵90度。即不使用额外空间。 拿2X2 3X3 4X4 矩阵画一画就知道了，跟踪1的走向，就会发现，可以通过分层循环转动元素，以达到旋转的目的。
 */

#include <stdio.h>
#include "tools.h"
#include "run.h"

using namespace std;

#ifdef __RUN__

struct Point{
    int x,y;
    Point(int a, int b){
        x=a,y=b;
    }
};

Point calc_next_point(int x, int y, int step, int top, int right, int bottom, int left){
    int newX = x, newY = y;
    if(x == top){
        if(y + step <= right){
            newX = x;
            newY = y + step;
        }
        else {
            newX = x + (y+step)-right;
            newY = right;
        }
    }
    else if(x == bottom){
        if(y - step >= left) {
            newX = x;
            newY = y - step;
        }
        else {
            newX = x - (left - (y-step));
            newY = left;
        }
    }
    else if(y == left){
        if(x - step >= top){
            newX = x - step;
            newY = left;
        }else{
            newX = top;
            newY = left + top - (x-step);
        }
    }
    else if(y == right){
        if(x + step <= bottom){
            newX = x + step;
            newY = right;
        }else{
            newX = bottom;
            newY = right - (x+step-bottom);
        }
    }
    
    Point res(newX,newY);
    return res;
}


void rotate(vector<vector<int>>& m) {
    int n = m.size();
    int radius = 0;
    for(int i=0; i<n/2; i++){ // n/2 levels
        int step=n-1-2*i; // the distance between two elements
        int top = i, right = n-1-i, bottom = n-1-i, left = i;
        for(int j=0; j<step; j++){ // rotate count
            int x = i, y = i+j, first = m[x][y], v = m[x][y];
            for(int k=0; k<4; k++){
                Point p = calc_next_point(x,y,step,top,right,bottom,left);
                int tmp = m[p.x][p.y];
                m[p.x][p.y] = v;
                x = p.x, y = p.y, v = (k==3?v:tmp);
            }
            m[x][y] = v;
        }
    }
}


int main(int argc, const char * argv[]) {
    int n = 4;
    vector<vector<int>> m;
    for(int i=0; i<n; i++){
        vector<int> r;
        for(int j=0; j<n; j++){
            r.push_back(i*n+1+j);
        }
        m.push_back(r);
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            cout<<m[i][j]<<' ';
        cout<<endl;
    }
    
    rotate(m);
    for(int i=0; i<n; i++)
        cout<<'-';
    cout<<endl;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            cout<<m[i][j]<<' ';
        cout<<endl;
    }
    
    cout<<"FIN"<<endl;
    return 0;
}



#endif