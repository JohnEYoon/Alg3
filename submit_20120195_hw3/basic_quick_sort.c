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
   int randIdx=rand()%n+start;//rand Idx: start~(n-1)
   temp=data[randIdx];
   data[randidx]=data[start];
   data[start]=temp;
}

unsigned long quick_sort (int *data, unsigned int n) {
    unsigned long cnt = (n - 1); // number of comparisons
	/* your code here */
	int static start=0;
	int end, temp;
	int i, j;
	end=start+n-1;
	i=start+1;
    // choose pivot and  always place it at first element of array
    if(n==1)
		return cnt;
	choose_pivot(data, n);
    
<<<<<<< HEAD
	for(j=1;j<n;j++){
		if(data[1]<data[j]){
=======
	for(j=start+1;j<=end;j++){
		if(data[start]<data[j]){
>>>>>>> f7ad0eaaf489286ddb280c1e50b4cacb4b17610a
			temp=data[i];
			data[i]=data[j];
			data[j]=temp;
			i++;
		}//swap
	}
	
	temp=data[i-1];
	data[i-1]=data[start];
	data[start]=temp;
	
	quick_sort(data,i-start-1);//front
	start=i;
	quick_sort(data,end-i+1);//back
	
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

