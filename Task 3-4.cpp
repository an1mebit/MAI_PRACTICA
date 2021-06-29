#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

template<typename T>
class List
{
public:
	List();
	~List();

	void popfront();
	void pushnode(T data);
	void clear();
	int getsize() { return size; }
	void show();
	void ToMas(T *head,int size);

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
void List<T>::ToMas(T *head, int size)
{
	setlocale(LC_ALL, "rus");
	double arifm = 0;
	double kvadrat = 0;
	double kvadratOtklon = 0;
	for (int i = 0; i < size; i++)
		arifm += head[i];
	arifm = arifm / size;
	for (int i = 0; i < size; i++)
		kvadrat += pow((head[i] - arifm), 2);
	for (int i = 0; i < size; i++)
		kvadratOtklon = sqrt(kvadrat / size);
	cout << "Среднее квадратичное отклонение равно: " << kvadratOtklon << endl;;
}

int main()
{
	List<int> list;
	int size;
	cin >> size;
	for (int i = 0; i < size; i++)
		list.pushnode(rand() % 100);
	list.show();
	int *node;
	cout << "Среднее квадратичное отклонение равно: ";
	list.ToMas(node,size);
	return 0;
}