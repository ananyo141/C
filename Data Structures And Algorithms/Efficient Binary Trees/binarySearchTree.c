// Implement a Binary Search Tree

#include <stdio.h>
#include <stdlib.h>

// Tree node //
typedef struct tree_node {
    struct tree_node *left;
    double data;
    struct tree_node *right;
} TNode;

// prototypes //
int   totalNodes    (const TNode *);
int   totalExternal (const TNode *);
int   totalInternal (const TNode *);
int   heightTree    (const TNode *);
void  preorderTrav  (const TNode *);
void  inorderTrav   (const TNode *);
void  postorderTrav (const TNode *);
void  makeMirror    (TNode *);
void  deleteTree    (TNode *);
void  handleChoice  (int,    TNode **);
void  insertElem    (TNode **, double);
void  deleteElem    (TNode **, double);
const TNode *smallestElem (const TNode *);
const TNode *largestElem  (const TNode *);
const TNode *searchElem   (const TNode *,  double);

int main() {
    int choice;
    TNode *tree = NULL;
    for (;;) {
        puts(
                "       ******* Binary Search Tree *******\n"
                "1) Insert Element          8) Total Number of Nodes\n"
                "2) Preorder Traversal      9) Total External Nodes\n"
                "3) Inorder Traversal      10) Total Internal Nodes\n"
                "4) Postorder Traversal    11) Height Of Tree\n"
                "5) Smallest Element       12) Mirror Image\n"
                "6) Largest Element        13) Delete Tree\n"
                "7) Delete Element         14) Search Element\n"
                "Command (-1 to Exit):"
        );
        scanf("%d", &choice);
        system("clear");
        if (choice == -1) break;
        puts("Output:");
        handleChoice(choice, &tree);
        puts("Operation Completed Successfully");
    }
    puts("Exit");
    return 0;
}

// Definitions //
static void choice234 (void (*traveller) (const TNode *), const TNode *tree) {
    /* Handle choices 2,3,4; a similar routine for pre-, in- and
       post-order tree traversals */
    if (tree == NULL) {
        puts("Tree Empty");
        return;
    }
    traveller(tree);
    putchar('\n');
}

void handleChoice (int choice, TNode **tree_ptr) {
    /* Handler for choice selected by user */
    double val;
    const TNode *nodeptr;
    switch (choice) {
        case  1: for (;;) {
                    printf("Enter value: ");
                    scanf("%lf", &val);
                    if (val == -1) break;
                    insertElem(tree_ptr, val);
                 }
                 break;

        case  2: puts("Preorder Traversal:");
                 choice234(preorderTrav, *tree_ptr);
                 break;

        case  3: puts("Inorder Traversal:");
                 choice234(inorderTrav, *tree_ptr);
                 break;

        case  4: puts("Postorder Traversal:");
                 choice234(postorderTrav, *tree_ptr);
                 break;

        case  5: puts("Smallest Element:");
                 nodeptr = smallestElem(*tree_ptr);
                 if (!nodeptr) puts("Not found");
                 else printf("%g is the smallest\n", nodeptr->data);
                 break;

        case  6: puts("Largest Element:");
                 nodeptr = largestElem(*tree_ptr);
                 if (!nodeptr) puts("Not found");
                 else printf("%g is the largest\n", nodeptr->data);
                 break;

        case  7: printf("Enter val: ");
                 scanf("%lf", &val);
                 deleteElem(tree_ptr, val);
                 break;

        case  8: puts("Total Number of elements:");
                 val = totalNodes(*tree_ptr);
                 printf("The total number of elements (nodes): %g\n", val);
                 break;

        case  9: puts("Total Number of External Nodes:");
                 val = totalExternal(*tree_ptr);
                 printf("The total number of external nodes: %g\n", val);
                 break;

        case 10: puts("Total Number of Internal Nodes:");
                 val = totalInternal(*tree_ptr);
                 printf("The total number of internal nodes: %g\n", val);
                 break;

        case 11: puts("Height of Tree:");
                 val = heightTree(*tree_ptr);
                 printf("The height of tree: %g\n", val);
                 break;

        case 12: puts("Mirroring Tree");
                 makeMirror(*tree_ptr);
                 break;

        case 13: puts("Deleting Tree...");
                 deleteTree(*tree_ptr);
                 *tree_ptr = NULL;
                 break;

        case 14: printf("Enter value: ");
                 scanf("%lf", &val);
                 nodeptr = searchElem(*tree_ptr, val);
                 if (nodeptr)
                     printf("%g is present in the tree at %p\n",
                             val, nodeptr);
                 else
                     printf("%g is not present in the tree\n", val);
                 break;

        default: puts("Invalid choice"); 
                 break;
    }
}

void insertElem(TNode **tree, double val) {
    /* Insert an element in bst */
    if (*tree == NULL) {        // if found right place to insert node,
        TNode *newnode = malloc(sizeof(TNode));
        if (!newnode) {
            fprintf(stderr, "Unable to allocate memory\n");
            exit(EXIT_FAILURE);
        }
        newnode->data = val;
        newnode->left = newnode->right = NULL;
        *tree = newnode;        // set value of new node (insert)
    }
    else if (val < (*tree)->data)         // else, if value to be inserted is
        insertElem(&(*tree)->left, val);  // less than current node-val,
    else                                  // traverse left subtree,
        insertElem(&(*tree)->right, val); // or right subtree if greater
}

