/*********************************************************************
** Program name: Doubly-linked List 
** Author: Ryan DiRezze
** Date: November 4, 2018
** Description: 
*********************************************************************/

#include "menu.hpp"
#include "inputValidation.hpp"
#include "doubleLinkedList.hpp"

int main() {
   cout << endl;
   srand(time(0));
   // initialize the variable for determining which function will be 'called'
   char selection;

   LinkedList* list = new LinkedList();

      // only break the loop if the user opts to exit the program
   while(tolower(selection) != 'h') {
      // reset the value after each iteration through the loop
      selection = 'z';

      // start the menu of recursive functions
      GameMenu(selection);

      // add a new node to the head
      if(tolower(selection) == 'a') {
         cout << "Please enter a positive integer (to add to the head): ";
         int input;
         cin >> input;
         intValidation(input);
         list->addToHead(input);
         cout << endl;
         list->print();
      }

      // add a new node to the tail
      else if(tolower(selection) == 'b') {
         cout << "Please enter a positive integer (to add to the tail): ";
         int input;
         cin >> input;
         intValidation(input);
         list->addToTail(input);
         cout << endl;
         list->print();
      }

      // delete from head
      else if(tolower(selection) == 'c') {
         list->deleteHeadNode();
         cout << endl;
         list->print();
      }

      // delete from tail
      else if(tolower(selection) == 'd') {
         list->deleteTailNode();
         cout << endl;
         list->print();
      }

      // traverse the list reversely
      else if(tolower(selection) == 'e') {
         list->reversePrint();
      }

      // print the value at the head node
      else if(tolower(selection) == 'f') {
         list->printHeadNode();
      }

      // print the value at the tail node
      else if(tolower(selection) == 'g') {
         list->printTailNode();
      }

      // break the loop & end the program
      else if(tolower(selection) == 'h') {
         break;
      }

      cout << endl << endl;
      mainMenuReturn(selection);      
      cout << endl;
   }
   
   delete list;
   return 0;
}
