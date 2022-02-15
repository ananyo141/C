// AVL Tree implementation

#include <stdio.h>
#include <stdlib.h>
#define DEBUG(elem,type) fprintf(stderr, #elem " = " type "\n", elem); \
                         fflush(stderr)

typedef struct tree_node {
    struct tree_node *left, *right;
    double data;
    unsigned height;
} *TNode;

// prototypes
TNode createTree (TNode);
TNode insertNode(TNode, double val);
TNode deleteNode(TNode, double val);
void inOrderTrav(const TNode);
void postOrderTrav(const TNode);
TNode deleteTree(TNode);

// Helper Functions
static void handleChoice(TNode *, int);
inline int max(int a, int b);
inline int getBalance(const TNode);
unsigned getHeight(const TNode);
TNode leftRotate(TNode);
TNode rightRotate(TNode);
int getDelCase(TNode);
TNode delCase1(TNode);
TNode delCase2(TNode);
TNode delCase3(TNode);

int main() {
    int choice;
    TNode root = NULL;
    for (;;) {
        puts(
                "     ******* AVL Tree *******\n"
                "1) Create Tree       2) Insert Node\n"
                "3) Inorder Traversal 4) PostOrder Traversal\n"
                "5) Delete Node       6) Delete Tree\n"
                "Command (-1 to exit):"
        );
        if (scanf("%d", &choice) < 1)
                exit(EXIT_FAILURE);
        system("clear");
        if (choice == -1)
            break;
        puts("Output:");
        handleChoice(&root, choice);
    }
    puts("Exit");
    return 0;
}

void handleChoice(TNode *root_ptr, int choice) {
    /* Handle the choice */
    double val;
    switch(choice) {
        case 1: *root_ptr = createTree(*root_ptr); 
                break;
        case 2: printf("Enter val: ");
                scanf("%lf", &val);
                *root_ptr = insertNode(*root_ptr, val);
                break;
        case 3: if (*root_ptr == NULL)
                    puts("Tree empty");
                inOrderTrav(*root_ptr);
                putchar('\n');
                break;
        case 4: if (*root_ptr == NULL)
                    puts("Tree empty");
                postOrderTrav(*root_ptr);
                putchar('\n');
                break;
        case 5: printf("Enter val: ");
                scanf("%lf", &val);
                *root_ptr = deleteNode(*root_ptr, val);
                break;
        case 6: *root_ptr = deleteTree(*root_ptr);
                break;
        default: fprintf(stderr, "Invalid Choice\n");
                 break;
    }
}

TNode createTree (TNode root) {
    int numNodes = 0;
    double val;
    for (;;) {
        printf("Enter val: ");
        scanf("%lf", &val);
        if (val == -1)
            break;
        root = insertNode(root, val);
        numNodes++;
    }
    printf("Inserted %d nodes\n", numNodes);
    return root;
}

void postOrderTrav(const TNode root) {
    /* Post Order Traversal of avl tree */
    if (root == NULL)
        return;
    postOrderTrav(root->left);
    postOrderTrav(root->right);
    printf("%g ", root->data);
}

void inOrderTrav(const TNode root) {
    /* Inorder Traversal of avl tree */
    if (root == NULL)
        return;
    inOrderTrav(root->left);
    printf("%g ", root->data);
    inOrderTrav(root->right);
}

TNode deleteTree(TNode root) {
    /* Delete the avl tree */
    if (root == NULL)
        return NULL;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
    return NULL;
}

TNode insertNode(TNode root, double val) {
    /* Insert a node into avl tree */
    // Perform standard bst insertion

    // This happens only when the root given to func is null,
    // i.e, either at the final recursive call or if 
    // the root is literally null at the start of tree creation
    if (root == NULL) {
        TNode newnode = malloc(sizeof(struct tree_node));
        if (!newnode) {
            fprintf(stderr, "Unable to allocate memory\n");
            exit(EXIT_FAILURE);
        }
        newnode->data = val;
        newnode->height = 1;
        newnode->left = newnode->right = NULL;
        return newnode;
    }

    if (val < root->data)
        root->left = insertNode(root->left, val);
    else    // allowing duplicate values here (add > only to avoid dup)
        root->right = insertNode(root->right, val);

    // Update height
    root->height = getHeight(root);

    // Magic happens here: check for the balance factors of the
    // ancestral nodes when recursive calls to insert return
    int balanceFactor = getBalance(root);
    // Left Heavy
    if (balanceFactor > 1) {
        // LR Case (Perform an additional left rotation to convert to LL)
        if (val >= root->left->data)
            root->left = leftRotate(root->left);
        // LL Case
        root = rightRotate(root);
    }
    // Right Heavy
    else if (balanceFactor < -1) {
        // RL Case (Perform an additional right rotation to convert to RR)
        if (val < root->right->data)
            root->right = rightRotate(root->right);
        // RR Case
        root = leftRotate(root);
    }
    return root;
}