void preorderTrav(const TNode *tree) {
    /* Travel the bst in preorder (NLR) */
    if (tree == NULL)
        return;
    printf("%g ", tree->data);  // print the node data
    preorderTrav(tree->left);   // then traverse left subtree
    preorderTrav(tree->right);  // finally right subtree
}

void inorderTrav(const TNode *tree) {
    /* Travel the bst inorder (LNR) */
    if (tree == NULL)
        return;
    inorderTrav(tree->left);    // travel left subtree first
    printf("%g ", tree->data);  // then print node data
    inorderTrav(tree->right);   // travel right subtree
}

void postorderTrav(const TNode *tree) {
    /* Travel the bst in postorder (LRN) */
    if (tree == NULL)
        return;
    postorderTrav(tree->left);  // travel left subtree
    postorderTrav(tree->right); // travel right subtree
    printf("%g ", tree->data);  // finally print the node data
}

const TNode *smallestElem(const TNode *tree) {
    /* Find the smallest element in bst */
    if (tree == NULL || tree->left == NULL)  // if level 0 call has tree null,
        return tree;                         // return null, else if got to final left
    return smallestElem(tree->left);         // node in tree, return that left-est node
}

const TNode *largestElem(const TNode *tree) {
    /* Find the largest element in bst */
    if (tree == NULL || tree->right == NULL) // same as smallest element logic,
        return tree;                         // except here search for right-est
    return largestElem(tree->right);         // node in tree (largest element)
}

void deleteElem(TNode **tree_ptr, double val) {
    /* Delete an element from the bst */
    if (*tree_ptr == NULL) {
        puts("Value not found in tree");
        return;
    }
    // Traversal Logic
    if (val < (*tree_ptr)->data)
        return deleteElem(&(*tree_ptr)->left, val);
    else if (val > (*tree_ptr)->data)
        return deleteElem(&(*tree_ptr)->right, val);
    // Else, val is found in current node
    // Case 1: Node has no children (Leaf)
    if (!(*tree_ptr)->left && !(*tree_ptr)->right) {
        free(*tree_ptr);
        *tree_ptr = NULL;
    }
    // Case 2: Node has one child
    else if ((*tree_ptr)->left != NULL ^ (*tree_ptr)->right != NULL) {
        TNode *ptr = (*tree_ptr)->left 
                   ? (*tree_ptr)->left 
                   : (*tree_ptr)->right;
        free(*tree_ptr);
        *tree_ptr = ptr;
    }
    // Case 3: Node has two children
    else {
        double inorderPredecessor = largestElem((*tree_ptr)->left)->data;
        (*tree_ptr)->data = inorderPredecessor;             // reduce case to case 1 or 2
        deleteElem(&(*tree_ptr)->left, inorderPredecessor); // and delete inorder predec node
    }
}

int totalNodes(const TNode *tree) {
    /* Find the total number of nodes in
       the bst */
    if (tree == NULL)
        return 0;                       // if current tree is null, return 0,
    return totalNodes(tree->left)       // else, add total nodes for left subtree
         + totalNodes(tree->right)      // and that of right subtree,
         + 1;                           // and 1 for the current node
}

int totalExternal(const TNode *tree) {
    /* Find the total number of external (leaf)
       nodes in the bst */
    if (tree == NULL)                   // if tree is null, return 0
        return 0;
    else if (tree->right == NULL &&     // if leaf node, ie, no right and
             tree->left  == NULL)       // left subtrees, return 1
        return 1;
    return totalExternal(tree->left)    // else, return total leafs in left
         + totalExternal(tree->right);  // and right subtrees
}

int totalInternal(const TNode *tree) {
    /* Find the total number of internal (non-leaf) node,
       having atleast one child (left or right) node */
    if (tree == NULL   ||                    // if tree is null or
       (!tree->left && !tree->right))        // it is a leaf node (no children),
        return 0;                            // return 0
    return totalInternal(tree->left)         // else, return internal nodes in left
         + totalInternal(tree->right) + 1;   // and right trees, +1 for self
}

int heightTree(const TNode *tree) {
    /* Find the height of the bst */
    if (tree == NULL)                          // return 0 if base tree null
        return 0;
    int leftHeight  = heightTree(tree->left);  // find height of left subtree
    int rightHeight = heightTree(tree->right); // find height of right subtree
    if (leftHeight > rightHeight)
        return leftHeight + 1;      // return the greater of leftheight
    else                            // and rightheight (+1 for self)
        return rightHeight + 1;
}

void makeMirror(TNode *tree) {
    /* Flip the tree as in a mirror image */
    if (tree == NULL) return;
    makeMirror(tree->left);         // recursively traverse the left
    makeMirror(tree->right);        // and right trees first, down to leafs
    TNode *temp = tree->left;       // then swap the left and right
    tree->left = tree->right;       // tree pointers
    tree->right = temp;
}

void deleteTree(TNode *tree) {
    /* Delete the bst */
    if (tree == NULL) return;
    deleteTree(tree->left);         // recursively travel the entire
    deleteTree(tree->right);        // tree, then free node
    free(tree);
}

const TNode *searchElem(const TNode *tree, double val) {
    /* Find an element in the bst */
    if (tree == NULL || tree->data == val)    // if found, return node *, else null
        return tree;
    else if (val < tree->data)
        return searchElem(tree->left, val);   // or if search val is less than tree data,
    else                                      // traverse left subtree
        return searchElem(tree->right, val);  // otherwise travel right subtree
}

