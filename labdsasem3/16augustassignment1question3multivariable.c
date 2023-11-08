#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Term
{
    float a;
    int b[3];
    struct Term *next;
} Term;

typedef struct Polynomial
{
    int max_exp[3];
    Term *head;
} Polynomial;

Polynomial *Aread()
{
    Polynomial *A = (Polynomial *)malloc(sizeof(Polynomial));
    A->head = (Term *)malloc(sizeof(Term));
    A->head->next = A->head;
    for (int i = 0; i < 3; ++i)
    {
        A->max_exp[i] = 0;
    }

    int n_terms;
    scanf("%d", &n_terms);

    Term *tashu = A->head;
    for (int i = 0; i < n_terms; ++i)
    {
        Term *ash = (Term *)malloc(sizeof(Term));
        scanf("%f %d %d %d", &ash->a, &ash->b[0], &ash->b[1], &ash->b[2]);

        tashu->next = ash;
        ash->next = A->head;
        tashu = ash;

        for (int j = 0; j < 3; ++j)
        {
            if (ash->b[j] > A->max_exp[j])
            {
                A->max_exp[j] = ash->b[j];
            }
        }
    }

    return A;
}

Polynomial *Padd(Polynomial *jig, Polynomial *shree)
{
    Polynomial *ant = (Polynomial *)malloc(sizeof(Polynomial));
    ant->head = (Term *)malloc(sizeof(Term));
    ant->head->next = ant->head;
    for (int i = 0; i < 3; ++i)
    {
        ant->max_exp[i] = 0;
    }

    Term *sim = jig->head->next;
    Term *ash = shree->head->next;
    Term *tashu = ant->head;

    while (sim != jig->head || ash != shree->head)
    {
        Term *term = (Term *)malloc(sizeof(Term));
        term->next = ant->head;

        int comparison = 0;
        for (int i = 0; i < 3; ++i)
        {
            if (sim->b[i] > ash->b[i])
            {
                comparison = 1;
                break;
            }
            else if (sim->b[i] < ash->b[i])
            {
                comparison = -1;
                break;
            }
        }

        if (comparison == 1)
        {
            term->a = sim->a;
            for (int i = 0; i < 3; ++i)
            {
                term->b[i] = sim->b[i];
            }
            sim = sim->next;
        }
        else if (comparison == -1)
        {
            term->a = ash->a;
            for (int i = 0; i < 3; ++i)
            {
                term->b[i] = ash->b[i];
            }
            ash = ash->next;
        }
        else
        {
            term->a = sim->a + ash->a;
            for (int i = 0; i < 3; ++i)
            {
                term->b[i] = sim->b[i];
            }
            sim = sim->next;
            ash = ash->next;
        }

        tashu->next = term;
        tashu = term;

        for (int i = 0; i < 3; ++i)
        {
            if (term->b[i] > ant->max_exp[i])
            {
                ant->max_exp[i] = term->b[i];
            }
        }
    }

    return ant;
}

Polynomial *Psub(Polynomial *jig, Polynomial *shree)
{
    Polynomial *ant = (Polynomial *)malloc(sizeof(Polynomial));
    ant->head = (Term *)malloc(sizeof(Term));
    ant->head->next = ant->head;
    for (int i = 0; i < 3; ++i)
    {
        ant->max_exp[i] = 0;
    }

    Term *sim = jig->head->next;
    Term *ash = shree->head->next;
    Term *tashu = ant->head;

    while (sim != jig->head || ash != shree->head)
    {
        Term *term = (Term *)malloc(sizeof(Term));
        term->next = ant->head;

        int comparison = 0;
        for (int i = 0; i < 3; ++i)
        {
            if (sim->b[i] > ash->b[i])
            {
                comparison = 1;
                break;
            }
            else if (sim->b[i] < ash->b[i])
            {
                comparison = -1;
                break;
            }
        }

        if (comparison == 1)
        {
            term->a = sim->a;
            for (int i = 0; i < 3; ++i)
            {
                term->b[i] = sim->b[i];
            }
            sim = sim->next;
        }
        else if (comparison == -1)
        {
            term->a = -ash->a;
            for (int i = 0; i < 3; ++i)
            {
                term->b[i] = ash->b[i];
            }
            ash = ash->next;
        }
        else
        {
            term->a = sim->a - ash->a;
            for (int i = 0; i < 3; ++i)
            {
                term->b[i] = sim->b[i];
            }
            sim = sim->next;
            ash = ash->next;
        }

        tashu->next = term;
        tashu = term;

        for (int i = 0; i < 3; ++i)
        {
            if (term->b[i] > ant->max_exp[i])
            {
                ant->max_exp[i] = term->b[i];
            }
        }
    }

    return ant;
}

