//1
#include<stdio.h>
#include<ctype.h>
void main()
{
    char ch,arioperators[]="+-*/%=",logoperators[]="&|!",lexmes[]="=,>,<",special[]="{}";
    FILE *fp;
    int i,j,flag=0;
    fp = fopen("a.txt","r");
    if(fp==NULL)
    {
        printf("File not found");
        exit(0);
    }
    else if(fp!=NULL)
    {
        while((ch = fgetc(fp)) != EOF)
        {
            if(ch =='\n')
            {
                printf("\n");
            }
             if(isspace(ch))
            {
                printf(" ");
            }
             if(ch =='\t')
            {
                printf("\t");
            }

                //ARITHMETIC OPERATORS
            for(i=0;i<=5;i++)
            {
                if(ch ==arioperators[i])
                {
                    switch(ch)
                    {
                        case '+':printf("PLUS");
                                 printf(" ");
                                break;
                        case '-':printf("MINUS");
                                printf(" ");
                                 break;
                        case '*':printf("STAR");
                                printf(" ");
                                 break;
                        case '%':printf("MODULO");
                                printf(" ");
                                 break;

                    }
                }
            }

            //LOGICAL OPERATORS
            for(i=0;i<=3;i++)
            {
                if(ch == logoperators[i])
                {
                    switch(ch)\
                    {
                        case '&':ch = fgetc(fp);
                                 if(ch =='&')
                                 {
                                     printf("AND");
                                     printf(" ");
                                 }
                                 break;
                        case '|':ch = fgetc(fp);
                                 if(ch == '|')
                                 {
                                     printf("OR");
                                     printf(" ");
                                 }
                                 break;
                        case '!':printf("NOT");
                                printf(" ");
                                 break;
                    }
                }
            }



             if(isalpha(ch))
            {
            switch(ch)
            {
              case 'f':ch = fgetc(fp);
                        if(ch=='l')
                        {
                            ch = fgetc(fp);
                            if(ch=='o')
                            {
                                ch = fgetc(fp);
                                if(ch=='a')
                                {
                                    ch = fgetc(fp);
                                    {
                                        if(ch=='t')
                                        {
                                            printf("KW");
                                            printf(" ");
                                            ch = fgetc(fp);
                                            if(isspace(ch))
                                            {
                                                printf(" ");
                                            }
                                            ch = fgetc(fp);
                                            if(isalpha(ch))
                                            {
                                                printf("ID");
                                                printf(" ");
                                                while(ch !='=')
                                                {
                                                    ch = fgetc(fp);
                                                    if(ch==';')
                                                    {
                                                        printf("SP");
                                                        break;
                                                    }

                                                }

                                            }
                                            
                                            if(ch=='=')
                                            {
                                                printf("ASSIGN");
                                                printf(" ");
                                            }
                                            ch = fgetc(fp);
                                            if(isdigit(ch))
                                            {
                                                printf("FLOATCONST");
                                                printf(" ");
                                                while(ch !=';')
                                                {
                                                    ch = fgetc(fp);
                                                    if(ch==';')
                                                    {
                                                        printf("SP");
                                                    }
                                                }

                                            }
                                else if(isalpha(ch))
                                    {
                                     printf("ID");
                                     printf(" ");
                                     while(isalpha(ch))
                                     {
                                         ch = fgetc(fp);
                                     }
                            for(i=0;i<=5;i++)
                            {
                            if(ch ==arioperators[i])
                            {
                            switch(ch)
                            {
                                case '+':printf("PLUS");
                                        printf(" ");
                                        break;
                                case '-':printf("MINUS");
                                        printf(" ");
                                        break;
                                case '*':printf("STAR");
                                        printf(" ");
                                        break;
                                case '%':printf("MODULO");
                                        printf(" ");
                                        break;

                        }
                        }
                        }
                                ch = fgetc(fp);
                                if(isalpha(ch))
                                {
                                    printf("ID");
                                    printf(" ");
                                    while(ch!=';')
                                    {
                                        ch = fgetc(fp);
                                        if(ch==';')
                                        {
                                            printf("SP");
                                            break;
                                        }
                                    }
                                }

                                 }
                                        }
                                    }
                                }
                            }
                        }
                        else if(ch=='o')
                        {
                            ch = fgetc(fp);
                            if(ch=='r')
                            {
                                printf("FN");
                                while(ch !='\n')
                                {
                                    ch = fgetc(fp);
                                }
                            }
                        }
                        break;

            case 'w':ch = fgetc(fp);
                    if(ch=='h')
                    {
                        ch = fgetc(fp);
                        if(ch=='i')
                        {
                            ch = fgetc(fp);
                            if(ch=='l')
                            {
                                ch = fgetc(fp);
                                if(ch=='e')
                                {
                                    printf("FN");
                                    printf(" ");
                                    while(ch !='\n')
                                    {
                                        ch = fgetc(fp);

                                    }
                                }
                            }
                        }
                    }

            case 'i':ch = fgetc(fp);
                     if(ch=='n')
                     {
                         ch = fgetc(fp);
                         if(ch=='t')
                         {
                             printf("KW");
                             printf(" ");
                             ch = fgetc(fp);
                             if(isspace(ch))
                             {
                                 printf(" ");
                             }
                             ch = fgetc(fp);
                             if(isalpha(ch))
                             {
                                 printf("ID");
                                 printf(" ");
                                 while(ch!='=')
                                 {
                                     ch = fgetc(fp);
                                      if(ch==';')
                                    {
                                     printf("SP");
                                     break;
                                    }
                                 }
                                 if(ch=='=')
                                 {
                                     printf("ASSIGN");
                                     printf(" ");
                                 }

                                 ch = fgetc(fp);
                                 if(isdigit(ch))
                                 {
                                     printf("NUMCONST");
                                     printf(" ");
                                     while(ch !=';')
                                     {
                                         ch =fgetc(fp);
                                         if(ch==';')
                                         {
                                             printf("SP");
                                             break;
                                         }
                                     }

                                 }
                                 else if(isalpha(ch))
                                 {
                                     printf("ID");
                                     printf(" ");
                                     while(isalpha(ch))
                                     {
                                         ch = fgetc(fp);
                                     }
                            for(i=0;i<=5;i++)
                            {
                            if(ch ==arioperators[i])
                            {
                            switch(ch)
                            {
                                case '+':printf("PLUS");
                                        printf(" ");
                                        break;
                                case '-':printf("MINUS");
                                        printf(" ");
                                        break;
                                case '*':printf("STAR");
                                        printf(" ");
                                        break;
                                case '%':printf("MODULO");
                                        printf(" ");
                                        break;

                        }
                        }
                        }
                                ch = fgetc(fp);
                                if(isalpha(ch))
                                {
                                    printf("ID");
                                    printf(" ");
                                    while(ch!=';')
                                    {
                                        ch = fgetc(fp);
                                        if(ch==';')
                                        {
                                            printf("SP");
                                            break;
                                        }
                                    }
                                }

                                 }
                             }
                         }

                     }
                     else if(ch =='f')
                          {
                              printf("KW");
                              printf(" ");
                              ch = fgetc(fp);
                              if(ch =='(')
                              {
                                  printf("SP");
                                  printf(" ");
                                  while(ch !=')')
                                  {
                                      ch = fgetc(fp);
                                      if(isalpha(ch))
                                      {

                                          while(isalpha(ch))
                                          {
                                              ch = fgetc(fp);
                                          }
                                      }
                                      printf("ID");
                                      printf(" ");
                                      for(i=0;i<=6;i++)
                                      {
                                         if(ch==lexmes[i])
                                        {
                                          printf("RELOP");
                                          printf(" ");
                                        }
                                      }

                                      if(isspace(ch))
                                      {
                                          printf(" ");
                                      }
                                  }
                                  printf("SP");
                                  printf(" ");
                              }

                          }
                     break;

            case 'e':ch = fgetc(fp);
                         if(ch=='l')
                         {
                             ch = fgetc(fp);
                             if(ch=='s')
                             {
                                 ch = fgetc(fp);
                                 if(ch=='e')
                                 {
                                     ch = fgetc(fp);
                                     if(isspace(ch))
                                     {
                                         ch = fgetc(fp);
                                         if(ch=='i')
                                         {
                                             ch = fgetc(fp);
                                             if(ch=='f')
                                             {
                                                 printf("KW");
                                                 printf(" ");
                                                 ch =fgetc(fp);
                                                 if(ch=='(')
                                                 {
                                                     printf("SP");
                                                     printf(" ");
                                                     while(ch!=')')
                                                     {
                                                         ch = fgetc(fp);
                                                         if(isalpha(ch))
                                                         {
                                                             while(isalnum(ch))
                                                             {
                                                                 ch = fgetc(fp);
                                                             }
                                                         }
                                                         printf("ID");
                                                         printf(" ");
                                                          if(isspace(ch))
                                                         {
                                                             printf(" ");
                                                         }
                                                         for(i=0;i<=6;i++)
                                                         {
                                                             if(ch==lexmes[i])
                                                             {
                                                                 printf("RELOP");
                                                                 printf(" ");
                                                             }
                                                         }
                                                     }
                                                     printf("SP");
                                                     printf(" ");
                                                 }
                                             }
                                         }
                                         else
                                         {
                                             printf("KW");
                                             printf(" ");
                                             printf("\n");
                                         }
                                     }
                                 }

                             }
                         }
                            break;
            case 'r':ch = fgetc(fp);
                        if(ch=='e')
                        {
                            ch = fgetc(fp);
                            if(ch=='a')
                            {
                                ch = fgetc(fp);
                                if(ch=='l')
                                {
                                    printf("KW");
                                    printf(" ");
                                    ch = fgetc(fp);
                                    if(isspace(ch))
                                    {
                                        printf(" ");
                                    }
                                    ch = fgetc(fp);
                                    if(isalpha(ch))
                                    {
                                        printf("ID");
                                        printf(" ");
                                while(ch!='=')
                                 {
                                     ch = fgetc(fp);
                                      if(ch==';')
                                    {
                                     printf("SP");
                                     break;
                                    }
                                 }
                                 if(ch=='=')
                                 {
                                     printf("ASSIGN");
                                     printf(" ");
                                 }
                                 ch = fgetc(fp);
                                 if(isdigit(ch))
                                 {
                                     printf("EXPCONST");
                                     printf(" ");
                                     while(ch !=';')
                                     {
                                         ch = fgetc(fp);
                                         if(ch==';')
                                         {
                                             printf("SP");
                                             break;
                                         }
                                     }
                                 }
                                 else if(isalpha(ch))
                                 {
                                     printf("ID");
                                     printf(" ");
                                     while(isalpha(ch))
                                     {
                                         ch = fgetc(fp);
                                     }
                            for(i=0;i<=5;i++)
                            {
                            if(ch ==arioperators[i])
                            {
                            switch(ch)
                            {
                                case '+':printf("PLUS");
                                        printf(" ");
                                        break;
                                case '-':printf("MINUS");
                                        printf(" ");
                                        break;
                                case '*':printf("STAR");
                                        printf(" ");
                                        break;
                                case '%':printf("MODULO");
                                        printf(" ");
                                        break;

                        }
                        }
                        }
                                ch = fgetc(fp);
                                if(isalpha(ch))
                                {
                                    printf("ID");
                                    printf(" ");
                                    while(ch!=';')
                                    {
                                        ch = fgetc(fp);
                                        if(ch==';')
                                        {
                                            printf("SP");
                                            break;
                                        }
                                    }
                                }

                                 }



                                    }
                                }
                            }
                        }
                        break;
            case 'p':ch = fgetc(fp);
                          if(ch=='r')
                          {
                              ch = fgetc(fp);
                              if(ch=='i')
                              {
                                  ch = fgetc(fp);
                                  if(ch=='n')
                                  {
                                      ch = fgetc(fp);
                                      if(ch=='t')
                                      {
                                          ch = fgetc(fp);
                                          if(ch=='f')
                                          {
                                              printf("FN");
                                              printf(" ");
                                          }
                                      }
                                  }
                              }
                          }
                          while(ch !='\n')
                          {
                              ch = fgetc(fp);
                          }
                          printf("\n");
                          break;
            case 's':ch = fgetc(fp);
                          if(ch=='c')
                          {
                              ch = fgetc(fp);
                              if(ch=='a')
                              {
                                  ch = fgetc(fp);
                                  if(ch=='n')
                                  {
                                      ch = fgetc(fp);
                                      if(ch=='f')
                                      {
                                          printf("FN");
                                          printf(" ");
                                      }
                                  }
                              }
                          }
                          while(ch !='\n')
                          {
                              ch = fgetc(fp);
                          }
                          printf("\n");
                          break;

                case 'm':ch=fgetc(fp);
                         if(ch=='a')
                         {
                             ch = fgetc(fp);
                             if(ch=='i')
                             {
                                 ch = fgetc(fp);
                                 if(ch=='n');
                                 {
                                     ch = fgetc(fp);
                                     if(ch=='(')
                                     {
                                         ch = fgetc(fp);
                                         if(ch ==')')
                                         {
                                             printf("FN");
                                             printf(" ");
                                         }
                                     }
                                     else
                                     {
                                         printf("KW");
                                         printf(" ");
                                     }

                                 }
                             }
                         }
                         while(ch!='\n')
                         {
                             ch = fgetc(fp);
                         }
                         printf("\n");
                         break;



            default:printf("ID");
                    printf(" ");
                    while(ch !='=')
                    {
                        ch = fgetc(fp);
                    }
                    if(ch=='=')
                    {
                        printf("ASSIGN");
                        printf(" ");
                    }
                    ch = fgetc(fp);
                    if(isalpha(ch))
                    {
                        printf("ID");
                        printf(" ");
                        while(isalpha(ch))
                        {
                            ch = fgetc(fp);
                        }
                        for(i=0;i<=5;i++)
                            {
                            if(ch ==arioperators[i])
                            {
                            switch(ch)
                            {
                                case '+':printf("PLUS");
                                        printf(" ");
                                        break;
                                case '-':printf("MINUS");
                                        printf(" ");
                                        break;
                                case '*':printf("STAR");
                                        printf(" ");
                                        break;
                                case '%':printf("MODULO");
                                        printf(" ");
                                        break;

                        }
                        }
                        }
                        ch = fgetc(fp);
                                if(isalpha(ch))
                                {
                                    printf("ID");
                                    printf(" ");
                                    while(ch!=';')
                                    {
                                        ch = fgetc(fp);
                                        if(ch==';')
                                        {
                                            printf("SP");
                                            break;
                                        }
                                    }
                                }

                    }
            }//end of switch
        }
        if(ch == '/')//for comments
            {

                ch = fgetc(fp);
                if(ch == '/')
                {
                    printf("SLC");
                    printf(" ");
		    printf("\n");
                    while(ch !='\n')
                        {
                            ch = fgetc(fp);
                        }
                }
                else if(ch == '*')
                {
                    printf("Start of MLC");
                    printf(" ");
                    while(ch !='*')
                    {
                        ch = fgetc(fp);
                        printf(" ");
			if(ch == '\n')
			{
			 printf("\n");
			}
                    }
                   while(ch !='/')
                   {
                       ch = fgetc(fp);
                       printf(" ");
                   }
                   printf("END OF MLC");
                   printf(" ");

                }
                else
                {
                    printf("DIVIDE");
                    printf(" ");
                }
            }
            for(i=0;i<=2;i++)
            {
                if(ch==special[i])
                {
                    printf("SP");
                    printf(" ");
                }
            }

        }//main while loop

    }
    fclose(fp);
    return 0;
}













