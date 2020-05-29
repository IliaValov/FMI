#pragma once
#include "JSONObject.h"
#include "JSONBase.h"
#include <cstring>
#include "String.h"
#include "List.h"

template <class T>
class JSONArray : public JSONBase<T> {
private:
	const JSONType jsonType = JSONType::JSONArray;

	List<JSONBase<T>*> array;

public:
	JSONArray();
	JSONArray(const JSONArray& from);
	JSONArray& operator= (const JSONArray& from);
	~JSONArray();

	JSONBase<T> operator[] (const int& pos) const;

	void insert(const String& key, T value);

	void insert(JSONArray<T>& jsonBase);

	void insert(const JSONBase<T>* jsonBase);

	T get_value(const String& key) const;

	int get_size() const;

	JSONType GetType() const override;

	void Print() override;
};

template<class T>
inline JSONArray<T>::~JSONArray()
{
	for (int i = 0; i < this->array.GetLength(); i++)
	{
		delete this->array[i];
	}
}

template<class T>
inline JSONArray<T>::JSONArray()
{
}

template<class T>
inline JSONArray<T>::JSONArray(const JSONArray& from)
{
	this->array = from.array;
}

template<class T>
inline JSONArray<T>& JSONArray<T>::operator=(const JSONArray& from)
{
	if (this != &from) {
		this->array = from.array;
	}

	return *this;
}

template <class T>
JSONBase<T> JSONArray<T>::operator[] (const int& pos) const
{
	return this->array[pos];
}

template <class T>
void JSONArray<T>::insert(const String& key, T value)
{

	JSONObject<T>* temp = new JSONObject<T>;

	temp->set_key(key);
	temp->set_value(value);

	this->array.AddElement(temp);
}

template<class T>
inline void JSONArray<T>::insert(JSONArray<T>& jsonBase)
{
	JSONArray<T>* temp = new JSONArray<T>;
	*temp = jsonBase;

	this->array.AddElement(temp);
}

template<class T>
inline void JSONArray<T>::insert(const JSONBase<T>* jsonBase)
{
	this->array.AddElement(jsonBase);
}

template <class T>
T JSONArray<T>::get_value(const String& key) const
{
	for (int i = 0; i < this->get_size(); i++)
	{
		if (strcmp(key, this->array[i].get_key()) == 0)
		{
			return this->array[i].get_value();
		}
	}
	std::cout << "key not found"; // Exception ?
	return T();
}

template <class T>
int JSONArray<T>::get_size() const
{
	return this->array.size;
}

template<class T>
inline JSONType JSONArray<T>::GetType() const
{
	return this->jsonType;
}

template<class T>
inline void JSONArray<T>::Print()
{
	std::cout << "[\r\n";
	for (int i = 0; i < this->array.GetLength(); i++)
	{
		std::cout << "\r\n    ";
		(*this->array[i]).Print();
		std::cout << "\r\n";
	}
	std::cout << "\r\n]";
}
