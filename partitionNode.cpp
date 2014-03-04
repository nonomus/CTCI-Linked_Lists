#include <iostream>
#include <list>

using namespace std;
//Basic function that prints out a spaced out list. Requires list
//elements to be printable.
template<typename T>
void printList(list<T> *listIn){
	for(typename list<T>::iterator i = listIn->begin(); i != listIn->end(); i++){
		cout << *i << " ";
	}
	cout << endl;
}

//Write code to partition a linked list around a value x, such that all nodes less than x
//come before all nodes greater than or equal to x
template<typename T>
list<T> partitionNode(const list<T> &listIn, T value){
	list<T> left;
	list<T> middle;
	list<T> right;
	for(typename list<T>::const_iterator i = listIn.begin();
		i != listIn.end(); ++i){
		if(*i < value){
			left.push_back(*i);
		} else if(*i > value){
			right.push_back(*i);
		} else middle.push_back(*i);
	}
	left.splice(left.end(), middle);
	left.splice(left.end(), right);
	return left;
}

int main(){
	list<int> testList;
	cout << "partitionNode test cases: " << endl;
	testList = partitionNode(testList, 5);
	printList(&testList);
	testList.push_back(5);
	testList = partitionNode(testList, 5);
	printList(&testList);
	testList.push_back(6);
	testList.push_back(7);
	testList.push_back(3);
	testList.push_back(2);
	testList = partitionNode(testList, 5);
	printList(&testList);
	return 0;
}