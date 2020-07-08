#include "dll.h"
#include <stddef.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

typedef struct student_{
    int id;
    char name[32];
    int age;
    int height;
    dll_node_t glue;
} student_t;

void print_student_details(dll_node_t *node){
    student_t *student = (char *)node - offsetof(student_t, glue);
    printf("Name: %s\n", student->name);
    printf("ID: %d\n", student->id);
    printf("Age: %d\n", student->age);
    printf("Height: %d\n", student->height);
}

void print_student_db(dll_t *student_db){
    assert(student_db);
    dll_node_t *head = student_db->head;
    while(head){
        print_student_details(head);
        head = head->next;
    }
}

int match_student_record_by_key(void *node, void *key){
    dll_node_t *student_node = (dll_node_t *)node;
    student_t *student = (int *)node - offsetof(student_t, glue);
    int *id = (int *)key;
    if(student->id == id){
        return 0;
    }
    return -1;
}

int main(void) {
    student_t *student1 = calloc(1, sizeof(student_t));
    student1->id = 1;
    student1->age = 16;
    strncpy(student1->name, "Samson", strlen("Samson"));
    student1->height = 150;

    student_t *student2 = calloc(1, sizeof(student_t));
    student2->id = 2;
    student2->age = 16;
    strncpy(student2->name, "George", strlen("George"));
    student2->height = 150;

    student_t *student3 = calloc(1, sizeof(student_t));
    student3->id = 3;
    student3->age = 16;
    strncpy(student3->name, "Neena", strlen("Neena"));
    student3->height = 150;

    dll_t *student_db = dll_initilise();
    register_match_key(&student_db, match_student_record_by_key);
    dll_insert_node_at_the_tail(&student_db, &student1->glue);
    dll_insert_node_at_the_tail(&student_db, &student2->glue);
    dll_insert_node_at_the_tail(&student_db, &student3->glue);
    print_student_db(student_db);   
}