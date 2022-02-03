#include "iGraphics.h"
#include "back_move.h"          //header file for opponent background move
#include "opp_carmove.h"        //header file for opponent car move        


int scrn_h=600,scrn_w=600;     //Screen height and width


int image1;     //variable for homepage image load

int image2;     //variable for level choose page image load

int image5;     //variable for gameover page image load

int image6;     //variable for player car image load

int image14;    //variable for high score image load

int image15;    //variable for about us image load


int hmscrn_x=0,hmscrn_y=0,hmscrn_w=600,hmscrn_h=600;                //co-ordinate for home page

int levelscrn_x=0,levelscrn_y=0,levelscrn_w=600,levelscrn_h=600;    //co-ordinate for level choose page



bool level1 =true;            //for easy level
bool level2 =true;            //for medium level
bool level3 =true;            //for hard level

bool musicOn = false;         //sound for gameplay
bool music2On = false;        //sound for gameover
bool music3On = true;         //sound for menu and other page before starting game

int score =0;         //for increase score
char score2[20];      //for store score





int thunder;      //for thunder image load
int thunder_x,thunder_y,thunder_w=15,thunder_h=180;     //co-ordinate for thunder
bool th_show=false;
int thunderchange;      //variable for thunderchange iSetTimer.

int resmenu;           //for resume image load
int resmenu_x=0,resmenu_y=0,resmenu_w=600,resmenu_h=600;   //co-ordinate for resume image


int flashlogo;    //for flash logo image load
int flashlogo_x=555,flashlogo_y=540,flashlogo_w=30,flashlogo_h=50;   //co-ordinate for super power flash logo


int mycar_x=0,mycar_y=0,mycar_w=70,mycar_h=70;   //co-ordinate for player car (initial)

int  bomb;    //for bomb image load
int gbomb_x=mycar_x+56,gbomb_y=55,gbomb_w=8,gbomb_h=13;   //co-ordinate for bomb

int car1,car2,car3,car4;    //variable for all opponetn car image load



		

int gmover_up_x=0,gmover_up_y=0,gmover_up_w=600,gmover_up_h=600;    //co-ordinate for gameover page




int aboutus_x=0,aboutus_y=0,aboutus_w=600,aboutus_h=600;   //co-ordinate for about us page

int bck_change;   //variable for iSetTimer for background move 










int hscore_x=0,hscore_y=0,hscore_w=600,hscore_h=600;  //co-ordinate for highscore page   
int gamestate=0;       //variable for different gamestate.
int level;               //variable for different level.

int flame;       //image loader for crush time variable.
int flame_x,flame_y,flame_w=60,flame_h=70;   //co-ordinate for crash time flame


int k =0;
int gamer_bomb;          //variable for using iSetTimer  for bomb.
#define gbombnumber 500   //defining bomb number

struct gamerbomb       //structure for bomb show,move.
{
	int gbomb_x;
	int gbomb_y;
	bool gbombshow;
	bool isBombActive;
};
gamerbomb gbomb[gbombnumber];



void setgbomb()                     //funtion for bomb initial position
{
	for (int i=k;i<gbombnumber;i++)
	{
		gbomb[i].gbomb_x=mycar_x+45;
		gbomb[i].gbomb_y=mycar_y+45;
		gbomb[i].gbombshow=false;
		gbomb[i].isBombActive = false;
	}
}

void gbombmovement()  //function for bomb image show.
{
	for (int i=0;i<gbombnumber;i++)
	{
	
		if(gbomb[i].gbombshow)
		iShowImage(gbomb[i].gbomb_x,gbomb[i].gbomb_y,15,8,bomb);
	}
}

