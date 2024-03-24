#include <stdio.h>
#include "libs/algorithms/array/array.h"
#include "libs/data_structures/bitset/bitset.h"
#include "libs/data_structures/ordered_array_set/ordered_array_set.h"
#include "libs/data_structures/unordered_array_set/unordered_array_set.h"
#include "libs/data_structures/vector/vector.h"

// тест на наличие элемента в множестве
void test_bitset_in_1() {
    bitset set = bitset_create_from_array((unsigned int[]) {1, 2, 3}, 3, 10);
    unsigned int value = 2;
    assert(bitset_in(set, value));
}

void test_bitset_in_2() {
    bitset set = bitset_create_from_array((unsigned int[]) {1, 2, 3}, 3, 10);
    unsigned int value = 4;
    assert(!bitset_in(set, value));
}

void test_bitset_in() {
    test_bitset_in_1();
    test_bitset_in_2();
}

// тест на равенство множеств
void test_bitset_isEqual_1() {
    bitset set1 = bitset_create_from_array((unsigned int[]) {1, 2, 3}, 3,
                                           10);
    bitset set2 = bitset_create_from_array((unsigned int[]) {1, 2, 3}, 3,
                                           10);
    assert(bitset_isEqual(set1, set2));
}

void test_bitset_isEqual_2() {
    bitset set1 = bitset_create_from_array((unsigned int[]) {1, 2, 3}, 3,
                                           10);
    bitset set2 = bitset_create_from_array((unsigned int[]) {1, 2, 4}, 3,
                                           10);
    assert(!bitset_isEqual(set1, set2));
}

void test_bitset_isEqual() {
    test_bitset_isEqual_1();
    test_bitset_isEqual_2();
}

// тест на является ли одно множество подмножеством другого
void test_bitset_isSubset_1() {
    bitset set1 = bitset_create_from_array((unsigned int[]) {1, 2, 3, 4}, 4,
                                           10);
    bitset set2 = bitset_create_from_array((unsigned int[]) {1, 2, 3}, 3,
                                           10);
    assert(bitset_isSubset(set2, set1));
}

void test_bitset_isSubset_2() {
    bitset set1 = bitset_create_from_array((unsigned int[]) {1, 2, 3, 4}, 4,
                                           10);
    bitset set2 = bitset_create_from_array((unsigned int[]) {1, 2, 3, 5}, 4,
                                           10);
    assert(!bitset_isSubset(set1, set2));
}

void test_bitset_isSubset_3() {
    bitset set1 = bitset_create_from_array((unsigned int[]) {1, 2, 3, 4}, 4,
                                           10);
    bitset set2 = bitset_create_from_array((unsigned int[]) {}, 0, 10);
    assert(bitset_isSubset(set2, set1));
}

void test_bitset_isSubset_4() {
    bitset set1 = bitset_create_from_array((unsigned int[]) {1, 2, 3, 4}, 4,
                                           10);
    bitset set2 = bitset_create_from_array((unsigned int[]) {1, 2, 3, 4}, 4,
                                           10);
    assert(bitset_isSubset(set1, set2));
}

void test_bitset_isSubset() {
    test_bitset_isSubset_1();
    test_bitset_isSubset_2();
    test_bitset_isSubset_3();
    test_bitset_isSubset_4();
}

// тест на вставку элемента в множество
void test_bitset_insert_1() {
    bitset set = bitset_create_from_array((unsigned int[]) {1, 3}, 2, 10);
    unsigned int value = 2;
    bitset_insert(&set, value);
    bitset result_set = bitset_create_from_array((unsigned int[]) {1, 2, 3},
                                                 3, 10);
    assert(bitset_isEqual(set, result_set));
}

void test_bitset_insert_2() {
    bitset set = bitset_create_from_array((unsigned int[]) {1, 3}, 2, 10);
    unsigned int value = 3;
    bitset_insert(&set, value);
    bitset result_set = bitset_create_from_array((unsigned int[]) {1, 3}, 2,
                                                 10);
    assert(bitset_isEqual(set, result_set));
}

void test_bitset_insert() {
    test_bitset_insert_1();
    test_bitset_insert_2();
}

// тест на удаление элемента
void test_bitset_deleteElement_1() {
    bitset set = bitset_create_from_array((unsigned int[]) {1, 2, 3}, 3, 10);
    unsigned int value = 2;
    bitset_deleteElement(&set, value);
    bitset result_set = bitset_create_from_array((unsigned int[]) {1, 3}, 2,
                                                 10);
    assert(bitset_isEqual(set, result_set));
}

void test_bitset_deleteElement_2() {
    bitset set = bitset_create_from_array((unsigned int[]) {1, 2, 3}, 3, 10);
    unsigned int value = 4;
    bitset_deleteElement(&set, value);
    bitset result_set = bitset_create_from_array((unsigned int[]) {1, 2, 3},
                                                 3, 10);
    assert(bitset_isEqual(set, result_set));
}

void test_bitset_deleteElement() {
    test_bitset_deleteElement_1();
    test_bitset_deleteElement_2();
}

// тест на объединение множеств
void test_bitset_union_1() {
    bitset set1 = bitset_create_from_array((unsigned int[]) {1, 2, 3}, 3,
                                           10);
    bitset set2 = bitset_create_from_array((unsigned int[]) {4, 5, 6}, 3,
                                           10);
    bitset res_set = bitset_union(set1, set2);
    bitset check_set = bitset_create_from_array((unsigned int[]) {1, 2, 3, 4,
                                                                  5, 6}, 6, 10);
    assert(bitset_isEqual(res_set, check_set));
}

