#include "Queue.h"

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	std::set_unexpected([]{
		std::cout << "Unhandled exception" << std::endl;
	});

	Queue <int> Q;

	Q.Enqueue(1);
	Q.Enqueue(2);
	Q.Enqueue(3);
	Q.Enqueue(4);
	Q.Enqueue(5);

	getchar();
	return 1;
}