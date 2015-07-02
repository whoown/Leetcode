//
//  25.cpp
//  Leetcode
//
//  Created by yan zhang on 15/6/3.
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


// x-1->2->3->4->5 if k = 2. head & tail will be [x, 2] [2, 4]
ListNode* reverseKGroup(ListNode* list, int k) {
    if(k<=1)
        return list;
    ListNode *tmp = new ListNode(-1);
    tmp->next = list;
    list = tmp;
    ListNode *rangeHead = list, *rangeTail = list;
    
    while(1){
        int cnt = 0;
        while(rangeTail && cnt++ < k){
            rangeTail = rangeTail->next;
        }
        if(!rangeTail) // less than k
            break;
        rangeTail = rangeTail->next;

        ListNode* newStartPoint = rangeHead->next;
        ListNode* one = rangeHead->next;
        ListNode* two = rangeHead->next->next;
        ListNode* three = rangeHead->next->next->next;
        one->next = rangeTail;
        
        while(1){
            two->next = one;
            if(three == rangeTail)
                break;
            one = two;
            two = three;
            three = three->next;
        }
        
        rangeHead->next = two;
        rangeHead = rangeTail = newStartPoint;
    }
    
    return list->next;
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
    int a[] = {1,2,3,4,5,6,7,8,9};
    int la = sizeof(a) / sizeof(int);
    printList(getList(a, la));
    printList(reverseKGroup(getList(a, la), 3));
}

int main(int argc, const char * argv[]) {
    test();
    cout<<"GOOD\n";
    return 0;
}

#endif
