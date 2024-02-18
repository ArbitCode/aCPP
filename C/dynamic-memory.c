#include<stdio.h>
#include<stdlib.h>

/*
malloc: allocate single block of memory with garbage value
calloc: allocate multiple blocks of memory without garbage value
realloc: resize memory of malloc and calloc memory
free: free memory

*/

/*syntax
malloc: ptr = (type-cast*) malloc(byte-size);
calloc: ptr = (type-cast*) calloc(count, byte-size);
realloc: pre = (type-cast*) realloc(ptr, new-byte-size);
free: free(ptr);
*/

int main(){
    int n, i, *ptr, sum = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    //ptr = (int *)malloc(n * sizeof(int)); 
    ptr = (int *)calloc(n , sizeof(int)); 
    ptr = realloc(ptr, n * 2 * sizeof(int));
    if(ptr == NULL){
        printf("Memory allocation failure!");
        exit(1);
    }
    printf("Elements of array: ");
    for(int i =  0; i < n; i++){
        scanf("%d", ptr + i);
        printf("%d\t", *(ptr + i));
        sum += *(ptr + i);
    }
    printf("\nsum = %d\n", sum);
    free(ptr);
    return 0;
    
}
