//
//  Leetcode
//
//  Created by yan zhang on 15/4/8.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
/*
 网上流行的思路：框架和我的类似，只不过是枚举str的起点，并检查从这个起点开始连续N个单词是否满足要求
 其左边界是+1来移动的，而我的算法中左边界的调整可能很快。但都是O(Len(s))。
 其没有把字符串hash成数字，于是需要每次进行substring。其综合复杂度是O(Len(s)*Len(word)*Cnt(word))
 理论上比我的慢，但是因为可以使用大量的STL和现成方法。所以还是比较快的。
 下面的code，只修改最终匹配：采用枚举起点，左边界+1增长的方式。
 ================
 测试结果：左边界+1方式递增，运行速度比原来的队列方式慢。所以真正影响速度的是预处理部分，应该换成RK算法。
 */
#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__


void quick_sort(vector<string>& nums, int begin_index, int end_index){
    if(begin_index >= end_index)
        return;
    string div = nums[begin_index];
    int p = begin_index, i = begin_index+1, j = end_index;
    
    while(i < j){
        if(nums[j] >= div){
            --j;
        }else if(nums[i] < div){
            ++i;
        }else{
            nums[p] = nums[j];
            nums[j] = nums[i];
            p = i;
        }
    }
    if(i == j){
        if(nums[i] < div){
            nums[p] = nums[i];
            p = i;
        }
    }
    
    nums[p] = div;
    quick_sort(nums, begin_index, p-1);
    quick_sort(nums, p+1, end_index);
}


vector<int> findSubstring(string s, vector<string>& rawWords) {
    vector<int> res = vector<int>();
    if(rawWords.size() <= 0)
        return res;
    
    // sort and store every unique words
    quick_sort(rawWords, 0, (int)rawWords.size()-1);
    vector<string> words = vector<string>();
    vector<int> count = vector<int>();
    string preWord = "";
    for(int i=0; i<rawWords.size(); i++){
        if(rawWords[i] != preWord){
            preWord = rawWords[i];
            words.push_back(rawWords[i]);
            count.push_back(1);
        }else{
            count[count.size()-1] ++ ;
        }
    }
    
    int strLen = (int)s.size(), wordsCount = (int)words.size(), wordLen = (int)words[0].size();
    if(wordLen == 0){
        for(int i=0; i<strLen; i++)
            res.push_back(i);
        return res;
    }
    
    int targetGapLen = wordLen * ((int)rawWords.size()-1);
    int *line = new int[strLen], *next = new int[wordLen];
    memset(line, -1, strLen*sizeof(int));
    
    // run kmp and record every start postion of each word.
    for(int x=0; x<wordsCount; x++){
        string p = words[x];
        // calc the next array
        next[0] = -1;
        for(int i=1, pre=i-1; i<wordLen; pre=++i-1){
            while(next[pre] >=0 && p[next[pre]] != p[i-1])
                pre = next[pre];
            next[i] = next[pre] + 1;
        }
        // search every match point
        int i = 0, j = 0;
        while(i < strLen){
            if(s[i] == p[j]){
                if(j == wordLen-1){ // match
                    line[i - (wordLen-1)] = x;
                    i = i-(wordLen-1)+1, j = 0;
                }else{
                    ++i, ++j;
                }
            }else{
                j = next[j];
                if(j < 0){
                    j = 0;
                    ++i;
                }
            }
        }
    }

    int* visitCount = new int[wordsCount];
    // enumerate the matching start point
    for(int i=0,j=0; i<strLen-wordLen+1;i++){
        memset(visitCount, 0, wordsCount*sizeof(int));
        for(j=i; j<strLen; j+=wordLen){
            //cout<<i<<' '<<j<<' '<<line[j]<<' '<<count[line[j]]<<' '<<visitCount[line[j]]<<endl;
            if(line[j] < 0) // empty gap
                break;
            if(visitCount[line[j]] >= count[line[j]])
                break;
            visitCount[line[j]]++;
            if(j - i == targetGapLen){
                res.push_back(i);
                break;
            }
        }
    }
    
    return res;
}

void test(){
    string s = "cccca";
    string ss[] = {"cca"};
    
    vector<string> v = vector<string>();
    for(int i=0; i<sizeof(ss)/sizeof(ss[0]); i++)
        v.push_back(ss[i]);
    vector<int> res = findSubstring(s, v);
    
    cout<<"\nres:\n";
    for(int i=0; i<res.size(); i++)
        cout<<res[i]<<' ';
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    test();
    
    cout<<"GOOD\n";
    return 0;
}

#endif
