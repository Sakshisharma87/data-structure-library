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
TreeNode* createNode(int value);
TreeNode* insertBST(TreeNode* root, int value);
void inorder(TreeNode* root);
void handleArray(int n);
void handleLinkedList();
void handleStack();
void handleQueue();
int push(int top, int max, int stack[]);
int pop(int stack[], int top);
void traverseStack(int top, int stack[]);

int main() {
    int choice, n, top = -1;
    TreeNode* root = NULL;
    int stack[100];

    while (1) {
        printf("Select data structure:\n1. Array\n2. Linked List\n3. Stack\n4. Queue\n5. Tree (BST)\n0. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of elements (not more than 100): ");
                scanf("%d", &n);
                if (n > 0 && n <= 100) {
                    handleArray(n);
                } else {
                    printf("Invalid size! Must be between 1 and 100.\n");
                }
                break;

            case 2:
                handleLinkedList();
                break;

            case 3:
                handleStack(top, stack);
                break;

            case 4:
                handleQueue();
                break;

            case 5:
                printf("Enter value of root node: ");
                int rootVal;
                scanf("%d", &rootVal);
                root = createNode(rootVal);

                char cont = 'y';
                while (cont == 'y' || cont == 'Y') {
                    printf("Enter data to insert: ");
                    int val;
                    scanf("%d", &val);
                    root = insertBST(root, val);

                    printf("Do you want to continue insertion? (y/n): ");
                    scanf(" %c", &cont);
                }
                printf("Inorder traversal of BST:\n");
                inorder(root);
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
TreeNode* createNode(int value) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a value into a Binary Search Tree (BST)
TreeNode* insertBST(TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    } else if (value > root->data) {
        root->right = insertBST(root->right, value);
    } else {
        root->left = insertBST(root->left, value);
    }
    return root;
}

// Function for inorder traversal of a Binary Search Tree (BST)
void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d\n", root->data);
        inorder(root->right);
    }
}

// Function to handle array operations
void handleArray(int n) {
    int i, arr[100];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("The array elements are:\n");
    for (i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
}

// Function to handle linked list operations
void handleLinkedList() {
    struct ListNode *head = NULL, *temp, *newNode;
    char cont = 'y';

    while (cont == 'y' || cont == 'Y') {
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
        scanf(" %c", &cont);
    }

    printf("The linked list is:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// Function to handle stack operations
void handleStack(int top, int stack[]) {
    int choice;
    int max = 100;

    while (1) {
        printf("Stack operations:\n1. Push\n2. Pop\n3. Traverse\n0. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                top = push(top, max, stack);
                break;

            case 2:
                if (top >= 0) {
                    printf("The popped item is %d\n", pop(stack, top));
                    top--;
                } else {
                    printf("Stack underflow.\n");
                }
                break;

            case 3:
                traverseStack(top, stack);
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
int push(int top, int max, int stack[]) {
    int val;
    if (top == max - 1) {
        printf("Stack overflow.\n");
        return top;
    } else {
        printf("Enter element to push: ");
        scanf("%d", &val);
        top++;
        stack[top] = val;
        return top;
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
void traverseStack(int top, int stack[]) {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("The stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

// Function to handle queue operations
void handleQueue() {
    struct ListNode *front = NULL, *rear = NULL, *temp, *newNode;
    char cont = 'y';
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
                        rear = NULL;
                    }
                }
                break;

            case 3:
                printf("The queue elements are:\n");
                temp = front;
                while (temp != NULL) {
                    printf("%d\n", temp->data);
                    temp = temp->next;
                }
                break;

            case 0:
                return;

            default:
                printf("Incorrect choice. Please select a valid option.\n");
                break;
        }
    }
}
