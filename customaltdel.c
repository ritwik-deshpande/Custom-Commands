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
    int fd1 = open(argv[1], O_RDONLY);
    int fd2 = open(argv[1], O_WRONLY);
    char a[2],c;
    printf("fd = %d\n", fd1);
    //fd is the file descriptor which ponts to the table containing file pointers
    if (fd1 ==-1)
    {
        // print which type of error have in a code
        printf("Error Number % d\n", errno);                  
    }
    else
	{
		while(read(fd1,a,2) > 0)/*It tells us no of bytes read and returns number of bytes that are actually read stored inn a Basically we are reading byte by byte till end of file is reached*/
		{
			//printf("%c",a[0]);
			//write(1,&a[0],1);
			write(fd2,&a[0],1);
		}
	}
	int sizeoffile = lseek(fd1,0,SEEK_END);
	ftruncate(fd2,ceil((sizeoffile)/2));
	close(fd1);
	close(fd2);	
    return 0;
}

