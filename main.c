#include <stdio.h>
#include "libs/algorithms/array/array.h"
#include "libs/data_structures/bitset/bitset.h"
#include "libs/data_structures/ordered_array_set/ordered_array_set.h"
#include "libs/data_structures/unordered_array_set/unordered_array_set.h"
#include "libs/data_structures/vector/vector.h"

void test_pushBack_emptyVector(){
    vector  v = createVector(0);
    pushBack(&v, 5);
    assert(v.size == 1);
    assert(v.capacity == 1);
    assert(v.data[0] == 5);
    deleteVector(&v);
}

void test_pushBack_fullVector(){
    vector v = createVector(5);
    for(int i = 0; i < v.capacity; i++){
        pushBack(&v, i);
    }
    assert(v.size == 5);
    pushBack(&v, 5);
    assert(v.data[v.size - 1] == 5 );
    assert(v.size == 6);
    assert(v.capacity == 10);
    deleteVector(&v);
}
void test_popBack_notEmptyVector(){
   vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);

}

void test() {

}

int main() {
    test();
    vector v = createVector(SIZE_MAX);
    return 0;
}