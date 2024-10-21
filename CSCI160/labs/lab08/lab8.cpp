/*  Christopher Nilssen (Jack)
    lab8.cpp
    This program takes two filenames as command line arguments, and copies the first file into
    the second (overwriting the second file if it already existed). 
*/

#include <cstdio>

// copy the contents of the source file into the destination file,
//    one character at a time
// generates error message and returns false if it is unable to open
//    either of the files, 
// otherwise performs the copy and returns true
bool copyFileByChars(const char srcfile[], const char destfile[]);

// takes two command line arguments, 
//    the name of the file to be copied,
// and the name to use for the copy
// e.g.   ./lab8x  originalFile  copiedVersion
int main(int argc, char *argv[])
{
   // if they don't give both filenames,
   //    tell them how to run the program correctly
   if (argc != 3)  {
      printf("correct use is\n   %s infile outfile\n", argv[0]);
   } else if (copyFileByChars(argv[1], argv[2])) {
      printf("Copied %s to %s\n", argv[1], argv[2]);
   } else {
      printf("Unable to perform copy operation\n");
   }
   // end the program
   return 0;
}

// copy the contents of the source file into the destination file,
//    one character at a time
// generates error message and returns false if it is unable to open
//    either of the files, 
// otherwise performs the copy and returns true
bool copyFileByChars(const char srcfile[], const char destfile[])
{
   FILE* fpin;  // tracking position in the input file
   FILE* fpout; // tracking position in the output file

   fpin= fopen(srcfile, "r"); //attempt to open input file, set to read

   if (fpin == NULL) {
      // print an error message and return false, 
      printf("We couldn't copy because we couldn't open the input file\n");
      return false;
   }

   fpout = fopen(destfile, "w"); //attempt to open output file, set to write

   if (fpout == NULL) {
      // print an error message, close the input file, and return false, 
      printf("We couldn't copy because we couldn't open the output file\n");
   }
   
   char currCh;
   do { //loop to end of input file, copying chars to output  
      currCh = getc(fpin);  // read a char from fpin, put it in currCh
      if (!feof(fpin)) {
         fprintf(fpout, "%c", currCh);  // write it into fpout
      }
   } while (!feof(fpin));      

   fclose(fpout); //close the output file
   return true;
}
