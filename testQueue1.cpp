// testQueue1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CallArray.h"


CallArray QueuePort[10];

int main(int argc, char* argv[])
{



//	QueuePort[0].push(10,0);

	QueuePort[0].printCallAray();

	int pp = QueuePort[0].top();

	printf("\n%d",pp);
	/*QueuePort[1].push(20,0);
	QueuePort[0].push(11,0);
	QueuePort[0].push(12,0);
	QueuePort[2].push(30,0);
	QueuePort[1].push(22,0);
	QueuePort[2].push(31,0);
	QueuePort[2].push(32,0);
	QueuePort[1].push(21,0);
	QueuePort[0].push(14,0);
	QueuePort[2].push(34,0);
	QueuePort[1].push(24,0);


	QueuePort[0].printCallAray();

	printf("\n");

	QueuePort[1].printCallAray();

	printf("\n");

	QueuePort[2].printCallAray();

	/*callArr.push(1,0);
	callArr.push(2,0);
	callArr.push(3,0);
	callArr.push(4,0);
	callArr.push(5,0);
	callArr.push(6,0);

	callArr.printCallAray();
	printf("\nPop\n");
	callArr.pop();
	callArr.printCallAray();
	printf("\nPush\n");
	callArr.push(8,0);
	callArr.push(9,0);

	callArr.printCallAray();
	printf("\nPop\n");
	callArr.pop();
	callArr.printCallAray();

	printf("\nRemove\n");
	callArr.remove(6);
	callArr.printCallAray();

	printf("\nRemove\n");
	callArr.remove(54);
	callArr.printCallAray();


	callArr.push(123,120);
	callArr.printCallAray();*/


	getchar();


	return 0;

}