TNode deleteNode(TNode root, double val) {
    /* Delete a node in avl tree */
    // Perform standard bst deletion
    if (root == NULL) {     // value is not found
        printf("Value: %g is not present in tree\n", val);
        return root;
    }
    // Traversal logic
    else if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if (val > root->data)
        root->right = deleteNode(root->right, val);
    else {                  // value is found
        switch(getDelCase(root)) {
            case 1: root = delCase1(root); break;
            case 2: root = delCase2(root); break;
            case 3: root = delCase3(root); break;
        }
    }
    if (root == NULL)
        return NULL;
    // Update Height
    root->height = getHeight(root);
    // Check if Unbalanced
    int balanceFactor = getBalance(root);
    // left heavy
    if (balanceFactor > 1) {
        // LR Case
        if (getHeight(root->right) > getHeight(root->left))
            root->right = leftRotate(root->right);
        // LL Case
        root = rightRotate(root);
    }
    // right heavy
    else if (balanceFactor < -1) {
        // RL case
        if (getHeight(root->left) > getHeight(root->right))
            root->left = rightRotate(root->left);
        // RR Case
        root = leftRotate(root);
    }
    return root;
}

TNode rightRotate(TNode root) {
    /* Perform right rotation on the node */
    // identify and save children
    TNode leftChild = root->left;
    TNode rightOfLeftChild = leftChild->right;

    // rotate
    leftChild->right = root;
    root->left = rightOfLeftChild;

    // Update heights
    root->height = getHeight(root);
    leftChild->height = getHeight(leftChild);

    // return as new root
    return leftChild;
}

TNode leftRotate(TNode root) {
    /* Perform left rotation on the given node */
    // save previous values
    TNode rightChild = root->right;
    TNode leftOfRightChild = rightChild->left;

    // rotate
    rightChild->left = root;
    root->right = leftOfRightChild;

    // Update height
    root->height = getHeight(root);
    rightChild->height = getHeight(rightChild);

    // return as node
    return rightChild;
}

int max(int a, int b) {
    /* Return the max of two numbers */
    return a > b ? a : b;
}

unsigned getHeight(const TNode node) {
    /* Return the height of subtree */
    if (node == NULL)
        return 0;
    return max(getHeight(node->left), getHeight(node->right)) + 1;
}

int getBalance(const TNode node) {
    /* Return the balance factor of the given node */
    return getHeight(node->left) - getHeight(node->right);
}

int getDelCase(TNode node) {
    /* Get the deletion Case for node */
    // Case 1: No children
    if (!node->left && !node->right)
        return 1;
    // Case 3: Both children
    else if (node->left && node->right)
        return 3;
    // Case 2: Either of one children
    else 
        return 2;
}

TNode delCase1(TNode node) {
    /* Deletion Case 1 (No children) */
    free(node);
    return NULL;
}

TNode delCase2(TNode node) {
    /* Delete Case 2 (Either one child) */
    TNode child = node->left ? node->left : node->right;
    free(node);
    return child;
}

TNode delCase3(TNode node) {
    /* Delete Case 3 (Both children) */
    // Find inorder predec
    TNode *predec = &node->left;
    while ((*predec)->right) {
        predec = &(*predec)->right;
    }
    // Copy data to current node
    node->data = (*predec)->data;
    // Delete predec node
    switch(getDelCase(*predec)) {
        case 1: *predec = delCase1(*predec); break;
        case 2: *predec = delCase2(*predec); break;
    }
    return node;
}