void test_bitset_union_2() {
    bitset set1 = bitset_create_from_array((unsigned int[]) {1, 2, 3}, 3,
                                           10);
    bitset set2 = bitset_create_from_array((unsigned int[]) {3, 4, 5}, 3,
                                           10);
    bitset res_set = bitset_union(set1, set2);
    bitset check_set = bitset_create_from_array((unsigned int[]) {1, 2, 3, 4,
                                                                  5}, 5, 10);
    assert(bitset_isEqual(res_set, check_set));
}

void test_bitset_union_3() {
    bitset set1 = bitset_create_from_array((unsigned int[]) {1, 2, 3}, 3,
                                           10);
    bitset set2 = bitset_create_from_array((unsigned int[]) {1, 2, 3}, 3,
                                           10);
    bitset res_set = bitset_union(set1, set2);
    bitset check_set = bitset_create_from_array((unsigned int[]) {1, 2, 3}, 3, 10);
    assert(bitset_isEqual(res_set, check_set));
}

void test_bitset_union_4() {
    bitset set1 = bitset_create_from_array((unsigned int[]) {1, 2, 3}, 3, 10);
    bitset set2 = bitset_create_from_array((unsigned int[]) {}, 0, 10);
    bitset res_set = bitset_union(set1, set2);
    bitset check_set = bitset_create_from_array((unsigned int[]) {1, 2, 3},
                                                3, 10);
    assert(bitset_isEqual(res_set, check_set));
}

void test_bitset_union() {
    test_bitset_union_1();
    test_bitset_union_2();
    test_bitset_union_3();
    test_bitset_union_4();
}

// тест на пересечение множеств
void test_bitset_intersection_1() {
    bitset set1 = bitset_create_from_array((unsigned int[]) {1, 2, 3}, 3,
                                           10);
    bitset set2 = bitset_create_from_array((unsigned int[]) {1, 2, 4}, 3,
                                           10);
    bitset res_set = bitset_intersection(set1, set2);
    bitset check_set = bitset_create_from_array((unsigned int[]) {1, 2}, 2,
                                                10);
    assert(bitset_isEqual(res_set, check_set));
}

void test_bitset_intersection_2() {
    bitset set1 = bitset_create_from_array((unsigned int[]) {1, 2, 3}, 3,
                                           10);
    bitset set2 = bitset_create_from_array((unsigned int[]) {4, 5, 6}, 3,
                                           10);
    bitset res_set = bitset_intersection(set1, set2);
    bitset check_set = bitset_create_from_array((unsigned int[]) {}, 0, 5);
    assert(bitset_isEqual(res_set, check_set));
}

void test_bitset_intersection_3() {
    bitset set1 = bitset_create_from_array((unsigned int[]) {1, 2, 3}, 3,
                                           10);
    bitset set2 = bitset_create_from_array((unsigned int[]) {1, 2, 3}, 3,
                                           10);
    bitset res_set = bitset_intersection(set1, set2);
    bitset check_set = bitset_create_from_array((unsigned int[]) {1, 2, 3},
                                                3, 10);
    assert(bitset_isEqual(res_set, check_set));
}

void test_bitset_intersection() {
    test_bitset_intersection_1();
    test_bitset_intersection_2();
    test_bitset_intersection_3();
}

// тест на разность множеств
void test_bitset_difference_1() {
    bitset set1 = bitset_create_from_array((unsigned int[]) {1, 2, 3}, 3,
                                           10);
    bitset set2 = bitset_create_from_array((unsigned int[]) {1, 3, 4}, 3,
                                           10);
    bitset res_set = bitset_difference(set1, set2);
    bitset check_set = bitset_create_from_array((unsigned int[]) {2}, 1, 10);
    assert(bitset_isEqual(res_set, check_set));
}

void test_bitset_difference_2() {
    bitset set1 = bitset_create_from_array((unsigned int[]) {1, 2, 3}, 3,
                                           10);
    bitset set2 = bitset_create_from_array((unsigned int[]) {}, 0, 10);
    bitset res_set = bitset_difference(set1, set2);
    bitset check_set = bitset_create_from_array((unsigned int[]) {1, 2, 3},
                                                3, 10);
    assert(bitset_isEqual(res_set, check_set));
}

void test_bitset_difference_3() {
    bitset set1 = bitset_create_from_array((unsigned int[]) {1, 2, 3}, 3,
                                           10);
    bitset set2 = bitset_create_from_array((unsigned int[]) {1, 2, 3}, 3,
                                           10);
    bitset res_set = bitset_difference(set1, set2);
    bitset check_set = bitset_create_from_array((unsigned int[]) {}, 0, 5);
    assert(bitset_isEqual(res_set, check_set));
}

void test_bitset_difference() {
    test_bitset_difference_1();
    test_bitset_difference_2();
    test_bitset_difference_3();
}

// тест на симметрическую разность
void test_bitset_symmetricDifference_1() {
    bitset set1 = bitset_create_from_array((unsigned int[]) {1, 2, 3}, 3,
                                           10);
    bitset set2 = bitset_create_from_array((unsigned int[]) {1, 3, 4}, 3,
                                           10);
    bitset res_set = bitset_symmetricDifference(set1, set2);
    bitset check_set = bitset_create_from_array((unsigned int[]) {2, 4}, 2,
                                                10);
    assert(bitset_isEqual(res_set, check_set));
}

