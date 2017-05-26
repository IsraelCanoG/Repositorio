#include <stdio.h>
#include <string.h>
#include <math.h>

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


int main(){
	char mensaje[100];
	int numero;

	printf("\n\t\t========================================\n\n\tIngrese mensaje a cifrar: ");
	fgets(mensaje,100,stdin);
	printf("\tIngrese la llave numerica: ");
	scanf("%d", &numero);

	*cifrar(mensaje,numero);

	printf("\tMensaje cifrado: %s\n\t\t========================================\n\n", mensaje);
	//printf("%d\n", numero);
	return 0;
}
