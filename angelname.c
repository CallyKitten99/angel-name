\#define NAMEBUFSZ 128

tolower(c);
strcmpi(a, b);
get_names();
get_parent_name();
char  get_char(str, index);
char  first_vowel(str);
char  last_consonant(str);
is_vowel(c);
get_yes_no();
should_exit();

char *ws;

char *line;
int len, alen;
int numNames;

char namebuf[NAMEBUFSZ];
char angel[16];

char *names[3];

main()
{
    ws = " \t\r\n";
    line = 0;
    len  = 0;
    numNames = 0;
    names[0] = names[1] = names[2] = 0;

    for (;;)
    {
        for (;;)
        {
            get_names();
            if (should_exit()) goto L_Exit;
            if (numNames > 1) break;
        }

        if (numNames == 2) get_parent_name();

        alen = 0;
        angel[alen++] = toupper(get_char(names[2], 0));
        angel[alen++] = tolower(get_char(names[2], 1));
        angel[alen++] = tolower(first_vowel(names[0]));
        angel[alen++] = tolower(get_char(names[1], 2));
        angel[alen++] = tolower(last_consonant(names[2]));
        angel[alen++] = 'i';
        angel[alen++] = 'e';
        angel[alen++] = 'l';
        angel[alen++] = '\0';
        
        printf("Your angel name is \"%s\".\n", angel);
        if (!get_yes_no()) break;
    }

L_Exit:
    printf("Exiting.\n");
    return 0;
}

get_names()
{
    int c;
    int text;

    for (;;)
    {
        names[0] = names[1] = names[2] = 0;
        len      = 0;
        numNames = 0;
        text     = 0;

        printf("Enter 'Exit' to exit.\nPlease enter your full name: ");

        while ( (c = getchar()) != '\n' && len < NAMEBUFSZ-2 )
        {
            if (text)
            {
                if (c == ' ' || c == '\t' || c == '\r')
                {
                    text = 0;
                    namebuf[len++] = '\0';
                }
                else namebuf[len++] = c;
            }
            else
            {
                if (c == ' ' || c == '\t' || c == '\r') continue;

                numNames = numNames >= 2 ? 3 : numNames + 1;
                names[numNames - 1] = namebuf + len;

                namebuf[len++] = c;

                text = 1;
            }
        }
        namebuf[len++] = '\0';

        if (numNames) break;
    }
}

should_exit()
{
    if (toupper(namebuf[0]) == 'E' &&
        toupper(namebuf[1]) == 'X' &&
        toupper(namebuf[2]) == 'I' &&
        toupper(namebuf[3]) == 'T')
    {
        return 1;
    }

    if (toupper(namebuf[0]) == 'Q' &&
        toupper(namebuf[1]) == 'U' &&
        toupper(namebuf[2]) == 'I' &&
        toupper(namebuf[3]) == 'T')
    {
        return 1;
    }

    if (toupper(namebuf[0]) == 'S' &&
        toupper(namebuf[1]) == 'T' &&
        toupper(namebuf[2]) == 'O' &&
        toupper(namebuf[3]) == 'P')
    {
        return 1;
    }

    return 0;
}

get_parent_name()
{
    int c;
    int text;
    
    names[2] = names[1];
    names[1] = 0;
    text = 0;
    
    for (;;)
    {
        printf("Please enter a parent's name: ");

        while ( (c = getchar()) != '\n' && len < NAMEBUFSZ-2 )
        {
            if (text)
            {
                if (c == ' ' || c == '\t' || c == '\r')
                {
                    namebuf[len++] = '\0';
                    while (getchar() != '\n');
                    break;
                }
                else namebuf[len++] = c;
            }
            else
            {
                if (c == ' ' || c == '\t' || c == '\r') continue;

                names[1] = namebuf+len;

                namebuf[len++] = c;

                text = 1;
            }
        }

        if (names[1]) break;
    }
}

strlen(str)
    char *str;
{
    char *p;

    for (p = str; *p; ++p);

    return p - str;
}

toupper(c)
{
    if (c >= 'a' && c <= 'z')
    {
        return c+'A'-'a';
    }
    else
    {
        return c;
    }
}

tolower(c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c+'a'-'A';
    }
    else
    {
        return c;
    }
}

strcmpi(a, b)
    char *a, *b;
{
    int cmp;
    char a_, b_;
    
    for (;; ++a, ++b) {
        a_ = toupper(*a);
        b_ = toupper(*b);

        if (!a_) {
            if (!b_) return 0;
            return -1;
        } else if (!b_) return 1;
        
        cmp = b_ - a_;
        if (cmp) return cmp;
    }
}

char get_char(str, index)
    char *str;
    int index;
{
    int nlen;

    nlen = strlen(str);
    if (!nlen) return '\0';
    
    if (index < 0) return str[nlen - (abs(index) % nlen)];
    else           return str[index % nlen];
}

char first_vowel(str)
    char *str;
{
    for (; *str; ++str)
    {
        if (is_vowel(*str)) return *str;
    }
    
    return '\0';
}

is_vowel(c)
    char c;
{
    int i;

    for (i = 0; i < 10; ++i)
    {
        if (c == "AaEeIiOoUu"[i]) return 1;
    }
    
    return 0;
}

char last_consonant(str)
    char *str;
{
    char *cur;

    cur = str;
    if (!*cur) return '\0';
    
    do { ++cur; } while (*cur);
    --cur;
    
    while (cur >= str && is_vowel(*cur)) --cur;
    
    if (cur < str) return '\0';
    return *cur;
}

get_yes_no()
{
    int c;

    for (;;)
    {
L_TryAgain:
        printf("Try another name? (Yes/No): ");

        for (;;)
        {
            c = getchar();
            if (c == '\n') break;
            if (c == ' ' || c == '\t' || c == '\r') continue;

            switch (c)
            {
            case 'Y': case 'y':
                c = getchar();

                if (c == 'E' || c == 'e') {
                    if ( (c = getchar()) == 'S' || c == 's' ) {
                        while (getchar() != '\n');
                        return 1;
                    }
                    if (c == '\n') goto L_TryAgain;
                }
                if (c == '\n') goto L_TryAgain;

                while (getchar() != '\n');
                goto L_TryAgain;

            case 'N': case 'n':
                c = getchar();

                if (c == 'O' || c == 'o') {
                    while (getchar() != '\n');
                    return 0;
                }
                if (c == '\n') goto L_TryAgain;

                while (getchar() != '\n');
                goto L_TryAgain;

            default:
                while (getchar() != '\n');
                goto L_TryAgain;
            }
        }
    }
}
