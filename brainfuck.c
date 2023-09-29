#include <stdio.h>
#include <stdlib.h>

#define DATA_SIZE 30000

unsigned char data[DATA_SIZE];

size_t program_size = 0;
char* instruction_ptr = NULL;
char* data_ptr = &data[0];

void interpret();
void load();
void run();

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
	    scanf("%hhu", *data_ptr);
	    break;
	case '[':
	    // TODO: implement using stack
	    if (*data_ptr == 0) {
	    
	    }
	    break;
	case ']':
	    // TODO: implement using stack
	    if (*data_ptr != 0) {
		
	    }
	    break;
    }
}

void load(char file[]) {
    FILE* fp = fopen(file, "r");
    if (fp == NULL) {
	printf("Can't read file!\n");
	exit(EXIT_FAILURE);
    }

    fseek(fp, 0, SEEK_END);
    program_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    instruction_ptr = malloc(program_size);
    fgets(instruction_ptr, program_size, fp);
    fclose(fp);
}

void run() {
    while (*instruction_ptr != '\0') {
	interpret();
	instruction_ptr++;
    }
}

int main(int argc, char *argv[]) {
    load(argv[1]);
    run();
}
