#include<stdio.h>
#include<stdlib.h>

// standard data types declairation:
typedef unsigned char u8;
typedef unsigned short int u16;

// global variables declairation:
const u16 password=1234;	// to prevent magic number
u8 slots[5];
u8 ID;
u8 Index;

// functions prototypes:
void LL_vid_NewRecord(void);
struct node* LL_ptr_IDSearch(u8 key);
void LL_vid_EditRecord(void);
void LL_vid_viewRecord(void);
void arr_vid_viewSlots(void);
void arr_vid_reserveSlot(void);
void arr_vid_dayRes(void);
u8 arr_vid_cancelReservation(void);

// struct declairation:
struct node
{
	u8 name[12];
	u8 age; 
	u8 gender[10];
	u8 id;
	
	struct node * nptr;
};
struct node * head=NULL;
struct node * tail=NULL;

void main(void)
{
	// variables declairation:
	u16 mode=0, pass=0, selection=0, selection2=0;
	u8 i=0, id;
	u8 patient_id;	//func-2 /ask user for it
	
	// initializing time slots:
	for(i=0;i<5;i++)
	{	slots[i]=(i+1);	}
	
	// start program:
	printf("Select mode to start: \n\n");
	printf("- ADMEN MODE \t\t 1 \t\t - CLIENT MODE \t\t 2 \n\n");
	printf("Your Choice: ");
	scanf("%d",&mode);
	
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
					{	printf("Exceeded The number of trials");
						break;
					}
				}
			}
			while(1)
			{
				if(pass==password)
				{
					printf("ADMEN MODE: \n");
					printf("----------- \n\n");
					printf("Select Operation:\n\n");
					printf("- Create new patient record  1 \n");
					printf("- Edit patient record        2 \n");
					printf("- Add slot reservation       3 \n");
					printf("- Cancle reservation         4 \n\n");
					printf("Your Choice: ");
					scanf("%d",&selection);
				
					switch(selection)
					{
						case 1:
						{
							LL_vid_NewRecord();
							printf("___________________________________\n");
							printf("\n\n");
							break;
						}
						case 2:
						{
							LL_vid_EditRecord();
							printf("___________________________________\n");
							printf("\n\n");
							break;
						}
						case 3:
						{
							arr_vid_viewSlots();
							printf("___________________________________\n");
							printf("\n\n");
	
							arr_vid_reserveSlot();
							printf("___________________________________\n");
							printf("\n\n");
							break;
						}
						case 4:
						{
							arr_vid_viewSlots();
							printf("___________________________________\n");
							printf("\n\n");
	
							id =arr_vid_cancelReservation();
						
							if(id!=0)
							{	
								printf("ID not found - Retry \n");	
								printf("___________________________________\n");
								printf("\n\n");
							}
							else
							{
								arr_vid_viewSlots();
								printf("___________________________________\n");
								printf("\n\n");	
							}
							break;
						}
						default:
						{
							printf("Unvalied Choice - Restart the program");
							break;
						}
					}
				}
		
			}
			break;
		}
		
		case 2:
		{
			printf("CLIENT MODE: \n");
			printf("----------- \n\n");
			printf("Select Operation:\n\n");
			printf("- View Patient Record        1 \n");
			printf("- View Today's Reservations  2 \n\n");
			printf("Your Choice: ");
			scanf("%d",&selection2);	
			switch(selection2)
			{
				case 1:
				{
					LL_vid_viewRecord();
					printf("___________________________________\n");
					printf("\n\n");
					break;
				}
				case 2:
				{
					arr_vid_dayRes();
					printf("___________________________________\n");
					printf("\n\n");
					break;
				}
				default:
				{
					printf("Unvalied Choice - Restart the program");
					break;
				}
			}
			break;
		}
		
		default:
		{
			printf("Unvalied Choice - Restart the program");
			break;
		}
		
	}	
}

// functions:

