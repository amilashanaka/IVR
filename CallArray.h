#include <stdlib.h>



class CallArray
{

private:
	int index;

	int call[60];
public:

	void push(int val,int pri);
	int pop();
	void remove(int val);
	void printCallAray();
	int top();
	int size();
	bool empty();
		
	//functions for changing the position
	char * generateQueueXML();
	void changePosition(int value,int newPosition);
	void insertByIndex(int val,int index);

};

