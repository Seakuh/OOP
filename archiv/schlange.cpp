#include <iostream>
#include "schlange.h"

Queue::Queue(const int size) : size(size), schlange(new int[size]){};

int Queue::getSize()
{
	return this->size;
}

bool Queue::isEmpty()
{
	if (length == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Queue::get()
{

	if (head == size)
	{
		head = 0;
	}

	else if ((head + 1) != tail)
	{
		head++;
		length--;
	}
	else
	{
		length = 0;
		std::cout << "________________________" << std::endl;
		throw "Liste ist leer";
	}

	std::cout << " " << std::endl;
	std::cout << "Get:\t\t\t" << schlange[head] << std::endl;
	std::cout << "leange:\t\t\t" << length << std::endl;
	std::cout << "head:\t\t\t" << head << std::endl;

	std::cout << " " << std::endl;

	return head;
}

void Queue::put(int v)
{

	if (length != size)
	{
		length++;
	}
	schlange[tail] = v;

	std::cout << "Put:\t\t\t" << schlange[tail] << std::endl;

	tail = tail + 1;

	std::cout << "leange:\t\t\t" << length << std::endl;

	if (tail == size)
	{
		tail = 0;
	}
	if (tail == head)
	{
		head++;
	}
	std::cout << "head:\t\t\t" << head << std::endl;

	std::cout << " " << std::endl;
}

int main()
{
	Queue python(50);

	std::cout << python.isEmpty() << std::endl;

	try
	{

		for (int i = 1; i <= 55; i++)
		{
			python.put(i);
		}

		std::cout << "------------get------------" << std::endl;

		for (int i = 1; i <= 70; i++)
		{
			python.get();
		}
	}

	catch (const char *e)
	{
		std::cout << e << std::endl;
	}
	std::cout << python.isEmpty() << std::endl;

	return 0;
}

// #include <iostream>
// #include "schlange.h"

// Queue::Queue(const int size1):size(size1){
// 	schlange = new int[size1];
// };

// int Queue::getSize()
// {
// 	return this->size;
// }
// int Queue::getanStelle(int j)
// {
// 	if (j <= sizeof(schlange))
// 	{
// 		return schlange[j];
// 	}
// 	else
// 	{
// 		throw "Not in the Python range.";
// 	}
// }

// bool Queue::isEmpty()
// {
// 	if (size == 0)
// 	{
// 		return true;
// 	}
// 	else
// 	{
// 		return false;
// 	}
// }

// int Queue::get()
// {

// 	int r = *head;
// 	std::cout << "Get:\t\t\t" << r << std::endl;
// 	head = head + 1;
// 	length--;
// 	size--;
// 	std::cout << "leange:\t\t" << length << std::endl;
// 	std::cout << "Anzahl der Elemente :\t\t" << size << std::endl;
// 	std::cout << "Array Index:\t\t" << hIndex << std::endl;
// 	hIndex++;

// 	std::cout << " " << std::endl;

// 	return r;
// }

// void Queue::put(int v)
// {

// 	if (tIndex == 49 && hIndex != 0)
// 	{

// 		tIndex = 0;
// 		tail = &schlange[0];
// 		head++;
// 	}
// 	if (tIndex + 1 == hIndex)
// 	{

// 		tail = &schlange[0];
// 		head = &schlange[0];
// 		length = 0;
// 		tIndex = 0;
// 		size = 0;
// 	}
// 	if (tIndex - 49 == hIndex)
// 	{
// 		tail = &schlange[0];
// 		head = &schlange[0];
// 		length = 0;
// 		tIndex = 0;
// 		size = 0;
// 	}

// 	*tail = v;
// 	std::cout << "Put:\t\t\t" << *tail << std::endl;
// 	*tail++;
// 	size++;
// 	length++;
// 	std::cout << "Array Index: \t\t" << tIndex << std::endl;
// 	tIndex++;
// 	std::cout << "length:\t\t\t" << length << std::endl;
// 	std::cout << "Anzahl der Elemente:\t" << size << std::endl;

// 	std::cout << " " << std::endl;
// 	std::cout << "PosH:\t\t\t" << hIndex << std::endl;
// 	std::cout << "PosT:\t\t\t" << tIndex << std::endl;
// }

// int main()
// {
// 	Queue python(50);
// 	int position = 5;

// 	python.isEmpty();

// 	try
// 	{
// 		for (int i = 1; i <= 70; i++)
// 		{
// 			python.put(i);
// 		}
// 	}
// 	catch (const char *e)
// 	{
// 		std::cout << "Exception:\t\t" << e << std::endl;
// 	}
// 	try
// 	{
// 		python.get();
// 		std::cout << "Position\t\t" << position << python.getanStelle(position) << std::endl;
// 	}
// 	catch (const char *e)
// 	{
// 		std::cout << "Exception:\t\t" << e << std::endl;
// 	}

// 	for (int i = 0; i < 50; i++)
// 	{
// 		std::cout << python.getanStelle(i) << "...";
// 	}
// 	std::cout << "" << std::endl;
// 	return 0;
// }