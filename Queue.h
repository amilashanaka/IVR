

#include <stdlib.h>

struct QueueNode
{
	int value;
	QueueNode * next;
	int priority;
};


class CallQueue
{
private:
	QueueNode * head;
	QueueNode * tail;
	
	
public:
	CallQueue()
	{
		head = NULL;
		tail = NULL;
		
	};
	
	bool empty(); 
	int size();
	int top();
	void push(int val,int pri);
	void push(int val);
	int pop();
	void remove(int val);
	void remove(QueueNode * nodeptr);
	void pushToHead(int val);
	
	//functions for changing the position
	char * generateQueueXML();
	void changePosition(int value,int newPosition);
	void insertByIndex(int val,int index);

};

