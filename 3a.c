#include<stdio.h>
int main(){
    int users,files;
    printf("Enter the number of users:\n");
    scanf("%d",&users);
    char uname[10][20];
    char fname[10][10][20];
    for(int i=0;i<users;i++){
        printf("Enter the user name\n");
        scanf("%s",uname[i]);
        printf("Enter the number of files:\n");
        scanf("%d",&files);
        for(int j=0;j<files;j++){
            printf("Enter the %d file name :\n",j+1);
            scanf("%s",fname[i][j]);
        }
    }
    printf("directory structure:\n");
    for(int i=0;i<users;i++){
        printf("\n%s\n",uname[i]);
        for(int j=0;j<files;j++){
            if(fname[i][j][0]!='\0'){
            printf("--  %s\n",fname[i][j]);
        }}
    }
}
