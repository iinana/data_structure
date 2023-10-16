#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct STUDENT
{
    int id;
    char name[20];
    struct STUDENT *next;
} Student;

typedef struct COURSE
{
    Student *head;
} Course;

int isEmpty(Course *c)
{
    return (c->head == NULL);
}

int Add(Course *c, int id, char *name)
{
    if (isEmpty(c))
    {
        c->head = (Student *)malloc(sizeof(Student));
        c->head->next = NULL;
        c->head->id = id;
        strcpy(c->head->name, name);
        return 1;
    }
    if (c->head->id == id) return 0;
    

    Student *h = c->head;
    Student *s = (Student *)malloc(sizeof(Student));
    strcpy(s->name, name);
    s->id = id;
    s->next = NULL;

    if (h->id > id)
    {
        s->next = h;
        c->head = s;
        return 1;
    }

    while ((h->next) && (h->next->id < id)) h = h->next; 
    if (h->next)
    {
        if (h->next->id == id)
        {
            free(s);
            return 0;
        }
        s->next = h->next;
        h->next = s;
    }
    else h->next = s;
    return 1;
}

void print_linked(Course *c, FILE *out)
{
    Student *h = c->head;
    while (h)
    {
        fprintf(out, "%d %s ", h->id, h->name);
        h = h->next;
    }
    fputc('\n', out);
}

int Delete(Course *c, int id)
{
    if (isEmpty(c)) return 0;

    Student *prev = c->head;
    Student *curr = prev->next;
    if (id == prev->id)
    {
        c->head = curr;
        free(prev);
        return 1;
    }

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

Student *Find(Course *c, int id)
{
    if (isEmpty(c)) return NULL;

    Student *h = c->head;
    while (h)
    {
        if (h->id == id) return h;
        h = h->next;
    }
    return NULL;
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

    char ch;
    int id;
    Course *c = (Course *)malloc(sizeof(Course));
    c->head = NULL;
    while ((ch = fgetc(input)) != EOF)
    {
        if (ch == '\n') continue;
        else if (ch == 'A')
        {
            int id;
            fscanf(input, "%d", &id);

            char name[20];
            fscanf(input, "%s", name);

            if (Add(c, id, name)) print_linked(c, output);
            else fputs("Addition Failed\n", output);
        }
        else if (ch == 'D')
        {
            int id;
            fscanf(input, "%d", &id);

            if (Delete(c, id)) print_linked(c, output);
            else fputs("Deletion Failed\n", output);
        }
        else if (ch == 'F')
        {
            int id;
            fscanf(input, "%d", &id);
            Student *q = Find(c, id);
            if (q) fprintf(output, "%d %s\n", q->id, q->name);
            else fputs("Search Failed\n", output);
        }
        else 
        {
            fputs("FUNCTION ERROR\n", output);
            while((ch = fgetc(input)) != '\n') continue;
        }
    }

    fclose(input);
    fclose(output);
    free(c);
}