void gbombpositionchange()        //function for bomb move
{
	for (int i=0;i<gbombnumber;i++)
	{
		if(gbomb[i].gbombshow && gbomb[i].isBombActive == true)
		{
			gbomb[i].gbomb_x +=12;

			
			
		}
	}

	for (int i=0;i<gbombnumber;i++)    //function for reinitiate bomb.
	{
		if(gbomb[i].gbomb_x>=700)
		{
			gbomb[i].gbombshow=false;
			gbomb[i].isBombActive = false;
			gbomb[i].gbomb_x=mycar_x+30;
		}
	}
}
 

void menubutton()    //function for showing menu button
{

	iSetColor(255,255,255);
	iSetColor(255,0,0);
	iText(23,565,"MENU");

		
}

bool res_img=true;
void resume_image()     //showing resume image
{

	iShowImage( resmenu_x=0,resmenu_y=0,resmenu_w=600,resmenu_h=600,resmenu);


}



//crash with bomb function

void collisioncheck1(){

	for (int i = 0; i < gbombnumber ; i++)
	{
		
	//for 1st car crash
		if(gbomb[i].gbombshow)
			{
				
			if((gbomb[i].gbomb_x+8>=oppcar1_x && gbomb[i].gbomb_x<=oppcar1_x+oppcar1_w) && (gbomb[i].gbomb_y+13>=oppcar1_y && gbomb[i].gbomb_y<=oppcar1_y+oppcar1_h))
			{
				iShowImage(flame_x,flame_y,flame_w,flame_h,flame);
				gbomb[i].isBombActive = false;
				gbomb[i].gbombshow=false;
				
				score+=10;
				
				c1=false;
				oppcar1_x=1900;
			}
			
		//for 2nd car crash
			if((gbomb[i].gbomb_x+8>=oppcar2_x && gbomb[i].gbomb_x<=oppcar2_x+oppcar2_w) && (gbomb[i].gbomb_y+13>=oppcar2_y && gbomb[i].gbomb_y<=oppcar2_y+oppcar2_h))
				{
					
					gbomb[i].isBombActive = false;
					gbomb[i].gbombshow=false;
					iShowImage(oppcar2_x,oppcar2_y,flame_w,flame_h,flame);
					
					c2=false;
					oppcar2_x=1600;
					score+=10;

				}
			
		//for 3rd car crash
			if((gbomb[i].gbomb_x+8>=oppcar3_x && gbomb[i].gbomb_x<=oppcar3_x+oppcar3_w) && (gbomb[i].gbomb_y+13>=oppcar3_y && gbomb[i].gbomb_y<=oppcar3_y+oppcar3_h))
				{
					gbomb[i].isBombActive = false;
			
					gbomb[i].gbombshow=false;
					iShowImage(oppcar3_x,oppcar3_y,flame_w,flame_h,flame);
					
					c3=false;
					oppcar3_x=1300;
					score+=10;

				}
				
		//for 4th car crash
			if((gbomb[i].gbomb_x+8>=oppcar4_x && gbomb[i].gbomb_x<=oppcar4_x+oppcar4_w) && (gbomb[i].gbomb_y+13>=oppcar4_y && gbomb[i].gbomb_y<=oppcar4_y+oppcar4_h))
				{
					gbomb[i].isBombActive = false;
			
					gbomb[i].gbombshow=false;
					iShowImage(oppcar4_x,oppcar4_y,flame_w,flame_h,flame);
					
					c4=false;
					oppcar4_x=1000;
					score+=10;
				}
			
		}
			
	}
}

//End of crash with bomb function

