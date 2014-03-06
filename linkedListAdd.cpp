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

//You have two numbers represented by a linked list, where each node contains a
//single digit. The digits are stored in reverse order, such that the 1 's digit is at the head
//of the list. Write a function that adds the two numbers and returns the sum as a
//linked list.
list<int> linkedListAdd(list<int> list1, list<int> list2){
	list<int>::iterator iter1 = list1.begin(),
	                    iter2 = list2.begin();
	list<int> retList;	//return list.
	int rem = 0;
	//While either list still has items or remainder is nonzero
	while(iter1 != list1.end() || iter2 != list2.end() || rem){
		//If iter1 is not at the end of list1, use iter1's value,
		//otherwise use 0.
		int topNum = (iter1 != list1.end())? *iter1:0;
		//Same logic for iter2.
		int botNum = (iter2 != list2.end())? *iter2:0;
		int fValue = topNum + botNum + rem;
		//Remainder is = iteger division of fValue by max value of 10.
		rem = fValue/10;
		//Final value is anything that is in the 1's place.
		fValue = fValue % 10;

		retList.push_back(fValue);

		if(iter1 != list1.end()) ++iter1;
		if(iter2 != list2.end()) ++iter2;
	}

	retList.reverse();
	return retList;
}

int main(){
	list<int> top;
	top.push_back(2);
	top.push_back(8);
	top.push_back(9);
	top.push_back(6);
	top.push_back(2);
	list<int> bot;
	bot.push_back(8);
	bot.push_back(9);
	bot.push_back(5);
	list<int> result = linkedListAdd(top, bot);
	printList(&result);
	return 0;
}
