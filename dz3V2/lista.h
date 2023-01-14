#pragma once
#include <iostream>
#include <exception>
using namespace std;

class GIzvanOpsega : public exception {
public:
	GIzvanOpsega():exception("Index je izvan opsega."){}
};

template<typename T>

class Lista {
	struct Node {
		T data;
		Node* next;
		Node(const T& dat, Node* nxt = nullptr) { data = dat; next = nxt; }
	};
	Node* first, * last;

	void copy(const Lista& l);
	void move(Lista& l);
	void brisi();

public:
	Lista() { first = last =  nullptr; }
	~Lista() { brisi(); }
	Lista(const Lista& l) { copy(l); }
	Lista(Lista&& l) { move(l); }
	Lista& operator=(const Lista& l) {
		if (this != &l) {
			brisi();
			copy(l);
		}
		return *this;
	}

	Lista& operator=(Lista&& l) {
		if (this != &l) {
			brisi();
			move(l);
		}
		return *this;
	}
	Lista& operator+=(const T& t) {
		Node *tmp = new Node(t);
		if (!first)first = tmp;
		else last->next = tmp;
		last = tmp;
		return *this;
	}
	T& operator[](int index) const;

	int getNumOfElems() const;
};


template<typename T>
int Lista<T>::getNumOfElems() const {
	int br=0;
	for (Node* curr = first; curr; curr = curr->next) br++;
	return br;
}

template<typename T>
T& Lista<T>::operator[](int index) const {
	if (index >= this->getNumOfElems()) throw GIzvanOpsega();
	int br = 0;
	for (Node* curr = first; curr; curr = curr->next) {
		if (br == index) return curr->data;
		br++;
	}
 }

template<typename T>
void Lista<T>::copy(const Lista& l) {
	first = last = nullptr;
	for (Node* curr = l.first; curr; curr = curr->next) {
		Node* novi = new Node(curr->data);
		if (!first)first = novi;
		else last->next = novi;
		last = novi;
	}
}

template<typename T>
void Lista<T>::move(Lista& l) {
	last = l.last;
	first = l.first;
	l.last = l.first = nullptr;
}

template<typename T>
void Lista<T>::brisi() {
	while (first) {
		Node* old = first;
		first = first->next;
		delete old;
	}
}
