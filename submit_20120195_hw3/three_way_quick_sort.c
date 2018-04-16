/**
 * "three-way Quick Sort"
 * - ./three_way__quick_sort <input_file_name> <N>
 * - measure running time of 'three-way Quick Sort'
 *
 * name / ID Yoon Hyowon / 20120195
  **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>

void choose_pivot (int *data, unsigned int n) { 
   	int temp;
	int *start=data;
   	int *randIdx=start+rand()%n;//rand Idx: start~end
  
	temp=*randIdx;
   	*randIdx=*start;
   	*start=temp;
}

unsigned long three_way_quick_sort (int *data, unsigned int n) {
    unsigned long cnt = (n - 1); // number of comparisons
	int *start,*end;
	int *i,*j,*s;
	int temp;

	if(n<=1)
		return cnt;
	start=data;
	end=start+n-1;
	i=start+1;
 	s=end;

    // choose pivot and  always place it at first element of array
	choose_pivot(data, n);
	
	while(*s==*start&&s==start+1)//if *s equal to pivot
		s--;

	for(j=start+1;j<=s;j++){
		if(*start==*j){
			temp=*s;
			*s=*j;
			*j=temp;
			s--;
		}
		if(*start>*j){
			temp=*i;
			*i=*j;
			*j=temp;
			i++;
		}//swap
	}
	temp=*(i-1);
	*(i-1)=*start;
	*start=temp;//pivot swap
	
	three_way_quick_sort(data,(i-start-1));//front

	if(s!=end){
		for(s=s+1;s<=end;s++){
			temp=*i;
			*i=*s;
			*s=temp;
			i++;
		}
	}//middle
	
	data=i;//change start
	
	three_way_quick_sort(data,(end-i+1));//back	
    return cnt;
	
}


int main (int argc, char* argv[]) {
	if(argc!=3){
		puts("command line input error");
		return -1;
	}//command line input error
	
	FILE *src=fopen(argv[1], "rt");//file directory, name
	char *end;
	int size=strtol(argv[2],&end,10);//size of array(input)+start idx
	int idx=0;//index: start of the array
	int*arr=(int*)malloc(sizeof(int)*size);
	int check;
	int N;
	double duration;
	
	if(src==NULL){
		puts("error: failed to open the file");
		return -1;
	}//file open error

	if(*end){
		puts("command line input error: check the input format");
		return -1;
	}//if : input is not in a number format

	while(EOF!=fscanf(src,"%d",&arr[idx])){
		if(size==idx){
			break;
		}//read the first N integers
		idx++;
	}
	
	if(idx!=size){
		size=idx;//actual size of the array;
		arr=(int*)realloc(arr,sizeof(int)*size);
	}
	N=idx;
	duration=clock();
	three_way_quick_sort(arr,size);
	duration=clock()-duration;
	check=arr[0];
	for(idx=0;idx<size;idx++){
		printf("%d\n", arr[idx]);
		if(check>arr[idx]){
			puts("not sorted");
			break;}//if not sorted
		check=arr[idx];
	}
	
	
	// Please keep these printf statements!
    printf("N = %7d,\tRunning_Time = %.3f ms\n", N, duration);

	free(arr);
	fclose(src);
    return 0;
}

