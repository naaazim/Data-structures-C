#include <stdio.h>
#include "linked_list.h"

int main(int argc, char **argv){
    Linked_list list = create_linked_list();
    add(&list, 2);
    add(&list, 265);
    add(&list, 2423);
    add(&list, 23);
    add(&list, 3);
    display(&list);
    pop(&list);
    pop(&list);
    pop(&list);
    pop(&list);
    pop(&list);
    display(&list);
    printf(is_empty(&list) ? "Vide\n" : "Non vide\n");
}