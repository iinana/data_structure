#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct STUDENT
{
    int id;
    char name[20];
    struct STUDENT *next;
} Student;

int Add(Student **h, int id, char *name)
{
    Student *s = (Student *)malloc(sizeof(Student));
    strcpy(s->name, name);
    s->id = id;
    s->next = NULL;

    if ((*h) == NULL) *h = s;
    else if ((*h)->id == id) 
    {
        free(s);
        return 0;
    }
    else if ((*h)->id > id) 
    {
        s->next = *h;
        *h = s;
    }
    else 
    {   
        Student *curr = *h;
        while ((curr->next) && (curr->next->id < id)) curr = curr->next; 
        if (curr->next)
        {
            if (curr->next->id == id)
            {
                free(s);
                return 0;
            }
            s->next = curr->next;
            curr->next = s;
        }
        else curr->next = s;
    }
    return 1;
}

void print_linked(Student *h, FILE *out)
{
    while (h)
    {
        fprintf(out, "%d %s ", h->id, h->name);
        h = h->next;
    }
    fputc('\n', out);
}

int Delete(Student **h, int id)
{
    if (id == (*h)->id)
    {
        *h = (*h)->next;
        return 1;
    }

    Student *curr = (*h)->next;
    Student *prev = *h;
    while (curr && (curr->id != id))
    {
        prev = curr;
        curr = curr->next;
    }
    if (!curr) return 0;
    else
    {
        prev->next = curr->next;
        free(curr);
        return 1;
    }
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Correct Usage : [program] [intput file] [output file]");
        return 0;
    }

    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");

    if ((input == NULL) || (output == NULL))
    {
        printf("Failed to Open File");
        return 0;
    }

    char c;
    int id;
    Student *h = (Student *)malloc(sizeof(Student));
    h = NULL;
    while ((c = fgetc(input)) != EOF)
    {
        if (c == '\n') continue;
        else if (c == 'A')
        {
            int id;
            fscanf(input, "%d", &id);

            char name[20];
            fscanf(input, "%s", name);

            if (Add(&h, id, name)) print_linked(h, output);
            else fputs("Addition Failed\n", output);
        }
        else if (c == 'D')
        {
            int id;
            fscanf(input, "%d", &id);

            if (Delete(&h, id)) print_linked(h, output);
            else fputs("Deletion Failed\n", output);
        }
        else if (c == 'F')
        {
            int id;
            fscanf(input, "%d", id);
        }
        else fputs("FUNCTION ERROR\n", output);
    }

    fclose(input);
    fclose(output);
    while (h)
    {
        free(h);
        h = h->next;
    }
}