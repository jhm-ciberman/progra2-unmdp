#include "colas.h"

int vaciaC (TCola C) 
{

	return C.pri == -1;

}

void sacaC(TCola *C, TElementoC* dato) 
{

	if (!vaciaC(*C)) 
	{

		*dato = (*C).datos[(*C).pri];

		if ((*C).pri == (*C).ult)
		{

			iniciaC(C);

		}
		else
		{

			(*C).pri += 1;

		}

	}

}

TElementoC consultaC (TCola C)
{
	
	if (C.pri != -1) {
		
		return C.datos[C.pri];
		
	}
	//else  return -1;
	
}