//crash with thunder function
void th_crash()
{

	if(th_show==true)
			{
		
		//for 1st car crash	
			if((thunder_x+thunder_w>=oppcar1_x && thunder_x<=oppcar1_x+oppcar1_w) && (thunder_y+thunder_h>=oppcar1_y && thunder_y<=oppcar1_y+oppcar1_h))
			{
				iShowImage(flame_x,flame_y,flame_w,flame_h,flame);
				
				score+=10;
				
				c1=false;
				oppcar1_x=1900;
			}
			
		//for 2nd car crash
			if((thunder_x+thunder_w>=oppcar2_x && thunder_x<=oppcar2_x+oppcar2_w) && (thunder_y+thunder_h>=oppcar2_y && thunder_y<=oppcar2_y+oppcar2_h))
				{
					iShowImage(oppcar2_x,oppcar2_y,flame_w,flame_h,flame);
					
					c2=false;
					oppcar2_x=1600;
					score+=10;

				}
		//for 3rd car crash
			if((thunder_x+thunder_w>=oppcar3_x && thunder_x<=oppcar3_x+oppcar3_w) && (thunder_y+thunder_h>=oppcar3_y && thunder_y<=oppcar3_y+oppcar3_h))
				{
					iShowImage(oppcar3_x,oppcar3_y,flame_w,flame_h,flame);
					
					c3=false;
					oppcar3_x=1300;
					score+=10;

				}
				
			//for 4th car crash
			 if((thunder_x+thunder_w>=oppcar4_x && thunder_x<=oppcar4_x+oppcar4_w) && (thunder_y+thunder_h>=oppcar4_y && thunder_y<=oppcar4_y+oppcar4_h))
				{
					iShowImage(oppcar4_x,oppcar4_y,flame_w,flame_h,flame);
					
					c4=false;
					oppcar4_x=1000;
					score+=10;
				}
			
		}
}

//End crash with thunder function


//crash with player car function
void mycarcrash()
{

	//for 1st car crash
		if((mycar_x+mycar_w>=oppcar1_x && mycar_x<=oppcar1_x+oppcar1_w) && (mycar_y+35>=oppcar1_y && mycar_y<=oppcar1_y+oppcar1_h))
			{
				iShowImage(flame_x,flame_y,flame_w,flame_h,flame);
				
				oppcar2_x=1700;
				score-=20;
				life+=50;
				c1=false;
				
			}

		//for 2nd car crash
			if((mycar_x+mycar_w>=oppcar2_x && mycar_x<=oppcar2_x+oppcar2_w) && (mycar_y+35>=oppcar2_y && mycar_y<=oppcar2_y+oppcar2_h))
		
			{
					iShowImage(oppcar2_x,oppcar2_y,flame_w,flame_h,flame);
					
					c2=false;
					oppcar2_x=1600;
					score-=20;
					life+=50;

				}

		//for 3rd car crash
			if((mycar_x+mycar_w>=oppcar3_x && mycar_x<=oppcar3_x+oppcar3_w) && (mycar_y+35>=oppcar3_y && mycar_y<=oppcar3_y+oppcar3_h))
		
			{
					iShowImage(oppcar3_x,oppcar3_y,flame_w,flame_h,flame);
					
					c3=false;
					oppcar3_x=1300;
					score-=20;
					life+=50;

				}
				
			
		//for 4th car crash
			 if((mycar_x+mycar_w>=oppcar4_x && mycar_x<=oppcar4_x+oppcar4_w) && (mycar_y+35>=oppcar4_y && mycar_y<=oppcar4_y+oppcar4_h))
		
			 {
					iShowImage(oppcar4_x,oppcar4_y,flame_w,flame_h,flame);
					
					c4=false;
					oppcar4_x=1000;
					score-=20;
					life+=50;
				}
}

//End of crash with player car function


//Start of function for score store in file
void store_score()

{
	FILE *fp=fopen("Score.txt","a");
	if(fp!=NULL)
	{
		fprintf(fp," %d\n",score);
	}
	fclose(fp);
}
//End of function for score store in file


//End of function for highscore
void show_Score()
{
	FILE *fpr=fopen("Score.txt","r");
	if(fpr==NULL)
	{
		printf("\nFile not found!\n");
	}
else
{	

	int y;
	int highs=0;
	char Highscore[20];


while(fscanf(fpr,"%d",&y)!=EOF)
{	
	if(y>=highs)
	{
		highs=y;

	}
}

	itoa(highs,Highscore,10);
	iSetColor(0, 0, 0);
	iText(60, 375, Highscore , GLUT_BITMAP_TIMES_ROMAN_24);

	}
fclose(fpr);
}
//End of function for highscore


