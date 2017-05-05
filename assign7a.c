//Name-Saurav Roll-1601CS41
//The aim of the program is to find the inverse of a matrix if possible and also position of its highest minor

#include<stdio.h>
#include<math.h>

//prototyping the functions
float determinant(float[25][25],float);
void cofactor(float[25][25],float);
void transpose(float[25][25],float[25][25],float);

//variables used to locate highest minor
int maxMinor=0,maxx,maxy;
int main()
{
  //n and m to hold the row and column of the matrix and d to hold the value of the determinant
  float a[25][25],n,m,d;
  
  //i and j for the loop
  int i,j;

  printf("Enter the size of the Matrix = ");
  scanf("%f,%f",&n,&m);
  
  //getting the input
  for (i=0;i<n;i++)
    {
      printf("Enter the row %d of the matrix = ",i+1);
     for (j=0;j<m;j++)
       {
            if (j !=(m-1))
            {
                scanf("%f,",&a[i][j]); 
            }
            else
            {
              scanf("%f",&a[i][j]);
            }
          
      }
    
    } 

  //finding the determinant to check whether inverse is possible
  d=determinant(a,n);
  
  if (d==0 || (n!=m)){
      printf("\nInverse of Entered Matrix is not possible\n");
  }
  
  else{
    // if it is square and non-singular then find its cofactor
     cofactor(a,n); 
    }
}

/*For calculating Determinant of the Matrix, we will use recursion  */
float determinant(float a[25][25],float size)
{
  //multiplier will be switch between 1 and -1, det will store the value of determinant and b will store the small Matrix for calculating minor
  float multiplier=1,det=0,small_matrix[25][25];
  int i,j,m,n,col;
  if (size==1)
    {
     return (a[0][0]);
    }
  else
    {
     det=0;
     for (col=0;col<size;col++)
       {
        m=0;
        n=0;
        for (i=0;i<size;i++)
          {
            for (j=0;j<size;j++)
              {
                small_matrix[i][j]=0;
                if (i != 0 && j != col)
                 {
                   small_matrix[m][n]=a[i][j];
                   if (n<(size-2))
                   //shift to next column if possible
                    n++;
                   else
                    {
                     //shift to next row 
                     n=0;
                     m++;
                     }
                   }
               }
             }
          det=det + multiplier * (a[0][col] * determinant(small_matrix,size-1));
          multiplier*=-1;
          }
    }

    return det;
}

//function to calculate cofactor of the Matrix, almost same as Determinant calculation
void cofactor(float a[25][25],float size)
{

//small_matrix will used for recursion purpose and cofactor array wull store the cofactors
 float small_matrix[25][25],cofact[25][25];

 //some iterating variables
 int p,q,m,n,i,j;
 for (q=0;q<size;q++)
 {
   for (p=0;p<size;p++)
    {
     m=0;
     n=0;
     for (i=0;i<size;i++)
     {
       for (j=0;j<size;j++)
        {
          if (i != q && j != p)
          {
            small_matrix[m][n]=a[i][j];
            if (n<(size-2))
             //shift to next column 
             n++;
            else
             {
               //shift to the next row
               n=0;
               m++;
               }
            }
        }
      }

      //power will store the value of -1 raised to the power m+n
      int power=1;
      for(i=0;i<m+n;i++){
          power*=-1;
      }
      cofact[q][p]=power * determinant(small_matrix,size-1);

      //Finding the location of maxMinor
      if (((cofact[q][p])/power)>maxMinor)
      {
        maxMinor=((cofact[q][p])/power);
        maxx=q;
        maxy=p;
      }
    }
  }
  //Finding the transpose of the Matrix
  transpose(a,cofact,size);
}
/*Finding transpose of matrix */  
void transpose(float a[25][25],float cofact[25][25],float size)
{
  int i,j;
  float transposed[25][25],d;

//transposing the Matrix
  for (i=0;i<size;i++)
    {
     for (j=0;j<size;j++)
       {
         transposed[i][j]=cofact[j][i];
        }
    }
  printf("\nThe inverse of matrix is : \n");

  d=determinant(a,size);
  for (i=0;i<size;i++)
    {
     for (j=0;j<size;j++)
       {
          printf("%.0f/%.0f  ",transposed[i][j],d);
        }
        printf("\n");
    }
   printf("The Entered matrix is a square matrix\n");
   printf("The position of the highest minor is %d , %d", maxx, maxy);

   
}
