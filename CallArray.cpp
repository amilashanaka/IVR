#include "stdafx.h"
#include "CallArray.h"




void CallArray::push(int val,int pri)
{
	if(pri==0)
	{
		call[index] = val;
		index++;
		return;
	}

	int count=index;
	while(count!=0)
	{
		call[count]=call[count-1];
		count--;
	}
	call[0]=val;
	index++;
};	

int CallArray::pop()
{
	if(index>0)
	{
		int count=0;
		int value=call[0];

		
		while(count!=index)
		{
			call[count] = call[count+1];
			count++;
		}

		call[index]=NULL;
		index--;

		return value;
	}

	return -1;
};

void CallArray::printCallAray()
{
	int count=0;
	while(count!=index)
	{
		printf("%d\n",call[count]);
		count++;
	}
};

void CallArray::remove(int val)
{
	int count=0;
	while(count!=index)
	{
		if(call[count]==val)
		{
			int cnt=count;
			while(cnt!=index)
			{
				call[cnt] = call[cnt+1];
				cnt++;
			}
			index--;
			return;
		}

		count++;
	}
};


int CallArray::top()
{
	if(index>0)
	{
		return call[0];
	}
	else
		return -1;
};

int CallArray::size()
{
	return index;
};

bool CallArray::empty()
{
	if(index>0)
		return true;
	else
		return false;
};

	
char * CallArray::generateQueueXML()
{
	return "Not implemented";
};
	
void CallArray::changePosition(int value,int newPosition)
{

};
	
void CallArray::insertByIndex(int val,int index)
{

};