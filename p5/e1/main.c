#include <stdio.h>
#include <stdlib.h>
#include "piladinamica.h"
#include "pilaestatica.h"
#include "colaestatica.h"
#include "coladinamica.h"

int main()
{
    printf("Starting tests\n");
    pilad_tests();
    pilae_tests();
    colad_tests();
    colae_tests();
    printf("All tests passed\n");
    return 0;
}
