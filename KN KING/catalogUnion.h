// Use union-struct to make a catalog of items.
#define TITLE_LEN 20
#define AUTHOR_LEN 20
#define DESIGN_LEN 24

struct catalog_item {
    int stock_number;
    double price;
    int item_type;
    union {
        struct {
            char title[TITLE_LEN + 1];
            char author[AUTHOR_LEN + 1];
            int num_pages;
        } book;
        struct {
            char design[DESIGN_LEN + 1];
        } mug;
        struct {
            char design[DESIGN_LEN + 1];
            int colors;
            int sizes;
        } shirt;
    } item;
};