void test_bitset_symmetricDifference_2() {
    bitset set1 = bitset_create_from_array((unsigned int[]) {1, 2, 3}, 3,
                                           10);
    bitset set2 = bitset_create_from_array((unsigned int[]) {4, 5, 6}, 3,
                                           10);
    bitset res_set = bitset_symmetricDifference(set1, set2);
    bitset check_set = bitset_create_from_array((unsigned int[]) {1, 2, 3, 4,
                                                                  5, 6}, 6, 10);
    assert(bitset_isEqual(res_set, check_set));
}

void test_bitset_symmetricDifference_3() {
    bitset set1 = bitset_create_from_array((unsigned int[]) {1, 2, 3}, 3,
                                           10);
    bitset set2 = bitset_create_from_array((unsigned int[]) {1, 2, 3}, 3,
                                           10);
    bitset res_set = bitset_symmetricDifference(set1, set2);
    bitset check_set = bitset_create_from_array((unsigned int[]) {}, 0, 10);
    assert(bitset_isEqual(res_set, check_set));
}

void test_bitset_symmetricDifference() {
    test_bitset_symmetricDifference_1();
    test_bitset_symmetricDifference_2();
    test_bitset_symmetricDifference_3();
}

// тест на дополенение множества
void test_bitset_complement_1() {
    bitset set = bitset_create_from_array((unsigned int[]) {1, 2, 3}, 3, 10);
    bitset res_set = bitset_complement(set);
    bitset check_set = bitset_create_from_array((unsigned int[]) {0, 4, 5, 6,
                                                                  7, 8, 9, 10}, 8, 10);
    assert(bitset_isEqual(res_set, check_set));
}

void test_bitset_complement_2() {
    bitset set = bitset_create_from_array((unsigned int[]) {0, 1, 2, 3, 4, 5,
                                                            6, 7, 8, 9, 10}, 11, 10);
    bitset res_set = bitset_complement(set);
    bitset check_set = bitset_create_from_array((unsigned int[]) {}, 0, 10);
    assert(bitset_isEqual(res_set, check_set));
}

void test_bitset_complement_3() {
    bitset set = bitset_create_from_array((unsigned int[]) {}, 0, 10);
    bitset res_set = bitset_complement(set);
    bitset check_set = bitset_create_from_array((unsigned int[]) {0, 1, 2, 3,
                                                                  4, 5, 6, 7, 8, 9, 10}, 11, 10);
    assert(bitset_isEqual(res_set, check_set));
}

void test_bitset_complement() {
    test_bitset_complement_1();
    test_bitset_complement_2();
    test_bitset_complement_3();
}

void test_bitset() {
    test_bitset_in();
    test_bitset_isEqual();
    test_bitset_isSubset();
    test_bitset_insert();
    test_bitset_deleteElement();
    test_bitset_union();
    test_bitset_intersection();
    test_bitset_difference();
    test_bitset_symmetricDifference();
    test_bitset_complement();
}

// тест для множеств на неупорядоченном массиве
// тест на наличие элемента в множестве
void test_unordered_array_set_in_1() {
    unordered_array_set set = unordered_array_set_create_from_array((int[])
                                                                            {1, 2, 3}, 3);
    int value = 2;
    assert(unordered_array_set_in(&set, value) == 1);
    unordered_array_set_delete(&set);
}

void test_unordered_array_set_in_2() {
    unordered_array_set set = unordered_array_set_create_from_array((int[])
                                                                            {1, 2, 3}, 3);
    int value = 4;
    assert(unordered_array_set_in(&set, value) == 3);
    unordered_array_set_delete(&set);
}

void test_unordered_array_set_in() {
    test_unordered_array_set_in_1();
    test_unordered_array_set_in_2();
}

// тест на то, является ли одно множество подмножеством другого
void test_unordered_array_set_isSubset_1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[])
                                                                             {1, 2, 3, 4, 5}, 5);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[])
                                                                             {1, 2, 3}, 3);
    assert(unordered_array_set_isSubset(set2, set1));
    unordered_array_set_delete(&set1);
    unordered_array_set_delete(&set2);
}

void test_unordered_array_set_isSubset_2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[])
                                                                             {1, 2, 3, 4, 5}, 5);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[])
                                                                             {1, 2, 6}, 3);
    assert(!unordered_array_set_isSubset(set2, set1));
    unordered_array_set_delete(&set1);
    unordered_array_set_delete(&set2);
}

void test_unordered_array_set_isSubset_3() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[])
                                                                             {5, 2, 1, 3, 6}, 5);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[])
                                                                             {1, 2, 6}, 3);
    assert(unordered_array_set_isSubset(set2, set1));
    unordered_array_set_delete(&set1);
    unordered_array_set_delete(&set2);
}

void test_unordered_array_set_isSubset_4() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[])
                                                                             {5, 2, 1, 3, 6}, 5);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[])
                                                                             {1, 2, 6, 3, 5}, 5);
    assert(unordered_array_set_isSubset(set2, set1));
    unordered_array_set_delete(&set1);
    unordered_array_set_delete(&set2);
}

void test_unordered_array_set_isSubset() {
    test_unordered_array_set_isSubset_1();
    test_unordered_array_set_isSubset_2();
    test_unordered_array_set_isSubset_3();
    test_unordered_array_set_isSubset_4();
}

// тест на равенство множеств
void test_unordered_array_set_isEqual_1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[])
                                                                             {5, 2, 1, 3, 6}, 5);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[])
                                                                             {1, 2, 6, 3, 5}, 5);
    assert(unordered_array_set_isEqual(set2, set1));
    unordered_array_set_delete(&set1);
    unordered_array_set_delete(&set2);
}

