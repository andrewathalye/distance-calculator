#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	if(argc != 4) {
		printf("Usage: %s x y z\n", argv[0]);
		exit(-1);
	}
	double origx=atof(argv[1]);
	double origy=atof(argv[2]);
	double origz=atof(argv[3]);

	char line[500];
	char* tmp;
	double x;
	double y;
	double z;
	double d;
	while(1) {
		if(!fgets(line, 500, stdin))
			break;
		if(!(tmp=strtok(line, " ")))
			break;
		x=atof(tmp);
		if(!(tmp=strtok(NULL, " ")))
			break;
		y=atof(tmp);
		if(!(tmp=strtok(NULL, " ")))
			break;
		z=atof(tmp);
		d=sqrt(pow(x - origx, 2) + pow(y - origy, 2) + pow(z - origz, 2));		
		printf("%lf\n", d);
	}
	return 0;
}

