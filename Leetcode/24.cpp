//
//  Leetcode
//
//  Created by yan zhang on 15/4/8.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
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

ListNode* swapPairs(ListNode* head) {
    if(!head || !head->next)
        return head;
    ListNode *far, *near, *sailor = new ListNode(-1);
    sailor->next = head;
    head = sailor;
    
    // x->1->2->3
    while(sailor->next && sailor->next->next){
        far = sailor->next->next->next; // save 3
        near = sailor->next->next; // save 2
        near->next = sailor->next; // 2->1
        sailor->next = near; // x->2->1
        sailor->next->next->next = far; // x->2->1->3
        sailor = sailor->next->next;
    }
    
    return head->next;
}


void test(){
    int a[] = {};
    int la = sizeof(a) / sizeof(int);
    printList(getList(a, la));
    printList(swapPairs(getList(a, la)));
}

int main(int argc, const char * argv[]) {
    test();
    cout<<"GOOD\n";
    return 0;
}

#endif
