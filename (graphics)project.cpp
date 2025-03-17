#include <cstdio>
#include <GL/gl.h>
//Computer graphics(2D animation)//
//teamamte: Farjana haque Chamok,Kausik Roy,Debabrata Roy
//ID:201-15-13850,201-15-14102,201-15-13942



#include <iostream>
#include <GL/glut.h>
#include <math.h>
#include <windows.h>
using namespace std;


int sunstatus=0,cloudstatus=1,waterstatus=1,cyclestatus=1,humanstatus=1,rainstatus=0,birdstatus=1,start=0;
float sunX=0,sunY=0,cloudX=0,cloudY=0,waterX=0,waterY=0,cycleX=0,cycleY=0,humanX=0,humanY=0,rainX=0,rainY=0,birdsX=0,birdsY=0;
int day=1;
void init(void)
{
  glClearColor(0.0,0.0,0.0,0.0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers
  glMatrixMode(GL_PROJECTION);  // To specify which matrix is the current matrix & projection applies subsequent matrix to projecton matrix stack
  glLoadIdentity();


}
//////draw circle starts//////
 void DrawCircle(float cx, float cy, float r, int num_segments)
 {

	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < num_segments; i++)
	{
		float angle = 2.0f * 3.1415926f * float(i) / float(num_segments);//get current angle

		float x = r * cosf(angle);//calculate x
		float y = r * sinf(angle);//calculate y

		glVertex2f(x + cx, y + cy);//output vertex

	}
	glEnd();
	glFlush();
}
//////draw circle ends///////
///////move wave & boat////////
void movewater()
{
    if (waterstatus ==1)
    {
        waterX += 1;
    }
    if (waterX>680)
    {
        waterX = -500;
        waterY = 0;

    }
}
///////move wave & boat ends////////
////clouds//////
void clouds() {
    glColor3ub(200, 220, 220);
	DrawCircle(100, 360, 25, 1000);
	DrawCircle(130, 360, 35, 1000);
	DrawCircle(160, 360, 25, 1000);

    glColor3ub(200, 220, 220);
	DrawCircle(170, 400, 15, 2000);
	DrawCircle(200, 400, 25, 2000);
	DrawCircle(230, 400, 15, 2000);

glColor3ub(200, 220, 220);
	DrawCircle(300, 420, 25, 2000);
	DrawCircle(330, 420, 35, 2000);
	DrawCircle(360, 420, 25, 2000);

    glColor3ub(200, 220, 220);
	DrawCircle(400, 400, 25, 2000);
	DrawCircle(430, 400, 35, 2000);
	DrawCircle(460, 400, 25, 2000);


	glColor3ub(200, 220, 220);
	DrawCircle(600, 400, 25, 2000);
	DrawCircle(630, 400, 35, 2000);
	DrawCircle(660, 400, 25, 2000);
	glFlush();
}
/////clouds/////
//////hills/////
void hills(int x,int y,int z)
{


    glColor3f(0,1,0);
    glBegin(GL_TRIANGLES);
    glVertex2i(80, 255);
    glVertex2i(120, 290);
    glVertex2i(160, 255);
    glEnd();



    glColor3f(0,1,0);
    glBegin(GL_TRIANGLES);
    glVertex2i(140, 255);
    glVertex2i(170, 280);
    glVertex2i(200, 255);
    glEnd();

    glColor3f(0,1,0);
    glBegin(GL_TRIANGLES);
    glVertex2i(180, 255);
    glVertex2i(270, 320);
    glVertex2i(360, 255);
    glEnd();




     glColor3f(0,1,0);
    glBegin(GL_TRIANGLES);
    glVertex2i(260, 255);
    glVertex2i(320, 300);
    glVertex2i(380, 255);
    glEnd();

    glColor3f(0,1,0);
    glBegin(GL_TRIANGLES);
    glVertex2i(370, 255);
    glVertex2i(420, 275);
    glVertex2i(470, 255);

    glEnd();



    glColor3f(0,1,0);
    glBegin(GL_TRIANGLES);
    glVertex2i(430, 255);
    glVertex2i(500, 275);
    glVertex2i(570, 255);

    glEnd();

     glColor3f(0,1,0);
    glBegin(GL_TRIANGLES);
    glVertex2i(565, 255);
    glVertex2i(595, 275);
    glVertex2i(625, 255);

    glEnd();
    glColor3f(0,1,0);
    glBegin(GL_TRIANGLES);
    glVertex2i(620, 255);
    glVertex2i(640, 275);
    glVertex2i(660, 255);

    glEnd();
    glFlush();
}
//////////

////////move clouds///

void movecloud()
{
	if (cloudstatus == 1)
        {
            cloudX +=0.3;
        }
	if (cloudX>680)
        {
            cloudX = -500;
            cloudY =0;
        }
}
/////////this side tree/////////////
void trees()
{
    //////////////////////////////////////pata
   glColor3ub(139,69,19);
    DrawCircle(50, 280, 50, 2000);//1
    DrawCircle(50, 320, 35, 3000);//1

    glEnd();
    glFlush();
    ////////////////////////////////majher daal
    glColor3ub (180, 180, 40);
    glBegin(GL_QUADS);
    glVertex2i(40, 155);
    glVertex2i(60, 155);
    glVertex2i(60, 245);
    glVertex2i(40, 245);
    glEnd();
    //////////////////////////////////bam daal
    glColor3ub (180, 180, 40);
    glBegin(GL_QUADS);
    glVertex2i(40, 245);
    glVertex2i(50, 245);
    glVertex2i(40, 270);
    glVertex2i(30, 270);
    glEnd();
    /////////////////////////////////right daal
    glColor3ub (180, 180, 40);
    glBegin(GL_QUADS);
    glVertex2i(50, 245);
    glVertex2i(60, 245);
    glVertex2i(70, 270);
    glVertex2i(60, 270);
    glEnd();
    glFlush();
/////tree shadow
    glColor3ub (79, 214, 72);
    glBegin(GL_QUADS);
    glVertex2i(15, 120);
    glVertex2i(35, 120);
    glVertex2i(55, 155);
    glVertex2i(40, 155);
    glEnd();

    glColor3ub (79, 214, 72);
    DrawCircle(20,100,30,1000);
    glEnd();

}

