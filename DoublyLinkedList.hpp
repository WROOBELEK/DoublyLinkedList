// DoublyLinkedList.hpp
#pragma once

#include <string>
#include <sstream>

#include "Node.h"

using namespace std;

template<typename T>
class DoublyLinkedList {
private:
	int nodeCount = 0;
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;

public:
	
	// A - dodanie nowego elementu na końcu listy
		void addTail(const T& value) {
		if (nodeCount == 0)
		{
			addHead(value);
			return;
		}

		Node<T>* node = new Node<T>{ value };
		tail->next = node;
		node->prev = tail;
		tail = node;

		nodeCount++;
	}

	// B - dodanie nowego elementu na początku listy
	void addHead(const T& value) {
		Node<T>* node = new Node<T>();
		node->value = value;
		
		node->next = head;

		if (head != nullptr) {
			head->prev = node;
		}

		head = node;

		if (nodeCount == 0) {
			tail = head;
		}
		
		nodeCount++;
	}

	// C - usunięcie ostatniego elementu
	void popTail() {
		if (nodeCount == 0) {
			return;
		}
		else if (nodeCount == 1)
		{
			popHead();
			return;
		}

		Node<T>* node = tail;
		tail = tail->prev;

		tail->next = nullptr;

		delete node;
		nodeCount--;
	}

	// D - usunięcie pierwszego elementu
	void popHead() {
		if (nodeCount == 0) {
			return;
		}

		Node<T>* node = head;
		head = head->next;

		delete node;

		if (head != nullptr) {
			head->prev = nullptr;
		}

		nodeCount--;
	}

	// E - zwrócenie danych i-tego elementu listy
	Node<T>* getByIndex(int index) {
		if (index < 0 || index > nodeCount) {
			return nullptr;
		}
		else if (index == 0) {
			return head;
		}
		else if (index == nodeCount - 1) {
			return tail;
		}

		Node<T>* temp = head;

		for (int i = 0; i < index; i++) {
			temp = temp->next;
		}

		return temp;
	}

	// F - ustawienie (podmiana) danych i-tego elementu listy
	void changeDataAtIndex(int index, T& value) {
		Node<T>* temp = head;

		for (int i = 0; i < index; i++) {
			temp = temp->next;
		}

		temp->value = value;
	}

	// G - wyszukanie elementu
	Node<T>* findByValues(T& data) {
		Node<T>* temp = head;

		for (int i = 0; i < nodeCount; i++) {
			if (temp->value == data) {
				return temp;
			}
			temp = temp->next;
		}
		return NULL;

	}
	
	// G2 - wyszukanie elementu --- ptr
	Node<T>* findByValues(T& data, bool x) {
		Node<T>* temp = head;

		for (int i = 0; i < nodeCount; i++) {
			if (*(temp->value) == *data) {
				return temp;
			}
			temp = temp->next;
		}
		return NULL;

	}
	
	// H - wyszukanie i usuniecie elementu
	bool findAndDelete(T& data) {
		Node<T>* temp = head;

		bool flag = false;

		for (int i = 0; i < nodeCount; i++) {

			if (nodeCount == 0) {
				return false;
			}

			if (temp->value == data) {
				flag = true;
				break;
			}
			temp = temp->next;
		}

		if (flag == true) {

			Node<T>* next_node = temp->next;
			Node<T>* prev_node = temp->prev;

			prev_node->next = next_node;
			next_node->prev = prev_node;

			delete temp;
			nodeCount--;

			return true;
		}

	}

	// H - wyszukanie i usuniecie elementu
	bool findAndDelete(T& data, bool x) {
		Node<T>* temp = head;

		bool flag = false;

		for (int i = 0; i < nodeCount; i++) {

			if (nodeCount == 0) {
				return false;
			}

			if (*(temp->value) == *data) {
				flag = true;
				break;
			}
			temp = temp->next;
		}

		if (flag == true) {

			Node<T>* next_node = temp->next;
			Node<T>* prev_node = temp->prev;

			prev_node->next = next_node;
			next_node->prev = prev_node;

			delete temp;
			nodeCount--;

			return true;
		}

	}

	// J  -  czyszczenie listy tj. usunięcie wszystkich elementów
	void clearList() {
		Node<T>* temp;

		while (head != nullptr) {
			temp = head;
			head = head->next;
			delete temp;
			nodeCount--;
		}
		tail = nullptr;
		
	}

	// K - zwrócenie napisowej reprezentacji listy
	string list_to_string() {
		ostringstream lts;

		Node<T>* temp = head;
		for (int i = 0; i < nodeCount; i++) {
			lts << temp->value;
			temp = temp->next;
		}

		return lts.str();

	}

	string node_to_string(Node<T>* x) {
		if (x == NULL) {
			return "ERROR";
		}
		ostringstream nts;
		nts << x->value;
		return nts.str();
	}
};
