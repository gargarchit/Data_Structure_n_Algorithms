#include<stdio.h>
#include<stdlib.h>
struct Node
{
        int data;
        struct Node *next;
};
typedef struct Node node;

node *getNode()
{
         node *newnode;
         newnode=(node*)malloc(sizeof(node));
         printf("Enter the data to be stored in the newnode\n");
         scanf("%d",&(newnode->data));
         newnode->next=NULL;
         return newnode;
}

node *head=NULL;
void DisplayList()
{
        if(head==NULL)
        	printf("Empty list\n");
        else{
        	node *temp;
        	temp=head;
        	while(temp!=NULL)
        	{
                	printf("%d ->\n",temp->data);
                	temp=temp->next;
        	}
        	free (temp);
        }
}
void InsertNodeFront()
{
         node *newnode=getNode();
	 newnode->next=head;
         head=newnode;
}

void DeleteNodeFront()
{
        if(head==NULL)
        	printf("Empty List\n");
        else
	{
        	node *temp;
        	temp=head;
        	head=head->next;
        	free (temp);
        }
}


void InsertNodeEnd()
{
        node *cur,*newnode;
        newnode=getNode();
        if(head==NULL)
        {
            head=newnode;
  
	}
	else
        {
        	cur=head;
	
        	while(cur->next!=NULL)
        	{
                	cur=cur->next;
        	}
       
        	cur->next=newnode;
	}
}
void DeleteNodeEnd()
{
        if(head==NULL)
        	printf("Empty list\n");
        else if(head->next==NULL)
                {
			free(head);
                        head=NULL;
		}
        else
         {
        	node *cur,*prev;
        	cur=head;
        	while(cur->next!=NULL)
        	{
	 		prev=cur;
                	cur=cur->next;
        	}
        	prev->next=NULL;
       		 free(cur);
	}	
}
void InsertAtPosition(int i)
{
        if(i==1)
          	InsertNodeFront();
	else
	{
        	int count=1;
        	node *cur,*newnode;
        	newnode=getNode();
        	cur=head;
        	while(count==i-2)
        	{
                	cur=cur->next;
                	i++;
        	}
       	 	newnode->next=cur->next;
        	cur->next=newnode;
	}

}

void DeleteAtPosition(int i)
{
	if(i==1)
        {
		 DeleteNodeFront();
	}
	else
	{
        	int count=i;
        	node *cur,*temp;
      		  cur=head;
        	for(int i=1;i<=count;i++)
        	{	
		        temp=cur;
                	cur=cur->next;
                	i++;
        	}
	temp->next=cur->next;
 	free (cur);
	}

}


int main()
{
     int num=0;	
     int choice=0;
     while(1)
      {
        printf("\n\n\n\nEnter choice\n");
        printf("Enter 1 to insert a node from front \n");
        printf("Enter 2 to delete a node from front \n");
        printf("Enter 3 to insert a node from end \n");
        printf("Enter 4 to delete a node from end \n");
        printf("Enter 5 to display the linked list \n");
        printf("Enter 6 to insert node at position i\n");
        printf("Enter 7 to delete node at position i\n");
	printf("Enter 8 to QUIT\n");


	 scanf("%d",&choice);
        switch(choice)
        {
                 case 1:
                        {
                                InsertNodeFront();
                                DisplayList();
				num++;
                                break;
                        }
                 case 2:
                        {
                                DeleteNodeFront();
                                DisplayList();
				if(head!=NULL)
					{
						num--;
					}
                                break;
                        }
                 case 3:
                        {
                                InsertNodeEnd();
                                DisplayList();
				num++;
                                break;
                        }
                 case 4:
                        {
                                DeleteNodeEnd();
                                DisplayList();
				if(head!=NULL)
                                        {
                                                num--;
                                        }
                                break;
                        }
                 case 5:
                        {
                                DisplayList();
                                break;
                        }
                case 6:
                        {
                                int pos;
                                printf("Enter the position at which you have to insert\n");
                                scanf("%d",&pos);
				if(pos>(num+1)&&(pos!=1))
					{
						printf("Invalid position\n");
						DisplayList();
					}
				else if(pos==num+1)
					{
						InsertNodeEnd();
						DisplayList();
						num++;
					}
				else
					{
                                		InsertAtPosition(pos);
                                  		DisplayList();
						num++;
					}
			       break;
                        }
			
			case 7:
                        {
                                if(head==NULL)
					printf("Empty list");
				else
				{
				int pos;
                                printf("Enter the position at which you have to delete\n");
                                scanf("%d",&pos);
				
				  if((pos>num)||(pos<1))
                                        {
                                                printf("Invalid position\n");
                                        }
				  else if(pos==num)
				  	{
						DeleteNodeEnd();
						num--;
						DisplayList();
					}
                                else
                                        {
						DeleteAtPosition(pos);
                		                DisplayList();
						num--;
					}
				}
                                  break;
                        }
		case 8: exit(0);	 

                default:
                        {
                                printf("Invalid option");
                                break;
                        }

        }
     }
    return 0;
}


