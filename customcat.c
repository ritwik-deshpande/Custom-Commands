#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
extern int errno;
int main(int narg,char** argv)
{     
    //printf("%s   ",argv[1]);
    char a;
    char n='\n';
    int i=1;
    if(narg==1)
    {
    	while(read(0,&a,1) > 0)
		{
			write(1,&a,1);
		}
    }
    else if(narg==2 && argv[1][0]=='>')
    {
    	int size=strlen(argv[1]);
    	char* temp=(char*)malloc(sizeof(char)*(size-1));
    	for(i=0;i<size-1;i++)
    	{
    		temp[i]=argv[1][i+1];
    	}
    	//write(1,&temp,size-1);
    	int fd = open(temp,O_RDONLY | O_CREAT);
		if (fd ==-1)
			{
				// print which type of error have in a code
				printf("Error Number% d\n", errno); 
				                  
			}
			else
			{
				while(read(0,&a,1) > 0)
				{
					write(fd,&a,1);
				}
			}
			close(fd);
    }
    else
    {
		while(i<narg)
		{
			int fd = open(argv[i], O_RDONLY); 
			//printf("fd = %d/n", fd);
			//fd is the file descriptor which ponts to the table containning file pointers
			if (fd ==-1)
			{
				// print which type of error have in a code
				printf("Error Number% d\n", errno); 
				                  
			}
			else
			{
				while(read(fd,&a,1) > 0)/*It tells us no of bytes read and returns number of bytes that are actually read stored inn a Basically we are reading byte by byte till end of file is reached*/
				{
					write(1,&a,1);
				}
			}
			close(fd);
			write(1,&n,1);
			i++;
		}
	}	
    return 0;
}