//lex.l

%{
	#include<stdio.h>
%}
FN printf\(\"({letter}|{digit}|{SP}|\s)*\"\)\;|scanf\(\"\%({letter}|{digit}|{SP})*\"({letter}|{digit}|{SP})*\)\;|main\(\)

letter [a-zA-Z]
digit [0-9]
identifier {letter}({letter}|{digit})*

INTCONST {digit}+
FRACTCONST {digit}*\.{digit}+
EXPCONST {digit}*E(\+|-){digit}+
CCONST \'{letter}*\'
SCONST \"{letter}*\"

AOPE \+|\-|\*|\/|% 
LOPE &&|\|\||!
ROPE <|<=|==|!=|>|>=

ASI =
SP \,|\;|\{|\}|\(|\)|\[|\]

SLC \/\/({letter}|{digit})*
MLC \/\*({letter}|{digit})*\n({letter}|{digit})*\*\/
%%

{FN} {	printf("FN ");
		yytext="\n";}
int|float|char|for|while|if|else {printf("KW ");}

{identifier} {printf("ID ");}

{INTCONST} {printf("INTCONST ");}
{FRACTCONST} {printf("FRACTCONST ");}
{EXPCONST} {printf("EXPCONST ");}

{AOPE} {printf("AOPE ");}
{LOPE} {printf("LOPE ");}
{ROPE} {printf("ROPE ");}

{CCONST} {printf("CHARCONST ");}
{SCONST} {printf("STRCONST ");}
{ASI} {printf("ASSIGN ");}

{SP} {printf("SP ");}

{SLC} {printf("SLC");}
{MLC} {printf("MLC");}

%%

int main(int argc, char **argv)
{
yylex();
return 0;
}
int yywrap()
{
return 1;
}








//symboltable.l
%{
#include<stdio.h>
#include<string.h>

char tempk[10];
int i=0,j;

struct table
{
char type[10];
char name[10];
char value[10];
}T[30];
%}


id {letter}({letter}|{digit})*

INTCONST {digit}+
FLOATCONST {digit}*\.{digit}+
EXPCONST {digit}*E(\+|-){digit}+

KW int|float|char|real
end [;]
SP \{|\}|\(|\)|\[|\|,]

FN printf\(\"({letter}|{digit}|{SP}|\s)*\"\)\;|scanf\(\"\%({letter}|{digit}|{SP})*\"({letter}|{digit}|{SP})*\)\;|main\(\)

letter [a-zA-Z]
digit [0-9]

AOPE \+|\-|\*|\/|% 
LOPE &&|\|\||!
ROPE <|<=|==|!=|>|>=

CCONST \'{letter}*\'
SCONST \"{letter}*\"
ASSIGN =

SLC \/\/({letter}|{digit})*
MLC \/\*({letter}|{digit})*\n({letter}|{digit})*\*\/

%%

{FN} {	printf("FN ");
		yytext="\n";}
{INTCONST} {
	strcpy(T[i-1].value,yytext);	
	printf("%s INTCONST ",yytext);
}
{FLOATCONST} {
	strcpy(T[i-1].value,yytext);	
	printf("%s FLOATCONST ",yytext);
	}

{EXPCONST} {
	strcpy(T[i-1].value,yytext);
	printf("%s EXPCONST",yytext);
}

{CCONST} {
	strcpy(T[i-1].value,yytext);
	printf("%s CHARCONST ",yytext);
}
{SCONST} {
	strcpy(T[i-1].value,yytext);
	printf("%s STRCONST ",yytext);
		}
{KW}  {
	strcpy(tempk,yytext);
	//strcpy(T[i].type,yytext);
	printf("%s KW ",yytext);
	
	}

{id} {  printf("%s ID",yytext);
	strcpy(T[i].type,tempk);
	strcpy(T[i].name,yytext);
	strcpy(T[i].value,"0");
	i++;
	}

{ASSIGN} { printf("%s ASSIGN ",yytext); }
{AOPE} {  printf("%s AOPE ",yytext);}
{ROPE} {  printf("%s ROPE ",yytext);}
{LOPE} {  printf("%s LOPE ",yytext);}

{SP}   {  printf("%s SP ",yytext);}

{end} {

        printf("\nType\tName\tValue\n");
 	for(j=0;j<=i;j++)
	 {
 	printf("\n %s\t%s\t%s",T[j].type,T[j].name,T[j].value);

	   }
	
	}

%%


int main()
{
yylex();
return 0;
}

int yywrap()
{
return 1;
}










//calc.l
%{
#include"y.tab.h"
int yyerror(char *);
#include<stdio.h>
#include<stdlib.h>	
extern int yylval;
%}
const [0-9]+
%%

{const} {yylval=atoi(yytext);
         return NUM;     }

[\n] {return *yytext;}

[(] {return *yytext;}
[)] {return *yytext;}
[*] {return *yytext;}
[/] {return *yytext;}
[-] {return *yytext;}
[+] {return *yytext;}
[/^] {return *yytext;}

. {char msg[200];
   sprintf(msg,"%s",yytext);
   yyerror(msg);}

%%





//calc.y
%{
#include"y.tab.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int yylex(void);
%}

%token NUM

%%
S:E '\n'{printf("%d",$$);}
 ;
E:E '+' T{ $$ = $1+$3;}
 |E '-' T{ $$ = $1-$3;}
 |T {$$=$1;}
 ;

T:T '*' M{ $$ = $1*$3;}
 |T '/' M{ $$ = $1/$3;}
 |M {$$=$1;}
 ;

M:N '^' M{ $$ =pow($1,$3);}
 |N { $$=$1;}
 ;

N:'(' E ')' { $$ = $2;}
 |NUM{$$=$1;}
 ;

%%
int main()
{
  yyparse();
}
int yywrap()
{
  return 1;
}
int yyerror(char *s)
{
  fprintf(stderr,"%s",s);
}













//synchk.l
%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "y.tab.h"
  int c;
  extern int yylval;
%}

letter [a-zA-Z]
digit [0-9]
digits {digit}({digit})*
identifier {letter}({letter}|{digit})*
intConst ({digit})+
fracConst ({digit})*\.{intConst}
expConst {digits}E([\+|\-|])?{digits}
charConst '{letter}'
const {intConst}|{expConst}|{fracConst}|{charConst}
KW int|char|float

%%

" "       ;

if|else|for {return *yytext;}

{KW}	{
	        yylval = atoi(yytext);
	        return(KEYWORD);
      	}

{identifier} {
				        yylval = atoi(yytext);
		            return(IDENTIFIER);
			       }

{const}   {
            yylval = atoi(yytext);
            return(CONSTANT);
          }

\=\=|\>\=|\<\=|\!\=|\>|\< {
                            yylval = atoi(yytext);
                            return(RELOP);
                          }

\+|\-|\\|\* {
              yylval = atoi(yytext);
              return(OP);
            }

=|\,|\;|\(|\) {return *yytext;}

\n {return *yytext;}

%%




//synchk.y
%{
#include<stdio.h>
#include "y.tab.h"
#include<math.h>
%}
%token KEYWORD
%token CONSTANT
%token IDENTIFIER
%token RELOP
%token OP
%%

//Declaration and assignment
START: S {printf("Correct syntax");}
      ;



S: KEYWORD E '\n' S
  | A '\n' S
  | C '\n' S
  | LOOP '\n' S
  | 
  ;

E: A
  | D
  |
  ;

//Assignment
A: E IDENTIFIER '=' CONSTANT
  | E IDENTIFIER '=' CONSTANT ','
  ;

//Declaration
D: E IDENTIFIER
  | E IDENTIFIER ','
  ;

//Conditional Statement
C: 'if' '(' EXPR ')' '\n' STATEMENT '\n' 'else' '\n' STATEMENT
    ;

STATEMENT: IDENTIFIER '=' CONSTANT
          | IDENTIFIER '=' IDENTIFIER OP CONSTANT
          | IDENTIFIER '=' IDENTIFIER
          ;

EXPR: IDENTIFIER RELOP IDENTIFIER 
      | IDENTIFIER RELOP CONSTANT
      ;

//Looping Statement
LOOP: 'for' '(' STATEMENT ';' LOOPTWO ';' STATEMENT ')' '\n' STATEMENT
      ;

LOOPTWO: IDENTIFIER RELOP CONSTANT
        ;



%%
int main()
{
    yyparse();
    //return 0;
}
int yyerror(char *s)
{
    //printf("error:%s",s);
}
int yywrap()
{
  return(1);
}












//ast.l
%{
#include"y.tab.h"
int yyerror(char *);
#include<stdio.h>
#include<stdlib.h>	
extern int yylval;
%}
const [0-9]+
%%
{const} {yylval=atoi(yytext);
         return ID;     }
[\n] {return *yytext;}
[(] {return *yytext;}
[)] {return *yytext;}
[*] {return *yytext;}
[/] {return *yytext;}
[-] {return *yytext;}
[+] {return *yytext;}
[%] {return *yytext;}
[/^] {return *yytext;}
. {char msg[200];
   sprintf(msg,"%s",yytext);
   yyerror(msg);}
%%




//ast.y
%{
#include"y.tab.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int yylex(void);
struct node
{
 int val;
 struct node *left,*right;
}n;
%}
%token ID
%%
S:E '\n'{}
 ;
E:E '+' T{ struct node* start;
     start=malloc(sizeof(struct node));
     start->val='+';
     start->left=$1;
     start->right=$3;
     printf("\nNode + has been created with %ld as left and %ld as right at address %ld",start->left,start->right,start);$$=start; }
 |T {$$=$1;}
 ;
T:T '*' F{struct node* start;
     start=malloc(sizeof(struct node));
     start->val='*';
     start->left=$1;
     start->right=$3;
     printf("\nNode * has been created with %ld as left and %ld as right at address %ld",start->left,start->right,start);$$=start; }
 |F {$$=$1;}
 ;
F:ID{struct node* start;
     start=malloc(sizeof(struct node));
     start->val=$1;
     start->left=start->right=NULL;
     printf("[%ld <-%d-> %ld] :%ld\n",start->left,start->val,start->right,start);
     //printf("\nNode %d has been created with %ld as left and %ld as right at address %ld",start->val,start->left,start->right,start);
     $$=start;/*printf("value of $$ %ld\n",$$);*/}
 ;
%%
int main()
{
  yyparse();
}
int yywrap()
{
  return 1;
}
int yyerror(char *s)
{
  fprintf(stderr,"%s",s);
}











//typechk.l
%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "y.tab.h"
  int c;
  extern int yylval;
%}

