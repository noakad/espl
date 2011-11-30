void ahalan();

int main(int arg, char **argv) {
ahalan();
return 0;
}

int length(char *s) {
char *t = s;
while(*t) ++t;
return t-s;
}
