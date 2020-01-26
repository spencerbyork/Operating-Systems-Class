#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define LSIZ

// Defining comparator function as per the requirement 
static int myCompare(const void* a, const void* b) 
{ 
  
    // setting up rules for comparison 
    return strcmp(*(const char**)a, *(const char**)b); 
} 
  
// Function to sort the array 
void sort(char * arr[], int n) 
{ 
    // calling qsort function to sort the array 
    // with the help of Comparator 
    qsort(arr, n, sizeof(const char*), myCompare); 
        int i;
        for (i = 0; i < n; i++)

            printf("%s", arr[i]); 
} 
  

int main(int argc, char *argv[])
{
    
    FILE * fp;
    int count = 0;
    char **buffer;
    if(argv[1] == NULL){
        fp = stdin;
        size_t numbersize = 3000;
        buffer = malloc(numbersize * sizeof(char *));
         size_t sizeofline = 0;
        while(getline(buffer+count, &sizeofline,fp) != -1)
            {
                if(count == numbersize)
                {
                    numbersize += 3000;
                    buffer = realloc(buffer, numbersize);
                }
                ++count;
            }
            sort(buffer, count);
        fclose(fp);
    }
    else{
        size_t numbersize = 3000;
        buffer = malloc(numbersize * sizeof(char *));
        fp = fopen(argv[1], "r");
        if (!fp){
            fprintf(stderr, "stderr: file does not exist.\n");
            return 0;
        }
         size_t sizeofline = 0;
        while(getline(buffer+count, &sizeofline,fp) != -1)
            {
                if(count == numbersize)
                {
                    numbersize += 3000;
                    buffer = realloc(buffer, numbersize);
                }
                ++count;
            }
            sort(buffer, count);
        fclose(fp);
    }
    
  
    return 0;
}