#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>

#include "graph.h"

void print_graph_node_details(dll_node_t *node){
    g_node_t *g_node = (char *)node - offsetof(g_node_t, graph_dll_node);
    printf("======Node Info - %s=======\n", g_node->name);
    printf("Number of neighbors: %d\n", g_node->no_of_neighbours);
    for(int i = 0; i < g_node->no_of_neighbours; i ++){
        g_arc_t *arc_temp = g_node->out_arcs[i];
        printf("Arc Name: %s\n", arc_temp->name);
        if(arc_temp->direction == N1_TO_N2){
            printf("Arc: %s --> %s, cost: %d \n", arc_temp->n1->name, arc_temp->n2->name, arc_temp->cost);
        }
    }
    printf("\n======xxxxxxxxxxxxxxxxxxxxx=======\n");
}

void print_graph_arcs(dll_t *graph){
    assert(graph);
    dll_node_t *head = graph->head;
    while(head){
        print_graph_node_details(head);
        head = head->next;
    }
}

int main(int argc, char **argv){
    dll_t *graph = create_new_graph();
    g_node_t *n1 = create_graph_node(graph, "1");
    g_node_t *n2 = create_graph_node(graph, "2");
    g_node_t *n3 = create_graph_node(graph, "3");
    g_node_t *n4 = create_graph_node(graph, "4");
    g_node_t *n5 = create_graph_node(graph, "5");
    g_node_t *n6 = create_graph_node(graph, "6");
    g_node_t *n7 = create_graph_node(graph, "7");
    /*
    * create_graph_arc(first, second, 2); - The arc is oriented from first to second
    */
    create_graph_arc(n1, n2, 2);
    g_arc_t *arc = create_graph_arc(n1, n3, 5);
    // printf("%s", n1->out_arcs[0]->name);
    create_graph_arc(n2, n3, 2);
    create_graph_arc(n2, n6, 4);
    create_graph_arc(n3, n4, 7);
    create_graph_arc(n3, n7, 2);
    create_graph_arc(n5, n4, 7);
    create_graph_arc(n6, n5, 6);
    create_graph_arc(n6, n7, 3);
    create_graph_arc(n7, n4, 2);
    create_graph_arc(n7, n5, 5);
    print_graph_arcs(graph);
}