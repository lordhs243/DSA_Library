#include <bits/stdc++.h>
#ifndef SINGLYLINKEDLISTNODE_H
#define SINGLYLINKEDLISTNODE_H

struct SinglyLinkedListNode
{
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int data){
        this->data = data;
        this->next = nullptr;
    }
};

#endif