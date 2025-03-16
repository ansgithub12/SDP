#include<stdio.h>
#include<stdlib.h>

// http://www.cplusplus.com/forum/beginner/2680/
struct node
{
	int data;
	struct node*next=NULL;
}*head=NULL;

struct node*newnode;
struct node*createnode();
void create(struct node*newnode);
void createlast(struct node*newnode);
void createafter(struct node*newnode);
void deletefirst(struct node*newnode);
void display();

int main()
{
	int n,i=0;
	while(n!=10)
	{
		printf("*******OPERATIONS******* \n 1.Create \n 2.Display \n 3.Create last \n 4.Create After \n 5.Delete first \n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:newnode=createnode();
		    create(newnode);
			break; 
			
			case 2:display();
			break;
			
			case 3:createlast(newnode);
			break;
			
			case 4:createafter(newnode);
			break;
			
			case 5:deletefirst(newnode);
			break;
		}
	}
}

struct node*createnode()
{
	int d;
	newnode=(struct node*)malloc(sizeof(struct node*));
	printf("\n Enter Data \n");
	scanf("%d",&d);
	newnode->data=d;
	newnode->next=NULL;
	return newnode;
}

void create(struct node*newnode)
{
	struct node*temp=head;
        if(head==NULL)
        {
        	head=newnode;
        	head->next=head;
		}
		else
		{
			temp=head;
			while(temp->next!=head)
			{
				temp=temp->next;
			}
			newnode->next=head;
			temp->next=newnode;
			head=newnode;
		}
	printf("\n node added \n"); 	
}

void display()
{
	struct node *temp=head;

	while(temp->next!=head)
	{
		printf("\t %d \n",temp->data);
		temp=temp->next;	
	}
   	printf("\t %d \n",temp->data);
}

void createlast(struct node*newnode)
{
	struct node *temp=head;
	if(head==NULL)
    {
    	head=newnode;
    	head->next=head;
	}
	else
	{
	   while(temp->next!=head)
	    {
		   temp=temp->next;
	    }
	newnode->next=head;
	temp->next=newnode;	
    } 
}

void createafter(struct node*newnode)
{
	int e;
	struct node *temp=head;
	printf("\n Enter Node \n");
	scanf("%d",&e);
	newnode=(struct node*)malloc(sizeof(struct node*));
	while(temp->data!=e)
	{
		temp=temp->next;
	}
	newnode->next=temp->next;
	temp->next=newnode;		
}

void deletefirst(struct node*newnode)
{
	struct node *temp=head;
	if(head==NULL)
    {
       printf("\n Empty \n");
	}
	if(head->next==head)
	{
		free(temp);
		head=NULL;
	}
	else
	{
		while(temp->next!=head)
	    {
		   temp=temp->next;
	    }
	    temp->next=head->next;
	    head=head->next;
	    free(temp->next);
	}
}

