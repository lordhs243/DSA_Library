#include <bits/stdc++.h>
#include "../singlylinked/SinglyLinkedListNode.h"
#include "../doublylinked/DoublyLinkedListNode.h"

using namespace std;

//Floyd's cycle detection algorithm for singly linked list
bool detectCycleInSinglyLinkedList(SinglyLinkedListNode* head){
    SinglyLinkedListNode* slow = head;
    SinglyLinkedListNode* fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true;
        }
    }

    return false;
}

//Floyd's cycle detection algorithm for doubly linked list
bool detectCycleInDoublyLinkedList(DoublyLinkedListNode* head){
    DoublyLinkedListNode* slow = head;
    DoublyLinkedListNode* fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true;
        }
    }

    return false;
}

int main(){
    return 0;
}


