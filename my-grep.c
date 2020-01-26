#include<stdio.h>
#include <string.h>


int main(int argc, char *argv[])
{
    FILE * fp;
    if(argv[2] == NULL){
        printf("usage: my-grep searchterm [file ...]\n");
        return 0;
    }
    else{
        fp = fopen(argv[2], "r");
        int str_len;
        size_t buf_siz = 1;
        char *string = NULL; 
        char *pattern = argv[1];

        if (!fp){
            fprintf(stderr, "stderr: file does not exist.\n");
            return 0;
        }

        while ((str_len = getline(&string, &buf_siz, fp)) > 0)
            {
            if (strstr(string, pattern))
                printf("%s", string);
            }
        fclose(fp);
    }
    return 0;
}