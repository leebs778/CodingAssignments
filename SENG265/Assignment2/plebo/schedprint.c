#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 256
/*
 * If newline at end of string, then remove it.
 */
void chomp(char *line) {
    int len;

    if (line == NULL) {
        return;
    }

    len = strlen(line);
    if (line[len-1] == '\n') {
        line[len-1] = '\0';
    }

    len = strlen(line);
    if (line[len-1] == '\r') {
        line[len-1] = '\0';
    }
}

int main(int argc, char *argv[])
{

    int from_y = 0, from_m = 0, from_d = 0;
    int to_y = 0, to_m = 0, to_d = 0;
    char *filename = NULL;
    int i; 
	//populates start, end, and filename variables
    for (i = 0; i < argc; i++) {
        if (strncmp(argv[i], "--from=", 7) == 0) {
            sscanf(argv[i], "--from=%d/%d/%d", &from_d, &from_m, &from_y);
        } else if (strncmp(argv[i], "--to=", 5) == 0) {
            sscanf(argv[i], "--to=%d/%d/%d", &to_d, &to_m, &to_y);
        } else if (strncmp(argv[i], "--file=", 7) == 0) {
            filename = argv[i]+7;
        }
    }
	//block of code to account for call with no arguments
    if (from_y == 0 || to_y == 0 || filename == NULL) {
        fprintf(stderr, 
            "usage: %s --from=dd/mm/yyyy --to=dd/mm/yyyy --file=icsfile\n",
            argv[0]);
        exit(1);
    }

    /* Starting calling your own code from this point. */
    /* --->
 		Ideas for implementation:
		) open at required date point, close by end of date.
		) Get Data field by data field
		) Print out results in a stomachable way
    */
    struct dtstart{
        char *DTSTART;
    }
  //  char *DTSTART;
    char *DTEND;
    char *timeStart;
    char *timeEnd;
    char *LOCATION;
    char *SUMMARY;
    char *Freq;
    char *untilDate;
    char *untilTime;


    FILE *inputFile;
    inputFile = fopen(filename, "r");
    if (inputFile == NULL){
	   printf("\n File opening failed, my friend. Pack it up and call it a day\n");
	   return 1;
    }else{
        char line[80];
        fgets(line, 80, inputFile);
        if (strncmp(line, "BEGIN:VCALENDAR", 15) == 0){ // if we have a valid calendar file, proceed until we hit the end
           fgets(line, 80, inputFile);
           while (strncmp(line, "END:VCALENDAR", 13) != 0){  
                fgets(line, 80, inputFile);                 //extra fgets to get rid of the event beginning marker   
                while (strncmp(line, "END:VEVENT", 10) != 0){   //Now, iterate event by event
                    printf("%s", line);
                    char *token;
                    token = strtok(line, ":");


                    if (strncmp(line, "DTSTART",7) == 0){           //acquire DTSTART   X
                        dtstartDTSTART = strtok(NULL,":T");
                        timeStart = strtok(NULL,":T");
                    }
                    if (strncmp(line, "DTEND",5) == 0){             //acquire DTEND X
                        DTEND = strtok(NULL, ":T");
                        timeEnd = strtok(NULL,":T");
                    }
                    if (strncmp(line, "RRULE:", 5) == 0){           //acquire RR rule X
                        strtok(NULL, "=");
                        Freq = strtok(NULL, ";");
                        strtok(NULL, "=");
                        untilDate = strtok(NULL, "T");
                        untilTime = strtok(NULL, "");
                    }
                    if (strncmp(line, "LOCATION", 8) == 0){         //acquire LOCATION X
                        LOCATION = strtok(NULL, "");
                    }
                    if (strncmp(line, "SUMMARY",5) == 0){           //acquire SUMMARY x
                        SUMMARY = strtok(NULL, "");
                    }

                    fgets(line, 80, inputFile);
                }
                //print event report





                if (Freq != NULL){
                    char buffer[SIZE];
                    struct tm * date;
                    /*
                    strftime (buffer, SIZE, "%B %d, %y (%a)", *date);
                    fputs(buffer, stdout);
                    printf("\n----------------------\n");
                    strftime (buffer, SIZE, "")
                    */

                



                }else{

                

                }
                




            fgets(line, 80, inputFile);
           }
           printf("\nThat's the end of the file\n");
        }
    }
    fclose(inputFile);	
    exit(0);
}