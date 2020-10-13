#include "IntList.h"


// Initializes an empty list with dummy head and dummy tail.
IntList::IntList(){}

//Inserts a data value at front of list.  This must be an O(1) operation
void IntList::push_front(int value){}

//Removes the node at the front end of the list. This must be an O(1) operation
void IntList::pop_front(){}

//nserts a data value at the back end of the list. This must be an O(1) operation.
void IntList::push_back(int value){}

//Removes the node at the back end of the list. This must be an O(1) operation
void IntList::pop_back(){}

bool IntList::empty(){}

/*A global friend function that outputs to the stream all of the integer values within the list on a single line, each separated by a space. 
This function does NOT send to the stream a newline or space at the end. */
ostream & operator<<(ostream &out, const IntList &rhs);

/*prints to a single line all of the int values stored in the list in REVERSE order, each separated by a space. 
This function does NOT output a newline or space at the end. */
void IntList::printReverse(){}

//Deallocates all remaining dynamically allocated memory (all remaining IntNodes).
IntList::~IntList(){}
    
