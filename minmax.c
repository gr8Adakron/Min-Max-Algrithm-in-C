#include<stdio.h>

int max(int a[15][15], int n, int value);
int min(int a[15][15], int n, int value);

main()
{
  int i,j,n,a[15][15],c,goal,childnode,ans;
 		printf ("Enter the number of vertices in the graph : ");
 		scanf("%d",&n);
 		for(i=0;i<n;i++){
		 								printf("\n\n **** Insert the edges related to the vertex => %d ****", (i+1));
     for(j=0;j<n;j++){
					 if(i!=j){
						 	  printf("\n Edge between vertex [ %d->%d ] (1/0): ",(i+1),(j+1));
								scanf("%d",&a[i][j]);
						}
						if(i==j){//Prevents own Loop in the graph.
	 				    a[i][j]=0;
	 				  }
				}
		}
		
		printf("\n\n ***** Adjacency Matrix of following graph *****\n");
		printf("\n       ");
		for(i=0;i<n;i++)
		{
	    printf("   %d",(i+1));
		}
		
		printf("\n       ");
		for(i=0;i<n;i++)
		{
	    printf("____");
		}
		for(i=0;i<n;i++)
		{
		  printf("\n  %d   |",(i+1));
		  for(j=0;j<n;j++)
		  {
				printf("   %d",a[i][j]);
	    }
		}		
		
		
		printf("\n\n ***** Insert the weight related to Child nodes *****\n");
		
		for(i=0;i<n;i++)
		{ 
			childnode=1;
		  for(j=0;j<n;j++)
		  {
				 if(a[i][j]==1)
				 {
				   childnode=0;
				 }
				 if(childnode==1 && j==(n-1))
				 {
	 			   printf("\n Enter the weight of child node -> %d : ",(i+1));
					 scanf("%d",&a[i][i]);					 
				 }
		  }
		}
		
		printf("\n");
		ans=max(a,n,0);
		printf("\n\n Final Answer is ====> %d", ans);
		
		  printf ("\n\n*****  Programmed By : AFZAL JUNEJA  *****\n");
			 
}

int max(int a[15][15], int n, int value)
{
 int num=0,weight,pw,finalw,i,j;
 if(a[value][value]!=0 && a[value][value]!=0)
 {
    finalw=a[value][value];
    return finalw;
 }
 else
 {
   for(i=value;i<value+1;i++)
   {
		  for(j=0;j<n;j++)
		  {
				if(a[i][j]==1)
				{
				  if(num>0)
					{
				    pw=weight;
					}
					weight=min(a,n,j);
					printf("\nThe max value at depth 1  : %d", weight);
					if(weight>pw)
					{
				    finalw=weight;
				  }
				  if(num==0)
				  {
 					  finalw=weight;
				  }
		    	num++;
				}
		  }
   }
   return finalw;
 }
}

int min(int a[15][15], int n, int value)
{
 int num=0,weight,pw,finalw,i,j;
 if(a[value][value]!=0 && a[value][value]!=0)
 {
    finalw=a[value][value];
    return finalw;
 }
 else
 {
   for(i=value;i<value+1;i++)
   {
		  for(j=0;j<n;j++)
		  {
				if(a[i][j]==1)
				{
				  if(num>0)
					{
				    pw=weight;
					}
					weight=max(a,n,j);
					if(weight<pw)
					{
				    finalw=weight;
				  }
				  if(num==0)
				  {
 					  finalw=weight;
				  }
		    	num++;
				}
		  }
   }
   return finalw;
 }
}