//function for gameover page sound
void game_oversound()            
{
	if (gamestate == 7)           //gamestate for set gameover sound
	{

		if (musicOn)
		{
			music2On = true;
		}
		if (musicOn == false)
		{
			music2On = false;
		}
		if (music2On)
		{
			PlaySound("Music\\game over.wav", NULL, SND_LOOP | SND_ASYNC);
		}
		else
		{
			PlaySound(0, 0, 0);
		}
			gamestate = 2;
	}
}
//End of function for gameover page sound

 // Start function for Game over + life
void carmiss()
{

	if(life>=100)
			
	{
		gamestate=2;                         //game over state
		iPauseTimer(backchange);             //stop background move
		iPauseTimer(carchange);              //stop car move
		iPauseTimer(thunderchange);          //stop thunder move
		
		//to make false level to back main menu from game over page
		level1=false;                          
		level2=false;
		level3=false;
		gamestate = 7;                       //gamestate for set gameover sound 
		game_oversound();                    //function for gameover page sound
	}
}

 //function for Game over + life

// start of the function for all level
void levelshow()
{

		//start of all background image show

		iShowImage(sky1_x,sky1_y,sky1_w,sky1_h,sky1);                                   
		iShowImage(mountainbc_x,mountainbc_y,mountainbc_w,mountainbc_h,mountainbc1);    

		iShowImage(mountain1_x,mountain1_y,mountain1_w,mountain1_h,mountain1);          
		iShowImage(mountain2_x,mountain2_y,mountain2_w,mountain2_h,mountain2);

		iShowImage(field1_x,field1_y,field1_w,field1_h,field1);
		iShowImage(field2_x,field2_y,field2_w,field2_h,field2);
		iShowImage(bc1_x,bc1_y,bc1_w,bc1_h,bc1);                     //for 1st background
		iShowImage(bc2_x,bc2_y,bc2_w,bc2_h,bc2);                     //for 2nd background
		iShowImage(bc3_x,bc3_y,bc3_w,bc3_h,bc3);                     //for 3rd background
	

		iShowImage(tree1_x,tree1_y,tree1_w,tree1_h,tree1);
		iShowImage(tree2_x,tree2_y,tree2_w,tree2_h,tree2);

		//End of all background image show

		iShowImage(mycar_x,mycar_y,mycar_w,mycar_h,image6);        //for player car image show
		
		
		iShowImage(thunder_x,thunder_y,thunder_w,thunder_h,thunder);    //for thunder image show
		if(thunder_x>4000)
		{
			iShowImage(flashlogo_x,flashlogo_y,flashlogo_w,flashlogo_h,flashlogo);      //for super power flash logo image show
		}
		

		//Start of all image for opponent car show

		iShowImage(oppcar1_x,oppcar1_y,oppcar1_w,oppcar1_h,car1);
		iShowImage(oppcar2_x,oppcar2_y,oppcar2_w,oppcar2_h,car2);
		iShowImage(oppcar3_x,oppcar3_y,oppcar3_w,oppcar3_h,car3);
		iShowImage(oppcar4_x,oppcar4_y,oppcar4_w,oppcar4_h,car4);

		//End of all image for opponent car show
		
		collisioncheck1();                     //crash with bomb function
		th_crash();                            //crash with thunder function
		mycarcrash();                          //crash with player car  function
		
		gbombmovement();                       //function for bomb move
		

		iSetColor(0,0,0);
		itoa(score,score2,10);
		iText(30,560,"Score: ",GLUT_BITMAP_TIMES_ROMAN_24);  //for 'Score' print on gameplay 
		iText(100,560,score2,GLUT_BITMAP_TIMES_ROMAN_24);     //for updating player 'Score' by score2 variables
		 
		iSetColor(0,255,0);
		iFilledRectangle(300,560,100,20);  //for showing player score 

		iSetColor(255,0,0);
		iFilledRectangle(300,560,life,20);  //for showing life 
		
		carmiss();                           //function for Game over + life


}
// End of the function for all level