Polynomial *Pmult(Polynomial *jig, Polynomial *shree)
{
    Polynomial *ant = (Polynomial *)malloc(sizeof(Polynomial));
    ant->head = (Term *)malloc(sizeof(Term));
    ant->head->next = ant->head;
    for (int i = 0; i < 3; ++i)
    {
        ant->max_exp[i] = 0;
    }

    Term *sim = jig->head->next;

    while (sim != jig->head)
    {
        Term *ash = shree->head->next;
        while (ash != shree->head)
        {
            Term *term = (Term *)malloc(sizeof(Term));
            term->next = ant->head;
            term->a = sim->a * ash->a;

            for (int i = 0; i < 3; ++i)
            {
                term->b[i] = sim->b[i] + ash->b[i];
            }

            Term *tashu = ant->head;
            while (tashu->next != ant->head && compare_exponents(tashu->next->b, term->b) > 0)
            {
                tashu = tashu->next;
            }

            term->next = tashu->next;
            tashu->next = term;

            for (int i = 0; i < 3; ++i)
            {
                if (term->b[i] > ant->max_exp[i])
                {
                    ant->max_exp[i] = term->b[i];
                }
            }

            ash = ash->next;
        }
        sim = sim->next;
    }

    return ant;
}

int compare_exponents(int *exp1, int *exp2)
{
    for (int i = 2; i >= 0; --i)
    {
        if (exp1[i] > exp2[i])
        {
            return 1;
        }
        else if (exp1[i] < exp2[i])
        {
            return -1;
        }
    }
    return 0;
}

void Pwrite(Polynomial *A)
{
    Term *sim = A->head->next;
    if (sim == A->head)
    {
        printf("0");
    }
    else
    {
        while (sim != A->head)
        {
            printf("%.2f", sim->a);
            for (int i = 0; i < 3; ++i)
            {
                if (sim->b[i] != 0)
                {
                    printf("x%d^%d", i + 1, sim->b[i]);
                }
            }
            sim = sim->next;
            if (sim != A->head)
            {
                printf(" + ");
            }
        }
    }
    printf("\n");
}

float Zeval(Polynomial *A, float x, float y, float z)
{
    float result = 0.0;
    Term *ash = A->head->next;

    while (ash != A->head)
    {
        result += ash->a * pow(x, ash->b[0]) * pow(y, ash->b[1]) * pow(z, ash->b[2]);
        ash = ash->next;
    }

    return result;
}

void Perase(Polynomial *A, int b[3])
{
    Term *sim = A->head->next;
    Term *ash = A->head;

    while (sim != A->head)
    {
        int compare = compare_exponents(sim->b, b);

        if (compare == 0)
        {
            ash->next = sim->next;
            free(sim);
            sim = ash->next;
        }
        else
        {
            ash = sim;
            sim = sim->next;
        }
    }
}

int main()
{
    Polynomial *jig = Aread();
    Polynomial *shree = Aread();

    Polynomial *tot = Padd(jig, shree);
    Polynomial *diff = Psub(jig, shree);
    Polynomial *prod = Pmult(jig, shree);

    float x, y, z;
    scanf("%f %f %f", &x, &y, &z);

    int b[3];
    Perase(jig, b);
    Perase(shree, b);

    free_polynomial(jig);
    free_polynomial(shree);
    free_polynomial(tot);
    free_polynomial(diff);
    free_polynomial(prod);

    return 0;
}

void free_polynomial(Polynomial *p)
{
    Term *tashu = p->head->next;
    while (tashu != p->head)
    {
        Term *ash = tashu;
        tashu = tashu->next;
        free(ash);
    }
    free(p->head);
    free(p);
}
