#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char **makeargv(char *);
int main(){
char s[]="sanket ******* haii";
char **myargv;
myargv=makeargv(s);
int i=0;
if(myargv==NULL)
fprintf(stderr,"failed to construct argument array \n");
else{
for( i=0;myargv[i]!=NULL;i++){
printf("myargv[%d]: %s \n",i,myargv[i]);
}
}

}
char **makeargv(char *s){
char *t,**argp;
int ntokens,i;
argp=NULL;
t=(char *)malloc(sizeof(char)*(strlen(s)+1));
strcpy(t,s);
if(strtok(s," ")!=NULL){
for(ntokens=1;strtok(NULL," ")!=NULL;ntokens++);
}
printf("No of tokens: %d \n",ntokens);
argp=(char **)malloc((ntokens +1)*sizeof(char *));
*argp=strtok(t," ");
for(i=1;i<ntokens;i++)
*(argp+i)=strtok(NULL," ");
*(argp+ntokens)=NULL;
return argp;


}
