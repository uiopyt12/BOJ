#include <stdio.h>


int main()
{
    int t;
    scanf("%d", &t);

    
    for(int i=0; i<t; i++){
        char OX[81] = {0,};
        scanf("%s", OX);

        int streak=0;
        int sum=0;
        int index=-1;
        while(OX[++index]){
            if (OX[index] == 'O'){
                streak++;
                sum+=streak;   
            }
            else {
                streak=0;
            }
        }
        printf("%d\n", sum);


    }
    
}