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
 =========
 尽管这样的效率可能会更高，但是我依然决定先使用更简单的搜索策略。因为。。简单。。（毕竟9X9数据量不大）
 而且居然1Y，运行速率还排在前20%。。。 到底还是水题。。
 */

#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__

int map[9][9];

const int FULL_FILL = (10<<1) - 1;

int res[9][9];

int calcFilledBits(int x, int y){
    int bits = 0;
    for(int i=0; i<9; i++)
        bits |= (1 << map[x][i]) | (1 << map[i][y]);
    int top = x / 3 * 3, left = y / 3 * 3;
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            bits |= (1 << map[top+i][left+j]);
    return bits;
}

void dfs(int i, int j){
    
    //cout<<i<<' '<<j<<endl;
    
    if(map[i][j]) { // already filled
        if(i==8 && j==8) {
            for(int x=0; x<9; x++)
                for(int y=0; y<9; y++)
                    res[x][y] = map[x][y];
            return;
        }
        dfs(j==8?i+1:i , j==8?0:j+1);
        return;
    }
    // not filled.
    int bits = calcFilledBits(i, j);
    if(bits == FULL_FILL)
        return;
    for(int k=1; k<=9; k++)
        if(!(bits & (1<<k))) {
            map[i][j] = k;
            if(i==8 && j==8) {
                for(int x=0; x<9; x++)
                    for(int y=0; y<9; y++)
                        res[x][y] = map[x][y];
                return;
            }
            dfs(j==8?i+1:i, j==8?0:j+1);
            map[i][j] = 0;
        }
}


void solveSudoku(vector<vector<char>>& board) {
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            map[i][j] = board[i][j] == '.' ? 0 : (board[i][j] - '0');
    
    dfs(0, 0);
    
    for(int i=0; i<9 ;i++)
        for(int j=0; j<9; j++)
            board[i][j] = '0'+res[i][j];
    
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cout<<res[i][j]<<' ';
     }
     cout<<endl;
     }
}





void test(){
    string data[9] = {
        "53..7....",
        "6..195...",
        ".98....6.",
        "8...6...3",
        "4..8.3..1",
        "7...2...6",
        ".6....28.",
        "...419..5",
        "....8..79"
    };
    
    string data2[9] = {
        ".........",
        ".........",
        ".........",
        ".........",
        ".........",
        ".........",
        ".........",
        ".........",
        "........."
    };
    
    vector<vector<char>> in;
    for(int i=0; i<9 ;i++){
        vector<char> line;
        for(int j=0; j<9; j++)
            line.push_back(data[i][j]);
        in.push_back(line);
    }
    solveSudoku(in);
    //cout<<isValidSudoku(in)<<endl;
}


int main(int argc, const char * argv[]) {
    test();
    cout<<"FIN"<<endl;
    return 0;
}

#endif
