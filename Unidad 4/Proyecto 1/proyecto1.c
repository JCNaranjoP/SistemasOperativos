#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>




void printPath(char dir[30],int tabs){
	DIR *streamp;
	struct dirent *dep;
	streamp = opendir(dir);

	
	while ((dep = readdir(streamp)) != NULL) {
		for(int i=0;i<tabs;i++){
			printf(" ");
		}
		printf("%s\n", dep->d_name);
		if(dep->d_type == 4){
			if(dep->d_name[0] != '.'){
				char dirT[100];
				strcpy(dirT,dir);
				if(dirT[strlen(dirT)-1]!='/'){
					sprintf(dirT,"%s%s",dirT,"/");
				}
				sprintf(dirT,"%s%s\0",dirT,dep->d_name);
				printPath(dirT,tabs+1);
			}
		}
	}
	

	closedir(streamp);
}


int main(int argc, char **argv)
{

	if (argc != 2) {
		printf("Necesario: %s <pathname>\n", argv[0]);
		exit(1);
	}
	printPath(argv[1],0);

    exit(0);
}
