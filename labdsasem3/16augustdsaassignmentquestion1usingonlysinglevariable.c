#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Term {
    float a;
    int b;
    struct Term* next;
} Term;

typedef struct Polynomial {
    int max_exp;
    Term* head;
} Polynomial;

Polynomial* Aread() {
    Polynomial* A = (Polynomial*)malloc(sizeof(Polynomial));
    A->head = (Term*)malloc(sizeof(Term));
    A->head->next = A->head;
    A->max_exp = 0;

    int n_terms;
    printf("Enter number of terms in polynomial A: ");
    scanf("%d", &n_terms);
    printf("\n");

    Term* tashu = A->head;
    for (int i = 0; i < n_terms; ++i) {
        Term* ash = (Term*)malloc(sizeof(Term));
        printf("Enter coefficient and exponents of term %d: ", (i + 1));
        scanf("%f %d", &ash->a, &ash->b);

        tashu->next = ash;
        ash->next = A->head;
        tashu = ash;

        if (ash->b > A->max_exp) {
            A->max_exp = ash->b;
        }
        printf("\n");
    }

    return A;
}

void Pwrite(Polynomial* A) {
    Term* sim = A->head->next;
    if (sim == A->head) {
        printf("0");
    } else {
        while (sim != A->head) {
            printf("%.2fx^%d", sim->a, sim->b);
            sim = sim->next;
            if (sim != A->head) {
                printf(" + ");
            }
        }
    }
    printf("\n");
}

Polynomial* Padd(Polynomial* jig, Polynomial* shree) {
    Polynomial* ant = (Polynomial*)malloc(sizeof(Polynomial));
    ant->head = (Term*)malloc(sizeof(Term));
    ant->head->next = ant->head;
    ant->max_exp = 0;

    Term* sim = jig->head->next;
    Term* ash = shree->head->next;
    Term* tashu = ant->head;

    while (sim != jig->head || ash != shree->head) {
        Term* term = (Term*)malloc(sizeof(Term));
        term->next = ant->head;

        if (sim->b > ash->b) {
            term->a = sim->a;
            term->b = sim->b;
            sim = sim->next;
        } else if (ash->b > sim->b) {
            term->a = ash->a;
            term->b = ash->b;
            ash = ash->next;
        } else {
            term->a = sim->a + ash->a;
            term->b = sim->b;
            sim = sim->next;
            ash = ash->next;
        }

        tashu->next = term;
        tashu = term;

        if (term->b > ant->max_exp) {
            ant->max_exp = term->b;
        }
    }

    return ant;
}

Polynomial* Psub(Polynomial* jig, Polynomial* shree) {
    Polynomial* ant = (Polynomial*)malloc(sizeof(Polynomial));
    ant->head = (Term*)malloc(sizeof(Term));
    ant->head->next = ant->head;
    ant->max_exp = 0;

    Term* sim = jig->head->next;
    Term* ash = shree->head->next;
    Term* tashu = ant->head;

    while (sim != jig->head || ash != shree->head) {
        Term* term = (Term*)malloc(sizeof(Term));
        term->next = ant->head;

        if (sim->b > ash->b) {
            term->a = sim->a;
            term->b = sim->b;
            sim = sim->next;
        } else if (ash->b > sim->b) {
            term->a = -ash->a;
            term->b = ash->b;
            ash = ash->next;
        } else {
            term->a = sim->a - ash->a;
            term->b = sim->b;
            sim = sim->next;
            ash = ash->next;
        }

        tashu->next = term;
        tashu = term;

        if (term->b > ant->max_exp) {
            ant->max_exp = term->b;
        }
    }

    return ant;
}

Polynomial* Pmult(Polynomial* jig, Polynomial* shree) {
    Polynomial* ant = (Polynomial*)malloc(sizeof(Polynomial));
    ant->head = (Term*)malloc(sizeof(Term));
    ant->head->next = ant->head;
    ant->max_exp = 0;

    Term* sim = jig->head->next;

    while (sim != jig->head) {
        Term* ash = shree->head->next;
        while (ash != shree->head) {
            Term* term = (Term*)malloc(sizeof(Term));
            term->next = ant->head;
            term->a = sim->a * ash->a;
            term->b = sim->b + ash->b;

            Term* tashu = ant->head;
            while (tashu->next != ant->head && tashu->next->b > term->b) {
                tashu = tashu->next;
            }

            term->next = tashu->next;
            tashu->next = term;

            if (term->b > ant->max_exp) {
                ant->max_exp = term->b;
            }

            ash = ash->next;
        }
        sim = sim->next;
    }

    return ant;
}

float Zeval(Polynomial* A, float x) {
    float tashu = 0.0;
    Term* ash = A->head->next;

    while (ash != A->head) {
        tashu += ash->a * pow(x, ash->b);
        ash = ash->next;
    }

    return tashu;
}

void Perase(Polynomial* A, int b) {
    Term* sim = A->head->next;
    Term* ash = A->head;

    while (sim != A->head) {
        if (sim->b == b) {
            ash->next = sim->next;
            free(sim);
            sim = ash->next;
        } else {
            ash = sim;
            sim = sim->next;
        }
    }
}

int main() {
    Polynomial* jig = Aread();
    Polynomial* shree = Aread();

    printf("Polynomial A: ");
    Pwrite(jig);
    printf("Polynomial B: ");
    Pwrite(shree);

    Polynomial* tot = Padd(jig, shree);
    printf("Sum (A + B): ");
    Pwrite(tot);

    Polynomial* diff = Psub(jig, shree);
    printf("Difference (A - B): ");
    Pwrite(diff);

    Polynomial* prod = Pmult(jig, shree);
    printf("Product (A * B): ");
    Pwrite(prod);

    float x;
    printf("Write a value at which you want to evaluate the polynomials: ");
    scanf("%f", &x);
    printf("\n");
    printf("Evaluation of Polynomial A at %.2f: %.2f\n", x, Zeval(jig, x));
    printf("Evaluation of Polynomial B at %.2f: %.2f\n", x, Zeval(shree, x));

    int b;
    printf("Write the exponent of term you want to remove from Polynomial A: ");
    scanf("%d", &b);
    Perase(jig, b);
    printf("\nPolynomial A after erasing term with exponent %d: ", b);
    Pwrite(jig);
    printf("\n");
    printf("Enter the exponent of term you want to erase from polynomial B: ");
    scanf("%d", &b);
    Perase(shree, b);
    printf("Polynomial B after erasing term with exponent %d: ", b);
    Pwrite(shree);

    Term* tashu = jig->head->next;
    while (tashu != jig->head) {
        Term* ash = tashu;
        tashu = tashu->next;
        free(ash);
    }
    free(jig->head);
    free(jig);

    tashu = shree->head->next;
    while (tashu != shree->head) {
        Term* ash = tashu;
        tashu = tashu->next;
        free(ash);
    }
    free(shree->head);
    free(shree);

    tashu = tot->head->next;
    while (tashu != tot->head) {
        Term* ash = tashu;
        tashu = tashu->next;
        free(ash);
    }
    free(tot->head);
    free(tot);

    tashu = diff->head->next;
    while (tashu != diff->head) {
        Term* ash = tashu;
        tashu = tashu->next;
        free(ash);
    }
    free(diff->head);
    free(diff);

    tashu = prod->head->next;
    while (tashu != prod->head) {
        Term* ash = tashu;
        tashu = tashu->next;
        free(ash);
    }
    free(prod->head);
    free(prod);

    return 0;
}
