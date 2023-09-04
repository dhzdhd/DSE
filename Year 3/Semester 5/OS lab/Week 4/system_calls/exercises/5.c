#include <stdio.h>
#include <dirent.h>

int main(void)
{
    struct dirent *de;      // Pointer for directory entry
    DIR *dr = opendir("."); // opendir() returns a pointer of DIR type.

    if (dr == NULL)
    { // opendir returns NULL if couldn't open directory
        printf("Could not open current directory");
        return 0;
    }

    while ((de = readdir(dr)) != NULL)
        printf("%s\n", de->d_name);

    closedir(dr);
    return 0;
}

// .
// ..
// 1.c
// 2.c
// 3.c
// 4.c
// 5.c
// main
