/*********************************************************************
** Program name: Doubly-linked List 
** Author: Ryan DiRezze
** Date: November 4, 2018
** Description: 
*********************************************************************/

#include "doubleLinkedList_v2.hpp"

void LinkedList::addToHead(int x) {
   if(head == nullptr) {
      head = new Node(x);
   }
   else {
      Node* nodePtr = head;
      while(nodePtr->next != nullptr) {
         nodePtr = nodePtr->next;
      }
      nodePtr->next = new Node(x);
   }
}

void LinkedList::print() {
   Node* nodePtr = head;
   while(nodePtr) {
      cout << "nodePtr->val = " << nodePtr->val << endl;
      nodePtr = nodePtr->next;
   }
}

