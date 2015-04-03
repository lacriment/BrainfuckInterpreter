#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    if(argc != 2 ){
        printf("Please use like this: ./BrainfuckInterpreter filename\n");
    }
    else{
        FILE *fp;
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            perror("Error while opening the file.\n");
            exit(EXIT_FAILURE);
        }

        char tokens[8];
        tokens[0] = '+';
        tokens[1] = '-';
        tokens[2] = '>';
        tokens[3] = '<';
        tokens[4] = '.';
        tokens[5] = ',';
        tokens[6] = '[';
        tokens[7] = ']';

        unsigned int pointer = 0, step = 0,stepback = 0, i = 0;
        int tape[30000];
        //memset(tape, 0, 20*sizeof(int)); //does not work
        for (i = 0; i < sizeof(tape) / 4; i++) {
            tape[i] = 0;
        }
        char ch, command;
        int boyut = 0;
        while((ch = getc(fp)) != EOF){
            for (i = 0; i < 8; i++) {
                if(tokens[i] == ch){
                    boyut++;
                }
            }
        }
        char commands[boyut];
        //char *commands = malloc(boyut);
        fp = fopen(argv[1], "r");
        int addTo = 0;
        while((ch = getc(fp)) != EOF){
            //printf("%c", ch);
            for (i = 0; i < 8; i++) {
                if(tokens[i] == ch){
                    commands[addTo] = ch;
                    addTo++;
                }
            }
        }
        while(step < sizeof(commands)){
            command = commands[step];
            switch (command) {
            case '<':
                pointer--;
                break;
            case '>':
                pointer++;
                break;
            case '+':
                tape[pointer]++;
                break;
            case '-':
                tape[pointer]--;
                break;
            case ',':
                printf("Input: ");
                scanf("%d", &tape[pointer]);
                break;
            case '.':
                printf("%c", tape[pointer]);
                break;
            case '[':
                stepback = step;
                break;
            case ']':
                if(tape[pointer] > 0)
                    step = stepback - 1;
                break;
            default:
                break;
            }
            step++;
        }
            for (i = 0; i < sizeof(tape) / 4; i++) {
                //printf("[%d]", tape[i]);
            }
        fclose(fp);
    }
    return 0;
}
