//
//  Leetcode
//
//  Created by yan zhang on 15/4/8.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
//  cmp传入需要声明成static方法，bucket！
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

struct Heap{
    void **heap = NULL;
    int heapSize = 0, heapMaxSize;
    int (*cmp)(const void* a, const void* b);
    
    Heap(int maxSize, int (*heapCmp)(const void* a, const void* b)){
        heapMaxSize = maxSize;
        heap = new void*[heapMaxSize];
        cmp = heapCmp;
        heapSize = 0;
    }
    
    /* Min-Heap which accroding the implemention of cmp.  */
    void filterDown(int startLoc){
        int parent = startLoc, child = startLoc * 2 + 1; // parent and child
        void* needArragedVal = heap[startLoc];
        
        while(child < heapSize){
            if(child+1 < heapSize && cmp(heap[child], heap[child+1]) > 0){
                child++; // left child bigger than right one
            }
            // adjusting finished.
            if(cmp(heap[parent], heap[child]) <= 0)
                break;
            swap(heap[parent], heap[child]);
            parent = child;
            child = (parent<<1) + 1;
        }
        heap[parent] = needArragedVal;
    }
    
    /* Min-Heap which accroding the implemention of cmp.  */
    void filterUp(int startLoc){
        int child = startLoc, parent = (startLoc-1) / 2; // parent and child
        void* needArragedVal = heap[startLoc];
        
        while(child-1>=0){
            // adjsuting finished.
            if(cmp(heap[parent], heap[child]) <= 0)
                break;
            swap(heap[parent], heap[child]);
            child = parent;
            parent = (child - 1) >> 1; // parent alway no less than 0
        }
        heap[child] = needArragedVal;
    }
    
    void enqueue(void* val){
        if(heapSize >= heapMaxSize)
            return;
        heap[heapSize++] = val;
        filterUp(heapSize-1);
    }
    
    void* dequeue(){
        if(heapSize <= 0)
            return NULL;
        void* head = heap[0];
        swap(heap[--heapSize], heap[0]);
        filterDown(0);
        return head;
    }
    
    void clear(){
        delete[] heap;
        heapSize = -1;
        heapMaxSize = -1;
    }
    
    void printHeap(){
        for(int i=0; i<heapSize; i++)
            cout<<((int*)heap[i])[0]<<' ';
        cout<<endl;
    }
};


static int cmp1(const void* a, const void* b){
    return ((ListNode*)a)->val - ((ListNode*)b)->val;
}

static int cmp2(const void* a, const void* b){
    return ((ListNode*)b)->val - ((ListNode*)a)->val;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* res = NULL, *p = NULL;
    int k = (int)lists.size();
    bool increase = true;
    for(int i=0; i<k; i++){
        if(lists[i] && lists[i]->next && lists[i]->val != lists[i]->next->val){
            increase = lists[i]->val < lists[i]->next->val;
            break;
        }
    }
    
    Heap heap = Heap(k+1, increase ? cmp1 : cmp2);
    ListNode* tmp;
    for(int i=0; i<k; i++) {
        if(lists[i])
            heap.enqueue(lists[i]);
    }
    
    void* voidTmp;
    while(true){
        voidTmp = heap.dequeue();
        if(!voidTmp)
            break;
        tmp = ((ListNode*)voidTmp);
        if(tmp->next)
            heap.enqueue(tmp->next);
        
        if(p == 0){
            res = p = tmp;
        }else{
            p->next = tmp;
            p = p->next;
        }
    }
    heap.clear();
    return res;
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
    int a[] = {2,3};
    int b[] = {1,5, 7};
    int la = sizeof(a) / sizeof(int);
    int lb = sizeof(b) / sizeof(int);
    
    vector<ListNode*> lists = vector<ListNode*>();
    lists.push_back(getList(a, la));
    lists.push_back(getList(b,lb));
    printList(mergeKLists(lists));
}

int main(int argc, const char * argv[]) {
    test();
    cout<<"GOOD\n";
    return 0;
}

#endif
