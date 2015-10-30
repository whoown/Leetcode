//
//  49.cpp
//  Leetcode
//
//  Created by yan zhang on 15/10/28.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
/* ["eat", "tea", "tan", "ate", "nat", "bat"] 将“同构异形”的单词分组。 
 这题没什么好说的，哈希 + 插入排序。但写起来太麻烦了。我决定用快排，进行二级排序，一次性搞定之。
 */

#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__


const static int MAXN = 99997;

struct Str{
    string str;
    string tag;
    int hash;
    int* alpha = new int[26];
    
    string calc_hash(string str, int& output_hash){
        memset(alpha, 0, sizeof(int)*26);
        for(int i=0; i<str.size(); i++)
            alpha[str[i]-'a']++;
        int res = 0;
        for(int i=1; i<=26; i++) {
            res = (37 * res + alpha[i-1]*i*i) % MAXN;
        }
        output_hash = res;
        string tag = "";
        for(int i=0; i<26; i++)
            for(int j=0; j<alpha[i]; j++)
                tag += char('a'+i);
        return tag;
    }
    
    Str(string s){
        str = s;
        int tmp = 0;
        tag = calc_hash(s, tmp);
        hash = tmp;
    }
};

int cmp(Str a, Str b){ //二级排序（int的比较最快，作为第一层cache，tag再作为第二场比较）
    if(a.hash != b.hash)
        return a.hash - b.hash;
    if(a.tag != b.tag)
        return a.tag > b.tag ? 1 : -1;
    if(a.str != b.str)
        return a.str > b.str ? 1 : -1;
    return 0;
}

void qsort(vector<Str>& v, int st, int ed){
    if(st >= ed)
        return;
    Str div = v[st];
    int i = st+1, j = ed;
    while(i < j){ // [<div][div][>=div]
        while(cmp(v[i], div) < 0 && i < j) ++i;
        while(cmp(v[j], div)>= 0 && i < j) --j;
        swap(v[i], v[j]);
    }
    if(cmp(v[i], div) > 0)
        --i;
    swap(v[i], v[st]);
    qsort(v, st, i-1);
    qsort(v, i+1, ed);
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    int len = strs.size();
    if(len <= 0)
        return res;
    
    vector<Str> v;
    for(int i=0; i<len; i++)
        v.push_back(Str(strs[i]));
    
/*    for(int i=0; i<len; i++){
        cout<<v[i].str<<' '<<v[i].tag<<' '<<v[i].hash<<endl;
    }
*/

    qsort(v, 0, len-1);

    string preTag = "XXX";
    vector<string> item;
    for(int i=0; i<len; i++){
        if(v[i].tag != preTag){
            preTag = v[i].tag;
            if(item.size() > 0)
                res.push_back(vector<string>(item));
            item = vector<string>();
        }
        item.push_back(v[i].str);
    }
    if(item.size() > 0)
        res.push_back(item);
    
    return res;
}

int main(int argc, const char * argv[]) {
    string strs[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    
    vector<string> v;
    for(int i=0; i<sizeof(strs)/sizeof(string); i++)
        v.push_back(strs[i]);
    
    vector<vector<string>> res = groupAnagrams(v);
    
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++)
            cout<<res[i][j]<<' ';
        cout<<endl;
    }
    
    cout<<"FIN"<<endl;
    return 0;
}



#endif