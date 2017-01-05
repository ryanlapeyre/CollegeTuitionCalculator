/**********************
 * Ryan Lapeyre
 * College Tuition Calculator
 *********************/




#include <stdio.h>

int checkID(int a[][2] , int b);
int checkHours(int h, int t);
int checkScholarship(float t , float s , int k);
void processUndergrad(float a[][3] , int id , int row);
void processGraduate(float a[][3] , int id , int row);
void processPHD(float a[][3] , int id , int row);
void processFinalReport( int s[][2] , float b [][3]);	
void sort( int s[][2] , float b[][3]);

int main (void)
{
    int stuInfo [6][2] = { 
	{394003920 , 2},
	{388920394 , 3},
	{499230076 , 1},
	{298760112 , 2},
	{592493811 , 3},
	{355982306 , 3} };

    float billInfo[6][3] = {  
	{0.0 , 0.0 , 0.0},
	{0.0 , 0.0 , 0.0},
	{0.0 , 0.0 , 0.0},	      	
	{0.0 , 0.0 , 0.0},	
	{0.0 , 0.0 , 0.0},   	    			
	{0.0 , 0.0 , 0.0} };						


    int order = 1;
    int inputID;
    int rowID;


    do
    {
	printf("Enter the student ID:");
	scanf("%d" , &inputID);
	while (checkID(stuInfo , inputID) == -1)
	{
	    printf("Invalid student ID. Please type again or enter 0 to quit:");
	    scanf("%d" , &inputID);
	    if(inputID == 0)
	    {
		return 0;    
	    }
	
	}

	rowID = checkID(stuInfo , inputID);

	switch (stuInfo[rowID][1])
	{
	    case 1 : processUndergrad(billInfo , inputID , rowID);
		     break;

	    case 2 : processGraduate(billInfo , inputID , rowID);
		     break;

	    case 3 : processPHD(billInfo , inputID , rowID);
		     break;
	}



	printf("\nDo you want to continue for next student? If yes hit 1 else hit 0:");
	scanf("%d" , &order);


    }
    while ( order == 1 );
    processFinalReport(stuInfo , billInfo);
    sort(stuInfo , billInfo);
    printf("\n\n\nSORTED BY STUDENT ID");
    processFinalReport(stuInfo , billInfo);
    return 0;


}


int checkID (int a[][2], int b)
{
    int c; 

    for ( c = 0; c < 6; c++)
    {
	if ( a[c][0] == b)
	{
	    return c;
	}
    }

    return -1; 
}

int checkHours (int h, int t)
{
    switch(t)
    {
	case 1: if( h > 18 || h < 3)
		{
		    return 0;
		}
		return 1;
		break;

	case 2: if( h > 12 || h < 3)
		{
		    return 0;
		}
		return 1;
		break;
	case 3: if( h > 9 || h < 3)
		{
		    return 0;
		}
		return 1;
		break;

    }
    return 0;

}

void processUndergrad(float a[][3] , int id , int row)
{
    int hours; 
    int type = 1;
    float tuition;
    float scholarship;
    float net;

    printf("Enter the number of credit hours:");
    scanf("%d" , &hours);
    while(checkHours(hours , type ) == 0)

    {   printf("Undergrad students must be enrolled in 3 - 18 hours. Please enter again:");
	scanf("%d" , &hours);
    }
    tuition = hours * 750.00; 

    printf("Enter scholarship amount:");
    scanf("%f" , &scholarship);
    while(checkScholarship(tuition ,scholarship , type ) == 0)
    {
	printf("Scholarship can't be greater than half of the tuition. Please enter the correct amount:");
	scanf("%f" , &scholarship);
    }

    net = tuition - scholarship;
    a[row][0] = tuition;
    a[row][1] = scholarship;
    a[row][2] = net;

    printf("\nUndergraduate student %d Tuition is :" , id);
    printf("\nGross                        $ %.2f" , a[row][0]);
    printf("\nScholarship Amount           $ %.2f" , a[row][1]);
    printf("\nTotal Tuition Bill           $ %.2f\n" , a[row][2]);

    return;
}


