//
//  main.cpp
//  281pj1
//
//  Created by ZhengHao on 8/25/15.
//  Copyright (c) 2015 ZhengHao. All rights reserved.
//

#include <getopt.h>
#include "Header.h"


struct option longOpts[] = {
    {"optionA", no_argument, NULL, 'a'},
    {"optionB", required_argument, NULL, 'b'}
};


//convert the file to a map/grid.
vector<string> inputFile() {
    vector<string> myMap;
    string line;
    while(getline(cin, line)) {
        if(line == "") break;
        if(line[0] == '/') continue;
        myMap.push_back(line);
    }
 //print myMap
/*
    for(int i = 0; i < myMap.size(); ++i) {
        cout << myMap[i] << endl;
    }
*/
    return myMap;
}

vector<int> findStart(vector<string>& myMap, int n) {
    //find the start position
    vector<int> start;
    for(int i = 3; i < (int)myMap.size(); ++i) {
        for(int j = 0; j < n; ++j) {
            if(myMap[i][j] == 'S') {
                start = {(i - 3) / n, (i - 3) % n, j};
                return start;
            }
        }
    }
    return start; // need to be upgraded;
}

void findMapWay(vector<string>& myMap, bool choose) {
//mapWay is to restore the result of the finded way, also the vector we need print
    int n = stoi(myMap[1]);
    int roomNum = stoi(myMap[2]);
    vector<int> startPos = findStart(myMap, n);
    //cout << startPos[0] << " " << startPos[1] << " " << startPos[2]<< endl;
    int current_room = startPos[0];
    int current_i = startPos[1];
    int current_j = startPos[2];
    vector<int> sP ={current_i, current_j, current_room};
    if(!choose)
    queueSearch(myMap, current_room, current_i, current_j, n, roomNum, sP);
    else
    stackSearch(myMap, current_room, current_i, current_j, n, roomNum, sP);
    
}


int main(int argc, char **argv){
    bool choose = false;
    /*
     this program takes in two arguments
     --optionA or -a does not have a required option
     --optionB or -b DOES have a required option.
     */
    struct option longOpts[] = {
        {"stack", no_argument, NULL, 's'},
        {"queue", no_argument, NULL, 'q'}
    };
    
    int opt = 0, index = 0;
    while((opt = getopt_long (argc, argv, "sq", longOpts, &index)) != -1){
        switch(opt) {
            case 's':
                choose = true;
                break;
            case 'q':
                choose = false;
                //optarg is defined in getopt.h
                break;
            case '?':
                cout << "I didn't recognize one of your flags\n";
                break;
        }
    }
    vector<string> myMap = inputFile();
    vector<string> mapWay;
    findMapWay(myMap, choose);
    std::cout << "Hello, World!\n";
    return 0;
}

/*
int main(int argc, const char ** argv) {
    struct option longOpts[] = {
        {"optionA", no_argument, NULL, 'a'},
        {"optionB", required_argument, NULL, 'b'}
    };
    
    int opt = 0, index = 0;
    while((opt = getopt_long(argc, argv, "ab:", longOpts, &index)) != -1){
        switch(opt) {
            case 'a':
                cout << "you have triggered option A\n";
                break;
            case 'b':
                cout << "you have triggered option B with option " << optarg << "\n";
                //optarg is defined in getopt.h
                break;
            case '?':
                cout << "I didn't recognize one of your flags\n";
                break;
        }
    }
    
    // insert code here...
    vector<string> myMap = inputFile();
    vector<string> mapWay;
    findMapWay(myMap, mapWay);
    std::cout << "Hello, World!\n";
    //cout mapWay;
    
}
*/
