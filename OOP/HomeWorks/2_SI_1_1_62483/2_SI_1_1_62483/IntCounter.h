template<typename T>
class IntCounter {
private:
	T* ptr;
	int* counter;

	void add_reference();
	void remove_reference();
	void freeMemory();

	void redirectPointers(T* newPtr, int* newCounter);
	void redirectPointers(const IntCounter<T>& rhs);

public:
	IntCounter();

	IntCounter(T* newPtr);
	IntCounter(const IntCounter<T>& rhs);
	IntCounter& operator=(const IntCounter<T>& rhs);
	~IntCounter();

	int get_count() const;
	T get_value() const;
};



template<typename T>
inline void IntCounter<T>::add_reference() {
	*(this->counter) += 1;
}

template<typename T>
inline void IntCounter<T>::remove_reference() {
	*(this->counter) -= 1;
}

template<typename T>
inline void IntCounter<T>::freeMemory() {
	delete this->ptr;
	delete this->counter;
}

template<typename T>
inline void IntCounter<T>::redirectPointers(T* newPtr, int* newCounter)
{
	this->ptr = newPtr;
	this->counter = newCounter;
}

template<typename T>
inline void IntCounter<T>::redirectPointers(const IntCounter<T>& rhs)
{
	this->redirectPointers(rhs.ptr, rhs.counter);
}

template<typename T>
inline IntCounter<T>::IntCounter() :ptr(nullptr), counter(new int(0)) {}


template<typename T>
inline IntCounter<T>::IntCounter(T* newPtr)
{
	this->redirectPointers(newPtr, new int(1));
	// this->ptr = ptr;
	// this->counter = new int(1);
}

template<typename T>
inline IntCounter<T>::IntCounter(const IntCounter& rhs)
{
	this->redirectPointers(rhs);
	this->add_reference();

}

template<typename T>
inline IntCounter<T>& IntCounter<T>::operator=(const IntCounter<T>& rhs)
{
	// Two objects are the same if they have the same pointer int* ptr,
	// which is different from the usual check in operator=
	if (this->ptr != rhs.ptr) {
		// Remove reference from the old pointer and check if deletion is due
		this->remove_reference();
		if (this->get_count() == 0) {
			this->freeMemory();
		}

		// Point the variables to the new pointer and add a reference
		this->redirectPointers(rhs);
		this->add_reference();
	}
	return *this;
}

template<typename T>
inline IntCounter<T>::~IntCounter()
{
	this->remove_reference();
	if (this->get_count() == 0) {
		this->freeMemory();
	}

}

template<typename T>
inline int IntCounter<T>::get_count() const
{
	return *this->counter;

}

template<typename T>
inline T IntCounter<T>::get_value() const
{
	return *this->ptr;
}
