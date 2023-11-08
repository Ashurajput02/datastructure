#include <iostream>
using namespace std;
struct node
{
    int value;
    struct node *next;
    struct node *child;
};

struct node *head = NULL;

struct node *create(struct node *head, int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->value = x;
    temp->child = NULL;
    temp->next = NULL;
    return temp;
}
void createnode(int u, int v, int type)
{
    struct node *temp = head;
    struct node *ptr1 = NULL;
    struct node *ptr2 = NULL;
    while (temp != NULL)
    {
        if (temp->value == u)
        {
            ptr1 = temp;
        }
        if (temp->value == v)
            ptr2 = temp;
    }

    if (ptr1 != NULL && ptr2 == NULL)
        ptr2 = create(ptr2, v);
    else if (ptr1 == NULL && ptr2 != NULL)
    {
        ptr1 = create(ptr1, u);
    }
    else if (ptr1 == NULL && ptr2 == NULL)
    {
        ptr1 = create(ptr1, u);
        ptr2 = create(ptr2, v);
        head = ptr1;
    }
    if (type == 0)
    {
        ptr1->next = ptr2;
    }
    else if (type == 1)
        ptr1->child = ptr2;
}
void printer()
{
    struct node *temp1 = head;

    while (temp1 != NULL)
    {
        cout << temp1->value << " ";
        if (temp1->child != NULL)
        {
            int i = 0;
            struct node *arr[100];
            struct node *temp2 = temp1->child;
            while (temp2 != NULL)
            {
                cout << temp2->value << " ";
                if (temp2->next != NULL)
                    arr[i++] = temp2->next;
            }
            temp2 = temp2->child;
            while (i >= 0)
            {
                struct node *temp = arr[i];
                while (temp->next != NULL)
                {
                    cout << temp->value << " ";
                    temp = temp->next;
                }
                i--;
            }
        }
        temp1 = temp1->next;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n - 1; i++)
        {
            int u, v, type;
            cin >> u >> v >> type;
            createnode(u, v, type);
        }
        printer();
    }
}
