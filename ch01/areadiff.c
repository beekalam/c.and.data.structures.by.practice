//Use structures to find surface area of different colored balls
#include  <stdio.h>  //library file on standard i/o
#define PI  3.14159   
//declare function prototype
float FindArea(float  radius);
struct FootBall {
    char  color[20];
    float radius;
    float  area;
};

typedef struct FootBall stsb;
stsb ball[10];  // maximum of 10 Foot balls
void main() {
  int  n, i = 0;    // i we will use as structure index, n for keeping count

  printf("To stop enter STOP for the color field\n");
  printf("\n Enter color of the ball: ");
  scanf("%s", ball[i].color);
  /*  if any one of sub expression is true enter the loop. fore example if first letter
   *  is not S enter while loop. Similarly enter 2,3 , 4 letters are not T,O,P */
  while( ball[i].color[0] !='S' || ball[i].color[1] != 'T' || 
          ball[i].color[2] != 'O' || ball[i].color[3] != 'P')
  {
      printf("\n Radius = ? " );
      scanf("%f", &ball[i].radius);
      if( ball[i].radius < 0)
          ball[i].area = 0;
      else
          ball[i].area = FindArea(ball[i].radius);

      ++i;
      printf("To stop enter STOP for the color field\n"); // get next set of data
      printf("\n Enter color of ball: " );
      scanf("%s", ball[i].color);
  }// end of while

  n = --i; // this is because you have increased the count for i for color = STOP
           // case also
  printf("\n Surface area of Foot balls\n" );
  for( i = 0; i <= n; ++i)
      printf("color %s radius = %f area = %f\n", ball[i].color, ball[i].radius,
                  ball[i].area);
}

//function definition
float FindArea(float radius) {
    float answer = 4 * PI * radius * radius;
    return answer;
}
