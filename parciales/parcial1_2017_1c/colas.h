
#define COLA_MAX 30

typedef char StringFecha[9];

typedef struct TElementoC {
    StringFecha fecha;
} TElementoC;

typedef struct TCola {
    TElementoC datos[COLA_MAX];
    int pri;
    int ult;
} TCola;

void iniciaC(TCola *c);
void poneC (TCola *c, TElementoC dato);
void sacaC(TCola *c, TElementoC* dato);
TElementoC consultaC(TCola c);
int vaciaC(TCola c);
