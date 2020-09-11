#ifndef __SORTS_H
#define __SORTS_H
#include "list.h"
#include "list.cpp"

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "list.h"

using namespace std;

vector<long> InsertionSort(vector<long> nums);
vector<long> MergeSort(vector<long> nums);
vector<long> QuickSortArray(vector<long> nums);
vector<long> QuickSortList(vector<long> nums);
vector<long> HeapSort(vector<long> nums);
vector<long> QueenOfAllSorts(vector<long> nums);
ListItem<long> *Merge2(ListItem<long>*h1,ListItem<long>*h2);
void Merge1(ListItem<long>**head);
void QA1(long *arr,int a,int b);
long QA2(long *arr,int a,int b);
void QL1(ListItem<long>*head,ListItem<long>*tail);
ListItem<long>*QL2(ListItem<long>*head,ListItem<long>*tail);
#endif