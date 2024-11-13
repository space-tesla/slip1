/*Q.1) Take multiple files as Command Line Arguments and print their inode numbers and file types */


#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    struct stat fileStat;

    for (int i = 1; i < argc; i++) {
        if (stat(argv[i], &fileStat) == 0) {
            printf("File: %s\n", argv[i]);
            printf("Inode number: %d\n", (int)fileStat.st_ino);  // Changed %ld to %d and casted to int

            if (S_ISDIR(fileStat.st_mode)) {
                printf("File Type: Directory\n");
            } else if (S_ISREG(fileStat.st_mode)) {
                printf("File Type: Regular File\n");
            } else {
                printf("File Type: Other\n");
            }
        } else {
            perror("stat failed");
        }
        printf("---------------------------------\n");
    }

    return 0;
}


 gcc A.c -o A
 ./A   A.c
/*Output:
File: file1.txt
Inode number: 123456
File Type: Regular File
---------------------------------
File: directory1
Inode number: 654321
File Type: Directory
---------------------------------
File: link_to_file
Inode number: 112233
File Type: Symbolic Link
---------------------------------*/
