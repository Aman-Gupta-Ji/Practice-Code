// program is to take out the sum of all the left leaf nodes that has right cousin
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
int c=0,sum=0;
typedef struct tree
{
	struct tree *left;
	int info;
	struct tree *right;
}treetype;
treetype *create(int num)
{
	treetype *temp;
	temp=(treetype*)malloc(sizeof(treetype));
	if(temp==NULL)
	printf("Not enough memory\n");
	else
	{
		temp->info=num;
		temp->left=NULL;
		temp->right=NULL;
	}
	return(temp);
}
void insert(treetype *root,treetype *temp)
{
	if(temp->info<root->info)
	{
		if(root->left==NULL)
		root->left=temp;
		else
		insert(root->left,temp);
	}
	else
	{
		if(root->right==NULL)
		root->right=temp;
		else
		insert(root->right,temp);
	}
}
int checkleaf(treetype *node) {
    if(node==NULL)
        return 0;
    if(node->left==NULL&&node->right==NULL)
        return 1;
    return 0;
}
treetype *getparent(treetype *root, treetype * node) {
    if(root==NULL)
        return NULL;
    if(root->left==node||root->right==node)
        return root;
    treetype *par=getparent(root->left,node);
    if(par!=NULL)
        return par;
    par=getparent(root->right,node);
    return par;
}

int depth(treetype *root, treetype *node, int d) {
    if(root==NULL)
        return 0;
    if(root==node)
        return d;
    int temp=depth(root->left,node,d+1);
    if(temp!=0)
        return temp;
    temp=depth(root->right,node,d+1);
    return temp;
}
int height(treetype *root){
    if(root==NULL)
        return 0;
    int l=height(root->left);
    int r=height(root->right);
    return 1+(l>r)?l:r;
}
int checkrighcousion(treetype *root, treetype *node) {
    if(root==NULL||node==root)
        return 0;
    int right=height(root->right);
    int left=depth(root->left,node,0);
    if(left==0)
        return checkrighcousion(root->right,node);
    return (right>=left)?1:0;
}
int checkcousion(treetype *root, treetype *a, treetype *b) {
    if(a==b)
        return 0;
    int da=depth(root,a,1);
    int db=depth(root,b,1);
    if(da!=db||da==0)
        return 0;
    treetype *pa, *pb;
    pa=getparent(root,a);
    pb=getparent(root,b);
    if(pa==pb)
        return 0;
    return 1;    
}
void count(treetype *root, treetype *node){
	if(root!=NULL)
	{
		if(checkleaf(node)&&checkrighcousion(root,node)){
				sum=sum+root->left->info;
		}
		count(root,node->left);
		count(root,node->right);
	}
}
int main()
{
	int num;
	treetype *root=NULL,*temp;
	char ch;
	do
	{
		printf("enter the number:");
	    scanf("%d",&num);
		temp=create(num);
		if(root==NULL)
		root=temp;
		else
		insert(root,temp);
		printf("do you want to continue y/n \n");
		fflush(stdin);
		scanf("%c",&ch);
    }while(ch=='y');
	printf("sum of the left nodes are:\n");
	count(root,root);
	printf("%d",sum);
	return 0;
}