#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/* Function prototypes */

/* Print Functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Sorting Functions */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);


int lomuto_partition(int *array, int low, int high, size_t size);
void quick_sort_recursive(int *array, int low, int high, size_t size);


void swap_nodes(listint_t **list, listint_t *a, listint_t *b);
void forward_pass(listint_t **list, listint_t *start, listint_t *end, int *swapped);
void backward_pass(listint_t **list, listint_t *start, listint_t *end, int *swapped);


void counting_sort(int *array, size_t size);



#endif
