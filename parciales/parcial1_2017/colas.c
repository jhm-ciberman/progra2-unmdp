#include "colas.h"

void iniciaC(TCola *c) {
    c->pri = -1;
    c->ult = -1;
}

void poneC (TCola *c, TElementoC dato) {
    if (c->ult < COLA_MAX+1) {
        c->datos[++c->ult] = dato;
        if (c->pri == -1) {
            c->pri = 0;
        }
    }
}

void sacaC(TCola *c, TElementoC* dato)  {
	if (!vaciaC(*c)) {
		*dato = (*c).datos[(*c).pri];
		if ((*c).pri == (*c).ult) {
			iniciaC(c);
		} else {
			(*c).pri += 1;
		}
	}
}

TElementoC consultaC (TCola c) {
    TElementoC basura;
	if (c.pri != -1) {
		return c.datos[c.pri];
	}
	else
        return basura; //Evitar warnings!
}

int vaciaC (TCola c) {
	return c.pri == -1;
}
