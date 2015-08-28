//
//  queueSearch.cpp
//  281pj1
//
//  Created by ZhengHao on 8/27/15.
//  Copyright (c) 2015 ZhengHao. All rights reserved.
//

#include <stdio.h>
#include "Header.h"


void queueSearch(vector<string>& originalMap, int current_room, int current_i, int current_j, int n, int roomNum, vector<int> startPos){
    vector<string> myMap = originalMap;
    int count = 0;
    deque<vector<int>> myDeque;
    map<vector<int>, vector<int>> mMap;
    vector<int> a = {};
    vector<int> b = {};
    vector<int> finalPos = {};
    myDeque.push_back({current_i, current_j, current_room});// push_back the staPos
    
    while (!myDeque.empty()) {
        current_i = myDeque.front()[0];
        current_j = myDeque.front()[1];
        current_room = myDeque.front()[2];
        int cr = current_room;
        myDeque.pop_front();
        if(myMap[3 + current_room * n + current_i][current_j] == '#') continue;
        if(current_i - 1 >= 0){
            
            cr = current_room;
            count = 0;
            if(myMap[3 + current_room * n + current_i - 1][current_j] == '.'){
                myDeque.push_back({current_i - 1, current_j, current_room});
                myMap[3 + current_room * n + current_i - 1][current_j] = 'V';
                a = {current_i - 1, current_j, cr};
                b = {current_i, current_j, current_room};
                mMap[a]=b;
            }
            else if(isdigit(myMap[3 + current_room * n + current_i - 1][current_j])){
                while(isdigit(myMap[3 + cr * n + current_i - 1][current_j])){
                    cr=myMap[3 + cr * n + current_i - 1][current_j] - '0';
                    ++count;
                    if(count > 9) break;
                }
                myDeque.push_back({current_i - 1, current_j, cr});
                myMap[3 + current_room * n + current_i - 1][current_j] = 'V';
                if(myMap[3 + cr * n + current_i - 1][current_j] == '.')
                    myMap[3 + cr * n + current_i - 1][current_j] = 'V';
                a = {current_i - 1, current_j, cr};
                b = {current_i, current_j, current_room};
                mMap[a]=b;
            }
            else if(myMap[3 + current_room * n + current_i - 1][current_j] == 'R'){
                finalPos = {current_i - 1, current_j, current_room};
                mMap[finalPos] = {current_i, current_j, current_room};
                break;
            }
            
        }
        if(current_j + 1 <= n - 1){
            
            cr = current_room;
            count = 0;
            if(myMap[3 + current_room * n + current_i][current_j + 1] == '.'){
                myDeque.push_back({current_i, current_j + 1, current_room});
                myMap[3 + current_room * n + current_i][current_j + 1] = 'V';
                a = {current_i, current_j + 1, cr};
                b = {current_i, current_j, current_room};
                mMap[a]=b;
            }
            else if(isdigit(myMap[3 + current_room * n + current_i][current_j+1]))
            {
                while(isdigit(myMap[3 + cr * n + current_i][current_j+1])){
                    cr=myMap[3 + cr * n + current_i][current_j+1] - '0';
                    ++count;
                    if(count > 9) break;
                }
                myDeque.push_back({current_i, current_j+1, cr});
                myMap[3 + current_room * n + current_i][current_j+1] = 'V';
                if(myMap[3 + cr * n + current_i][current_j+1] == '.')
                    myMap[3 + cr * n + current_i][current_j+1] = 'V';
                a = {current_i, current_j + 1, cr};
                b = {current_i, current_j, current_room};
                mMap[a]=b;
            }
            else if(myMap[3 + current_room * n + current_i][current_j+1] == 'R'){
                finalPos = {current_i, current_j + 1, current_room};
                mMap[finalPos] = {current_i, current_j, current_room};
                break;
            }
            
        }
        if(current_i + 1 <= n - 1){
            
            cr = current_room;
            if(myMap[3 + current_room * n + current_i + 1][current_j] == '.'){
                myDeque.push_back({current_i + 1, current_j, current_room});
                myMap[3 + current_room * n + current_i + 1][current_j] = 'V';
                a = {current_i + 1, current_j, cr};
                b = {current_i, current_j, current_room};
                mMap[a]=b;
            }
            else if(isdigit(myMap[3 + current_room * n + current_i +1][current_j]))
            {
                while(isdigit(myMap[3 + cr * n + current_i +1][current_j])){
                    cr=myMap[3 + cr * n + current_i +1][current_j] - '0';
                    ++count;
                    if(count > 9) break;
                }
                myDeque.push_back({current_i + 1, current_j, cr});
                myMap[3 + current_room * n + current_i +1][current_j] = 'V';
                if(myMap[3 + cr * n + current_i +1][current_j] == '.')
                    myMap[3 + cr * n + current_i +1][current_j] = 'V';
                a = {current_i + 1, current_j, cr};
                b = {current_i, current_j, current_room};
                mMap[a]=b;
            }
            else if(myMap[3 + current_room * n + current_i +1][current_j] == 'R'){
                finalPos = {current_i + 1, current_j, current_room};
                mMap[finalPos] = {current_i, current_j, current_room};
                break;
            }
            
        }
        if(current_j - 1 >= 0){
            
            cr = current_room;
            if(myMap[3 + current_room * n + current_i][current_j - 1] == '.'){
                myDeque.push_back({current_i, current_j - 1, current_room});
                myMap[3 + current_room * n + current_i][current_j - 1] = 'V';
                a = {current_i, current_j - 1, cr};
                b = {current_i, current_j, current_room};
                mMap[a]=b;
            }
            else if(isdigit(myMap[3 + current_room * n + current_i][current_j-1]))
            {
                while(isdigit(myMap[3 + cr* n + current_i][current_j-1])){
                    cr=myMap[3 + cr * n + current_i][current_j - 1] - '0';
                    ++count;
                    if(count > 9) break;
                }
                myDeque.push_back({current_i, current_j - 1, cr});
                myMap[3 + current_room * n + current_i][current_j - 1] = 'V';
                if(myMap[3 + cr * n + current_i][current_j - 1] == '.')
                    myMap[3 + cr * n + current_i][current_j - 1] = 'V';
                a = {current_i, current_j - 1, cr};
                b = {current_i, current_j, current_room};
                mMap[a]=b;
            }
            else if(myMap[3 + current_room * n + current_i][current_j - 1] == 'R'){
                finalPos = {current_i, current_j - 1, current_room};
                mMap[finalPos] = {current_i, current_j, current_room};
                break;
            }
            
        }
    }
    //find the way from 'S' to 'R';
    if(finalPos.empty()) cout << "Not Found!" << endl;
    else {
        vector<int> now = finalPos;
        vector<int> from = {};
        while(now != startPos){
            from = mMap[now];
            if(from[2] != now[2])
                myMap[3 + from[2] * n + now[0]][now[1]] = 'p';
            if(from[0] - now[0] == 1)
                myMap[3 + from[2] * n + from[0]][from[1]] = 'n';
            else if(from[0] - now[0] == -1)
                myMap[3 + from[2] * n + from[0]][from[1]] = 's';
            else if(from[1] - now[1] == 1)
                myMap[3 + from[2] * n + from[0]][from[1]] = 'w';
            else if(from[1] - now[1] == -1)
                myMap[3 + from[2] * n + from[0]][from[1]] = 'e';
            
            now = from;
        }
    }
    //print the myMap;
    cout << n << endl;
    cout << roomNum << endl;
    cout << "//room 0" << endl;
    for(int i = 3; i < (int)myMap.size(); ++i){
        for(int j = 0; j < n; ++j){
            if(myMap[i][j] == '.' || myMap[i][j] == 'V' || myMap[i][j] == '#')
                cout << originalMap[i][j];
            else
                cout << myMap[i][j];
        }
        cout << endl;
        if((i - 3 + 1) % n == 0 && (i - 3 + 1) / n < roomNum)
            cout << "//room " << (i - 3 + 1) / n << endl;
    }
}


