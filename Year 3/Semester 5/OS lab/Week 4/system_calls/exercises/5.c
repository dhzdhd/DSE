#include <stdio.h>
#include <dirent.h>

int main(void)
{
    struct dirent *de;      // Directory entry
    DIR *dr = opendir("."); // opendir() returns a pointer of DIR type.

    if (dr == NULL)
    {
        // NULL is returned if dir failed to open
        printf("Could not open current directory");
        return 0;
    }

    while ((de = readdir(dr)) != NULL) // Read every file object
        printf("%s\n", de->d_name);

    closedir(dr); // Close opened dir
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
