//#ifndef MYHEADER_H_INCLUDED
//#define MYHEADER_H_INCLUDE

int life=0;                        //variable for life
int carchange;                     //variable for iSetTimer for opponent car move
int oppcar1_x=1000,oppcar1_y=0,oppcar1_w=70,oppcar1_h=70;       //co-ordinate for opponent car1 image
int oppcar2_x=900,oppcar2_y=120,oppcar2_w=70,oppcar2_h=70;      //co-ordinate for opponent car2 image
int oppcar3_x=1400,oppcar3_y=120,oppcar3_w=70,oppcar3_h=70;     //co-ordinate for opponent car3 image
int oppcar4_x=800,oppcar4_y=0,oppcar4_w=70,oppcar4_h=70;        //co-ordinate for opponent car4 image
int speed_oop;                     //control opponent car speed
bool c1,c2,c3,c4=true;             //boolean variable for all car to show and hide


void change()                      //function for opponent car random move
{
	c1=true;
	c2=true;
	c3=true;
	c4=true;

    oppcar1_x-=speed_oop;
    oppcar2_x-=speed_oop;
    oppcar3_x-=speed_oop;
	oppcar4_x-=speed_oop;
  
    
	
    if (oppcar1_x < -100)                      //random move for opponent's 1st car
	{
		life+=20;
		c1=true;
		oppcar1_y = rand()%(150);                      
		oppcar1_x = 700+rand()%(300);
	}
	if (oppcar2_x < -100)                      //random move for opponent's 2nd car
	{
		life+=20;
		c2=true;
		oppcar2_y = rand()%(150);
		oppcar2_x = 700+rand()%(300);
	}

	if (oppcar3_x < -100)                      //random move for opponent's 3rd car
	{
		life+=20;
		c3=true;
		oppcar3_y = rand()%(150);
		oppcar3_x = 700+rand()%(300);
	}

	if (oppcar4_x < -100)                      //random move for opponent's 4th car
	{
		life+=20;
		c4=true;
		oppcar4_y = rand()%(150);
		oppcar4_x = 700+rand()%(300);
	}


	

	

}

//#endif // MYHEADER_H_INCLUDED