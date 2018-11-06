/*********************************************************************
** Program name: Doubly-linked List 
** Author: Ryan DiRezze
** Date: November 4, 2018
** Description: 
*********************************************************************/

#include "doubleLinkedList.hpp"

// destructor of the LinkedList
LinkedList::~LinkedList() {
   Node* prev;
   Node* nodePtr;
   nodePtr = head;
   prev = nodePtr;
   while(nodePtr->getNext() != nullptr) {
      nodePtr = nodePtr->getNext();
      delete prev;
      prev = nodePtr;
   }
   delete nodePtr;
}

// returns the value (integer) of a node
int Node::getValue() {
   return val;
}

// returns the previous node object
Node* Node::getPrev() {
   return prev;
}

// sets the previous node object
void Node::setPrev(Node* prevNode) {
   prev = prevNode;
}

// returns the next node within the double linked list
Node* Node::getNext() {
   return next;
}

// updates the next node object
void Node::setNext(Node* nextNode) {
   next = nextNode;
}

// updates the value of the node node
void Node::setValue(int x) {
   val = x;
}

// adds an integer to the beginning of the double linked list of integers
void LinkedList::addToHead(int x) {
  // when the list is empty, add an integer to the beginning of the list
   if(head == nullptr & tail == nullptr) {
      Node* nodePtr = new Node(x);
      head = nodePtr;
      tail = nodePtr;
   }

   // when the list is not empty, add an integer to the beginning of the list
   else {
      Node* nodePtr = new Node(x);
      nodePtr->setNext(head);
      head->setPrev(nodePtr);
      head = nodePtr;

      // make sure tail is updated
      while(nodePtr->getNext() != nullptr) {
         nodePtr = nodePtr->getNext();
      }
      tail = nodePtr;
   }
}

// deletes the first node within the double linked list
void LinkedList::deleteHeadNode() {
   // if the list of empty: notify the user and don't delete anything
   if(head == nullptr && tail == nullptr) {
      cout << "The list is empty, and thus, there is no node (integer) to delete..." << endl;
   }
   
   // if the list is not empty: delete the list's first node & update the "head" node
   else {
      cout << "Deleting the first node (integer) in the list..." << endl;      
      Node* nodePtr = head;
      if(nodePtr->getNext() != nullptr) {
         head = head->getNext();
         head->setPrev(nullptr);
         delete nodePtr;
      }
      else {
         delete nodePtr;
         head = nullptr;
         tail = nullptr;
      }
   }
}

// adds a new node to the tail of the double linked list
void LinkedList::addToTail(int x) {
   // if the list of empty: notify the user and don't delete anything
   if(head == nullptr && tail == nullptr) {
      Node* nodePtr = new Node(x);
      head = nodePtr;
      tail = nodePtr;
   }
   
   // if the list is not empty: delete the list's last node & update the "tail" node
   else {
      Node* nodePtr = new Node(x);
      nodePtr->setPrev(tail);
      tail->setNext(nodePtr);
      tail = nodePtr;

      // make sure head is updated
      while(nodePtr->getPrev() != nullptr) {
         nodePtr = nodePtr->getPrev();
      }
      head = nodePtr;
   }
}

// deletes the last integer (node) from the list and updates the list's tail node
void LinkedList::deleteTailNode() {
   // if the list is empty, notify the user and don't update the list
   if(tail == nullptr && head == nullptr) {
      cout << "The list is empty, and thus, there is no node (integer) to delete..." << endl;
   }

   // if the list is not empty, delete the last node (integer) in the list at the tail
   else {
      cout << "Deleting the last node (integer) in the list..." << endl;
      Node* nodePtr = head;
      Node* prev;
      if(nodePtr->getNext() != nullptr) {
         while(nodePtr->getNext() != nullptr) {
            prev = nodePtr;
            nodePtr = nodePtr->getNext();
         }
         prev->setNext(nullptr);
         tail = prev;
         delete nodePtr;
      }
      else {
         delete nodePtr;
         tail = nullptr;
         head = nullptr;
      }
   }
}

// prints the double linked list of integers in reverse
void LinkedList::reversePrint() {
   if(head != nullptr || tail != nullptr) {
      Node* nodePtr = tail;
      cout << "LinkedList: ";
      
      // steps through the nodes (ints) in the linked list in reverse
      while(nodePtr) {
         cout << nodePtr->getValue() << " ";
         nodePtr = nodePtr->getPrev();
      }
   }

   // message when the list is empty
   else if(head == nullptr && tail == nullptr) {
      cout << "The list is empty..." << endl;
   }
}

// prints the double linked list of integers
void LinkedList::print() {
   if(head != nullptr || tail != nullptr) {
      Node* nodePtr = head;
      cout << "LinkedList: ";

      // steps through the linked list, beginning at the head, and prints all
      // integers values from each node within the list
      while(nodePtr) {
         cout << nodePtr->getValue() << " ";
         nodePtr = nodePtr->getNext();
      }
   }
   else if(head == nullptr && tail == nullptr) {
      cout << "The list is empty..." << endl;
   }
}

// prints the value at the head node
void LinkedList::printHeadNode() {
   if(head != nullptr) {
      cout << "Head node's value: " << head->getValue() << endl;
   }
   else {
      cout << "The list is empty, so there is no value for the head node..." << endl;
   }
}

// prints the value at the tail node
void LinkedList::printTailNode() {
   if(tail != nullptr) {
      cout << "Tail node's value: " << tail->getValue() << endl;
   }
   else {
      cout << "The list is empty, so there is no value for the tail node..." << endl;
   }
}
