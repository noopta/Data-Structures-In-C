//Anupta Islam
//University of Guelph
//AVL Tree

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct Node
{
	char key[20];					// create struct
	struct Node *left;
	struct Node *right;
	int height;
};

struct Node* newNode(char key[50])	//create a new Node given a key
{
	struct Node* node = (struct Node*)
	malloc(sizeof(struct Node));
	strcpy(node->key, key);
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return(node);
}
int max(int a, int b);

int height(struct Node *N) 	//gets height of a Node
{
	if (N == NULL)
		return 0;
	return N->height;
}


int max(int a, int b)
{
	return (a > b)? a : b;
}



/* Helper function that allocates a new node with the given key and
	NULL left and right pointers. */



struct Node *rightRotate(struct Node *y)			//function to rotate tree to the right
{
	struct Node *x = y->left;
	struct Node *T2 = x->right;

	x->right = y;
	y->left = T2;


	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;


	return x;
}

struct Node *leftRotate(struct Node *x)  //function to rotate tree to the left
{
	struct Node *y = x->right;
	struct Node *T2 = y->left;


	y->left = x;
	x->right = T2;


	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;


	return y;
}


int getBalance(struct Node *N)		//checks if tree is balanced
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}


struct Node* insert(struct Node* node, char* key)	//insert a string into the tree
{
	/* 1. Perform the normal BST insertion */
	if (node == NULL)
		return(newNode(key));

	if (strcmp(key, node->key) < 0)
		node->left = insert(node->left, key);
	else if (strcmp(key,node->key)>0)
		node->right = insert(node->right, key);
	else // Equal keys are not allowed in BST
		return node;

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left),
						height(node->right));

	/* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
	int balance = getBalance(node);

	if (balance > 1 && strcmp(key,node->left->key)<0)
		return rightRotate(node);

	if (balance < -1 && strcmp(key, node->right->key)>0)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && strcmp(key,node->left->key)>0)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && strcmp(key,node->right->key)<0)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;

}

// A utility function to print preorder traversal
// of the tree.
// The function also prints height of every node
void preOrder(struct Node *root)
{
	if(root != NULL)
	{
		printf("%s ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}


bool Search(struct Node* root, char string[50]){ 	//checks if the string exists in the tree

  if(root == NULL){
  return false;
  }
  else if(strcmp(root->key, string)==0){
    return true;
  }
  else if(strcmp(string,root->key)<=0){
    return Search(root->left,string);
  }
  else{
    return Search(root->right,string);
  }
}

int counter(struct Node *root)	//counts the number of nodes in the tree
{

int count = 1;

if(root == NULL)
{
	return 0;
}

else
	{
	count += counter(root->left);
	count += counter(root->right);
	return count;
	}

}

struct Node * minValue(struct Node* root)		//gets the lowest value in the tree
{
	struct Node* current = root;

	while(current->left !=NULL){
		current = current->left;
	}
	return current;
}

struct Node* delete(struct Node* root,char key[50])		//function to delete a node in the tree given a string
{
	if(root==NULL){
		return root;
	}

	if(strcmp(key,root->key)<0){
		root->left = delete(root->left,key);
	}

	else if(strcmp(key, root->key) >0){
		root->right = delete(root->right,key);
	}

	else{

		if(root->left==NULL){
			struct Node *temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL){

			struct Node *temp = root->left;
			free(root);
			return temp;
		}

		struct Node* temp = minValue(root->right);


    strcpy(root->key,temp->key);

		root->right = delete(root->right, temp->key);

	}

	return root;
}

/*Main function below to test the functions above and create the tree*/
int main()
{
struct Node *root = NULL;
int choose,nodeCount;
char keyVal[50];
char keyRemove[50];
int  testTwo=0;
char keyInput[50];

printf("1.Initialization\n");
printf("2.Find\n");
printf("3.Remove\n");
printf("4.Check Total Count\n");
printf("5.Show Pre Order Traversal\n");
printf("6.Exit\n");


root = insert(root, "abc");		//hardcoding strings and creating the avl tree,
root = insert(root, "def");
root = insert(root, "ghi");
root = insert(root, "jkl");
root = insert(root, "mno");
root = insert(root, "pqr");

do{
printf("Enter a code(1-6) and hit Return\n");
printf("avl/>");
scanf("%d", &choose);			//recurring menu

switch(choose){

	case 1:
	printf("Insertion\n");

	printf("Insert key: \n");
	scanf("%s", keyInput);
	root = insert(root, keyInput);
	printf("key: %s inserted\n",keyInput);
	testTwo = counter(root);
	printf("%d nodes\n", testTwo);

	break;

	case 2:
	printf("find key: ");
	scanf("%s", keyVal);

	if(Search(root,keyVal)==true){
		printf("key: %s found.\n", keyVal, root->height);
	}
	else{
		printf("No_such_key\n");
	}

	break;

	case 3:

	printf("Remove key: \n");
	scanf("%s", keyRemove);
	delete(root, keyRemove);
	printf("key: %s removed.\n",keyRemove,root->height);

	break;

	case 4:

	printf("Check total count\n");
	nodeCount = counter(root);
	printf("The number of nodes is %d\n", nodeCount);

	break;

	case 5:
	printf("Preorder traversal of the constructed AVL"
			" tree is \n");
	preOrder(root);
  printf("\n");


	break;

	case 6:
	return 0;

	}

}while(choose<6);	// wuntil the user enters 6, keep showing the menu

return 0;
}
