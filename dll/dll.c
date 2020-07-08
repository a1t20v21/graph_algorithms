#include "dll.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

dll_node_t * search_list_for_node(dll_t *dll, void *key); 

void register_match_key(dll_t *dll, int (*match_key)(void *, void *)){
    dll->match_key = match_key;
}

dll_t * dll_initilise(){
    dll_t *dll = calloc(1, sizeof(dll_t));
    dll->head = NULL;
    dll->tail = NULL;
    dll->size = 0;
    return dll;
}

int dll_insert_node_at_the_tail(dll_t *dll, dll_node_t *node){
    assert(dll);
    assert(node);
 
    /*insertion of the first node in the list*/
    if(dll && !dll->head){
        node->next = NULL;
        node->prev = NULL;
        dll->head = node;
        dll->tail = node;
        dll->size++;
        return EXIT_SUCCESS;
    }

    /*Node is the not the first in the list*/
    dll->tail->next = node;
    node->prev = dll->tail;
    node->next = NULL;
    dll->tail = node;
    dll->size++;
    return EXIT_SUCCESS;
}

/*
* Search the list for node
*/
dll_node_t * search_list_for_node(dll_t *dll, void *key) {
    dll_node_t *head = dll->head;

    while(head) {
        if(dll->match_key(head, key)){
            return head;
        }
        head = head->next;
    }
    return NULL;
}

/*
*
* Delete the node from the list that contains the data pointed to by *data;
*/
dll_node_t * dll_delete_node(dll_t *dll, void *key){
    assert(dll && dll->head);
    assert(key);

    dll_node_t *node;
    if(!(node = search_list_for_node(dll, key))){
        perror("object with the given key does not exist\n");
        return NULL;
    }

    node->prev->next = node->next;
    node->next->prev = node->prev;   
    node->next = node->prev = NULL;
    return node;
}