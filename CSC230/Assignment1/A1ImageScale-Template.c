/* File: A1ImageScale.c - Csc 230 Assignment 1  */
/* Micaela Serra - Student Number V00123456  */
/* The program reads a 2D image from an input file,
 	rotates it right by 90 degrees, scales it to double its size
	twice with two different algorithms.
	It prints the new images each time.
	The 2D image is read as integers and stored and
	handled as a 2D array of characters. */

/******TEMPLATE ONLY TO START: DOES NOT COMPILE OR EXECUTE *****/

/****** PSEUDO CODE: ******
	*Initialization
		Open the input file
			if problems, print message and exit program directly
		Print a welcome message for the program start with identification
	*Obtain the input data:
		Read row dimension of image
		While not end-of-file:
			Read the column dimension
			Read elements of image as integers, convert to characters,
				and store as 2D char array
			Print image as characters with headings
	*Processing the image:
		Rotate the original image right by 90 degrees and print it
		Scale the image to double size and print it
		Scale the image to double size with vector algorithm and print it
	*Continue for more images:
		Repeat the process for other images until end of file
			(read row dimension and go to While)
	*Closure:
		When end-of-file is reached
		Print a final message and close the input file
		Exit the program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXROW 50
#define MAXCOL 50
#define	AP	'&'
#define	PL	'+'

/* possible global variables*/
FILE *fpin1;	/*pointer to input file*/

/*************************************************************/
/**** Function OpenInputFile: opens a given file for input****/
/*    returns file pointer */
FILE *OpenInputFile(char *fileName) {
	FILE	*result;
	result = fopen(fileName, "r");  /* open the file for reading */
	if (result == NULL)   			/* an error opening the file? */
		fprintf(stderr, "cannot read %s\n", fileName);
	return (result);
}

/*************************************************************/
/****** void PrImage(Image, Nrows,Ncols) ******/
/* This procedure prints a 2D char array row by row */
void PrImage( char Image[MAXROW][MAXCOL], int Nrows, int Ncols)
{
	int ii, jj;
	for(ii = 0; ii < Nrows; ii++) {
		for(jj = 0; jj < Ncols; jj++) {
			fprintf(stdout, " %2c", Image[ii][jj]);
		}
		fprintf(stdout, "\n");
	}
}/*End of PrImage*/

/*************************************************************/
/****** void CopyColRow(Mat1,Mat2,Nrows,Ncols,Coli,Rowj) ******/
/* Copy col i of Mat1 from 0 to Nrows-1
	to row j of Mat2 from Ncols-1 to 0 */
/* That is, copy a specified column of Mat1 from top
	element to bottom into the specified row of Mat2
	from right to left*/
/*Called by RotR in a loop*/
/*This is not strictly necessary, but it is useful to modularize
		the processing */
void CopyColRow( char Mat1[MAXROW][MAXCOL], char Mat2[MAXROW][MAXCOL],
	int Nrows, int Ncols, int Coli, int Rowj)
{
	/*YOUR CODE HERE*/
	/*copy a single given column of Mat1 from top
		element to bottom (i.e. from 0 to Nrows) into
		the given single row of Mat2, from right to left
		(i.e. from Ncols-1 to 0) */


}/*End of CopyColRow*/


/*************************************************************/
/****** void RotR(Image1, Image2, Nrows, Ncols) ******/
/*Given the 2D char array of Image1 and its dimensions,
	construct the rotated by 90 degree image in Image2 */
	/*NOTE: dimensions of Image2 are inverted from Image1 */
	/*It may call CopyColRow (if so chosen) in a loop to copy each column
	of Image1 into its corresponding row into Image 2*/
void RotR( char Image1[MAXROW][MAXCOL], char Image2[MAXROW][MAXCOL],
	int Nrows, int Ncols)
{
	printf("\n Not yet implemented\n");

	/*YOUR CODE HERE*/
	/*Loop for each column of Image1*/
	/*Copy that column into a row of Image 2
		by calling CopyColRow*/


}/*End of RotR*/

/*************************************************************/
/****** void ScaleUp2(Image1, Image2, Nrows, Ncols) ******/
/*Given the 2D char array of Image1 and its dimensions,
	construct Image 2 of twice its size */

