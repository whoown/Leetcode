//
//  Leetcode
//
//  Created by yan zhang on 15/4/8.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
/*
case比较bug，单词组中有重复词。
1. 单词排序，去重，记录数量；
2. kmp扫全串，找出所有位置出现的单词ID (O len(str) * len(word))
3. 维护双指针，和某个单词的访问队列，队列中记录各个对单词的访问位置。 (O len(str) * cnt(word))
4. 双指针差异 = 固定间隔时，得到一次匹配。
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
    
    // enumerate the start offset.
    for(int startOffset=0; startOffset < wordLen; startOffset++){
        vector<int> *visit = new vector<int>[wordsCount];
        
        int i = startOffset, j = startOffset, k; // move two pointers of i and j
        vector<int> *visitTrace;
        while(j < strLen){

            if(line[j] < 0){ // jump the gap
                i = (j += wordLen);
                continue;
            }
            visitTrace = &visit[line[j]];
            
            // remove uselessly records before i
            for(k=0; k<visitTrace->size() && (*visitTrace)[k] < i;k++);
            if(k >= 1)
                visitTrace->erase(visitTrace->begin(), visitTrace->begin()+k);
            if(visitTrace->size() <= 0 || (*visitTrace)[visitTrace->size()-1] != j)
                visitTrace->push_back(j);
            
            if(visitTrace->size() <= count[line[j]]){ // not full visit. search continue.
                if(j - i == targetGapLen){
                    res.push_back(i);
                    i += wordLen;
                }else{
                    j += wordLen;
                }
            }else{
                i = (*visitTrace)[0]+wordLen;
                visitTrace->erase(visitTrace->begin());
            }
        }
        
        delete[] visit;
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
