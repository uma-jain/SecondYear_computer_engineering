#include<iostream> 
#include<math.h> 
#include<graphics.h>
using namespace std;
           
            // function to draw polygon of n sides
           void drawpolygon(int todraw[][2],int n)          
		  {   
		  	for( int i=0;i<n-1;i++)
		  	{ line(todraw[i][0],todraw[i][1],todraw[i+1][0],todraw[i+1][1]); }
		  	
			  line(todraw[n-1][0],todraw[n-1][1],todraw[0][0],todraw[0][1]);
			
		  }
               //take input
                    void getdata(int input[][2],int n)
			  {   
				  	 cout<<" enter x and y co-ordinates sequence ( x1 y1 x2 y2 ____)";
				  	 for(int i=0;i<n;i++)
				  	 {
				  	 	  cin>>input[i][0]>>input[i][1];
				  	 	  
					 }
					
		  }
                // multiplies two matrices s and p
		  
		void findNewCoordinate(int s[][2], int p[2][1]) 
			{ 
			    int temp[2][1]={0} ;
			  
			    for (int i = 0; i < 2; ++i) 
			        {    
					  
					  for (int j = 0; j < 1; ++j) 
			            { 
					       for (int k = 0; k < 2; ++k) 
			                {
							temp[i][j] +=(s[i][k] * p[k][j]);
						    }
						  
						}
				    
					}
		   
			  
			    p[0][0] = temp[0][0]; 
			    p[1][0] = temp[1][0]; 
			} 

			
		
		  // SCALING
		  void scale(int a[][2], int sx, int sy,int n) 
		{ 
		   
		  
		    // Initializing the Scaling Matrix. 
		    int s[2][2] = { sx, 0, 0, sy }; 
		    int p[2][1]; 
		
		    for (int i = 0; i < n; i++)           
		   {                                 
		        p[0][0] = a[i][0];                  
		        p[0][1] = a[i][1]; 
		        
		  
		        findNewCoordinate(s, p); 
		        
			    a[i][0]= p[0][0] ;                  
			    a[i][1]= p[0][1] ; 
			    
		    } 
		    cout<<"function executed\n";
		    cout<<"updated\n";
		    
			
		   
		    
		   		   drawpolygon(a,n);
		   
		} 
		//ROTATE 
		  void rotate(int a[][2], int n, int x_pivot, int y_pivot, int angle) 
		{ 
		    int i = 0; 
		    while (i < n) 
		    { 
		        // Shifting the pivot point to the origin 
		        // and the given points accordingly 
		        int x_shifted = a[i][0] - x_pivot; 
		        int y_shifted = a[i][1] - y_pivot; 
		   
		        a[i][0] = x_pivot + (x_shifted*cos(angle*3.141/180)  
		                          - y_shifted*sin(angle*3.141/180)); 
		        a[i][1] = y_pivot + (x_shifted*cos(angle*3.141/180)  
		                          + y_shifted*sin(angle*3.141/180)); 
		        cout<<a[i][0]<<a[i][1];
		        i++; 
		    } 
		
		   drawpolygon(a,n);
		   
		} 
		// TRANSLATE
		void translate ( int a[][2], int t[][1],int n) 
			{ 
			     for(int i=0;i<n;i++)
				 {
				 	a[i][0] += t[i][0];
				 	a[i][1] += t[i][1];
				 	
				  } 
			    setcolor (2); 
			    drawpolygon(a,n);
			  
			     
			} 

  
  
	

main() 
{ 
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"C:\\TC\\BGI");
   int n,choice;
  
   cout<<"enter no of sides";
   cin>>n;
   int input[n][2];
   
   getdata(input,n);
   drawpolygon(input,n);
  
  //------------------------------------
   cout<<"------========MENU=======-------\n1.Scaling\n2.Rotation\n3.Translation\n4.Enter your choice";
   cin>>choice;
   switch(choice)
   {
   	 case 1 :     
		             
					 scale(input,2,2,n); ;
   	 	break;
   	   case 2: 
		 rotate(input, n, 450, 450, 45) ;
		break;
		case 3:
		 int t_factor[][1]={50,50};
		translate(input,t_factor,n);
		break;	
   }
   
   
   getch();
   closegraph();
} 
