#include <iostream>
#include <list>

using namespace std;

template<typename T>
void printList(list<T> *listIn){
	for(typename list<T>::iterator i = listIn->begin(); i != listIn->end(); i++){
		cout << *i << " ";
	}
	cout << endl;
}

//Implement an algorithm to remove a node from a singly linked list
//given access only to that node.
template<typename T>
void removeNode(list<T> listIn, typename list<T>::iterator i){
	typename list<T>::iterator j = i;
	advance(j, 1);
	*i = *j;
	listIn.erase(i);
}

int main(){
	list<int> testList;
	cout << "removeNode test: " << endl;
	testList.push_back(1);
	testList.push_back(2);
	testList.push_back(3);
	testList.push_back(4);
	testList.push_back(5);
	list<int>::iterator i = testList.begin();
	removeNode(testList, i);
	printList(&testList);
	i = testList.begin();
	advance(i, 2);
	removeNode(testList, i);
	printList(&testList);
	return 0;
}