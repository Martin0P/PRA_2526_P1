#ifndef LIST_H
#define LIST_H

template <typename T>
class List {
    public:
        virtual ~List() = default;

	virtual void insert(int pos, const T& e) = 0;
	virtual void append(const T& e){ insert(size(), e);} 	// final = size()
	virtual void prepend(const T& e){ insert(0, e);}		// inicio = 0
	
	virtual T remove(int pos) = 0;
	virtual T get(int pos) const = 0;

	virtual int search(const T& e) const = 0;
	virtual int size() const = 0;
	virtual bool empty() const { return size() == 0; }
};

#endif