void LL_vid_NewRecord(void)
{
	printf("Create New Patient's Record: \n");
	printf("----------------------------\n");
	struct node *ptr;
	struct node *IDptr;
	ptr =(struct node *)malloc(sizeof(struct node));
	
	if(head==NULL)
	{
		head=ptr;
		tail=ptr;
		ptr->nptr=NULL;
	}
	else
	{
		tail->nptr=ptr;
		tail=ptr;
		tail->nptr=NULL;
	}

	//take struct data
	printf("Enter Patient's Data: \n");
	printf("--------------------- \n");
	printf("Full Name:\t");			// bitgahel l satr da ???
	gets(ptr->name);
	
	printf("\ngender: \t");
	gets(ptr->gender);
	
	printf("\nAge:\t");
	scanf("%d",&(ptr->age));
	
	printf("\nID:\t");
	scanf("%d",&(ptr->id));
	/*
	IDptr = LL_ptr_IDSearch(ptr->id);
		u8 trial=1;
	while(IDptr!=NULL)
	{	
		if(trial==3)
		{
			break;
		}
		else
		{
			printf(" This ID already exist \nRe-enter ID:\t");
			scanf("%d",&(ptr->id));
			IDptr = LL_ptr_IDSearch(ptr->id);
			trial++;
		}
	}
	*/
	// something is wrong in ID search function ??
	printf("\n\nPatient Record is Created\n");
}

struct node* LL_ptr_IDSearch(u8 key)
{
	printf("------ Searching For Patient's ID ------- \n");
	struct node * ptr;
	ptr = head;
	while(ptr->id != key)
	{
		if(ptr==NULL || ptr->nptr==NULL)
		{	break;	}
		ptr = ptr->nptr;
	}
	if(ptr->id == key)
	{	return ptr;		}
	else 
	{	return NULL;	}
}

void LL_vid_EditRecord(void)
{
	printf("Edit Patient's Record: \n");
	printf("----------------------\n");
	struct node * ptr;
	struct node * IDptr;
	u8 ID=0, key=0;
	
	printf("Enter Patient's ID to Find Record: ");
	scanf("%d",&ID);
	ptr = LL_ptr_IDSearch(ID);
	
	while(ptr == NULL)
	{
		printf("ID not found --- Re-eneter ID: ");
		scanf("%d",&ID);
		ptr = LL_ptr_IDSearch(ID);
	}
	
	if(ptr->id == key)
	{
		printf("Patient's Existing Record: \n");
		printf("-------------------------- \n\n");
		
		printf("1- Name: \t %s \n\n",ptr->name);
		printf("2- Gender: \t %s \n\n",ptr->gender);
		printf("3- Age: \t %d \n\n",ptr->age);
		printf("4- ID: \t %d \n\n",ptr->id);
		
		printf("Select data index to change: ");
		scanf("%d",&key);
		switch(key)
		{
			case 1:
				printf("Full Name:\t");
				gets(ptr->name);
				printf("\n\nPatient Record Updated Successfully\n");
				break;
			
			case 2:
				printf("\ngender: \t");
				gets(ptr->gender);			
				printf("\n\nPatient Record Updated Successfully\n");
				break;
				
			case 3:
				printf("\nAge:\t");
				scanf("%d",&(ptr->age));
				printf("\n\nPatient Record Updated Successfully\n");
				break;
				
			case 4:
				printf("\nID:\t");
				scanf("%d",&(ptr->id));
				IDptr = LL_ptr_IDSearch(ptr->id);
				while(IDptr!=NULL)
				{
					printf(" This ID already exist \nRe-enter ID:\t");
					scanf("%d",&(ptr->id));
					IDptr = LL_ptr_IDSearch(ptr->id);
				}
				printf("\n\nPatient Record Updated Successfully\n");				
				break;
				
			default:
				printf("Wrong index selected --- Operation is terminated");
				break;	
		}
	}
	else
	{//for testing
		printf("Something is wrong !!!");
	}
}

void LL_vid_viewRecord(void)
{
	printf("View Patient's Record: \n");
	printf("----------------------\n");
	struct node * ptr;
	struct node * IDptr;
	u8 ID=0, key=0;
	
	printf("Enter Patient's ID to Find Record: ");
	scanf("%d",&ID);
	ptr = LL_ptr_IDSearch(ID);
	
	while(ptr == NULL)
	{
		printf("ID not found --- Re-eneter ID: ");
		scanf("%d",&ID);
		ptr = LL_ptr_IDSearch(ID);
	}
	
	if(ptr->id == key)
	{
		printf("Patient's Record: \n");
		printf("-------------------------- \n\n");
		
		printf("1- Name: \t %s \n\n",ptr->name);
		printf("2- Gender: \t %s \n\n",ptr->gender);
		printf("3- Age: \t %d \n\n",ptr->age);
		printf("4- ID: \t %d \n\n",ptr->id);
	}
}

