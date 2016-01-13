//
//  79.cpp  [0]
//  Leetcode
//
//  Created by yan zhang on 16/1/12.
//  Copyright (c) 2016年 yan zhang. All rights reserved.
//  basic dfs

#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__


int d[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
int n, m, len;

bool check(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}

bool dfs(vector<vector<char>>& map, int x, int y, string word, int now) {
    if(map[x][y] != word[now]) {
        return false;
    }else if(now == word.length()-1){
        return true;
    }
    char ch = map[x][y];
    map[x][y] = 0;
    int nx, ny;
    for(int i=0; i<4; i++){
        nx = x + d[i][0];
        ny = y + d[i][1];
        if(check(nx, ny) && dfs(map, nx, ny, word, now+1)) {
            return true;
        }
    }
    map[x][y] = ch;
    return false;
}


bool exist(vector<vector<char>>& board, string word) {
    len = word.length();
    if (len <=0 || board.size()<=0 || board[0].size() <= 0) {
        return false;
    }
    n = board.size();
    m = board[0].size();
    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++) {
        if(dfs(board, i,j, word, 0))
            return true;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    string s[] = {"A"};
    vector<vector<char>> map;
    for(int i=0; i<1; i++) {
        vector<char> v;
        for(int j=0; j<s[i].length(); j++) {
            v.push_back(s[i][j]);
        }
        map.push_back(v);
    }
    cout<<exist(map, "AB")<<endl;
    
    cout<<"FIN"<<endl;
    return 0;
}

#endif
