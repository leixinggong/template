//
//  mysort.h
//  mysort
//
//  Created by 龚磊星 on 2019/5/1.
//  Copyright © 2019 龚磊星. All rights reserved.
//

#ifndef mysort_h
#define mysort_h

#include <stdio.h>

void bubbleSort(int * arr,int len);
void selectSort(int * arr,int len);
void insertSort(int * arr,int len);
void shellSort(int * arr,int len);
void quickSort(int * arr, int low, int height);

void mergeCenter(int * arr,int * arr2, int low, int height);
void mergeSort(int * arr,int * arr2,int start,int mid,int end);

#endif /* mysort_h */
