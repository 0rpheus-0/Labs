#include <fstream> 
#include "List.h"
#include "Person.h"


List::List() {
	head = NULL;
	tail = NULL;
}

List::List(Person& info) {
	head->data = info;
	head->next = NULL;
}

List::~List() {
	if (!IsEmpty()) {
		Node* curPtr = head, *tempPtr;
		while (curPtr != NULL) {
			tempPtr = curPtr;
			curPtr = curPtr->next;
			delete tempPtr;
		}
	}
}

bool List::IsEmpty() {
	return head == NULL;
}

void List::InsertFront(Person& info) {
	Node* newPtr = new Node;
	newPtr->data = info;
	newPtr->next = NULL;

	if (IsEmpty())
		head = tail = newPtr;
	else {
		newPtr->next = head;
		head = newPtr;
	}
	size++;
}

void List::InsertBack(Person& info) {
	Node* newPtr = new Node;
	newPtr->data = info;
	newPtr->next = NULL;

	if (IsEmpty())
		head = tail = newPtr;
	else {
		tail->next = newPtr;
		tail = newPtr;
	}
	size++;
}

int List::ChangeByKey(std::string key) {
	if (IsEmpty()) {
		std::cout << "The list is empty\n";
		return 0;
	}

	if (head->data.GetName() == key) 
		head->data.Change();
	else {
		Node* curPtr = head;
		while (curPtr != tail) {
			if (curPtr->data.GetName() == key)
				curPtr->data.Change();
			curPtr = curPtr->next;
		}

	}
	return 1;
}

void List::FindByKey(std::string key) {
	if (IsEmpty()) {
		std::cout << "The list is empty\n";
		return;
	}

	if (head->data.GetName() == key)
		head->data.Print();
	else {
		Node* curPtr = head;
		while (curPtr != tail) {
			if (curPtr->data.GetName() == key)
				curPtr->data.Print();
			curPtr = curPtr->next;
		}
	}
}

int List::RemovFromFront() {
	if (IsEmpty()) {
		std::cout << "The list is empty\n";
		return 0;
	}

	if (head == tail)
		head = tail = NULL;
	else
		head = head->next;
	size--;
	return 1;
}

int List::RemovFromBack() {
	if (IsEmpty()) {
		std::cout << "The list is empty\n";
		return 0;
	}


	if (head == tail)
		head = tail = NULL;
	else {
		Node* curPtr = head;
		while (curPtr->next != tail)
			curPtr = curPtr->next;
		tail = curPtr;
		curPtr->next = NULL;
		//delete curPtr;
	}
	size--;
	return 1;
}

int List::RemovByKey(std::string key) {
	if (IsEmpty()) {
		std::cout << "The list is empty\n";
		return 0;
	}

	if (head == tail && (head->data.GetName() == key)) {
		head = tail = NULL;
		return 1;
	}
	if(head->next != tail && head->data.GetName() == key)
		head = head->next;
	else {
		Node* curPtr = head;
		while (curPtr->next != tail && !(curPtr->next->data.GetName() == key)) 
			curPtr = curPtr->next;

		curPtr->next = curPtr->next->next;
		delete curPtr;
	}
	size--;
	return 1;
}

void List::ReadFile() {
	std::ifstream fin;
	fin.open("Person.txt");
	if (!fin.is_open()) {
		std::cout << "Error reading the file " << "Person.txt" << std::endl;
		system("pause");
	}
	else
		std::cout << "Person.txt" << " loading...\n";

	std::string temp;
	int examples;
	fin >> temp;
	if (temp == "Person") {
		fin >> examples;
		for (int i = 0;i < examples; i++) {
			Person temp;
			temp.ReadFile(fin);
			InsertBack(temp);
		}
		//size += examples;
	}
	fin.close();
}

void List::SaveFile() {
	std::ofstream fout;
	fout.open("Persen.txt");
	if (!fout.is_open()) {
		std::cout << "Error reading the file " << "Persen_Test_Safe.txt" << std::endl;
		system("pause");
	}
	else
		std::cout << "Persen.txt" << " loading...\n";

	fout << "Persen\n";
	fout << size << "\n";
	Node* curPtr = head;
	for (int i = 0;i < size; i++) {
		curPtr->data.SaveFile(fout);
		curPtr = curPtr->next;
	}
	std::cout << "List is saved\n";
	fout.close();

}

void List::Print() {
	if (IsEmpty()) {
		std::cout << "The list is empty\n";
		return;
	}

	Node* tempPtr = head;
	std::cout << "The list :\n";
	while (tempPtr != NULL) {
		tempPtr->data.Print();
		tempPtr = tempPtr->next;
	}
	delete tempPtr;
}