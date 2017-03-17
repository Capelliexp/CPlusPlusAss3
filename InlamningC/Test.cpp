#include "Queue.h"
#include <exception>

/*int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Queue <int> Q(1);

	Q.enqueue(1);
	Q.enqueue(2);
	Q.enqueue(3);
	Q.enqueue(4);
	Q.enqueue(5);
	Q.enqueue(6);

	Q.PrintQueue();

	Q.dequeue();
	Q.dequeue();
	Q.dequeue();

	std::cout << std::endl;
	Q.PrintQueue();

	std::cout << std::endl;
	std::cout << Q.front() << std::endl;
	std::cout << Q.isEmpty() << std::endl;

	std::cout << std::endl;
	Q.PrintQueue();

	getchar();
	return 1;
}*/


// /*
int main() {	//the test
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	std::cout << "Press enter to start test 1 (with int)" << std::endl;
	getchar();

	std::cout << "create queue (Q1) of type int" << std::endl;
	Queue <int> Q1(3);

	std::cout << std::endl << "<add 5 items>" << std::endl;
	Q1.enqueue(1);	//add 1
	Q1.enqueue(2);	//add 2
	Q1.enqueue(3);	//add 3
	Q1.enqueue(4);	//add 4
	Q1.enqueue(5);	//add 5

	std::cout << std::endl << "All items:" << std::endl;
	Q1.PrintQueue();

	//----
	std::cout << std::endl << "<remove 2 items>" << std::endl;
	try {
		std::cout << "Remove item: " << Q1.dequeue() << std::endl;	//remove 1
		std::cout << "Remove item: " << Q1.dequeue() << std::endl;	//remove 2
	}
	catch (int e) {
		std::cout << "Error: Dequeue of empty queue at pos " << e << std::endl;
		std::cout << "Halting remaining Dequeue commands" << std::endl;
	}
	
	

	std::cout << std::endl << "All items:" << std::endl;
	Q1.PrintQueue();

	std::cout << std::endl << "<copy queue to new queue-item (Q2)>" << std::endl;
	Queue <int> Q2(Q1);	//test copy constructor

	std::cout << std::endl << "All items of Q2:" << std::endl;
	Q2.PrintQueue();

	//----

	std::cout << std::endl << "<add 2 items>" << std::endl;
	Q1.enqueue(11);	//add 11
	Q1.enqueue(12);	//add 12

	std::cout << std::endl << "All items:" << std::endl;
	Q1.PrintQueue();

	std::cout << std::endl << "<copy Q1 to Q2>" << std::endl;
	Q2 = Q1;	//test overload operator

	std::cout << std::endl << "All items of Q2:" << std::endl;
	Q2.PrintQueue();

	//----
	try {
		std::cout << std::endl << "the front-most item is: " << Q1.front() << std::endl;	//print front-most element (3)
	}
	catch (int e) {
		std::cout << "Error: Front of empty queue at pos " << e << std::endl;
	}

	std::cout << "is list empty? (0 = no, 1 = yes) " << Q1.isEmpty() << std::endl;	//returns 0 (bcs list is not empty)

	//----

	std::cout << std::endl << "<remove 7 items> (5 items + 2 empty)" << std::endl;
	try {
		std::cout << "Remove item: " << Q1.dequeue() << std::endl;	//remove 3
		std::cout << "Remove item: " << Q1.dequeue() << std::endl;	//remove 4
		std::cout << "Remove item: " << Q1.dequeue() << std::endl;	//remove 5
		std::cout << "Remove item: " << Q1.dequeue() << std::endl;	//remove 11
		std::cout << "Remove item: " << Q1.dequeue() << std::endl;	//remove 12
		std::cout << "Remove item: " << Q1.dequeue() << std::endl;	//--
		std::cout << "Remove item: " << Q1.dequeue() << std::endl;	//--
	}
	catch (int e) {
		std::cout << "Error: Dequeue of empty queue at pos " << e << std::endl;
		std::cout << "Halting remaining Dequeue commands" << std::endl; 
	}

	std::cout << std::endl << "All items:" << std::endl;
	Q1.PrintQueue();

	std::cout << std::endl << "is list empty? (0 = no, 1 = yes) " << Q1.isEmpty() << std::endl;	//returns 1 (bcs list is empty)


	//---------------------------------------------------

	//Q1.~Queue();	//triggar break
	//Q2.~Queue();

	//---------------------------------------------------

	std::cout << std::endl << "Press enter to start test 2 (with char)";
	getchar();

	std::cout << std::endl << std::endl << "___________________________________________________" << std::endl << std::endl;

	std::cout << std::endl << "create queue (Q3) of type char" << std::endl;
	Queue <char> Q3(3);

	std::cout << std::endl << "<add 5 items>" << std::endl;
	Q3.enqueue('a');	//add a
	Q3.enqueue('b');	//add b
	Q3.enqueue('c');	//add c
	Q3.enqueue('d');	//add d
	Q3.enqueue('e');	//add e

	std::cout << std::endl << "All items:" << std::endl;
	Q3.PrintQueue();

	//----

	std::cout << std::endl << "<remove 2 items>" << std::endl;
	try {
		std::cout << "Remove item: " << Q3.dequeue() << std::endl;	//remove a
		std::cout << "Remove item: " << Q3.dequeue() << std::endl;	//remove b
	}
	catch (int e) {
		std::cout << "Error: Dequeue of empty queue at pos " << e << std::endl;
		std::cout << "Halting remaining Dequeue commands" << std::endl;
	}

	std::cout << std::endl << "All items:" << std::endl;
	Q3.PrintQueue();

	std::cout << std::endl << "<copy queue to new queue-item (Q4)>" << std::endl;
	Queue <char> Q4(Q3);	//test copy constructor

	std::cout << std::endl << "All items of Q4:" << std::endl;
	Q4.PrintQueue();

	//----

	std::cout << std::endl << "<add 2 items>" << std::endl;
	Q3.enqueue('x');	//add x
	Q3.enqueue('y');	//add y

	std::cout << std::endl << "All items:" << std::endl;
	Q3.PrintQueue();

	std::cout << std::endl << "<copy Q3 to Q4>" << std::endl;
	Q4 = Q3;	//test overload operator

	std::cout << std::endl << "All items of Q4:" << std::endl;
	Q4.PrintQueue();

	//----
	try {
		std::cout << std::endl << "the front-most item is: " << Q3.front() << std::endl;	//print front-most element (c)
	}
	catch (int e) {
		std::cout << "Error: Front of empty queue at pos " << e << std::endl;
	}

	std::cout << "is list empty? (0 = no, 1 = yes) " << Q3.isEmpty() << std::endl;	//returns 0 (bcs list is not empty)

	//----

	std::cout << std::endl << "<remove 7 items> (5 items + 2 empty)" << std::endl;
	try {
		std::cout << "Remove item: " << Q3.dequeue() << std::endl;	//remove c
		std::cout << "Remove item: " << Q3.dequeue() << std::endl;	//remove d
		std::cout << "Remove item: " << Q3.dequeue() << std::endl;	//remove e
		std::cout << "Remove item: " << Q3.dequeue() << std::endl;	//remove x
		std::cout << "Remove item: " << Q3.dequeue() << std::endl;	//remove y
		std::cout << "Remove item: " << Q3.dequeue() << std::endl;	//--
		std::cout << "Remove item: " << Q3.dequeue() << std::endl;	//--
	}
	catch (int e) {
		std::cout << "Error: Dequeue of empty queue at pos " << e << std::endl;
		std::cout << "Halting remaining Dequeue commands" << std::endl;
	}

	std::cout << std::endl << "All items:" << std::endl;
	Q3.PrintQueue();

	std::cout << std::endl << "is list empty? (0 = no, 1 = yes) " << Q3.isEmpty() << std::endl;	//returns 1 (bcs list is empty)

	//---------------------------------------------------

	//Q3.~Queue();	//triggar break
	//Q4.~Queue();

	//---------------------------------------------------

	std::cout << std::endl << "Press enter to exit" << std::endl;
	getchar();
	return 1;
}
// */