void ScaleUp2( appropriate parameters )
{
	printf("\n Not yet implemented\n");

	/*YOUR CODE HERE*/

	/*loop for each element [i][j] of Image 1 starting
		at i=0 and j=0 and let r=0 and c=0 be the
		indeces into elements [r][c] of Image2
	Each element at position [i][j] of Image1
		must be replicated into 4 positions of Image2:
		Image2[r][c], Image2[r][c+1],
		Image2[r+1][c], Image2[r+1][c+1]
	Increase or reset r and c appropriately where needed.*/

}/*End of ScaleUp2*/

/*************************************************************/
/****** void ScaleUp2a(Image1, Image2, Nrows, Ncols) ******/
/*Given the 2D char array of Image1 and its dimensions,
	construct Image 2 of twice its size */
/*Makes the elements of the 2D array into one 1D vector
	and operates on it */
/* Uses an interpolation algorithm based on simple
	near-neighbour to replicate each character/pixel into
	4 of them in a square. Takes advantage of the storage
	viewed as a one 1D vector and interpolates each
	elements into another 1D vector which can be viewed as
	the correct 2D enlarged image */
/* Given the static allocation used here, the 2D image must
	first be stored as the expected 1D vector on which the
	algorithm can then operate. Not efficient, but useful
	for this programming exercise */
/*The original near-neighbour algorithm uses the x_ratio
	and y_ratio (which can be arbitrary) as floating point numbers.
	This version replaces all floating point variables with integers
	and multiplies the original values by 65636=2^16 before calculating
	the scaling ratios. The << operator is the bitwise shift left
	operator, and x<<16 is equivalent to x*65536, since shifting left by
	16 bits is equivalent to multiplication by 2^16 in binary. The >>16 is equivalent
	to division by 65536. This is one way of extending integers and
	using the lower 16 bits as equivalent to the values of the fractional
	part */

void ScaleUp2a( appropriate parameters)
{
	int i,j,k;
	char temp1[MAXROW*MAXCOL];
	char temp2[(MAXROW*2)*(MAXCOL*2)];
	int x_ratio,y_ratio,x2,y2,Nrows2,Ncols2;

	Nrows2=Nrows*2;
	Ncols2=Ncols*2;

	printf("\n Not yet implemented\n");

	/*Copy current elements of 2D image into the 1D vector temp1*/
		/*YOUR CODE HERE*/

	/*Compute the scaling ratio as integers (here always
		doubling the size however) */
	/*Note: added +1 to account for rounding problem*/
	/*Precise conversion from floating to int*/
	x_ratio = (int)((Ncols<<16)/Ncols2)+1;
	y_ratio = (int)((Nrows<<16)/Nrows2)+1;

	/*Compose the new 1D vector of correct size - twice here*/
	for (i=0;i<(Nrows2);i++) {
		for (j=0;j<Ncols2;j++) {
			x2 = ((j*x_ratio)>>16);
			y2 = ((i*y_ratio)>>16);
			temp2[(i*Ncols2)+j] = temp1[(y2*Ncols)+x2];
		}
	}

	/*Copy the new 1D longer vector temp2 into new 2D scaled up Image2*/
		/*YOUR CODE HERE*/

}/*End of ScaleUp2a*/

/*************************************************************/
/***VERSION 1: FILE POINTER PASSED AS PARAMETER ***/
/****** int RdSize(FILE *fpi,*Nrows,*Ncols) ******/
/*Read from an input file two integers for the number of rows and
	number of columns of the image to be processed */
/* Check for possible end of file after reading row dimension.
	If EOF, return 0*/