digit [0-9]
letter [a-zA-Z]
intConst [0-9]+
fracConst ({digit})*\.{intConst}
charConst '{letter}'

%%

" "       ;

{charConst}   {
                yylval = 1;
                return(CHARCONST);
              }

{intConst}	{
    	        yylval = 2;
    	        return(INTCONST);
      	     }

{fracConst} {
  			        yylval = 3;
  	            return(FRACCONST);
  		       }

\+|\-|\/|\*|\=\=|\(|\) {return *yytext;}

\n {return *yytext;}

. {
    yylval = 4;
    return(OTHER);
  }

%%






//typechk.y
%{
#include<stdio.h>
#include "y.tab.h"
#include<math.h>
%}
%token INTCONST
%token FRACCONST
%token CHARCONST
%token OTHER
%%

START: S {
                if($$ == 4)
                  printf("INVALID\n");
                else if($$ == 3)
                  printf("VALID, TYPE IS FLOAT\n");
                else if($$ == 2)
                  printf("VALID, TYPE IS INT\n");
                else if($$ == 1)
                  printf("VALID, TYPE IS CHAR\n");
              }
      ;

S:  E '=' E  {
                if($1==4 || $3==4)
                  $$=4;
                else if($1==3 || $3==3)
                  $$=3;
                else if($1==2 || $3==2)
                  $$=2;
                else if($1==1 || $3==1)
                  $$=1;
              }
  | E         {$$=$1;}
