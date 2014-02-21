/* File: A1ImageScale.c - Csc 230 Assignment 1  */
/* Peter Lebo - Student Number V00748436 */

/*  This program will keep reading in 2d arrays from an input text file and save them as a series of '+'s and '&'s depending on their 0 and 1 values*/
/*	then it will scale up that 2d array of characters to twice it's original size. this program does it in two different procedures*/
/*	utilizing two different methods to do so. Then it will rotate the original shape 90 degrees clockwise*/
/* It will repeat this process while there still are more 2d arrays to read in from the input file,and then provide an end ofprogrammessage*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXROW 50
#define MAXCOL 50
#define	AP	'&'
#define	PL	'+'

FILE *fpin1;	/* global file pointer variable in order to make it easier for functions to access the input file */

/*************************************************************/
/**** Function OpenInputFile: opens a given file for input****/
/*    returns file pointer  if a valid file path*/
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

/************* RdSize(fpin1,Rsize,Csize)**************/
	/*check if there's a valid Row size integer present and save it as Rsize1*/
		/*if there is, do the same for the column size and save it as Csize1*/
			/*if that goes well too, return a flag saying we were successful*/
		/*otherwise, kill the procedure and return an 'insuccessful procedure flag*/

int RdSize(FILE *fpin1, int *Rsize1, int *Csize1) 
{
	int eof;
	eof = fscanf(fpin1, "%d", Rsize1);
	if (eof < 0){
		return -1;
	}else{
		fscanf(fpin1, "%d", Csize1);
	}
	return 1;
}

/**************void RdImage(fpi, Image1, Nrows, Ncols)*****************/
	/*for 0 to number of rows*/
		/*for 0 to number of columns*/
			/*read the next integer in and save it to temp*/
			/*if the integer is a 0, save it to the 2d array as a '+' char */
			/*otherwise, save it as a '&' char*/
	/*exit subroutine*/

void RdImage(FILE *fpi,char Image1[MAXROW][MAXCOL],int Nrows, int Ncols)
{
	int i, j;
	int temp = 1;
	for(i=0; i<Nrows;i++){
		for(j=0; j<Ncols;j++){
			fscanf(fpi,"%d", &temp);
			if (temp == 0){
				Image1[i][j] = '+';
			}else{
				Image1[i][j] = '&';
			}
		}
	}

}/*End of RdImage*/

/*************************************************************/
/****** void ScaleUp2(Image1, Image2, Nrows, Ncols) ******/
/*Given the 2D char array of Image1 and its dimensions,*/
/*construct Image 2 of twice its size */
/*for 0 to number of rows in original image*/
	/*for 0 to number of columns*/
		/*expand each item in the original array to every 2d array space adjacent to the right, bottom, and bottom right to it*/
/*exit program*/
void ScaleUp2(char Image1[MAXROW][MAXCOL],char Image2[MAXROW][MAXCOL], int Nrows, int Ncols)
{

	/*loop for each element [i][j] of Image 1 starting
		at i=0 and j=0 and let r=0 and c=0 be the
		indeces into elements [r][c] of Image2
	Each element at position [i][j] of Image1
		must be replicated into 4 positions of Image2:
		Image2[r][c], Image2[r][c+1],
		Image2[r+1][c], Image2[r+1][c+1]
	Increase or reset r and c appropriately where needed.*/
	int i, j, r, c;
	r= 0;
	c= 0;
	for (i=0;i<Nrows;i++){
		for(j=0;j<Ncols;j++){
			Image2[r][c]=Image1[i][j];
			Image2[r+1][c]= Image1[i][j];
			Image2[r][c+1]=Image1[i][j];
			Image2[r+1][c+1]=Image1[i][j];
			c=c+2;
		}
		r=r+2;
		c=0;
	}

}/*End of ScaleUp2*/
/************ void RotR(Image1, Image2, nRows,Ncols)**********/
	/*	for each column in Image one */
		/* for each row in Image one */
			/*write to image2 from right to left on the top row */

	/*exit subroutine*/

void RotR( char Image1[MAXROW][MAXCOL], char Image2[MAXROW][MAXCOL], int Nrows, int Ncols)
{

	/*Loop for each column of Image1*/
	/*Copy that column into a row of Image 2*/
		/*by calling CopyColRow*/
	int i, j;	
	for (i=0;i<Ncols;i++){
		for (j=0;j<Nrows;j++){
			Image2[i][Nrows-1-j] = Image1[j][i];
		}
	}

}/*End of RotR*/

/* ***** void ScaleUp2a(Image1,Image2,Nrows,Ncols)***********/
	/* takes in original matrix to be sized up, the matrix we will output it to(Image2), and the Number of rows and columns in the original image */
	/* occupies a single array with all the items in the original matrix*/
	/*for 0 to the number of rows*/
		/*for 0 to the number of columns */
		/* occupy each sequential item of 1D temp[] char array with the items of the matrix*/
	/*Compute the new size of the larger 1d array and fill it up with the proper amount of new characters to occupy it*/
	/*for 0 to twice to the amount of rows*/
		/*for 0 to twice the amount of columns*/
		/*occupy the new larger 2d char array with items fromthe new 1d vector array*/
	/*end procedure*/

