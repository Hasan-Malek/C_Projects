/*
    Creating a HTML String Parser in C
    by : HM
    GitHub: https://github.com/Hasan-Malek
    Linkedin: https://linkedin.com/in/hasan-malek-125036297
*/

#include <stdio.h>
#include <string.h>

void parser(char *str)
{

    int in = 0, index = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '<')
        {
            in = 1;
            continue;
        }

        else if(str[i] == '>')
        {
            in = 0;
            continue;
        }
        
        if (in == 0)
        {
            str[index] = str[i];
            index++;
        }
    }

    str[index] = '\0';

    // Removing the Trailling Spaces
    while (str[0] == ' ')
    {
        for (int i = 0; i < strlen(str); i++)
        {
            str[i] = str[i + 1];
        }
        
    }
    
    while (str[strlen(str) - 1] == ' ')
    {
        str[strlen(str) - 1] = '\0';
    }
    
    

}

int main()
{

    char str[] = "<h1>   Hello from Hasan  </h1>";

    printf("The String is : ~%s~ \n\n", str);

    parser(str);

    printf("The Parsed String is : ~%s~ \n\n", str);

    return 0;
}
