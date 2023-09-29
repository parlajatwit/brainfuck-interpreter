#include <stdio.h>

#define DATA_SIZE 30000
unsigned char data[DATA_SIZE];

char instructions[] = "+++++++++++++++++++++++++++++++++++++++++.";
char* instruction_ptr = &instructions[0];
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

void load() {
    // TODO: implement loading from file
}

void run() {
    while (*instruction_ptr != '\0') {
	interpret();
	instruction_ptr++;
    }
}

int main() {
    run();
}
