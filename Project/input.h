/***************************************************************************************************
C Header Files
***************************************************************************************************/
#include <stdlib.h>  //standard library definitions
#include <stdio.h>   //standard buffered input/output
#include <ctype.h>   //character types
#include <string.h>  //string operations
#include <strings.h> //string operations
#include <math.h>    //mathematical declarations
#include <time.h>    //time types
#include <complex.h> //complex arithmetic
#include <assert.h>  //verify program assertion
#include <limits.h>  //implementation-dependent constants
/***************************************************************************************************
Constant Declarations 
***************************************************************************************************/
// VARIOUS CONSTANTS
#define Mfnam 20   // Max number of characters in the input/output file name
#define Mlin 500   // Max number of characters in a single line in the input file
#define Mnod 15000 // Max number of gates in a circuit/netlist
#define Mnam 25    // Max number of characters in the node name
#define Mtyp 10    // Max number of nodes/gates type
#define Min 9      // Max number of fanin of a gate
#define Mout 16    // Max number of fanout of a gate
#define Mpi 233    // Max number of total primary inputs in a circuit/netlist
#define Mpo 140    // Max number of total primary outputs in a circuit/netlist
#define Mpt 1000000  // Max number of lines(inputpatterns) in .vec file
#define Mft 31     // Max number of lines(stuck at faults) in .fau file
// GATE TYPE CONSTANTS
#define INPT 1  // Primary Input
#define FROM 2  // STEM BRANCH
#define BUFF 3  // BUFFER
#define NOT 4   // INVERTER
#define AND 5   // AND
#define NAND 6  // NAND
#define OR 7    // OR
#define NOR 8   // NOR
#define XOR 9   // XOR
#define XNOR 10 // XNOR

#define D 3     // D  
#define D_bar 4  // D_bar


/***************************************************************************************************************************
Structure Declarations 
****************************************************************************************************************************/
//1.Stucture declaration for LIST
typedef struct LIST_type
{
  int Id;                 //Id for current element
  struct LIST_type *Next; //Pointer to next element (if there is no element,it will be NULL)
} LIST;
//2.Stucture declaration for GATE

typedef struct GATE_type
{
  char *Name;                    //Name of the gate
  int Type, Nfi, Nfo, Mark, Val; //Type, No of fanins, No of fanouts, Marker,Value
  LIST *Fin, *Fot;               //Fanin members, Fanout members
} GATE;

typedef struct PATTERN
{
  char PI[Mpi];
} PATTERN;



typedef struct nodeValues
{
    int nodeNumber;
    int nodeValue;
}nodeValuesFor;

//Create the objects of struct nodeValue


/***************************************************************************************************************************
Functions in declared in input.c
****************************************************************************************************************************/
/***************************************************************************************************************************
LIST Structure Functions
****************************************************************************************************************************/
void InsertEle(LIST **, int);
void DeleteEle(LIST **, int);
int FindEle(LIST *, int);
void PrintList(LIST *);
int CountList(LIST *);
void FreeList(LIST **);
/***************************************************************************************************************************
 GATE Structure Functions
****************************************************************************************************************************/
void InitiGat(GATE *, int);
void PrintGats(GATE *, int);
void CountPri(GATE *, int, int *, int *);
void ClearGat(GATE *, int);
/***************************************************************************************************************************
Functions for reading .isc file
****************************************************************************************************************************/
int AssignType(char *);
int ReadIsc(FILE *, GATE *);

/***************************************************************************************************************************
 Function for Reading .vec File
 ***************************************************************************************************************************/
int ReadVec(FILE *, PATTERN *);
/***************************************************************************************************************************
User Defined Functions in user.c
****************************************************************************************************************************/
/****************************************************************************************************************************/
int simulate(int, int, GATE *, PATTERN *, FILE *, LIST *);
int charToInt(char);
char intToChar(int);

int checkDfrontier (GATE* , int);
nodeValuesFor getObjective( GATE* , LIST* , int , int);

nodeValuesFor Backtrace(nodeValuesFor, GATE*, nodeValuesFor);

int PODEM_recursion(int* , GATE * , int);

int faultSensitize(int , GATE* ,  nodeValuesFor, int,int , LIST*);

void PrimaryOutput(int, GATE*, int*);


