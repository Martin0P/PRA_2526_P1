#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <stdexcept>
#include <ostream>
#include "List.h"

template <typename T>
class ListArray : public List<T> {
    private:
        T* arr;
    	int max;
	int n;
	static const int MINSIZE = 2;

	void resize(int nsize){
	    if(nsize < MINSIZE) nsize = MINSIZE;
	    if(nsize < n) nsize = n;

	    T* narr = new T[nsize];

	    for(int i = 0; i < n; ++i){
	    	narr[i] = arr[i];
	    }

	    delete[] arr;
	    arr = narr;
	    max = nsize;

	}
    public:
	ListArray(): arr(new T[MINSIZE]), max(MINSIZE), n(0) {}
        ~ListArray() override {delete[] arr; }
	
	// Metodos de LIST<T>
	int size() const override{ return n; }

	void insert(int pos, const T& e) override {
	    if(pos < 0 || pos > n) throw std::out_of_range("Posicion fuera de rango");

	    if(n == max) resize(max * 2);

	    for(int i = n; i > pos; --i){
	        arr[i] = arr[i -1]; 
	    }
	    arr[pos] = e;
	    ++n;
	}

	T remove(int pos) override{
	    if(pos < 0 || pos >= n) throw std::out_of_range("Posicion fuera de rango");
	    
	    T removed = arr[pos];

	    for(int i = pos; i < n -1; i++){
	    	arr[i] = arr[i + 1]; 
	    }
	    --n;

	    if(max > MINSIZE && n <= max/4){
	    	resize(max / 2);
	    }

	    return removed;
	}

	T get(int pos) const override{
	    if(pos < 0 || pos >= n) throw std::out_of_range("Posicion fuera de rango");
	    return arr[pos];
	}

	int search(const T& e) const override{
            for(int i = 0; i < n; ++i){
	    	if(arr[i] == e) return i;
	    }
	    return -1;
	}

	// LISTARRAY
	T operator[](int pos) const{
	    if(pos < 0 || pos >= n) throw std::out_of_range("Posicion fuera de rango");
	    return arr[pos];
	}

	friend std::ostream& operator<<(std::ostream& out, const ListArray<T>& list){
	    out << "[";
	    for(int i = 0; i < list.n; i++){
	    	out << list.arr[i];
		if(i != list.n - 1) out << ",";
	    }
	    out << "]";
	    return out;
	}
};

#endif
