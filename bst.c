#include<stdio.h>
#include<stdlib.h>
#define maxsize 30
struct node
{
	int data;
	struct node *left,*right;
};
typedef struct 
{
	struct node *data[maxsize];
	int front,rear;
}QUEUE;
void initq(QUEUE *pq)
{
	pq->front=pq->rear=-1;
}
void addq(QUEUE *pq,struct node *treenode)
{
	pq->data[++pq->rear]=treenode;
}
struct node *removeq(QUEUE *pq)
{
	return pq->data[++pq->front];
}
int isempty(QUEUE *pq)
{
return (pq->front==pq->rear);
}
int isfull(QUEUE *pq)
{
	return(pq->rear==maxsize-1);
}
struct node *create(struct node *root)
{
	struct node *temp,*newnode,*parent;
	int n,num,i;
	printf("enter limit:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("enter data:");
	scanf("%d",&num);
	newnode->data=num;
	newnode->left=newnode->right=NULL;
	if(root==NULL)
	{
	root=newnode;
	continue;
	}
	temp=root;
	while(temp!=NULL)
	{
	parent=temp;
	if(num<temp->data)
	temp=temp->left;
	else
	temp=temp->right;
	}
	if(num<parent->data)
	parent->left=newnode;
	else
	parent->right=newnode;
	}
	return (root);
}
void preorder(struct node *root)
{
	struct node *temp=root;
	if(temp!=NULL)
	{
	printf("%d\t",temp->data);
	preorder(temp->left);
	preorder(temp->right);
	}
}
void inorder(struct node *root)
{
	struct node *temp=root;
	if(temp!=NULL)
	{
	inorder(temp->left);
	printf("%d\t",temp->data);
	inorder(temp->right);
	}
}
void postorder(struct node *root)
{
	struct node *temp=root;
	if(temp!=NULL)
	{
	postorder(temp->left);
	postorder(temp->right);
	printf("%d\t",temp->data);
	}
}
struct node *search(struct node *root,int key)
{
	struct node *temp=root;
	while(temp!=NULL)
	{
	if(key==temp->data)
	return temp;
	if(key<temp->data)
	temp=temp->left;
	else
	temp=temp->right;
	}
	return NULL;
}
int countnode(struct node *root)
{
	static int cnt=0;
	struct node *temp=root;
	if(temp!=NULL)
	{
	cnt++;
	countnode(temp->left);
	countnode(temp->right);
	}
	return cnt;
}
int countleaf(struct node *root)
{
	static int count=0;
	struct node *temp=root;
	if(temp!=NULL)
	{
	if(temp->left==NULL&&temp->right==NULL)
	count++;
	countleaf(temp->left);
	countleaf(temp->right);
	}
	return count;
}
int minvalue(struct node *root)
{
	struct node *temp=root;
	while(temp!=NULL&&temp->left!=NULL)
	temp=temp->left;
	return temp->data;
}
int maxvalue(struct node *root)
{
	struct node *temp=root;
	while(temp!=NULL&&temp->right!=NULL)
	temp=temp->right;
	return temp->data;
}
struct node *treecopy(struct node *root)
{
	struct node *newnode;
	if(root!=NULL)
	{
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=root->data;
	newnode->left=treecopy(root->left);
	newnode->right=treecopy(root->right);
	return newnode;
	}
	else
	return NULL;
	
}
int compare(struct node *root1,struct node *root2)
{
	if(root1==NULL&&root2==NULL)
	return 1;
	else
	if(root1!=NULL&&root2!=NULL)
	if(root1->data==root2->data)
	if(compare(root1->left,root2->left))
	return compare(root1->right,root2->right);
      return 0;
}
void mirror(struct node *root)
{
	struct node *temp=root,*temp1;
	if(temp!=NULL)
	{
	if(temp->left!=NULL)
	mirror(temp->left);
	if(temp->right!=NULL)
	mirror(temp->right);
	temp1=temp->left;
	temp->left=temp->right;
	temp->right=temp1;
	}
}
int level(struct node *root)
{
	int i,level=0;
	struct node *temp,*m=NULL;
	QUEUE q;
	initq(&q);
	addq(&q,root);
	addq(&q,m);
	printf("\nlevel %d---->",level);
	while(!isempty(&q))
	{
	temp=removeq(&q);
	if(temp==m)
	{
	level++;
	if(!isempty(&q))
	{
	addq(&q,m);
	printf("\nlevel %d---->",level);
	}
	}
	else
	{
	printf("%d\t",temp->data);
	if(temp->left)
	addq(&q,temp->left);
	if(temp->right)
	addq(&q,temp->right);
	}
	}
}
int main()
{
	struct node *root=NULL,*root1=NULL,*root2=NULL;
	int key,ch,s;
	do
	{
	printf("\nenter choice\n1-create:\n2-preorder:\n3-inorder:\n4-postorder:\n5-search:\n6-count total node:\n7-count leaf node:\n8-find smallest value:\n9-find largest value:\n10-tree copy:\n11-compare:\n12-mirror\n13-level\n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:root=create(root);break;
	case 2:printf("display data in preorder:\n");
	        preorder(root);break;
	case 3:printf("display data in inorder:\n");
	       inorder(root);break;
	case 4:printf("display data in postorder:\n");
	        postorder(root);break;
	case 5:printf("enter key to search:");
	       scanf("%d",&key);
	        struct node *result=search(root,key);
	       if(result!=NULL)
	       {
	        printf("%d found",key);
	        }
	       else
	       {
	       printf("%d is not found",key);
	       }break;
	case 6:printf("count node:%d",countnode(root));break;
	case 7:printf("count leaf:%d",countleaf(root));break;
	case 8:printf("minimum value:%d",minvalue(root));break;
	case 9:printf("maximum value:%d",maxvalue(root));break;
	case 10:root=create(root);
	        root2=treecopy(root);
	        preorder(root);
	        break;
	case 11:printf("first:");
	        root1=create(root1);
	        printf("second:");
	        root2=create(root2);
	        if(compare(root1,root2))
	        {
	        printf("same");
	        }
	        else
	        {
	        printf("not same");
	        }
	        break;
	 case 12:mirror(root);
	         preorder(root);
	         break;
	 case 13:level(root);
	         break;
	 }
	}while(ch<14);
}
