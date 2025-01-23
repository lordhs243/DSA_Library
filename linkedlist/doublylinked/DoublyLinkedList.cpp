#include <bits/stdc++.h>
#include "DoublyLinkedListNode.h"

using namespace std;

class DoublyLinkedList{
private:
    DoublyLinkedListNode* head;

public:
    //default constructor for initiation
    DoublyLinkedList(){
        head = nullptr;
    }

    //constructor for initiating with head value
    DoublyLinkedList(int headData){
        head->data = headData;
        head->next = nullptr;
        head->prev = nullptr;
    }

    //get the head of the linked list
    DoublyLinkedListNode* getHead(){
        return head;
    }

    //print the linked list
    void printLinkedList(){
        DoublyLinkedListNode* temp = head;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    //get the length of the linked list
    int getLength(){
        DoublyLinkedListNode* temp = head;
        int length = 0;
        while(temp != nullptr){
            length++;
            temp = temp->next;
        }
        return length;
    }

    //insert a new node at the beginning of the linked list
    void insertAtBeginning(int data){
        DoublyLinkedListNode* newNode = new DoublyLinkedListNode(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    //insert a new node at the end of the linked list
    void insertAtEnd(int data){
        DoublyLinkedListNode* newNode = new DoublyLinkedListNode(data);
        if(head == nullptr){
            head = newNode;
            return;
        }
        DoublyLinkedListNode* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
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
        DoublyLinkedListNode* newNode = new DoublyLinkedListNode(data);
        DoublyLinkedListNode* temp = head;
        for(int i = 1; i < position-1; i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }

    //delete the first node of the linked list
    void deleteFirstNode(){
        if(head == nullptr){
            cout << "Linked list is empty" << endl;
            return;
        }
        DoublyLinkedListNode* temp = head;
        head = head->next;
        head->prev = nullptr;
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
        DoublyLinkedListNode* temp = head;
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
        DoublyLinkedListNode* temp = head;
        for(int i = 1; i < position-1; i++){
            temp = temp->next;
        }
        DoublyLinkedListNode* toDelete = temp->next;
        temp->next = temp->next->next;
        temp->next->prev = temp;
        delete toDelete;
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
        DoublyLinkedListNode* temp = head;
        for(int i = 1; i < position-1; i++){
            temp = temp->next;
        }
        DoublyLinkedListNode* toDelete = temp->next;
        temp->next = temp->next->next;
        temp->next->prev = temp;
        delete toDelete;
    }

    //get the position of a specific node with given data in the linked list
    int getPosition(int data){
        DoublyLinkedListNode* temp = head;
        int position = 1;
        while(temp!=nullptr){
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
        DoublyLinkedListNode* slow = head;
        DoublyLinkedListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }

    //reverse the linked list
    void reverseLinkedList(){
        DoublyLinkedListNode* temp = nullptr;
        DoublyLinkedListNode* current = head;
        while(current != nullptr){
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if(temp != nullptr){
            head = temp->prev;
        }
    }
};

int main(){
    return 0;
}