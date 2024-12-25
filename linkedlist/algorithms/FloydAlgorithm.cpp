#include <bits/stdc++.h>
#include "../singlylinked/SinglyLinkedListNode.h"
#include "../doublylinked/DoublyLinkedListNode.h"

using namespace std;

/*
Floyd's cycle detection algorithm is used to detect a cycle in a linked list.
It is also known as the "Tortoise and the Hare" algorithm.
The algorithm uses two pointers, one moving at twice the speed of the other.
If there is a cycle in the linked list, the two pointers will meet at some point.
If there is no cycle, the faster pointer will reach the end of the linked list.

The algorithm has a time complexity of O(n) and a space complexity of O(1).
*/

/*
function - detectCycle() is being overloaded 
for singly linked list and doubly linked list
so as to make the function generalised for each
*/

//for singly linked list
bool detectCycle(SinglyLinkedListNode* head){
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

//for doubly linked list
bool detectCycle(DoublyLinkedListNode* head){
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


