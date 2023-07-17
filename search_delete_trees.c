#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    char color;
    struct node *lnode;
    struct node *rnode;
};
struct node* getnode(int key)
{
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    newnode->data=key;
    newnode->rnode=NULL;
    newnode->lnode=NULL;
    return newnode;
}
struct node* insertnode(struct node *root,int key)
{
    struct node *newnode=getnode(key);
    if(root==NULL)
    {
        root=newnode;
        return root;
    }
    else{
            if(key>root->data)
            {
               root->rnode=insertnode(root->rnode,key);
            }
            else if(key<=root->data)
            {
               root->lnode=insertnode(root->lnode,key);
            }
    }
}
/*int searchnode(struct node *root,int key)
{
    struct node *cur=root;
    int status;
    if(cur==NULL)
        return 0;

    else if(cur->data==key)
        return 1;

    else{

            if(key>root->data)
            {
               status=searchnode(root->rnode,key);
            }
            else if(key<=root->data)
            {
               status=searchnode(root->lnode,key);
            }
    }
    return status;
}*/
int searchnode(struct node *root,int key)
{
    int status=0;
    if(root!=NULL)
    {
        if(root->data==key)
        {
            status=1;
            return 1;
        }
        else if(key>root->data)
            status=searchnode(root->rnode,key);
        else
            status=searchnode(root->lnode,key);
    }
    return status;
}
int level_node(struct node *root,int key)
{
    int level=0;
    while(root->data!=key)
    {
        if(root->data<key)
            root=root->rnode;
        else
            root=root->lnode;
        level++;
    }
    return level;
}
void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d\n",root->data);
        preorder(root->lnode);
        preorder(root->rnode);
    }
}
void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->lnode);
        postorder(root->rnode);
        printf("%d\n",root->data);
    }
}
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->lnode);
        printf("%d %c\n",root->data,root->color);
        inorder(root->rnode);
    }
}
int find_min(struct node *root)
{
    while(root->lnode!=NULL)
    {
        root=root->lnode;
    }
    return root->data;
}
int find_max(struct node *root)
{
    while(root->rnode!=NULL)
    {
        root=root->rnode;
    }
    return root->data;
}
struct node* search_delete(struct node *root,int key)
{
    if(root==NULL)
    {
        printf("key not found\n");
    }
    else if(root->data==key)
        {
            if(root->lnode==NULL && root->rnode==NULL)
            {
                printf("%d is deleted\n",root->data);
                free(root);
                return NULL;
            }
            else if(root->lnode==NULL && root->rnode!=NULL)
            {
                struct node *temp = root->rnode;
                printf("%d is deleted\n",root->data);
                free(root);
                return temp;
            }
            else if(root->lnode!=NULL && root->rnode==NULL)
            {
                struct node *temp = root->lnode;
                printf("%d is deleted\n",root->data);
                free(root);
                return temp;
            }
            else if(root->lnode!=NULL && root->rnode!=NULL)
            {
                 struct node *cur=root,*prev=root ;
                 cur=cur->lnode;
                 while(cur->rnode!=NULL)
                 {
                     prev=cur;
                    cur=cur->rnode;
                 }
                 if(cur==root->lnode)
                 {
                     root->data=cur->data;
                     root->lnode=cur->lnode;
                     free(cur);
                 }
                 else{
                    root->data=cur->data;
                    prev->rnode=cur->lnode;
                    free(cur);
                 }
                 return root;
            }
        }

        else if(key>root->data)
            {
                root->rnode=search_delete(root->rnode,key);
            }

        else{
                root->lnode=search_delete(root->lnode,key);
        }

