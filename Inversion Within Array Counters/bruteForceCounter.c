# include <stdio.h>


int inversionCount(int n, int arr[]){
int i,j = 0;
int inversions =0;

for(i=0; i< n-1; i++){
    for(j=i; j <n; j++){
        if(arr[i] > arr[j]){
            inversions++;
        }
    }
}


    return inversions;
}
  int main(){

    int i,j=0;
    int exampleArr[10] = {1,20,6,4,5};
    int inversions = 0;
    int n = 5;

    inversions = inversionCount(n, exampleArr);

    printf("Inversions Counted: %d", inversions);


   return 0;

}