//Start of restart funtion 
void restart()
{

	if(gamestate==0)
	{
		iSetColor(255,255,255);
		iShowImage(hmscrn_x,hmscrn_y,hmscrn_w,hmscrn_h,image1);
	
	}
	

	if(gamestate==1)
	{
		iSetColor(255,255,255);
		iShowImage(levelscrn_x,levelscrn_y,levelscrn_w,levelscrn_h,image2);
		menubutton();
	
	}

	
	

	if(level==1  &&  level1 ==true)
	{
		

		levelshow();


	}

	if(level==2 && level2 ==true)
	{
		levelshow();
	
	}

	if(level==3  && level3 ==true)
	{
		levelshow();

	}

	

	if(gamestate==2)
	{
		iSetColor(255,255,255);
		iShowImage(gmover_up_x,gmover_up_y,gmover_up_w,gmover_up_h,image5);
		menubutton();
		store_score();
		level1=false;
			level2=false;
			level3=false;

	}
	if(gamestate==3)
	{
		iShowImage(hscore_x,hscore_y,hscore_w,hscore_h,image14);
		iSetColor(255,255,255);
		iFilledRectangle(15,350,150,50);
		iSetColor(0,0,0);
		
		menubutton();
		show_Score();

	}
	if(gamestate==4)
	{
		iShowImage(aboutus_x,aboutus_y,aboutus_w,aboutus_h,image15);
		menubutton();
	}

	if(gamestate==5 && res_img==true )
	{
	
		resume_image();
	}
}
//End of retart function(DN);


void iDraw()
{
	iClear();
	


	

	if(gamestate==0)                                  //gamestate for home screen
	{
		iSetColor(255,255,255);
		iShowImage(hmscrn_x,hmscrn_y,hmscrn_w,hmscrn_h,image1);
		
	
	}
	

	if(gamestate==1)                             //gamestate for level choose screen 
	{
		iSetColor(255,255,255);
		iShowImage(levelscrn_x,levelscrn_y,levelscrn_w,levelscrn_h,image2);
		menubutton();
	
	}

	
	

	if(level==1  &&  level1 ==true)                   //for easy level game
	{
		

		levelshow();
		speed_oop=5;

	}

	if(level==2 && level2 ==true)                    //for medium level game
	{
		levelshow();
		speed_oop=10;
	
	}

	if(level==3  && level3 ==true)                  //for hard level game
	{
		levelshow();
		speed_oop=12;

	}

	

	if(gamestate==2)                               //gamestate for gameoover
	{
		iSetColor(255,255,255);
		iShowImage(gmover_up_x,gmover_up_y,gmover_up_w,gmover_up_h,image5);
		menubutton();
		store_score();
		

	}
	if(gamestate==3)                                     //gamestate for high score
	{
		iShowImage(hscore_x,hscore_y,hscore_w,hscore_h,image14);
		iSetColor(255,255,255);
		iFilledRectangle(15,350,150,50);
		iSetColor(0,0,0);
		
		menubutton();
		show_Score();

	}
	if(gamestate==4)                             //gamestate for about us
	{
		iShowImage(aboutus_x,aboutus_y,aboutus_w,aboutus_h,image15);
		menubutton();
	}

	if(gamestate==5 && res_img==true )          //gamestate for pause and resume              
	{
	
		resume_image();
	}
	

	if(gamestate == 6)     //restart the game from gameover page(DN)
	{	
		restart();
	}

	

}
	

