//
// Created by pokeg on 3/28/2021.
//
#include <iostream>
#include <time.h>
#include <stdio.h>
#ifndef UNTITLED1_PLAYERLIST_H
#define UNTITLED1_PLAYERLIST_H

using namespace std;

struct listNode{
    int mod;
    int initiative;
    string name;
    listNode* next;
};

class playerList {
private:
    listNode* head;
public:
    playerList();
    bool isEmpty();
    bool search(const string& name);
    void printList();
    void push(const string& name, int score);
    void pop();
    void remove(const string& name);
    void genInt();
    void emptyList();
    void sort();
    static listNode* swap(listNode* nodeA, listNode* nodeB);
};


#endif //UNTITLED1_PLAYERLIST_H
