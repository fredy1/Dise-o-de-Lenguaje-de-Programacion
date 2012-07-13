%{  
#include <stdio.h>  
#include <conio.h> 
#include "y.tab.h"  
int num_lineas = 0, num_caracteres = 0;  
%}  
%option noyywrap  
%option yylineno  
letra [a-zA-Z]  
digito [0-9]  
ignora " "|\t|\n  
opera /|*|-|+  
operlog &|%
comparador <|>|<=|>=|==|!= 
%%  

{ignora}+                   {;}  

"INICIO"            {return PRINICIO;}
"FINAL"            {return PRFINAL;} 
"SI"            {return PRSI;} 
"SINO"            {return PRSINO;} 
"FINSI"            {return PRFINSI;} 
"PARA"            {return PRPARA;} 
"FINPARA"            {return PRFINPARA;} 
"ENTERO"            {return PRENTERO;} 
"CADENA"            {return PRCADENA;} 
"ARRAY"            {return PRARRAY;} 
"IMPRIMIR"            {return PRIMPRIMIR;} 
"\""({letra}|{digito}|" "|"\t"|"\n")*+"\""  {return CAD;} 
{letra}+                   {return CAR;}  
"["{digito}+"]"    {return ARR;}    
{digito}+                  {return ENT;}  
{digito}+"."{digito}+       {return REA;}  
{comparador}                {return COM;}  
";"                         {return PUNCOM;}  
"!="                        {return DIF;}  
","                         {return COMA;}  
"="                        {return IGU;}  
">="                     {return MAIGO;}  
"<="                     {return MEIGO;}  
"("                         {return APAR;}  
")"                         {return CPAR;}  
">"                      {return MAY;}  
"<"                      {return MEN;}  
"{"                         {return ALLA;}  
"}"                         {return CLLA;}  
"+"                         {return SUM;}  
"-"                         {return RES;}  
"*"                         {return MUL;}  
"/"                         {return DIV;}  
"&"                         {return YY;}  
"%"                         {return OO;}  
\n                          ++num_lineas;  
.                           {return ERROR;}  
%%  
int main(int argc,char *argv[])  
{  
char NomArch[30];  
printf("Ingrese nombre de archivo: ");  
gets(NomArch);  
if ((yyin = fopen(NomArch, "rt")) == NULL)  
 {  
  printf("\nNo se puede abrir el archivo: %s\n", NomArch);  
 }  
 else  
 {    
  yyparse();  
 }  
 fclose(yyin);  
getch(); 
 return 0;  
} 