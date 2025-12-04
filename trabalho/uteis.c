#include "uteis.h"
#include <stdlib.h>

void limparEcra(void) {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
