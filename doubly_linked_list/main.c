#include <stdio.h>
#include "doubly_linked_list.h"

int main(){
    Doubly_linked_list list = create_doubly_linked_list();
    printf("La liste est vide ? %d\n", is_empty(&list));
    display(&list);
    add(&list, 5);
    add(&list, 5);
    add(&list, 5);
    display(&list);
    insert_at_index(&list,2,1);
    display(&list);
}