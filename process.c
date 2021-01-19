#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_ITER 65536
#define SIZE 256

int main(int argc, char *argv[]) {
	if(argc<5) {
		printf("Usage: %s DATA DIST SORT NUM\n", argv[0]);
		exit(0);
	}

	FILE *data = fopen(argv[1], "r");	
	FILE *dist = fopen(argv[2], "r");	
	FILE *sort = fopen(argv[3], "r");
	char buf[SIZE];
	char buf2[SIZE];
	int i; /*Iterator for sort*/
	int i2; /*Iterator for dist*/
	int i3; /*Iterator for data*/
	char * time;
	char * player;

	for(i=0; i<atoi(argv[4]); i++) {
		fgets(buf, SIZE, sort);	

		rewind(dist);
		for(i2=0; i2<MAX_ITER; i2++) {	
			fgets(buf2, SIZE, dist);		
			if(!strcmp(buf, buf2))	
				break;
		}

		rewind(data);
		for(i3=0; i3<=i2; i3++)
			fgets(buf2, SIZE, data);

		time=strtok(buf2, " ");
		player=strtok(NULL, " ");
		printf("%s %s %s", time, player, buf);
	}

	fclose(data);
	fclose(dist);
	fclose(sort);
	return 0;
}
