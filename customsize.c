#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include <math.h>
extern int errno;
int main(int narg,char** argv)
{     
    int fd = open(argv[1], O_RDONLY ); 
    char a;
    if (fd ==-1)
    {
        // print which type of error have in a code
        printf("Error Number % d\n", errno); 
                    
    }
    /* fd is file descriptor i.e pointer pointing to the file, 0 is offset from begining of the file and SEEK_BEG is start from beginning there 
    can be SEEK_CUR SEEK_END*/
    int sizeoffile = lseek(fd,0,SEEK_END);
    struct stat fi;
    stat(argv[1], &fi);
    int blocksize=fi.st_blksize;
    /*Offset is 0 + End of file therefore start reading from beginning till this offset i.e no of bytes returned.*/
    //SEEK_SET from beginnning of the file and SEEK_CUR from current location of the file.
    printf("%d      %d\n",blocksize,sizeoffile);
    float m = blocksize/(512);
    float size = ceil((float)sizeoffile/(float)blocksize)*m;
    printf("%f\n",size);
    close(fd);
    return 0;
}
