#pragma once
#include <iostream>
#include <exception>
#include "greske.h"
using namespace std;

template<typename T>
class Lista {
	struct Node {
		T data;
		Node* next;
		Node(const T& dat, Node* nxt = nullptr): data(dat) {next = nxt; }
	};
	Node* first, * last;
	mutable Node* curr, *prev;
	void brisi();
public:
	Lista() { first = last = curr = prev = nullptr; }
	Lista(const Lista&) = delete;
	Lista& operator=(const Lista&) = delete;
	~Lista() { brisi(); }
	Lista& operator<<=(const T& t);
	Lista& operator>>=(const T& t);
	Lista& setCurrToFirst();
	const Lista& setCurrToFirst() const;
	Lista& moveCurr();
	const Lista& moveCurr() const;
	bool currExists() const { return curr != nullptr; }
	T& getCurr();
	T& getCurr() const;

};

template<typename T>
Lista<T>& Lista<T>::operator<<=(const T& t) {
	Node* tmp = new Node(t);
	if (!first) first = tmp;
	else last->next = tmp;
	last = tmp;
	return *this;
}

template<typename T>
Lista<T>& Lista<T>::operator>>=(const T& t)
{
	Node* tmp = new Node(t);
	if (!first) last = tmp;
	tmp->next = first;
	first = tmp;
	return *this;

}

template<typename T>
 const Lista<T>& Lista<T>::setCurrToFirst() const
{
	 if (!first) return;
	 else curr = first;
	 prev = nullptr;
	 return *this;
}

 template<typename T>
 Lista<T>& Lista<T>::moveCurr()
 {
	 prev = curr;
	 curr = curr->next;
	 return *this;
 }

 template<typename T>
 const Lista<T>& Lista<T>::moveCurr() const
 {
	 if (!curr) return;
	 prev = curr;
	 curr = curr->next;
	 return *this;
 }

template<typename T>
Lista<T>& Lista<T>::setCurrToFirst()
{
	curr = first;
	prev = nullptr;
	return *this;
}

template<typename T>
T& Lista<T>::getCurr() {
	if (!curr) throw GNemaCurr();
	return curr->data;
}

template<typename T>
T& Lista<T>::getCurr() const {
	if (!curr) throw GNemaCurr();
	return curr->data;
}

template<typename T>
void Lista<T>::brisi()
{
	for (Node* curr = first; curr;) {
		Node* old = curr;
		curr = curr->next;
		delete old;
	}
	first = last = curr = prev = nullptr;
}
