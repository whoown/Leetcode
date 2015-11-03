//
//  61.cpp
//  Leetcode
//
//  Created by Zhang Yan on 15/6/13.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
/* 旋转一个链表，大水题，1Y
  */

#include <stdio.h>
#include "tools.h"
//#include "run.h"

using namespace std;

#ifdef __RUN__

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};


ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL)
        return NULL;
        
    int len = 0;
    ListNode *p = head, *tail = NULL;
    while(p){
        ++len;
        if(p->next == NULL)
            tail = p;
        p = p->next;
    }
    k %= len;
    
    ListNode* ret;
    
    p = head;
    for(int i=0; i<len-k-1; i++){
        p = p->next;
    }
    if(p->next){
        ret = p->next;
        tail->next = head;
        p->next = NULL;
    }else{
        ret = head;
    }
    return ret;
}

void print(ListNode* list){
    ListNode* res = list;
    while(res){
        cout<<res->val<<',';
        res = res->next;
    }
    cout<<endl;

}

int main(int argc, const char * argv[]) {
    int a[] = {1};
    ListNode* list = NULL, *p = NULL;
    for(int i=0; i<sizeof(a)/sizeof(int); i++){
        if(!list)
            p = list = new ListNode(a[i]);
        else{
            p->next = new ListNode(a[i]);
            p = p->next;
        }
    }
    print(list);
    print(rotateRight(list, 1));
    
    
    cout<<"FIN"<<endl;
    return 0;
}

#endif
