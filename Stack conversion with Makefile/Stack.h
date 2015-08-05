
#include    <iostream>
#include	"List.h"

using namespace std;

namespace myStackSpace
{
	class Stack
	{
	public:
		Stack();
	   ~Stack();
		void push(int);
		void pop();
		int  top();
		bool full();
		bool empty();

	private:
		List* headPtr;
		int  maxLen;
		int  topSub;
	};

}
