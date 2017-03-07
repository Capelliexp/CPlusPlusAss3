#include "Queue.h"
#include <exception>

/*int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Queue <int> Q(1);

	Q.Enqueue(1);
	Q.Enqueue(2);
	Q.Enqueue(3);
	Q.Enqueue(4);
	Q.Enqueue(5);
	Q.Enqueue(6);

	Q.PrintQueue();

	Q.Dequeue();
	Q.Dequeue();
	Q.Dequeue();

	std::cout << std::endl;
	Q.PrintQueue();

	std::cout << std::endl;
	std::cout << Q.Front() << std::endl;
	std::cout << Q.IsEmpty() << std::endl;

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
	Q1.Enqueue(1);	//add 1
	Q1.Enqueue(2);	//add 2
	Q1.Enqueue(3);	//add 3
	Q1.Enqueue(4);	//add 4
	Q1.Enqueue(5);	//add 5

	std::cout << std::endl << "All items:" << std::endl;
	Q1.PrintQueue();

	//----

	std::cout << std::endl << "<remove 2 items>" << std::endl;
	Q1.Dequeue();	//remove 1
	Q1.Dequeue();	//remove 2

	std::cout << std::endl << "All items:" << std::endl;
	Q1.PrintQueue();

	std::cout << std::endl << "<copy queue to new queue-item (Q2)>" << std::endl;
	Queue <int> Q2(Q1);	//test copy constructor

	std::cout << std::endl << "All items of Q2:" << std::endl;
	Q2.PrintQueue();

	//----

	std::cout << std::endl << "<add 2 items>" << std::endl;
	Q1.Enqueue(11);	//add 11
	Q1.Enqueue(12);	//add 12

	std::cout << std::endl << "All items:" << std::endl;
	Q1.PrintQueue();

	std::cout << std::endl << "<copy Q1 to Q2>" << std::endl;
	Q2 = Q1;	//test overload operator

	std::cout << std::endl << "All items of Q2:" << std::endl;
	Q2.PrintQueue();

	//----

	std::cout << std::endl << "the front-most item is: " << Q1.Front() << std::endl;	//print front-most element (3)
	std::cout << "is list empty? (0 = no, 1 = yes) " << Q1.IsEmpty() << std::endl;	//returns 0 (bcs list is not empty)

	//----

	std::cout << std::endl << "<remove 7 items> (5 items + 2 empty)" << std::endl;
	Q1.Dequeue();	//remove 3
	Q1.Dequeue();	//remove 4
	Q1.Dequeue();	//remove 5
	Q1.Dequeue();	//remove 11
	Q1.Dequeue();	//remove 12
	Q1.Dequeue();	//--
	Q1.Dequeue();	//--

	std::cout << std::endl << "All items:" << std::endl;
	Q1.PrintQueue();

	std::cout << std::endl << "is list empty? (0 = no, 1 = yes) " << Q1.IsEmpty() << std::endl;	//returns 1 (bcs list is empty)


	//---------------------------------------------------

	std::cout << std::endl << "Press enter to start test 2 (with char)";
	getchar();

	std::cout << std::endl << std::endl << "___________________________________________________" << std::endl << std::endl;

	std::cout << std::endl << "create queue (Q3) of type char" << std::endl;
	Queue <char> Q3(3);

	std::cout << std::endl << "<add 5 items>" << std::endl;
	Q3.Enqueue('a');	//add a
	Q3.Enqueue('b');	//add b
	Q3.Enqueue('c');	//add c
	Q3.Enqueue('d');	//add d
	Q3.Enqueue('e');	//add e

	std::cout << std::endl << "All items:" << std::endl;
	Q3.PrintQueue();

	//----

	std::cout << std::endl << "<remove 2 items>" << std::endl;
	Q3.Dequeue();	//remove a
	Q3.Dequeue();	//remove b

	std::cout << std::endl << "All items:" << std::endl;
	Q3.PrintQueue();

	std::cout << std::endl << "<copy queue to new queue-item (Q4)>" << std::endl;
	Queue <char> Q4(Q3);	//test copy constructor

	std::cout << std::endl << "All items of Q4:" << std::endl;
	Q4.PrintQueue();

	//----

	std::cout << std::endl << "<add 2 items>" << std::endl;
	Q3.Enqueue('x');	//add x
	Q3.Enqueue('y');	//add y

	std::cout << std::endl << "All items:" << std::endl;
	Q3.PrintQueue();

	std::cout << std::endl << "<copy Q3 to Q4>" << std::endl;
	Q4 = Q3;	//test overload operator

	std::cout << std::endl << "All items of Q4:" << std::endl;
	Q4.PrintQueue();

	//----

	std::cout << std::endl << "the front-most item is: " << Q3.Front() << std::endl;	//print front-most element (c)
	std::cout << "is list empty? (0 = no, 1 = yes) " << Q3.IsEmpty() << std::endl;	//returns 0 (bcs list is not empty)

	//----

	std::cout << std::endl << "<remove 7 items> (5 items + 2 empty)" << std::endl;
	Q3.Dequeue();	//remove c
	Q3.Dequeue();	//remove d
	Q3.Dequeue();	//remove e
	Q3.Dequeue();	//remove x
	Q3.Dequeue();	//remove y
	Q3.Dequeue();	//--
	Q3.Dequeue();	//--

	std::cout << std::endl << "All items:" << std::endl;
	Q3.PrintQueue();

	std::cout << std::endl << "is list empty? (0 = no, 1 = yes) " << Q3.IsEmpty() << std::endl;	//returns 1 (bcs list is empty)

	std::cout << std::endl << "Press enter to exit" << std::endl;
	getchar();
	return 1;
}
// */