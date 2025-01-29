#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
// список о выделенной памяти
typedef struct list
{
    uint64_t address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

list *memlist = NULL;

// добавление  информация в однонаправленный список о новом блоке выделенной памяти
void insert(list **head, uint64_t address, size_t size, char *comment)
{
    list *tmp = malloc(sizeof(list));
    tmp->next = *head;
    tmp->address = address;
    tmp->size = size;
    sprintf(tmp->comment, "%s", comment);
    *head = tmp;
}

_Bool delete(list **head, uint64_t address)
{
    if (*head == NULL) // если списко пустой - выходим
        return 0;
    list *del = NULL;
    if ((*head)->address == address)
    {
        del = *head;
        *head = (*head)->next;
        free(del);
        return 1;
    }
    list *tmp = *head;
    while (tmp->next)
    {
        if (tmp->next->address == address)
        {
            del = tmp->next;
            tmp->next = del->next;
            free(del);
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

void printList(list *head)
{
    if (head == NULL)
    {
        printf("No memory leak detect\n");
    }
    while (head)
    {
        printf("%s [%zu]\n", head->comment, head->size);
        head = head->next;
    }
}

uint64_t findMaxBlock(list *head)
{
    if (head == NULL)
    {
        return 0;
    }

    list *tmp = head;
    uint64_t maxAddress = tmp->address;
    size_t maxSize = tmp->size;

    tmp = tmp->next;

    while (tmp != NULL)
    {
        if (tmp->size > maxSize)
        {
            maxSize = tmp->size;
            maxAddress = tmp->address;
        }
        tmp = tmp->next;
    }
    return maxAddress;
}

size_t totalMemoryUsage(list *head)
{
    if (head == NULL)
    {
        return 0;
    }

    list *tmp = head;
    size_t Size = tmp->size;

    tmp = tmp->next;

    while (tmp != NULL)
    {
        Size += tmp->size;
        tmp = tmp->next;
    }

    return Size;
}

void *my_malloc(size_t size, const char *file, int line, const char *func)
{
    void *ptr = malloc(size);
    char coment[64] = {0};
    sprintf(coment, "Allocated = %s, %i, %s, %p", file, line, func, (uint64_t)ptr);
    insert(&memlist, (uint64_t)ptr, size, coment);
    return ptr;
}

void my_free(void *ptr, const char *file, int line, const char *func)
{
    delete (&memlist, (uint64_t)ptr);
    free(ptr);
}

// макрос, который заменяет стандартный вызов функции malloc() на вызов функции  my_malloc() и аналогичный макрос для вызова функции free()
#define malloc(X) my_malloc((X), __FILE__, __LINE__, __FUNCTION__)
#define free(X) my_free((X), __FILE__, __LINE__, __FUNCTION__)

int main(void)
{
    int *p = malloc(1); // my_malloc
    //~ int *p  = my_malloc( sizeof(int), __FILE__, __LINE__, __FUNCTION__ );//my_malloc
    int *ar = malloc(sizeof(int));
    *p = 5;
    // free(p);
    p = malloc(sizeof(int) * 10);

    // free(p);
    printList(memlist);
    printf("Address of max block is %p\n", findMaxBlock(memlist));
    printf("Total memory usage: %d bytes\n", totalMemoryUsage(memlist));
    return 0;
}