////////////rivers opposite side village/////////
void oposite_village(int x,int y,int z)
{
    //////////////////////tree 1st/////
    glColor3ub (148, 124, 84);
    glBegin(GL_LINES);
    glVertex2i(110, 255);
    glVertex2i(110, 270);
    glEnd();

    //glColor3ub (51, 204, 51);
    glColor3ub (x, y, z);
    DrawCircle(110, 270, 5, 5000);//1
    DrawCircle(110, 274, 3, 5000);//1
    glEnd();
    glFlush();
        //////////////////////tree 2nd////
    glColor3ub (148, 124, 84);
    glBegin(GL_LINES);
    glVertex2i(200, 255);
    glVertex2i(200, 270);
    glEnd();

    //glColor3ub (51, 204, 51);
    glColor3ub (x, y, z);
    DrawCircle(200, 270, 5, 5000);//1
    DrawCircle(200, 274, 3, 5000);//1
    glEnd();
    glFlush();
    //////////////////////tree 3rd//////
    glColor3ub (148, 124, 84);
    glBegin(GL_LINES);
    glVertex2i(250, 255);
    glVertex2i(250, 275);
    glEnd();

    //glColor3ub (51, 204, 51);
    glColor3ub (x, y, z);
    DrawCircle(250, 275, 5, 5000);
    DrawCircle(250, 279, 3, 6000);
    glEnd();
    glFlush();
    ///////////////////////tree 4th///////
    glColor3ub (148, 124, 84);
    glBegin(GL_LINES);
    glVertex2i(270, 255);
    glVertex2i(270, 275);
    glEnd();

   // glColor3ub (51, 204, 51);
   glColor3ub (x, y, z);
    DrawCircle(270, 275, 5, 5000);//1
    DrawCircle(270, 279, 3, 6000);//1
    glEnd();
    glFlush();
    ///////////////////////////tree 5th////////
    glColor3ub (148, 124, 84);
    glBegin(GL_LINES);
    glVertex2i(300, 255);
    glVertex2i(300, 275);
    glEnd();

    //glColor3ub (51, 204, 51);
    glColor3ub (x, y, z);
    DrawCircle(300, 275, 5, 6000);
    DrawCircle(300, 279, 3, 6000);
    glEnd();
    glFlush();


}
void wave()
{
        /////wave////////////////
    glColor3ub (169, 242, 242);
    glBegin(GL_LINES);
    glVertex2i(200, 220);
    glVertex2i(220, 220);

    glVertex2i(210, 230);
    glVertex2i(220, 230);

    glVertex2i(300, 220);
    glVertex2i(320, 220);

    glVertex2i(400, 220);
    glVertex2i(420, 220);

    glVertex2i(100, 240);
    glVertex2i(120, 240);

    glVertex2i(150, 180);
    glVertex2i(150, 180);

    glVertex2i(0, 190);
    glVertex2i(10, 190);

    glVertex2i(0, 200);
    glVertex2i(10, 200);

    glVertex2i(30, 185);
    glVertex2i(40, 185);

    glVertex2i(100, 250);
    glVertex2i(125, 250);

    glVertex2i(150,240);
    glVertex2i(165,240);

    glVertex2i(90,200);
    glVertex2i(100,200);

    glVertex2i(300,190);
    glVertex2i(320,190);

    glVertex2i(270,235);
    glVertex2i(275,235);

    glVertex2i(500,200);
    glVertex2i(510,200);

    glVertex2i(600,220);
    glVertex2i(615,220);

    glVertex2i(550,200);
    glVertex2i(555,200);

    glVertex2i(520,225);
    glVertex2i(540,225);

    glVertex2i(370,215);
    glVertex2i(380,215);
    glEnd();
}
/////////////////////boat & wave/////////////////////
void boat_wave()
{
    wave();  ////just wave
    //boat1///
    ///////////////////boat body///////////////////////
    glColor3ub (150, 129, 117);
    glBegin(GL_QUADS);
    glVertex2i(20, 220);
    glVertex2i(60, 220);
    glVertex2i(70, 230);
    glVertex2i(10, 230);
    glEnd();
    /////////////////boat ar oporer part///////////////
    glColor3ub (206, 175, 109);
    glBegin(GL_POLYGON);
    glVertex2i(27, 230);
    glVertex2i(57, 230);
    glVertex2i(57, 240);
    glVertex2i(27, 240);
    glEnd();
    //////////////pal er chera cloths///////
    glColor3ub (209, 102, 27);
    glBegin(GL_TRIANGLES);
    glVertex2i(57, 230);
    glVertex2i(90, 280);
    glVertex2i(50, 290);
    glEnd();
    /////////boat ar pal ar bamboo//////////
    glColor3ub (206, 175, 109);
    glBegin(GL_LINES);
    glVertex2i(57, 230);
    glVertex2i(73, 290);
    glEnd();
    ///////////////boat shadow////////////
    glColor3ub (149, 187, 198);
    glBegin(GL_QUADS);
    glVertex2i(15, 210);
    glVertex2i(55, 210);
    glVertex2i(60, 220);
    glVertex2i(20, 220);
    glEnd();

    //boat2//
    glColor3ub (150, 129, 117);
    glBegin(GL_QUADS);
    glVertex2i(100, 220);
    glVertex2i(140, 220);
    glVertex2i(150, 230);
    glVertex2i(90, 230);
    glEnd();
    /////////////////boat ar oporer part///////////////
    glColor3ub (206, 175, 109);
    glBegin(GL_POLYGON);
    glVertex2i(107, 230);
    glVertex2i(137, 230);
    glVertex2i(137, 240);
    glVertex2i(107, 240);
    glEnd();
    //////////////pal er chera cloths///////
    glColor3ub (102, 102, 700);
    glBegin(GL_TRIANGLES);
    glVertex2i(137, 230);
    glVertex2i(180, 280);
    glVertex2i(130, 290);
    glEnd();
    /////////boat ar pal ar bamboo//////////
    glColor3ub (206, 175, 109);
    glBegin(GL_LINES);
    glVertex2i(137, 230);
    glVertex2i(153, 290);
    glEnd();
    ///////////////boat shadow////////////
    glColor3ub (149, 187, 198);
    glBegin(GL_QUADS);
    glVertex2i(95, 210);
    glVertex2i(135, 210);
    glVertex2i(140, 220);
    glVertex2i(100, 220);
    glEnd();
}
///////////////////////////water////////////
void water(int x,int y,int z)
{
    glColor3ub(30,144,255);
    glBegin(GL_QUADS);
    glVertex2i(0, 180);
    glVertex2i(640, 180);
    glVertex2i(640, 255);
    glVertex2i(0, 255);
    glEnd();
}
void line()
{
    glColor3ub (153, 153, 102);
    glBegin(GL_QUADS);
    glVertex2i(0, 50);
    glVertex2i(640, 50);
    glVertex2i(640, 60);
    glVertex2i(0, 60);
    glEnd();
}
////////land//////
void land(int x,int y,int z)
{
    glColor3ub (x,y,z);
    glBegin(GL_QUADS);
    glVertex2i(0, 0);
    glVertex2i(640, 0);
    glVertex2i(640, 180);
    glVertex2i(0, 180);
    glEnd();
}
///////land ends////////
///////tree///////////
void tree(int x,int y,int z)
{
    //////////leaf///////////
    glColor3ub(x,y,z);
    DrawCircle(65,280,50,2000);
    DrawCircle(40,280,50,2000);
    DrawCircle(50,320,50,2000);
    //////////leaf ends///////////
    glColor3ub (180, 180, 40);////main guri
    glBegin(GL_QUADS);
    glVertex2i(40, 155);
    glVertex2i(60, 155);
    glVertex2i(60, 245);
    glVertex2i(40, 245);
    glEnd();
    ////////left///////////////////////////
    glColor3ub (180, 180, 40);
    glBegin(GL_QUADS);
    glVertex2i(40, 245);
    glVertex2i(50, 245);
    glVertex2i(40, 270);
    glVertex2i(30, 270);
    glEnd();
    ///////right /////////
    glColor3ub (180, 180, 40);
    glBegin(GL_QUADS);
    glVertex2i(50, 245);
    glVertex2i(60, 245);
    glVertex2i(70, 270);
    glVertex2i(60, 270);
    glEnd();
    glFlush();
}
////////tree ends/////

////////road////////////
void road(int x,int y,int z)
{
    glColor3ub (x,y,z);
    glBegin(GL_POLYGON);
    glVertex2i(0, 60);
    glVertex2i(640, 100);
    glVertex2i(640, 175);
    glVertex2i(0, 100);
    glEnd();

    //grass flower1
    glColor3ub (0,100,0);
    glBegin(GL_LINES);
    glVertex2i(525,100);//middle
    glVertex2i(525,107);
    glVertex2i(525,100);//left
    glVertex2i(530,105);
    glVertex2i(525,100);//right
    glVertex2i(520,105);
    glVertex2i(525,100);//ground left
    glVertex2i(520,101);
    glVertex2i(525,100);//ground right
    glVertex2i(530,101);
    glEnd();
    glColor3ub (139,0,0);
    DrawCircle(525,107,1,5);
    DrawCircle(530,105,1,5);
    DrawCircle(520,105,1,5);
    glEnd();
    //grass flower2
    glColor3ub (0,100,0);
    glBegin(GL_LINES);
    glVertex2i(600,150);//middle
    glVertex2i(600,157);
    glVertex2i(600,150);//left
    glVertex2i(595,155);
    glVertex2i(600,150);//right
    glVertex2i(605,155);
    glVertex2i(600,150);//ground left
    glVertex2i(595,151);
    glVertex2i(600,150);//ground right
    glVertex2i(605,151);
    glEnd();
    glColor3ub (139,0,0);
    DrawCircle(600,157,1,5);
    DrawCircle(595,155,1,5);
    DrawCircle(605,155,1,5);
    glEnd();
     //grass flower3
    glColor3ub (0,100,0);
    glBegin(GL_LINES);
    glVertex2i(225,100);//middle
    glVertex2i(225,107);
    glVertex2i(225,100);//left
    glVertex2i(220,105);
    glVertex2i(225,100);//right
    glVertex2i(230,105);
    glVertex2i(225,100);//ground left
    glVertex2i(220,101);
    glVertex2i(225,100);//ground right
    glVertex2i(230,101);
    glEnd();
    glColor3ub (139,0,0);
    DrawCircle(225,107,1,5);
    DrawCircle(220,105,1,5);
    DrawCircle(230,105,1,5);
    glEnd();
    //grass flower4
    glColor3ub (0,100,0);
    glBegin(GL_LINES);
    glVertex2i(375,100);//middle
    glVertex2i(375,107);
    glVertex2i(375,100);//left
    glVertex2i(370,105);
    glVertex2i(375,100);//right
    glVertex2i(380,105);
    glVertex2i(375,100);//ground left
    glVertex2i(370,101);
    glVertex2i(375,100);//ground right
    glVertex2i(380,101);
    glEnd();
    glColor3ub (139,0,0);
    DrawCircle(375,107,1,5);
    DrawCircle(370,105,1,5);
    DrawCircle(380,105,1,5);
    glEnd();
    //grass flower5
    glColor3ub (0,100,0);
    glBegin(GL_LINES);
    glVertex2i(50,75);//middle
    glVertex2i(50,82);
    glVertex2i(50,75);//left
    glVertex2i(45,80);
    glVertex2i(50,75);//right
    glVertex2i(55,80);
    glVertex2i(50,75);//ground left
    glVertex2i(45,76);
    glVertex2i(50,75);//ground right
    glVertex2i(55,76);
    glEnd();
    glColor3ub (139,0,0);
    DrawCircle(50,82,1,5);
    DrawCircle(45,80,1,5);
    DrawCircle(55,80,1,5);
    glEnd();
}

