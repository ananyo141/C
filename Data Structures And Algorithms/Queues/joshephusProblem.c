// Solve the Josephus' Problem using queue implemented as circular linked list.

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int player_id;
    struct node *next;
} Node;

static void checkalloc(void *ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    int num_players, skips, i;
    printf("Enter number of players: ");
    scanf("%d", &num_players);
    printf("Enter number of skips: ");
    scanf("%d", &skips);

    // Construct the circular linked list
    Node *start=NULL, *currNode, *prevNode;
    for (i = 0; i < num_players; i++) {
        checkalloc(currNode = malloc(sizeof(Node)));
        currNode->player_id = i+1;
        if (start)
            prevNode->next = currNode;
        else
            start = currNode;
        prevNode = currNode;
    }
    if (start)
        currNode->next = start;

    // Play the russian roulette
    int turn;
    Node **ptr = &start, *temp;
    for (i = 0; i < num_players - 1; i++) {
        for (turn = 0; turn < skips - 1; turn++)
            ptr = &(*ptr)->next;

        // Delete the selected player (Linus Torvalds Style)
        temp = (*ptr)->next;
        free(*ptr);
        *ptr=temp;
    }
    printf("Player %d is the winner\n", (*ptr)->player_id);
    return 0;
}

