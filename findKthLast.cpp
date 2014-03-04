#include <iostream>
#include <list>

using namespace std;

//Implement an algorithm to find the kth to last element of a singly linked list.
//REQUIRES: k > 0, and is not bigger than the size of the list.
template<typename T>
T kthLastElement(list<T> listIn, int k){
	typename list<T>::iterator currElt = listIn.begin();
	typename list<T>::iterator advRun = listIn.begin();
	advance(advRun, k);
	while(advRun != listIn.end()){
		currElt++;
		advRun++;
	}
	return *currElt;
}

int main(){
	list<int> testList;
	cout << "findKthLast test: " << endl;
	testList.push_back(1);
	testList.push_back(2);
	testList.push_back(3);
	cout << kthLastElement(testList, 2) << endl;
	return 0;
}