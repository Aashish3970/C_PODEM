#include "input.h"
/***************************************************************************************************
Command Instructions
***************************************************************************************************/
//To Compile: make
//To Run: ./project c17.isc 
/***************************************************************************************************
 Main Function
***************************************************************************************************/
int main(int argc,char **argv)
{
LIST* Dfront;
FILE *Isc,*Pat,*Res, *fwrite;                  //File pointers used for .isc, .pattern, and .res files
int Npi,Npo,Tgat;                     //Tot no of PIs,Pos,Maxid,Tot no of patterns in.vec,.fau
GATE *Node;                           //Structure to store the ckt given in .isc file 
static PATTERN p_vect[Mpt]; 
clock_t Start,End;                    //Clock variables to calculate the Cputime
double Cpu;                           //Total cpu time
int i,j;                              //Temporary variables



/****************PART 1.-Read the .isc file and store the information in Node structure***********/
Npi=Npo=Tgat=0;                                //Intialize values of all variables
Isc=fopen(argv[1],"r");                        //File pointer to open .isc file 
Node=(GATE *) malloc(Mnod * sizeof(GATE));     //Dynamic memory allocation for Node structure
Tgat=ReadIsc(Isc,Node);                        //Read .isc file and return index of last node
fclose(Isc);                                   //Close file pointer for .isc file
PrintGats(Node,Tgat);                          //Print the information of each active gate in Node structure after reading .isc file
CountPri(Node,Tgat,&Npi,&Npo);                 //Count the No of Pis and Pos
printf("\n\nNpi: %d Npo: %d\n",Npi,Npo);       //Print the no of primary inputs and outputs
/***************************************************************************************************/
int a;
fwrite=fopen("output.txt","w");
Pat=fopen(argv[2],"r");                          
int Total=0; Total=ReadVec(Pat,p_vect);          
printf("\nTot No of Pattern: %d",Total);         
fclose(Pat);    
for(a=0;a<Total;a++){  printf("%d\t%s",a,p_vect[a].PI);
} 

//int gateValue= 0 ;
//int gateID= 9;

nodeValuesFor returnBack;


int faultId;
int faultValue;
//int * POnodes;
//int size;
int POnodes[1000];
//fwrite=fopen("output.txt","w");

/***************************************************************************************************
 ************************************************************************************************/

//simulate(Tgat,Total,Node,p_vect,fwrite, Dfront);

// Calling PODEM resursion function

PODEM_recursion(POnodes, Node , Tgat);


// if(PODEM_recursion(POnodes, Node , Tgat))
// {
//     printf("PODEM is successful");
//     for (i=0; i<Tgat; i++)
//         {
//             if(Node[i].Type == INPT)
//             {
//                 printf("the test pattern is %d", Node[i].Val);
//             }
//             else    
//             {
//                 printf("The  fault is untestable");
//             }
//         }
    
    
// }   


PrimaryOutput( Tgat, Node, POnodes);



/***************************************************************************************************/
fclose(fwrite);
ClearGat(Node,Tgat);  free(Node);                                      
return 0;
}//end of main
/****************************************************************************************************************************/



