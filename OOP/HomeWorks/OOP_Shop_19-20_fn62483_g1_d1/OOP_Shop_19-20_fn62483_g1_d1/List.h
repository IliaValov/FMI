#pragma once

template<typename T>
class List
{
private:
	T* elements;

	int size = 0;
	int length = 0;

	void Resize_Array();

	void Shift_Array_To_Right(const int& index);
	void Shift_Array_To_Left(const int& index);

	bool Need_Resize();


public:
	List();
	List(const T elements[], const int& size);
	List(const List& list);
	~List();

	int Get_Length();

	int Get_Size();

	T Get_Element(const int& index);

	bool Add_Element(const T& element);
	bool Add_ElementOnIndex(const T& element,const int& index);

	bool Delete_Element(const int& index);

	bool Delete_All();

	List<T> operator =(const List<T>& obj);
	T operator[](const int&);
};

template<typename T>
List<T>::List()
{
	this->elements = new T[0];
}

template<typename T>
List<T>::List(const T elements[], const int& size)
{
	this->elements = new T[size];

	this->size = size;
	this->length = size;

	for (int i = 0; i < this->length; i++)
	{
		this->elements[i] = elements[i];
	}
}

template<typename T>
inline List<T>::List(const List& list)
{
	this->length = list.length;
	this->size = list.size;

	this->elements = new T[this->size];

	for (int i = 0; i < list.length; i++)
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
void List<T>::Resize_Array() {
	this->size = (this->size + 1) * 2;
	int size = this->size;
	int length = this->length;

	T* elements = new T[size];

	for (size_t i = 0; i < length; i++)
	{
		elements[i] = this->elements[i];
	}

	delete[] this->elements;

	this->elements = elements;

	this->size = size;
}

template<typename T>
void List<T>::Shift_Array_To_Right(const int& index)
{
	for (int i = this->length - 1; i >= index; i--)
	{
		this->elements[i + 1] = this->elements[i];
	}

}

template<typename T>
void List<T>::Shift_Array_To_Left(const int& index)
{
	for (int i = index + 1; i < this->length; i++)
	{
		this->elements[i - 1] = this->elements[i];
	}

	this->elements[this->length - 1] = T();
}

template<typename T>
bool List<T>::Need_Resize()
{
	if (this->size == this->length) {
		return true;
	}

	return false;
}

template<typename T>
int List<T>::Get_Length()
{
	return this->length;
}

template<typename T>
int List<T>::Get_Size()
{
	return this->size;
}

template<typename T>
T List<T>::Get_Element(const int& index)
{
	if (this->length <= index) {
		return T();
	}

	return this->elements[index];
}

template<typename T>
bool List<T>::Add_Element(const T& element)
{
	if (this->Need_Resize())
		this->Resize_Array();

	this->elements[this->length] = element;
	this->length++;

	return true;
}

template<typename T>
bool List<T>::Add_ElementOnIndex(const T& element,const int& index)
{
	if (index >= this->length) {
		return false;
	}

	this->Shift_Array_To_Right(index);

	this->elements[index] = element;
	this->length++;

	return true;
}

template<typename T>
bool List<T>::Delete_Element(const int& index)
{
	if (index >= this->length)
		return false;

	this->Shift_Array_To_Left(index);
	this->length--;

	return true;
}

template<typename T>
inline bool List<T>::Delete_All()
{
	delete[] this->elements;

	this->elements = new T[0];

	return true;
}

template<typename T>
inline List<T> List<T>::operator=(const List<T>& obj)
{
	if (this != &obj) {
		this->length = obj.length;
		this->size = obj.size;

		delete[] this->elements;

		this->elements = new T[this->size];

		for (int i = 0; i < obj.length; i++)
		{
			this->elements[i] = obj.elements[i];
		}
	}

	return *this;
}

template<typename T>
inline T List<T>::operator[](const int& index)
{
	if (index >= size)
		return T();

	return this->elements[index];
}

