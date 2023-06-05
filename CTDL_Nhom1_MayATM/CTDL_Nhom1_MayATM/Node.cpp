#include "Node.h"

template<class DataType>
DataType Node<DataType>::getData() {
	return _data;
}

template<class DataType>
void Node<DataType>::setData(DataType data) {
	_data = data;
}

template <class DataType>
Node<DataType>* Node<DataType>::getpNext() {
	return _pNext;
}

template<class DataType>
Node<DataType>::Node(DataType data) {
	_data = data;
	_pNext = NULL;
}

template<class DataType>
void Node<DataType>::display() {
	cout << _data << endl;
}

