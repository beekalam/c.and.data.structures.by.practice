// Array implementation to determine surface area of  Foot balls
#include  <stdio.h>  //library file on standard i/o
#define PI  3.14159   
//declare function prototype
float FindArea(float  radius);
void main() {
    int  n, i = 0; // i will use an array index, n for keeping count
    float radius[50];  //array of radius, numbering max of 50
    float area[50];    //array of area, numbering max of 50
    printf("To stop enter 0 for the radius \n");
    printf("\n Radius=?");
    scanf("%f", &radius[i]); // we are storing at address of radius[i]
    while(radius[i] != 0)
    {
        if (radius[i] < 0)
            area[i]  = 0;
        else
            area[i] = FindArea(radius[i]); //store the result in array area
        //get the next set of data. we have to increment i prior to  getting new
        // radius else old data will be over written and hence lost
        ++i;
        printf("To Stop enter 0 for the radius\n");
        printf("\n Radius=?" );
        scanf("%f", &radius[i]);
    }
    n = --i; //This is because you have increased the count
            // for i for radius = 0 case also. we will use n in for loop.
    //display array  elements
    printf("\n Surface area of balls\n" );
    for( i = 0; i <= n; ++i)
        printf("radius = %f area = %f\n",radius[i], area[i]);

}

//function definition
float FindArea(float radius) {
    return (4 * PI * radius * radius);
}
