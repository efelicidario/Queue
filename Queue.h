#pragma once
#include "cmpslib19.h"
#include "easylogging++.h"


#ifndef QUEUESIZE
#define QUEUESIZE 10
#endif

#ifndef ELEMTYPE
#define ELEMTYPE int
#endif

class Queue
{
    private:
        ELEMTYPE data[QUEUESIZE];
        int backIndex;

    public:

        Queue();
        ~Queue();
        bool empty();
        bool full();
        int size();
        bool enQueue(ELEMTYPE elem);
        bool deQueue();
        ELEMTYPE peekFront();
        string ToString();// return a string representation of the data in the container..

        string MACRO_VALUES();// return a string representation of the MACRO values

};

// the size is the difference between the back and front

// for this particular queue impementation the front index is always 0

int Queue::size()
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning: " << backIndex << endl;
    return backIndex;
}



// Initialize the Queue

Queue::Queue( )
{
    // set the backIndex to 0
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    backIndex = 0;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
}


Queue::~Queue()
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
}


bool Queue::empty()
{
    // return a bool value indicating if the Queue is empty
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    bool result = false;
    if(backIndex == 0)
        result = true;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning: " << result << endl;
    return result;
}


// Check if the Queue is currently full

bool Queue::full()
{
    // return a bool value indicating if the Queue is full
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    bool result = false;
    if(backIndex == QUEUESIZE)
        result = true;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning: " << result << endl;
    return result;
}

// Add an element to the top of the Queue

bool Queue::enQueue(ELEMTYPE elem)
{
    // if the Queue is full return false
    // insert the value elem to the array at the position of backIndex
    // increment the backIndex 
    // return true
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Parameter: " << elem << endl;
    LOG(INFO) << "Testing to see if the queue is full" << endl;
    bool result;
    if(full())
        result = false;
    else
    {
    LOG(INFO) << "storing the value into index 0" << endl;
        data[backIndex] = elem;
    LOG(INFO) << "incrementing backIndex" << endl;
        backIndex++;
        result = true;
    }
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning: " << result << endl;
    return result;
}


// Remove the element at the front of the Queue

bool Queue::deQueue()
{
    // if the Queue is empty return false
    // shift all the elements in the array over one positon
    // replace  element 0 ( front ) with the one at index 1
    //  1 with 2 , 2 with 3, 3 with 4 and so on
    // decrement the backIndex
    // return true
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    bool result;
    if(empty())
        result = false;
    else
    {
        for(int loop=0;loop<backIndex-1;loop++)
        {
            LOG(INFO) << "copying value from index " << loop+1 << " to index " << loop << endl;
            data[loop] = data[loop+1];
        }
        LOG(INFO) << "decrementing backIndex" << endl;
        backIndex--;
    }
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning: " << result << endl;
    return result;
}




// Retrieve the value at the top of the Queue but do not delete it

ELEMTYPE Queue::peekFront()
{
    // if the queue is empty throw a the message "cannot peekFront() on and empty queue"
    // return the value at the top of the Queue
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    ELEMTYPE temp;
    if(empty())
        throw (" cannot peekFront() on and empty queue");
    else
        temp = data[0];
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning: " << temp << endl;
    return temp;
}


string Queue::ToString()
{
    // create a string reresentation of the Queue
    // add in the value from MACRO_VALUES()
    // show the backIndex, the values returnted by the functions size, empty, full
    // list the value of all the postitions of the array  ie
    // data[0]:addres 0x000048 value:duck
    // data[1]:addres 0x000052 value:chicken
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    //string val;
    ELEMTYPE val2;
    string val3;
    val3 += "\nELEMTYPE: " + GetClassName(val2) + "\n";
    val3 += "QUEUESIZE: " + NumberToString(QUEUESIZE) + "\n";
    val3 += "backIndex: " + NumberToString(backIndex) + "\n";
    val3 += "size(): " + NumberToString(size()) + "\n";
    val3 += "empty(): " + NumberToString(empty()) + "\n";;
    val3 += "full(): " + NumberToString(full()) + "\n";
    for(int loop=0;loop<backIndex;loop++)
    {
        val2 = data[loop];
        val3 += "data[" + NumberToString(loop) + "]: address: " + NumberToString(&data[loop]) + " value: " + NumberToString(val2) + "\n";
    }
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning: " << val3 << endl;
    return val3;
}


string Queue::MACRO_VALUES()
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    ostringstream oss;
    ELEMTYPE x;
    oss << "ELEMTYPE: " << GetClassName(x)  << endl 
        << "QUEUESIZE: "      << QUEUESIZE;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning: " << backIndex << endl;
    return oss.str();
}


