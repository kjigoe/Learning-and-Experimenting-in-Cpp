
#include    "Stack.h"
#include	"List.h"


using namespace myStackSpace;

Stack::Stack()
{
	headPtr = new List;
	cout << "Stack::Stack( )\n";
}


Stack::~Stack()
{
	delete(headPtr);
	cout << "Stack::~Stack( )\n";
}


void Stack::push(int n)
{
	List temp_head = *headPtr;
	headPtr = new List;
	headPtr ->setNext() = &temp_head;
	headPtr ->setValue() = n;
}


void Stack::pop()
{
	if (top() == NULL){
		cerr << "\tpop( )   --stack is empty\n";
	}
	else {
		List* itemToRemove = headPtr->getNext();
		int topNodeValue = itemToRemove->getValue();
		headPtr->next = headPtr->getNext()->next;
		delete itemToRemove;
	}
}


int Stack::top()
{
	if (headPtr->getNext() == nullptr) {
		cout << "\nIllegal State Exception: You cannot get the top element of an empty stack." << endl;
		return 0;
	}
	else {
		return headPtr->next->value;
	}
}