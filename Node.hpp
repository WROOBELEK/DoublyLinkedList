// Node.h
#pragma once

#include "Car.h"

template<typename T>
struct Node {
	T value;
	Node<T>* next = nullptr;
	Node<T>* prev = nullptr;
};
