#pragma once
#include "JsonObject.h"
#include "JsonArray.h"
#include "String.h"
#include <fstream>

template<class T>
class Json
{
private:
	JsonArray<T> jsonArray;

public:

	const T GetValueByKey(const String& key);

	bool AddJsonObject(const JsonObject<T>& jsonObject);
	bool AddJsonObjectByKeyValue(const String& key, const T& value);

	bool DeleteJsonObjectByKey(const String& key);
	bool DeleteJsonObjectByIndex(const int& index);

	//const String GetJson();

	friend std::ostream& operator<<(std::ostream& os, const Json<T>& obj)
	{
		os << "{\r\n	" << obj.jsonArray << "\r\n}";

		return os;
	}

	bool PrintJsonToFile(String path, String fileName);

};

template<class T>
inline const T Json<T>::GetValueByKey(const String& key)
{
	return this->jsonArray.GetValueByKey(key);
}

template<class T>
inline bool Json<T>::AddJsonObject(const JsonObject<T>& jsonObject)
{
	return this->jsonArray.AddJsonObject(jsonObject);
}

template<class T>
inline bool Json<T>::AddJsonObjectByKeyValue(const String& key, const T& value)
{
	return this->jsonArray.AddJsonObjectByKeyValue(key, value);
}


template<class T>
inline bool Json<T>::DeleteJsonObjectByKey(const String& key)
{
	return this->jsonArray.DeleteJsonObjectByKey(key);
}

template<class T>
inline bool Json<T>::DeleteJsonObjectByIndex(const int& index)
{
	return this->jsonArray.DeleteJsonObjectByIndex(index);
}

template<class T>
inline bool Json<T>::PrintJsonToFile(String path, String fileName)
{


	String temp = path;

	temp.Append('/');
	temp.Append(fileName);

	const char* text = temp.GetString();
	std::ofstream file(text);

	file << *this;

	file.flush();
	file.close();

	return true;
}

//template<class T>
//inline const String Json<T>::GetJson()
//{
//	return this->jsonArray.GetJsonArray();
//}

