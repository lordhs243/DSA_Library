#include <bits/stdc++.h>
#ifndef DOUBLYLINKEDLISTNODE_H
#define DOUBLYLINKEDLISTNODE_H

struct DoublyLinkedListNode
{
    int data;
    DoublyLinkedListNode* prev;
    DoublyLinkedListNode* next;

    DoublyLinkedListNode(int data){
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

#endif