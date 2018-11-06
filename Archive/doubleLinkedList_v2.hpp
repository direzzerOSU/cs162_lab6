/*********************************************************************
** Program name: Doubly-linked List 
** Author: Ryan DiRezze
** Date: November 4, 2018
** Description: 
*********************************************************************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include<string>
using std::string;

struct Node {
   Node(int x) {
      val = x;
   }
   Node* next = nullptr;
   Node* prev = nullptr;
   int val;
};

class LinkedList {
 public:
    LinkedList() {}
    ~LinkedList() {}
    void addToHead(int x);
    void print();
 protected:
    Node* head = nullptr;
    Node* tail = nullptr;
};
#endif
