#include <stdio.h>
#include <stdlib.h>

#define DATA_SIZE 30000
#define LOOP_COUNT 256

unsigned char data[DATA_SIZE];

size_t program_size = 0;

char* instruction_ptr = NULL;
char* data_ptr = &data[0];

struct bracket_pair {
    char* start;
    char* end;
};
struct bracket_pair pairs[LOOP_COUNT];
int pair_count = 0;


void match_brackets();
void interpret();
void load();
void run();

void match_brackets() {
    // TODO: syntax checking
    char* stack[LOOP_COUNT];
    int stack_idx = 0;
    for (int i = 0; i < program_size; i++) {
	if (instruction_ptr[i] == '[') {
	    // push
	    stack[stack_idx] = &instruction_ptr[i];
	    stack_idx++;
	}
	if (instruction_ptr[i] == ']') {
	    stack_idx--;
	    struct bracket_pair pair = { stack[stack_idx], &instruction_ptr[i] };
	    pairs[pair_count] = pair;
	    pair_count++;
	}
    }	
}

void interpret() {
    switch (*instruction_ptr) {
	case '>':
	    data_ptr++;
	    break;
	case '<':
	    data_ptr--;
	    break;
	case '+':
	    *data_ptr += 1;
	    break;
	case '-':
	    *data_ptr -= 1;
	    break;
	case '.':
	    putchar(*data_ptr);
	    break;
	case ',':
	    *data_ptr = fgetc(stdin);
	    break;
	case '[':
	    if (*data_ptr == 0) {
		for (int i = 0; i < pair_count; i++) {
		    if (pairs[i].start == instruction_ptr) {
			instruction_ptr = pairs[i].end;
			break;
		    }
		}
	    }
	    break;
	case ']':
	    if (*data_ptr != 0) {
		for (int i = 0; i < pair_count; i++) {
		    if (pairs[i].end == instruction_ptr) {
			instruction_ptr = pairs[i].start;
			break;
		    }
		}
	    }
	    break;
	case '\0':
	    exit(0);
	    break;
    }
}

void load(char file[]) {
    FILE* fp = fopen(file, "r");
    if (fp == NULL) {
	printf("Can't read file!\n");
	exit(EXIT_FAILURE);
    }

    
    fseek(fp, 0L, SEEK_END);
    program_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    instruction_ptr = malloc(program_size + sizeof(char));
    fread(instruction_ptr, sizeof(char), program_size, fp);
    fclose(fp);
    instruction_ptr[program_size] = '\0';
}

void run() {
    while (instruction_ptr != NULL) {
	interpret();
	instruction_ptr++;
    }
}

int main(int argc, char *argv[]) {
    load(argv[1]);
    match_brackets();
    run();
}
