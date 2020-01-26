#include<stdio.h>

int main(int argc, char *argv[])
{
    int i;
    FILE * fp;
    char buffer[1000];
    if(argv[1] == NULL){
        printf("usage: my-cat file\n");
        return 0;
    }
    for(i=1; i<argc; i++){
        fp = fopen(argv[i], "r");
        if (!fp){
            fprintf(stderr, "stderr: file does not exist.\n");
            return 0;
        }

        while(fgets(buffer, 1000, fp)){
            printf("%s", buffer);
            
        }
        fclose(fp);
    }
        printf("%s\n", argv[i]);
    return 0;
}