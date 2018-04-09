#include <math.h>
#include <stdio.h>

const char *f[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const char *c[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
const char *e[] = {"ten", "eleven", "twelve", "thirteen", "forteen", "fifteen", "sixteen", "seventeen",
    "eighteen", "nineteen"};
const char *d[] = {"hundred", "thousand", "lakh", "crore"};

static void twodig(long int val){
    long int rem = val / 10;
    if(rem > 0){
        if(rem == 1){
            printf("%s", e[val - 10]);
            return;
        }
        else
            printf("%s", c[rem - 2]);
        if(val % 10 == 0)
            return;
        printf(" ");
    }

    printf("%s", f[val % 10]);
}

static void num_to_word(long int num){
    if(num > 9999999){
        num_to_word(num / 10000000);
        printf(" crore ");
        num = num % 10000000;
    }
    
    long int t = num;
    int count = 0;

    while(t > 0){
        t /= 10;
        count++;
    }
    
    t = num;
    long int hp = 0;
    if(count < 3){
        twodig(t);
        return;
    }
    else if(count == 3 || count % 2 == 0)
        hp = pow(10, count - 1);
    else
        hp = pow(10, count - 2);
    long int pos = count;
    t = num;

    long int dig;
    while(t > 0){
        dig = t / hp;
        twodig(dig);
        if(pos > 2){
             printf(" %s ", d[pos / 2 - 1]);
        }

        t = t % hp;
        hp /= (pos == 4 || pos == 5) ? 10 : 100;       
        pos -= (pos % 2 == 0) ? 1 : 2;
    }
}

int main(){
    long int a;
    printf("\nEnter the number : ");
    scanf("%ld", &a);
    if(a < 0){
        printf("minus ");
        a *= -1;
    }
    num_to_word(a);
    printf("\n");
    return 0;
}

