#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
extern int errno;
int main(int narg,char** argv)
{     
    // if file does not have in directory 
    // then file foo.txt is created.
    int sfd = open(argv[1], O_RDONLY ); 
    int dfd = open(argv[2], O_WRONLY | O_CREAT);
	if(narg!=3)
	{
		printf("Invalid number of arguements\n");
		exit(1);
	}
	if(strcmp(argv[1],argv[2])==0)
	{
		printf("Source and destination file cant be same!\n");
		exit(1);
	}
    ftruncate(dfd,0);
    //printf("fd = %d/n", fd);
    //printf("%s    %s",argv[1],argv[2]);
    char a;
    if (sfd ==-1)
    {
        // print which type of error have in a code
        printf("Error Number % d\n", errno); 
        
        // print program detail "Success or failure"
        //perror("Program");                 
    }
    while(read(sfd,&a,1) >0)
	{
		//printf("%c ",a);
		write(dfd,&a,1);
	}
	
	remove(argv[1]);
	close(dfd);
    return 0;
}
