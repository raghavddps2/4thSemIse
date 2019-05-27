/*

    @Author: Raghav Maheshwari.
    @Date: 26th May, 2019
    @Topic: Horspool ALgorithm

*/

#include<stdio.h>
#include<string.h>

int table[128]; //This defines the shift table, because it contains all the possible chatracters.
void shiftTable(char *searchStr){
    //This defines the shift table values for all the characters.
    for(int i=0;i<128;i++){
        table[i] = strlen(searchStr);
    }

    for(int i=0;i<strlen(searchStr)-1;i++){
        table[searchStr[i]] = strlen(searchStr)-i-1;
        //This defines the value for table[searchStr[i]],
        //consider, we have i as 0, then searchStr[0] will be suppose R, then  
        //so, will convert R to ASCII code, and then store the value in table[code of R] = strlen(searchStr)-i-1
    }
}

int horspool(char *str,char *searchStr){
    shiftTable(searchStr);
    //As we strat matching from the last charcacter, so we will assign i as
    int i = strlen(searchStr)-1;
    
    int searchStrlen =  strlen(searchStr);
    //we will check till the i value becomes equal to the original string last index.
    while(i<strlen(str)){
        int k = 0; //this is to know if all the charcters of the searchStr are found, we put it to zero
                    // in every iteration of the original while loop.
        //we will see if the value of k is less than searchString length and the corresponding values match.
        while(k<searchStrlen && str[i-k] == searchStr[searchStrlen-k-1]){
            k++;
        }
        //If the size comes as equal, we return the position.
        if(k == searchStrlen){
            return (i-searchStrlen+2);
        }
        else{
            //We increment the i by the value of the first mismatched charcater of the original string.
            i = i + table[str[i]]; 
        }
    }
    return -1;
}

//This functions take the original stringa and the string to be found and then determines the position
//of the specific character.
void main(){

    char str[100]; //This contains the original source string.
    char searchStr[100]; //This contains the string to be matched.

    printf("\nEnter the string:\t");
    scanf("%s",str);

    printf("\nEnter the string to be searched:\t");
    scanf("%s",searchStr);

    int pos = horspool(str,searchStr);

    if(pos == -1){
        printf("\nThe given string is not found in the original string.");
    }
    else{
        printf("\nThe search string is found at position %d in the original string",pos);
    }
}