#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#define num_bits 32
void DecimalToBinary(int*array_Num,int64_t Num,int Numbits);
void ThreeArraysConcatenator(int* array_AC_Q0_Q_n1,int* array_AC,int* array_Q0,int* array_Q_n1);
void ArtithmeticRightShift(int* array_AC_Q0_Q_n1);
void ThreeArraysSplitter(int* array_AC_Q0_Q_n1,int* array_AC,int* array_Q0,int* array_Q_n1);
int64_t BinaryToDecimal(int*array_Num,int Numbits);
void TwoArraysConcatenator(int* array_AC_Q0,int* array_AC,int* array_Q0);
void ArtithmeticLeftShift(int* array_AQ);
void TwoArraysSplitter(int* array_AQ,int* array_A,int* array_Q);

/*
    //Case 1: Divisor is greater than Dividend
    int64_t a = 30;
    int64_t b = 60;
    printf("Finding Quotient and remainder for 30/60\n");
    Division(60,30);

    //Case 2: Divisor is smaller than Dividend
    a = 30;
    b = 15;
    printf("Finding Quotient and remainder for 30/15\n");
    Division(15,30);

    //Case 3: Divisor is equal to Dividend
    a = 30;
    b = 30;
    printf("Finding Quotient and remainder for 30/30\n");
    Division(30,30);

    //Case 4: Divisor is Zero
    a = 30;
    b = 0;
    printf("Finding Quotient and remainder for 30/0\n");
    Division(0,30);
*/ 
/*I have tested the code for all cases and it works perfectly*/

int main(){
    int N=num_bits;
    int64_t A=0;
    int64_t M=0;  //divisor
    int64_t Q=30;  //dividend
    int64_t A_Res=A; //The value of A before subtraction with M

    int* array_AQ=(int*)calloc(num_bits*2,sizeof(int));
    int* array_A=(int*)calloc(num_bits,sizeof(int));
    int* array_Q=(int*)calloc(num_bits,sizeof(int));
    while (N!=0){
        DecimalToBinary(array_A,A,num_bits);
        DecimalToBinary(array_Q,Q,num_bits);

        TwoArraysConcatenator(array_AQ,array_A,array_Q);
        ArtithmeticLeftShift(array_AQ);
        TwoArraysSplitter(array_AQ,array_A,array_Q);
        A=BinaryToDecimal(array_A,32);

        A_Res=A;
        A=A-M;
        DecimalToBinary(array_A,A,32);
        if (array_A[0]==0){
            array_Q[31]=1;
        }
        else if (array_A[0]==1)
        {
            array_Q[31]=0;
            A=A_Res;
        }
        Q=BinaryToDecimal(array_Q,32);
        N=N-1;
    }
    Q=BinaryToDecimal(array_Q,32);

    printf("\nQuotient= %ld \n",Q);
    printf("\n");
    printf("\nRemainder= %ld \n",A);
    if(Q==-1){
        printf("\nDIVISION BY ZERO\n");
    }
    free(array_AQ);
    free(array_A);
    free(array_Q);
}
void DecimalToBinary(int*array_Num,int64_t Num,int Numbits){
    int64_t num=Num;
    int i=0;
    int64_t remainder;
    for (int j = 0; j < Numbits; j++)
    {
        *(array_Num+j)=0;
    }    
    if (num>0){
        *(array_Num+(0))=0;
        while (num>=1){
            remainder=num%2;
            
            *(array_Num+(Numbits-1-i))=remainder;
            i++;
            num=num/2;
        }
    }
    else if (num<0){
        *(array_Num+(0))=1;
        num=(int64_t)pow(2, (Numbits-1))+num;
        while (num>=1){
            remainder=num%2;
            *(array_Num+(Numbits-1-i))=remainder;
            i++;
            num=num/2;
        }
    }  
}
void ThreeArraysConcatenator(int* array_AC_Q0_Q_n1,int* array_AC,int* array_Q0,int* array_Q_n1){
    for(int i=0;i<32;++i){
        *(array_AC_Q0_Q_n1+i)=*(array_AC+i);
    }
    for(int j=32;j<64;++j){
        *(array_AC_Q0_Q_n1+j)=*(array_Q0+j-32);
    }
    for(int k=64;k<96;++k){
        *(array_AC_Q0_Q_n1+k)=*(array_Q_n1+k-64);
    }
}
void ArtithmeticRightShift(int* array_AC_Q0_Q_n1){
    int c=*(array_AC_Q0_Q_n1);
    for(int j=0;j<95;++j){
        *(array_AC_Q0_Q_n1+95-j)=*(array_AC_Q0_Q_n1+95-(j+1));
    }
    *(array_AC_Q0_Q_n1)=c;
}
void ArtithmeticLeftShift(int* array_AQ){
    for(int j=0;j<63;++j){
        *(array_AQ+j)=*(array_AQ+j+1);
    }
    *(array_AQ+63)=0;
    *(array_AQ)=0;
}
void ThreeArraysSplitter(int* array_AC_Q0_Q_n1,int* array_AC,int* array_Q0,int* array_Q_n1){
    for(int i=0;i<32;++i){
        *(array_AC+i)=*(array_AC_Q0_Q_n1+i);
    }
    for(int j=32;j<64;++j){
        *(array_Q0+j-32)=*(array_AC_Q0_Q_n1+j);
    }
    for(int k=64;k<96;++k){
        *(array_Q_n1+k-64)=*(array_AC_Q0_Q_n1+k);
    }
}
void TwoArraysSplitter(int* array_AQ,int* array_A,int* array_Q){
    for(int i=0;i<32;++i){
        *(array_A+i)=*(array_AQ+i);
    }
    for(int j=32;j<64;++j){
        *(array_Q+j-32)=*(array_AQ+j);
    }

}

int64_t BinaryToDecimal(int* array_Num, int Numbits) {
    int64_t Result = 0;

    if (array_Num[0] == 1) {
        Result -= (int64_t)pow(2, Numbits - 1);
    }

    for (int i = 1; i < Numbits; i++) {
        if (array_Num[i] == 1) {
            Result += (int64_t)pow(2, Numbits-i-1);
        }
        else{
            Result=Result;
        }
    }

    return Result;
}

void TwoArraysConcatenator(int* array_AC_Q0,int* array_AC,int* array_Q0){
    for(int i=0;i<32;++i){
        *(array_AC_Q0+i)=*(array_AC+i);
    }
    for(int j=32;j<64;++j){
        *(array_AC_Q0+j)=*(array_Q0+j-32);
    }
}

/*I used the commented code below to test all functions in this code*/
/*
    printf("AQ\n");
    for (int i = 0; i < 64; i++)
    {
        if (i%32==0){
            printf(" ");
        }
        printf("%d",array_AQ[i]);
    }
    printf("\n");
    printf("A=%ld\n",A);
    for (int i = 0; i < 32; i++)
    {
        printf("%d",array_A[i]);
    }
    printf("\n");
    printf("Q=%ld\n",Q);
    for (int i = 0; i < 32; i++)
    {
        printf("%d",array_Q[i]);
    }
    printf("\n");
*/