void test_unordered_array_set_isEqual_2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[])
                                                                             {5, 2, 1, 3, 6}, 5);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[])
                                                                             {1, 2, 6}, 3);
    assert(!unordered_array_set_isEqual(set2, set1));
    unordered_array_set_delete(&set1);
    unordered_array_set_delete(&set2);
}

void test_unordered_array_set_isEqual() {
    test_unordered_array_set_isEqual_1();
    test_unordered_array_set_isEqual_2();
}

// тест на то, можно ли вставить элемент в множество
void test_unordered_array_set_isAbleAppend_1() {
    unordered_array_set set = unordered_array_set_create(5);
    assert(unordered_array_set_isAbleAppend(&set));
    unordered_array_set_delete(&set);
}

void test_unordered_array_set_isAbleAppend_2() {
    unordered_array_set set = unordered_array_set_create(0);
    assert(!unordered_array_set_isAbleAppend(&set));
    unordered_array_set_delete(&set);
}

void test_unordered_array_set_isAbleAppend() {
    test_unordered_array_set_isAbleAppend_1();
    test_unordered_array_set_isAbleAppend_2();
}

// тест на вставку элемента
void test_unordered_array_set_insert_1() {
    unordered_array_set set = unordered_array_set_create(3);
    unordered_array_set_insert(&set, 1);
    unordered_array_set_insert(&set, 3);
    unordered_array_set_insert(&set, 7);
    unordered_array_set check_set =
            unordered_array_set_create_from_array((int[]) {1, 3, 7}, 3);
    assert(unordered_array_set_isEqual(set, check_set));
    unordered_array_set_delete(&set);
    unordered_array_set_delete(&check_set);
}

void test_unordered_array_set_insert_2() {
    unordered_array_set set = unordered_array_set_create(4);
    unordered_array_set_insert(&set, 1);
    unordered_array_set_insert(&set, 3);
    unordered_array_set_insert(&set, 3);
    unordered_array_set_insert(&set, 7);
    unordered_array_set check_set =
            unordered_array_set_create_from_array((int[]) {1, 3, 7}, 3);
    assert(unordered_array_set_isEqual(set, check_set));
    unordered_array_set_delete(&set);
    unordered_array_set_delete(&check_set);
}

void test_unordered_array_set_insert() {
    test_unordered_array_set_insert_1();
    test_unordered_array_set_insert_2();
}

// тест на удаление элемента
void test_unordered_array_set_deleteElement_1() {
    unordered_array_set set = unordered_array_set_create_from_array((int[])
                                                                            {1, 4, 5, 3}, 4);
    unordered_array_set_deleteElement(&set, 1);
    unordered_array_set check_set =
            unordered_array_set_create_from_array((int[]) {4, 5, 3}, 3);
    assert(unordered_array_set_isEqual(set, check_set));
    unordered_array_set_delete(&set);
    unordered_array_set_delete(&check_set);
}

void test_unordered_array_set_deleteElement_2() {
    unordered_array_set set = unordered_array_set_create_from_array((int[])
                                                                            {1, 4, 5, 3}, 4);
    unordered_array_set_deleteElement(&set, 1);
    unordered_array_set_deleteElement(&set, 4);
    unordered_array_set_deleteElement(&set, 5);
    unordered_array_set_deleteElement(&set, 3);
    unordered_array_set check_set =
            unordered_array_set_create_from_array((int[]) {}, 0);
    assert(unordered_array_set_isEqual(set, check_set));
    unordered_array_set_delete(&set);
    unordered_array_set_delete(&check_set);
}

void test_unordered_array_set_deleteElement() {
    test_unordered_array_set_deleteElement_1();
    test_unordered_array_set_deleteElement_2();
}

// тест на объединение множеств
void test_unordered_array_set_union_1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[])
                                                                             {1, 4, 5, 3}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[])
                                                                             {6, 8, 10}, 3);
    unordered_array_set result_set = unordered_array_set_union(set1, set2);
    unordered_array_set check_set =
            unordered_array_set_create_from_array((int[]) {1, 4, 5, 3, 6, 8, 10}, 7);
    assert(unordered_array_set_isEqual(result_set, check_set));
    unordered_array_set_delete(&result_set);
    unordered_array_set_delete(&set1);
    unordered_array_set_delete(&set2);
    unordered_array_set_delete(&check_set);
}

void test_unordered_array_set_union_2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[])
                                                                             {1, 4, 5, 3}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[])
                                                                             {4, 5, 10}, 3);
    unordered_array_set result_set = unordered_array_set_union(set1, set2);
    unordered_array_set check_set =
            unordered_array_set_create_from_array((int[]) {1, 4, 5, 3, 10}, 5);
    assert(unordered_array_set_isEqual(result_set, check_set));
    unordered_array_set_delete(&result_set);
    unordered_array_set_delete(&set1);
    unordered_array_set_delete(&set2);
    unordered_array_set_delete(&check_set);
}

void test_unordered_array_set_union_3() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[])
                                                                             {1, 4, 5, 3}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[])
                                                                             {}, 0);
    unordered_array_set result_set = unordered_array_set_union(set1, set2);
    unordered_array_set check_set =
            unordered_array_set_create_from_array((int[]) {1, 4, 5, 3}, 4);
    assert(unordered_array_set_isEqual(result_set, check_set));
    unordered_array_set_delete(&result_set);
    unordered_array_set_delete(&set1);
    unordered_array_set_delete(&set2);
    unordered_array_set_delete(&check_set);
}

