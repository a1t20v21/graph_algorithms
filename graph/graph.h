#ifndef _GRAPH_H
#define _GRAPH_H

#include "dll/dll.h"

#define GRAPH_MAX_NODES 50
#define GRAPH_MAX_NEIGHBOURS_PER_NODE 49

enum ARC_DIRECTION {N1_TO_N2, N2_TO_N1};

typedef struct g_node_ g_node_t;

typedef struct g_arc_{
    char name[32];
    g_node_t *n1;
    g_node_t *n2;
    unsigned int cost;    
    enum ARC_DIRECTION direction;
}g_arc_t;

typedef struct g_node_{
    char name[32];
    unsigned int no_of_neighbours;
    struct g_node_ *neighbours[GRAPH_MAX_NEIGHBOURS_PER_NODE];
    struct g_arc_ *out_arcs[GRAPH_MAX_NEIGHBOURS_PER_NODE];
    dll_node_t graph_dll_node;
}g_node_t;

dll_t * create_new_graph();
g_node_t * create_graph_node(dll_t *graph, char *node_name);
g_arc_t * create_graph_arc(g_node_t *node1, g_node_t *node2, unsigned int cost);
#endif