#include <stdio.h>
#include <stdlib.h>

// Structure for a linked list node
struct ListNode {
    int data;
    struct ListNode* next;
};

// Structure for a binary search tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef struct TreeNode TreeNode;

// Function prototypes
TreeNode* createTreeNode(int value);
TreeNode* insertBST(TreeNode* root, int value);
void inorderTraversal(TreeNode* root);
void handleArray(int size);
void handleLinkedList();
void handleStack();
void handleQueue();
int push(int stackTop, int maxStackSize, int stack[]);
int pop(int stack[], int top);
void traverseStack(int top, int stack[]);

int main() {
    int choice, arraySize, stackTop = -1;
    TreeNode* root = NULL;
    int stack[100];

    while (1) {
        printf("Select data structure:\n1. Array\n2. Linked List\n3. Stack\n4. Queue\n5. Tree (BST)\n0. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of elements (not more than 100): ");
                scanf("%d", &arraySize);
                if (arraySize > 0 && arraySize <= 100) {
                    handleArray(arraySize);
                } else {
                    printf("Invalid size! Must be between 1 and 100.\n");
                }
                break;

            case 2:
                handleLinkedList();
                break;

            case 3:
                handleStack(stackTop, stack);
                break;

            case 4:
                handleQueue();
                break;

            case 5:
                printf("Enter value of root node: ");
                int rootValue;
                scanf("%d", &rootValue);
                root = createTreeNode(rootValue);

                char continueInsertion = 'y';
                while (continueInsertion == 'y' || continueInsertion == 'Y') {
                    printf("Enter data to insert: ");
                    int value;
                    scanf("%d", &value);
                    root = insertBST(root, value);

                    printf("Do you want to continue insertion? (y/n): ");
                    scanf(" %c", &continueInsertion);
                }
                printf("Inorder traversal of BST:\n");
                inorderTraversal(root);
                break;

            case 0:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Incorrect choice. Please select a valid option.\n");
                break;
        }
    }

    return 0;
}

// Function to create a new node in a Binary Search Tree (BST)
TreeNode* createTreeNode(int value) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a value into a Binary Search Tree (BST)
TreeNode* insertBST(TreeNode* root, int value) {
    if (root == NULL) {
        return createTreeNode(value);
    } else if (value > root->data) {
        root->right = insertBST(root->right, value);
    } else {
        root->left = insertBST(root->left, value);
    }
    return root;
}

// Function for inorder traversal of a Binary Search Tree (BST)
void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d\n", root->data);
        inorderTraversal(root->right);
    }
}

// Function to handle array operations
void handleArray(int arraySize) {
    int i, arr[100];
    printf("Enter %d elements:\n", arraySize);
    for (i = 0; i < arraySize; i++) {
        scanf("%d", &arr[i]);
    }
    printf("The array elements are:\n");
    for (i = 0; i < arraySize; i++) {
        printf("%d\n", arr[i]);
    }
}