void ScaleUp2a(char Image1[MAXROW][MAXCOL], char Image2[MAXROW][MAXCOL],int Nrows,int Ncols)
{
	int i,j,k;
	char temp1[MAXROW*MAXCOL];
	char temp2[(MAXROW*2)*(MAXCOL*2)];
	int x_ratio,y_ratio,x2,y2,Nrows2,Ncols2;
	Nrows2=Nrows*2;
	Ncols2=Ncols*2;

	/*transfers the elements of the original 2d array into a 1d array*/
	k=0;		/*k is the iterator for the 1d array that allows us to occupy it*/
	for(i=0;i<Nrows;i++){
		for(j=0;j<Ncols;j++){
			temp1[k] = Image1[i][j];
			k++;
		}
	}
	/*counts the ratio of scaling. This function implements a 2x expansion*/
	/*Note: added +1 to account for rounding problem*/
	/*Precise conversion from floating to int*/
	x_ratio = (int)((Ncols<<16)/Ncols2)+1;
	y_ratio = (int)((Nrows<<16)/Nrows2)+1;

	/*create the new(larger) vector array*/
	for (i=0;i<(Nrows2);i++) {
		for (j=0;j<Ncols2;j++) {
			x2 = ((j*x_ratio)>>16);
			y2 = ((i*y_ratio)>>16);
			temp2[(i*Ncols2)+j] = temp1[(y2*Ncols)+x2];
		}
	}
	/*copies the data from the extended 1d vector array to the new 2d array*/
	k=0;						/*uses k as a counter for incrementing through the 1d array*/
	for(i=0;i<Nrows*2;i++){
		for(j=0;j<Ncols*2;j++){
			Image2[i][j] = temp2[k];
			k++;
		}
	}

}/*End of ScaleUp2a*/

int main() {

    int	eof;
    int Rsize1, Csize1;	/*beginning image dimensions*/
	char IMchr1[MAXROW][MAXCOL]; /*original */
	char IMchrUP[MAXROW][MAXCOL]; /*image after scaling up*/
	char IMchrRot[MAXROW][MAXCOL]; /*image after rotating*/

	fpin1 = OpenInputFile("Image1.txt"); /*we know the name of the file, so we can hardcode the name in after we open it*/
	if (fpin1 == NULL) {	/*There was a problem in reading the file. Gotta exit the running of this program*/
		fprintf(stdout, "Cannot open input file - Bye\n");
		return(0); 
	}
	printf("File Successfully Opened!\n");
	/* this message indicated a successful start of the program */

	fprintf(stdout, "\n Peter Lebo - Student Number V00748436 \n");
	fprintf(stdout, "\n File = A1csc230.c - Spring 2014 \n");
	fprintf(stdout, "\n CSC 230, Assignment 1, Part 2 \n\n");
	fprintf(stdout,"Starting: \n");

	/*Read in the dimensions for the image*/
	/*Call RdSize with appropriate parameters*/ /*if the end of file was found, return an integer of value 0*/
	int *Rsz = &Rsize1;
	int *Csz = &Csize1;
	eof = RdSize(fpin1, Rsz, Csz);

	while (eof >0) {

		/* read in the image and retrieve the dimensions of the original image*/
		RdImage(fpin1,IMchr1,Rsize1,Csize1);

		/*Print that initial image*/
		fprintf(stdout, "\n \n Initial IMchr1 contains: \n");
		PrImage(IMchr1, Rsize1, Csize1);

		/*Scale image up to twice it's size*/
		/*Call ScaleUp2 and then print out the resulting larger 2d array*/
		ScaleUp2(IMchr1,IMchrUP,Rsize1,Csize1);
		fprintf(stdout, "\n Scaled Up IMchrUP contains: \n");
		PrImage(IMchrUP, Rsize1*2, Csize1*2);

		/*Scale image up to twice the size using the second scaling up algorithm*/
		/*Call ScaleUp2a with the original 2d array, larger 2d array, then the original row and column size*/
		fprintf(stdout, "\n Scaled Up (NEW) IMchrUP contains: \n");
		ScaleUp2a(IMchr1,IMchrUP,Rsize1,Csize1);
		PrImage(IMchrUP, Rsize1*2, Csize1*2);

		/*Rotate original image right by 90 degrees and print*/
		/*Call RotR with original image, the image to be outputted(post rotation) and then the original row and column size*/
		fprintf(stdout, "\n Rotated IMchrRot contains: \n");
		RotR(IMchr1,IMchrRot,Rsize1,Csize1);
		PrImage(IMchrRot, Csize1,Rsize1);

		/*fenceposting by testing for whether or not there exists another matrix to read in and compute
			if there isnt,then the program exits*/
		eof = RdSize(fpin1, Rsz, Csz);
	}

	/* Closure statements*/
	fprintf(stdout, "\nI'm all out of input to read! This program's gonna stop. Thanks for running me!\n");
	fclose(fpin1);  /* close the files */

	return (0);
}/*End of Main*/
