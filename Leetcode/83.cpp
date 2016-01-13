//
//  83.cpp  [0]
//  Leetcode
//
//  Created by yan zhang on 16/1/12.
//  Copyright (c) 2016年 yan zhang. All rights reserved.
/* 有序链表，删除所有重复元素
 */

#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__

ListNode* deleteDuplicates(ListNode* head) {
    if(!head)
        return head;
    ListNode *ret = 0, *tail = 0;
    ListNode *p = head;
    int curVal = head->val-1;
    while(p){
        if(p->val != curVal){
            curVal = p->val;
            if(!ret) {
                ret = tail = p;
            }else {
                tail->next = p;
                tail = tail->next;
            }
        }
        p = p->next;
    }
    if(tail)
        tail->next = 0; //clean the tail
    return ret;
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