void arr_vid_viewSlots(void)
{
	u8 i;u8 counter=0;
	printf("Available slots reservations: \n");
	printf("-----------------------------\n");
	for(i=0;i<5;i++)
	{
		switch(i)
		{
			case 0:
			{	if(slots[i]==(i+1))
				{
					counter++;
					printf("%d- 2:00 to 2:30 pm \n",counter);
				}
				break;
			}
			
			case 1:
			{	if(slots[i]==(i+1))
				{
					counter++;
					printf("%d- 2:30 to 3:00 pm \n",counter);
				}
				break;
			}
			
			case 2:
			{	if(slots[i]==(i+1))
				{
					counter++;
					printf("%d- 3:00 to 3:30 pm \n",counter);
				}
				break;
			}
			
			case 3:
			{	if(slots[i]==(i+1))
				{
					counter++;
					printf("%d- 3:30 to 4:00 pm \n",counter);
				}
				break;
			}
			
			case 4:
			{	if(slots[i]==(i+1))
				{
					counter++;
					printf("%d- 4:30 to 5:00 pm \n",counter);
				}
				break;
			}
		}
	}
}

void arr_vid_reserveSlot(void)
{
	struct node * ptr;
	printf("Slot Reservation: \n");
	printf("-----------------\n");
	
	printf("Enter slot index to reserve: ");
	scanf("%d",&Index);
	
	if(Index<=5)
	{
		printf("\nEnter patient's ID: ");
		scanf("%d",&ID);
	
		ptr = LL_ptr_IDSearch(ID);
		while(ptr == NULL)
		{
			printf("ID not found --- Re-eneter ID: ");
			scanf("%d",&ID);
			ptr = LL_ptr_IDSearch(ID);
		}
		
		if(ptr->id == ID)
		{
			for(u8 i=0;i<5;i++)
			{
				if(slots[i]==Index)
				{	slots[i]=ID;	}
			}
		}
		
	}
	else{printf("Incorrect index value");}
}

void arr_vid_dayRes(void)
{
	u8 i;u8 counter=0;
	printf("Reservations of today: \n");
	printf("----------------------\n");
	for(i=0;i<5;i++)
	{
		switch(i)
		{
			case 0:
			{	if(slots[i]!=(i+1))
				{
					counter++;
					printf("%d- 2:00 to 2:30 pm - %d \n",counter,slots[i]);
				}
				break;
			}
			
			case 1:
			{	if(slots[i]!=(i+1))
				{
					counter++;
					printf("%d- 2:30 to 3:00 pm - %d \n",counter,slots[i]);
				}
				break;
			}
			
			case 2:
			{	if(slots[i]!=(i+1))
				{
					counter++;
					printf("%d- 3:00 to 3:30 pm - %d \n",counter,slots[i]);
				}
				break;
			}
			
			case 3:
			{	if(slots[i]!=(i+1))
				{
					counter++;
					printf("%d- 3:30 to 4:00 pm  - %d \n",counter,slots[i]);
				}
				break;
			}
			
			case 4:
			{	if(slots[i]!=(i+1))
				{
					counter++;
					printf("%d- 4:30 to 5:00 pm - %d \n",counter,slots[i]);
				}
				break;
			}
			default:
			{	printf("No Reservation \n");}
		}
	}
}

u8 arr_vid_cancelReservation(void)
{
	printf("Cancle Slot Reservation: \n");
	printf("------------------------\n");
	u8 ID=0; u8 i=0;
	printf("Enter patient ID: ");
	scanf("%d",&ID);
	
	for(i=0;i<5;i++)
	{
		if(slots[i]==ID)
		{	
			printf("Reservation Cancled Successfully \n");
			slots[i]=(i+1);
			return 0;
		}
	}
	return ID;
}


// a5iran