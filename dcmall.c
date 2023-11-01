#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 101

typedef struct Person{
    char name [MAX_STR];
    int age;
    char sex;
} person;

person* Ctor(int N){
    person *p = malloc(sizeof(person)*N);
    if(p==NULL) return 0;
    return p;
}

void Dtor(person *p){
    free(p);
}

int main(){
    int N;
    printf("How many people in your list?\n");
    scanf("%i", &N);
    person* p1 = Ctor(N);
    for(int i=0; i<N; i++){
        printf("Write down name of %i. person\n", i+1);
        scanf("%s", p1[i].name);
        printf("Write down age of %i. person\n", i+1);
        scanf("%i", &p1[i].age);
        printf("Write down sex of %i. person\n", i+1);
        scanf(" %c", &p1[i].sex);
        getchar();
    }

    for(int i = 0; i<N; i++){
        printf("Person №%i:\n", i+1);
        printf("Name: %s\nAge: %i\nSex: %c\n", p1[i].name, p1[i].age, p1[i].sex);
    }
    Dtor(p1);
}