;

E: E '+' T  {
              if($1==4 || $3==4)
                $$=4;
              else if($1==3 || $3==3)
                $$=3;
              else if($1==2 || $3==2)
                $$=2;
              else if($1==1 || $3==1)
                $$=1;
            }
  |E '-' T  {
              if($1==4 || $3==4)
                $$=4;
              else if($1==3 || $3==3)
                $$=3;
              else if($1==2 || $3==2)
                $$=2;
              else if($1==1 || $3==1)
                $$=1;
            }
  |T        {$$=$1;}
  ;

T: T '*' F  {
              if($1==4 || $3==4)
                $$=4;
              else if($1==3 || $3==3)
                $$=3;
              else if($1==2 || $3==2)
                $$=2;
              else if($1==1 || $3==1)
                $$=1;
            }
  |T '/' F  {
              if($1==4 || $3==4)
                $$=4;
              else if($1==3 || $3==3)
                $$=3;
              else if($1==2 || $3==2)
                $$=2;
              else if($1==1 || $3==1)
                $$=1;
            }
  |F        {$$=$1;}
  ;

F:  '(' E ')'   {$$=$2;}
   |INTCONST    {$$=$1;}
   |FRACCONST   {$$=$1;}
   |CHARCONST   {$$=$1;}
   |OTHER       {$$=$1;}
   ;