/*
 function iMouseMove() is called when the user presses and drags the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouseMove(int mx, int my)
{
	printf("x = %d, y= %d\n", mx, my);
}

/*
 function iMouse() is called when the user presses/releases the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(mx>=5 && mx<=180 && my<=470 && my>=350 && gamestate == 0)    //mouse point for go to levelscreen
		{
			gamestate=1;

			level1=false;
			level2=false;
			level3=false;
		}
		if(mx>=5 && mx<=285 && my<=320 && my>290 && gamestate == 0)     //mouse point for go to highscore page
		{
			gamestate=3;
			
		}
		if(mx>=5 && mx<=285 && my<=170 && my>90 && gamestate == 0)       //mouse point for go to about us page
		{
			gamestate=4;
			
		}

		if(mx>=5 && mx<=80 && my<=390 && my>360&& gamestate==1  )         //mouse point for level 1
		{
			

			level1 =true;
			level=1;
			


		    //only level music is true
			if (music3On)
			{
				musicOn = true;
			}
			if (music3On == false)
			{
				musicOn = false;
			}
			if (musicOn)
			{
				PlaySound("Music\\NFS Most Wanted 2 for game.wav", NULL, SND_LOOP | SND_ASYNC);
			}
			else
			{
				PlaySound(0, 0, 0);
			}
			
		}

		if(mx>=5 && mx<=80 && my<=350 && my>320&& gamestate==1)   //mouse point for level 2
		{
			level2 =true;
			level=2;
			
			//only level music is true
			if (music3On)
			{
				musicOn = true;
			}
			if (music3On == false)
			{
				musicOn = false;
			}
			if (musicOn)
			{
				PlaySound("Music\\NFS Most Wanted 2 for game.wav", NULL, SND_LOOP | SND_ASYNC);
			}
			else
			{
				PlaySound(0, 0, 0);
			}
		}
		if(mx>=5 && mx<=80 && my<=315 && my>270 && gamestate==1)    //mouse point for level 3
		{
			level3 =true;
			level=3;
			
			//only level music is true
			if (music3On)
			{
				musicOn = true;
			}
			if (music3On == false)
			{
				musicOn = false;
			}
			if (musicOn)
			{
				PlaySound("Music\\NFS Most Wanted 2 for game.wav", NULL, SND_LOOP | SND_ASYNC);
			}
			else
			{
				PlaySound(0, 0, 0);
			}
		}

		if(mx>=13 && mx <=65 && my>=565 && my<=590 && gamestate == 1 )   //back to main from level screen.
		{

			gamestate = 0;
			
			
		}

		
		if(mx>=13 && mx <=65 && my>=565 && my<=590 && gamestate == 2 )   //back to main from gameover screen.
		{

			gamestate = 0;
			if (musicOn)
			{
				music3On = true;
			}
			if (musicOn == false)
			{
				music3On = false;
			}
			if (music3On)
			{
				PlaySound("Music\\Black Hawk Down(inGame).wav", NULL, SND_LOOP | SND_ASYNC);
			}
			else
			{
				PlaySound(0, 0, 0);
			}
		}
		if(mx>=13 && mx <=65 && my>=565 && my<=590 && gamestate == 3 )   //back to main from highscore screen.
		{

			gamestate = 0;
		}
		if(mx>=13 && mx <=65 && my>=565 && my<=590 && gamestate == 4 )   //back to main from abuotus  screen.
		{

			gamestate = 0;
		}

		if(((mx>=13 && mx <=65 && my>=565 && my<=590) && gamestate == 2)  )     //back to main menu from gameover page.
		{
		
			gamestate = 0;
			if (musicOn)
			{
				music3On = true;
			}
			if (musicOn == false)
			{
				music3On = false;
			}
			if (music3On)
			{
				PlaySound("Music\\Black Hawk Down(inGame).wav", NULL, SND_LOOP | SND_ASYNC);
			}
			else
			{
				PlaySound(0, 0, 0);
			}
			
		}

		if(mx>=70 && mx<=1150 && my>=210 && my<=300 && gamestate==5)   //mouse point for back main menu
		{
			
			gamestate=0;
			level1=false;
			level2=false;
			level3=false;
			

		}
		
		
		if(mx>=70 && mx<=1150 && my>=350 && my<=480 && gamestate==5)            //mouse ponit for resume
		{
			res_img=false;
			iResumeTimer(0);
			iResumeTimer(carchange);
			if (music3On)
			{
				musicOn = true;
			}
			if (music3On == false)
			{
			musicOn = false;
			}
			if (musicOn)
			{
				PlaySound("Music\\NFS Most Wanted 2 for game.wav", NULL, SND_LOOP | SND_ASYNC);
			}
			else
			{
				PlaySound(0, 0, 0);
			}
		}
		
		}	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}

}

/*
 function iKeyboard() is called whenever the user hits a key in keyboard.
 key- holds the ASCII value of the key pressed.
 */
