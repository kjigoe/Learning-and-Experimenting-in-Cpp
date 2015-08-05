#include	<iostream>

using namespace std;

namespace myStackSpace {
	class List
	{
	public:
		List();
		List(const List& orig);
		virtual ~List();
		bool hasNext();
		List* getNext();
		void setNext(List* newNext);
		int getValue();
		void setValue(int val);
		int value;
		List* next;

	private:
		//List* next;
		//int value;
	};
}