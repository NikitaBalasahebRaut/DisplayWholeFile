// Application which accepts file name from user and display whole file on screen

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

void DisplayWholeFile(char Fname[])
{
  	int fd = 0;
	char arr[100] = {'\0'};
	int iRet = 0;
	
	fd = open(Fname,O_RDWR);
	
	if(fd == -1)
	{
		printf("Unable to open the file\n");
		return;
	}
	
	printf("Data from file is :\n");
	
	while((iRet = read(fd,arr,100)) != 0)
	{
		write(1,arr,iRet);
	}
	close(fd);
}

int main()
{
	char name[30] = {'\0'};
	
	printf("Enter the file name \n");
	scanf("%s",name);

   DisplayWholeFile(name);
   
return 0;
}

/*

output

D:\ProgramTopicWise\LB\8File_Handling\DisplayWholeFile>myexe
Enter the file name
InfoWeb.txt
Data from file is :

my name is nikita raut
my college name is janta vidhayalay pohregaon

*/