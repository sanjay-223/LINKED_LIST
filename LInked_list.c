#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node *ptn;
typedef ptn list;
typedef ptn pos;

typedef int ele;

struct node
{
    ele data;
    struct node *next;
};

struct node *head;

/*struct head
{
    struct head *next;
};
*/

void insert(ele x, pos p)
{
    pos tmp;
    tmp = (ptn)malloc(sizeof(struct node));
    if((tmp!=NULL))
    {
        tmp->data=x;
        tmp->next=p->next;
        p->next=tmp;
    }
}

int isempty(struct head *h)
{
    return (h->next == NULL);
}

int islast(pos p)
{
    return (p->next == NULL);
}

pos find(list l, ele x)
{
    pos p = l;

    while((p != NULL) && (p->data != x))
        p = p->next;

    return p;
}

pos find_prev(list l, ele x)
{
    pos p = l;

    while((p->next != NULL) && (p->next->data != x))
        p=p->next;

    return p;
}

void disp(struct head *h)
{
    pos p;
    p = (ptn)malloc(sizeof(struct node));
    if(p!=NULL)
    {
        p = h;
        while(p->next!=NULL){
            printf("%d\n",p->next->data);
            p = p->next;
        }
    }
}

/*void create()
{
    int sz,a,i;
    printf("Enter size of list : ");
    scanf("%d",&sz);
    for(i=0;i<sz;i++)
    {
        printf("Enter Element : ");
        scanf("%d",&a);
        insert(a,l);
        l = l->next;
    }

}

void main()
{
    list l;
    l = (ptn)malloc(sizeof(struct node));
    l->next=NULL;
    struct head *h;
    h = (struct head*)malloc(sizeof(struct head));
    h->next=&l;

    create();
    disp(h);
}*/
