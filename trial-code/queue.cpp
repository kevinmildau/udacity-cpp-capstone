// CPP program to illustrate
// Implementation of push() function
#include <iostream>
#include <queue>
using namespace std;

int main(){
	// Empty Queue
	queue<int> myqueue;
	for (int i; i < 4; i++){
	  myqueue.push(i);
	  cout << "int i = " << i << " added to queue\n";
	}

	// Printing content of queue
	while (!myqueue.empty()) {
		cout << "Popping value: " << myqueue.front() << " from queue\n"; // <- does lookup of last added element
		myqueue.pop(); // <-- does the pop
	}
}
