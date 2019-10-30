#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>


struct Node
{
	char* key;
	struct Node *left;
	struct Node *right;
	int frequency;
};


int max(int a, int b);


int height(struct Node *N)
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
struct Node* newNode(int key)
{
	struct Node* node = (struct Node*)
						malloc(sizeof(struct Node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // new node is initially added at leaf
	return(node);
}


struct Node *rightRotate(struct Node *y)
{
	struct Node *x = y->left;
	struct Node *T2 = x->right;


	x->right = y;
	y->left = T2;


	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;


	return x;
}

struct Node *leftRotate(struct Node *x)
{
	struct Node *y = x->right;
	struct Node *T2 = y->left;


	y->left = x;
	x->right = T2;


	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;


	return y;
}


int getBalance(struct Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}


struct Node* insert(struct Node* node, int key)
{
	/* 1. Perform the normal BST insertion */
	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
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


	if (balance > 1 && key < node->left->key)
		return rightRotate(node);


	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key < node->right->key)
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
		printf("%d ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}


bool Search(struct Node* root, int data){

  if(root == NULL){
  return false;
  }
  else if(root->key == data){
    return true;
  }
  else if(data <= root->key){
    return Search(root->left,data);
  }
  else{
    return Search(root->right,data);
  }
}

int counter(struct Node *root)
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

struct Node * minValue(struct Node* root)
{
	struct Node* current = root;

	while(current->left !=NULL){
		current = current->left;
	}
	return current;
}

struct Node* delete(struct Node* root,char *word)
{
	struct Node *temp;
  int cmp;

  if(root==NULL){
    printf("Element not found");
  }

  else if(root !=NULL){
    cmp = strcmp(string,root->key);
  }
  else if(cmp >0)
  {
    root->right = delete(root->right,string);
  }
  else if(cmp<0)
  {
    root->left = delete(root->left,string);
  }

  else if(cmp==0){
    if(node->right && node->left){
      temp = minValue(root->right);
      free(root->key);
      root->key = (char *)malloc(strlen(temp->key)+1);
      strcpy(root->key,temp->key);
      root->right = delete(root->right,temp->key);
    }
    else{
      temp = root;
      if(root->left == NULL){
        root = root->right;
      }
      else if(root->right==NULL){
        root = root->left;
      }
      free(temp->key);
      free(temp);
    }

}
  return root;
}

int findSum(struct Node *root)
{

if(root == NULL){
	return 0;
}

return (root->key+findSum(root->left)+ findSum(root->right));

}

/* Drier program to test above function*/
int main()
{
struct Node *root = NULL;
int choose,nodeCount;
int keyVal, keyRemove;
int test, testTwo=0;
int keyInput;

printf("1.Initialization\n");
printf("2.Find\n");
printf("3.Insert\n");
printf("4.Remove\n");
printf("5.Check Height,Size, and Total Count\n");
printf("6.Find All(above a given frequency)\n");
printf("7.Exit\n");



root = insert(root, 10);
root = insert(root, 20);
root = insert(root, 30);
root = insert(root, 40);
root = insert(root, 50);
root = insert(root, 25);
/*
root = insert(root, 100);
root = insert(root, 200);
root = insert(root, 300);
root = insert(root, 400);
root = insert(root, 500);
root = insert(root, 600);
*/
do{

printf("Enter your option: ");
scanf("%d", &choose);

switch(choose){

	case 1:
	printf("Insertion\n");
	break;

	case 2:
	printf("Enter a key: ");
	scanf("%d", &keyVal);

	if(Search(root,keyVal)==true){
		printf("Found %d\n", keyVal);
	}
	else{
		printf("No_such_key\n");
	}

	break;

	case 3:
	printf("Insert a key: \n");
	scanf("%d", &keyInput);
	root = insert(root, keyInput);
	testTwo = counter(root);
	printf("%d\n", testTwo);


	break;

	case 4:
	printf("Remove key: \n");
	scanf("%d", &keyRemove);

	delete(root, keyRemove);
	printf("Key removed\n");
	break;

	case 5:
	printf("Check height,size,total count\n");
	nodeCount = counter(root);
	printf("The number of nodes is %d\n", nodeCount);

	test = findSum(root);
	printf("The sum of all keys is %d\n", test);

	break;

	case 6:
	printf("Find all\n");
	break;

	case 7:
	return 0;

}


}while(choose!=7);

/* Constructing tree given in the above figure */


/* The constructed AVL Tree would be
			30
		/ \
		20 40
		/ \	 \
	10 25 50
*/



printf("Preorder traversal of the constructed AVL"
		" tree is \n");
preOrder(root);

return 0;
}
