#include <bits/stdc++.h>
#include "SinglyLinkedListNode.h"

using namespace std;

class LinkedList{
private:
    SinglyLinkedListNode* head;

public:

    //default constructor for initiation
    LinkedList(){
        head = nullptr;
    }

    //constructor for initiating with head value
    LinkedList(int headData){
        head->data = headData;
        head->next = nullptr;
    }

    //get the head of the linked list
    SinglyLinkedListNode* getHead(){
        return head;
    }

    //print the linked list
    void printLinkedList(){
        SinglyLinkedListNode* temp = head;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    //get the length of the linked list
    int getLength(){
        SinglyLinkedListNode* temp = head;
        int length = 0;
        while(temp != nullptr){
            length++;
            temp = temp->next;
        }
        return length;
    }

    //insert a new node at the beginning of the linked list
    void insertAtBeginning(int data){
        SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
        newNode->next = head;
        head = newNode;
    }

    //insert a new node at the end of the linked list
    void insertAtEnd(int data){
        SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
        if(head == nullptr){
            head = newNode;
            return;
        }
        SinglyLinkedListNode* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    //insert a new node at a specific position of the linked list
    void insertAtPosition(int position, int data){
        if(position < 1 || position > getLength()+1){
            cout << "Invalid position" << endl;
            return;
        }
        if(position == 1){
            insertAtBeginning(data);
            return;
        }
        if(position == getLength()+1){
            insertAtEnd(data);
            return;
        }
        SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
        SinglyLinkedListNode* temp = head;
        for(int i = 1; i < position-1; i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    //delete the first node of the linked list
    void deleteFirstNode(){
        if(head == nullptr){
            cout << "Linked list is empty" << endl;
            return;
        }
        SinglyLinkedListNode* temp = head;
        head = head->next;
        delete temp;
    }

    //delete the last node of the linked list
    void deleteLastNode(){
        if(head == nullptr){
            cout << "Linked list is empty" << endl;
            return;
        }
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        SinglyLinkedListNode* temp = head;
        while(temp->next->next != nullptr){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    //delete a node at a specific position of the linked list
    void deleteAtPosition(int position){
        if(position < 1 || position > getLength()){
            cout << "Invalid position" << endl;
            return;
        }
        if(position == 1){
            deleteFirstNode();
            return;
        }
        if(position == getLength()){
            deleteLastNode();
            return;
        }
        SinglyLinkedListNode* temp = head;
        for(int i = 1; i < position-1; i++){
            temp = temp->next;
        }
        SinglyLinkedListNode* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    //get the position of a specific node with given data in the linked list
    int getPosition(int data){
        SinglyLinkedListNode* temp = head;
        int position = 1;
        while(temp != nullptr){
            if(temp->data == data){
                return position;
            }
            temp = temp->next;
            position++;
        }
        return -1;
    }

    //get the middle node of the linked list
    int getMiddleNode(){
        SinglyLinkedListNode* slow = head;
        SinglyLinkedListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }

    //reverse the linked list
    void reverseLinkedList(){
        SinglyLinkedListNode* prev = nullptr;
        SinglyLinkedListNode* current = head;
        SinglyLinkedListNode* next = nullptr;
        while(current != nullptr){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};

int main(){
    return 0;
}