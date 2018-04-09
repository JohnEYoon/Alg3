/**
 * "Quick Sort"
 * - ./basic_quick_sort <input_file_name> <N>
 * - measure running time of 'Quick Sort'
 *
 * name / ID Yoon Hyowon / 20120195
  **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>


void choose_pivot (int *data, unsigned int n) { 
   int temp;
   int randIdx=rand()%n;//rand Idx: 1~(n-1)
   temp=data[randIdx];
   data[randidx]=data[0];
   data[0]=temp;
}

unsigned long quick_sort (int *data, unsigned int n) {
    unsigned long cnt = (n - 1); // number of comparisons
	/* your code here */
	int i, j;
	int temp;
	i=1;
    // choose pivot and  always place it at first element of array
    choose_pivot(data, n);
    
	for(j=1;j<n;j++){
		if(data[1]<data[j]){
			temp=data[i];
			data[i]=data[j];
			data[j]=temp;
			i++;
		}//swap
	
	temp=data[i-1];
	data[i-1]=data[0];
	data[0]=temp;
	quick_sort=(data,n);
	
	quick_sort(data,);//front
	quick_sort(data,);//back
	
	/* your code here */

	
    return cnt;
}



int main (int argc, char* argv[]) {





	/* your code here */


	/* your code here */

	
	/* your code here */
	
	
	// Please keep these printf statements!
    printf("N = %7d,\tRunning_Time = %.3f ms\n", N, duration);

	/* your code here */
	
		
    return 0;
}

