#ifndef __DLL__
#define __DLL__

typedef struct dll_node_{
    struct dll_node_ *next;
    struct dll_node_ *prev;
} dll_node_t;

typedef struct dll_{
    dll_node_t *head;
    dll_node_t *tail;
    unsigned int size;
    int (*match_key)(void *, void*);
} dll_t;

dll_t * dll_initilise();
void register_match_key(dll_t *, int (*match_key)(void *, void *));
int dll_insert_node_at_the_tail(dll_t *dll, dll_node_t *node);
dll_node_t * dll_delete_node(dll_t *dll, void *key);
#endif