#include <iostream>

// THIS STRUCTURE IS JUST A GUIDELINE
// FEEL FREE TO CHANGE WHATEVER YOU WANT

class Stack{
private:
    int* s;
    int top;
    int size;
    int MAX_SIZE;

public:

    // Default Constructor
    Stack(){
        s = new int[10];
        top = -1;
        size = 0;
        MAX_SIZE = 10;
        // Dynamically allocate memory for stack using keyword "new"
        // Initialize top, size
        // set MAX_SIZE to whatever you want
    }

    // Additional Constructor
    Stack(int MAX_SIZE){
        s = new int[MAX_SIZE];
        top = -1;
        size = 0;

        // Dynamically allocate memory for stack using keyword "new"
        // Initialize top, size

        // setting MAX_SIZE according to the parameter
        this->MAX_SIZE = MAX_SIZE;
    }

    bool push(int elem){

        if(top == MAX_SIZE - 1){
            return false;
        }
        else
        {
            s[++top] = elem;
            return true;
        }
        // insert element at top of stack
        // check if stack is full already
        // if insertion is successfull return true
        // else return false
    }

    int pop(){

        if(top == -1){
            return -1;
        }
        else
        {
            return s[top--];
        }
        // remove element from the top of stack
        // return the removed element
        // do not forget to change values of top, size appropriately
        // if stack is empty return -1
    }

    int get_size(){

        return top + 1;
        // return current size of stack
    }

    int get_max_size(){
        return MAX_SIZE;
        // return max size of stack
    }

};