void processGraduate(float a[][3] , int id , int row)
{
    int hours; 
    int type = 2;
    float tuition;
    float scholarship;
    float net;

    printf("Enter the number of credit hours:");
    scanf("%d" , &hours);
    while(checkHours(hours , type ) == 0)

    {   printf("Grad students must be enrolled in 3 - 12 hours. Please enter again:");
	scanf("%d" , &hours);
    }
    tuition = hours * 1000.00;


    printf("Enter scholarship amount:");
    scanf("%f" , &scholarship);
    while(checkScholarship(tuition ,scholarship , type ) == 0)
    {
	printf("Scholarship can't be greater than 75%% of the tuition. Enter the correct amount:");
	scanf("%f" , &scholarship);
    }

    net = tuition - scholarship;
    a[row][0] = tuition;
    a[row][1] = scholarship;
    a[row][2] = net;

    printf("\nGraduate student %d Tuition is :" , id);
    printf("\nGross                        $ %.2f" , a[row][0]);
    printf("\nScholarship Amount           $ %.2f" , a[row][1]);
    printf("\nTotal Tuition Bill           $ %.2f\n" , a[row][2]);


    return;
}

void processPHD(float a[][3] , int id , int row)
{
    int hours; 
    int type = 3;
    float tuition;
    float stipend;
    float net;

    printf("Enter the number of credit hours:");
    scanf("%d" , &hours);
    while(checkHours(hours , type ) == 0)

    {   printf("PhD students must be enrolled in 3 - 9 hours. Please enter again:");
	scanf("%d" , &hours);
    }
    tuition = hours * 1200.00;


    printf("Enter stipend amount:");
    scanf("%f" , &stipend);
    while(checkScholarship(tuition ,stipend, type ) == 0)
    {
	printf("Stipend cannot be greater than 10,000. Please enter the correct amount:");
	scanf("%f" , &stipend);
    }

    net = tuition - stipend;
    a[row][0] = tuition;
    a[row][1] = stipend;
    a[row][2] = net;

    printf("\nPhd student %d Tuition is :" , id);
    printf("\nGross                   $ %.2f" , a[row][0]);
    printf("\nStipend Amount          $ %.2f" , a[row][1]);
    printf("\nTotal Tuition Bill      $ %.2f\n" , a[row][2]);

    return;
}
int checkScholarship ( float t , float s , int k)
{

    switch(k)
    {
	case 1: if(  s  > t * .50 ) 
		{
		    return 0;
		}
		return 1;
		break;

	case 2: if( s > t * .75)
		{
		    return 0;
		}
		return 1;
		break;
	case 3: if( s > 10000)
		{
		    return 0;
		}
		return 1;
		break;
    }
    return 0;

}


void processFinalReport( int s[][2] , float b [][3] )
{

    int d;
    float g_total = 0;
    float d_total = 0;
    float n_total = 0;

    printf("\n\nSTUDENT BILLING REPORT\n\n");

    printf("\n\n%s%18s%17s%19s%14s\n" ,"ID" , "TYPE" , "GROSS" ," DISCOUNT" ,"NET");
    for (d = 0; d < 6; d++)
    {
	if (b[d][0] != 0.0)
	{
	    printf("%d" , s[d][0] );
	    printf("%8d" , s[d][1] );
	    printf("%22.2f" , b[d][0] );
	    printf("%17.2f" , b[d][1] );
	    printf("%18.2f\n" , b[d][2] );
	}
    }
    printf("-------------------------------------------------------------------------------\n");
    for (d = 0; d < 6; d++)
    {
	if (b[d][0] != 0)
	{
	    g_total += b[d][0];
	    d_total += b[d][1];
	    n_total += b[d][2];
	}
    }
    printf("\t\tTOTAL%18.2f%17.2f%18.2f\n" , g_total , d_total , n_total);

    return;


}


void sort (int s[][2] , float b[][3])

{
    int c;
    int d;
    int extra;
    int spare;
    float clone;
    float copy;
    float duplicate;


    for ( c = 0; c < 6; c++)
    {

	for (d = 0; d < 5; d++)
	{
	    if (s[d][0] > s[d + 1][0] && b[d][0] != 0.0)
	    {

		extra = s[d][0];
		s[d][0] = s[d + 1][0];
		s[d + 1][0] = extra;

		spare = s[d][1];
		s[d][1] = s[d + 1][1];
		s[d + 1][1] = spare;

		clone = b[d][0];
		b[d][0] = b[d + 1][0];
		b[d + 1][0] = clone;

		copy = b[d][1];
		b[d][1] = b[d + 1][1];
		b[d + 1][1] = copy;

		duplicate = b[d][2];
		b[d][2] = b[d + 1][2];
		b[d + 1][2] = duplicate;





	    }
	}


    }

    return;
}
