#include <iostream>
using namespace std;
#include "cmpslib19.h"
#include "easylogging++.h"
INITIALIZE_EASYLOGGINGPP


#define ELEMTYPE int
#define QUEUESIZE 4
#include "Queue.h"

int main()
{
  // set up the logger
  InitializeLogger("main1.log");

  cout << "test to see if you can retrieve a value from an empty queue, hopefully not \n";

	Queue Queue1; // should be empty


	try
	{
		// test that peekFront will throw an exception
		Queue1.peekFront();
		cout << "Fail:"<<endl;

	}
	catch (const char * val)
	{
		cout <<"Pass:"<<endl;
		cout <<"Exception:" << val << endl;
	}
	return 0;
}