void test_unordered_array_set_union() {
    test_unordered_array_set_union_1();
    test_unordered_array_set_union_2();
    test_unordered_array_set_union_3();
}

// тест на пересечение множеств
void test_unordered_array_set_intersection_1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[])
                                                                             {1, 4, 5, 3}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[])
                                                                             {1, 6, 5, 2}, 4);
    unordered_array_set result_set = unordered_array_set_intersection(set1,
                                                                      set2);
    unordered_array_set check_set =
            unordered_array_set_create_from_array((int[]) {1, 5}, 2);
    assert(unordered_array_set_isEqual(result_set, check_set));
    unordered_array_set_delete(&result_set);
    unordered_array_set_delete(&set1);
    unordered_array_set_delete(&set2);
    unordered_array_set_delete(&check_set);
}

void test_unordered_array_set_intersection_2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[])
                                                                             {1, 4, 5, 3}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[])
                                                                             {2, 6, 7, 10}, 4);
    unordered_array_set result_set = unordered_array_set_intersection(set1,
                                                                      set2);
    unordered_array_set check_set =
            unordered_array_set_create_from_array((int[]) {}, 0);
    assert(unordered_array_set_isEqual(result_set, check_set));
    unordered_array_set_delete(&result_set);
    unordered_array_set_delete(&set1);
    unordered_array_set_delete(&set2);
    unordered_array_set_delete(&check_set);
}

void test_unordered_array_set_intersection() {
    test_unordered_array_set_intersection_1();
    test_unordered_array_set_intersection_2();
}

// тест на разность множеств
void test_unordered_array_set_difference_1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[])
                                                                             {1, 4, 5, 3}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[])
                                                                             {5, 3}, 2);
    unordered_array_set result_set = unordered_array_set_difference(set1,
                                                                    set2);
    unordered_array_set check_set =
            unordered_array_set_create_from_array((int[]) {1, 4}, 2);
    assert(unordered_array_set_isEqual(result_set, check_set));
    unordered_array_set_delete(&result_set);
    unordered_array_set_delete(&set1);
    unordered_array_set_delete(&set2);
    unordered_array_set_delete(&check_set);
}

void test_unordered_array_set_difference_2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[])
                                                                             {1, 4, 5, 3}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[])
                                                                             {6, 8}, 2);
    unordered_array_set result_set = unordered_array_set_difference(set1,
                                                                    set2);
    unordered_array_set check_set =
            unordered_array_set_create_from_array((int[]) {1, 4, 5, 3}, 4);
    assert(unordered_array_set_isEqual(result_set, check_set));
    unordered_array_set_delete(&result_set);
    unordered_array_set_delete(&set1);
    unordered_array_set_delete(&set2);
    unordered_array_set_delete(&check_set);
}

void test_unordered_array_set_difference_3() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[])
                                                                             {1, 4, 5, 3}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[])
                                                                             {1, 4, 5, 3}, 4);
    unordered_array_set result_set = unordered_array_set_difference(set1,
                                                                    set2);
    unordered_array_set check_set =
            unordered_array_set_create_from_array((int[]) {}, 0);
    assert(unordered_array_set_isEqual(result_set, check_set));
    unordered_array_set_delete(&result_set);
    unordered_array_set_delete(&set1);
    unordered_array_set_delete(&set2);
    unordered_array_set_delete(&check_set);
}

void test_unordered_array_set_difference() {
    test_unordered_array_set_difference_1();
    test_unordered_array_set_difference_2();
    test_unordered_array_set_difference_3();
}

// тест на дополнение множеств
void test_unordered_array_set_complement_1() {
    unordered_array_set set = unordered_array_set_create_from_array((int[])
                                                                            {1, 4, 5, 3}, 4);
    unordered_array_set universumSet =
            unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    unordered_array_set result_set = unordered_array_set_complement(set,
                                                                    universumSet);
    assert(unordered_array_set_isSubset(result_set, universumSet));
    unordered_array_set_delete(&result_set);
    unordered_array_set_delete(&set);
    unordered_array_set_delete(&universumSet);
}

void test_unordered_array_set_complement_2() {
    unordered_array_set set = unordered_array_set_create_from_array((int[])
                                                                            {1, 4, 5, 3, 2}, 5);
    unordered_array_set universumSet =
            unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    unordered_array_set result_set = unordered_array_set_complement(set,
                                                                    universumSet);
    assert(unordered_array_set_isSubset(result_set, universumSet));
    unordered_array_set_delete(&result_set);
    unordered_array_set_delete(&set);
    unordered_array_set_delete(&universumSet);
}

void test_unordered_array_set_complement_3() {
    unordered_array_set set = unordered_array_set_create_from_array((int[])
                                                                            {}, 0);
    unordered_array_set universumSet =
            unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    unordered_array_set result_set = unordered_array_set_complement(set,
                                                                    universumSet);
    assert(unordered_array_set_isSubset(result_set, universumSet));
    unordered_array_set_delete(&result_set);
    unordered_array_set_delete(&set);
    unordered_array_set_delete(&universumSet);
}

void test_unordered_array_set_complement() {
    test_unordered_array_set_complement_1();
    test_unordered_array_set_complement_2();
    test_unordered_array_set_complement_3();
}

