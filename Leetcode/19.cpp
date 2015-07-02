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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(n < 0)
        return head;
    vector<ListNode*> list = vector<ListNode*>();
    ListNode* p = head;
    while(p){
        list.push_back(p);
        p = p->next;
    }
    int len = list.size();
    int tar = len - n;

    if(tar < 0 || len <= 0)
        return head;
    else if(tar == 0)
        return head->next;
    else {
        list[tar-1]->next = list[tar]->next;
        return head;
    }
    return head;
}

int arr[] = {1,2};

void printList(ListNode* head){
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

void test(){
    ListNode* list = 0, *head = 0;
    for(int i=0; i<sizeof(arr)/sizeof(int); i++){
        if(list == 0){
            head = list = new ListNode(arr[i]);
        }else {
            list->next = new ListNode(arr[i]);
            list = list->next;
        }
    }
    printList(head);
    printList(removeNthFromEnd(head, 3));
}

int main(int argc, const char * argv[]) {
    test();
    cout<<"GOOD\n";
    return 0;
}

#endif
