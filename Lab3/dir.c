
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
 
int main(int argc, char *argv[])
{
        DIR             *dip;
        struct dirent   *dit; //ino_t  d_ino (file serial number)
			     //char   d_name[]    name of entry
        int             i = 0;
 
        // check to see if user entered the argumants OPTIONS and //directory name
        if (argc < 3)
        {
                printf("Command missing args\n");
                return 0;
        }
 
        /* DIR *opendir(const char *name);
         *
         * Open a directory stream to argv[2] and make sure
         * it's a readable and valid (directory) */
        if ((dip = opendir(argv[2])) == NULL)
        {
                perror("opendir");
                return 0;
        }
 
        printf("Directory stream is now open\n");
 
        /*  struct dirent *readdir(DIR *dir);
         *
         * Read in the files from argv[2] and print */
        while ((dit = readdir(dip)) != NULL)
        {
                i++;
                printf("\n%s", dit->d_name);
        }
 
        printf("\n\nreaddir() found a total of %i files\n", i);
 
        /* int closedir(DIR *dir);
         *
         * Close the stream to argv[1]. And check for errors. */
        if (closedir(dip) == -1)
        {
                perror("closedir");
                return 0;
        }
 
        printf("\nDirectory stream is now closed\n");
        return 1;
} 