// тест на симметрическую разность множеств
void test_unordered_array_set_symmetricDifference_1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[])
                                                                             {1, 4, 5, 3}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[])
                                                                             {2, 4, 6, 3}, 4);
    unordered_array_set result_set =
            unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set check_set =
            unordered_array_set_create_from_array((int[]) {1, 5, 2, 6}, 4);
    assert(unordered_array_set_isEqual(result_set, check_set));
    unordered_array_set_delete(&result_set);
    unordered_array_set_delete(&set1);
    unordered_array_set_delete(&set2);
    unordered_array_set_delete(&check_set);
}

void test_unordered_array_set_symmetricDifference_2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[])
                                                                             {1, 4, 5, 3}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[])
                                                                             {2, 9, 6, 10}, 4);
    unordered_array_set result_set =
            unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set check_set =
            unordered_array_set_create_from_array((int[]) {1, 4, 5, 3, 2, 9, 6, 10}, 8);
    assert(unordered_array_set_isEqual(result_set, check_set));
    unordered_array_set_delete(&result_set);
    unordered_array_set_delete(&set1);
    unordered_array_set_delete(&set2);
    unordered_array_set_delete(&check_set);
}

void test_unordered_array_set_symmetricDifference_3() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[])
                                                                             {1, 4, 5, 3}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[])
                                                                             {1, 4, 5, 3}, 4);
    unordered_array_set result_set =
            unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set check_set =
            unordered_array_set_create_from_array((int[]) {}, 0);
    assert(unordered_array_set_isEqual(result_set, check_set));
    unordered_array_set_delete(&result_set);
    unordered_array_set_delete(&set1);
    unordered_array_set_delete(&set2);
    unordered_array_set_delete(&check_set);
}

void test_unordered_array_set_symmetricDifference() {
    test_unordered_array_set_symmetricDifference_1();
    test_unordered_array_set_symmetricDifference_2();
    test_unordered_array_set_symmetricDifference_3();
}

void test_unordered_array_set() {
    test_unordered_array_set_in();
    test_unordered_array_set_isSubset();
    test_unordered_array_set_isEqual();
    test_unordered_array_set_isAbleAppend();
    test_unordered_array_set_insert();
    test_unordered_array_set_deleteElement();
    test_unordered_array_set_union();
    test_unordered_array_set_intersection();
    test_unordered_array_set_difference();
    test_unordered_array_set_complement();
    test_unordered_array_set_symmetricDifference();
}

// тест для множеств на упорядоченном массиве
// тест на наличие элемента в множестве
void test_ordered_array_set_in_1() {
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {1,
                                                                         2, 3}, 3);
    int value = 2;
    assert(ordered_array_set_in(&set, value) == 1);
    ordered_array_set_delete(&set);
}

void test_ordered_array_set_in_2() {
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {1,
                                                                         2, 3}, 3);
    int value = 4;
    assert(ordered_array_set_in(&set, value) == 3);
    ordered_array_set_delete(&set);
}

void test_ordered_array_set_in() {
    test_ordered_array_set_in_1();
    test_ordered_array_set_in_2();
}

// тест на то, является ли одно множество подмножеством другого
void test_ordered_array_set_isSubset_1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1,
                                                                          2, 3, 4, 5}, 5);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1,
                                                                          2, 3}, 3);
    assert(ordered_array_set_isSubset(set2, set1));
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
}

void test_ordered_array_set_isSubset_2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1,
                                                                          2, 3, 4, 5}, 5);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1,
                                                                          2, 6}, 3);
    assert(!ordered_array_set_isSubset(set2, set1));
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
}

void test_ordered_array_set_isSubset_3() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1,
                                                                          2, 3, 5, 6}, 5);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1,
                                                                          2, 6}, 3);
    assert(ordered_array_set_isSubset(set2, set1));
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
}

void test_ordered_array_set_isSubset_4() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1,
                                                                          2, 3, 5, 6}, 5);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1,
                                                                          2, 3, 5, 6}, 5);
    assert(ordered_array_set_isSubset(set2, set1));
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
}

void test_ordered_array_set_isSubset() {
    test_ordered_array_set_isSubset_1();
    test_ordered_array_set_isSubset_2();
    test_ordered_array_set_isSubset_3();
    test_ordered_array_set_isSubset_4();
}

// тест на равенство множеств
void test_ordered_array_set_isEqual_1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1,
                                                                          2, 3, 5, 6}, 5);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1,
                                                                          2, 3, 5, 6}, 5);
    assert(ordered_array_set_isEqual(set2, set1));
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
}

void test_ordered_array_set_isEqual_2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1,
                                                                          2, 3, 5, 6}, 5);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1,
                                                                          2, 6}, 3);
    assert(!ordered_array_set_isEqual(set2, set1));
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
}

void test_ordered_array_set_isEqual() {
    test_ordered_array_set_isEqual_1();
    test_ordered_array_set_isEqual_2();
}

// тест на то, можно ли вставить элемент в множество
void test_ordered_array_set_isAbleAppend_1() {
    ordered_array_set set = ordered_array_set_create(5);
    assert(ordered_array_set_isAbleAppend(&set) != 0);
    ordered_array_set_delete(&set);
}

void test_ordered_array_set_isAbleAppend_2() {
    ordered_array_set set = ordered_array_set_create(0);
    assert(ordered_array_set_isAbleAppend(&set) == 0);
    ordered_array_set_delete(&set);
}

void test_ordered_array_set_isAbleAppend() {
    test_ordered_array_set_isAbleAppend_1();
    test_ordered_array_set_isAbleAppend_2();
}

