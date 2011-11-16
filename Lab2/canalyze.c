#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
//#include <nameList.h>

int counter=0;

struct entry {
  struct entry *next;
  char *word;
  int count;
};
typedef struct entry *wordlist;

wordlist register_word(wordlist words, char *word){

	wordlist new_el;
	wordlist tmp = words;

	while (words!=NULL){
		if(strcmp(words->word, word)==0){
        	++(words->count);
			return tmp;
        }
		words = words->next;
 	}

	new_el = malloc(sizeof(struct entry));
	new_el->word = malloc(strlen(word)+1);
	strcpy(new_el->word,word);
	(*new_el).count=1;
	(*new_el).next=tmp;

	if(strlen(word)>0){
		++counter;
	}

	return new_el;
}

void wordlist_foreach(wordlist words, void (*handler)(struct entry *word)){
	wordlist tbp = words;
	while(tbp!=NULL){
		handler(tbp);
		tbp = tbp->next;
	}
}

void memFree(wordlist tbf){
	 while(tbf!=NULL){
		 wordlist next = tbf->next;
		 free(tbf->word);
		 free(tbf);
		 tbf = next;
	 }
}

void printer(wordlist word){
	printf("%s: %d\n",(*word).word, (*word).count);
}

void listSort(wordlist words){
	wordlist current,ptr;
	int temp, temp2;
	current = words;
	for(; current->next != NULL; current = current->next){
		for(ptr = current->next; ptr != NULL; ptr = ptr->next){
			if(strcmp((current->word),(ptr->word))>0){
				temp = current->word;
				temp2 = current->count;
				current->word = ptr->word;
				current->count = ptr->count;
				ptr->word = temp;
				ptr->count = temp2;
			}
		}
	}
}

int main(int argc, char **argv) {

	 char* input = (char*)malloc(100*sizeof(char));
	 int i,j;
	 char c;
	 wordlist list = NULL;

	 FILE *pFile;
	 for(j=1;j<argc;j++){
	 pFile=fopen(argv[j],"r");
	 c = fgetc(pFile);

	 while(c != EOF){
		i=0;
		 while(isalpha(c) || c=='_' || isdigit(c) || c=='"'){
			 input[i] = c;
			 i++;
			 c = fgetc(pFile);
		 }
		 if(i!=0 && !(isdigit(input[0])) && input[0]!='"'&& input[i-1]!='"'){
			if((strcmp(input,"int"))&&(strcmp(input,"if"))&&(strcmp(input,"else"))&&(strcmp(input,"while"))&&(strcmp(input,"return"))&&(strcmp(input,"char"))){
				list = register_word(list, input);
			}
		 }
		 input = (char*)malloc(100*sizeof(char));
		 c = fgetc(pFile);
	 }
	 fclose (pFile);
	}
	 listSort(list);
	
	 wordlist_foreach(list,printer);

	 memFree(list);


	return 0;
}
