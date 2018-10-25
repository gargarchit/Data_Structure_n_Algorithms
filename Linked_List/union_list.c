#include<stdio.h>

#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

typedef struct node NODE;

NODE *head1=NULL;

NODE *head2=NULL;

NODE *getnode(){
	int e;
	NODE *newnode;
	newnode=(NODE*)malloc(sizeof(NODE));

	printf("\nenter the value of the element\n");
	scanf("%d",&e);

	newnode->data=e;
	newnode->next=NULL;
}

NODE* insert_front_end(NODE*head){

	NODE *newnode;

	newnode=getnode();

	newnode->next=head;

	head=newnode;

	display(head);

	return head;
}


NODE* insert_last_end(NODE*head){
	NODE *newnode,*cur;

	if(head==NULL){

		insert_front_end(head);
		return head;
	}

	newnode=getnode();
	cur=head;
	
	while(cur->next!=NULL){
		cur=cur->next;
	}

	cur->next=newnode;

	display(head);

	return head;
}
NODE* delete_front_end(NODE*head){

	if(head==NULL){

		printf("\ndeletion  is not possible as list is already empty");

		return head ;
	}

	NODE*temp;

	temp=head;

	head=temp->next;

	free(temp);

	display(head);

	return head;
}


NODE* delete_last_end(NODE*head){

	NODE *pre,*cur;

	cur=head;

	if(head==NULL){
		printf("\ndeletion is not possible as list is  already empty");

		return head ;
	}

	if(head->next==NULL){

		printf("\nonly one element was in list which has deleted");

		head=NULL;
		free(head);

		return head;
	}

	while(cur->next!=NULL){

		pre=cur;
		cur=cur->next;

	}

	cur=pre->next;

	pre->next=NULL;

	free(cur);

	display(head);

	return head;
}


void display(NODE*head){

	NODE*cur;

	cur=head;

	if(cur==NULL){

		printf("\nlinked list is empty");

		return ;
	}

	while(cur!=NULL){

		printf("%d->",cur->data);

		cur=cur->next;
	}
}


NODE* insert_i_position(NODE*head){

	NODE *newnode,*cur;

	int count,i;

	cur=head;

	count=0;

	if(cur==NULL){

		printf("list is empty so u can insert at only front\n");

		insert_front_end(head);

		return head;
	}

	printf("\nenter the position where you want to insert");

	scanf("%d",&i);

	while(cur->next!=NULL){

		cur=cur->next;

		count++;
	}

	newnode=getnode(head);

	if(i>count+2){

		printf("\ninsertion at thius position is not posibble");

	}

	else if(i==count+2){

		cur->next=newnode;

		display(head);
	}

	else{

		cur=head;

		count=1;

		while(count!=i-1){

			count++;

			cur=cur->next;
		}

		newnode->next=cur->next;

		cur->next=newnode;

		display(head);

		return head;
	}
}


NODE* delete_i_position(NODE*head){

	NODE*prev,*cur;

	int i,count;

	printf("\nenter the position number where you want to delete");

	scanf("%d",&i);

	count=1;

	cur=head;

	if(cur==NULL){

		printf("\nlist is empty");

		return head;
	}

	if(cur->next==NULL){

		if(i==1){

			head=head->next;

			free(cur);

			printf("\nthe only element of the list has been deleted");

			return head;
		}		

		 else{

			printf("\noperation cannot be performed");

				return head;
		 }
	}

	while(cur!=NULL){

		cur=cur->next;

		count++;

	}

	if(count<i){

		printf("\ndeleteion is not possible as i postion is not exist");

		return head;
	}

	else{
		cur=head;

		count=1;

		while(count!=i){

			count++;

			prev=cur;

			cur=cur->next;

		}

		prev->next=cur->next;

		free(cur);

		display(head);

		return head;
	}
}


NODE* union_list(){


    NODE *cur,*prev,*head;

    head=NULL;

    cur=NULL;

    if(head1->data ==head2->data){
     
	    cur=head1;
  
	    head=cur;

      	    head1=head1->next;
	  
	    prev=head;

      	    cur=cur->next;
     
	    head2=head2->next;

    }

    else if(head1->data > head2->data){

      	    cur=head2;
     
	    head=cur;
 
       	    head2=head2->next;
    
	    prev=head;
 
       	    cur=cur->next;

    }


    else  if(head1->data < head2->data){
    
	    cur=head1;

      	    head=cur;
    
	    head1=head1->next;

      	    prev=head;
     
	    cur=cur->next;

    }


 	while(head1!=NULL&&head2!=NULL){


       		   if(head1->data ==head2->data){
    		

			   cur=head1;

			   prev->next=cur;
                	 
			   head1=head1->next;
              		  
			   prev=cur;

			   cur=cur->next;
               		 
			   head2=head2->next;
        	
		   }

 		
		   else if(head1->data > head2->data){
        	  
		   	   cur=head2;

			   prev->next=head2;
                

			  head2=head2->next;
			 
			  prev=cur;
                	
		
			  cur=cur->next;
		}

		
		   else if(head1->data < head2->data){
                	 
			 
			 cur=head1;
               	
	      		 head1=head1->next;

			 prev->next=cur;
			 
			 prev=cur;

    
			 cur=cur->next;
      		 }



	}
	
	  if(head1==NULL){
	
	  	  cur=head2;
       		
	  
	  	  return head;
	 
	  }


	if(head2==NULL){
        
		cur=head1;
      		
	      	return head;
	}


}

int main(){
        int ch;
        NODE* head;
	printf("list element should be sorted ");
        while(1){
                printf("\nyou can choose among following operation");
                printf("\n1.insert at front in 1st list\n2.insert at end in 1st list\n3.delete at frontin first list\n4.deletet at end in first list\n5.insert at ith positio in first list\n6. delete at ith positionin 1st list\n");
		printf("7.display 1st list");
		printf("\n 8.insert at front in 2nd list \n 9.insert at end in the 2nd list\n10.delete at front in 2nd list\n11.delete at end in 2nd list\n12.insert at ith position in the 2nd list\n13. delete at ith position in the 2nd list\n14.display 2nd list\n15. union of the  lists\16.exit\n");
                printf("\nenter your choice\n");
                scanf("%d",&ch);

                if(ch>=16){
                        return;
                }


                switch(ch){

                        case 1:
                                head1=insert_front_end(head1);
                                break;

                        case 2 :
                                head1=insert_last_end(head1);
                                break;

			case 3 :
				head1=delete_front_end(head1);
				break;

			case 4 :
				delete_last_end(head1);
				break;

			case 5 :
				head1=insert_i_position(head1);
				break;

			case 6 :
				head1=delete_i_position(head1);
				break;

			case 7 :
				display(head1);
				break;

			case 8:
                                head2=insert_front_end(head2);
                                break;

                        case 9 :
                                head2=insert_last_end(head2);
                                break;

                        case 10:
                                head2=delete_front_end(head2);
                                break;

                        case 11:
                                delete_last_end(head2);
                                break;

                        case 12:
                                head2=insert_i_position(head2);
                                break;

                        case 13:
                                head2=delete_i_position(head2);
                                break;

                        case 14 :
                                display(head2);
				break;

			case 15 :
				head=union_list();
  			        display(head);
		}
	}
}
