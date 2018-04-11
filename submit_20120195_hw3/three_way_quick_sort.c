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
	/* your code here */
	if(n<=1)
		return cnt;
	start=data;
	end=start+n-1;
	i=start+1;
 	s=end;

    // choose pivot and  always place it at first element of array
	choose_pivot(data, n);
	
	while(*s==*start&&s==start+1){//if *s equal to pivot
		s--;
	}

	for(j=start+1;j<=s;j++){
	
		if(*start==*j){
			temp=*s;
			*s=*j;
			*j=temp;
			s--;
			if(s<data)
				puts("error");
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
//	printf("pivot: %d=",*(i-1)); 
	//puts("no prob before sort");
	//if(s==end)
	//	puts("no duplicate");
	three_way_quick_sort(data,(i-start-1));//front
	//printf("pivot: %d,%d: ", *start,*data);
	//puts("no prob after first part");
	if(s!=end){
	//	puts("start mid");
		for(s=s+1;s<=end;s++){
			temp=*i;
			*i=*s;
			*s=temp;
			i++;
		//	printf(" %d, ",*(i-1));
		}
		if(i>end)
			puts("smthing wrong");
		//printf("\n%d", cc);
	}//middle
	//puts("no prob after mid");
	data=i;//change start
//	puts("no prob after allocation");
	if(i>end){
		puts("error");
		return cnt;}
	three_way_quick_sort(data,(end-i+1));//back	
//	puts("not prob after back sort");
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
	//time
	three_way_quick_sort(arr,size);
	//time

	for(idx=0;idx<size;idx++)
		printf("%d\n", arr[idx]);
	
	printf("size: %d\n", size);
	
	// Please keep these printf statements!
    //printf("N = %7d,\tRunning_Time = %.3f ms\n", N, duration);

	free(arr);
	fclose(src);
    return 0;
}

