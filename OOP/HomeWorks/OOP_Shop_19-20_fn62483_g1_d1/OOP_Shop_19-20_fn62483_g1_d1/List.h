#pragma once
template<typename T>
class List
{
private:
	T* elements = new T[0];

	int size = 0;
	int length = 0;

	void Resize_Array();

	void Shift_Array_To_Right(int index);
	void Shift_Array_To_Left(int index);

	bool Need_Resize();


public:
	int Get_Length();

	int Get_Size();

	T Get_Element(int index);

	bool Add_Element(T element);
	bool Add_ElementOnIndex(T element, int index);

	bool Delete_Element(int index);
};


