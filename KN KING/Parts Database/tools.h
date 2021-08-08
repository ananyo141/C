#ifndef tools
#define tools

#define NAME_LEN 25
#define MAX_PARTS 100
#define COMMAND_LEN 10

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};
// variable declaration
extern struct part *inventory;
extern int space_available;

// function declarations
int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void expand(int req_space);
bool is_full(void);

#endif