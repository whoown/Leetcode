//
//  76.cpp 【4】
//  Leetcode
//
//  Created by yan zhang on 15/11/10.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
/* 如果排除知识层面的问题，一道问题的难易，真的是个很个人化的问题。这道标为Hard的问题，反而没有把人卡住，根源在于使用了正确的思考模式，正确的分析方法。
 所以，在你去解决任何一个问题之前，找到正确的方法，才是最要紧的。
 两个串S,T，在S中寻找长度最短的一个字串，能够包含T中含有的所有字符（T中字符会有重复，例如AAABBC）。
 【归纳思维】：先不考虑T中含有重复字符的情况，假设T中只有三个不重复字符，例如ABC。那么如何在S中找到一个字串包含有'A','B','C'呢？
 【直觉思维】：从最左开始，如果能找到第一个有效区间（包含了三个字符），那么继续往右的时候后，就可以不断调整这个区间。
 【细化】：
 三个指针Pa,Pb,Pc，分别指向A\B\C，从左向右扫描，首先发现了'A'，这样Pa就有着落了；接着走，又发现一个'A'，那么就把Pa直接移过来；接着走，发现'B'；
 再接着走，又发现了'A'，此时再把Pa指向此位置，则Pb变成了区间的左边界；再接着走，发现了'C'，此时三个指针都有值，则第一次发现一个有效区间，将结果记录一次。
 再接着向右走，不断更新Pa，Pb，Pc，从而不断更新区间，从而在O(n)时间里找到答案。
 【特殊->一般】：
 那么如何处理T中有多个A\B\C的情况呢？还是按照相同的逻辑。只不过指向A\B\C的不再是三个指针，而是三个指针队列Qa,Qb,Qc。而一个有效区间的达成，则需要每个字符
 的数量都满足它们在T中的数量要求；之后的调整也会是类似，当新发现一个’A‘，那么Qa的队头出队，将新位置放在Qa的队尾。
 
============================
 以上思路是立刻想到的。但其实空间上有极大的优化余地：也不需要记录那么多个队列。遍历指针，和窗口[st, ed]，可以独立开来维护。
 
*/
 

#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__



int c2i(char ch){
    if(ch>='0' && ch <= '9')
        return ch - '0';
    if(ch >='A' && ch <= 'Z')
        return ch - 'A' + 10;
    if(ch >='a' && ch <= 'z')
        return ch - 'a' + 36;
    return 69;
}


string minWindow(string s, string t) {
    int *cs = new int[70]; // char nums
    memset(cs, 0, sizeof(int)*70);
    for(int i=0;i<t.size();i++)
        cs[c2i(t[i])]++;
    
    vector<vector<int>> qs; // the pointer queues;
    for(int i=0; i<70; i++)
        qs.push_back(vector<int>());
    
    int edge_left, ch;
    int min_range=-1, res_st=0, res_ed=-1, curt_pointer_cnts = 0;
    
    for(int i=0; i<s.size(); i++){
        ch = c2i(s[i]);
        if(!cs[ch]) // not exist in T
            continue;
        // update the pointer
        qs[ch].push_back(i);
        if(qs[ch].size() > cs[ch]) {
            qs[ch].erase(qs[ch].begin());
        }else{
            ++curt_pointer_cnts;
        }
        
        // update the answer
        if(curt_pointer_cnts == t.size()){
            // calc the left edge at first.
            edge_left = 2e15;
            for(int i=0; i<qs.size(); i++)
                if(qs[i].size())
                    edge_left = min(edge_left, qs[i][0]);
            
            if(i - edge_left + 1 < min_range || min_range == -1){
                min_range = i - edge_left + 1;
                res_st = edge_left;
                res_ed = i;
            }
        }
    }
    
    return s.substr(res_st, res_ed-res_st+1);
}

int main(int argc, const char * argv[]) {
    cout<<minWindow("cabwefgewcwaefgcf","cae")<<endl;
    
    cout<<"FIN"<<endl;
    return 0;
}

#endif