    return root;
}
/*void printsibling(struct node *root,int key)
{
    struct node *cur=root,*prev=NULL;
    while(cur->data!=key)
    {
        prev=cur;
        if(key>cur->data)
            cur=cur->rnode;
        else
            cur=cur->lnode;
    }
    if(prev->rnode==NULL)
    {
        printf("no sibling of 13\n");
    }
    else
    {
        printf("the sibling of the node %d is %d\n",key,prev->rnode->data);
    }
}
void secondmin(struct node *root)
{
    struct node *cur=root,*prev=NULL;
    while(cur->lnode!=NULL)
    {
        prev=cur;
        cur=cur->lnode;
    }
    if(cur->rnode!=NULL)
    {
        printf("the second minimum is %d\n",cur->rnode->data);
    }
    else{
        printf("the second minimum %d\n",prev->data);
    }
}
void secondmax(struct node *root)
{
    struct node *cur=root,*prev=NULL;
    while(cur->rnode!=NULL)
    {
        prev=cur;
        cur=cur->rnode;
    }
    if(cur->lnode!=NULL)
    {
        printf("the second maximum is %d\n",cur->lnode->data);
    }
    else{
        printf("the second maximum is   %d\n",prev->data);
    }
}
void topview(struct node*root)
{
    struct node *cur=root->lnode;
    while(cur!=NULL)
    {
        printf("%d ",cur->data);
        cur=cur->lnode;
    }
    cur=root;
    while(cur!=NULL)
    {
        printf("%d ",cur->data);
        cur=cur->rnode;
    }
}
void topview1(struct node* root)
{
    struct node *cur=root->lnode;
    int arr[10],i=0;
    while(cur!=NULL)
    {
        arr[i]=cur->data;
        i++;
        cur=cur->lnode;
    }
    while(i>=0)
    {
        printf("%d ",arr[i]);
        i--;
    }
    cur=root;
    while(cur!=NULL)
    {
        printf("%d ",cur->data);
        cur=cur->rnode;
    }
}
void printleaf(struct node *root)
{
    if(root!=NULL)
    {
        if(root->lnode==NULL && root->rnode==NULL)
        {
            printf("%d ",root->data);
        }
        else{
            if(root->lnode!=NULL)
        {
            printleaf(root->lnode);
        }
            if(root->rnode!=NULL)
        {
            printleaf(root->rnode);
        }
        }
    }
}
void printparentchild(struct node *root)
{
    if(root!=NULL)
    {
        if(root->rnode!=NULL || root->lnode!=NULL)
        {
            if(root->rnode==NULL)
            {
                printf("%d->%d\n",root->data,root->lnode->data);
            }
            else if(root->lnode==NULL)
            {
                printf("%d->%d\n",root->data,root->rnode->data);
            }
            else{
                printf("%d->%d,%d\n",root->data,root->lnode->data,root->rnode->data);
            }
            printparentchild(root->lnode);
            printparentchild(root->rnode);
        }
    }
}
/*int find_depth(struct node *root,struct node *subroot)
{
    int depth=0;
    if(root!=NULL)
    {
        depth++;
        if(root->data==subroot->data)
            return depth;
        else if(subroot->data>root->data)
            depth+=find_depth(root,root->rnode);
        else
            depth+=find_depth(root,root->lnode);
    }
    return depth;
}*/
/*int max_depth(struct node *root)
{
    int max=-1;
    if(root!=NULL)
    {
    if(root->rnode==NULL && root->lnode==NULL)
    {
        if(max<find_depth(root,su))
            max=find_depht(root);
    }
    max_depth(root->lnode);
    }
    return max;
}*/
int find_depth(struct node *root,struct node *subroot)
{
    struct node *cur=root;
    int depth=0;
    while(cur->data!=subroot->data)
    {
        if(cur->data>subroot->data)
            cur=cur->lnode;
        else
            cur=cur->rnode;
        depth++;
    }
        return depth;
}
int max_depth(struct node *root,struct node *subroot,int max)
{
    if(subroot!=NULL)
    {
    if(subroot->lnode==NULL && subroot->rnode==NULL)
        {
        if(max<find_depth(root,subroot))
            max=find_depth(root,subroot);
        }
    else{
        max=max_depth(root,subroot->lnode,max);
        max=max_depth(root,subroot->rnode,max);
    }
    }
    return max;
}
int height(struct node *root)
{
   if(root!=NULL)
   {
       int hight=1;
       int l,r;
       l=height(root->lnode);
       r=height(root->rnode);
       if(l>r)
       {
           hight+=l;
       }
       else{
        hight+=r;
       }
       return hight;
   }
   else{
    return 0;
   }
}
void colorgraph(struct node *root)
{
    if(root!=NULL)
    {
        if(root->lnode==NULL && root->rnode==NULL)
            root->color='G';
        else if(root->lnode!=NULL || root->rnode!=NULL)
        root->color='M';
        colorgraph(root->lnode);
        colorgraph(root->rnode);
    }
}
void bottomview(struct node *root)
{

}
int main()
{
    struct node *root=NULL;
    int ch;
    int key;
    int status;
    int level;
    int hight;
    while(1)
    {
        printf("1)insert node 2)search node 3)display 4)find minimum 5)search and delete 6)print sibling of 7)secondmax 8)seconndmin\n 9)top view 10)bottom view 11)print parent child for all nodes 12)max depth 13)color graph 14)exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("enter data\n");
            scanf("%d",&key);
            root=insertnode(root,key);
            break;
            case 2:printf("enter data\n");
            scanf("%d",&key);
            status=searchnode(root,key);
            if(status==1)
                printf("key found\n");
            else
                printf("key not found");
            break;
            case 3:
                inorder(root);
            break;
            case 4:key=find_min(root);
            printf("%d",key);
            break;
            case 5:printf("enter the data to be deleted\n");
            scanf("%d",&key);
            root=search_delete(root,key);
            break;
            case 6:printf("enter the node\n");
            scanf("%d",&key);
            printsibling(root,key);
            case 7:secondmax(root);
            break;
            case 8:secondmin(root);
            break;
            case 9:topview1(root);
            break;
            case 10:printleaf(root);
            break;
            case 11:printparentchild(root);
                break;
            case 12:key=max_depth(root,root,-1);
            printf("max depth = %d\n",key);
            break;
            case 13:colorgraph(root);
            root->color='B';
            break;
            case 14:bottomview(root);
            break;
            case 15:hight=height(root);
            printf("height of the tree:%d\n",hight);
            break;
            case 16:hight=height(root);
            printf("depth of the tree:%d",hight-1);
            break;
            case 17:printf("Enter the key\n");
            scanf("%d",&key);
                level=level_node(root,key);
                printf("Level of the node:%d\n",level);
                break;
            case 18:exit(0);
            break;
            default:printf("f");
                break;
       }
  }
  return 0;
}

