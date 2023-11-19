#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//Дана строка символов до точки. Записать новую строку из слов задан-ной, содержащих букву «М».
int main(void) {

    char pstr[50];
    char *str;
    str = (char*)malloc(50);
    char sep[1] = ".";
    int i, c = 0;
    char temp;

    printf("Enter some text: ");
    fgets(str, 50, stdin);
    fflush(stdin);

    for(i = 0; i < 50; i++)
    {
        if(str[i] != '.')
        {
            pstr[i] = str[i];
            c++;
        }
        else
        {
            pstr[i] = str[i];
            break;
        }
    }

    free(str);

    c = 0;
    for(i = 0; i < 50; i++)
    {
        if(pstr[i] == ' ' || pstr[i] == '.')
        {
            temp = pstr[i-1];
            pstr[i-1] = pstr[c];
            pstr[c] = temp;
            c = i+1;
        }
    }

    puts(pstr);

}