// тест на вставку элемента
void test_ordered_array_set_insert_1() {
    ordered_array_set set = ordered_array_set_create(3);
    ordered_array_set_insert(&set, 1);
    ordered_array_set_insert(&set, 3);
    ordered_array_set_insert(&set, 7);
    ordered_array_set check_set = ordered_array_set_create_from_array((int[])
                                                                              {1, 3, 7}, 3);
    assert(ordered_array_set_isEqual(set, check_set));
    ordered_array_set_delete(&set);
    ordered_array_set_delete(&check_set);
}

void test_ordered_array_set_insert_2() {
    ordered_array_set set = ordered_array_set_create(4);
    ordered_array_set_insert(&set, 1);
    ordered_array_set_insert(&set, 3);
    ordered_array_set_insert(&set, 3);
    ordered_array_set_insert(&set, 7);
    ordered_array_set check_set = ordered_array_set_create_from_array((int[])
                                                                              {1, 3, 7}, 3);
    assert(ordered_array_set_isEqual(set, check_set));
    ordered_array_set_delete(&set);
    ordered_array_set_delete(&check_set);
}

void test_ordered_array_set_insert() {
    test_ordered_array_set_insert_1();
    test_ordered_array_set_insert_2();
}

// тест на удаление элемента
void test_ordered_array_set_deleteElement_1() {
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {1, 3, 4, 5}, 4);
    ordered_array_set_deleteElement(&set, 1);
    ordered_array_set check_set = ordered_array_set_create_from_array((int[])
                                                                              {3, 4, 5}, 3);
    assert(ordered_array_set_isEqual(set, check_set));
    ordered_array_set_delete(&set);
    ordered_array_set_delete(&check_set);
}

void test_ordered_array_set_deleteElement_2() {
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {1,3, 4, 5}, 4);
    ordered_array_set_deleteElement(&set, 1);
    ordered_array_set_deleteElement(&set, 3);
    ordered_array_set_deleteElement(&set, 4);
    ordered_array_set_deleteElement(&set, 5);
    ordered_array_set check_set = ordered_array_set_create_from_array((int[])
                                                                              {}, 0);
    assert(ordered_array_set_isEqual(set, check_set));
    ordered_array_set_delete(&set);
    ordered_array_set_delete(&check_set);
}

void test_ordered_array_set_deleteElement() {
    test_ordered_array_set_deleteElement_1();
    test_ordered_array_set_deleteElement_2();
}

// тест на объединение множеств
void test_ordered_array_set_union_1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1,
                                                                          3, 4, 5}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {6,
                                                                          8, 10}, 3);
    ordered_array_set result_set = ordered_array_set_union(set1, set2);
    ordered_array_set check_set = ordered_array_set_create_from_array((int[])
                                                                              {1, 3, 4, 5, 6, 8, 10}, 7);
    assert(ordered_array_set_isEqual(result_set, check_set));
    ordered_array_set_delete(&result_set);
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
    ordered_array_set_delete(&check_set);
}

void test_ordered_array_set_union_2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1,
                                                                          3, 4, 5}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {4,
                                                                          5, 10}, 3);
    ordered_array_set result_set = ordered_array_set_union(set1, set2);
    ordered_array_set check_set = ordered_array_set_create_from_array((int[])
                                                                              {1, 3, 4, 5, 10}, 5);
    assert(ordered_array_set_isEqual(result_set, check_set));
    ordered_array_set_delete(&result_set);
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
    ordered_array_set_delete(&check_set);
}

void test_ordered_array_set_union_3() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1,
                                                                          3, 4, 5}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {},
                                                                 0);
    ordered_array_set result_set = ordered_array_set_union(set1, set2);
    ordered_array_set check_set = ordered_array_set_create_from_array((int[])
                                                                              {1, 3, 4, 5}, 4);
    assert(ordered_array_set_isEqual(result_set, check_set));
    ordered_array_set_delete(&result_set);
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
    ordered_array_set_delete(&check_set);
}

void test_ordered_array_set_union() {
    test_ordered_array_set_union_1();
    test_ordered_array_set_union_2();
    test_ordered_array_set_union_3();
}

// тест на пересечение множеств
void test_ordered_array_set_intersection_1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1,
                                                                          3, 4, 5}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1,
                                                                          2, 5, 6}, 4);
    ordered_array_set result_set = ordered_array_set_intersection(set1,
                                                                  set2);
    ordered_array_set check_set = ordered_array_set_create_from_array((int[])
                                                                              {1, 5}, 2);
    assert(ordered_array_set_isEqual(result_set, check_set));
    ordered_array_set_delete(&result_set);
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
    ordered_array_set_delete(&check_set);
}

void test_ordered_array_set_intersection_2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1,
                                                                          3, 4, 5}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {2,
                                                                          6, 7, 10}, 4);
    ordered_array_set result_set = ordered_array_set_intersection(set1,
                                                                  set2);
    ordered_array_set check_set = ordered_array_set_create_from_array((int[])
                                                                              {}, 0);
    assert(ordered_array_set_isEqual(result_set, check_set));
    ordered_array_set_delete(&result_set);
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
    ordered_array_set_delete(&check_set);
}

void test_ordered_array_set_intersection() {
    test_ordered_array_set_intersection_1();
    test_ordered_array_set_intersection_2();
}

