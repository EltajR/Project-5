#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct candidate{
    int votes;
    char* name;
} candidate;

char *read_candidate_names(void);
char **get_names (char *);
void initialize_candidate_list(candidate*);

int main(void){

    char *candidate_names = read_candidate_names();
    char **names_separated = get_names(candidate_names);
    printf("%s\n",names_separated[0]);
    printf("%s\n",names_separated[1]);
    printf("%s\n",names_separated[2]);

}

char *read_candidate_names(){
    char* candidate_names = malloc(256 * (sizeof(char)));
    scanf(" %[^\n]", candidate_names);
    return candidate_names;
}

char **get_names(char *candidate_names){
    int len = strlen(candidate_names);
    char **names = malloc(256 * (sizeof(char)));
    char *name = malloc(25 * (sizeof(char)));
    int name_counter = 0;
    int names_counter = 0;
    for (int i = 0; i < len; ++i) {
        if(candidate_names[i] == ' '){
            printf("%s\n", name);
            *names[names_counter] = *name;
            printf("%ss", names[names_counter]);
            names_counter++;
            name_counter = 0;
            continue;
        }

        name[name_counter] = candidate_names[i];
        name_counter++;
    }
}