#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node{
    int page;
    struct node *next;
    struct node *prev;
}node;

typedef struct lru{
    int size;
    node *head;
    node *tail;
}cache;

cache* createCache(int size){
    cache *c= malloc(sizeof(cache));
    c-> size = size;
    c-> head = NULL;
    c-> tail = NULL;
    return c;
}

node *insertNode(cache *c, int page){
    node *n = malloc(sizeof(node));
    n->page = page;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

void addNode(cache *c, int page){
    node *n = insertNode(c, page);
    if(c->head == NULL){
        c->head = n;
        c->tail = n;
    }else{
        c->tail->next = n;
        n->prev = c->tail;
        c->tail = n;
    }
}

void removeNode(cache *c, node *n){
    if(n->prev != NULL){
        n->prev->next = n->next;
    }else{
        c->head = n->next;
    }
    if(n->next != NULL){
        n->next->prev = n->prev;
    }else{
        c->tail = n->prev;
    }
    free(n);
}

void moveToHead(cache *c, node *n){
    if(n == c->head){
        return;
    }
    removeNode(c, n);
    addNode(c, n->page);
}

void printCache(cache *c){
    node *n = c->head;
    while(n != NULL){
        printf("%d ", n->page);
        n = n->next;
    }
    printf("\n");
}

int main(){
    cache *c = createCache(3);
    addNode(c, 1);
    addNode(c, 2);
    addNode(c, 3);
    addNode(c, 1);
    printCache(c);
    moveToHead(c, c->head->next);
    printCache(c);
    removeNode(c, c->head);
    printCache(c);
    return 0;
}

