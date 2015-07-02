//
//  2.cpp
//  Leetcode
//
//  Created by yan zhang on 15/4/7.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <cmath>

//#include "run.h"
#ifdef __RUN__

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void printList(ListNode* list);
ListNode* createList(int val);
int parseList(ListNode* list);


ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode* list_head = 0, *list_root = 0;
    int count = 0, a = 0, b = 0, sum = 0;
    
    while(l1 || l2 ){
        a = l1 ? l1->val : 0;
        b = l2 ? l2->val : 0;
        //printf("a=b=c , %d, %d, %d ", a, b, count);
        sum = (a+b+count);
        count = sum / 10;
        //printf("new-c=sum = SS, %d, %d, %d\n ", count, sum, sum%10);
        ListNode* node = new ListNode(sum%10);
        if(!list_root){
            list_head = list_root = node;
        }else{
            list_head->next = node;
            list_head = node;
        }
        if(l1)
            l1 = l1->next;
        if(l2)
            l2 = l2->next;
    }
    if(count){
        ListNode* node = new ListNode(count);
        if(!list_root){
            list_root = list_head = node;
        }else{
            list_head->next = node;
            list_head = node;
        }
    }
    return list_root;
}


/*
 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)  342 + 465 = 807
 Output: 7 -> 0 -> 8
 */

void fuckingtest(){
    int TEST_TIMES = 100000;
    srand(time(0));
    for(int i=0; i<TEST_TIMES; i++){
        int a = rand() % 100000000, b = rand() % 100000000;
        //a = 1, b = 99999;
        int sum = a + b;
        ListNode* l1 = createList(a);
        ListNode* l2 = createList(b);
        //printList(l1);
        //printList(l2);
        //printList(addList(l1, l2));
        ListNode* res = addTwoNumbers(l1, l2);
        int sum2 = parseList(res);
        if(sum != sum2){
            printf("FUCK!%d a=%d, b=%d, sum1 = %d, sum2 = %d ", i, a, b,sum, sum2);
            break;
        }
    }
    printf("FUCKING OK!!!");
}

int main(int argc, const char * argv[]) {
    fuckingtest();
    return 0;
}

void printList(ListNode* list){
    while(list != 0){
        printf("%d-", list->val);
        list = list->next;
    }
    printf("\n");
}

int parseList(ListNode* list){
    int p = 1, ret = 0;
    while(list){
        ret += p * list->val;
        p *= 10;
        list = list->next;
    }
    return ret;
}

ListNode* createList(int val){
    ListNode* list = 0, *root = 0;
    while(val){
        ListNode* node = new ListNode(val%10);
        if(!list){
            root = list = node;
        }else{
            list->next = node;
            list = node;
        }
        val /= 10;
    }
    return root;
}

#endif
