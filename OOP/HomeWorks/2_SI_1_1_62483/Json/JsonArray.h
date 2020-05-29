#pragma once
#include "List.h"
#include "JsonObject.h"
#include "JsonArray.h";

template<typename T>
class JsonArray
{
private:
	List<JsonObject<T>> jsonObjects;

public:

	const int GetLength() const;

	const T GetValueByKey(const String& key);

	bool AddJsonObject(const JsonObject<T>& jsonObject);
	bool AddJsonObjectByKeyValue(const String& key, const T& value);

	bool DeleteJsonObjectByKey(const String& key);
	bool DeleteJsonObjectByIndex(const int& index);

	//const String GetJsonArray();

	friend std::ostream& operator<<(std::ostream& os, const JsonArray<T>& obj)
	{
		os << "[\r\n	";

		for (int i = 0; i < obj.GetLength(); i++)
		{
			os << "\r\n		" << obj.jsonObjects[i];

			if (i < obj.GetLength() - 1) {
				os << ",";
			}
		}

		os << "\r\n	]";

		return os;
	}

};

template<typename T>
inline const int JsonArray<T>::GetLength() const
{
	return this->jsonObjects.GetLength();
}

template<typename T>
inline const T JsonArray<T>::GetValueByKey(const String& key)
{
	for (int i = 0; i < key.GetLength(); i++)
	{
		if (this->jsonObjects[i].GetKey() == key) {
			return this->jsonObjects[i].GetValue();
		}
	}

	return T();
}

template<typename T>
inline bool JsonArray<T>::AddJsonObject(const JsonObject<T>& jsonObject)
{
	for (int i = 0; i < this->jsonObjects.GetLength(); i++)
	{
		if (this->jsonObjects[i].GetKey() == jsonObject.GetKey())
			return false;
	}

	return this->jsonObjects.AddElement(jsonObject);
}

template<typename T>
inline bool JsonArray<T>::AddJsonObjectByKeyValue(const String& key, const T& value)
{
	JsonObject<T> temp(key, value);

	return this->jsonObjects.AddElement(temp);
}

template<typename T>
inline bool JsonArray<T>::DeleteJsonObjectByKey(const String& key)
{
	for (int i = 0; i < this->jsonObjects.GetLength(); i++)
	{
		if (this->jsonObjects[i].GetKey() == key)
			return this->jsonObjects.DeleteElement(i);
	}

	return false;
}

template<typename T>
inline bool JsonArray<T>::DeleteJsonObjectByIndex(const int& index)
{
	return this->jsonObjects.DeleteElement(index);
}

//template<typename T>
//inline const String JsonArray<T>::GetJsonArray()
//{
//	String result = "[";
//
//	for (int i = 0; i < this->jsonObjects.GetLength(); i++)
//	{
//	
//		result = result + "\r\n" + this->jsonObjects[i].GetJsonObject();
//	}
//
//	result = result + "\r\n]";
//
//	return result;
//}

