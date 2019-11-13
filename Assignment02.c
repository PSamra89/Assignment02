#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define CHECK(P) printf("%s...%s\n", (P) ? "passed" : "FAILED", #P)


/* Returns 1 if the string s contains a digit; otherwise, returns 0 */
int str_has_digit(const char s[]){
    size_t i = 0;
    for(; s[i] != '\0'; i++) {
        if(isdigit(s[i])) {
            return 1;
        }
    }
    return 0;
}
/* -replaces all occurrences of the character specified by old c in the string s
 * by the character specified by newc
 * */
size_t str_replace_all(char s[], int oldc, int newc){

    size_t replacements = 0;
    size_t i = 0;

    for(; s[i] != '\0'; i++){
        if(s[i] == oldc){
            s[i] = newc;
            replacements++;
        }
    }

    return replacements;

}

int str_replace_last(char s[], int oldc, int newc){

    size_t index = -1;
    size_t i = 0;

    for(; s[i] != '\0'; i++){
        if(s[i] == oldc){
            index = i;
        }
    }
    if((int)index != -1) {
        s[index] = newc;
        return 1;
    }
    return 0;
}

int str_equal(const char s[], const char t[]){

    size_t i = 0;
    for(; s[i] != '\0' && t[i] != '\0'; i++){
        if(s[i] != t[i]){
            return 0;
        }
    }
    if (s[i] == '\0' && t[i] == '\0') {
        return 1;
    }
    return 0;
}


int main(void) {
    char a[] = "abcdefg";
    char b[] = "abcdefg";
    char c[] = "hello world";
   /* char d[] = "vancouver";*/
    char e[] = "pavans1";

    CHECK(str_has_digit(a) == 0 );
    CHECK(str_has_digit(e)== 1);
    CHECK(str_replace_all(c,'l','x')==3);
    CHECK(strcmp(c,"hexxo worxd") == 0);

    CHECK(str_replace_all(c,'l','x')==0);
    CHECK(strcmp(c,"hexxo worxd") == 0);


    CHECK(str_replace_last(e,'a','e') == 1);
    CHECK(strcmp(e,"pavens1") == 0);
    CHECK(str_replace_last(e,'a','e') == 1);
    CHECK(strcmp(e,"pevens1") == 0);
    CHECK(str_replace_last(e,'a','e') == 0);
    CHECK(strcmp(e,"pevens1") == 0);
    CHECK(str_equal(a,b) == 1 );
    CHECK(str_equal(a,a) == 1 );
    CHECK(str_equal(a,e) == 0 );
}

