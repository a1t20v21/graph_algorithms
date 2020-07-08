#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "graph.h"

dll_t * create_new_graph(){
    dll_t *graph = dll_initilise(); 
    return graph;
}

g_node_t * create_graph_node(dll_t *graph, char *node_name){
    g_node_t *g_node = calloc(1, sizeof(g_node_t));
    strcpy(g_node->name, node_name);
    g_node->no_of_neighbours = 0;
    dll_insert_node_at_the_tail(graph, &g_node->graph_dll_node);
    return g_node;
}

int search_arcs_for_node(g_node_t *node){
    assert(node);
    return 0;
}

/*
* create_graph_arc(first, second, cost); - The arc is oriented from first to second
*/
g_arc_t * create_graph_arc(g_node_t *node1, g_node_t *node2, unsigned int cost){
    assert(node1);
    assert(node2);
    g_arc_t *arc = calloc(1, sizeof(g_arc_t));
    strcat(arc->name, node1->name);
    strcat(arc->name, "-to-");
    strcat(arc->name, node2->name);
    arc->n1 = node1;
    arc->n2 = node2;
    arc->cost = cost;
    arc->direction = N1_TO_N2;
    if(node1->no_of_neighbours == 0){
        node1->neighbours[0] = node2;
        node1->out_arcs[0] = arc;
    } else {
        node1->neighbours[node1->no_of_neighbours] = node2;
        node1->out_arcs[node1->no_of_neighbours] = arc;
        
    }
    node1->no_of_neighbours++;
    return arc;
}
