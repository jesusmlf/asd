#include <stdio.h>

int main(){

    char topping[24];
    int slices;
    int month,year,day;
    float cost;

    printf("How much does a pizza costs in your area?");
    printf("Enter cost in $XX.XX\n");
    fflush(stdin);
    printf("$");
    scanf("%f",&cost);

    printf("What is your favorite one word favorite topping?: ");
    fflush(stdin);
    fflush(stdout);
    scanf(" %s",topping);

    printf("How many slices of %s pizza can you it in one sitting?",topping);
    scanf("%d",&slices);

    printf("Cual es el dia de hoy? Ingresar por XX/XX/XX\n");
    scanf("%d",&year);

    printf("Why not treat yourself to dinner on %d and have %d slices of %s pizza?", year,slices,topping);

    return (0);


}