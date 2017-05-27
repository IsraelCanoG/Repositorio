#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

char *cifrar(char *mensaje,int n){
    int i,j;
    for(i=0;i<strlen(mensaje);i++){
        for(j=0;j<fabs(n);j++){
            if(((mensaje[i]>=65&&mensaje[i]<90) || (mensaje[i]>=97 && mensaje[i]<122)) && n>0){ 
		mensaje[i]++;
	    }else if(((mensaje[i]>65&&mensaje[i]<=90) || (mensaje[i]>97 && mensaje[i]<=122)) && n<0){
	    	mensaje[i]--;
            }else if((mensaje[i]==90) && (n>0)){
                mensaje[i]=65;
            }else if((mensaje[i]==122) && (n>0)){
                mensaje[i]=97;
	    }else if((mensaje[i]==65) && (n<0)){
		mensaje[i]=90;
	    }else if((mensaje[i]==97) && (n<0)){
		mensaje[i]=122;
	    }
        }
    }
    return mensaje;
}


char *cifrarMorse(char *mensaje){
    char *tabla[36]={".-", "-...", "-.-.", "-..", "." , "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
                         "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---",
                         "...--", "....-", ".....", "-....", "--...", "---..", "----."};
    int i,j;
    for(i=0;i<strlen(mensaje);i++){
    	if((mensaje[i]>=97&&mensaje[i]<=122)){
		printf("%s ", tabla[mensaje[i]-97]);
	}else if((mensaje[i]>=65&&mensaje[i]<=90)){
		printf("%s ", tabla[mensaje[i]-65]);
	}else if (mensaje[i]==32){
		printf("/ ");
	}else if((mensaje[i]>=48&&mensaje[i]<=57)){
		printf("%s ", tabla[mensaje[i]-22]);
	}
    }
	return mensaje;
}

int main(int argc, char * argv[]){
	int numero;
	if(argc<3 || argc >3){
		printf("\n\t\t========================================\n\n\tIngrese mensaje a cifrar: ");
		fgets(argv[1],100,stdin);
		printf("\tIngrese la llave numerica: ");
		scanf("%d", &numero);
		*cifrar(argv[1],numero);
		printf("\tMensaje cifrado: %s",argv[1]);
        	printf("\tMensaje cifrado en morse: ");
        	*cifrarMorse(argv[1]);
        	printf("\n\n\t\t========================================\n\n");
	}else if(argc==3){
		printf("\n\t\t========================================\n\n");
                numero=strtol(argv[1], NULL, 10);
		*cifrar(argv[2],numero);
        	printf("\tMensaje cifrado: %s",argv[2]);
        	printf("\tMensaje cifrado en morse: ");
        	*cifrarMorse(argv[2]);
        	printf("\n\n\t\t========================================\n\n");
	}else{
		printf("\n\t\t========================================\n\n");
		numero=strtol(argv[1], NULL, 10);
	}
return 0;
}