void iKeyboard(unsigned char key)
{
	if (key == 'a')                 //restart the game from gameover page(DN)
	{
		if(gamestate == 2)
	
		gamestate = 6;
	}

	if (key == 'q')                  //button for direct gameover
	{
		gamestate=2;
		iPauseTimer(0);
		iPauseTimer(carchange);
	}

	if (thunder_x>4000)              //button for movement and reinitiate for SUPER POWER.
	{
		thunder_x=4800;
		if(key == 's')
		{
			th_show=true;
			thunder_x=70;
			for(thunder_x=70;thunder_x>=4000;)
			{
				thunder_x+=5;
				if(thunder_x>=700)
				{
				
					th_show=false;
				}
			}
		}
	}

	if(key=='f')                               //button for reinitiate for bomb
	{
		gbomb[k].gbombshow=true;
		gbomb[k].isBombActive = true;
		k++;
		if(k==500)
		{
			k=0;
		}
	}

	if(key=='r')                             //button for pause and resume
	{
		gamestate=5;
		iPauseTimer(0);
		iPauseTimer(carchange);
		res_img=true;

		if (musicOn)
		{
			music3On = true;
		}
		if (musicOn == false)
		{
			music3On = false;
		}
		if (music3On)
		{
			PlaySound("Music\\Black Hawk Down(inGame).wav", NULL, SND_LOOP | SND_ASYNC);
		}
		else
		{
			PlaySound(0, 0, 0);
		}
		
	}
	

}
	
	
	
	
	
	
	//place your codes for other keys here


/*
 function iSpecialKeyboard() is called whenver user hits special keys like-
 function keys, home, end, pg up, pg down, arraows etc. you have to use
 appropriate constants to detect them. A list is:
 GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
 GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
 GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
 GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
 */
void iSpecialKeyboard(unsigned char key)
{

	//same music for different gamestate
	if (gamestate == 0 || gamestate == 1  || gamestate == 3 || gamestate == 4 || gamestate == 5 || gamestate == 6)
	{
		if (music3On)
		{
			music3On = false;
			PlaySound(0, 0, 0);
		}
		else
		{
			music3On = true;
			PlaySound("Music\\Black Hawk Down(inGame).wav", NULL, SND_LOOP | SND_ASYNC);
		}
	}

	//same music for different level
	if(level ==1 || level ==2 || level ==3)
	{
		if (music3On)
		{
			music3On = false;
			PlaySound(0, 0, 0);
		}
		else
		{
			music3On = true;
			PlaySound("Music\\NFS Most Wanted 2 for game.wav", NULL, SND_LOOP | SND_ASYNC);
		}
	}

	if(key == GLUT_KEY_UP)
		
	{
		
		mycar_y+=10;       //movement for gamer player car with up button.
		

		if(mycar_y>=140)
		{
			mycar_y=140;
		}

		setgbomb();        //reinitiate bomb position.
		
		
		
	}
	
	if(key == GLUT_KEY_DOWN)
	{
		
		mycar_y-=10;             //movement for gamer player car with down button.
		
		if(mycar_y<0)
		{
			mycar_y=0;
		}
		
		setgbomb();              //reinitiate bomb position
		
		
		
		
		
	}
	if(key == GLUT_KEY_RIGHT)
	{
		
		
	}
	if(key == GLUT_KEY_LEFT)
	{
		
		
	}

	//music for different gamestate
	if (gamestate == 0 || gamestate == 1 || gamestate == 3 || gamestate == 4 || gamestate == 5)
	{
		if(key == GLUT_KEY_F6)
		{
			if (music3On)
			{
				music3On = false;
				PlaySound(0, 0, 0);
			}
			else
			{
				music3On = true;
				PlaySound("Music\\Black Hawk Down(inGame).wav", NULL, SND_LOOP | SND_ASYNC);
			}
		}
	}

	//same music for different level
	if (level == 1 || level == 2 || level == 3)
	{
		if(key == GLUT_KEY_F6)
		{
			if (musicOn)
			{
				musicOn = false;
				PlaySound(0, 0, 0);
			}
			else
			{
				musicOn = true;
				PlaySound("Music\\NFS Most Wanted 2 for game.wav", NULL, SND_LOOP | SND_ASYNC);
			}
		}
	}
	

}


