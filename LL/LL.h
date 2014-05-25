//
//  LL.h
//  
//
//  Created by Will Salisbury on 5/23/14.
//
//

#ifndef _LL_h
#define _LL_h

#include <stdbool.h>

typedef unsigned long long LLDataType;

struct Node {
    LLDataType val;
    struct Node* next;
};

typedef struct Node* LL;
typedef LL* LLRef;
typedef const LLDataType Data;

Data LL_get_val(LL);

LL LL_create(Data);
void LL_destroy(LLRef);
LL LL_generate(void);

void LL_print(LL);
void LL_find_and_print(const LL , Data);

LL LL_insert(LL, Data);
bool LL_find(const LL, Data);
LL find_and_remove(LLRef , Data );
LL LL_reverse(LL);





#endif
