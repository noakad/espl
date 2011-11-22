/* NAME
   bfix - apply differences to a binary file

SYNOPSIS
   bfix [OPTIONS] file differences

DESCRIPTION
   bfix applies the differences (second argument) as printed
   by bcmp(3) to the file (the first argument).
   Before applying each difference, bfix verifies that the old value
   of the byte in the file is the same as the old value in the
   difference line. If option -r is specified, the differences are
   reversed: the new value must be changed to the old value.

OPTIONS
   -h  print a summary of options and exit
   -r  reverse the differences
   -m  print a message each time a change is applied

SEE ALSO
    bcmp(3)
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "diff.h"


int main (int argc , char** argv)
{

	int i,c1,f;
	FILE* tbchanged;
	FILE* diffs;
	char* buff;
	struct diff* diff;

	tbchanged = fopen(argv[1],"+r");//opening the file we want to cange the bytes in
	if(!tbchanged){
	  printf("ERROR: faid to open tbchanged \n");
	  return 1;
	}
	diffs = fopen(argv[2],"r");//openingthe list of differences
	if(!diffs){
	  printf("ERROR: faid to open diffs \n");
	  return 1;
	}

	c1 = fgetc(diffs);
	while(c1 != EOF){
	  i = 1;
	  while((c1)!= 0){//read one line
	    buff[i] = c1;
	    c1 = fgetc(diffs);
	    ++i;
	  }
	  parsediff(buff, diff);
	  fseek(tbchanged, (long)(diff->offset), SEEK_SET);
	  if(fgetc(tbchanged)==(diff->old)){
	    if((fputc(diff->new, tbchanged))==(diff->new)){
	   //if((fwrite(diff->new, 1, 1, tbchanged))==1){
	      fputdiff(stdout, diff);
	    }
	  }
	  else{
	    printf("WRONG INFORMATION IN DIFFS\n");
	  }
	  
	  c1 = fgetc(diffs);
	}//while
  fclose(tbchanged);
  fclose(diffs);
  return 0;
}
   




//parsediff("byte 33 -174 +230", &diff);
//לא משנה מה "פארסדיף" מחזירה לי - ברגע שהשתמשתי בה, זה יוצר לי "סטראקט" -דיף ומאתחל לי את השדות להיות מה שביקשתי בקריאה לפונקצי זו. ככה שא"כ אני יכולה להשתמש ב"דיף" הזה ולפי השדות שלו לעשות את השינויים הנדרשים.עליי לעשות לולאה(שמשתמשת ב3 פונקציות ארבע פעמים) ובלולאה זו אני בעצם מבצעת את השינויים הנדרשים. לא לשכוח שעליי לבדוק שבאמת במקום שאני רוצה לבצע שינוי נמצא באמת הביית שציפיתי שיהיה (זה שמופיע אחרי המינוס) - ב"דיף" נמצא בשדה שנקרא אולד
//if(c1!=c2){
	//	printf("byte %lu -%u +%u \n", i, c1,c2);
	
	//c1 = fgetc(file1);
	//c2 = fgetc(file2);
	//++i;