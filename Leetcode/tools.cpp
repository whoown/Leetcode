//
//  tools.cpp
//  Leetcode
//
//  Created by yan zhang on 15/4/8.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
//

#include "tools.h"

using namespace std;

string alphas = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
string alphas_lower_letters = "abcdefghijklmnopqrstuvwxyz";
const int ALPHA_TYPE_ALL = 0;
const int ALPHA_TYPE_LOWER_LETTERS = 1;
const int ALPHA_TYPE_UPPER_LETTERS = 2;
const int ALPHA_TYPE_NUMBERS = 3;

string random_string(int len, int type){
    string alpha;
    switch(type){
        case ALPHA_TYPE_LOWER_LETTERS:
            alpha = alphas_lower_letters;
            break;
        case ALPHA_TYPE_ALL:
        default:
            alpha = alphas;
            break;
    }
    return random_string(len, alpha);
}

string random_string(int len, string alpha){
    int alpha_len = (int)alpha.length();
    string res = "";
    for(int i=0; i<len; i++){
        int idx = rand() % alpha_len;
        res += alpha[idx];
    }
    return res;
}


void quick_sort(vector<int>& nums, int begin_index, int end_index){
    if(begin_index >= end_index)
        return;
    int div = nums[begin_index], p = begin_index;
    int i = begin_index+1, j = end_index;
    
    while(i < j){
        if(nums[j] >= div){
            --j;
        }else if(nums[i] < div){
            ++i;
        }else{
            nums[p] = nums[j];
            nums[j] = nums[i];
            p = i;
        }
    }
    if(i == j){
        if(nums[i] < div){
            nums[p] = nums[i];
            p = i;
        }
    }
    
    nums[p] = div;
    quick_sort(nums, begin_index, p-1);
    quick_sort(nums, p+1, end_index);
}


// sort [st, ed]
void qsort(vector<int>& v, int st, int ed){
    if(st >= ed)
        return;
    int div = v[st], i = st+1, j=ed;
    while(i < j){ // [<div][div][>=div]
        while(v[i]  < div && i < j) ++i; // i will equals to j finally.
        while(v[j] >= div && i < j) --j;
        swap(v[i], v[j]);
    }
    if(v[i] >= div) --i;
    swap(v[st], v[i]);
    
    qsort(v, st, i-1);
    qsort(v, i+1, ed);
}



/******************* Std Heap Implementions ********************/

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


/******************* Std KMP ********************/


int* getNext(string p){
    int len = (int)p.size();
    int* next = new int[len];
    memset(next, -1, sizeof(int)*len);
    
    for(int i=1; i<len; i++){
        int j = next[i-1];
        while(j >= 0 && p[j] != p[i-1])
            j = next[j];
        if(j < 0)
            next[i] = 0;
        else
            next[i] = j + 1; // p[j] == p[i-1]
    }
    
    return next;
}

// ababcdxyz  <-  ababd
int kmp(string s, string p){
    int* next = getNext(p);
    int i=0, j=0, slen = (int)s.size(), plen = (int)p.size();
    while(i < slen && j<plen){
        if(s[i] == p[j] || j == -1){
            ++i, ++j;
        }else{
            j = next[j];
        }
    }
    
    return j == plen ? i-plen : -1;
}


/******************* Testing ********************/



//#define TEST_TOOLS test

#ifdef TEST_TOOLS

int cmp_min_heap(const void* a, const void* b){
    return ((int*)a)[0] - ((int*)b)[0];
}



bool test(){
    int cs[] = {71,51, 60, 13, 30};
    int n = 10000;
    vector<int> arr = vector<int>();
    srand(time(0));
    
    for(int i=0; i<n; i++) {
        int num = rand() % 1000;
        arr.push_back(num);
        //        cout<<num<<' ';
    }
    //    cout<<endl;
    
    Heap heap = Heap(n, cmp_min_heap);
    time_t t1 = clock();
    for(int i=0; i<n; i++)
        heap.enqueue(&(arr[i]));
    //heap.printHeap();
    
    vector<int> res = vector<int>();
    time_t t2 = clock();
    
    quick_sort(arr, 0, arr.size()-1);
    time_t t3 = clock();
    
    bool ok = true;
    for(int i=0; i<n; i++)
        if(res[i] != arr[i])
            ok = false;
    
    if(!ok){
        cout<<"Fuck!!\n";
    }else
        cout<<"OK!!"<<(t2-t1)<<" "<<(t3-t2)<<endl;
    return ok;
    
}

int main(){
    int cnt = 1000;
    while(--cnt && test());
    cout<<"done";
    return 0;
}

#endif

