#pragma once
#include <cstring>
#include <iostream>
#include "String.h"
#include "JSONBase.h"

template <class T>
class JSONObject : public JSONBase<T> {
private:
	const JSONType jsonType = JSONType::JSONObject;

	String key;
	T value;
public:

	void set_key(const String& key);
	void set_value(T value);

	const String& get_key() const;
	T get_value() const;

	// Inherited via JSONBase
	JSONType GetType() const override;
	void Print() override;
};



template<class T>
inline void JSONObject<T>::set_key(const String& key)
{
	this->key = key;
}

template <class T>
void JSONObject<T>::set_value(T value)
{
	this->value = value;
}

template <class T>
const String& JSONObject<T>::get_key() const
{
	return this->key;
}

template <class T>
T JSONObject<T>::get_value() const
{
	return this->value;
}

template<class T>
inline JSONType JSONObject<T>::GetType() const
{
	return this->jsonType;
}

template<class T>
inline void JSONObject<T>::Print()
{
	std::cout << "\"" << this->key << "\": " << this->value << "\r\n";
}

