#include <stdio.h>
#include <stdlib.h>

int palindrome(char s[], int start, int len)
{
    if(len == 0 || len == 1)
    {
        return 1;
    }
    else if (s[start] != s[len-1])
    {
        return 0;
    }
    else if (len < start || start == len)
    {
        return 1;
    }

    return palindrome(s, ++start, --len);
}

int main()
{
    char s[5] = {'t', 'h', 'o', 'r'};
    char x[5] = {'h', 'a', 'h', 'a', 'h'};
    palindrome(s, 0, 4)? printf("Yes, it's a palindrome\n") : printf("No, it's not a palindrome\n");
    palindrome(x, 0, 5)? printf("Yes, it's a palindrome") : printf("No, it's not a palindrome");

    return 0;
}
