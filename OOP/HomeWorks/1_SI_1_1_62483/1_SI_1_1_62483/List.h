#pragma once

template<typename T>
class List
{
private:
	T* elements;

	int capacity;
	int size;

	void ResizeArray();

	void ShiftArrayToRight(const int& index);
	void ShiftArrayToLeft(const int& index);

	bool NeedResize();

public:
	List();
	List(const T* elements, const int& size);
	List(const List& list);
	~List();

	const int GetLength() const;

	const int GetCapacity() const;

	T GetElement(const int& index) const;

	const bool AddElement(const T& element);
	const bool AddElementOnIndex(const T& element, const int& index);

	const bool DeleteElement(const int& index);

	const bool DeleteAll();

	List<T> operator =(const List<T>& obj);
	T operator[](const int&) const;
};

template<typename T>
List<T>::List() : capacity(1), size(0)
{
	this->elements = new T[1];
}

template<typename T>
List<T>::List(const T* elements, const int& size)
{
	this->elements = new T[size];

	this->capacity = size;
	this->size = size;

	for (int i = 0; i < this->size; i++)
	{
		this->elements[i] = elements[i];
	}
}

template<typename T>
inline List<T>::List(const List& list) : capacity(list.capacity), size(list.size)
{
	this->elements = new T[list.capacity];

	for (int i = 0; i < list.size; i++)
	{
		this->elements[i] = list.elements[i];
	}


}

template<typename T>
inline List<T>::~List()
{
	delete[] this->elements;
}

template<typename T>
void List<T>::ResizeArray() {
	this->capacity = (this->capacity + 1) * 2;
	int size = this->capacity;
	int length = this->size;

	T* elements = new T[size];

	for (size_t i = 0; i < length; i++)
	{
		elements[i] = this->elements[i];
	}

	delete[] this->elements;

	this->elements = elements;

	this->capacity = size;
}

template<typename T>
void List<T>::ShiftArrayToRight(const int& index)
{
	for (int i = this->size - 1; i >= index; i--)
	{
		this->elements[i + 1] = this->elements[i];
	}

}

template<typename T>
void List<T>::ShiftArrayToLeft(const int& index)
{
	for (int i = index + 1; i < this->size; i++)
	{
		this->elements[i - 1] = this->elements[i];
	}

	this->elements[this->size - 1] = T();
}

template<typename T>
bool List<T>::NeedResize()
{
	if (this->capacity == this->size) {
		return true;
	}

	return false;
}

template<typename T>
const int List<T>::GetLength() const
{
	return this->size;
}

template<typename T>
const int List<T>::GetCapacity()const
{
	return this->capacity;
}

template<typename T>
T List<T>::GetElement(const int& index)const
{
	if (this->size <= index) {
		return T();
	}

	return this->elements[index];
}

template<typename T>
const bool List<T>::AddElement(const T& element)
{
	if (this->NeedResize())
		this->ResizeArray();

	this->elements[this->size] = element;
	this->size++;

	return true;
}

template<typename T>
const bool List<T>::AddElementOnIndex(const T& element, const int& index)
{
	if (index >= this->size) {
		return false;
	}

	this->ShiftArrayToRight(index);

	this->elements[index] = element;
	this->size++;

	return true;
}

template<typename T>
const bool List<T>::DeleteElement(const int& index)
{
	if (index >= this->size)
		return false;

	this->ShiftArrayToLeft(index);
	this->size--;

	return true;
}

template<typename T>
inline const bool List<T>::DeleteAll()
{
	delete[] this->elements;

	this->elements = new T[0];

	return true;
}

template<typename T>
inline List<T> List<T>::operator=(const List<T>& obj)
{
	if (this != &obj) {
		this->size = obj.size;
		this->capacity = obj.capacity;

		delete[] this->elements;

		this->elements = new T[this->capacity];

		for (int i = 0; i < obj.size; i++)
		{
			this->elements[i] = obj.elements[i];
		}
	}

	return *this;
}

template<typename T>
inline T List<T>::operator[](const int& index) const
{
	if (index >= capacity)
		return T();

	return this->elements[index];
}