%%
int main()
{
    yyparse();
    //return 0;
}
int yyerror(char *s)
{
    //printf("error:%s",s);
}
int yywrap()
{
  return(1);
}
















//stack
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct active
{
  int ret,no;
  char pt[50];
};

struct active st[100];
int top=0,flag=0,sp=2000;
char fname[100];
void push(struct active tmp)
{
	int i=0;
	st[top]=tmp;
	printf("\nENTRY %s function\nreturn address:%d\nno of parameters:%d\n",fname,st[top].ret,st[top].no);
	printf("Type Of Parameters-");
	printf("%s ",st[top].pt);
	top++;
	sp+=(sizeof(tmp));
	printf("\nStack pointer address: %d\n",sp);
}

void pop()
{
	top--;
	sp-=(sizeof(st[top]));
}

void disp()
{
	printf("\nEXIT %s function\nreturn address:%d\nno of parameters:%d\n",fname,st[top].ret,st[top].no);
	printf("Type Of Parameters-");
		printf("%s ",st[top].pt);
	printf("\nStack pointer address: %d\n",sp);
}
void main()
{
	int i=0,j,n,lineno=100,k;
	char s[1024][1024];
	printf("Enter number of lines in the program: ");
	scanf("%d",&n);
	while(i<=n)
	{
	  gets(s[i++]);
	}
	printf("\nInitial stack pointer address: %d\n",sp);
	for(j=1;j<=n;++j,lineno+=20)
	{
	  while(flag>0)
	  {
		pop();
 		disp();
		flag--;
	  }
	  if(strstr(s[j],"(") && strstr(s[j],"="))
      {
		struct active tmp;
		tmp.ret=lineno+20;
		tmp.no=0;
		int pos=0;
		int f=0;
		for(k=0;k<strlen(s[j]);++k)
		{
		  if(s[j][k]==',')
		  tmp.no++;
		  if(s[j][k]=='=')
 		  {
			while(f==0)
			{
				k++;
				if(s[j][k]=='(')
				{
					f=1;
					break;
				}
				fname[pos++]=s[j][k];
			}
		  }
        }
		fname[pos]='\0';
		char params[30];
		int j1,jj,pa;
		for(j1=0;j1<n;++j1)
		{
			if(strstr(s[j1],fname)&&j1!=j)
			{
				for(jj=0;jj<strlen(s[j1]);jj++)
				{
					
					if(s[j1][jj]=='(')
					{
						pa=0;
						jj++;
						while(s[j1][jj]!=')')
							params[pa++]=s[j1][jj++];
						params[pa]='\0';
						strcpy(tmp.pt,params);
						
					}
						
				}	
			}
		}
		  if(tmp.no!=0)
			tmp.no++;
		  push(tmp);
		  flag++;
	  }
	  
	}
}













