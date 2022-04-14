#include "stack.h"

Stack *init_stack() {
    Stack *s = (Stack*) malloc(sizeof(Stack));
    s->top = NULL;
    s->returned = NULL;
    s->r_size = 0;
    return s;
}


Stack* destroy_stack(Stack *s) {
    if (s) {
        while (s->top) {
            struct node *elem = s->top;
            s->top = s->top->next;
            if (elem->data)
                free(elem->data);
            free(elem);
        }
        if (s->returned) {
            for (size_t i = 0; i < s->r_size; i++)
                if (s->returned[i])
                    free(s->returned[i]);
            free(s->returned);
        }
        free(s);
    }
    return NULL;
}

int is_stack_empty(Stack *s) {
    int res = 1;
    if (s->top)
        res = 0;
    return res;
}


void push_stack(Stack *s, void *value, size_t v_size) {
    struct node *elem = (struct node*) malloc(sizeof(struct node));
    void *data = malloc(v_size);
    for (size_t i = 0; i < v_size; i++)
        *((char*) data + i) = *((char*) value + i);
    elem->data = data;
    elem->next = s->top;
    s->top = elem;
}

void *del_stack(Stack *s) {
    struct node *elem = s->top;
    void *res = NULL;
    if (elem) {
        s->top = s->top->next;
        res = elem->data;
        free(elem);
        void **tmp = s->returned;
        s->returned = realloc (tmp, ++(s->r_size) * sizeof(void*));
        s->returned[s->r_size - 1] = res;
    }
    return res;
}

void *top_stack(Stack *s) {
    void *res = NULL;
    if (s->top)
        res = s->top->data;
    return res;
}
