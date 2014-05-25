//
//  main.c
//  LL
//
//  Created by Will Salisbury on 5/13/14.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "LL.h"

void test_print(void){
    // Construct and print a list
    LL ll =  LL_generate();
    LL_print(ll);
    LL_destroy(&ll);

    // Find a non-existant value
    LL new_ll = LL_generate();
    unsigned long long theVal = 50;

    LL_find_and_print(new_ll, theVal);
    assert(false == LL_find(new_ll, theVal));
    
    new_ll = LL_insert(new_ll, theVal);
    LL_find_and_print(new_ll, theVal);
    assert(true == LL_find(new_ll, theVal));
}

void test_reverse(void){
    LL test_ll = NULL;
    assert(NULL == LL_reverse(test_ll));
    
    test_ll = LL_reverse(LL_create(10));
    assert(10 == LL_get_val(test_ll));
    
    test_ll = LL_reverse(LL_insert(LL_create(10), 20));
    assert(10 == LL_get_val(test_ll));
    
    test_ll = LL_reverse(LL_insert(LL_insert(LL_create(10), 20),30));
    assert(10 == LL_get_val(test_ll));
    
    test_ll = LL_reverse(LL_reverse(LL_reverse(LL_insert(LL_create(10), 20))));
    assert(10 == LL_get_val(test_ll));
}

void test_remove(){
    Data val = 30;
    LL ll, out;
    
    
    //NULL Case
    fprintf(stdout, "%s\n", "*NULL Case*");
    ll = NULL;
    out = find_and_remove(&ll, val);
    assert(false == LL_find(ll,val));
    LL_print(ll);
    LL_print(out);
    
    //Single Case, no Val
    fprintf(stdout, "%s\n", "*Single Case, no Val*");
    ll = LL_create(42);
    out = find_and_remove(&ll, val);
    assert(false == LL_find(ll,val));
    LL_print(ll);
    LL_print(out);
    
    
    //Single Case, with Val
    fprintf(stdout, "%s\n", "*Single Case, with Val*");
    ll = LL_create(val);
    out = find_and_remove(&ll, val);
    LL_print(ll);
    LL_print(out);
    assert(false == LL_find(ll,val));
    
    //Hard Case
    fprintf(stdout, "%s\n", "*Hard Case*");
    ll = LL_generate();
    fprintf(stdout, "%s\n", "Before:");
    LL_print(ll);
    assert(true == LL_find(ll, val));
    
    out = find_and_remove(&ll, val);
    assert(val == out->val);
    assert(false == LL_find(ll,val));
    fprintf(stdout, "%s%llu\n", "Remove: ",val);
    LL_print(ll);
    LL_print(out);
    
    Data newVal = 40;
    fprintf(stdout, "%s%llu\n", "Remove: ",newVal);
    out = find_and_remove(&ll, newVal);
    assert(newVal == out->val);
    assert(false == LL_find(ll,newVal));
    LL_print(ll);
    LL_print(out);
    
    Data nonExistantVal = 42;
    fprintf(stdout, "%s%llu\n", "Remove: ",nonExistantVal);
    out = find_and_remove(&ll, nonExistantVal);
    assert(NULL == out);
    assert(false == LL_find(ll,nonExistantVal));
    LL_print(ll);
    LL_print(out);
}

int main(void) {
    
    test_print();
    test_reverse();
    test_remove();
    
    exit(EXIT_SUCCESS);
}
