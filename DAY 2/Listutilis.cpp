#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

template<typename T>
class List
{
private:


	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
public:
	List();
	~List();

	void popfront();
	void pushnode(T data);
	void clear();
	int getsize() { return size; }
	void show();
	double Skofromlist(Node<T>* head, int size);
	double TestSkofromList();
	static void runTest(int(List<T>::*testFunction)(), const string& testName);
	
	int size;
	Node<T>* head;
};

template<typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::popfront()
{
	Node<T>* temp = head;

	head = head->pNext;
	delete temp;
	size--;
}

template<typename T>
void List<T>::pushnode(T data)
{
	Node* nd = new Node();
	nd->data = data;
	nd->next = head;
	head = nd;
}

template<typename T>
void List<T>::clear()
{
	while (size)
	{
		popfront();
	}
}

template<typename T>
void List<T>::show()
{
	Node* current = head;
	while (current)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

template<typename T>
double List<T>::Skofromlist(Node<T>* head, int size)
{
	setlocale(LC_ALL, "rus");
	if (!head) return 0;

	int count = 0;
	double sum = 0;

	Node<T>* current = head;

	while (current)
	{
		++count;
		current = current * current;
		sum += current;
		if (sum == 0)
			continue;
		sum = sum / count->data;
		current = current->next;
	}
	return sqrt(sum);
}

template<typename T>
double List<T>::TestSkofromList()
{
	Node<T>* head = new Node;
	pushnode(head, new Node{ 1 });
	pushnode(head, new Node{ 2 });

	init(head->next);
	bool f2 = (head->next->data == 0);
	pushNode(head, new Node{ 3 });
	pushNode(head, new Node{ 4 });
	lRoundShiftNode(head, 3);
	bool f3 = (head->data == 4 && head->next->data == 1
		&& head->next->next->data == 2 && head->next->next->next->data == 3);

	return ((f1 && f2 && f3) ? 0 : -1);
}

template<typename T>
void List<T>::runTest(double(List<T>::*TestSkofromList)(), const string& testName)
{
	if (List<T>::TestSkofromList() == 0)
		std::cout << "Test " << testName << " - OK" << std::endl;
	else
		std::cout << "Test " << testName << " - FAIL" << std::endl;
}

int main()
{
	List<double> list;
	list.runTest(bind(list.TestSkofromList()), "testSkoFromList");
}