//codeopt1
#include<stdio.h>
#include<stdlib.h>
int main()
{
  int i,s;
  char c;
  char TAC[10][10];
  printf("Input  :");
  for(i=0;i<2;i++)
    scanf("%s",TAC[i]);
  printf("\nGiven Sequence :");
  for(i=0;i<2;i++)
    printf("\n%s",TAC[i]);

  for(i=0;i<2;i++)
  {
  s=TAC[i][2]-48+TAC[i][4]-48;
  c=s+48;
  TAC[i][2]=c;
  TAC[i][3]='\0';
  }
  printf("\nOptimized Sequence :");
  for(i=0;i<2;i++)
    printf("\n%s",TAC[i]);

}



//codeopt2
#include<stdio.h>
#include<stdlib.h>
int main()
{
  int i,s;
  char c;
  char Seq[10][10];
  printf("Input :");
  for(i=0;i<2;i++)
    scanf("%s",Seq[i]);
  printf("\nGiven Sequences :");
  for(i=0;i<2;i++)
    printf("\n%s",Seq[i]);

    for(i=0;i<2;i++)
    {
       if((Seq[i][3]=='+') && (Seq[i][2]=='0'|| Seq[i][4]=='0'))
      {     
    if(Seq[i][2]=='0')
      {     
     Seq[i][2]=Seq[i][4];
       Seq[i][3]='\0';
      }
    if(Seq[i][4]=='0')
      {     
     
       Seq[i][3]='\0';
    }
   }   

   if((Seq[i][3]=='-') && (Seq[i][2]=='0'|| Seq[i][4]=='0'))
      {     
    if(Seq[i][2]=='0')
      {     
     Seq[i][2]=Seq[i][4];
       Seq[i][3]='\0';
      }
    if(Seq[i][4]=='0')
      {     
     
       Seq[i][3]='\0';
    }
   }   
}
   printf("\nOptimized Sequences :");
   for(i=0;i<2;i++)
    printf("\n%s",Seq[i]);

}












