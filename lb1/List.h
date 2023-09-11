#pragma once
#include <iostream>
#include "Person.h"

//template<typename T>
//struct Node {
//	T data;
//	Node* next;
//};


struct Node {
	Person data;
	Node* next;
};

//template<typename T>
//class List {
//
//	Node<T>* head;
//	Node<T>* tail;
//	int size;
//public:
//	List() {
//		head = NULL;
//	}
//
//	bool IsEmpty();
//	void InsertFront(T& info);
//	void InsertBack(T& info);
//	void Print();
//};

class List {
	Node* head;
	Node* tail;
	int size;
public:
	List();
	List(Person& info);
	~List();

	bool IsEmpty();
	void InsertFront(Person& info);
	void InsertBack(Person& info);
	int ChangeByKey(std::string key);
	void FindByKey(std::string key);
	int RemovFromFront();            
	int RemovFromBack();
	int RemovByKey(std::string key);
	void ReadFile();
	void SaveFile();
	void Print();
};