////////road ends////////

/////////flower starts///////////
void flower()
{
     //flower 1
    glColor3ub (0,100,0);
    glBegin(GL_QUADS);//branch
    glVertex2i(24,45);
    glVertex2i(24,0);
    glVertex2i(26,0);
    glVertex2i(26,45);
    glEnd();
    glColor3ub (139,69,19);//petals
    DrawCircle(25,45, 4, 15);
    glColor3ub (255,255,0);
    DrawCircle(26,49, 4.5, 15);
    glEnd();
    glColor3ub (0,100,0);
    glBegin(GL_TRIANGLES);//leaf1
    glVertex2i(25,30);
    glVertex2i(25,25);
    glVertex2i(30,33);
    glBegin(GL_TRIANGLES);//leaf2
    glVertex2i(25,20);
    glVertex2i(20,30);
    glVertex2i(25,15);
    glEnd();
    //flower 2
    glColor3ub (0,100,0);
    glBegin(GL_QUADS);//branch
    glVertex2i(47,46);
    glVertex2i(47,0);
    glVertex2i(49,0);
    glVertex2i(49,46);
    glEnd();
    glColor3ub (139,69,19);//petals
    DrawCircle(48,49, 4, 15);
    glColor3ub (255,255,0);
    DrawCircle(52,50, 3., 10);
    DrawCircle(50,52, 3., 10);
    DrawCircle(48,50, 3., 10);
    DrawCircle(45,51, 3., 10);
    glEnd();
    glColor3ub (0,100,0);
    glBegin(GL_TRIANGLES);//leaf1
    glVertex2i(42,40);
    glVertex2i(47,25);
    glVertex2i(47,30);
    glEnd();
    //flower 3
    glColor3ub (0,100,0);
    glBegin(GL_QUADS);//branch main
    glVertex2i(82,48);
    glVertex2i(82,0);
    glVertex2i(83,0);
    glVertex2i(83,48);
    glEnd();
    glColor3ub (139,69,19);//petals
    DrawCircle(83,48, 5, 15);
    glEnd();
    glColor3ub (255,255,0);//petals
    DrawCircle(83,53, 3, 5);
    DrawCircle(80,50, 3, 5);
    glEnd();
    glColor3ub (0,100,0);
    glBegin(GL_TRIANGLES);//leaf1
    glVertex2i(83,35);
    glVertex2i(83,30);
    glVertex2i(90,45);
    glEnd();



    //flower 4
    glColor3ub (0,100,0);
    glBegin(GL_QUADS);//branch main
    glVertex2i(118,50);
    glVertex2i(118,0);
    glVertex2i(119,0);
    glVertex2i(119,50);
    glEnd();
    glColor3ub (139,69,19);//petals
    DrawCircle(117,55, 5, 15);
    glEnd();
    glColor3ub (255,255,0);//petals
    DrawCircle(122,56, 3, 5);
    DrawCircle(119,58, 3, 5);
    DrawCircle(120,57, 3, 5);
    DrawCircle(117,60, 3, 5);
    glEnd();

    glColor3ub (0,100,0);
    glBegin(GL_TRIANGLES);//leaf1
    glVertex2i(118,35);
    glVertex2i(118,25);
    glVertex2i(135,60);
    glEnd();

    glColor3ub (0,100,0);
    glBegin(GL_TRIANGLES);//leaf2
    glVertex2i(118,25);
    glVertex2i(118,20);
    glVertex2i(105,60);
    glEnd();


    //flower 5
    glColor3ub (0,100,0);
    glBegin(GL_QUADS);//branch main
    glVertex2i(154,52);
    glVertex2i(154,0);
    glVertex2i(155,0);
    glVertex2i(155,52);
    glEnd();
    glColor3ub (139,69,19);//petals
    DrawCircle(154,55, 5, 15);
    glEnd();
    glColor3ub (255,255,0);//petals
    DrawCircle(153,51, 3, 5);
    DrawCircle(150,53, 3, 5);
    glEnd();
    glColor3ub (0,100,0);
    glBegin(GL_TRIANGLES);//leaf1
    glVertex2i(155,35);
    glVertex2i(155,30);
    glVertex2i(170,45);
    glEnd();

    glColor3ub (0,100,0);
    glBegin(GL_TRIANGLES);//leaf2
    glVertex2i(155,25);
    glVertex2i(155,30);
    glVertex2i(140,45);
    glEnd();


    //flower6

    glColor3ub (0,100,0);
    glBegin(GL_QUADS);//branch main
    glVertex2i(190,54);
    glVertex2i(190,0);
    glVertex2i(191,0);
    glVertex2i(191,54);
    glEnd();
    glColor3ub (139,69,19);//petals
    DrawCircle(191,56, 5, 15);
    glEnd();
    glColor3ub (255,255,0);//petals
    DrawCircle(188,49, 3, 5);
    DrawCircle(185,52, 3, 5);
    glEnd();
    glColor3ub (0,100,0);
    glBegin(GL_TRIANGLES);//leaf1
    glVertex2i(191,35);
    glVertex2i(191,30);
    glVertex2i(170,45);
    glEnd();

    glBegin(GL_TRIANGLES);//leaf1
    glVertex2i(191,25);
    glVertex2i(191 ,30);
    glVertex2i(200,45);
    glEnd();
    //flower7

    glColor3ub (0,100,0);
    glBegin(GL_QUADS);//branch main
    glVertex2i(226,56);
    glVertex2i(226,0);
    glVertex2i(227,0);
    glVertex2i(227,56);
    glEnd();
    glColor3ub (139,69,19);//petals
    DrawCircle(226,57, 5, 15);
    glEnd();
    glColor3ub (255,255,0);//petals
    DrawCircle(224,59, 3, 5);
    DrawCircle(225,58, 3, 5);
    glEnd();
    glColor3ub (0,100,0);
    glBegin(GL_TRIANGLES);//leaf1
    glVertex2i(227,35);
    glVertex2i(227,30);
    glVertex2i(235,45);
    glEnd();

    glColor3ub (0,100,0);
    glBegin(GL_TRIANGLES);//leaf1
    glVertex2i(227,25);
    glVertex2i(227,30);
    glVertex2i(210,45);
    glEnd();

    //flower8

    glColor3ub (0,100,0);
    glBegin(GL_QUADS);//branch main
    glVertex2i(262,58);
    glVertex2i(262,0);
    glVertex2i(263,0);
    glVertex2i(263,58);
    glEnd();
    glColor3ub (139,69,19);//petals
    DrawCircle(262,59, 5, 15);
    glEnd();
    glColor3ub (255,255,0);//petals
    DrawCircle(260,60, 3, 5);
    DrawCircle(259,62, 3, 5);
    glEnd();
    glColor3ub (0,100,0);
    glBegin(GL_TRIANGLES);//leaf1
    glVertex2i(263,35);
    glVertex2i(263,30);
    glVertex2i(280,45);
    glEnd();

    glColor3ub (0,100,0);
    glBegin(GL_TRIANGLES);//leaf1
    glVertex2i(263,25);
    glVertex2i(263,30);
    glVertex2i(240,45);
    glEnd();

    //flower 9

    glColor3ub (0,100,0);
    glBegin(GL_QUADS);//branch main
    glVertex2i(298,60);
    glVertex2i(298,0);
    glVertex2i(299,0);
    glVertex2i(299,60);
    glEnd();
    glColor3ub (139,69,19);//petals
    DrawCircle(298,63, 5, 15);
    glEnd();
    glColor3ub (255,255,0);//petals
    DrawCircle(296,65, 3, 5);
    DrawCircle(299,68, 3, 5);
    glEnd();
    glColor3ub (0,100,0);
    glBegin(GL_TRIANGLES);//leaf1
    glVertex2i(299,35);
    glVertex2i(299,30);
    glVertex2i(310,45);
    glEnd();

    glColor3ub (0,100,0);
    glBegin(GL_TRIANGLES);//leaf1
    glVertex2i(299,40);
    glVertex2i(299,35);
    glVertex2i(280,45);
    glEnd();
    //flower 11

    glColor3ub (0,100,0);
    glBegin(GL_QUADS);//branch main
    glVertex2i(334,62);
    glVertex2i(334,0);
    glVertex2i(335,0);
    glVertex2i(335,62);
    glEnd();
    glColor3ub (139,69,19);//petals
    DrawCircle(335,63, 5, 15);
    glEnd();
    glColor3ub (255,255,0);//petals
    DrawCircle(333,68, 3, 5);
    DrawCircle(336,65, 3, 5);
    glEnd();
    glColor3ub (0,100,0);
    glBegin(GL_TRIANGLES);//leaf1
    glVertex2i(335,35);
    glVertex2i(335,30);
    glVertex2i(340,45);
    glEnd();


    glBegin(GL_TRIANGLES);//leaf1
    glVertex2i(335,35);
    glVertex2i(335,30);
    glVertex2i(310,45);
    glEnd();
//flower12
    glColor3ub (0,100,0);
    glBegin(GL_QUADS);//branch main
    glVertex2i(370,64);
    glVertex2i(370,0);
    glVertex2i(371,0);
    glVertex2i(371,64);
    glEnd();
    glColor3ub (139,69,19);//petals
    DrawCircle(370,64, 5, 15);
    glEnd();
    glColor3ub (255,255,0);//petals
    DrawCircle(373,69, 3, 5);
    DrawCircle(368,65, 3, 5);
    glEnd();
    glColor3ub (0,100,0);
    glBegin(GL_TRIANGLES);//leaf1
    glVertex2i(371,35);
    glVertex2i(371,30);
    glVertex2i(385,45);
    glEnd();

    glColor3ub (0,100,0);
    glBegin(GL_TRIANGLES);//leaf2
    glVertex2i(371,35);
    glVertex2i(371,30);
    glVertex2i(355,45);
    glEnd();
//flower13
    glColor3ub (0,100,0);
    glBegin(GL_QUADS);//branch main
    glVertex2i(406,64);
    glVertex2i(406,0);
    glVertex2i(407,0);
    glVertex2i(407,64);
    glEnd();
    glColor3ub (139,69,19);//petals
    DrawCircle(406,64, 5, 15);
    glEnd();
    glColor3ub (255,255,0);//petals
    DrawCircle(403,69, 3, 5);
    DrawCircle(407,65, 3, 5);
    DrawCircle(408,69, 3, 5);
    DrawCircle(405,65, 3, 5);
    glEnd();
    glColor3ub (0,100,0);
    glBegin(GL_TRIANGLES);//leaf1
    glVertex2i(407,35);
    glVertex2i(407,30);
    glVertex2i(375,45);
    glEnd();

    glColor3ub (0,100,0);
    glBegin(GL_TRIANGLES);//leaf1
    glVertex2i(407,35);
    glVertex2i(407,30);
    glVertex2i(410,45);
    glEnd();

    //flower14
    glColor3ub (0,100,0);
    glBegin(GL_QUADS);//branch main
    glVertex2i(433,62);
    glVertex2i(433,0);
    glVertex2i(434,0);
    glVertex2i(434,62);
    glEnd();
    glColor3ub (139,69,19);//petals
    DrawCircle(433,63, 5, 15);
    glEnd();
    glColor3ub (255,255,0);//petals
    DrawCircle(432,64, 3, 5);
    DrawCircle(431,65, 3, 5);
    glEnd();
    glColor3ub (0,100,0);
    glBegin(GL_TRIANGLES);//leaf1
    glVertex2i(434,35);
    glVertex2i(434,30);
    glVertex2i(445,45);
    glEnd();

    glColor3ub (0,100,0);
    glBegin(GL_TRIANGLES);//leaf1
    glVertex2i(434,25);
    glVertex2i(434,30);
    glVertex2i(425,45);
    glEnd();
    //flower15
    glColor3ub (0,100,0);
    glBegin(GL_QUADS);//branch main
    glVertex2i(464,62);
    glVertex2i(464,0);
    glVertex2i(465,0);
    glVertex2i(465,62);
    glEnd();
    glColor3ub (139,69,19);//petals
    DrawCircle(464,65, 5, 15);
    glEnd();
    glColor3ub (255,255,0);//petals
    DrawCircle(465,66, 3, 5);
    DrawCircle(464,66, 3, 5);
    glEnd();
    glColor3ub (0,100,0);
    glBegin(GL_TRIANGLES);//leaf1
    glVertex2i(465,35);
    glVertex2i(465,30);
    glVertex2i(485,45);
    glEnd();

    glColor3ub (0,100,0);
    glBegin(GL_TRIANGLES);//leaf1
    glVertex2i(465,25);
    glVertex2i(465,30);
    glVertex2i(455,45);
    glEnd();


    //flower 16

    glColor3ub (0,100,0);
    glBegin(GL_QUADS);//branch main
    glVertex2i(503,62);
    glVertex2i(503,0);
    glVertex2i(504,0);
    glVertex2i(504,62);
    glEnd();
    glColor3ub (139,69,19);//petals
    DrawCircle(503,63, 5, 15);
    glEnd();
    glColor3ub (255,255,0);//petals
    DrawCircle(504,68, 4, 5);
    DrawCircle(502,65, 4, 5);
    DrawCircle(505,68, 4, 5);
    DrawCircle(502,69, 4, 5);
    glEnd();
    glColor3ub (0,100,0);
    glBegin(GL_TRIANGLES);//leaf1
    glVertex2i(504,35);
    glVertex2i(504,30);
    glVertex2i(515,45);
    glEnd();


    glColor3ub (0,100,0);
    glBegin(GL_TRIANGLES);//leaf2
    glVertex2i(504,35);
    glVertex2i(504,30);
    glVertex2i(490,45);
    glEnd();
//flower17
    glColor3ub (0,100,0);
    glBegin(GL_QUADS);//branch main
    glVertex2i(538,64);
    glVertex2i(538,0);
    glVertex2i(539,0);
    glVertex2i(539,64);
    glEnd();
    glColor3ub (139,69,19);//petals
    DrawCircle(538,64, 5, 15);
    glEnd();
    glColor3ub (255,255,0);//petals
    DrawCircle(540,69, 3, 5);
    DrawCircle(537,65, 3, 5);
    DrawCircle(542,65, 3, 5);
    DrawCircle(536,65, 3, 5);
    DrawCircle(537,69, 3, 5);
    glEnd();
    glColor3ub (0,100,0);
    glBegin(GL_TRIANGLES);//leaf1
    glVertex2i(539,35);
    glVertex2i(539,30);
    glVertex2i(550,45);
    glEnd();

    glColor3ub (0,100,0);
    glBegin(GL_TRIANGLES);//leaf1
    glVertex2i(539,35);
    glVertex2i(539,30);
    glVertex2i(530,45);
    glEnd();

//flower18
    glColor3ub (0,100,0);
    glBegin(GL_QUADS);//branch main
    glVertex2i(573,64);
    glVertex2i(573,0);
    glVertex2i(574,0);
    glVertex2i(574,64);
    glEnd();
    glColor3ub (139,69,19);//petals
    DrawCircle(574,64, 5, 15);
    glEnd();
    glColor3ub (255,255,0);//petals
    DrawCircle(578,69, 3, 5);
    DrawCircle(579,65, 3, 5);
    DrawCircle(574,69, 3, 5);
    DrawCircle(573,65, 3, 5);
    glEnd();

    glColor3ub (0,100,0);
    glBegin(GL_TRIANGLES);//leaf1
    glVertex2i(574,25);
    glVertex2i(574,30);
    glVertex2i(584,45);
    glEnd();

 glColor3ub (0,100,0);
    glBegin(GL_TRIANGLES);//leaf2
    glVertex2i(574,25);
    glVertex2i(574,30);
    glVertex2i(564,45);
    glEnd();

    //flower19
    glColor3ub (0,100,0);
    glBegin(GL_QUADS);//branch main
    glVertex2i(608,62);
    glVertex2i(608,0);
    glVertex2i(609,0);
    glVertex2i(609,62);
    glEnd();
    glColor3ub (139,69,19);//petals
    DrawCircle(608,63, 5, 15);
    glEnd();
    glColor3ub (255,255,0);//petals
    DrawCircle(609,64, 3, 5);
    DrawCircle(606,64, 3, 5);
    DrawCircle(605,66, 3, 5);
    DrawCircle(608,65, 3, 5);
    glEnd();
    glColor3ub (0,100,0);
    glBegin(GL_TRIANGLES);//leaf1
    glVertex2i(609,35);
    glVertex2i(609,30);
    glVertex2i(620,45);
    glEnd();

    glColor3ub (0,100,0);
    glBegin(GL_TRIANGLES);//leaf1
    glVertex2i(609,35);
    glVertex2i(609,30);
    glVertex2i(590,45);
    glEnd();


}
//////////flower ends////////////////
//////////home 1 starts/////////////
void home1(int x,int y,int z,int m,int n,int o)
{
    //home 1
    glColor3ub (72,61,139);
    glBegin(GL_POLYGON);
    glVertex2i(95, 195);
    glVertex2i(170, 195);
    glVertex2i(225, 250);
    glVertex2i(150, 250);
    glEnd();

    glColor3ub (72,61,139);
    glBegin(GL_LINES);
    glVertex2i(225, 250);
    glVertex2i(280, 200);
    glEnd();

    glColor3ub (m,n,o);
    glBegin(GL_QUADS);
    glVertex2i(100, 200);
    glVertex2i(100, 150);
    glVertex2i(175, 150);
    glVertex2i(175, 200);
    glEnd();

    glColor3ub (x,y,z);
    glBegin(GL_POLYGON);
    glVertex2i(175, 200);
    glVertex2i(175, 150);
    glVertex2i(275, 150);
    glVertex2i(275, 200);
    glVertex2i(280, 200);
    glVertex2i(225, 250);
    glEnd();

    // door
    glColor3ub (72,61,139);
    glBegin(GL_POLYGON);
    glVertex2i(125, 185);
    glVertex2i(125, 150);
    glVertex2i(150, 150);
    glVertex2i(150, 185);
    glEnd();

    //window
    glColor3ub (72,61,139);
    glBegin(GL_POLYGON);
    glVertex2i(212, 200);
    glVertex2i(212, 175);
    glVertex2i(237, 175);
    glVertex2i(237, 200);
    glEnd();

    glColor3ub (216,191,216);
    glBegin(GL_LINES);
    glVertex2i(225, 200);
    glVertex2i(225, 175);

    glVertex2i(212, 187);
    glVertex2i(237, 187);
    glEnd();

    //pipe

    glColor3ub (72,61,139);
    glBegin(GL_QUADS);
    glVertex2i(250, 250);
    glVertex2i(250, 225);
    glVertex2i(255,220);
    glVertex2i(255, 250);
    glEnd();

    //smoke

    glColor3ub (70,70,70);
    glBegin(GL_POLYGON);
    glVertex2i(252, 250);//1
    glVertex2i(250,255);
    glVertex2i(253,260);
    glVertex2i(256,258);
    glVertex2i(253,256);
    glVertex2i(254,250);
    glEnd();
     ///////////////fence starts/////////////

    // fence 1
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//1
    glVertex2i(15,45);
    glVertex2i(10,40);
    glVertex2i(10,0);
    glVertex2i(15,0);
    glVertex2i(15,40);
    glColor3ub (218,165,32);
    glBegin(GL_POLYGON);//1
    glVertex2i(15,45);
    glVertex2i(15,0);
    glVertex2i(20,0);
    glVertex2i(20,40);
    glVertex2i(15,45);
    glEnd();
    // fence 2
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//2
    glVertex2i(35,45);
    glVertex2i(30,40);
    glVertex2i(30,0);
    glVertex2i(35,0);
    glVertex2i(35,40);
    glColor3ub (218,165,32);
    glBegin(GL_POLYGON);//2
    glVertex2i(35,45);
    glVertex2i(35,0);
    glVertex2i(40,0);
    glVertex2i(40,40);
    glVertex2i(35,45);
    glEnd();
    // fence 3
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//3
    glVertex2i(55,45);
    glVertex2i(50,40);
    glVertex2i(50,0);
    glVertex2i(55,0);
    glVertex2i(55,45);
    glColor3ub (218,165,32);
    glBegin(GL_POLYGON);//3
    glVertex2i(55,45);
    glVertex2i(55,0);
    glVertex2i(60,0);
    glVertex2i(60,40);
    glVertex2i(55,45);
    glEnd();
    // fence 4
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//4
    glVertex2i(75,45);
    glVertex2i(70,40);
    glVertex2i(70,0);
    glVertex2i(75,0);
    glVertex2i(75,45);
    glColor3ub (218,165,32);
    glBegin(GL_POLYGON);//4
    glVertex2i(75,45);
    glVertex2i(75,0);
    glVertex2i(80,0);
    glVertex2i(80,40);
    glVertex2i(75,45);
    glEnd();
    // fence 5
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//5
    glVertex2i(95,45);
    glVertex2i(90,40);
    glVertex2i(90,0);
    glVertex2i(95,0);
    glVertex2i(95,45);
    glColor3ub (218,165,32);
    glBegin(GL_POLYGON);//5
    glVertex2i(95,45);
    glVertex2i(95,0);
    glVertex2i(100,0);
    glVertex2i(100,40);
    glVertex2i(95,45);
    glEnd();



    // fence 6
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//1
    glVertex2i(115,45);
    glVertex2i(110,40);
    glVertex2i(110,0);
    glVertex2i(115,0);
    glVertex2i(115,40);
    glColor3ub (218,165,32);
    glBegin(GL_POLYGON);//1
    glVertex2i(115,45);
    glVertex2i(115,0);
    glVertex2i(120,0);
    glVertex2i(120,40);
    glVertex2i(115,45);
    glEnd();

    // fence 7
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//2
    glVertex2i(135,45);
    glVertex2i(130,40);
    glVertex2i(130,0);
    glVertex2i(135,0);
    glVertex2i(135,40);
    glColor3ub (218,165,32);
    glBegin(GL_POLYGON);//2
    glVertex2i(135,45);
    glVertex2i(135,0);
    glVertex2i(140,0);
    glVertex2i(140,40);
    glVertex2i(135,45);
    glEnd();
    // fence 8
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//3
    glVertex2i(155,45);
    glVertex2i(150,40);
    glVertex2i(150,0);
    glVertex2i(155,0);
    glVertex2i(155,45);
    glColor3ub (218,165,32);
    glBegin(GL_POLYGON);//3
    glVertex2i(155,45);
    glVertex2i(155,0);
    glVertex2i(160,0);
    glVertex2i(160,40);
    glVertex2i(155,45);
    glEnd();
    // fence 9
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//4
    glVertex2i(175,45);
    glVertex2i(170,40);
    glVertex2i(170,0);
    glVertex2i(175,0);
    glVertex2i(175,45);
    glColor3ub (218,165,32);
    glBegin(GL_POLYGON);//4
    glVertex2i(175,45);
    glVertex2i(175,0);
    glVertex2i(180,0);
    glVertex2i(180,40);
    glVertex2i(175,45);
    glEnd();
    // fence 10
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//5
    glVertex2i(195,45);
    glVertex2i(190,40);
    glVertex2i(190,0);
    glVertex2i(195,0);
    glVertex2i(195,45);
    glColor3ub (218,165,32);
    glBegin(GL_POLYGON);//5
    glVertex2i(195,45);
    glVertex2i(195,0);
    glVertex2i(200,0);
    glVertex2i(200,40);
    glVertex2i(195,45);
    glEnd();

     // fence 11
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//1
    glVertex2i(215,45);
    glVertex2i(210,40);
    glVertex2i(210,0);
    glVertex2i(215,0);
    glVertex2i(215,40);
    glColor3ub (218,165,32);
    glBegin(GL_POLYGON);//1
    glVertex2i(215,45);
    glVertex2i(215,0);
    glVertex2i(220,0);
    glVertex2i(220,40);
    glVertex2i(215,45);
    glEnd();
    // fence 12
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//2
    glVertex2i(235,45);
    glVertex2i(230,40);
    glVertex2i(230,0);
    glVertex2i(235,0);
    glVertex2i(235,40);
    glColor3ub (218,165,32);
    glBegin(GL_POLYGON);//2
    glVertex2i(235,45);
    glVertex2i(235,0);
    glVertex2i(240,0);
    glVertex2i(240,40);
    glVertex2i(235,45);
    glEnd();
    // fence 13
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//3
    glVertex2i(255,45);
    glVertex2i(250,40);
    glVertex2i(250,0);
    glVertex2i(255,0);
    glVertex2i(255,45);
    glColor3ub (218,165,32);
    glBegin(GL_POLYGON);//3
    glVertex2i(255,45);
    glVertex2i(255,0);
    glVertex2i(260,0);
    glVertex2i(260,40);
    glVertex2i(255,45);
    glEnd();
    // fence 14
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//4
    glVertex2i(275,45);
    glVertex2i(270,40);
    glVertex2i(270,0);
    glVertex2i(275,0);
    glVertex2i(275,45);
    glColor3ub (218,165,32);
    glBegin(GL_POLYGON);//4
    glVertex2i(275,45);
    glVertex2i(275,0);
    glVertex2i(280,0);
    glVertex2i(280,40);
    glVertex2i(275,45);
    glEnd();
    // fence 15
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//5
    glVertex2i(295,45);
    glVertex2i(290,40);
    glVertex2i(290,0);
    glVertex2i(295,0);
    glVertex2i(295,45);
    glColor3ub (218,165,32);
    glBegin(GL_POLYGON);//5
    glVertex2i(295,45);
    glVertex2i(295,0);
    glVertex2i(300,0);
    glVertex2i(300,40);
    glVertex2i(395,45);
    glEnd();

    // fence 16
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//1
    glVertex2i(315,45);
    glVertex2i(310,40);
    glVertex2i(310,0);
    glVertex2i(315,0);
    glVertex2i(315,40);
    glColor3ub (318,165,32);
    glBegin(GL_POLYGON);//1
    glVertex2i(315,45);
    glVertex2i(315,0);
    glVertex2i(320,0);
    glVertex2i(320,40);
    glVertex2i(315,45);
    glEnd();
    // fence 17
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//2
    glVertex2i(335,45);
    glVertex2i(330,40);
    glVertex2i(330,0);
    glVertex2i(335,0);
    glVertex2i(335,40);
    glColor3ub (218,165,32);
    glBegin(GL_POLYGON);//2
    glVertex2i(335,45);
    glVertex2i(335,0);
    glVertex2i(340,0);
    glVertex2i(340,40);
    glVertex2i(335,45);
    glEnd();
    // fence 18
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//3
    glVertex2i(355,45);
    glVertex2i(350,40);
    glVertex2i(350,0);
    glVertex2i(355,0);
    glVertex2i(355,45);
    glColor3ub (218,165,32);
    glBegin(GL_POLYGON);//3
    glVertex2i(355,45);
    glVertex2i(355,0);
    glVertex2i(360,0);
    glVertex2i(360,40);
    glVertex2i(355,45);
    glEnd();
    // fence 19
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//4
    glVertex2i(375,45);
    glVertex2i(370,40);
    glVertex2i(370,0);
    glVertex2i(375,0);
    glVertex2i(375,45);
    glColor3ub (218,165,32);
    glBegin(GL_POLYGON);//4
    glVertex2i(375,45);
    glVertex2i(375,0);
    glVertex2i(380,0);
    glVertex2i(380,40);
    glVertex2i(375,45);
    glEnd();
    // fence 20
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//5
    glVertex2i(395,45);
    glVertex2i(390,40);
    glVertex2i(390,0);
    glVertex2i(395,0);
    glVertex2i(395,45);
    glColor3ub (218,165,32);
    glBegin(GL_POLYGON);//5
    glVertex2i(395,45);
    glVertex2i(395,0);
    glVertex2i(400,0);
    glVertex2i(400,40);
    glVertex2i(395,45);
    glEnd();
// fence 21
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//1
    glVertex2i(415,45);
    glVertex2i(410,40);
    glVertex2i(410,0);
    glVertex2i(415,0);
    glVertex2i(415,40);
    glColor3ub (218,165,32);
    glBegin(GL_POLYGON);//1
    glVertex2i(415,45);
    glVertex2i(415,0);
    glVertex2i(420,0);
    glVertex2i(420,40);
    glVertex2i(415,45);
    glEnd();
    // fence 22
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//2
    glVertex2i(435,45);
    glVertex2i(430,40);
    glVertex2i(430,0);
    glVertex2i(435,0);
    glVertex2i(435,40);
    glColor3ub (218,165,32);
    glBegin(GL_POLYGON);//2
    glVertex2i(435,45);
    glVertex2i(435,0);
    glVertex2i(440,0);
    glVertex2i(440,40);
    glVertex2i(435,45);
    glEnd();
    // fence 3
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//3
    glVertex2i(455,45);
    glVertex2i(450,40);
    glVertex2i(450,0);
    glVertex2i(455,0);
    glVertex2i(455,45);
    glColor3ub (218,165,32);
    glBegin(GL_POLYGON);//3
    glVertex2i(455,45);
    glVertex2i(455,0);
    glVertex2i(460,0);
    glVertex2i(460,40);
    glVertex2i(455,45);
    glEnd();
    // fence 24
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//4
    glVertex2i(475,45);
    glVertex2i(470,40);
    glVertex2i(470,0);
    glVertex2i(475,0);
    glVertex2i(475,45);
    glColor3ub (218,165,32);
    glBegin(GL_POLYGON);//4
    glVertex2i(475,45);
    glVertex2i(475,0);
    glVertex2i(480,0);
    glVertex2i(480,40);
    glVertex2i(475,45);
    glEnd();
    // fence 25
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//5
    glVertex2i(495,45);
    glVertex2i(490,40);
    glVertex2i(490,0);
    glVertex2i(495,0);
    glVertex2i(495,45);
    glColor3ub (218,165,32);
    glBegin(GL_POLYGON);//5
    glVertex2i(495,45);
    glVertex2i(495,0);
    glVertex2i(500,0);
    glVertex2i(500,40);
    glVertex2i(500,45);
    glEnd();



    // fence 26
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//1
    glVertex2i(515,45);
    glVertex2i(510,40);
    glVertex2i(510,0);
    glVertex2i(515,0);
    glVertex2i(515,40);
    glColor3ub (218,165,32);
    glBegin(GL_POLYGON);//1
    glVertex2i(515,45);
    glVertex2i(515,0);
    glVertex2i(520,0);
    glVertex2i(520,40);
    glVertex2i(515,45);
    glEnd();

    // fence 27
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//2
    glVertex2i(535,45);
    glVertex2i(530,40);
    glVertex2i(530,0);
    glVertex2i(535,0);
    glVertex2i(535,40);
    glColor3ub (218,165,32);
    glBegin(GL_POLYGON);//2
    glVertex2i(535,45);
    glVertex2i(535,0);
    glVertex2i(540,0);
    glVertex2i(540,40);
    glVertex2i(535,45);
    glEnd();
    // fence 28
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//3
    glVertex2i(555,45);
    glVertex2i(550,40);
    glVertex2i(550,0);
    glVertex2i(555,0);
    glVertex2i(555,45);
    glColor3ub (218,165,32);
    glBegin(GL_POLYGON);//3
    glVertex2i(555,45);
    glVertex2i(555,0);
    glVertex2i(560,0);
    glVertex2i(560,40);
    glVertex2i(555,45);
    glEnd();
    // fence 29
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//4
    glVertex2i(575,45);
    glVertex2i(570,40);
    glVertex2i(570,0);
    glVertex2i(575,0);
    glVertex2i(575,45);
    glColor3ub (518,165,32);
    glBegin(GL_POLYGON);//4
    glVertex2i(575,45);
    glVertex2i(575,0);
    glVertex2i(580,0);
    glVertex2i(580,40);
    glVertex2i(575,45);
    glEnd();
    // fence 30
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//5
    glVertex2i(595,45);
    glVertex2i(590,40);
    glVertex2i(590,0);
    glVertex2i(595,0);
    glVertex2i(595,45);
    glColor3ub (218,165,32);
    glBegin(GL_POLYGON);//5
    glVertex2i(595,45);
    glVertex2i(595,0);
    glVertex2i(600,0);
    glVertex2i(600,40);
    glVertex2i(595,45);
    glEnd();

     // fence 31
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//1
    glVertex2i(615,45);
    glVertex2i(610,40);
    glVertex2i(610,0);
    glVertex2i(615,0);
    glVertex2i(615,40);
    glColor3ub (618,165,32);
    glBegin(GL_POLYGON);//1
    glVertex2i(615,45);
    glVertex2i(615,0);
    glVertex2i(620,0);
    glVertex2i(620,40);
    glVertex2i(615,45);
    glEnd();
    // fence 32
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//1
    glVertex2i(635,45);
    glVertex2i(630,40);
    glVertex2i(630,0);
    glVertex2i(635,0);
    glVertex2i(635,40);
    glColor3ub (618,165,32);
    glBegin(GL_POLYGON);//1
    glVertex2i(635,45);
    glVertex2i(635,0);
    glVertex2i(640,0);
    glVertex2i(640,40);
    glVertex2i(635,45);
    glEnd();
glColor3ub (184,134,11);
    glBegin(GL_QUADS);//--line
    glVertex2i(0,20);
    glVertex2i(0,15);
    glVertex2i(640,15);
    glVertex2i(640,20);
    glEnd();
    // fence
    ///////////////FENCE ends/////////////
}

