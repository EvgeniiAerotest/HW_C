#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

typedef struct list
{
    char word[20];
    struct list *next;
} list;

void add_to_list(list **head, char *text)
{
    list *new = calloc(1, sizeof(list));
    strncpy(new->word, text, 19);
    if (*head == NULL)
    {
        *head = new;
    }
    else
    {
        list *p = *head;
        while (p->next != NULL)
            p = p->next;
        p->next = new;
    }
}

void print_list(list *p)
{
    while (p)
    {
        printf("%s ", p->word);
        p = p->next;
    }
    printf("\n");
}

void delete_list(list *p)
{
    list *tmp;
    while (p)
    {
        tmp = p;
        p = p->next;
        free(tmp);
    }
}

void swap_elements(list *a, list *b)
{
    char temp[20];
    strncpy(temp, a->word, 19);
    strncpy(a->word, b->word, 19);
    strncpy(b->word, temp, 19);
}

void sort_list(list *p)
{
    int swapped;
    list *ptr;
    do
    {
        swapped = 0;
        ptr = p;
        while (ptr->next != NULL)
        {
            if (strcmp(ptr->word, ptr->next->word) > 0)
            {
                swap_elements(ptr, ptr->next);
                swapped = 1;
            }
            ptr = ptr->next;
        }
    } while (swapped);
}

int main(void)
{
    list *L = NULL;
    int word_count = 0;
    char str[SIZE] = {0};
    scanf("%[^.]", str);
    char *word = strtok(str, " ");
    while (word != NULL && word_count < 100)
    {
        add_to_list(&L, word);
        word_count++;
        word = strtok(NULL, " ");
    }
    sort_list(L);
    print_list(L);
    delete_list(L);

    return 0;
}
