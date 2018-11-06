/*********************************************************************
** Program name: Doubly-linked List 
** Author: Ryan DiRezze
** Date: November 4, 2018
** Description: 
*********************************************************************/

#include "menu.hpp"
#include "inputValidation.hpp"

// the main/primary menu that issues arrive at after starting the program;
// this menu allows the user to navigate to various areas of the program
// to perform different transactions and view different data.
void GameMenu(char& option1) {
   // introduction
   string program_name = "Doubly-linked List";
   cout << "Hello! Welcome to the " << program_name << "!" << endl << endl;

   while(tolower(option1) != 'a' && tolower(option1) != 'b' && tolower(option1) != 'c' && tolower(option1) != 'd' && tolower(option1) != 'e' && tolower(option1) != 'f' && tolower(option1) != 'g' && tolower(option1) != 'h') {
      // menu prompt
      cout << "Please select an option from the following choices:" << endl;
      cout << "Input the option's corresponding letter to make a selection..." << endl << endl;
      
      // menu choices
      cout << "    a. Add a new node to the head" << endl;
      cout << "    b. Add a new node to the tail" << endl;
      cout << "    c. Delete the first node in the list" << endl;
      cout << "    d. Delete the last node in the list" << endl;
      cout << "    e. Traverse the list reversely (tail to head)" << endl;
      cout << "    f. Print the head node's value" << endl;
      cout << "    g. Print the tail node's value" << endl;
      cout << "    h. Exit the program" << endl << endl;

      cout << "Selection: ";
      cin >> option1;
      charValidation(option1);

      if(tolower(option1) != 'a' && tolower(option1) != 'b' && tolower(option1) != 'c' && tolower(option1) != 'd' && tolower(option1) != 'e' && tolower(option1) != 'f' && tolower(option1) != 'g' && tolower(option1) != 'h') {
         cout << endl;
         while(tolower(option1) != 'a' && tolower(option1) != 'b' && tolower(option1) != 'c' && tolower(option1) != 'd' && tolower(option1) != 'e' && tolower(option1) != 'f' && tolower(option1) != 'g' && tolower(option1) != 'h') {
            cout << "Uh oh! It looks like you didn't input a valid menu option... Please try again." << endl << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            cout << "Selection: "; 
            cin >> option1;
            cout << endl;
         }
      }
      else {
         cout << endl;
      }
      if(tolower(option1) == 'f') {
         break;
      }
   }
}

// a small prompt that asks the user if he/she would like to return to the main
// menu; this was intended to appear after the user performs some transaction
void mainMenuReturn(char& option) {
   option = 'n';
   while(tolower(option) == 'n') {
      cout << "Do you want to return to the main menu? (Y/N): ";
      cin >> option;
      validYesNo(option);

      if(tolower(option) == 'y') {
         option = 'z';       // let the program escape the 'while loop' & return to the menu
      }
      
      else if(tolower(option) == 'n') {
         cout << "Do you want to exit the program? (Y/N): ";
         cin >> option;
         validYesNo(option);
         
         // escape the 'while loop' & quit the program
         if(tolower(option) == 'y') {
            option = 'h';
            cout << endl;     // add a line & space for aesthetics
         }
         
         // do nothing and let the program run back through the 'while loop'
         else if(tolower(option) == 'n') {
            //option = 'n'
         }
      }
   }
}
