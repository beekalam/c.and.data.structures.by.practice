//Use structures to find surface area of different colored balls
#include  <stdio.h>  //library file on standard i/o
#include  <stdlib.h>
#define PI  3.14159
//declare function prototype
float FindArea(float  radius);
struct FootBall {
    char  color[20];
    char sport[2];
    float radius;
    float  area;
};

typedef struct FootBall stsb;
stsb ball[10];  // maximum of 10 Foot balls
void main() {
  int  i = 0;    // i we will use as structure index
  char stg[20];  // This is an array. we will use it to store what we read from file
  FILE *fptr;    // fptr to object FILE. You can access definitions contained therein.
  fptr = fopen("SportsBalls.txt", "w");  // open SportsBalls for writing data

  if (fptr == NULL)
  {
    printf("File could not be opened\n");
    exit(1);
  }

   printf("To stop enter END for the color field\n");
   printf("\n Enter color of the ball: ");
   scanf("%s", ball[i].color);


  while (ball[i].color[0] != 'E'
         || ball[i].color[1] != 'N'
         || ball[i].color[2] != 'D')
  {

      fprintf(fptr, "%s\t", ball[i].color);

      //get details of sport, radius, and compute area
      printf("\n Sport = ?");
      scanf("%s", ball[i].sport);
      fprintf(fptr, "%s\t", ball[i].sport );

      printf("\n RADIUS = ?");
      scanf("%f", &ball[i].radius);
      fprintf(fptr, "%f\t", ball[i].radius);

      ball[i].area = FindArea(ball[i].radius);
      fprintf(fptr, "%f\t", ball[i].area);

      i++;

      //get the next set of data
      printf("To stop enter END for the color field \n"); //get next set of data
      printf("\nEnter color of the ball: ");
      scanf("%s", ball[i].color);

  }// end of while

  // close file SportsBalls.txt
  fclose(fptr);

  // now open the file in read mode
  fptr = fopen("SportsBalls.txt", "r"); // open sportsballs for reading data
  if (fptr == NULL)
  {
    printf("File could not be opened \n");
    exit(1);  // exit to operating system
  }

  printf("Detials of FootBalls fetched from file are ... \n");
  printf("color\t:\tsport\t:\tradius\t:\tarea \n");
  // do while end of file not reaached
  while (!feof(fptr))
  {
    //fscanf reads entire line as array. store it in array stg
    fscanf(fptr, "%s", stg);
    // print stg using printf command
    printf("%s\n", stg);
  }

  fclose(fptr);

}

//function definition
float FindArea(float radius) {
    float answer = 4 * PI * radius * radius;
    return answer;
}
