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

