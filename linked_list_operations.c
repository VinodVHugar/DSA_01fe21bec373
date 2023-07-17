#include<stdio.h>
#include<stdlib.h>
struct Node
{
 int data;
 struct node *next;
};

typedef struct Node *node;
node head,newnode,temp,cur,prev,del;
int specific_pos;
node addend(node);
node addbeg(node);
node delete_at_specific_pos(node head,int specific_pos);
void display( head);
node deleteend(head);
node deletebeg(head);
node addatspecific_pos(newnode,specific_pos);
node getnode();
node head=NULL;

void main()
{
    int choice;
    while(1)
    {
        printf("1.addend\n 2.addbeg\n 3.display\n 4.deleteend\n 5.deletebeg\n 6.add at specific_pos\n 7.Delete at specific_pos\n 8.exit\n");
        printf("enter choice:\n");
        scanf("%d",&choice);
    switch(choice)
        {
        case 1: head=addend(newnode);break;
        case 2: head=addbeg(newnode);  break;
        case 3:display(head);break;
        case 4:head=deleteend(head);break;
        case 5:head=deletebeg(head);break;
        case 6: printf("enter specific_position\n");
                scanf("%d",&specific_pos);
                        newnode=(struct Node*)malloc(sizeof(struct Node));
                       printf("enter data\n");
                       scanf("%d",&newnode->data);
                        head=addatspecific_pos(newnode,specific_pos);

                    break;
        case 7:printf("enter specific_position\n");
                   scanf("%d",&specific_pos);
                        head=delete_at_specific_pos(head,specific_pos);
                    break;
        case 8:exit(0);break;
        default:printf("invalid input\n");break;
        }
    }
}
node getnode()
{
 newnode=(node)malloc(sizeof(node));
    if(newnode==NULL)
    {
        printf("memory not allocated\n");
        exit(0);
    }
return newnode;
}
node read_details(node newnode)
{
    printf("enter data\n");
    scanf("%d",&newnode->data);
     newnode->next=NULL;
    return newnode;
}
node addend(node newnode)
{
    newnode=getnode();
    newnode=read_details(newnode);
    if(head==NULL)
    {
        head=newnode;
        return(head);
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        return(head);
    }
}
node addbeg(node newnode)
{
    newnode=getnode();
    newnode=read_details(newnode);
    if(head==NULL)
    {
        head=newnode;
        return(head);
    }
    else
    {
        newnode->next=head;
        head=newnode;
        return(head);
    }
}
void display(node head)
{
    if(head==NULL)
    {
        printf("Linked List is empty \n");
        exit(0);
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
node deleteend(node head)
{
    if(head==NULL)
    {
        printf("Linked list is empty\n");
        exit(0);
    }
    else
    {
        if(head->next==NULL)
        {
            printf("deleted=%d\n",head->data);
            free(head);
            head=NULL;
            return(head);
        }
        else
        {
            temp=head;
            cur=head->next;
            while(cur->next!=NULL)
            {
                temp=temp->next;
                cur=cur->next;
            }
            printf("deleted=%d\n",cur->data);
            free(cur);
            temp->next=NULL;
            return(head);
        }
    }
}
node deletebeg(node head)
{
    if(head==NULL)
    {
        printf("LL is empty\n");
        exit(0);
    }
    else
    {
        if(head->next==NULL)
        {
            printf("deleted=%d\n",head->data);
            free(head);
            head=NULL;
            return(head);
        }
        else
        {
            temp=head;
            head=temp->next;
            printf("deleted=%d\n",temp->data);
            free(temp);
            return(head);
        }
    }
}
node addatspecific_pos(node newnode,int specific_pos)
{
    int p;
    node temp1;
    if(specific_pos==1)
        head=addbeg(newnode);
    else
    {
        p=1;
        temp=head;
        while(p!=specific_pos)
        {
            temp1=temp;
            temp=temp->next;
            p++;
        }
        temp1->next=newnode;
        newnode->next=temp;
    }
    return head;
}
node delete_at_specific_pos(node head,int specific_pos)
{
    int p;
    node temp1;
    if(specific_pos==1)
        head=deletebeg(head);
    else
    {
        p=1;
        temp=head;
        while(p!=specific_pos)
        {
            temp1=temp;
            temp=temp->next;
            p++;
        }
        temp1->next=temp->next;
        printf("Node deleted=%d\n",temp->data);
        free(temp);
           }
    return(head);
}
