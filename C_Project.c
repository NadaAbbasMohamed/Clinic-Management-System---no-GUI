#include<stdio.h>
#include<stdlib.h>

// standard data types declairation:
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

const u16 password=1234;	// to prevent magic number

// node struct definition:
struct
{
	u8 Name[12];
	u8 age; 
	u8 gender[7];
	u8 id;
	
	struct node * nptr;
}node;
struct node * head=NULL;
struct node * tail=NULL;

// functions prototypes:
void LL_vidAddPatient(void);

void main(void)
{
	//variables declairation:
	u16 mode=0, pass=0;
	u8 i=0;
	
	printf("Select mode to start: \n\n");
	printf("- ADMEN MODE \t\t 1 \t\t - CLIENT MODE \t\t 2 \n\n");
	printf("Your Choice: ");
	scanf("%d",&mode);
	
	if(mode==1 || mode==2)
	{
		switch(mode)
		{
			case 1:
			{
				while(i<3)
				{
					printf("Please Enter the PassWord: ");
					scanf("%d", &pass);
					if(pass==password)
					{	i=5;	}
					else if(pass!=password)
					{
						printf("Invalied Password \n\n");
						i++;
						if(i==3)
						{
							printf("Exceeded The number of trials");
						}
					}
				}
				
				if(pass==password)
				{
					
				}
				break;
			}
		}
	}
	else
	{
		printf("Unvalied Choice - Restart the program");
	}
}


void LL_vidAddPatient(void)
{
	
}