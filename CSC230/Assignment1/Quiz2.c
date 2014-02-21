/* File: Quiz2MostFrequent-Frame.c */
/* Peter Lebo V00748436 */

/* Given as template to do file I/O for array of integers */
/* for Quiz #2 */

/*CUSTOMIZE DOCUMENTATION! */
/* This programs opens files for input and output, reads */
/* integers from a file until EOF and places them in a 1D array, */
/* Then prints them both to a file and to the screen */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 100

/* global variables and functions */
FILE *fpin1,*fpout1;	/*pointers to files*/

/* ====Function OpenInputFile: opens a given file for input*/
/*    returns file pointer */
FILE *OpenInputFile(char *fileName) {
	FILE	*result;
	result = fopen(fileName, "r");  /* open the file for reading */
	if (result == NULL)   			/* an error opening the file? */
		fprintf(stderr, "cannot read %s\n", fileName);
	return (result);
}
/* ==== Function OpenOutputFile: opens a given file for output*/
/*    returns file pointer */
FILE *OpenOutputFile(char *fileName) {
	FILE	*result;
	result = fopen(fileName, "w");  /* open the file for writing */
	if (result == NULL)   			/* an error opening the file? */
		fprintf(stderr, "cannot write %s\n", fileName);
	return (result);
}
/* ==== Function MostFrequent ==== */
int MostFrequent (int AnyArray[MAXLEN], int length) {
	/*YOUR CODE HERE for 8 marks */
	/* Make sure to include documentation */



	int mf = AnyArray[0];	/*init to be most frequent*/
	int HighFrequency = 1;
	int CurrentFrequency;
	int i;
	int j;

	for(i=0;i<length;i++){
		CurrentFrequency = 1;
		j= i +1;
		if(j == length){
			if(CurrentFrequency > HighFrequency){
				HighFrequency = CurrentFrequency;
				mf = AnyArray[i];
			}
		}else{
			if(AnyArray[j] == AnyArray[i]){
				CurrentFrequency++;
			}
			j++;
		}
	}

	return(mf);
}
/* ==== Function PrArray ==== */
void PrArray(int AnArray[MAXLEN], int length) {
	/*YOUR CODE HERE for 2 marks */
	/* Make sure to include documentation */
	fprintf(fpout1,"Most frequent element is %d\n",MostFrequent(AnArray,length));
}

/**************************************************/


int main() {

    int	MyArray[MAXLEN];	/* main array */
    int	size;				/*number of elements in array*/
    int nir,i;				/* counters */
    int	arraynum =1;		/* array number */

	fprintf(stdout, "Hello\n");		/*start of program*/
	/*open input and output files*/
	fpin1 = OpenInputFile("myQuizinput.txt");
	if (fpin1 == NULL) {
		fprintf(stdout, "Cannot open input file  - Bye\n");
		return(0); 					/*if problem, exit program*/
	}

	fpout1 = OpenOutputFile("myQuizoutput.txt");
	if (fpout1 == NULL) {
		fprintf(stdout, "Cannot open output file - Bye\n");
		return(0); 					/*if problem, exit program*/
	}

	fprintf(stdout,"Starting: \n");
	fprintf(fpout1,"Starting: \n");

	/* read all integers from the input file,and print them */
	nir = fscanf(fpin1,"%d",&size);  /* read number of elements */
	while(nir == 1) {			/*if EOF, fscanf returns 0 int read*/
		fprintf(stdout,"Size of Array (%d) is %d\n",arraynum,size);
		fprintf(fpout1,"Size of Array (%d) is %d\n",arraynum,size);
		for (i=0;i<size;i++)  	/*read array elements */
			nir = fscanf(fpin1,"%d",&MyArray[i]);
		fprintf(stdout,"Array elements are:\n");
		fprintf(fpout1,"Array elements are:\n");
		for (i=0;i<size;i++) {  /*print array elements */
			fprintf(stdout,"%d    ",MyArray[i]);
			fprintf(fpout1,"%d    ",MyArray[i]);
		}
		fprintf(stdout,"\n\n");
		fprintf(fpout1,"\n\n");
		/* YOUR CODE  to call function MostFrequent here */

		MostFrequent(MyArray,size);

		/* YOUR CODE to print a message and the most frequent element here */

		PrArray(MyArray,size);

		nir = fscanf(fpin1,"%d",&size);  /* read number of elements */
		arraynum++;                      /* for next array in file */
	}

	fclose(fpin1);  /* close the files */
	fclose(fpout1);
	fprintf(stdout, "Bye\n");

	return (0);
}
