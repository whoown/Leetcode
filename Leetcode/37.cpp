//
//  37.cpp
//  Leetcode
//
//  Created by Zhang Yan on 15/6/13.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
/*
 贪心 + 搜索
 而想要判明可行解，基本靠搜索。暴力搜索：按任何顺序遍历各个空位，枚举其可能的数值，然后做一次全局的check。
 如果可行解确定只有一组的情况下，这样的搜索速度是不是尚且ok呢？毕竟空位不是那么多。
 直接考虑相对高效的贪心做法：枚举空位的顺序问题：一定是依据其可行值的数量来排序。可行值最少的空位，应当最优先被枚举。
 而发现可行值=0的情况下，就可以直接回溯。37题见。
 */

#include <stdio.h>
#include "tools.h"
#include "run.h"

using namespace std;

#ifdef __RUN__

int map[9][9];

bool checkLine(int index, bool row){
    int records = 0, value;
    for(int i=0; i<9; i++) {
        value = row ? map[index][i] : map[i][index];
        if(!value)
            continue;
        //cout<<records<<'-'<<(1<<value)<<endl;
        if(value < 0 || value > 9 || (records & (1<<value)))
            return false;
        records |= (1<<value);
    }
    return true;
}

bool checkSquare(int top, int left){
    int records = 0, value;
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++) {
            value = map[top+i][left+j];
            if(!value)
                continue;
            if(value < 0 || value > 9 || (records & (1<<value)))
                return false;
            records |= (1<<value);
        }
    return true;
}

bool isValidSudoku(vector<vector<char>>& board) {
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            map[i][j] = board[i][j] == '.' ? 0 : (board[i][j] - '0');
    
    /*for(int i=0; i<9; i++) {
     for(int j=0; j<9; j++) {
     cout<<map[i][j]<<' ';
     }
     cout<<endl;
     }*/
    
    for(int i=0; i<9; i++)
        if(!checkLine(i, true) || !checkLine(i, false))
            return false;
    for(int i=0; i<9; i+=3)
        for(int j=0; j<9; j+=3)
            if(!checkSquare(i, j))
                return false;
    return true;
}

void test(){
    string data[9] = {
        ".1.....2.",
        ".2.......",
        ".3...1...",
        ".4.......",
        ".57......",
        ".6.......",
        ".7.......",
        ".86......",
        ".9......."
    };
    vector<vector<char>> in;
    for(int i=0; i<9 ;i++){
        vector<char> line;
        for(int j=0; j<9; j++)
            line.push_back(data[i][j]);
        in.push_back(line);
    }
    cout<<isValidSudoku(in)<<endl;
}


int main(int argc, const char * argv[]) {
    test();
    cout<<"FIN"<<endl;
    return 0;
}

#endif
