#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#define BUFSIZE 512

char string1[BUFSIZE] = "Good afternoon, good evening, and good night.";
char string2[BUFSIZE] = "Hello, World!";
char string3[BUFSIZE] = "hope is good thing, maybe the best of things. And no good thing ever dies.";

int main(){
    time_t second_a, second_b;
    char enter[20];
    char input1[BUFSIZE];
    char input2[BUFSIZE];
    char input3[BUFSIZE];
    int cnt=0;
    int n;
    int filedes;
    int fd;
    int sum = 0;
    double total = 0;


    printf("★ 타자 연습 프로그램 ★\n");
    printf("엔터 키를 눌러주세요.");
    fgets(enter,20,stdin);
    second_a = time(NULL);
    fprintf(stderr, "%s\n", string1);
    fgets(input1,50,stdin);
    fprintf(stderr,"%s\n", string2);
    fgets(input2,18,stdin);
    fprintf(stderr,"%s\n", string3);fgets(input3, 75, stdin); second_b = time(NULL);

    total = difftime(second_b, second_a);
    sum = strlen(input1) + strlen(input2) + strlen(input3);                                                                                                                
    sum /= total/60;
    for(int i = 0; i < strlen(string1); i++) if(input1[i] != string1[i]) cnt++;
    for(int i = 0; i < strlen(string2); i++) if(input2[i] != string2[i]) cnt++;
    for(int i = 0; i < strlen(string3); i++) if(input3[i] != string3[i]) cnt++;

    printf("잘못 타이핑한 횟수: %d\n",cnt);
    printf("평균 분당 타자수: %d\n", sum);
    printf("총 %2.f초 걸렸습니다.\n", total);
    exit(0);
    return 0;
}                                          
