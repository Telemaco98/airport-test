#include "stdio.h"
#include "stdlib.h"                                                                                                                                                             

#include "Airport_ctx.h"
#include "Airplane.h"
#include "Airport.h"


void add_planes () {
	printf("\n \t Adding planes... \n");

	Airport_ctx__AIRPLANE aa = 10;
	Airplane__add_plane(aa);

	bool bb;
	Airplane__has_airplane(aa, &bb);
	printf("%d\n", bb);
}



int main () {
    printf("+------- B-method: Airport --------+\n");

    printf("\n \t Initialization... \n");
	Airport__INITIALISATION();

	add_planes();

	// printf("\n \t Land plane 0... \n");
	
	Airport_ctx__AIRPLANE aa = 10;
	// Airport__land(aa, 0);

	// bool *bb;
	// Airport__can_landing(0, bb);
	// printf("Pode pousar na pista 0?: %d", (*bb));

    return 0;
}
