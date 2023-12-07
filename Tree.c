#include<stdio.h>
#include <stdlib.h>
struct node{
   int data;
   struct node *lc;
   struct node *rc;
}*root;


void inorder(struct node *node)
{
	if(node!=NULL)
	{
		inorder(node->lc);
		printf(" %d ",node->data);
		inorder(node->rc);
	}
}
struct node* InsertNode(struct node*node,int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp ->data= data;
	temp->rc = NULL;
	temp->lc = NULL;
	if(node == NULL)
	{
		 node =temp;
		return node;
	}
	else{
		if(data<node->data)
		{
			node->lc =InsertNode(node->lc,data);
			 
		}
		else
		{
			node->rc  = InsertNode(node->rc,data);
		}
		
	}
	return node;
}

struct node *delete(struct node*node,int data)
{
	if(node == NULL)
	{
	return NULL;
	}
	
	if(data < node->data)
	{
		node->lc=delete(node->lc,data);
		return node;
	}
	else if(data > node->data)
	{
		node->rc = delete(node->rc,data);
		return node;
	}	
	else if(data==node->data)
	{
	
		if(node->rc==NULL && node->lc == NULL)
		{
			return NULL;
		}
		
		else if(node->lc==NULL)
		{
			struct node * holder=node->rc;
			free(node);
			return holder;
		}
		else if(node->rc ==NULL)
		{
			struct node * holder=node->lc;
			free(node);
			return holder;
		}
		
		else 
		{
			struct node*succ;
			struct node *t1=node->rc;
			
			while(t1->lc!=NULL)
			{	
				succ =t1;
				t1=t1->lc;
			}
			node->data = t1->data;
			delete(root,t1->data);
			
		}
	}
	
}


void main()
{
	int x;
	printf("Enter element to insert at root\n");
	scanf("%d",&x);
	root = InsertNode(root,x);
	int i,in,out
	;
	while(i!=0)
	{
		printf("[1.insert]-[2.del]-[4.root]-[3.inorder display]-[0.exit]\n");
		scanf("%d",&i);
		
		switch(i)
		{
			case 1:
			printf("Enter element to insert \n");
			scanf("%d",&in);
			root = InsertNode(root,in);
			break;
			
			case 2:
			printf("Enter element to delete \n");
			scanf("%d",&out);
			delete(root,out);
			break;
			
			case 3 :
			inorder(root);
			break;
			
			case 4 :
			printf("%d\n",root->data);
			break;
			
			case 0:
			printf("Exiting...\n");
			i =0;
			break;
			
			default : 
			printf("working onit\n");
			break;
			
		}
	}
	


}
