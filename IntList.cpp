#include "IntList.h"

// Initializes an empty list with dummy head and dummy tail.
IntList::IntList(){
    dummyHead = new IntNode(0);
    dummyTail = new IntNode(0);

    dummyHead->next = dummyTail;
    dummyTail->prev = dummyHead;
    }

//Inserts a data value at front of list.  This must be an O(1) operation
void IntList::push_front(int value){
    IntNode* curr = new IntNode(value);
    IntNode* temp = dummyHead->next;

    curr->prev = dummyHead;
    curr->next = temp;
    temp->prev = curr;
    dummyHead->next = curr;
}

//Removes the node at the front end of the list. This must be an O(1) operation
void IntList::pop_front(){
    IntNode* remove = dummyHead->next;
    if (remove != dummyTail){  
        IntNode* temp = remove->next;

        remove->prev = 0;
        remove->next = 0;
        delete remove;

        dummyHead->next = temp;
        temp->prev = dummyHead;
    }
}

//nserts a data value at the back end of the list. This must be an O(1) operation.
void IntList::push_back(int value){
    IntNode* curr = new IntNode(value);   
    IntNode* temp = dummyTail->prev;

    curr->prev = temp;
    curr->next = dummyTail;
    dummyTail->prev = curr;
    temp->next = curr; 
}

//Removes the node at the back end of the list. This must be an O(1) operation
void IntList::pop_back(){
    IntNode* remove = dummyTail->prev;
    if (remove != dummyHead){
        IntNode* temp = remove->prev;

        remove->prev = 0;
        remove->next = 0;
        delete remove;

        dummyTail->prev = temp;
        temp->next = dummyTail;
    }
}

//Returns true if the list does not store any data values, otherwise returns false.
bool IntList::empty(){
    if(dummyHead->next == dummyTail){
        return true;
    }
    return false;   
}

/*A global friend function that outputs to the stream all of the integer values within the list on a single line, each separated by a space. 
This function does NOT send to the stream a newline or space at the end. */
ostream & operator<<(ostream &out, const IntList &rhs){

    IntNode* curr = rhs.dummyHead->next;

    while(curr != rhs.dummyTail){
        if (curr->next != rhs.dummyTail){
            out << curr->data << " ";      
        }else{
            out << curr->data;             
        }
        curr = curr->next;
    }
    return out;
}

/*prints to a single line all of the int values stored in the list in REVERSE order, each separated by a space. 
This function does NOT output a newline or space at the end. */
void IntList::printReverse(){
    IntNode* curr = dummyTail->prev;
    
    while(curr != dummyHead){
        if (curr->prev != dummyHead){
            cout << curr->data << " ";
        }else{
            cout << curr->data;
        }
        curr = curr->prev;
    }
}

//Deallocates all remaining dynamically allocated memory (all remaining IntNodes).
IntList::~IntList(){
    IntNode* curr = dummyHead->next;
    IntNode* temp = curr->next;
    while(curr != dummyTail){
        curr->prev = 0;
        curr->next = 0; 

        dummyHead->next = temp;
        temp->prev = dummyHead;
        delete curr;

        curr = temp;
        temp = curr->next;
    }
    delete dummyHead;
    delete dummyTail;
}
    
