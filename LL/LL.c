//
//  LL.c
//  
//
//  Created by Will Salisbury on 5/23/14.
//
//

#include <stdio.h>
#include <stdlib.h>
#include "LL.h"

LL LL_create(Data val){
    LL head = (LL)malloc(sizeof(struct Node));
    head->val = val;
    head->next = NULL;
    return head;
}

void LL_destroy(LLRef list){
    LL head = *list;
    while (NULL != head) {
        LL oldHead = head;
        head = head->next;
        free(oldHead);
    }
    *list = NULL;
}

void LL_print(LL head){
    
    while (NULL != head) {
        printf("%llu\t->\t", head->val);
        head = head->next;
    }
    printf("%s\n", "ø");
}

LL LL_insert(LL head, Data val){
    if (NULL == head){
        return LL_create(val);
    }
    LL newHead = LL_create(val);
    newHead->next = head;
    return newHead;
}

bool LL_find(const LL head, Data val){
    if (NULL == head) {
        return false;
    } else {
        if (head->val == val){
            return true;
        } else {
            return LL_find(head->next, val);
        }
    }
}

void LL_find_and_print(const LL head, Data theVal){
    fprintf(stdout, "%llu was %s\n", theVal, LL_find(head, theVal)?"found":"not found");
}

LL LL_generate(void){
    return LL_insert(LL_insert(LL_insert(LL_create(10), 20), 30), 40);
}

LL LL_reverse(LL head){
    if (NULL == head) {
        return NULL;
    }
    if (NULL == head->next) {
        return head;
    }
    
    LL new_head = NULL;
    while (NULL != head) {
        LL temp = head->next;
        head->next = new_head;
        new_head = head;
        head = temp;
    }
    return new_head;
}

LL find_and_remove(LLRef list, Data val){
    LL prev, head, next;
    
    head = *list;
    
    //NULL element
    if (NULL == head) {
        return NULL;
    }
    
    if (NULL == head->next) {
        if(val == head->val){
            (*list) = NULL;
            return head;
        } else {
            return NULL;
        }
    }
    
    for (prev = NULL, next = head->next; NULL != next; prev=head, head=next, next=next->next) {
        if(val == head->val){
            if (NULL != prev) {
                head = prev;
                prev = head->next;
                head->next = next;
                (*list) = head;
                prev->next = NULL;
                return prev;
                
            } else {
                prev = head;
                head = next;
                (*list) = head;
                prev->next = NULL;
                return prev;
            }
        }
    }
    return NULL;
}

Data LL_get_val(LL head){
    if (NULL == head) {
        return UINTMAX_MAX;
    } else {
        return head->val;
    }
}