void th_change()    //funtion for rendering super power.
{
	thunder_x+=7;

	
}





int main()
{
	
	backchange=iSetTimer(2,bc_change);             //Timer for background move
	thunderchange=iSetTimer(2,th_change);          //Timer for thunder move 
	carchange=iSetTimer(20,change);                //Timer for opponent car move
	gamer_bomb=iSetTimer(5,gbombpositionchange);   //Timer for bomb move

	

	iInitialize(scrn_h,scrn_w ,"game");

	
	image1=iLoadImage("img\\home scrn.png");           //image for home page
	image2=iLoadImage("img\\level_instruct.png");      //image for level choose page
	image5=iLoadImage("img\\gameoverpage.png");        //image for game over page
	image6=iLoadImage("img\\car+man.png");             //image for player car
	
	//image for all oponent car

	car1=iLoadImage("img\\oppcar1.png");
	car2=iLoadImage("img\\oppcar2.png");
	car3=iLoadImage("img\\oppcar3.png");
	car4=iLoadImage("img\\oppcar4.png");
	
	//End of image for all oponent car

	image14=iLoadImage("img\\highscorepage.png");     //image for highscore page
	image15=iLoadImage("img\\aboutus.png");           //image for about us page
	
	resmenu=iLoadImage("img\\resmenu.png");           //image for resume image
	

	
	//All image for full background 

	sky1=iLoadImage("img\\sky1.png");
	bc1=iLoadImage("img\\new bc201.png");
	mountain1=iLoadImage("img\\mountains22.png");
	bc2=iLoadImage("img\\new bc201.png");
	bc3=iLoadImage("img\\new bc201.png");
	mountain2=iLoadImage("img\\mountains22.png");
	tree1=iLoadImage("img\\tree1.png");
	tree2=iLoadImage("img\\tree2.png");
	mountainbc1=iLoadImage("img\\backforest2.png");
	field1=iLoadImage("img\\new bc2021.png");
	field2=iLoadImage("img\\new bc2021.png");
	
	//End of all image load for background

	thunder=iLoadImage("img\\thunder1.png");                //image for thunder
	flashlogo=iLoadImage("img\\flashlogo.png");             //image for flash logo
	
	flame=iLoadImage("img\\flame.png");                     //image for crash time flame

	bomb=iLoadImage("img\\blue bulet.png");                 //image for bomb
	
	setgbomb();                                             // function for bomb initial position
	
	

	//sound for menu and other page before game start
	if(music3On)
	{
		PlaySound("Music\\Black Hawk Down(inGame).wav", NULL, SND_LOOP | SND_ASYNC);      
	}

	iStart();
	return 0;
}
