#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
extern int errno;

int main(int narg,char** argv)
{     
    // if file does not have in directory 
    // then file foo.txt is created.
    printf("%s\n",argv[1]);
    int fd = open(argv[1], O_RDONLY); 
    char a[2],c;
    printf("fd = %d\n", fd);
    //fd is the file descriptor which ponts to the table containning file pointers
    if (fd ==-1)
    {
        // print which type of error have in a code
        printf("Error Number % d\n", errno);                  
    }
    else
	{
		while(read(fd,a,2) > 0)/*It tells us no of bytes read and returns number of bytes that are actually read stored inn a Basically we are reading byte by byte till end of file is reached*/
		{
			//printf("%c",a[0]);
			//write(1,"BSw",3);
			write(1,&a[0],1);
		}
	}
	close(fd);	
    return 0;
}

