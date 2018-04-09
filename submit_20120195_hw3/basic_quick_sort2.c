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
	int start=data[0];
   	int randIdx=rand()%n+start;//rand Idx: start~end
   	temp=data[randIdx];
   	data[randIdx]=data[start];
   	data[start]=temp;
}

unsigned long quick_sort (int *data, unsigned int n) {
    unsigned long cnt = (n - 1); // number of comparisons
	int start, end, temp;
	int i, j;
	/* your code here */
	if(n<=1)
		return cnt;
	start=data[0];
	end=start+n-1;
	i=start+1;
    // choose pivot and  always place it at first element of array
	choose_pivot(data, n);
    
	for(j=start+1;j<=end;j++){
		if(data[start]>data[j]){
			temp=data[i];
			data[i]=data[j];
			data[j]=temp;
			i++;
		}//swap
	}
	
	temp=data[i-1];
	data[i-1]=data[start];
	data[start]=temp;//start-pivot swap
	
	quick_sort(data,i-start-1);//front
	data[0]=i;//change start
	quick_sort(data,end-i+1);//back
	
	/* your code here */

	
    return cnt;
}



int main (int argc, char* argv[]) {
	if(argc!=3){
		puts("command line input error");
		return -1;
	}//command line input error

	FILE *src=fopen(argv[2], "rt");//file directory, name
	char *end;
	int size=strtol(argv[1],&end,10)+1;//size of array(input)+start idx
	int tempSize=size;
	int idx=1;//index: start of the array
	int*arr=(int*)malloc(sizeof(int)*size);
	if(src==NULL){
		puts("error: failed to open the file");
		return -1;
	}//file open error

	if(*end){
		puts("command line input error: check the input format");
		return -1;
	}//if : input is not in a number format
	arr[0]=idx;//arr[0]=start of the array
	while(feof(src)==0){
		fscanf(src, "%d", &arr[idx]);
		idx++;
		if(tempSize<idx){
			tempSize+=1000000;
			arr=(int*)realloc(arr,sizeof(int)*(tempSize));
		}//if:file input is bigger than command line input
	}
	if(idx-1!=tempSize){
		tempSize=idx-1;//actual size of the array;
		arr=(int*)realloc(arr,sizeof(int)*tempSize);
	}//realloc: final size of the array
	quick_sort(arr, tempSize-1);
	arr=(int*)realloc(arr,sizeof(int)*size);	
	for(idx=1;idx<size;idx++)
		printf("%d\n", arr[idx]);
	/* your code here */
	printf("%d\n", tempSize);
	printf("%d\n", size);
	/* your code here */

	
	
	// Please keep these printf statements!
    //printf("N = %7d,\tRunning_Time = %.3f ms\n", N, duration);

	/* your code here */
	free(arr);
	fclose(src);
    return 0;
}