// Function to handle linked list operations
void handleLinkedList() {
    struct ListNode *head = NULL, *temp, *newNode;
    char continueInsertion = 'y';

    while (continueInsertion == 'y' || continueInsertion == 'Y') {
        newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        printf("Enter data: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        printf("Do you want to continue adding nodes? (y/n): ");
        scanf(" %c", &continueInsertion);
    }

    printf("The linked list is:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// Function to handle stack operations
void handleStack(int stackTop, int stack[]) {
    int choice;
    int maxStackSize = 100;

    while (1) {
        printf("Stack operations:\n1. Push\n2. Pop\n3. Traverse\n0. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                stackTop = push(stackTop, maxStackSize, stack);
                break;

            case 2:
                if (stackTop >= 0) {
                    printf("The popped item is %d\n", pop(stack, stackTop));
                    stackTop--;
                } else {
                    printf("Stack underflow.\n");
                }
                break;

            case 3:
                traverseStack(stackTop, stack);
                break;

            case 0:
                return;

            default:
                printf("Incorrect choice. Please select a valid option.\n");
                break;
        }
    }
}

// Function to push an element onto the stack
int push(int stackTop, int maxStackSize, int stack[]) {
    int value;
    if (stackTop == maxStackSize - 1) {
        printf("Stack overflow.\n");
        return stackTop;
    } else {
        printf("Enter element to push: ");
        scanf("%d", &value);
        stackTop++;
        stack[stackTop] = value;
        return stackTop;
    }
}

// Function to pop an element from the stack
int pop(int stack[], int top) {
    if (top == -1) {
        printf("Stack underflow.\n");
        return -1;
    } else {
        return stack[top];
    }
}

// Function to traverse the stack
void traverseStack(int stackTop, int stack[]) {
    if (stackTop == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("The stack elements are:\n");
        for (int i = stackTop; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

// Function to handle queue operations
void handleQueue() {
    struct ListNode *front = NULL, *rear = NULL, *temp, *newNode;
    char continueInsertion = 'y';
    int choice;

    while (1) {
        printf("Queue operations:\n1. Enqueue\n2. Dequeue\n3. Display\n0. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
                printf("Enter data to enqueue: ");
                scanf("%d", &newNode->data);
                newNode->next = NULL;

                if (rear == NULL) {
                    front = rear = newNode;
                } else {
                    rear->next = newNode;
                    rear = newNode;
                }
                break;

            case 2:
                if (front == NULL) {
                    printf("Queue underflow.\n");
                } else {
                    temp = front;
                    front = front->next;
                    printf("The dequeued item is %d\n", temp->data);
                    free(temp);

                    if (front == NULL) {
                        rear = NULL# include <stdio.h>
# include<stdlib.h>
# include<string.h>
void element(){
    
}
	struct s{
		int info;
		struct s *next;
	};
    struct tre{
        int info;
        struct tre *lc;
        struct tre *rc ;
    };
    typedef struct tre t;
t* new(int x){
      t *n;
      n=(t*)malloc(sizeof(t));
     n->info=x;
     n->lc=NULL;
     n->rc=NULL;
     return n;
}
t* insert(t* r,int x){
    if(r==NULL){
        return new(x);
    }
    else if(x>r->info){
      r->rc=insert(r->rc,x);
    }
    else{
        r->lc=insert(r->lc,x);
    }
    return r;
}
void array(int a){
   int i,x[100];
   printf("enter data:");
   for(i=0;i<a;i++){
     scanf("%d",&x[i]);
   }
   printf("the array is:");
   for(i=0;i<a;i++){
     printf("%d\n",x[i]);
   }
}
int link(int x, int y){
    char ch;
    typedef struct s node;
     node *ptr,*start,*next,*f,*r,*n;
   ptr=NULL;
    do{
    	n=(node*)malloc(sizeof(node));
    	printf("enter data:");
    	scanf("%d",&n->info);
    	if(ptr!=NULL){
    		ptr->next=n;
    		ptr=ptr->next;
		}
		else{
			start=n;
			ptr=n;
		}
		scanf("%c",&ch);
		printf("do you want to continue(enter y/n):");
		scanf("%c",&ch);
	}while(ch=='y');
	
	ptr->next=NULL;
   if(x==2){
        printf("\nthe linklist is:");
	}
   
   if(x==4){
    printf("the queue is:");
    f=start;
    r=ptr;
    
   }
    ptr=start;
	while(ptr!=NULL){
		printf("%d\n",ptr->info);
		ptr=ptr->next;
    }
    if(x==4 &&y==2){
       ptr=f;
       f=f->next;
       ptr=start;
       printf("the queue after deletion is:");
       ptr=f;
	while(ptr!=NULL){
		printf("%d\n",ptr->info);
		ptr=ptr->next;
    }
      free(ptr);
    }
}
int  push(int t,int m,int s[]){
     int i;
     if(t==m-1){
        printf("stack overflow");
        exit(0);
     }
     else{
        printf("enter element to insert:");
        scanf("%d",&i);
        t=t+1;
        s[t]=i;
        return t;
     }

}
int pop(int s[],int t){
    int i;
    if(t==-1){
        printf("stack underflow");
        exit(0);
    }
    else{
        i=s[t];
        t=t-1;
        return i;
    }


}
void transverse(int t,int s[]){
    int i;
    if(t==-1){
        printf("stack underflow");
        exit(0);
    }
    else{
        printf("the stack is:");
        for (i = t; i >=0; i--)
        {
            printf("%d\n",s[i]);
        }
        
    }
}
void inorder(t *r){
    // printf("the inorder transversal of tree :\n");
    if(r!=NULL){
        inorder(r->lc);
        printf("%d\n",r->info);
        inorder(r->rc);
    }

}
int main(){
    int a,b=1,n=1,i,z;
    struct s *p,*tr;
    t *root;
    char ch='y';
    printf("select data structure:\n1.array\n2.linklist\n3.stack\n4.queue\n5.tree(BST)\n");
    scanf("%d",&a);
    switch(a){
        case 1:
        printf("enter the no. of element:(not more than 100 elements)");
        scanf("%d",&n);
        array(n);
        break;
        case 2:
         link(a,b);
         break;
         case 3:
        //   while(n==1){
         printf("(stack should not exceed 100 elements)\n");
         printf("select operation:-\n");
        //  scanf("%d",&b);
         int st[100];
         int top=-1;
         int max=100;
         while(n==1){
             printf("1.push\n2.pop\n3.traverse\n");
         scanf("%d",&b);
         switch (b)
         {
         case 1:
           top= push(top,max,st);
            break;
         case 2:
          printf("the deleted item is %d\n",pop(st,top));
          top=top-1;
          break;
            case 3:
            transverse(top,st);
            break;
         default:
         printf("incorrect choice...");
            break;
         }
         printf("do you want to continue (1/0):");
         scanf("%d",&n);

         } 
         break;
         case 4:
          printf("select operation\n1.insertion only\n2.insertion and deletion\n");
         scanf("%d",&b);
         link(a,b);
         break;
         case 5:
         printf("enter value of root node:");
         scanf("%d",&n);
          root=new(n);
         scanf("%c",&ch);
         printf("do you want to continue insertion(y/n):");
         scanf("%c",&ch);
        while(ch=='y'){
          printf("enter data:");
          scanf("%d",&z);
          insert(root,z);
           scanf("%c",&ch);
          printf("do you want to continue insertion(y/n):");
         scanf("%c",&ch);
        }
    printf("the inorder transversal of BST :\n");
         inorder(root);
         break;
    }
}
