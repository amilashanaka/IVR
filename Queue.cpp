//////////////////////////////////////////////////////////////////////////
// Queue.CPP
// Wasantha Gajanayaka
// DuoSoftware 
// 5/25/2008
////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Queue.h"
#include <string.h>
#include <stdio.h>

//check whether the queus is empty
bool CallQueue::empty()
{
	//if head = NULL then the queue is empty
	return (head==NULL);
};
 

//returns the size of the queue
int CallQueue::size()
{
	QueueNode * temp = head;

	int count=0;
	while (temp!=NULL)
	{
		count++;
		printf("Queue val : %d \n", temp->value);
		temp=temp->next;
	}
	return count;

};


//returns the value of top node of the queue
int CallQueue::top()
{
	if(head!=NULL)
	{
		return head->value;
	}
	else
		return -1;
};


//push a new node to the queue
void CallQueue::push(int val)
{
/*	QueueNode * temp = new QueueNode;
	temp->value = val;
	temp->next = NULL;
	if(tail==NULL)
	{
		head=temp; 
		tail=temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
*/
	push(val,0);
};

//push a new node to the queue according to the priority
void CallQueue::push(int val,int pri)
{
	//QueueNode * temp = new QueueNode;//create new node

	QueueNode * temp = (QueueNode*)calloc(sizeof(QueueNode),1);
	temp->value = val;//set value
	temp->next = NULL;//set next node
	temp->priority = pri;//set priority

	//if the queue is empty
	if(tail==NULL && head==NULL)
	{
		head=temp; 
		tail=temp;
		return;
	}

	//if the priority of new node is 0, the append at the end of queue
	if(pri==0)
	{
		tail->next = temp;
		tail = temp;
		return;
	}
	
	//new node has a prority. find the exact place and insert
	int count=0;
	QueueNode * tempNode = head;

	while(count<size())
	{
		//if the new node has the highesr priority among all add it to top
		if(head->priority<pri)
		{
			temp->next=head;
			head = temp;
			break;
		}
		
		//navigate trough all the nodes and find the exact place
		if(tempNode->next!=NULL)
		{
			if(tempNode->next->priority<pri)
			{
				temp->next = tempNode->next;
				tempNode->next = temp; 
				break;
			}

			QueueNode * tempNode2 = tempNode->next;
			tempNode = tempNode2;
			count++;

		}
		
		//has the lowest priority among all. add to the end of queue
		else
		{
			tempNode->next = temp;
			tail=temp;
			break;
		}				
	}
	
};


//pop the first element from the queue
int CallQueue::pop()
{
	//if head=NULL, the queue is empty.
	//otherwise pop the value
	if(head!=NULL)
	{
		//if the queue size =1, there is only one element. set the tail=NULL
		if(size()==1)
		{
			tail=NULL;
		}

		//get the value of head and delete the top element
		int val = head->value;
		QueueNode * temp = head;
		head=head->next;
		free(temp);
		//delete temp;
		
		return val;
	}
	else
	{
		return -1;
	}
};


//remove a specific element from the queue
void CallQueue::remove(int val)
{
	QueueNode * temp = head;
	QueueNode * temp2 = NULL;

	//if head=NULL, the queue is empty.
	//otherwise find the value and remove
	if(temp!=NULL)
	{

		//if the top element is to be removed
		if(temp->value==val)
		{
			//if there are only one element in the queue
			if(temp->next==NULL)
			{
					free(temp);
					head=NULL;
					tail= NULL;
					return;
			}
			else
			{
				head=temp->next;
				free(temp);
				return;
			}
		}


		//find the element to remove
		while (temp->next!=NULL)
		{
			if(temp->next->value==val)
			{
				temp2=temp->next;
				temp->next=temp->next->next;
				temp2->next= NULL;
				free(temp2);
				break;
			}
			temp=temp->next;
		}
	}
};


//push a new value to head of the queue
void CallQueue::pushToHead(int val)
{
	QueueNode * temp = new QueueNode;
	temp->value = val;
	temp->next = head;
	temp->priority=0;
	if(head==NULL)
	{
		head=temp; 
		tail=temp;
	}
	else
	{
		head = temp;
	}
};


//returns a comma seperated value collection of the queue
char* CallQueue::generateQueueXML()
{

	char temp_xml[2] ;
	char *xml = (char*)calloc(255,sizeof(char));
	QueueNode * temp=head;
	while(temp!=NULL)
	{
		if(temp==tail)
		{
			sprintf(temp_xml,"%d",temp->value);
		}
		else
		{
			sprintf(temp_xml,"%d,",temp->value);
		}
		xml = strcat(xml,temp_xml);
		temp = temp->next;
	}
	return xml;


};


//change the position of a specific element in the queue
void CallQueue::changePosition(int val,int newPosition)
{
	//first remove the value
	remove(val);
	//then add it as a new value
	insertByIndex(val,newPosition);
};

//insert an element to a specific position in the queue
void CallQueue::insertByIndex(int val,int index)
{
	//dont let change the first three elements
	if(index<4)
	{
		return;
	}

	int count=0;
	QueueNode * temp = head;
	QueueNode *newNode = new QueueNode;
	newNode->value= val;

	while(temp!=NULL)
	{
		/*
		if(index == 0)
		{
			newNode->next = temp;
			head = newNode;
			break;
		}*/

		if(count==index)
		{
			newNode->next = temp->next;
			temp->next = newNode;
			break;
		}
		count++;
		temp = temp->next;
	}
};