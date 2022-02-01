// Implement Threaded Binary Search Tree

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>
#define DEBUG(elem,type) fprintf(stderr, #elem " = " type "\n", elem); \
                         fflush(stderr)
#define READVAL(elem,type,prompt) {    \
    int flag = 0;                      \
    while (!flag) {                    \
        printf(prompt);                \
        switch (scanf(type, &elem)) {  \
            case EOF: fprintf(stderr,                            \
                        "Unexpected EOF while reading value\n"); \
                      exit(EXIT_FAILURE);                        \
            case 0:   while (getchar() != '\n') ;                \
                      fprintf(stderr, "Invalid input\n");        \
                      break;     \
            case 1:   flag = 1;  \
                      break;     \
        } \
    }     \
}

// Thread Node
typedef struct tree_node {
    double data;
    struct tree_node *left, *right; // pointers to left and right child, or in
    bool rthread, lthread;          // case of threads, inord predec and successor
} *ThreadNode;                      // resp.

// Main Tree Functions
ThreadNode insertNode    (ThreadNode);
ThreadNode deleteNode    (ThreadNode);
ThreadNode createTree    (ThreadNode);
ThreadNode inorderTrav   (ThreadNode);
ThreadNode reverseInOrder(ThreadNode);

// Helpers
ThreadNode inordSuccessor(ThreadNode);
ThreadNode inorderPredec (ThreadNode);

// Delete Functions
int  getCase (ThreadNode);
void delCase1(ThreadNode *, ThreadNode *);
void delCase2(ThreadNode *);
void delCase3(ThreadNode *);

int main() {
    int choice;
    ThreadNode root = NULL;
    ThreadNode (*commands[]) (ThreadNode) = {createTree, insertNode, deleteNode,
                                             inorderTrav, reverseInOrder};
    for (;;) {
        puts(
                "***** Threaded Binary Tree *****\n"
                "1) Create Tree        2) Insert Node\n"
                "3) Delete Node        4) Inorder Traversal\n"
                "5) Reverse Inorder Traversal\n"
                "Command (-1 to exit):"
        );
        READVAL(choice, "%d", "");
        system("clear");
        if (choice < 1 || choice > 5) {
            if (choice == -1) break;
            puts("Invalid Choice");
            continue;
        }
        puts("Output:");
        root = commands[choice-1](root);
    }
    puts("Exit");
    return 0;
}

