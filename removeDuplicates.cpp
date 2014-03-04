#include <iostream>
#include <list>
#include <vector>

using namespace std;

template<typename T>
void printList(list<T> *listIn){
	for(typename list<T>::iterator i = listIn->begin(); i != listIn->end(); i++){
		cout << *i << " ";
	}
	cout << endl;
}

//Returns true if an element is in vIn vector. False otherwise.
template<typename T> bool inVector(vector<T> vIn, T element){
	for(int i = 0; i < vIn.size(); i++){
		if(vIn[i] == element) return true;
	}
	return false;
}

//Write code to remove duplicates from an unsorted linked list.
template<typename T>
void removeDuplicates(list<T> *listIn){
	vector<T> elements(listIn->size());
	//Go through every element in the list and check whether it
	//is already in elements -- if it is, remove it from the list,
	//otherwise add the element to elements vector and continue.
	for(typename list<T>::iterator i = listIn->begin(); i != listIn->end(); i++){
		if(inVector(elements, *i)){ 
			listIn->erase(i);
			i--;
		}
		else elements.push_back(*i);
	}
}

//How would you solve this problem if a temporary buffer is not allowed?

int main(){
	cout << "removeDuplicates test cases:" << endl;
	list<int> testList;
	removeDuplicates(&testList);
	printList(&testList);
	testList.push_back(1);
	testList.push_back(2);
	testList.push_back(3);
	testList.push_back(4);
	testList.push_back(5);
	testList.push_back(6);
	testList.push_back(7);
	removeDuplicates(&testList);
	printList(&testList);
	testList.push_back(4);
	testList.push_back(5);
	testList.push_back(5);
	testList.push_back(5);
	testList.push_back(7);
	testList.push_back(9);
	removeDuplicates(&testList);
	printList(&testList);
	return 0;
}