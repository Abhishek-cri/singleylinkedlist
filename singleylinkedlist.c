#include<stdio.h>
#include<stdlib.h>
struct node
{
       int data;
       struct node *next;
};
struct node *head=NULL;
struct node *temp,*ptr,*preptr;
struct node *createnode(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_pos(struct node *);
struct node *insert_end(struct node *);
struct node *display(struct node *);
struct node *delete_beg(struct node*);
struct node *delete_pos(struct node*);
struct node *delete_end(struct node*);
int main()
{
       int choices,a;
       do
       {
       printf("WELCOME\n");
       printf("available options are\n");
       printf("1.CREATION\n");
       printf("2.INSERTION AT BEGINNING\n");
       printf("3.INSERTION AT ANY POSITION\n");
       printf("4.INSERTION AT END\n");
       printf("5.DISPLAY\n");
       printf("6.DELETION AT BEGINNING\n");
       printf("7.DELETION AT ANY POSITION\n");
       printf("8.DELETION AT ENDING\n");
       printf("enter your choice\n");
       scanf("%d",&choices);
       switch(choices)
       case 1:
       {
             head=createnode(head);
             printf("node is created successfully\n");
             break;

       case 2:

              head=insert_beg(head);
              printf("new node is inserted at beginning");
              break;

       case 3:

              head=insert_pos(head);
              printf("new node is inserted ");
              break;

       case 4:

              head=insert_end(head);
              printf("new node is inserted at end");
              break;

       case 5:

              head=display(head);
              break;

       case 6:

              head=delete_beg(head);
              printf("node is deleted");
              break;

       case 7:


             head=delete_pos(head);
             printf("node is deleted");
             break;

       case 8:

              head=delete_end(head);
              printf("node is deleted");
              break;
       }

       }while(choices!=9);
       return 0;
}
 struct node *createnode(struct node *head)
{
       struct node *temp,*ptr;
       int data,a;
       printf("enter data");
       scanf("%d",&data);
       ptr=(struct node *)malloc(sizeof(struct node));
       ptr->data=data;
       ptr->next=NULL;
       if(head=NULL)
       {
              ptr->next=head;
              head=ptr;
       }
       else
       {
              head=ptr;
              temp=head;
              printf("press 1 to create more nodes ");
              scanf("%d",&a);
              while(a==1)
              {
                     printf("enter data");
                     scanf("%d",&data);
                     ptr=(struct node*)malloc(sizeof(struct node));
                     ptr->data=data;
                     ptr->next=NULL;
                     temp->next=ptr;
                     temp=temp->next;
                     printf("press 1 to create more nodes");
                     scanf("%d",&a);
              }
       }
       return head;
};
struct node *insert_beg(struct node *head)
{
       struct node *temp,*new_node,*ptr;
       int data;
       printf("enter data you want to enter");
       scanf("%d",&data);
       new_node=(struct node*)malloc(sizeof(struct node));
       new_node->data=data;
       new_node->next=head;
       head=new_node;
       printf("new node is inserted at beginning");
       return head;
};
struct node *insert_pos(struct node *head)
{
       struct node *new_node,*temp,*ptr;
       int data,val;
       printf("enter data after you want to insert data");
       scanf("%d",&val);
       printf("enter data to enter");
       scanf("%d",&data);
       new_node=(struct node *)malloc(sizeof(struct node));
       new_node->data=data;
       ptr=head;
       temp=ptr;
       while(temp->data!=val)
       {
              temp=ptr;
              ptr=ptr->next;
       }
       new_node->next=ptr;
       temp->next=new_node;
       return head;
};
struct node *insert_end(struct node *head)
{
       struct node *ptr,*temp,*new_node;
       int data;
       printf("enter data\n");
       scanf("%d",&data);
       new_node=(struct node *)malloc(sizeof(struct node *));
       new_node->data=data;
       new_node->next=NULL;
       temp=head;
       while(temp->next!=NULL)
       {
              temp=temp->next;
       }
       temp->next=new_node;
       return head;
};
struct node *display(struct node *head)
{
       struct node *temp,*ptr;
       int data;
       temp=head;
       while(temp!=NULL)
       {
              printf("%d\n",temp->data);
              temp=temp->next;
       }
       return head;
};
struct node *delete_beg(struct node *head)
{
       struct node *temp,*ptr;
       temp=head;
       head=head->next;
       free(temp);
       return head;
};
struct node *delete_pos(struct node *head)
{
       struct node *temp,*temp1,*temp2;
       int data,val;
       printf("enter the you want to delete");
       scanf("%d",&val);
       temp=head;
       if(head->data==val)
       {
              head=delete_beg(head);
              return head;
       }
       else
       {
              while(temp->data!=val)
              {
                     temp1=temp;
                     temp=temp->next;
              }
              temp1->next=temp->next;
              free(temp);
              return head;

       }

};
struct node *delete_end(struct node *head)
{
       struct node *ptr,*preptr;
       int data,val;
       ptr=head;
       while(ptr->next!=NULL)
       {
              preptr=ptr;
              ptr=ptr->next;
       }
       preptr->next=NULL;
       free(ptr);
       printf("last node is deleted\n");
       return head;
};

