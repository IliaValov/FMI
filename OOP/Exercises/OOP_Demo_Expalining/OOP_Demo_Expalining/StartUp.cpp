#include <iostream>
#include "�angerine.h"

int main() {
	�angerine tangerine1("Orange", "Medium", "Sweet");

	//������� 1
	�angerine coppy(tangerine1.Get_Color(), tangerine1.Get_Size(), tangerine1.Get_Taste());
		
	//������� 2
	coppy.Set_Color(tangerine1.Get_Color());
	coppy.Set_Size(tangerine1.Get_Size());
	coppy.Set_Taste(tangerine1.Get_Taste());

	//������� 3 � coppy constructor
	�angerine coppy2(tangerine1);
}