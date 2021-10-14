#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#define TB 100
void allocate();
void deallocate();
void display();
int BFull();
struct Link
{
char n[30];//file name
int len; //size of the file
int st;
struct node
{
int index;
struct node *next;
}*Start,*current,*newnode,*temp;
}F[30];
int Table[TB+1],pos=0,r,i,j,ch,B=0;
char fn[30];
int main()
{
printf("\n-------------------------HOTEL MANAGEMENT SYSTEM---------------------n");
do{
printf("\n\n1.Allocate\n2.Deallocate\n3.Display\n4.Exit");
printf("\n\nEnter Your choice : ");
scanf("%d",&ch);switch(ch)
{
case 1:
pos++;
allocate();
break;
case 2:
deallocate();
break;
case 3:
display();
break;
case 4:
printf("exit");
default:
printf("\nInvalid Choice ");
}
}while(ch!=4);
}
void allocate()
{
printf("\nEnter  Name : ");
scanf("%s",F[pos].n);
printf("\nEnter number of rooms : ");
scanf("%d",&(F[pos].len));
F[pos].Start=NULL;

if(BFull())//checking if the required space is there.(max size=100)
{
pos--;
printf("\n\nNot enough rooms Available \n");
return;
}

for(i=1;i<=F[pos].len;i++) 
{
F[pos].newnode=(struct node *)malloc(sizeof(struct node));
while(1)
{
r=rand()%TB+1; //randomly finding free space and allocating

if(Table[r]==0)  //if that space is free...
{
F[pos].newnode->index =r;
F[pos].newnode->next=NULL; //next node pointer-->NULL
if(F[pos].Start==NULL)
{
F[pos].Start=F[pos].newnode;
F[pos].current=F[pos].newnode;
}
else{
F[pos].current->next=F[pos].newnode;
F[pos].current=F[pos].newnode;
}
Table[r]=1;
break;
}
}
}
F[pos].st=F[pos].Start->index;
for(i=r;i<r+F[pos].len;i++)
Table[i]=1;
printf("\n\tAllocation Table\n");
printf("\nName\tStart\tEnd\tLength\n");
for(i=1;i<=pos;i++)
{
printf("\n%s\t\t%d\t%d\t%d",F[i].n,F[i].st,F[pos].current->index,F[i].len);
printf("\n");
}
}


void deallocate()
{
printf("\nEnter Name : ");
scanf("%s",fn);
for(i=1;i<=pos;i++)
{
if(strcmp(F[i].n,fn)==0){
F[i].current=F[i].Start;
while(F[i].current)
{
Table[F[i].current->index]=0;
F[i].temp=F[i].current;
F[i].current=F[i].current->next;
free(F[i].temp);
}
strcpy(F[i].n,"NULL");
F[i].st=0;
F[i].len=0;
printf("\nvacated \n",fn);
break;
}
else
printf("\nName not registered\n");
}
printf("\n\t\t Allocation Table\n");
printf("\nFileName\tStart\tLength\n");
for(i=1;i<=pos;i++)
{
printf("\n%s\t\t%d\t%d",F[i].n,F[i].st,F[i].len);
printf("\n");
}
}


void display()
{printf("\nEnter Name : ");
scanf("%s",fn);
printf("\nRooms Allocated Are : ");
for(i=1;i<=pos;i++)
{
if(strcmp(F[i].n,fn)==0)
{
F[i].current=F[i].Start;
while(F[i].current)
{
printf(">--%d-->",F[i].current->index); F[i].current=F[i].current->next;
}
break;
}
}
if(i==pos+1)
{
printf("\n\nNot Found\n");
}
}


int BFull()
{
for(i=1,B=0;i<=pos;i++)
B=B+F[i].len;
if(B>TB)
return 1;
else
return 0;
    
}
