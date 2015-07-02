//
//  Leetcode
//
//  Created by yan zhang on 15/4/8.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
//  见 思维笔记本  欲速则不达
//
#include <stdio.h>
#include "tools.h"
// #include "run.h"

using namespace std;

#ifdef __RUN__

#define min(x,y) (x < y ? x : y)
#define max(x,y) (x > y ? x : y)

int maxArea(vector<int>& height) {
    int len = (int)height.size(), res = 0;
    int l = 0, r = len-1, lh = 0, rh = 0;
    while(l < r){
        if(height[r] >= rh){
            rh = height[r];
        }else{
            --r;
            continue;
        }
        
        if(height[l] >= lh){
            lh = height[l];
        }else{
            ++l;
            continue;
        }
        
        res = max(res, (r-l)*min(lh, rh));
        if(rh > lh){
            ++l;
        }else{
            --r;
        }
    }
    
    return res;
}

int testArea(vector<int>& height) {
    int i=0,j=height.size()-1,ans = 0;
    while(j>i)
    {
        ans = max(min(height[i],height[j])*(j-i),ans);
        if(height[i]>height[j]) j--;
        else i++;
    }
    return ans;
}



int main(int argc, const char * argv[]) {
    
    int ns[] = {5,9,5,3};
    vector<int> test = vector<int>();
    for(int i=0; i<sizeof(ns)/sizeof(ns[0]); i++)
        test.push_back(ns[i]);
    srand(time(0));
    int tnum = 1000;
    while(tnum--){
        test.clear();
        for(int i=0; i<4000; i++)
            test.push_back(rand()%5000 + 1);
        //test.push_back(i+1);
        time_t t1 = clock();
        int res = maxArea(test);
        time_t t2 = clock();
        int real = testArea(test);
        time_t t3 = clock();
        if(res != real){
            cout<<res<<' '<<real<<endl;
            for(int i=0;i<test.size();i++)
                cout<<test[i]<<' ';
            cout<<endl;
            break;
        }
        else
            cout<<tnum<<"OK "<<(t2-t1)<<' '<<(t3-t2)<<endl;
    }
    if(tnum <= 0)
        cout<<"GOOD!!!!!\n";
    
    cout<<"something\n";
    return 0;
}

#endif
