enum class JSONType {
	JSONObject = 1,
	JSONArray = 2,
};

#pragma once
template<class T>
class JSONBase
{
public:

	virtual JSONType GetType() const = 0;

	virtual void Print() = 0;
};

