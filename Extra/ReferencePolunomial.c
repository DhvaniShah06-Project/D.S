#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int expo;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->expo = e;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node into the polynomial in decreasing order of exponents
void insert(struct Node** poly, int c, int e) {
    struct Node* newNode = createNode(c, e);
    if (*poly == NULL || (*poly)->expo < e) {
        newNode->next = *poly;
        *poly = newNode;
    } else {
        struct Node* temp = *poly;
        while (temp->next && temp->next->expo > e)
            temp = temp->next;

        if (temp->expo == e)
            temp->coeff += c;
        else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

// Function to add two polynomials
struct Node* addPoly(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    while (poly1 && poly2) {
        if (poly1->expo == poly2->expo) {
            insert(&result, poly1->coeff + poly2->coeff, poly1->expo);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->expo > poly2->expo) {
            insert(&result, poly1->coeff, poly1->expo);
            poly1 = poly1->next;
        } else {
            insert(&result, poly2->coeff, poly2->expo);
            poly2 = poly2->next;
        }
    }

    while (poly1) {
        insert(&result, poly1->coeff, poly1->expo);
        poly1 = poly1->next;
    }

    while (poly2) {
        insert(&result, poly2->coeff, poly2->expo);
        poly2 = poly2->next;
    }

    return result;
}

// Function to print the polynomial
void printPoly(struct Node* poly) {
    while (poly) {
        printf("%dx^%d", poly->coeff, poly->expo);
        if (poly->next)
            printf(" + ");
        poly = poly->next;
    }
    printf("\n");
}

int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *sum = NULL;

    // Example polynomial: 3x^3 + 2x^2 + 1
    insert(&poly1, 3, 3);
    insert(&poly1, 2, 2);
    insert(&poly1, 1, 0);

    // Example polynomial: 5x^2 + 4x + 2
    insert(&poly2, 5, 2);
    insert(&poly2, 4, 1);
    insert(&poly2, 2, 0);

    printf("First Polynomial: ");
    printPoly(poly1);

    printf("Second Polynomial: ");
    printPoly(poly2);

    sum = addPoly(poly1, poly2);

    printf("Sum of Polynomials: ");
    printPoly(sum);

    return 0;
}