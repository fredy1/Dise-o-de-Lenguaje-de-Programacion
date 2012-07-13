%{  
int yystopparser=0;  
%}
%token PRINICIO PRFINAL PRSI PRSINO PRFINSI PRPARA PRFINPARA PRENTERO PRCADENA PRARRAY PRIMPRIMIR CAD CAR ARR ENT REA COM PUNCOM DIF COMA IGU MAIGO MEIGO APAR CPAR MAY MEN ALLA CLLA SUM RES MUL DIV YY OO ERROR

%start inicio  
  
%% 
inicio  : estruc cuerpo

  ;
estruc : ALLA declaracion CLLA {printf("ESTRCTURA CORRECTA\n");}
;
declaracion : PRENTERO CAR declaracion {printf("DECLARACION ENTERO\n");}
| PRENTERO CAR IGU ENT declaracion {printf("DECLARACION ENTERO\n");}
| PRENTERO CAR {printf("DECLARACION ENTERO\n");}
| PRENTERO CAR IGU ENT {printf("DECLARACION ENTERO\n");}
| PRCADENA CAR declaracion {printf("DECLARACION CADENA\n");}
| PRCADENA CAR IGU CAD declaracion {printf("DECLARACION CADENA\n");}
| PRCADENA CAR {printf("DECLARACION CADENA\n");}
| PRCADENA CAR IGU CAD {printf("DECLARACIOON CADENA\n");}
| PRARRAY CAR ARR declaracion {printf("DECLARACION ARRAY\n");}
| PRARRAY CAR ARR IGU ALLA terarr CLLA declaracion {printf("DECLARACION ARRAY\n");}
| PRARRAY CAR ARR {printf("DECLARACION ARRAY\n");}
| PRARRAY CAR ARR IGU ALLA terarr CLLA {printf("DECLARACION ARRAY\n");}
;
terarr : ENT
| ENT COMA terarr
;
cuerpo : PRINICIO cond PRFINAL {printf("PROGRAMA CORRECTO\n");}
| PRINICIO bucl PRFINAL  {printf("PROGRAMA CORRECTO\n");}
|PRINICIO oper PRFINAL    {printf("PROGRAMA CORRECTO\n");}
;


cond : PRSI res sentencia PRFINSI {printf("SENTENCIA SI CORRECTA\n");} r
| PRSI res sentencia PRSINO sentencia PRFINSI {printf("SENTENCIA SI CORRECTA\n");} r
;
res : APAR con CPAR YY res
| APAR con CPAR OO res
| APAR con CPAR
;
con : CAR COM CAR
|CAR COM ENT
|ENT COM ENT
|ENT COM CAR
;
sentencia :  ALLA cond CLLA
| ALLA bucl CLLA
| ALLA oper CLLA
;
oper : 
| CAR IGU we  oper  {printf("OPERACION CORECTA\n");}
;

we: CAR SUM we
| CAR {printf("OPERACION CORECTA\n");}  
| ENT SUM we
| ENT {printf("OPERACION CORECTA\n");}  
| CAR RES we
| ENT RES we
| CAR MUL we
| ENT MUL we
| CAR DIV we
| ENT DIV we
| CAR ARR SUM we
| CAR ARR {printf("OPERACION CORECTA\n");}  
| CAR ARR RES we
| CAR ARR MUL we
| CAR ARR DIV we
;

bucl : PRPARA APAR inc COMA cdc COMA paso CPAR sentencia PRFINPARA {printf("SENTENCIA PARA CORRECTA\n");} r
;
inc : CAR IGU ENT
;
cdc : CAR COM ENT
;
paso : CAR SUM SUM
| CAR RES RES
| oper
;
r : 
| cond
| bucl
;