// тест на разность множеств
void test_ordered_array_set_difference_1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1,
                                                                          3, 4, 5}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {3,
                                                                          5}, 2);
    ordered_array_set result_set = ordered_array_set_difference(set1, set2);
    ordered_array_set check_set = ordered_array_set_create_from_array((int[])
                                                                              {1, 4}, 2);
    assert(ordered_array_set_isEqual(result_set, check_set));
    ordered_array_set_delete(&result_set);
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
    ordered_array_set_delete(&check_set);
}

void test_ordered_array_set_difference_2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1,
                                                                          3, 4, 5}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {6,
                                                                          8}, 2);
    ordered_array_set result_set = ordered_array_set_difference(set1, set2);
    ordered_array_set check_set = ordered_array_set_create_from_array((int[])
                                                                              {1, 3, 4, 5}, 4);
    assert(ordered_array_set_isEqual(result_set, check_set));
    ordered_array_set_delete(&result_set);
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
    ordered_array_set_delete(&check_set);
}

void test_ordered_array_set_difference_3() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1,
                                                                          3, 4, 5}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1,
                                                                          3, 4, 5}, 4);
    ordered_array_set result_set = ordered_array_set_difference(set1, set2);
    ordered_array_set check_set = ordered_array_set_create_from_array((int[])
                                                                              {}, 0);
    assert(ordered_array_set_isEqual(result_set, check_set));
    ordered_array_set_delete(&result_set);
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
    ordered_array_set_delete(&check_set);
}

void test_ordered_array_set_difference() {
    test_ordered_array_set_difference_1();
    test_ordered_array_set_difference_2();
    test_ordered_array_set_difference_3();
}

// тест на дополнение множеств
void test_ordered_array_set_complement_1() {
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {1,
                                                                         3, 4, 5}, 4);
    ordered_array_set universumSet =
            ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    ordered_array_set result_set = ordered_array_set_complement(set,
                                                                universumSet);
    assert(ordered_array_set_isSubset(result_set, universumSet));
    ordered_array_set_delete(&result_set);
    ordered_array_set_delete(&set);
    ordered_array_set_delete(&universumSet);
}

void test_ordered_array_set_complement_2() {
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {1,
                                                                         2, 3, 4, 5}, 5);
    ordered_array_set universumSet =
            ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    ordered_array_set result_set = ordered_array_set_complement(set,
                                                                universumSet);
    assert(ordered_array_set_isSubset(result_set, universumSet));
    ordered_array_set_delete(&result_set);
    ordered_array_set_delete(&set);
    ordered_array_set_delete(&universumSet);
}

void test_ordered_array_set_complement_3() {
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {},
                                                                0);
    ordered_array_set universumSet =
            ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    ordered_array_set result_set = ordered_array_set_complement(set,
                                                                universumSet);
    assert(ordered_array_set_isSubset(result_set, universumSet));
    ordered_array_set_delete(&result_set);
    ordered_array_set_delete(&set);
    ordered_array_set_delete(&universumSet);
}

void test_ordered_array_set_complement() {
    test_ordered_array_set_complement_1();
    test_ordered_array_set_complement_2();
    test_ordered_array_set_complement_3();
}

// тест на симметрическую разность множеств
void test_ordered_array_set_symmetricDifference_1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1,
                                                                          3, 4, 5}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {2,
                                                                          3, 4, 6}, 4);
    ordered_array_set result_set =
            ordered_array_set_symmetricDifference(set1, set2);
    ordered_array_set check_set = ordered_array_set_create_from_array((int[])
                                                                              {1, 2, 5, 6}, 4);
    assert(ordered_array_set_isEqual(result_set, check_set));
    ordered_array_set_delete(&result_set);
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
    ordered_array_set_delete(&check_set);
}

void test_ordered_array_set_symmetricDifference_2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1,
                                                                          3, 4, 5}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {2,
                                                                          6, 9, 10}, 4);
    ordered_array_set result_set =
            ordered_array_set_symmetricDifference(set1, set2);
    ordered_array_set check_set = ordered_array_set_create_from_array((int[])
                                                                              {1, 2, 3, 4, 5, 6, 9, 10}, 8);
    assert(ordered_array_set_isEqual(result_set, check_set));
    ordered_array_set_delete(&result_set);
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
    ordered_array_set_delete(&check_set);
}

void test_ordered_array_set_symmetricDifference_3() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1,
                                                                          3, 4, 5}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1,
                                                                          3, 4, 5}, 4);
    ordered_array_set result_set =
            ordered_array_set_symmetricDifference(set1, set2);
    ordered_array_set check_set = ordered_array_set_create_from_array((int[])
                                                                              {}, 0);
    assert(ordered_array_set_isEqual(result_set, check_set));
    ordered_array_set_delete(&result_set);
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
    ordered_array_set_delete(&check_set);
}

void test_ordered_array_set_symmetricDifference() {
    test_ordered_array_set_symmetricDifference_1();
    test_ordered_array_set_symmetricDifference_2();
    test_ordered_array_set_symmetricDifference_3();
}

void test_ordered_array_set() {
    test_ordered_array_set_in();
    test_ordered_array_set_isSubset();
    test_ordered_array_set_isEqual();
    test_ordered_array_set_isAbleAppend();
    test_ordered_array_set_insert();
    test_ordered_array_set_deleteElement();
    test_ordered_array_set_union();
    test_ordered_array_set_intersection();
    test_ordered_array_set_difference();
    test_ordered_array_set_complement();
    test_ordered_array_set_symmetricDifference();
}

void test() {
    test_bitset();
    test_unordered_array_set();
    test_ordered_array_set();
}

int main() {
    test();
    vector v = createVector(SIZE_MAX);
    return 0;
}