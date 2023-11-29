#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <dirent.h>
#include <string.h>

int sumSize = 0;

char *userId(uid_t userId)
{
    return getpwuid(userId)->pw_name;
}

char *groupId(gid_t groupId)
{
    return getgrgid(groupId)->gr_name;
}

char *sTime(time_t *pTime)
{
    return ctime(pTime);
}

void fileList(char *file)
{ 
    struct stat tt;
    stat(file, &tt);
    char mod[20];

    strcpy(mod,"----------");
    if ((tt.st_mode & S_IFMT) == S_IFDIR) {
        mod[0]='d';
    }
    
    if (tt.st_mode & S_IRUSR) mod[1] = 'r';
    if (tt.st_mode & S_IWUSR) mod[2] = 'w';
    if (tt.st_mode & S_IXUSR) mod[3] = 'x';

    if (tt.st_mode & S_IRGRP) mod[4] = 'r';
    if (tt.st_mode & S_IWGRP) mod[5] = 'w';
    if (tt.st_mode & S_IXGRP) mod[6] = 'x';

    if (tt.st_mode & S_IROTH) mod[7] = 'r';
    if (tt.st_mode & S_IWOTH) mod[8] = 'w';
    if (tt.st_mode & S_IXOTH) mod[9] = 'x';

    printf("%s ", mod);
    printf("%3ld ", tt.st_nlink);
    printf("%s ", userId(tt.st_uid));
    printf("%s ", groupId(tt.st_gid));
    printf("%ld ", tt.st_size);
    sumSize += tt.st_size;
    
    char *p = sTime(&tt.st_ctime)+4;
    for (int i = 0; *p != '\n'; i++) {
        printf("%c", *p);
        p++;
    }
    printf(" ");
    if(mod[0] == 'd') {
        printf("\033[1;34m%s\033[0m\n", file);
    } else if (mod[9] == 'x'){
        printf("\033[1;32m%s\033[0m\n", file);
    } else {
        printf("%s\n", file);
    }
}

void ls(char *dir)
{
    struct dirent *dirPoint;
    DIR *dp = opendir(dir);

    while (dirPoint = readdir(dp)) {
        fileList(dirPoint -> d_name);
    }

    closedir(dp);
}

int main(int argc, char *argv[])
{
    printf("total %d\n", sumSize / 1024);
    
    if (argc < 2)
    {
        ls(".");
    }
    else
    {
        ++argv;
        ls(*argv);
    }

    return 0;
}