//////////////human //////////////////
    /////////move human ////////////////
    void move_human(int x)
    {
        if(humanstatus==1)
        {
            if(humanX >640.0f)
            {
                humanX = -700.0f;
            }
            humanX += 0.5f;
            humanY +=0.5f;
            glutPostRedisplay();
            glutTimerFunc(100000, move_human, 0);
        }
    }
     /////////move human ////////////////
void human()
{
   glColor3ub (0,139,139);//body down
   glBegin(GL_QUADS);
   glVertex2i(120,75);
   glVertex2i(135,75);
   glVertex2i(135,125);
   glVertex2i(120,125);
   glColor3ub (218,165,32);//body up
   glBegin(GL_QUADS);
   glVertex2i(122,100);
   glVertex2i(119.5,140);
   glVertex2i(134.5,140);
   glVertex2i(134.5,100);
   glEnd();
   glColor3ub(0,0,0);//head
   DrawCircle(127, 142, 6, 15);
   glEnd();
   glBegin(GL_LINES); //stick
   glVertex2i(100,138);
   glVertex2i(155,138);
   glEnd();
   glBegin(GL_LINES);//left rope
   glVertex2i(102,142.5);
   glVertex2i(102,120);

   glEnd();
   glColor3ub(128,0,0);
   DrawCircle(102, 120, 3, 10);//left bone
   glEnd();
   glBegin(GL_LINES);//right rope
   glVertex2i(154,142.5);
   glVertex2i(154,120);

   glEnd();
   glColor3ub(128,0,0);
   DrawCircle(154, 120,3, 10);//right bone
   glEnd();

   glBegin(GL_LINES);// left leg
   glVertex2i(122,75);
   glVertex2i(122,73);
   glBegin(GL_LINES);// right leg
   glVertex2i(128,75);
   glVertex2i(128,73);
   glEnd();
}
//////////////human 2 ends/////////////

