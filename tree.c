#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
        int data;
        struct tree *left;
	struct tree *right;
}NODE;

NODE* createNode();
NODE* insert(NODE* root, int data);
NODE *GetNewNode(int data);
void preorder(NODE* root);
void inorder(NODE* root);
void postorder(NODE* root);
int depthFirstSearch(NODE* root , int matchKey);

int main( int argc, char* argv[] )
{
	int i,matchKey;
	NODE* root = NULL;
	for (i=1;i<argc;i++)
		root = insert(root,atoi(argv[i]));
	
	printf("\nPre-order traversal: ");
	preorder(root);
	printf("\nIn-order traversal: ");
	inorder(root);
	printf("\nPost-order traversal: ");
	postorder(root);
		
	/*while(1)
	{
		printf("\n enter the number to search: ");
		scanf("%d", &matchKey);
		if (depthFirstSearch( root , matchKey) == 1 )
			printf("\n number found!");
		else
			printf("\n number not found! ");
		printf("\n(enter CTRL+C to exit)\n");
	}*/
	printf("\n\n");	
	return 0;
}

NODE* createNode()
{
        return ( (NODE *) malloc( sizeof(NODE)  ) );
}

NODE* insert(NODE* root, int data)
{
	if (root == NULL)
		root = GetNewNode(data);
	else if (data <= root->data)
		root->left = insert(root->left,data);
	else if (data > root->data)
		root->right = insert(root->right,data);
	return root;
}

NODE *GetNewNode(int data)
{
	NODE* newNode = createNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

void preorder(NODE* root)
{
	if(root==NULL)
		return;
	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(NODE* root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

void postorder(NODE* root)
{
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->data);
}

int depthFirstSearch(NODE* root , int matchKey)
{
	if (root->data == matchKey)
		return 1;
	else
		if (root->left != NULL)
			return depthFirstSearch( root->left, matchKey );
		else
			if (root->right != NULL)
				return depthFirstSearch( root->right, matchKey );
			else
				return 0;
}
