#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define POP -1
#define ACCEPT -2
#define ERROR -3

#define ALPHABET 3 /* Größe des Eingabealphabets */

#define MAX_LEN 80
/*
 Ein einfacher Kellerautomat ("pushdown automaton")

 Symbol   | (       | )      | \0
 ---------+---------+--------+-----------
 State 0  | PUSH 1  | ERROR  | ACCEPT
 State 1  | PUSH 1  | POP    | ERROR
*/

int states[2][ALPHABET*2] =
{
   {
      '(', 1 /* PUSH 1 */,
      ')', ERROR,
      '\0', ACCEPT
   },
   {
      '(', 1 /* PUSH 1 */,
      ')', POP,
      '\0', ERROR
   }
};


int main( int argc, char** argv )
{
   int stack[100] = { 0 };
   int i  = 0;
   int action  = 0;
   int* tos  = stack;
   char s  [MAX_LEN+1];
   char* p  = s;

   /* Eingabe-Zeichenkette */
   printf("Bitte Ausdruck eingeben: ");
   fgets(s, sizeof(s), stdin);
   s[strlen(s)-1]='\0'; /* Zeilenvorschub (NL) von fgets() durch binäre Null ersetzen */


   /* Startzustand auf Stack ("push") */
   *(tos++) = 0;

   /* Ausführungsschleife */
   do
   {
      /* Aktion auf Basis des Eingabesymbols ermitteln */
      action = ERROR;
      for( i = 0; i < ALPHABET; ++i )
      {
         if( states[*(tos-1)][i*2] == *p )
         {
            action = states[*(tos-1)][i*2+1];
            break;
         }
      }

      /* Ausführen der Aktionen */
      if( action == ERROR )
      {
         printf("Unerwartetes Zeichen an Position %d\n", p-s);
         break;
      }
      else if( action == ACCEPT )
         printf("Ausdruck akzeptiert!\n");
      else if( action == POP )
         --tos;
      else
         *(tos++) = action;

      /* Eingabe erweitern... */
      ++p;
   }
   while( action != ACCEPT );

   return 0;
}