void Rain(int x)
{

if(rainstatus==1){

    rainY += 0.000000000001f;

    glBegin(GL_POINTS);
    for(int i=1;i<=1000;i++)
    {
        int x=rand(),y=rand();
        x%=1000; y%=1000;
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(x,y);
        glVertex2d(x+5,y+5);
        glEnd();

    }

	glutPostRedisplay();
	glutTimerFunc(5, Rain, 0);

    glFlush();
}
}
/////////////rain ends////////////////
/////////////birds starts////////////
void birds()
{
    ///bird 1
    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    glVertex2f(70,385);
    glVertex2f(74,395);
    glVertex2f(80,390);
    glVertex2f(84,399);
    glVertex2f(84,389);
    glVertex2f(88,395);
    glVertex2f(84,387);
    glVertex2f(90,387);
    glVertex2f(86,383);
    glVertex2f(80,382);
    glEnd();

    ///bird 2
    glBegin(GL_POLYGON);
    glColor3f(0,1,1);
    glVertex2f(40,385);
    glVertex2f(44,395);
    glVertex2f(50,390);
    glVertex2f(54,399);
    glVertex2f(54,389);
    glVertex2f(58,395);
    glVertex2f(44,387);
    glVertex2f(60,387);
    glVertex2f(46,383);
    glVertex2f(50,382);
    glEnd();

    ///bird 3
        glBegin(GL_POLYGON);
    glColor3f(0,0,1.5);
    glVertex2f(50,365);
    glVertex2f(54,375);
    glVertex2f(60,370);
    glVertex2f(64,379);
    glVertex2f(64,369);
    glVertex2f(68,375);
    glVertex2f(54,367);
    glVertex2f(70,367);
    glVertex2f(56,363);
    glVertex2f(60,362);
    glEnd();


}////////move birds////////

