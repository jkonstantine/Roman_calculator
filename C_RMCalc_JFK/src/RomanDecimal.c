
/*   Roman Numeral Calculate Assignment JFK  6/26/2016   */

#include<stdio.h>
#include<string.h>


/* C Function prototypes */
int decNum(char Num_Roman_char);
long int ConvertRomanDecimal(char Num_Roman_chr[]);
int decimal_to_roman(char roman_Num[], long int number);
void predigits(char c1,char c2,char roman_Num_pre[]);
void postdigits(char c,int n,char roman_Num_post[]);

/*  Global variable for Roman output Char position */
int rcpos=0;

/**********************************************/
/*  C code main function Roman Calculate      */
/**********************************************/
int main(void)
{
printf("***************************************\n");
printf("  Roman Numeral Calculate Assignment  *\n");
printf("***************************************\n\n");

/* C code to change roman numbers to decimal */

    char Num_Roman_c[200];
    char roman_Num_sum[200]="\0";       /* initialize to NULL */;
    char roman_Num_diff[200]="\0";      /* initialize to NULL */;
    long int dval1=0, dval2=0, sum=0, diff=0;

    printf("Please enter the roman numerals one at a time\n\n");

    printf("Enter roman number#1 (Roman digits: I, V, X, L, C, D, M):  \n");
    scanf("%s",Num_Roman_c);
    dval1 = ConvertRomanDecimal(Num_Roman_c);
    printf("The decimal value: %ld\n\n",dval1);

    printf("Enter roman number#2 (Roman digits: I, V, X, L, C, D, M):  \n");
    scanf("%s",Num_Roman_c);
    dval2 = ConvertRomanDecimal(Num_Roman_c);
    printf("The decimal value: %ld\n\n",dval2);

    sum = (dval1 + dval2);

    if (dval1>dval2)
        diff=(dval1-dval2);
    else
        diff=(dval2-dval1);

    printf("The Added decimal value: %ld\n",sum);
    decimal_to_roman(roman_Num_sum, sum);
    printf("The Added Roman value: %s \n\n", roman_Num_sum);

    printf("The Subtracted decimal value: %ld\n",diff);
    decimal_to_roman(roman_Num_diff, diff);
    printf("The Subtracted Roman value: %s\n\n",roman_Num_diff);

return 0;
}

/****************************************************/
/* C code function to change decimal to roman       */
/****************************************************/
int decimal_to_roman (char roman_Num[],long int number)
{
rcpos=0;

if(number <= 0){
         printf("Invalid decimal number");
         return 0;
    }

    while(number != 0){

         if(number >= 1000){
             postdigits('M',number/1000,roman_Num);
             number = number - (number/1000) * 1000;
         }
         else if(number >=500){
             if(number < (500 + 4 * 100)){
                 postdigits('D',number/500,roman_Num);
                 number = number - (number/500) * 500;
             }
             else{
                 predigits('C','M',roman_Num);
                 number = number - (1000-100);
             }
         }
         else if(number >=100){
             if(number < (100 + 3 * 100)){
                 postdigits('C',number/100,roman_Num);
                 number = number - (number/100) * 100;
             }
             else{
                 predigits('L','D',roman_Num);
                 number = number - (500-100);
             }
         }
         else if(number >=50){
             if(number < (50 + 4 * 10)){
                 postdigits('L',number/50,roman_Num);
                 number = number - (number/50) * 50;
             }
             else{
                 predigits('X','C',roman_Num);
                 number = number - (100-10);
             }
         }
         else if(number >=10){
             if(number < (10 + 3 * 10)){
                 postdigits('X',number/10,roman_Num);
                 number = number - (number/10) * 10;
             }
             else{
                 predigits('X','L',roman_Num);
                 number = number - (50-10);
             }
         }
         else if(number >=5){
             if(number < (5 + 4 * 1)){
                 postdigits('V',number/5,roman_Num);
                 number = number - (number/5) * 5;
             }
             else{
                 predigits('I','X',roman_Num);
                 number = number - (10-1);
             }
         }
         else if(number >=1){
             if(number < 4){
                 postdigits('I',number/1,roman_Num);
                 number = number - (number/1) * 1;
             }
             else{
                 predigits('I','V',roman_Num);
                 number = number - (5-1);
             }
         }
    }

/*  For Debug use only
int z;
    printf("Roman number will be: ");
    for(z=0;z<rcpos;z++)
         printf("%c",roman_Num[z]);
*/
    return 0;
}
 void predigits(char c1,char c2, char roman_Num_pre[]){
    roman_Num_pre[rcpos++] = c1;
    roman_Num_pre[rcpos++] = c2;
    return;
}
void postdigits(char c,int n, char roman_Num_post[]){
    int k=0;
    for(k=0;k<n;k++)
         roman_Num_post[rcpos++] = c;
    return;
}


/****************************************************/
/*  C code function to change roman to decimal      */
/****************************************************/
   long int ConvertRomanDecimal(char Num_Roman_chr[])
    {
    int j=0;
    long int dvalue =0;

    while(Num_Roman_chr[j]){

         if(decNum(Num_Roman_chr[j]) < 0){
             printf("Not a valid roman digit : %c\n",Num_Roman_chr[j]);
             return 0;
         }

         if((strlen(Num_Roman_chr) -j) > 2){
             if(decNum(Num_Roman_chr[j]) < decNum(Num_Roman_chr[j+2])){
                 printf("Not a valid roman number\n");
                 return 0;
             }
         }

         if(decNum(Num_Roman_chr[j]) >= decNum(Num_Roman_chr[j+1]))
             dvalue = dvalue + decNum(Num_Roman_chr[j]);
         else{
             dvalue = dvalue + (decNum(Num_Roman_chr[j+1]) - decNum(Num_Roman_chr[j]));
             j++;
         }
         j++;
    }
/* debug    printf("The decimal value: %ld\n",dvalue); */
    return dvalue;
}

int decNum(char Num_Roman_char)
{
    int ldval=0;

    switch(Num_Roman_char){
         case 'I': ldval = 1; break;
         case 'V': ldval = 5; break;
         case 'X': ldval = 10; break;
         case 'L': ldval = 50; break;
         case 'C': ldval = 100; break;
         case 'D': ldval = 500; break;
         case 'M': ldval = 1000; break;
         case '\0': ldval = 0; break;
         default: ldval = -1;
    }

    return ldval;
}
