//
// Created by pokeg on 3/28/2021.
//
#include <iostream>
#ifndef UNTITLED1_PLAYERLIST_H
#define UNTITLED1_PLAYERLIST_H

using namespace std;

struct listNode{
    int score;
    string name;
    listNode* next;
};

class playerList {

    public:
    playerList();
    bool isEmpty();
    void push();
};


#endif //UNTITLED1_PLAYERLIST_H
