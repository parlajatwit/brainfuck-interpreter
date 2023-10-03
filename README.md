# brainfuck interpreter
[brainfuck](https://en.wikipedia.org/wiki/Brainfuck) is an esoteric programming language with 8 instructions.   
\> - increment the data pointer   
< - decrement the data pointer   
\+ - increment the byte at the data pointer   
\- - decrement the byte at the data pointer   
. - output the byte at the data pointer   
, - store an inputed char in the data pointer   
\[ - if the byte under the data pointer is 0, jump to the instruction after the matching \]   
\] - if the byte under the data pointer is not 0, jump to the instruction after the matching \[   
programs end at eof.  

## why?
i wrote this interpreter for practice in c and for fun.   
special thanks to ben for telling me to do this every week for 2 years straight.
