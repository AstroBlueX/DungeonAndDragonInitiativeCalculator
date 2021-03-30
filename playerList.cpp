//
// Created by pokeg on 3/28/2021.
//

#include "playerList.h"

playerList::playerList() {
    head = nullptr;
}


bool playerList::isEmpty() {
    if(head == nullptr)
        return true;
    else{
        return false;
    }
}

void playerList::printList() {
    listNode* search = head;
    cout << "=========================" << endl;
    while (search != nullptr){
        cout << search->name << " " << search->initiative << "   " << search->mod << endl;
        search = search->next;
    }
    cout << "=========================" << endl;
}

void playerList::genInt(){
    srand(time(NULL));
    listNode* search = head;
    while(search != nullptr){
        int randNum = rand() % 20 + 1;
        search->initiative =  randNum + search->mod;
        search = search->next;
    }
}

void playerList::push(const string& name, int score) {
    if(search(name)){
        return;
    }else{
        auto* newNode = new listNode;
        newNode->name = name;
        newNode->mod = score;
        if(head == nullptr){
            head = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }
}

bool playerList::search(const string& name){
    if(head != nullptr){
    }
    listNode* search = head;
    while(search != nullptr){
        if(search->name == name){
            return true;
        }
        search = search->next;
    }
    return false;
}

void playerList::pop() {
    listNode* temp = head->next;
    delete head;
    head = head->next;
}

void playerList::emptyList() {
    while(head != nullptr){
        pop();
    }
}

listNode* playerList::swap(listNode* ptr1, listNode* ptr2) {
    listNode* tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}

void playerList::sort(){
    listNode** h;
    int count = 0;
    listNode* search = head;
    int i, j, swapped;
    while(search != nullptr){
        count++;
        search = search->next;
    }

    for (i = 0; i <= count; i++)
    {

        h = &head;
        swapped = 0;

        for (j = 0; j < count - i - 1; j++)
        {

            listNode* p1 = *h;
            listNode* p2 = p1->next;

            if (p1->initiative < p2->initiative)
            {

                /* update the link after swapping */
                *h = swap(p1, p2);
                swapped = 1;
            }

            h = &(*h)->next;
        }

        /* break if the loop ended without any swap */
        if (swapped == 0)
            break;
    }
}

void playerList::remove(const string& name) {
    if(isEmpty()){
        cout << "Error: Cannot remove character, list is empty" << endl;
        return;
    }
    if(!search(name)){
        cout << "Error: Cannot remove character, does not exist" << endl;
        return;
    }
    if(name == head->name){
        head = NULL;
        return;
    }
    listNode* prev = nullptr;
    listNode* search = head;
    listNode* temp = nullptr;
    while (search->name != name){
        prev = search;
        search = search->next;
    }
    if(search == head){
        temp = head;
        delete head;
        head = temp->next;
        delete temp;
    }else{
        prev->next = search->next;
        delete search;
    }
}

