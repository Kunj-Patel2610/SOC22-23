#include <iostream>

// THIS STRUCTURE IS JUST A GUIDELINE
// FEEL FREE TO CHANGE WHATEVER YOU WANT

class LinearQueue{
private:
    int* q;
    int start;
    int end;
    int size;
    int MAX_SIZE;

public:

    // Default Constructor
    LinearQueue(){
        MAX_SIZE = 10;
        q = new int[MAX_SIZE];
        start = 0;
        end = 0;
        size = 0;
        
        // Dynamically allocate memory for queue using keyword "new"
        // Initialize start, end, size
        // set MAX_SIZE to whatever you want
    }

    // Additional Constructor
    LinearQueue(int MAX_SIZE){

        q = new int[MAX_SIZE];
        start = 0;
        end = 0;
        size = 0;
        
        // Dynamically allocate memory for queue using keyword "new"
        // Initialize start, end, size

        // setting MAX_SIZE according to the parameter
        this->MAX_SIZE = MAX_SIZE;
    }

    bool insert(int elem)
    {
        if (size >= this->MAX_SIZE)
        {
            return false;
        }
        else
        {
            q [end % this->MAX_SIZE] = elem;
            end++;
            size++;
        }

        // insert element at end of queue
        // check if queue is full already
        // if insertion is successfull return true
        // else return false
    }

    int remove(){
        if (size == 0)
        {
            return -1;
        }
        else
        {
            int elem = q[start % this->MAX_SIZE];
            start++;
            size--;
            return elem;
        }
        // remove element from the start of queue
        // return the removed element
        // do not forget to change values of start, end, size appropriately
        // if queue is empty return -1
    }

    int get_size(){
        return size;
        // return current size of queue
    }

    int get_max_size(){
        return MAX_SIZE;
        // return max size of queue
    }

};