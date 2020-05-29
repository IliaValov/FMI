#pragma once
#include "String.h"
#include <iostream>

template<typename T>
class JsonObject
{
private:
	String key;
	T value;

public:
	JsonObject();
	JsonObject(const String& key, const T& value);

	void SetKeyValue(const String& key, const T& value);

	const String GetKey() const;

	const T GetValue() const;

	//const String GetJsonObject();


	friend std::ostream& operator<<(std::ostream& os, const JsonObject<T>& obj) 
	{
		os << "{\r\n			\"" << obj.key << "\":" << obj.value << "\r\n		}";

		return os;
	}


};

template<typename T>
inline JsonObject<T>::JsonObject() : key(""), value(T())
{
}

template<typename T>
inline JsonObject<T>::JsonObject(const String& key, const T& value) : key(key), value(value)
{
}


template<typename T>
void JsonObject<T>::SetKeyValue(const String& key, const T& value)
{
	this->key = key;
	this->value = value;

}

template<typename T>
const String JsonObject<T>::GetKey() const
{
	return this->key;
}

template<typename T>
const T JsonObject<T>::GetValue() const
{
	return this->value;
}

//template<typename T>
//inline const String JsonObject<T>::GetJsonObject()
//{
//	String key = this->key;
//	String value = this->value;
//
//	String result = ("{ \r\n\"" + key) + (("\":" + value) +"\r\n}");
//
//	return result;
//}


