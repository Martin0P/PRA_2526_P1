#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <stdexcept>
#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
    private:
	Node<T>* first;
	int n;

	Node<T>* node_at(int pos) const{
	    Node<T>* cur = first;
	    for(int i = 0; i < pos; ++i) cur = cur->next;
	    return cur;
	}

    public:
	ListLinked(): first(nullptr), n(0) {}
        ~ListLinked() override {
	    while(first != nullptr){
	    	Node<T>* aux = first->next;
		delete first;
		first = aux;
	    }
	}
	
	// Metodos de LIST<T>
	int size() const override{ return n; }

	void insert(int pos, const T& e) override {
	    if(pos < 0 || pos > n) throw std::out_of_range("Posicion fuera de rango");

	    if(pos == 0){
	    	first = new Node<T>(e, first);
	    } else{
	    	Node<T>* prev = node_at(pos - 1);
		prev->next = new Node<T>(e, prev->next);
	    }
	    ++n;
	}

	T remove(int pos) override{
	    if(pos < 0 || pos >= n) throw std::out_of_range("Posicion fuera de rango");
	    
	    Node<T>* del = nullptr;

	    if(pos == 0){
	        del = first;
		first = first->next;
	    } else{
	        Node<T>* prev = node_at(pos - 1);
		del = prev->next;
		prev->next = del->next;
	    }


	    T value = del->data;
	    delete del;
	    --n;
	    return value;
	}

	T get(int pos) const override{
	    if(pos < 0 || pos >= n) throw std::out_of_range("Posicion fuera de rango");
	    return node_at(pos)->data;
	}

	int search(const T& e) const override{
            Node<T>* cur = first;
	    int i = 0;
	    while(cur != nullptr){
	    	if(cur->data == e) return i;
		cur = cur->next;
		++i;
	    }
	    return -1;
	}

	// LISTARRAY
	T operator[](int pos) const{
	    if(pos < 0 || pos >= n) throw std::out_of_range("Posicion fuera de rango");
	    return node_at(pos)->data;
	}

	friend std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list){
	    out << "[";
	    Node<T>* cur = list.first;
	    while(cur != nullptr){
		out << cur->data;
		if(cur->next != nullptr) out << ",";
		cur = cur->next;
	    }
	    out << "]";
	    return out;
	}
};

#endif
