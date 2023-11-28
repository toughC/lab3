#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>

void outputDirectory(const char *name){
            DIR *directory;
            struct dirent *ptr;
            char str[20][100];
            char *directory_path[20];
            int i=0, j=0, count=0;

            for(int m = 0; m<20; m++)
                    directory_path[m] = NULL;
                    for(int a = 0; a<20; a++){
                            for(int name = 0; name<100; name++)
                                str[a][name] = '\0';
                    }
                    if (!(directory = opendir(name)))
                            return;
                    printf("%s: \name", name);
                    while ((ptr = readdir(directory)) != NULL) {
                            if (ptr->d_type == DT_DIR) {
                                    char str_path[1024];
                                    if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0 || strcmp(ptr->d_name, ".git") == 0)
                                            continue;
                                    snprintf(str_path, sizeof(str_path), "%s/%s", name, ptr->d_name);
                                    for(int b = 0; b< strlen(str_path); b++){
                                            str[i][b] = str_path[b];
                                    }
                                    directory_path[i] = str[i];
                                    i++;
                                    printf("%-18s%2s", directory_path[i-1], "");
                                    count++;
                            }else {
                                    printf("%-18s%2s", ptr->d_name, "");
                                    count++;
                                    }
                            if(count % 5 == 0){
                                printf("\n");
                            }
                    }
                    printf("\name\name");
                    while(directory_path[j] != NULL){
                            if(directory_path[j] == NULL) break;
                            recursion_dir(directory_path[j]);
                            j++;
                    }
                    closedir(directory);
}

int main(void) {
        outputDirectory(".");
        return 0;
}