void plan(){
        //plan//
    glBegin(GL_POLYGON);
    glVertex2f(40,385);
    glVertex2f(90,385);
    glVertex2f(90,395);
    glVertex2f(40,385);
    glEnd();

        glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(80,388);
    glVertex2f(83,388);
     glVertex2f(100,405);
    glVertex2f(80,388);
    glEnd();

}
void move_birds(int x)
{
    if(birdstatus==1)
        {
            if(birdsX <-100.0f)
            {
                birdsX = 700.0f;
            }
            birdsX -= 0.5f;
            glutPostRedisplay();
            glutTimerFunc(100000, move_birds, 0);
        }
}
/////////////birds ends/////////////
void day_night()
{
    if(day==1)
    {
        /////draw sky starts///
            glColor3ub (90, 196, 242);
            glBegin(GL_QUADS);
            glVertex2i(0, 255);
            glVertex2i(640, 255);
            glVertex2i(640, 480);
            glVertex2i(0, 480);
            glEnd();
            glFlush();
        /////draw sky ends///
          /////draw sun/////

            glPushMatrix();
            glTranslatef(sunX, sunY, 0);
            glColor3ub (225,201,34);
            DrawCircle(550, 275, 40, 1000);
            glEnd();
            glFlush();
            glPopMatrix();
        /////draw sun ends////

             ////clouds/////
            glPushMatrix();
            glTranslatef(cloudX, cloudY, 0);
            clouds();
            glEnd();
            glFlush();
            glPopMatrix();
            movecloud();
             ////clouds////
             /////opposite grass////
            glColor3ub (46, 170, 49);
            glBegin(GL_QUADS);
            glVertex2i(0, 255);
            glVertex2i(520, 255);
            glVertex2i(520, 258);
            glVertex2i(0, 258);
            glEnd();
            ////draw ends//////////
            hills(208,176,45);
            oposite_village(51, 204, 51);

            water(142, 227, 227);
            /////moving wave & boat//////
            glPushMatrix();
            glTranslatef(waterX, waterY, 0);
            boat_wave();
            glPopMatrix();
            glEnd();
            glFlush();
            movewater();
            /////moving wave & boat ends//////
            land(31, 242, 7);
            tree(58,95,11);
            road(240,230,140);
            flower();
            home1(216,191,216,255, 230, 250);



                        /////move human///////////
             glPushMatrix();
            glTranslatef(humanX,0.0f,0.0f);
            human();
            glPopMatrix();
            glEnd();
            glFlush();
            move_human(1);



            /////move cycle starts///////
            glPushMatrix();


            glPopMatrix();
            glEnd();
            glFlush();

            /////move cycle ends///////
            /////rain starts////////////
            glPushMatrix();
            glTranslatef(0.0f,rainY,0.0f);
            Rain(1);
            glPopMatrix();
            glEnd();
            glFlush();
            ///////rain ends////////////
            ///////move birds starts///////
            glPushMatrix();
            glTranslatef(birdsX,0.0f,0.0f);
            birds();
            glPopMatrix();
            glEnd();
            glFlush();
            move_birds(1);
            ///////move birds end/////////



    }
    else
    {
        /////draw sky ////////
            glColor3ub (0, 0, 0);
            glBegin(GL_QUADS);
            glVertex2i(0, 255);
            glVertex2i(640, 255);
            glVertex2i(640, 480);
            glVertex2i(0, 480);
            glEnd();
        /////draw sky ends///
         /////draw moon/////
            glPushMatrix();
            glTranslatef(sunX, sunY, 0);
            glColor3ub (255,255,255);
            DrawCircle(550, 275, 40, 1000);
            glEnd();
            glFlush();
            glPopMatrix();
        /////draw moon ends////

            //star 1
            glColor3f(255,255,255);
            glBegin(GL_TRIANGLES);
            glVertex2i(15,408);
            glVertex2i(10,400);
            glVertex2i(20,400);
            glVertex2i(15,397);
            glVertex2i(10,405);
            glVertex2i(20,405);
            glEnd();
             //star 2
            glColor3f(255,255,255);
            glBegin(GL_TRIANGLES);
            glVertex2i(35,450);
            glVertex2i(30,442);
            glVertex2i(40,442);
            glVertex2i(35,439);
            glVertex2i(30,447);
            glVertex2i(40,447);
            glEnd();
            //star 3
            glColor3f(255,255,255);
            glBegin(GL_TRIANGLES);
            glVertex2i(75,311);
            glVertex2i(70,303);
            glVertex2i(80,303);
            glVertex2i(75,300);
            glVertex2i(70,308);
            glVertex2i(80,308);
            glEnd();
            //star 3
            glColor3f(255,255,255);
            glBegin(GL_TRIANGLES);
            glVertex2i(155,350);
            glVertex2i(150,342);
            glVertex2i(160,342);
            glVertex2i(155,339);
            glVertex2i(150,347);
            glVertex2i(160,347);
            glEnd();

            //star 4
            glColor3f(255,255,255);
            glBegin(GL_TRIANGLES);
            glVertex2i(205,508);
            glVertex2i(200,500);
            glVertex2i(210,500);
            glVertex2i(205,497);
            glVertex2i(200,505);
            glVertex2i(210,505);
            glEnd();

            //star 5
            glColor3f(255,255,255);
            glBegin(GL_TRIANGLES);
            glVertex2i(315,388);
            glVertex2i(310,380);
            glVertex2i(320,380);
            glVertex2i(315,377);
            glVertex2i(310,385);
            glVertex2i(320,385);
            glEnd();
            //star6
            glColor3f(255,255,255);
            glBegin(GL_TRIANGLES);
            glVertex2i(375,515);
            glVertex2i(370,507);
            glVertex2i(380,507);
            glVertex2i(375,504);
            glVertex2i(370,512);
            glVertex2i(380,512);
            glEnd();
            //star7
            glColor3f(255,255,255);
            glBegin(GL_TRIANGLES);
            glVertex2i(415,398);
            glVertex2i(410,390);
            glVertex2i(420,390);
            glVertex2i(415,387);
            glVertex2i(410,395);
            glVertex2i(420,395);
            glEnd();

             //star8
            glColor3f(255,255,255);
            glBegin(GL_TRIANGLES);
            glVertex2i(475,350);
            glVertex2i(470,342);
            glVertex2i(480,342);
            glVertex2i(475,339);
            glVertex2i(470,347);
            glVertex2i(480,347);
            glEnd();

            //star9
            glColor3f(255,255,255);
            glBegin(GL_TRIANGLES);
            glVertex2i(525,450);
            glVertex2i(520,442);
            glVertex2i(530,442);
            glVertex2i(525,439);
            glVertex2i(520,447);
            glVertex2i(530,447);
            glEnd();
            //star10
            glColor3f(255,255,255);
            glBegin(GL_TRIANGLES);
            glVertex2i(575,398);
            glVertex2i(570,390);
            glVertex2i(580,390);
            glVertex2i(575,387);
            glVertex2i(570,395);
            glVertex2i(580,395);
            glEnd();
            glColor3f(128,128,128);



            water(142, 227, 227);
            /////moving wave & boat//////
            glPushMatrix();
            glTranslatef(waterX, waterY, 0);

            glPopMatrix();
            glEnd();
            glFlush();
            movewater();
            /////opposite grass////
            glColor3ub (128,128,128);
            glBegin(GL_QUADS);
            glVertex2i(0, 255);
            glVertex2i(520, 255);
            glVertex2i(520, 258);
            glVertex2i(0, 258);
            glEnd();
            ////draw ends//////////


       ///////move plan starts///////
            glPushMatrix();
            glTranslatef(birdsX,0.0f,0.0f);
            plan();
            glPopMatrix();
            glEnd();
            glFlush();
            move_birds(1);

            hills(0,0,153);
            oposite_village(128,128,128);

            land(85,107,47);
            tree(85,107,47);
            road(112,128,144);
                        //flower();
            home1(169,169,169,169,169,169);



            /////rain starts////////////
            glPushMatrix();
            glTranslatef(0.0f,rainY,0.0f);
            Rain(1);
            glPopMatrix();
            glEnd();
            glFlush();
            ///////rain ends////////////

    }
}

