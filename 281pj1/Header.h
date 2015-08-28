//
//  Header.h
//  281pj1
//
//  Created by ZhengHao on 8/27/15.
//  Copyright (c) 2015 ZhengHao. All rights reserved.
//

#ifndef _81pj1_Header_h
#define _81pj1_Header_h

#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <map>
#include <string>
using namespace std;

void stackSearch(vector<string>& originalMap, int current_room, int current_i, int current_j, int n, int roomNum, vector<int> startPos);
void queueSearch(vector<string>& originalMap, int current_room, int current_i, int current_j, int n, int roomNum, vector<int> startPos);

#endif
