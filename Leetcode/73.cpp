//  73.cpp
//  Leetcode
//
//  Created by Zhang Yan on 15/11/3.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
/* 矩阵中，如果某个元素=0，则将其所处行&列都置为零。常数空间。 
 这个Medium题非常有意思。需要归纳思维。从最基本的做法：将每个零点的行列序号保存下来（O(n+m)空间）。进而该如何将空间削减为O(1)呢？
 不会太难想到，需要利用矩阵自身的空间。只要某行、某列用来标记是否为零就够了。但是具体该如何实现呢？这里才是真正的难点！！
 思维过程：乍一想，如果使用[i,j]行列来作为Marker，那么其他所有的零点确实可以完整的标记出来。但关键是[i,j]行列上自己的零点该如何处理？
 至此：其实已经非常接近答案！但是由于碰到这一点难题，而放弃此思路，实在是可惜！这里本质上呼唤一种思维：“人在任一情况下，都必须分清楚矛盾的主次。
 阻碍一个方案/计划成为一个优秀的方案/计划的原因，并不是一些小的瑕疵或困难，往往是根本性的缺陷。而，如果不能分清主次，就往往无法做出正确的选择：
 坚持错误的道路，或者放弃正确的道路”
 */
#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__

void setZeroes(vector<vector<int>>& mat) {
    int n = mat.size();
    if(n <= 0)
        return;
    int m = mat[0].size();
    if(m <= 0)
        return;
    
    int zrow = -1, zcol = -1;
    for(int i=0; i<n; i++)
        if(!mat[i][0])
            zcol = 0;
    for(int i=0; i<m; i++)
        if(!mat[0][i])
            zrow = 0;
    
    for(int i=1; i<n; i++)
        for(int j=1; j<m; j++)
            if(!mat[i][j])
                mat[0][j] = mat[i][0] = 0;
    
    for(int i=1; i<n; i++){
        if(!mat[i][0])
            for(int j=1; j<m; j++)
                mat[i][j] = 0;
    }
    
    for(int j=1; j<m; j++) {
        if(!mat[0][j])
            for(int i=1; i<n; i++)
                mat[i][j] = 0;
    }
    
    if(!zrow)
        for(int j=0; j<m; j++)
            mat[0][j] = 0;
    if(!zcol)
        for(int i=0; i<n; i++)
            mat[i][0] = 0;
}


int main(int argc, const char * argv[]) {
    int n = 6, m = 6, t=1;
    vector<vector<int>> v;
    for(int i=1; i<=n; i++){
        vector<int> tmp;
        for(int j=1; j<=m; j++)
            tmp.push_back(t++);
        v.push_back(tmp);
    }
    
    v[2][2] = v[5][5] = v[4][0]= 0;
    
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
