#include "List.h"

using namespace myStackSpace;

List::List() {
	next = nullptr;
}
List::List(const List& orig) {
	next = orig.next;
	value = orig.value;
}
bool List::hasNext(){
	if (next != nullptr){
		return true;
	}
	else{
		return false;
	}
}
List* List::getNext(){
	return next;
}
void List::setNext(List* newNext){
	if (newNext == nullptr){
		next = nullptr;
	}
	else {
		next = newNext->next;
	}
}
int List::getValue(){
	return value;
}
void List::setValue(int val){
	value = val;
}