// Definitions
ThreadNode insertNode(ThreadNode root) {
    /* Insert a node (value) into the threaded bst */
    double val;
    READVAL(val, "%lf", "Enter val: ");
    ThreadNode parent = root;

    while (parent) {   // entry restricted for initial value of ptr
        // if value is less than node, traverse left if
        // node is not lthread or next is not null
        if (val < parent->data) {
            if (parent->lthread || parent->left == NULL)
                break;
            parent = parent->left;
        // or if value is greater, traverse right if
        // node is not leaf (rthread) or next is not null
        } else {
            if (parent->rthread || parent->right == NULL)
                break;
            parent = parent->right;
        }
    }

    // Initialize new node
    ThreadNode newNode = malloc(sizeof(struct tree_node));
    if (!newNode) {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = val;
    newNode->lthread = newNode->rthread = true;

    // Insert as root node if no tree exists,
    if (parent == NULL) {
        root = newNode;
        newNode->left = newNode->right = NULL;
    // Insert as left child if value <
    } else if (val < parent->data) {
        newNode->left = parent->left;
        newNode->right = parent;
        parent->left = newNode;
        parent->lthread = false;
    // Insert as right child if value >
    } else {
        newNode->right = parent->right;
        newNode->left = parent;
        parent->right = newNode;
        parent->rthread = false;
    }

    return root;
}

ThreadNode createTree(ThreadNode root) {
    /* Create a chain of nodes from user input */
    char choice;
    bool already_exists = (root != NULL);
    if (already_exists)
        puts("Tree exists; adding nodes...");
    int total_nodes = 0;
    for (;;) {
        if (total_nodes && total_nodes % 5 == 0) {
            READVAL(choice, " %c", "Continue? [y/N] ");
            if (tolower(choice) != 'y') break;
        }
        root = insertNode(root);
        ++total_nodes;
    }
    if (already_exists)
        printf("Appended %d nodes to already existing tree", total_nodes);
    else
        printf("Added %d nodes to newly create tree", total_nodes);
    putchar('\n');
    return root;
}

ThreadNode inorderTrav(ThreadNode root) {
    /* Travel the tree in-order without recursion using threadlinks */
    if (root == NULL) {
        puts("Tree Empty");
        return NULL;
    }
    ThreadNode ptr = root;
    while (ptr->left && !ptr->lthread)
        ptr = ptr->left;

    while (ptr) {
        printf("%g ", ptr->data);
        ptr = (ptr->rthread)         // if thread node,
              ? ptr->right           // right already contains succ
              : inordSuccessor(ptr); // else find inorder successor
    }
    putchar('\n');
    return root;
}

ThreadNode reverseInOrder(ThreadNode root) {
    /* Travel the tree in reverse in-order without recursion */
    if (root == NULL) {
        puts("Tree Empty");
        return NULL;
    }
    ThreadNode ptr = root;
    while (ptr->right && !ptr->rthread)
        ptr = ptr->right;
    while (ptr) {
        printf("%g ", ptr->data);
        ptr = (ptr->lthread)
              ? ptr->left
              : inorderPredec(ptr);
    }
    putchar('\n');
    return root;
}

ThreadNode inordSuccessor(ThreadNode root) {
    /* Find the inorder successor of the given root */
    if (root) {
        root = root->right;
        while (root && !root->lthread)
            root = root->left;
    }
    return root;
}

ThreadNode inorderPredec(ThreadNode root) {
    /* Find the inorder predecessor of given root */
    if (root) {
        root = root->left;
        while (root && !root->rthread)
            root = root->right;
    }
    return root;
}

int getCase(ThreadNode ptr) {
    /* Find the deletion case */
    int delCase = 0;
    // Case 1: Leaf Node
    if ((!ptr->left  || ptr->lthread)
            &&
        (!ptr->right || ptr->rthread))
        delCase = 1;
    // Case 3: Has both children
    else if ((ptr->left && ptr->right)
                &&
            (!ptr->lthread && !ptr->rthread))
        delCase = 3;
    // Case 2: Has either one children
    else
        delCase = 2;
    return delCase;
}

void delCase1(ThreadNode *tnode, ThreadNode *parent) {
    /* Delete the node with no children */
    if (parent == NULL) {
        free(*tnode);
        *tnode = NULL;
        return;
    }
    if ((*parent)->left == *tnode) {   // if left child of parent
        (*parent)->lthread = true;
        (*parent)->left = (*tnode)->left;
    } else {                           // if right child of parent
        (*parent)->rthread = true;
        (*parent)->right = (*tnode)->right;
    }
    free(*tnode);
}

void delCase2(ThreadNode *tnode) {
    /* Delete the node with only one children */
    bool hasLeftChild = ((*tnode)->left && !(*tnode)->lthread);
    ThreadNode child = hasLeftChild ? (*tnode)->left : (*tnode)->right;
    if (hasLeftChild)
        inorderPredec(*tnode)->right = (*tnode)->right;
    else
        inordSuccessor(*tnode)->left = (*tnode)->left;
    free(*tnode);       // free and replace
    *tnode = child;     // with child
}

void delCase3(ThreadNode *tnode) {
    /* Delete node with both children, reduce to either of case 1 or 2 */
    // Find node to delete (predecessor here, can use successor); Can't use
    // existing function as it returns pointer by value and not the actual predecessor node
    if (*tnode == NULL)
        return;
    ThreadNode *predecessor = &(*tnode)->left, *parent = NULL;
    for (;;) {
        if (!(*predecessor)->right || (*predecessor)->rthread)
            break;
        parent = predecessor;
        predecessor = &(*predecessor)->right;
    }
    
    assert((*predecessor) == inorderPredec(*tnode));
    (*tnode)->data = (*predecessor)->data;          // copy predecessor value
    if (parent) {                                   // if predecessor parent exists, (!= *tnode),
        (*parent)->rthread = true;                  // make its parent a thread that points to
        (*parent)->right = (*predecessor)->right;   // inorder successor (right ptr) of predec
    }
    switch(getCase(*predecessor)) {
        case 1 : delCase1(predecessor, parent); break;
        case 2 : delCase2(predecessor);         break;
    }
}

ThreadNode deleteNode(ThreadNode root) {
    /* Delete a node from threaded bst */
    if (!root) {
        puts("Tree Empty");
        return NULL;
    }
    double val;
    bool notFound = false;
    READVAL(val, "%lf", "Enter node to delete: ");
    ThreadNode *ptr = &root, *parent = NULL;
    // Find node to delete
    while ((*ptr)->data != val) {
        parent = ptr;
        if (val < (*ptr)->data) {
            if (!(*ptr)->left || (*ptr)->lthread) {
                notFound = true;
                break;
            }
            ptr = &(*ptr)->left;
        } else {
            if (!(*ptr)->right || (*ptr)->rthread) {
                notFound = true;
                break;
            }
            ptr = &(*ptr)->right;
        }
    }
    // Delete the node
    if (notFound)
        printf("%g not present in tree\n", val);
    else {
        int deletionCase = getCase(*ptr);
        printf("Value Found: %g\nDeletion Case: %d\n",
                val, deletionCase);
        switch(deletionCase) {
            case 1: delCase1(ptr, parent); break;
            case 2: delCase2(ptr);         break;
            case 3: delCase3(ptr);         break;
        }
    }
    return root; 
}

