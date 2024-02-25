#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 *                       using the Insertion sort algorithm
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *sorted = NULL, *curr = *list, *next;

    while (curr)
    {
        next = curr->next;
        if (sorted == NULL || sorted->n > curr->n)
        {
            curr->next = sorted;
            sorted = curr;
        }
        else
        {
            listint_t *aux = sorted;
            while (aux->next && aux->next->n <= curr->n)
                aux = aux->next;
            curr->next = aux->next;
            aux->next = curr;
            curr->prev = aux;
            if (curr->next)
                curr->next->prev = curr;
        }
        curr = next;
        print_list(*list);
    }
    *list = sorted;
}
