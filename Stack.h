/*
This is a program that implements the stack abstract data type using an array.
*/


// Define a template class that contains an array of 100 element named "array"
// and an integer named "top".
template <class T,int STACK_SIZE=100>
class Stack
{
	T elements[STACK_SIZE];
	int top;
public:
	Stack();
	bool push(T x);
	bool pop(T &x);
	bool getTopItem(T &x) const;
	bool isFull();
	bool isEmpty() const;
	~Stack();
};

/////////////////////////////////////////////////////////////////////////////////////////////////
/*
Function: Stack()
The constructor of the Stack class.

*/

template <class T,int STACK_SIZE>
Stack<T,STACK_SIZE>::Stack()
{
	top = -1;
}

///////////////////////////////////////////////////////////////////////////////////////////////
/*
Function: isEmpty

Checks whether a stack is empty
*/
template <class T,int STACK_SIZE>
bool Stack<T,STACK_SIZE>:: isEmpty() const
{
	if (top == -1) return true;
	return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////
/*
Function: isFull
Checks whether a stack is full
*/
template <class T,int STACK_SIZE>
bool Stack<T,STACK_SIZE>::isFull()
{
	if (top == STACK_SIZE-1) return true;
	return false;
}
///////////////////////////////////////////////////////////////////////////////////////////////

//function push
/*
Function: push
Pushes an element onto a stack.

Parameters:
	x - The element to be pushed.

*/
template <class T,int STACK_SIZE>
bool Stack<T,STACK_SIZE>::push(T x)
{
	if (isFull()) return false; // check if the stack is full, then we can't push the element x

	top++;
	elements[top] = x;
	return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////

/*
Function: pop
Removes the top item of this stack. 

Returns:
	The popped element.
*/

template <class T,int STACK_SIZE>
bool Stack<T,STACK_SIZE>::pop(T &popedItem)
{
	if(!isEmpty())
	{
		popedItem = elements[top];
		top--;
		return true;
	}
	return false;
}


///////////////////////////////////////////////////////////////////////////////////////////////

/*
Function: getTopItem
get the top item of the stack without removing it from the stack

Returns:
	The top item of the stack.
*/

template <class T,int STACK_SIZE>
bool Stack<T,STACK_SIZE>::getTopItem(T &popedItem) const
{
	if(!isEmpty())
	{
		popedItem = elements[top];
		return true;
	}
	return false;
}



///////////////////////////////////////////////////////////////////////////////////////////////
template <class T,int STACK_SIZE>
Stack<T,STACK_SIZE>:: ~Stack()
{
}






