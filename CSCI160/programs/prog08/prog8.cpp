/* Christopher Nilssen (Jack)
   prog8.cpp
   This program takes a filename as a command line arguments, and checks for bracket completion
   { } while counting the number of lines, and reports the results (too many, too few, just
   right) to the user. 
*/

#include <cstdio>

// check and count bracket pairs { } and count the number of lines inside input file
// if bracket count negative, display line number and notify user 
// if bracket count greater than 0 at EOF, report count of unclosed brackets
bool countBracketsLines(const char srcfile[]);

// takes one command line argument, the name of the file to be read,
int main(int argc, char *argv[])
{
   // if they don't give a single filename,
   //    tell them how to run the program correctly
   if (argc != 2)  {
      printf("correct use is\n   %s infile\n", argv[0]);
   } else if(countBracketsLines(argv[1])) { //run the check function
      printf("\n%s closed.\n", argv[1]);
   } else { //general fault check
      printf("Unable to perform count operation\n");
   }
   // end the program
   return 0;
}

// check and count bracket pairs { } and count the number of lines inside input file
// if bracket count negative, display line number and notify user 
// if bracket count greater than 0 at EOF, report count of unclosed brackets
bool countBracketsLines(const char srcfile[])
{
   int bracketCount = 0; // tracks brackets
   int lineNumber = 0; // tracks lines

   FILE* fpin;  // tracking position in the input file

   fpin= fopen(srcfile, "r"); //attempt to open input file, set to read

   if (fpin == NULL) {
      // print an error message and return false, 
      printf("We couldn't read because we couldn't open the input file\n");
      return false;
   } else {
      printf("%s opened.\n\n", srcfile); //report file opened
   }

   char currCh; // container for currently read char from input
   do { //loop to end of input file, counting bracket pairs and line numbers
      currCh = getc(fpin);  // read a char from fpin, put it in currCh
      if (!feof(fpin)) {
         switch(currCh) { //check current character and either count or continue
            case '{': //check for open bracket and increase count if found
               bracketCount++;
               break;
            case '}': //check for closed bracket and increase count if found
               bracketCount--;
               break;
            case '\n': //check for new line, increase count if found, check closing brackets
               lineNumber++;
               if(bracketCount<0){ // too many closing brackets, display the line number
                  printf("Too many closing brackets on line %i\n", lineNumber);
               }
               break;
         }
      }
   } while (!feof(fpin));      

   fclose(fpin); //close the input file

   if(bracketCount>0){ //display how many brackets were left unclosed, if any
      switch(bracketCount){ //grammar correction
         case 1:
            printf("%i bracket was left unclosed in the file.\n", bracketCount);
            break;
         default:
            printf("%i brackets were left unclosed in the file.\n", bracketCount);
            break;
      }
   } else if(bracketCount==0){ //no errors
      printf("All (if any) brackets in %s were correctly paired.\n", srcfile);
   }
   return true;
}
