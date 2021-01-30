/* This program opens and reads a file of integers named
"file of integers.txt" with the first integer telling how many
numbers to put into an array. Then prints the average and max of
the array values and puts them into an output file named "answer-hw3.txt"
(the output file must be an empty text in the same directory!!)

Christos Drilakis, 26/11/2020 */

//First include preprocessing files
#include <stdio.h>

int main()
{
    //Declarations
    FILE *input_file, *output_file;
    int how_many, i, j, sum=0;
    float avg=0.0;

    //Open the txt files
    input_file = fopen("file of integers.txt", "r");
    output_file = fopen("answer-hw3.txt", "w+");

    //Extract the first integer value and declare the array
    rewind(input_file);
    fscanf(input_file, "%d", &how_many);
    int numberArray[how_many];

    //Read file into array
    for (i = 0; i < how_many; i++)
    {
        fscanf(input_file, "%d", &numberArray[i]);
    }

    //Print and save to outputfile the values of the array
    printf("The values of the array are:\n");
    fprintf(output_file, "The values of the array are:\n");
    for (i=0; i<how_many; i++)
    {
        printf("%d\t", numberArray[i]);
        fprintf(output_file, "%d\t", numberArray[i]);
    }

    //Compute, print and save to outputfile the average of the array values
    for (j = 0; j < how_many; j++)
    {
        sum = sum + numberArray[j];
    }
    avg = (float)sum / j;
    printf("\nAverage of array values is %f", avg);
    fprintf(output_file, "\nAverage of array values is %f", avg);

    //Compute, print and save to outputfile the maximum value of the array
    for (i = 1; i < how_many; ++i)
    {
        if (numberArray[0] < numberArray[i])
        numberArray[0] = numberArray[i];
    }
    printf("\nMaximum value = %d\n\n", numberArray[0]);
    fprintf(output_file, "\nMaximum value = %d\n\n", numberArray[0]);


    fclose(output_file);

return 0;

}
