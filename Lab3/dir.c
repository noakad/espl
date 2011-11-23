
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
 
int main(int argc, char *argv[])
{
        DIR             *dip;
        struct dirent   *dit; //ino_t  d_ino (file serial number)
			     //char   d_name[]    name of entry
        int i = 0;
	int sz;
	char *buf;
	size_t size;
	FILE* fp;
 
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
		printf("directory name is not specified - printing names of current dir\n");
		getcwd(buf, size);
		dip = opendir(argv[2]);
		printFiles(dip, dit, i);
        }
 
        /*  struct dirent *readdir(DIR *dir);
         *
         * Read in the files from argv[2] and print */
	
	printFiles(dip, dit, i);
 
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




printFiles(DIR  *dip, struct dirent *dit, int i){
	printf("Directory stream is now open\n");
	while ((dit = readdir(dip)) != NULL)
        {
                i++;
		if(strcmp(argv[1],"l") == 0){
		  fp = fopen(dit->d_name,r);
		  fseek(fp, 0L, SEEK_END);
		  sz = ftell(fp);
		  fseek(fp, 0L, SEEK_SET);
		  //i think its not a very good solution, because if someone is now reading or writing to this file' im changing the location of the poiner!
		}
                printf("\n%s", dit->d_name);
        }
        printf("\n\nreaddir() found a total of %i files\n", i);
}