////////////////////////////////////////display village function starts////////////////////////////////////////////////////////////////
void displayvillage(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
    day_night();
    glFlush();
    glutPostRedisplay();
    glutSwapBuffers();
}
////////////////////////////////////////display village function ends////////////////////////////////////////////////////////////////

void myInit (void)
{
glClearColor(1.0,1.0,1.0,1.0);
glColor3f(0.0,0.0,1.0);
glPointSize(2.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
/////////////////////////////////////////keyboard function starts////////////////////////////////////////////////////////////////
void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {

        case 'N':
        case 'n':
            day=0;
            break;
        case 'D':
        case 'd':
            day=1;
            break;
        case 'C':
        case 'c':
            cloudstatus=1;
            break;
        case 'X':
        case 'x':
            cloudstatus=0;
            break;
        case 'W':
        case 'w':
            waterstatus=1;
            break;
        case 'Q':
        case 'q':
            waterstatus=0;
            break;
        case 'O':
        case 'o':
            cyclestatus=1;
            break;
        case 'P':
        case 'p':
            cyclestatus=0;
            break;
        case 'H':
        case 'h':
            humanstatus=1;
            break;
        case 'G':
        case 'g':
            humanstatus=0;
            break;
        case 'K':
        case 'k':
            rainstatus=1;
            break;
        case 'L':
        case 'l':
            rainstatus=0;
            break;
        case 'B':
        case 'b':
            birdstatus=1;
            break;
        case 'V':
        case 'v':
            birdstatus=0;
            break;
    }

}
/////////////////////////////////////////keyboard function ends////////////////////////////////////////////////////////////////



int main(int argc, char** argv)
{

    cout << endl << "*********** Rural Village Scenario*************" << endl << endl;
    cout <<"teamamte: Farjana haque Chamok,Kausik Roy,Debabrata Roy" <<endl;
 cout << "ID:201-15-13850,201-15-14102,201-15-13942" <<endl <<endl<< endl;
    cout << "Press D : For Day Mode" << endl;
    cout << "Press N : For Night Mode" << endl<< endl;
    cout << "Press B : To Fly Birds" << endl;
    cout << "Press V : Stop Flying Birds " << endl<< endl;

    cout << "Press C : For Flying Clouds " << endl;
    cout << "Press X : For Stop Clouds " << endl << endl;

    cout << "Press W : For Water Flow " << endl;
    cout << "Press Q : For Stop Water Flow " << endl << endl;
    cout << "Press H : To Walk the man " << endl;
    cout << "Press G : To stop the man "<< endl << endl;
    cout << "Press K : For Start Rain " << endl;
    cout << "Press L : For Stop Rain " << endl << endl;




    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (640, 480);
    glutInitWindowPosition (100, 150);
    glutCreateWindow ("Rural Village Scenario");
    glutPostRedisplay();
    glutDisplayFunc(displayvillage); //called display village() function
    glutKeyboardFunc(keyboard); //called keyboard() function
    myInit ();
    glutMainLoop();
    return 0;
}
