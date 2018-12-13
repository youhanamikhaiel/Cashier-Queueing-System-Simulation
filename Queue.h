/*This code is an updated version from "Data Abstraction & Problem Solving with C++,WALLS AND MIRRORS ,SIXTH EDITION"*/

/*
This is a program that implements the queue abstract data type using a linked list.
The queue is implemented as a chain of linked nodes that has two pointers, 
a frontPtr pointer for the front of the queue and a backPtr pointer for the back of the queue.
*/

/*

General Queue case:

                 frontPtr										backPtr
					\											   /		
					 \											  /		
					-------- 	--------	--------			--------
					|	|nxt -->|	|nxt -->|	|nxt -->........|	|nxt -->NULL
					--------	--------	--------			--------	
		
Empty Case:

                 frontptr	 backptr
						\	 /				
						 \	/				
					---- NULL ------


Single Node Case:
                 frontPtr	 backPtr
					\		/	
					 \	   /			
					-------- 	
					|	|nxt -->NULL
					--------	

*/

#include "Node.h"
#ifndef NULL
#define NULL 0
#endif 

template <typename T>
class Queue
{
private :
	int size;
	Node<T>* backPtr;
	Node<T>* frontPtr;
public :
	Queue();	
	bool isEmpty() const ;
	bool enqueue(const T& newEntry);
	bool dequeue(T& frntEntry);  
	bool peekFront(T& frntEntry)  const;
	int getSize();
	void printQ();
	//int sizeQueue() const;
	~Queue();
	T accessQu(int x);
};
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: Queue()
The constructor of the Queue class.

*/

template <typename T>
Queue<T>::Queue()
{
	backPtr=nullptr;
	frontPtr=nullptr;
	size = 0;
}
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: isEmpty
Sees whether this queue is empty.

Input: None.
Output: True if the queue is empty; otherwise false.
*/
template <typename T>
bool Queue<T>::isEmpty() const
{
	if(frontPtr==nullptr)
		return true;
	else
		return false;
}

/////////////////////////////////////////////////////////////////////////////////////////

/*Function:enqueue
Adds newEntry at the back of this queue.

Input: newEntry .
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool Queue<T>::enqueue( const T& newEntry)
{
	Node<T>* newNodePtr = new Node<T>(newEntry);
	// Insert the new node
	if (isEmpty())
		frontPtr = newNodePtr; // The queue is empty
	else
		backPtr->setNext(newNodePtr); // The queue was not empty
	backPtr = newNodePtr; // New node is at back
	size++;
	return true ;

} // end enqueue


/////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Function: dequeue
Removes the front of this queue. That is, removes the item that was added
earliest.

Input: None.
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool Queue<T>:: dequeue(T& frntEntry)  
{
	if(isEmpty())
		return false;

	Node<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();
	// Queue is not empty; remove front
	if (nodeToDeletePtr == backPtr)	 // Special case: one node in queue
		backPtr = nullptr ;	
		
	// Free memory reserved by the dequeued node
	delete nodeToDeletePtr;
	size--;
	
	return true;

}



/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: peekFront
Returns the front of this queue. The operation does not modify the queue.

Input: None.
Output: The front of the queue.
*/
template <typename T>
bool Queue<T>:: peekFront(T& frntEntry) const 
{
	if(isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}
///////////////////////////////////////////////////////////////////////////////////

template <typename T>
Queue<T>::~Queue()
{
}


template <typename T>
int Queue<T>::getSize()
{
	return size;
}

template <typename T>
void Queue<T>::printQ()
{
	Node<int> *P = frontPtr;
	if (size > 0)
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << " " << P->getItem();
			P = P->getNext();
		}
	}
}

template <typename T>
T Queue<T>::accessQu(int x)
{
	Node<T> *P = frontPtr;
	int c = 0;
	while (c != x - 1 && P->getItem() != NULL)
	{
		P = P->getNext();
		c++;
	}
	if (c == x - 1)
	{
		return P->getItem();
	}
	else
	{
		return -1;
	}
}

/*template <typename T>
int Queue<T>::sizeQueue() const
{
	Node<T> *R = frontPtr;
	int size = 0;

	if (R == backPtr)
	{
		return size;
	}
	else
	{
		while (R->getItem() != NULL)
		{
			size++;
			if (R == backPtr)
			{
				break;
			}
			R = R->getNext();
		}
		return size;
	}
}*/