#include <iostream>
#include <string.h>

using namespace std;

void out(string in) {
    cout<<in.c_str();
}

void divcalc(int num) {
    int card;
    card = 0;

    out("\n  D" + to_string(num) + " = {");

    for(int ctr = 1; ctr <= num; ctr++) {
        if(num % ctr == 0) {
            out(to_string(ctr));
            card++;

            if(ctr != num) {
                out(", ");
            }
        }
    }

    out("} \n\n");
    out("  card D" + to_string(num) + " = " + to_string(card) + "\n");
}

void mulcalc(int num, int max, string denotation) {
    int card, lastvalue;
    card = 0;

    out("\n  " + denotation + " = {");

    for(int ctr = 1; ctr <= max; ctr++) {
        if(ctr * num <= max) {
            out(to_string(ctr * num));
            card++;

            lastvalue = ctr * num;

            if(num * 2 >= max && lastvalue < max) {
                out(", ");
            }else if(lastvalue + num <= max) {
                out(", ");
            }
        }
    }

    out("} \n\n");
    out("  card " + denotation + " = " + to_string(card) + "\n");
}

void between(int min, int max, int div, string denotation) {
    int card, nextvalue;
    card = 0;

    out("\n  " + denotation + " = {");

    for(int ctr = min; ctr <= max; ctr++) {
        if(ctr % div == 0) {
            out(to_string(ctr));
            card++;

            nextvalue = ctr + div;

            if(min + div >= max && nextvalue < max) {
                out(", ");
            }else if(nextvalue <= max) {
                out(", ");
            }
        }
    }
    out("} \n\n");
    out("  card " + denotation + " = " + to_string(card) + "\n");
}
int main()
{
    int param1, param2, param3;
    bool loop = true;

    string cmd, denotation;

    string ver = "ArrayCaramba v0.2 Alpha";

    string inputmkr = " > ";

    //string sparestring = "spare";

    string commands[6] = {"help", "ver", "exit", "div", "mul", "wtn"};

    string altcommands[6] = {"ls", "version", "quit", "divisors", "multiples", "within"};

    string helpdescs[6] = {
        "help - Displays a list of commands.",
        "ver - Displays the version number.",
        "exit - Exits ArrayCaramba.",
        "div (number) - Shows the divisors of a number.",
        "mul (number) (limit) (name) - Creates a set of a provided number's multiples up to a certain limit.",
        "wtn (min) (max) (div. by) (name) - Creates a set of numbers within a range, which are divisible by a given value."
    };

    out("\n " + ver + "\n 2023 wsxdrfvyhn et al.\n\n");
    out(" Type \"help\" for a list of commands.\n\n");

    while(loop == true) {

        out(inputmkr);

        cin>>cmd;

        if(cmd == "test") {

            out("\n  spare test command. don't bother me about it\n\n");

        } else if (cmd == commands[0] || cmd == altcommands[0]) {    // help

            out("\n");

            for(int ctr = 0; ctr <= 5; ctr++) {         // remember to change with number of commands!!!!
                out("  " + helpdescs[ctr] + "\n\n");
            }

        } else if (cmd == commands[1] || cmd == altcommands[1]) {    // ver

            out("\n  " + ver + "\n\n");

        } else if (cmd == commands[2] || cmd == altcommands[2]) {    // exit

            loop = false;

        } else if (cmd == commands[3] || cmd == altcommands[3]) {    // div

            cin>>param1;

            out("  _________________________________\n");

            divcalc(param1);

            out("\n\n");

        } else if (cmd == commands[4] || cmd == altcommands[4]) {    // mul

            cin>>param1;
            cin>>param2;
            cin>>denotation;

            out("  _________________________________\n");

            mulcalc(param1, param2, denotation);

            out("\n\n");

        } else if (cmd == commands[5] || cmd == altcommands[5]) {    // wtn

            cin>>param1;
            cin>>param2;
            cin>>param3;
            cin>>denotation;

            out("  _________________________________\n");

            between(param1, param2, param3, denotation);

            out("\n\n");

        } else {                            // unrec

            out("\n  Unrecognized command!\n\n");

        }
    }
    return 0;
}
