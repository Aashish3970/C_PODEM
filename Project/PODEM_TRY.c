int POnodes[1000];
int faultActFlag=0;
struct nodeValues
{
    int nodeNumber;
    int nodeValue;
};

//Create the objects of struct nodeValue
struct nodeValues Objective;
struct nodeValues Fault;
struct nodeValues Backtrace;


for(node_Line=0; node_Line <=Tgat; ++node_Line)
{
    if (node[node_Line].Fot==0)
    {  
        int a=0;
        POnodes[a]=node[node_Line]->id;
        a++;
    }    
}
void setDontCare(int Tgat, GATE* node)
{
    int i;
    for(i=1;i< Tgat; i++)
    {
        node[i].Val=2;
        node[i].Flag=0;
    }
}

//Determine if PODEM is successfull
int PODEM()
{   int x,i;
    //Check if fault-effect is observed at PO
    for(i=0;i< sizeof(POnodes);i++)
    {
        if(node[POnodes[i]].faultCheck==1)
        {
            printf("Propagation Successful")
            //print the primari inputs since propagation is successful

               
       
        }
    }
}

//Return the objective , function with return type struct
nodeValues getObjective(int Tgat, GATE* node, LIST* list,  )
{
    int l,v;
    l= Fault.nodeNumber;
    v=Fault.nodeValue;

    Objective.nodeNumber = 2;
    Objective.nodeValue = 2;

    //Check if the fault is activated
    for(int i=1;i< Tgat; i++)
    {
        if(node[i].faultFlag==1)
        {
            faultActFlag=1;
        }
    }
   
    if(!faultActFlag)
    {
        for(int i=0; i< Tgat; i++)
        {
            if( i ==l && node[i]->Val==2)
            {
                Objective.nodeNumber=l;
                Objective.nodeValue= !(v);
                return Objective;
            }
        }

       
    }
}

nodevalues Backtrace(nodeValues getObjective, int Tgat, GATE* node, LIST* list)
{   LIST* temp;
    int  Pinp[100];
    int a= getObjective.nodeNumber;
    int b= getObjective.nodeValue;
 while ( node[a].Nfi!=0)
 {
 
    temp=node[a].Fin;



    while(temp->Next != NULL)
    {   int num_inversion=0;
        a= temp->id;
       
        num_inversion ++;
    }

   
    Pinp=a;

 }


}

int main()
{
    int flag=1;
    int result=0;
   
    printf("Enter the fault node");
    scanf("%d",&Fault.nodeNumber);

    printf("Enter stuck at 0 or 1");
    scanf("%d",&Fault.nodeValue);

    /***************Call the PODEM Functions***************************/
        setDontCare(Tgat, Node);


}