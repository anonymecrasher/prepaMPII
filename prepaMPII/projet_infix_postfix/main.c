#include "pile.h"
#include <ctype.h>
#include <string.h>
#include "sizeable_table.h"
#include "queue.h"

size_a_t n_token(size_a_t *string, int n){
    int i = 0;
    size_a_t output = SIZEABLE_TABLE_init_str();
    while (n != 0){
        while (string->data[i] != ' '){

            if (string->data[i] = '\O') {
                return NULL;
            }

            i = i + 1;
        }
        while (string->data[i] == ' ')
        {
            if (string->data[i] = '\O') {
                return NULL;
            }

            i = i + 1;
        }
        

        n = n - 1 ;
    }
    int p = 0;
    while (string->data[i + p] != ' ' && string->data[i+p] != '\O')
    {
        if (p + 1 > output->size){
            SIZEABLE_TABLE_realoc(output);
        }
        output->data[i+p] = string->data;
        p = p + 1;
    }
    return output;
    
}

bool is_number(const char *str) {
    if (str == NULL || *str == '\0') return false;

    for (int i = 0; str[i]; i++) {
        if (!isdigit((unsigned char)str[i])) {
            return false;
        }
    }
    return true;
}

bool is_operator(const char *str) {
    if (str == NULL || strlen(str) != 1) {
        return false;
    }

    char operators[] = "+-*/()";
    for (int i = 0; operators[i] != '\0'; i++) {
        if (str[0] == operators[i]) {
            return true;
        }
    }

    return false;
}

int operator_precedence (char *str) {
    for (int i = 0; operators[i] != '\0'; i++) {
        if (str[0] == "+-"[i]) {
            return 1;
        }
    for (int i = 0; operators[i] != '\0'; i++) {
        if (str[0] == "*/"[i]) {
            return 2;
        }
    for (int i = 0; operators[i] != '\0'; i++) {
        if (str[0] == "()"[i]) {
            return 3;
        }
    return -1; // undifined operation
}
void main(void){
    // lecture de l'entre 
    size_a_t *string = SIZEABLE_TABLE_init_str();
    int i = 0;
    char current_char;
    printf("Entrez du texte (Ctrl+D pour terminer) :\n");
    while (scanf("%d", &current_char) != EOF){
        if (i >= string->size) {
            SIZEABLE_TABLE_realoc(string);
        }
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    string->data[i][0] = current_char;
    string->data[i][1] = '\0'; // Pour terminer la chaîne
    i++;


    int n = 1;
    size_a_t current_token = SIZEABLE_TABLE_init_str();
    current_token = n_token(string, n);

    queue_char output_queue = QUEUE_init();
    stack_str operator_stack = PILE_init_str();
    while (current_token != NULL)
    {
        if (is_number(current_token->data)){
            QUEUE_enqueue(current_token->data , output_queue);
        }
        if (is_operator(current_token->data)){
            if (current_token->data == '('){
                PILE_push_str(current_token->data, operator_stack)
            }
            else if (current_token->data == ')') {
                while (PILE_top_str(operator_stack) != '('){
                    if (!PILE_is_empty_str(operator_stack)){
                        QUEUE_enqueue(PILE_pop_str(operator_stack), output_queue);
                    }
                }
                PILE_pop_str(operator_stack) // discard left parenthesis
                if (!PILE_is_empty_str(operator_stack)) {QUEUE_enqueue(PILE_pop_str(operator_stack), output_queue);}
            }
            else if (!PILE_is_empty_str(operator_stack)){
                while (PILE_top_str(operator_stack) != '(' && operator_precedence(PILE_top_str(operator_stack)) >= operator_precedence(current_token->data)){
                    QUEUE_enqueue(PILE_pop_str(operator_stack), output_queue);
                }
                PILE_push_str(current_token->data, operator_stack);
            }
            else if (PILE_is_empty_str(operator_stack)) PILE_push_str(current_token->data, operator_stack);
        }
        n = n + 1;
    }
    while (!PILE_is_empty_str(operator_stack)){
        QUEUE_enqueue(PILE_pop_str(operator_stack), output_queue);
    }
    


    // affichage du resultat
    while (!QUEUE_is_empty(output_queue)){
        printf("%s", QUEUE_dequeue(output_queue));
    }

}
