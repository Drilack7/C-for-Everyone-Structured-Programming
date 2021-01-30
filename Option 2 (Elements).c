/* Program that prints the first 10 elements of 
the periodic table through a list 
25/11/2020, Christos Drilakis */

//First include preprocessing files
#include <stdio.h>
#include <stdlib.h>

//Declarations
typedef struct element{char name[15]; char symbol[10]; float weight; } element;
typedef struct list{element el; struct list *next;} list;

//Function that creates a single element list (as showed in class)
list* create_list(element e)
{
    list* head = malloc(sizeof(list));
    head->el = e;
    head->next = NULL;
    return head;
}

//Function that adds elements to the list (as showed in class)
list* add_to_front(element e, list* h)
{
    list* head = create_list(e);
    head->next = h;
    return head;
}

//Function that transforms an array to list (as showed in class)
list* array_to_list(element e[], int size)
{
    list* head = create_list(e[0]);
    int i;
    for (i=1; i<size; i++)
    {
        head = add_to_front(e[i], head);
    }
    return head;
}

// Function that prints the info from the element struct
void print_element(element* e)
{
    printf("The element %s with symbol %s has atomic weight of %.3f\n", e->name, e->symbol, e->weight);
}

// Function that prints the list elements
void print_list(list *h, char *title)
{
    printf("%s\n", title);
    while (h != NULL)
    {
        print_element(&h->el);
        h = h->next;
    }
}

int main()
{
    //Initialize the list
    list* head = NULL;
    //Initialize the elements to be printed
    element e1 = {"Neon", "Ne", 20.180};
    element e2 = {"Fluorine", "F", 	18.998};
    element e3 = {"Oxygen", "O", 15.999};
    element e4 = {"Nitrogen", "N", 14.007};
    element e5 = {"Carbon", "C", 12.011};
    element e6 = {"Boron", "B", 10.811};
    element e7 = {"Beryllium", "Be", 9.012};
    element e8 = {"Lithium", "Li", 6.941};
    element e9 = {"Helium", "He", 4.003};
    element e10 = {"Hydrogen", "H", 1.008};
    //Make an array of the elements for the array_to_list function
    element el[10] = {e1, e2, e3, e4, e5, e6, e7, e8, e9, e10};
    head = array_to_list(el, 10);
    //Print the elements of the list (from last to first)
    print_list(head, "Elements list");
    printf("\n\n");
    return 0;
}
