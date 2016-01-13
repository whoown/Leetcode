//
//  84.cpp  [?]
//  Leetcode
//
//  Created by Zhang Yan on 16/1/14.
//  Copyright (c) 2016年 yan zhang. All rights reserved.
//


#include <stdio.h>
#include "tools.h"
#include "run.h"

using namespace std;

#ifdef __RUN__

int largestRectangleArea(vector<int>& height) {
    
}

int main(int argc, const char * argv[]) {
    int a[] = {1,2,2,2,2,2};
    ListNode* list = buildLinkList(a, sizeof(a)/sizeof(int));
    printLinkList(list);
    cout<<endl;
    printLinkList(deleteDuplicates(list));
    
    cout<<"FIN"<<endl;
    return 0;
}

#endif

