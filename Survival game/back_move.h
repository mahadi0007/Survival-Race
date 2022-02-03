#ifndef MYHEADER_H_INCLUDED
#define MYHEADER_H_INCLUDE


int backchange ;                                 // variable for backchange iSetTimer.
int bc1,bc2,bc3;                                 //variable for background image load 
int bc1_x=0,bc1_y=0,bc1_w=600,bc1_h=600;         //co-ordinate for background image
int bc2_x=600,bc2_y=0,bc2_w=600,bc2_h=600;       //co-ordinate for background image
int bc3_x=1200,bc3_y=0,bc3_w=600,bc3_h=600;      //co-ordinate for background image
int bc4_x=1800,bc4_y=0,bc4_w=600,bc4_h=600;      //co-ordinate for background image

int sky1;                                        //variable for load sky image
int sky1_x=0,sky1_y=0,sky1_w=600,sky1_h=600;     //co-ordinate for sky image

int mountain1,mountain2;                         //variable for load mountain image
double mountain1_x=0,mountain1_y=310,mountain1_w=600,mountain1_h=300;    //co-ordinate for mountain1 image
double mountain2_x=600,mountain2_y=310,mountain2_w=600,mountain2_h=300;  //co-ordinate for mountain2 image

int mountainbc1;                                  //variable for load last small mountain image
double mountainbc_x=0,mountainbc_y=220,mountainbc_w=600,mountainbc_h=600;  //co-ordinate for last small mountain image

int field1,field2;                  //variable for load green filed image                          
double field1_x=0,field1_y=0,field1_w=600,field1_h=600;     //co-ordinate for green filed1 image
double field2_x=600,field2_y=0,field2_w=600,field2_h=600;   //co-ordinate for green filed2 image

int tree1,tree2;                     //variable for load tree image
int tree1_x=-20,tree1_y=165,tree1_w=70,tree1_h=400;         //co-ordinate for tree1 image
int tree2_x=580,tree2_y=165,tree2_w=70,tree2_h=400;         //co-ordinate for tree2 image



void bc_change()         //funtion rendering background.
{
	bc1_x-=3;
	bc2_x-=3;
	bc3_x-=3;
	bc4_x-=3;
	mountain1_x-=.6;
	mountain2_x-=.6;
	field1_x-=.75;
	field2_x-=.75;
	tree1_x-=3;
	tree2_x-=3;

	

	if (bc1_x<-600)
	{
		bc1_x=1195;
	}
	if (bc2_x<-600)
	{
		bc2_x=1195;
	}
	if (bc3_x<-600)
	{
		bc3_x=1195;
	}
	
	
	if (tree1_x<-630)
	{
		tree1_x=570;
	}
	if (tree2_x<-600)
	{
		tree2_x=580;
	}
	if (mountain1_x<-600)
	{
		mountain1_x=600;
	}
	if (mountain2_x<-600)
	{
		mountain2_x=600;
	}

	if(field1_x<-590)
	{
		field1_x=600;
	}
	
	if(field2_x<-590)
	{
		field2_x=600;
	}

}



#endif // MYHEADER_H_INCLUDED