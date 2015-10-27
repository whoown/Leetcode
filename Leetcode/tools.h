//
//  tools.h
//  Leetcode
//
//  Created by yan zhang on 15/4/8.
//  Copyright (c) 2015年 yan zhang. All rights reserved.
//

#ifndef __Leetcode__tools__
#define __Leetcode__tools__

#include <stdio.h>
#include "stdlib.h"
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>

std::string random_string(int len, int type);
std::string random_string(int len, std::string alpha);

void quick_sort(std::vector<int>& nums, int begin_index, int end_index);
void qsort(std::vector<int>& nums, int begin_index, int end_index);



#define MAX_INT 2147483647
#define MIN_INT -2147483648


#endif /* defined(__Leetcode__tools__) */

