#include "List.h"

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
void List<T>::Shift_Array_To_Right(int index)
{
	for (int i = this->length - 1; i >= index; i--)
	{
		this->elements[i + 1] = this->elements[i];
	}

}

template<typename T>
void List<T>::Shift_Array_To_Left(int index)
{
	for (int i = index + 1; i < this->length; i++)
	{
		this->elements[i - 1] = this->elements[i];
	}

	this->elements[this->elements - 1] = T();
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
T List<T>::Get_Element(int index)
{
	if (this->length <= index) {
		return T();
	}

	return this->elements[index];
}

template<typename T>
bool List<T>::Add_Element(T element)
{
	if (this->Need_Resize())
		this->Resize_Array();

	this->elements[this->length - 1] = element;
	this->length++;

	return true;
}

template<typename T>
bool List<T>::Add_ElementOnIndex(T element, int index)
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
bool List<T>::Delete_Element(int index)
{
	if (index >= this->length)
		return false;

	this->Shift_Array_To_Left(index);
	this->length--;

	return true;
}