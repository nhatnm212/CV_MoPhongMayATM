#ifndef Node_H
#define Node_H
#include <iostream>
using namespace std;

template <class DataType>
class LinkedList;

template <class DataType>
class Node {
	friend LinkedList<DataType>;
private:
	DataType _data;
	Node* _pNext;
public:
	DataType getData();
	void setData(DataType data); 
	Node<DataType>* getpNext(); 
	Node(DataType data);
	void display(); 
};

#endif // !Node_H
