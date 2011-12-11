#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAXLENGTH 1000

void main(){
  int *subject,*user,i,fp;
  char buffer[255],dem,*pbuf;
  subject = (int *)malloc(MAXLENGTH*sizeof(int));
  user = (int *)malloc(MAXLENGTH*sizeof(int));

  printf("欢迎使用简易推荐系统(C语言版本)\n");
  printf("********************************\n");
  fp=open("data.dat","O_RDONLY");
  i=0;
  dem=",";
  while(read(fp,buffer,256)){
    user[i]=atoi(buffer);
    pbuf=strtok(buffer,dem);
    subject[i]=atoi(pbuf);
  }
  close(fp);
}
