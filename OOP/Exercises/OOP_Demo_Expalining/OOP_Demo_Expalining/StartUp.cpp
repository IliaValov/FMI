#include <iostream>
#include "Òangerine.h"

int main() {
	Òangerine tangerine1("Orange", "Medium", "Sweet");

	//Âàğèàíò 1
	Òangerine coppy(tangerine1.Get_Color(), tangerine1.Get_Size(), tangerine1.Get_Taste());
		
	//Âàğèàíò 2
	coppy.Set_Color(tangerine1.Get_Color());
	coppy.Set_Size(tangerine1.Get_Size());
	coppy.Set_Taste(tangerine1.Get_Taste());

	//Âàğèàíò 3 ñ coppy constructor
	Òangerine coppy2(tangerine1);
}