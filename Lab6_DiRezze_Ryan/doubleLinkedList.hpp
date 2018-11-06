/*********************************************************************
** Program name: Doubly-linked List 
** Author: Ryan DiRezze
** Date: November 4, 2018
** Description: 
*********************************************************************/

#ifndef NODE_H
#define NODE_H

#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include<string>
using std::string;

class Node {
 public:
   Node() {};
   Node(int x) {
      val = x;
      next = nullptr;
      prev = nullptr;
   };
   ~Node() {
//      if(next != nullptr) {
//         delete next;
//      }
//      if(prev != nullptr) {
//         delete prev;
//      }
   };
   int getValue();
   void setValue(int);
   Node* getNext();
   void setNext(Node*);
   Node* getPrev();
   void setPrev(Node*);
 private:
    Node* next;
    Node* prev;
    int val;
};

class LinkedList {
 public:
    LinkedList() {}
    ~LinkedList();
    void addToHead(int);
    void addToTail(int);
    void deleteHeadNode();
    void deleteTailNode();
    void reversePrint();
    void print();
    void printHeadNode();
    void printTailNode();
 private:
    Node* head = nullptr;
    Node* tail = nullptr;
    int count = 0;
//    std::vector<Node*> list;
};

#endif