//DAG.c
#include<stdio.h>
struct node{
char val,label[10];
int count;
struct node *l,*r;
};
int main()
{
	char a[30][30];
	int n;
	struct node *l[30];
	int i,j,c=0;	
	printf("Enter number of statements:");
	scanf("%d",&n);
	printf("Enter the TAC statements:");
	for(i=0;i<n;i++)
		scanf("%s",a[i]);
	struct node *o1=malloc(sizeof(struct node));
	o1->val=a[0][2];
	o1->l=o1->r=NULL;
	o1->count=0;
	o1->label[o1->count++]=a[0][2];
	l[c++]=o1;

	struct node *o2=malloc(sizeof(struct node));
	o1->val=a[0][4];
	o2->l=o2->r=NULL;
	l[c++]=o2;
	o2->count=0;
	o2->label[o2->count++]=a[0][4];
	
	struct node *o3=malloc(sizeof(struct node));
	o3->val=a[0][3];
	o3->l=o1;
	o3->r=o2;
	o3->count=0;
	o3->label[o3->count++]=a[0][0];
	l[c++]=o3;
	
	printf("Node %c Created At %ld With Left Child %c with Address:%ld and Right Child %c with Address:%ld\n",o3->val,o3,o3->l->label[0],o3->l,o3->r->label[0],o3->r);		
//	printf("l[0]->label[0]:%c",l[0]->label[0]);
	for(i=1;i<n;i++)
	{
		struct node *o=malloc(sizeof(struct node));
		o->val=a[i][3];
		o->l=o->r=NULL;
		o->count=0;
		o->label[o->count++]=a[i][0];
		l[c++]=o;
		int left=0,right=0,li=-1,ri=-1;
				
		for(j=0;j<c;j++)
		{
			if(l[j]->label[0]==a[i][2])
			{
				
				//printf("Hello Left");
				o->l=l[j];
				left=1;
				li=j;
			}
			if(l[j]->label[0]==a[i][4])
			{

				//printf("Hello Right");
				o->r=l[j];
				right=1;
				ri=j;
			}
		}
		if(!left)
		{
			//Create Left Node
			struct node *o1=malloc(sizeof(struct node));
			o1->val=a[i][2];
			o1->l=o1->r=NULL;
			o1->count=0;
			o1->label[o1->count++]=a[i][2];
			l[c++]=o1;
			o->l=o1;
		}
		if(!right)
		{
			//Create Right Node
			struct node *o1=malloc(sizeof(struct node));
			o1->val=a[i][4];
			o1->l=o1->r=NULL;
			o1->label[o1->count++]=a[i][4];
			o1->count=0;
			l[c++]=o1;
			o->r=o1;
		}
		if(left&&right&&ri==li)
		{
				l[ri]->label[l[ri]->count++]=a[i][3];
				free(o);
				c--;
				
		}
		else
			{
				printf("Node %c Created At %ld With Left Child %c with Address:%ld and Right Child %c with Address:%ld\n",o->val,o,o->l->label[0],o->l,o->r->label[0],o->r);					
			}		
	}
}









//genkill.c
#include<stdio.h>
struct block
{
	char def[30][30];
	int nod;
	int *gen,*kill;
	int *in,*out;
};
int a[30][30],am[30][30];	
struct block *b;
int n,tnod=0,index=0,noe,b1,b2;
int visited[10];

void search(int node,int nodea)
{
	visited[node]=1;	
	a[nodea][node]=1;
	for(int j=0;j<n;j++)
		if(visited[j]==0&&a[node][j]==1)
			search(j,nodea);	
}
 
