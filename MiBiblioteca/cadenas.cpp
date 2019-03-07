#include "stdafx.h"

int cadLong(char *cad) {
	if (*cad == 0) return 0;
	int i = 1;
	while (cad[i++] != 0);
	return i;
}