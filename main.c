#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX 9
typedef struct candidate{
    int index;
    char* name;
    int votes;
} candidate;


char *read_str_from_console(void);
int ask_num_of_voters(void);
int is_valid_vote(char* , candidate[], int );
int find_the_greatest_vote(candidate[] , int );
void determine_winners(int , candidate[] , int );

int main(void){

    candidate candidates[MAX];
    printf("%s", "The candidates are:");
    char* names_as_one_str = read_str_from_console();

   // 1.0 separate string by space and get the candidate names in the string;
   // 1.1 use the individual candidate name to initialize a candidate and pass it to the array -->
   char *name = strtok(names_as_one_str, " ");
   int counter_candidates = 0;
   while (name != NULL){
       // initialize candidate with variable 'name' and pass it to the
       // candidates array for later use
        candidate c;
        c.name = name;
        c.index = counter_candidates;
        c.votes = 0;
        candidates[counter_candidates] = c;
        // increase the counter_candidates -->
        counter_candidates++;
        // return the next token in the previous string passed to the function -->
        name = strtok(NULL, " ");
    }

    // now that we have increased counter_candidates each time
    // we added a new element to the candidates array
    // the length of the array will be equal to the 'counter_candidates'

   // Voting process -->
   // 2.1.1 Ask the user to enter the number of voters;
   // 2.1.2 Check the user input: Is it less than or equal to MAX? Is it more than or equal to 1?
   // 2.1.3 If all conditions are fulfilled, continue, else ask again!
   int num_of_voters;
   do{
       num_of_voters = ask_num_of_voters();
   } while (num_of_voters == -1);

    // 2.2.1 Ask the user to enter a name for voting
    // 2.2.2 If the name is a valid candidate, change the candidate details in
    // the array (increase votes variable by one) and continue asking as many times as 'num_of_voters'
    // 2.2.3 Is the user input invalid candidate, change nothing (still counts as a vote, but as an invalid
    // one), output an error message to the user -->

    do{
        printf("%s", "Vote:");
        char *candidate_by_voter = read_str_from_console();
        int index = is_valid_vote(candidate_by_voter, candidates, counter_candidates);
        if(index == -1) printf("%s\n", "Invalid vote!");
        else candidates[index].votes++;
        num_of_voters--;
    } while (num_of_voters > 0);

    // Time to find winner(s) -->
    // 2.3.1 Find the greatest vote_count in the candidates array;
    // 2.3.2 Find candidates with the max_vote_count;
    // 2.3.3 Output those candidates(winners) to the user -->
    int max_vote = find_the_greatest_vote(candidates, counter_candidates);
    determine_winners(max_vote, candidates, counter_candidates);
}

char *read_str_from_console(){
    char* user_input = malloc(256 * (sizeof(char)));
    scanf(" %[^\n]", user_input);
    return user_input;
}

int ask_num_of_voters(){
    // prompt the user -->
    printf("%s", "Number of voters:");
    // should the user enter str instead of int, then the function returns -1!
    int voters = -1;
    // read the integer from the console
    scanf("%i", &voters);
    // if user input is a negative number (either because of string input or because of the intentional
    // use of negative number on the console) or 0, or a number greater than MAX, then return -1;
    // else return the user input itself -->
    return ((voters < 1) || (voters > MAX)) ? -1 : voters;
}

// return -1 if no such candidate as in the user input exists; else return the index
// at which this candidate in the candidates array can be found !!!
int is_valid_vote(char* user_input, candidate candidates[], int c_array_length){
    int index = -1;
    for (int i = 0; i < c_array_length; ++i) {
        candidate c = candidates[i];
        // if user input exists in the candidates array
        if(strcmp(user_input, c.name) == 0){
            index = c.index;
            break;
        }
    }
    return index;
}

int find_the_greatest_vote(candidate candidates[], int c_arr_len){
    int max_vote = 0;
    for (int i = 0; i < c_arr_len; ++i) {
        int vote_count = candidates[i].votes;
        if(vote_count > max_vote) max_vote = vote_count;
    }
    return max_vote;
}

void determine_winners(int max_vote_count, candidate candidates[], int c_arr_len){
    for (int i = 0; i < c_arr_len; ++i) {
        candidate c = candidates[i];
        if(c.votes == max_vote_count) printf("%s\n", c.name);
    }
}