/* int RdSize(appropriate parameters) */
{
	/*fpin1, the pointer to the input file, can be global */
	/*YOUR CODE HERE*/

	/* 	Read Row dimension into Nrows
		If not end-of-file (as returned by scanf) then
			read Column size into Ncols
		Return end-of-file flag to caller function*/

	/*Note: scanf returns an integer equal to the number
		of integers read in - in this case it should be 1.
		In case of end of file, it returns an integer < 0
		(probably -1) */


/* }*/
	/*End of RdSize*/

/*************************************************************/
/***VERSION 2: FILE POINTER REMAINS GLOBAL ***/
/****** int RdSize(*Nrows,*Ncols) ******/
/*Read from an input file two integers for the number of rows and
	number of columns of the image to be processed */
/* Check for possible end of file after reading row dimension.
	If EOF, return 0*/
/* int RdSize(appropriate parameters) */
{
	/*fpin1, the pointer to the input file, can be global */
	/*YOUR CODE HERE*/

	/* 	Read Row dimension into Nrows
		If not end-of-file (as returned by scanf) then
			read Column size into Ncols
		Return end-of-file flag to caller function*/

	/*Note: scanf returns an integer equal to the number
		of integers read in - in this case it should be 1.
		In case of end of file, it returns an integer < 0
		(probably -1) */


/* }*/
	/*End of RdSize*/

/*************************************************************/
/***VERSION 1: FILE POINTER PASSED AS PARAMETER ***/
/****** void RdImage(FILE *fpi,Image,Nrows,Ncols) ******/
/*Read from an input file the integers describing the image to
	be processed and store the corresponding character in the 2D array*/
void RdImage(FILE *fpi,char Image1[MAXROW][MAXCOL],int Nrows, int Ncols)
{
	/*fpin1, the pointer to the input file, can be global */

	/*YOUR CODE HERE*/

	/*	Loop through the 2D Image for each element [i][j]
		Read an integer from a file using scanf
		If the integer = 0, then place character PL into
			Image[i][j]
		Else place character AP*/

	/*Input file is guaranteed to contain the correct
		number of elements and thus there is no need to check
		here for end of file */

}/*End of RdImage*/

/*************************************************************/
/***VERSION 2: FILE POINTER REMAINS GLOBAL ***/
/****** void RdImage(Image,Nrows,Ncols) ******/
/*Read from an input file the integers describing the image to
	be processed and store the corresponding character in the 2D array*/
void RdImage(char Image1[MAXROW][MAXCOL],int Nrows, int Ncols)
{
	/*fpin1, the pointer to the input file, can be global */

	/*YOUR CODE HERE*/

	/*	Loop through the 2D Image for each element [i][j]
		Read an integer from a file using scanf
		If the integer = 0, then place character PL into
			Image[i][j]
		Else place character AP*/

	/*Input file is guaranteed to contain the correct
		number of elements and thus there is no need to check
		here for end of file */

}/*End of RdImage*/

/*************************************************************/
/*************************************************************/
int main() {

    int	eof;
    int Rsize1, Csize1;	/*original image sizes*/
	char IMchr1[MAXROW][MAXCOL]; /*original image*/
	char IMchrUP[MAXROW][MAXCOL]; /*resulting image after scaling up*/
	char IMchrRot[MAXROW][MAXCOL]; /*resulting image after rotating*/

	fprintf(stdout, "Hello:\n");		/*start of program*/
	/*open all input and output files*/
	fpin1 = OpenInputFile("Image1.txt"); /*file name hardcoded here*/
	if (fpin1 == NULL) {
		fprintf(stdout, "Cannot open input file - Bye\n");
		return(0); /*if problem, exit program*/
	}

	/*welcome message*/
	/* CUSTOMIZE ALL DOCUMENTATION, HERE AND ELSEWHERE */
	fprintf(stdout, "\n Captain Picard - Student Number V00123456 \n");
	fprintf(stdout, "\n File = A1csc230.c	- Spring 2014 \n");
	fprintf(stdout, "\n CSC 230, Assignment 1, Part 2 \n\n");
	fprintf(stdout,"Starting: \n");

	/*Read in the dimensions for the image*/
	/*Call RdSize with appropriate parameters*/ /*if EOF, returns 0*/
	while (eof >0) {
		/*Read in the image*/
		/*Call RdImage with appropriate parameters*/

		/*Print the initial image*/
		fprintf(stdout, "\n \n Initial IMchr1 contains: \n");
		PrImage(IMchr1, Rsize1, Csize1);

		/*Scale image up to twice the size*/
		/*Call ScaleUp2 with appropriate parameters*/
		fprintf(stdout, "\n Scaled Up IMchrUP contains: \n");
		PrImage(appropriate parameters);

		/*Scale image up to twice the size using the second algorithm*/
		/*Call ScaleUp2a with appropriate parameters*/
		fprintf(stdout, "\n Scaled Up (NEW) IMchrUP contains: \n");
		PrImage(appropriate parameters);

		/*Rotate original image right by 90 degrees and print*/
		/*Call RotR with appropriate parameters*/
		fprintf(stdout, "\n Rotated IMchrRot contains: \n");
		PrImage(appropriate parameters);

		/* read the size for the next image, if any*/
		/*Call RdSize with appropriate parameters*/ /*if EOF, returns 0*/
	}

	/* Closure */
	fprintf(stdout, "\n The program is all done - Bye! \n");

	fclose(fpin1);  /* close the files */

	return (0);
}/*End of Main*/
