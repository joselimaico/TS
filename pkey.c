#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){

FILE * fp;
FILE * fs;
char c [60];

if(argc!=2){printf("modo de uso: %s <nombre_archivo>\n",argv[0]); exit(1);}

fp=fopen("pk-aux","w");

//comando que transforma la llave publica a su formato hexadecimal
fprintf(fp,"awk '{print $2}' %s | base64 -d | hexdump",argv[1]); 

fclose(fp);  

fs=fopen("pk-aux","r");



fgets(c,60,fs);
printf("%s\n",c);

fclose(fs);

system(c);

printf("\n00 00 00 07: siguiente grupo tiene una longitud de 7 bytes\n");
printf("73 73 68 2d 72 73 61: ssh-rsa\n");
printf("00 00 00 03: siguiente grupo tiene una longitud de 3 bytes\n");
printf("01 00 01: exponente e (65537)\n");
printf("00 00 01 01: el siguiente bloque tiene una longitud de 257 bytes\n");
printf("modulo n\n");
}

