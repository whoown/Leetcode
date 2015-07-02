//
//  Leetcode
//
//  Created by yan zhang on 15/4/8.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
//
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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(!l1)
        return l2;
    if(!l2)
        return l1;
    bool increase = true;
    if(l1->next && l1->next->val < l1->val)
        increase = false;
    else if(l2->next && l2->next->val < l2->val)
        increase = false;
    
    ListNode *list = NULL, *p = NULL;
    int val = 0;
    while(l1 && l2){
        if(increase){
            if(l1->val < l2->val) {
                val = l1->val;
                l1 = l1->next;
            }else{
                val = l2->val;
                l2 = l2->next;
            }
        }else{
            if(l1->val > l2->val) {
                val = l1->val;
                l1 = l1->next;
            }else{
                val = l2->val;
                l2 = l2->next;
            }
        }
        
        if(!p){
            list = p = new ListNode(val);
        }else {
            p->next = new ListNode(val);
            p = p->next;
        }
    }
    
    while(l1){
        if(!p){
            list = p = new ListNode(l1->val);
        }else {
            p->next = new ListNode(l1->val);
            p = p->next;
        }
        l1 = l1->next;
    }
    
    while(l2){
        if(!p){
            list = p = new ListNode(l2->val);
        }else {
            p->next = new ListNode(l2->val);
            p = p->next;
        }
        l2 = l2->next;
    }
    
    return list;
}


void printList(ListNode* head){
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

ListNode* getList(int* arr, int num){
    ListNode* list = 0, *head = 0;
    for(int i=0; i<num; i++){
        if(list == 0){
            head = list = new ListNode(arr[i]);
        }else {
            list->next = new ListNode(arr[i]);
            list = list->next;
        }
    }
    return head;
}

void test(){
    
    int a[] = {3,2,1};
    int b[] = {2,1,-1};
    int la = sizeof(a) / sizeof(int);
    int lb = sizeof(b) / sizeof(int);
    //printList(getList(a, la));
    printList(mergeTwoLists(getList(a, la), getList(b, lb)));
    
}

int main(int argc, const char * argv[]) {
    test();
    cout<<"GOOD\n";
    return 0;
}

#endif