int main()
{
	printf("Enter number of blocks:");
	scanf("%d",&n);	
	b=malloc(n*sizeof(struct block));			
	
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j]=0;
	for(int i=0;i<n;i++)
	{
		printf("Enter number of definitions in Block B%d:",i+1);
		scanf("%d",&b[i].nod);
		printf("Enter the definitions in Block B%d:\n",i+1);
		for(int j=0;j<b[i].nod;j++)
			scanf("%s",b[i].def[j]);
		tnod+=b[i].nod;	
	}
	for(int i=0;i<n;i++)
	{
		b[i].gen=malloc(tnod*sizeof(int));
		b[i].kill=malloc(tnod*sizeof(int));
		b[i].in=malloc(tnod*sizeof(int));
		b[i].out=malloc(tnod*sizeof(int));
		for(int j=0;j<tnod;j++)
			b[i].gen[j]=b[i].kill[j]=0;	
	}
	//Working on GEN
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<b[i].nod;j++)
		{
			b[i].gen[index+j]=1;
		}
		index+=b[i].nod;
				
	}
	//Working on KILL
	printf("Enter number of edges:");
	scanf("%d",&noe);
	for(int i=0;i<noe;i++)
	{
		printf("Enter the Edge %d:",i+1); 	
		scanf("%d%d",&b1,&b2);
		a[b1-1][b2-1]=1;
		am[b1-1][b2-1]=1;
	}						
	//Adjacency Matrix in a
	char temp;
	for(int i=0;i<n;i++)
	{
		//printf("\nReachability from %d:",i+1);
		for(int j=0;j<n;j++)
					visited[j]=0;
			search(i,i);
	}
	for(int i=0;i<n;i++)
	{	
		for(int i1=0;i1<b[i].nod;i1++)
		{
		int nnod=0;
		for(int j=0;j<n;j++)
		{	
			if(a[i][j]==1&&i!=j)
			{
				for(int k=0;k<b[j].nod;k++)
					if(b[j].def[k][0]==b[i].def[i1][0])
						b[i].kill[nnod+k]=1;
						
			}
			
			nnod+=b[j].nod;
		}
		
		}
	}
	//Printing GEN
	printf("\nGEN:\n");
	for(int i=0;i<n;i++)
	{
		printf("\nBLOCK %d:",i+1);
		for(int j=0;j<tnod;j++)
			printf("%d",b[i].gen[j]);
	}
	printf("\nKILL:\n");
	//Printing KILL
	for(int i=0;i<n;i++)
	{
		printf("\nBLOCK %d:",i+1);
		for(int j=0;j<tnod;j++)
			printf("%d",b[i].kill[j]);
	}

	//Initialialize
	
}

















//codeconver
#include<stdio.h>
char a[30][30];
char reg[6],add[30][2];	
int n;

int isop(char a)
{
	switch(a)
 {
		case '+':
		case '-':
		case '*':
		case '/':return 1;
		default:return 0;
	}
}
int findop(char a)
{
	switch(a)
 {
		case '+':printf("ADD ");break;
		case '-':printf("SUB ");break;
		case '*':printf("MUL ");break;
		case '/':printf("DIV ");break;
	}
}
void comp(int i)
{
	int i1,ind=-1;
	for(i1=0;i1<6;i1++)
	{	
		if(reg[i1]==a[i][2])
			ind=i1;
	}
	if(ind==-1)	
	{
		for(i1=0;i1<6;i1++)
		{		
			if(reg[i1]=='0')
			{
				ind=i1;
				reg[ind]=a[i][2];
				break;
			}
		}
	}
	printf("MOV %c,%c\n",a[i][2],ind+'A');
	findop(a[i][3]);
 if(isdigit(a[i][4]))
  printf("#%c,%c\n",a[i][4],ind+'A');
 else
	printf("%c,%c\n",a[i][4],ind+'A');
	printf("MOV %c,%c\n",i1+'A',a[i][0]);
	reg[i1]=a[i][0];	
}
void assign(int i)
{
	if(isdigit(a[i][2]))
	{
		printf("MOV #%c,%c\n",a[i][2],a[i][0]);
	}
	else
	{
		int inr=-1;
		for(int i1=0;i1<6;i1++)
		{
			if(reg[i1]==a[i][2])
			{
				inr=i1;
				break;
			}				
		}
		if(inr==-1)
		{	for(int i1=0;i1<6;i1++)
				{
					if(reg[i1]=='0')
					{
						inr=i1;
						break;
					}	
				}
			printf("MOV %c,%c\n",a[i][2],inr+'A');				
		}
		printf("MOV %c,%c\n",'A'+inr,a[i][0]);
		reg[inr]=a[i][0];
	}
}
void ifcondn(int i)
{
	int j,flag=-1;
	for(j=0;j<6;j++)
	{
		if(reg[j]==a[i][3])
		{
			flag=j;
			break;
		}
	}
	if(flag==-1)
	{	
		for(j=0;j<6;j++)
		{
			if(reg[j]=='0')
			{
				printf("MOV %c,%c\n",a[i][3],j+'A');
				reg[j]=a[i][3];
				break;
			}
		}
	}
	if(isdigit(a[i][3]))
		printf("CMP %c,#%c",j+'A',a[i][5]);
	else
		printf("CMP %c,%c",j+'A',a[i][5]);	
	if(a[i][4]=='<')
		printf("\nJL");
	else if(a[i][4]=='>')
		printf("\nJG");
	if(a[i][5]=='=')
		printf("E");
	for(j=0;a[i][j+1]!='\0';j++);
	printf(" %c",a[i][j]);
}
void uncondn(int i)
{
	printf("\nJMP %c\n",a[i][strlen(a[i])-1]);
}
int main()
{
	for(int i=0;i<6;i++)
		reg[i]='0';
	printf("Number of TAC statements:");
	scanf("%d",&n);
	printf("Enter TAC statements:\n");	
	for(int i=0;i<n;i++)
	{	
		printf("%d:",i);
		scanf("%s",a[i]);
	}	
	printf("\nTarget Code:\n");
	for(int i=0;i<n;i++)
	{
		//Line By Line
		if(isop(a[i][3]))
			comp(i);
		else if(a[i][3]=='\0')
			assign(i);		
		else if(strstr(a[i],"if"))
				ifcondn(i);
		else if(strstr(a[i],"goto"))
			uncondn(i);	
	}
	printf("\nRegister:\n");
	for(int i=0;i<6;i++)
		printf("%c:%c\n",i+'A',reg[i]);
}
