%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include "lex.yy.c"

    void yyerror(const char *s);
    int yylex();
    int yywrap();    
    void util_write(char *);
    void util_writeln(char *);
    char * util_replace_quotes(char *);
    char * util_insert_newline(char *);
%}

%token FREE DISPLAY EQUALS STR ON INLR SEMI_COLON 

%%
program: FREE body endpgm
;

body:
| DISPLAY STR { 
    util_write("printf("); 
    util_write(util_replace_quotes(util_insert_newline(message))); 
    util_writeln(");"); } 
  SEMI_COLON 
;

endpgm: 
| INLR EQUALS ON SEMI_COLON
;

%%

int main() {
    util_writeln("#include <stdio.h>");
    util_writeln("int main (void) {");
    
    yyparse();

    util_writeln("return 0;");
    util_writeln("}");
}

void util_write(char *message) {
    printf("%s", message);
}

void util_writeln(char *message) {
    printf("%s\n", message);
}

char * util_replace_quotes(char *string) {
    int length = strlen(string);
    for (int x = 0; x < length; x++) {
        if (string[x] == '\'') {
            string[x] = '"';
        }
    }

    return string;
}


char * util_insert_newline(char *message) {
  int length = strlen(message);
  char new_str[length+3];
  int x = 0;

  for (x =0; x < length-1; x++) {
    new_str[x] = message[x];
  }
  new_str[x] = '\\';
  new_str[x+1] = 'n';
  new_str[x+2] = '\'';
  new_str[x+3] = '\0';

  return new_str;
}

void yyerror(const char* msg) {
    fprintf(stderr, "Error line number: %d near %s \n", yylineno, yytext);
    fprintf(stderr, "Message: %s\n", msg);
}