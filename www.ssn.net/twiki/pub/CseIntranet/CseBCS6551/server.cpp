//home
#include<GL/glut.h>
void myInit() {
glClearColor(1.0,1.0,1.0,0.0);
glPointSize(10);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,640.0,0.0,480.0);
}

void myDisplay() {
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_QUADS);
glColor3f(0.0f,1.0f,0.6f);
glVertex2d(300,200);
glVertex2d(100,200);
glVertex2d(100,10);
glVertex2d(300,10);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2d(300,200);
glVertex2d(100,200);
glVertex2d(200,300);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,0.6f);
glVertex2d(180,100);
glVertex2d(130,100);
glVertex2d(130,10);
glVertex2d(180,10);
glEnd();
glFlush();
}

int main(int argc,char* argv[]) {
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(640,480);
glutCreateWindow("First Exercise");
glutDisplayFunc(myDisplay);
myInit();
glutMainLoop();
return 1;   
  }



  
  
  
  
  
  
  
  
  
  
  
//dda


#include<GLUT/glut.h>
#include<math.h>
#include<iostream>
int X1=0,X2=0, Y1=0, Y2=0;
void myInit() {
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0f,0.0f,0.0f);
    glPointSize(1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-640/2.0, 640/2.0, -480/2.0, 480/2.0);
    
}
void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_POINTS);
    
    //main algo
    float x=X1*1.0,y=Y1*1.0;
    float m;
    m=(y-Y2)/(x-X2);
    //case1
    if(m<=1 && m>=-1)
    {
        if(x>X2)
        {
            int tmp=x;
            x=X2;
            X2=tmp;
            tmp=y;
            y=Y2;
            Y2=tmp;
        }
        while(x!=X2)
        {
            glVertex2d(x, round(y));
            x++;
            y+=m;
        }
    }
    else{
        if(y>Y2)
        {
            int tmp=x;
            x=X2;
            X2=tmp;
            tmp=y;
            y=Y2;
            Y2=tmp;
        }
        while(y!=Y2)
        {
            glVertex2d(round(x), y);
            y++;
            x+=(1/m);
        }
    }
    
    glEnd();
    glFlush();
    }
int main(int argc,char* argv[]) {
    std::cout<<"Enter x1:\t";
    std::cin>>X1;
    std::cout<<"Enter y1:\t";
    std::cin>>Y1;
    std::cout<<"Enter x2:\t";
    std::cin>>X2;
    std::cout<<"Enter y2:\t";
    std::cin>>Y2;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutCreateWindow("House");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 1;
}







//bress

#include<GLUT/glut.h>
#include <iostream>
using namespace std;
void init()
{
    gluOrtho2D(-200, 200, -200, 200);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}
void draw_line(int xa,int ya,int xb,int yb)
{
    int dx,dy;
    int x=xa,y=ya,incx,incy;
    dx=abs(xb-xa);
    dy=abs(yb-ya);
    if(xa>xb)
    {
        incx=-1;
        incy=-1;
    }
    else
    {
        incx=1;
        incy=1;
    }
    glBegin(GL_POINTS);
    if(dx>dy)
    {
        int p=2*dy-dx;
        glVertex2d(x,y);
        for(int i=0;i<dx;i++)
        {
            x+=incx;
            if(p<0)
                p+=2*dy;
            else
            {
                p+=2*(dy-dx);
                y+=incy;
            }
            cout<<x<<','<<y<<endl;
            glVertex2d(x, y);
        }
    }
    else
    {
        int p=2*dx-dy;
        glVertex2d(x,y);
        for(int i=0;i<dy;i++)
        {
            y+=incy;
            if(p<0)
                p+=2*dx;
            else
            {
                p+=2*(dx-dy);
                x+=incy;
            }
            cout<<x<<','<<y<<endl;
            glVertex2d(x,y);
        }
    }
    glEnd();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    draw_line(100,100,30,100);
    draw_line(100,100,40,0);
    glFlush();
}
int main(int argc,  char * argv[]) {
    // insert code here...
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutInitWindowSize(400,400);
    glutCreateWindow("line");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}







//mid
#include <stdio.h>
#include <iostream>
#include <GL/GLUT.h>
using namespace std;

int pntX1, pntY1, r;

void plot(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x+pntX1, y+pntY1);
    glEnd();
}


void myInit (void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}


void midPointCircleAlgo()
{
    int x = 0;
    int y = r;
    float decision = 5/4 - r;
    plot(x, y);
    
    while (y > x)
    {
        if (decision < 0)
        {
            x++;
            decision += 2*x+1;
        }
        else
        {
            y--;
            x++;
            decision += 2*(x-y)+1;
        }
        plot(x, y);
        plot(x, -y);
        plot(-x, y);
        plot(-x, -y);
        plot(y, x);
        plot(-y, x);
        plot(y, -x);
        plot(-y, -x);
    }
    
}

void myDisplay(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 0.0);
    glPointSize(1.0);
    
    midPointCircleAlgo();
    
    glFlush ();
}

int main(int argc, char** argv)
{
    cout << "Enter the coordinates of the center:\n\n" << endl;
    
    cout << "X-coordinate   : "; cin >> pntX1;
    cout << "\nY-coordinate : "; cin >> pntY1;
    cout << "\nEnter radius : "; cin >> r;
    
    
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (640, 480);
    glutInitWindowPosition (100, 150);
    glutCreateWindow ("Line Drawing Alogrithms");
    glutDisplayFunc(myDisplay);
    myInit ();
    glutMainLoop();
    
}






//2dt

    #include <iostream>
    #include<GLUT/GLUT.h>
    #include<math.h>
    using namespace std;
    int i,j;
    void myInit (void)
    {
        glClearColor(1.0, 1.0, 1.0, 0.0);
        glColor3f(0.0f, 0.0f, 0.0f);
        glPointSize(10);
       glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
       gluOrtho2D(-800.0,800.0,-800.0,800.0);
    }
    void drawtext(int x,int y)
    {
        glColor3f(0.0f,0.0f,0.0f);
        glRasterPos2i(x,y);
        char str[20],*c;
        sprintf(str,"(%d,%d)",x,y);
        for(c=str; *c!='\0';c++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,*c);}
        glutSwapBuffers();
    }
    void identity_matrix(float m[3][4])
    // Initialises the matrix as Unit Matrix
    {
        for (i=0; i<3; i++){
            for (j=0; j<3; j++){
               if(i==j)
                   m[i][j]=1.0;
               else
                   m[i][j]=0.0;
            }        }    }

    void draw_quad(float m[3][4]){
        glColor3f(0.1f,1.0f,2.0f);
        for(i=0;i<4;i++){
            glVertex2d(m[0][i],m[1][i]);
        }
        glEnd();
        for(i=0;i<4;i++){
            drawtext(m[0][i],m[1][i]);}
            glBegin(GL_QUADS);
    }

    void matmul(float mat1[3][4],float mat2[3][4])
    {
        float mat3[3][4];
        for (i = 0; i < 3; i++)
            for (j = 0; j < 4; j++){
                mat3[i][j]=0.0;
                for(int k=0;k<3;k++){
                    mat3[i][j]+=mat1[i][k]*mat2[k][j];
                }
            }
            for(i=0;i<3;i++)
            {
                for(j=0;j<4;j++){
                    mat1[i][j]=mat3[i][j];
                }            }    }

    void translate(float pmat[][4],float tx,float ty)
    {
        float [3][4];
        identity_matrix(m);
        m[0][2]=tx;
        m[1][2]=ty;
        matmul(m,pmat);
        cout<<"The matrix after translation is:";
        for(i=0;i<3;i++){
            for(j=0;j<4;j++){
                cout<<m[i][j]<<"\t";}
            cout<<endl;
        }
            draw_quad(m);
        }

    void rotate(float pmat[][4],float rad,float tx,float ty)
    {
            float m[3][4];
            identity_matrix(m);
            m[0][0] = cos(rad);
            m[0][1] = -sin(rad) ;
            m[0][2] = tx*(1 - cos(rad)) + ty*sin(rad);
            m[1][0] = sin(rad);
            m[1][1] = cos(rad);
            m[1][2] = tx*(1 - cos(rad)) - ty*sin(rad);
            matmul(m,pmat);
            draw_quad(m);
    }

    void scaling(float pmat[][4],float sx,float sy,float tx,float ty)
    {
        float m[3][4];
        identity_matrix(m);
        m[0][0] = sx;
        m[0][2] = (1 - sx)*tx;
        m[1][1] = sy;
        m[1][2] = (1 - sy)*ty;
        matmul(m,pmat);
        draw_quad(m);
    }
        void reflection(float pmat[][4])
        {
            float m[3][4];
            identity_matrix(m);
            m[1][1]=-1;
            matmul(m, pmat);;
            draw_quad(m);
        }

        void shear(float pmat[][4], float shx, float shy, float tx, float ty)
        {
            float m[3][4];
            identity_matrix(m);
            m[0][1]=shx;
            m[0][2]=-1*tx*shx;
            m[1][0]=shy;
            m[1][2]=-1*ty*shy;
            matmul(m, pmat);
            draw_quad(m);
        }

        void myDisplay()
        {
            float xa[5], ya[5], tx, ty, pmat[3][4], degree;
            int opt=1, choice;
            glClear(GL_COLOR_BUFFER_BIT);
            glBegin(GL_LINES);
            glVertex2d(0, -480);
            glVertex2d(0, 480);
            glVertex2d(-640, 0);
            glVertex2d(640, 0);
            glEnd();
        for(i=0; i<4; i++){
            cout<<"Enter x dimensions : ";
            cin>>xa[i];
            pmat[0][i]=xa[i];
                    }

        for(i=0; i<4; i++){
            cout<<"Enter y dimensions : ";
            cin>>ya[i];
            pmat[1][i]=ya[i];
        }

        for(i=0; i<4; i++){
            drawtext(xa[i], ya[i]);
                  }

        glBegin(GL_QUADS);
        for(i=0; i<4; i++)
        {
            glVertex2d(xa[i],ya[i]);
            pmat[2][i]=1;
        }

        cout<<"\n The Quad point matrix is:\n";
        for(i=0;i<3;i++)
        {for(j=0;j<4;j++)
        {cout<<pmat[i][j]<<"\t";}cout<<endl;}
        cout<<"\nMENU \n 1.Translation\n 2.Rotation \n 3.Scaling \n 4.Reflection \n 5.Shearing\n";
        while(opt==1){
            cout<<"Enter choice:";
            cin>>choice;
            switch(choice)
            {
	    case 1:{cout<<"Enter the translation points";
                cin>>tx>>ty;
                translate(pmat,tx,ty);
                break;
            }
                case 2:{cout<<"Enter the rotation angle:";
                    cin>>degree;
                    cout<<"enter the reference point";
                    cin>>tx>>ty;
                    float rad=(degree*3.14)/180;
                    rotate(pmat,rad,tx,ty);
                    break;
                }
                case 3:{
                    float sx, sy;
                    cout<<"Enter the scalingand reference points: ";
                    cin>>sx>>sy>>tx>>ty;
                    scaling(pmat, sx, sy, tx,ty);
                    break;
                }
            case 4:{
                cout <<"Reflection wrt to y axis!";
                reflection(pmat);
                break;
            }

        case 5:{
            float shx, shy;
            cout<<"Enter Shear points: ";
            cin>>shx>>shy;
            shear(pmat, shx, shy, tx, ty);
            break;
        }
        deafult:
            break;
        }
        cout<<"Do you want to continue:";
        cin>>opt;
    }
    glFlush();
    }
    int main(int argc, char* argv[]){
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
        glutInitWindowSize(800,800);
        glutCreateWindow("2D transformations");
        glutDisplayFunc(myDisplay);
        myInit();
        glutMainLoop();
        return 1;
    }

	
	
	



	
	
	
//2dc
#include<GLUT/glut.h> 
#include<iostream> 
#include<math.h> 
using namespace std; 
#define PI 3.14159265 
void myInit() { 
glClearColor(1.0,1.0,1.0,0.0); 
glColor3f(0.0f,0.0f,0.0f); 
glPointSize(10); 
glMatrixMode(GL_PROJECTION); 
glLoadIdentity(); 
gluOrtho2D(0.0,640.0,0.0,640.0); 
} 
void myDisplay() { 
glClear(GL_COLOR_BUFFER_BIT); 
glBegin(GL_LINES); 
glVertex2d(320,0); 
glVertex2d(320, 640); 
glEnd(); 
glBegin(GL_LINES); 
glVertex2d(0,320); 
glVertex2d(640,320); 
glEnd(); 
float x1,y1,x2,y2,x3,y3,tx,ty,px,py,x,y,sx,sy,xf,yf,shx,shy,x4,y4; 
int i,j,k=0,count=1,l=0,theta,ch1,ch2,rch,sch; 
float a[3][3]={0}; 
float b[3][1]={0}; 
float c[3][3]={0}; 
float ans[3][1]={0}; 
float comp1[3][3]={0}; 
float comp2[3][3]={0}; 
float arr[10]; 
cout<<"Enter vertices of a square:"; 
cout<<"\nEnter first coordinate"; 
cin>>x1>>y1; 
cout<<"Enter second coordinate"; 
cin>>x2>>y2; 
cout<<"Enter third coordinate"; 
cin>>x3>>y3; 
cout<<"Enter fourth coordinate"; 
cin>>x4>>y4; 
glBegin(GL_QUADS); 
glVertex2d(x1, y1); 
glVertex2d(x2, y2); 
glVertex2d(x3, y3); 
glVertex2d(x4, y4); 
glEnd(); 
cout<<"MENU\n1.Translation\n2.Rotation\n3.Scaling\n4.Reflection\n5.Shearing\n"; 
cout<<"\nEnter first transformation"; 
cin>>ch1; 
cout<<"\nEnter second transformation"; 
cin>>ch2; 
cout<<"\nFIRST TRANSFORMATION\n"; 
if(ch1==1) 
{ 
cout<<"Enter translation distances:"; 
cin>>tx>>ty; 
for(i=0;i<3;i++) 
{a[i][i]=1; 
} 
a[0][2]=tx; 
a[1][2]=ty; 
} 
else if(ch1==2) 
{ 
cout<<"Enter rotation angle:"; 
cin>>theta; 
for(i=0;i<3;i++) 
{a[i][i]=1; 
} 
a[0][0]=cos(theta*PI/180); 
a[0][1]=-1*sin(theta*PI/180); 
a[1][0]=sin(theta*PI/180); 
a[1][1]=cos(theta*PI/180); 
} 
else if(ch1==3) 
{ 
cout<<"Enter scaling wrt x direction"; 
cin>>sx; 
cout<<"Enter scaling wrt y direction:"; 
cin>>sy; 
for(i=0;i<3;i++) 
{a[i][i]=1; 
} 
a[0][0]=sx; 
a[1][1]=sy; 
}
else if(ch1==4) 
{ 
cout<<"\t1.Reflection wrt x axis\n2.Reflection wrt hy axis\n3.Reflection wrt x=y\n4.Reflection wrt origin\nEnter choice: "; 
cin>>rch; 
if(rch==1) 
{ 
for(i=0;i<3;i++) 
{a[i][i]=1; 
} 
a[1][1]=-1; 
} 
else if(rch==2) 
{ 
for(i=0;i<3;i++) 
{a[i][i]=1; 
} 
a[0][0]=-1; 
} 
else if(rch==3) 
{ 
for(i=0;i<3;i++) 
{a[i][i]=1; 
} 
a[0][1]=1; 
a[1][0]=1; 
a[0][0]=0; 
a[1][1]=0; 
} 
else{ 
for(i=0;i<3;i++) 
{a[i][i]=1; 
} 
a[0][0]=-1; 
a[1][1]=-1; 
} 
} 
else if(ch1==5) 
{ 
cout<<"\t1.Shearing wrt x axis\n2.Shearing wrt hy axis\nEnter choice: "; 
cin>>sch; 
if(sch==1) 
{
cout<<"Enter shear wrt x direction: "; 
cin>>shx; 
for(i=0;i<3;i++) 
{a[i][i]=1; 
} 
a[0][1]=shx; 
} 
else 
{ 
cout<<"Enter shear wrt y direction: "; 
cin>>shy; 
for(i=0;i<3;i++) 
{a[i][i]=1; 
	} 
a[1][0]=shy; 
		} 
			} 
for(i=0;i<3;i++) 
for(j=0;j<3;j++) 
comp1[i][j]=a[i][j]; 
for(i=0;i<3;i++) 
for(j=0;j<3;j++) 
a[i][j]=0; 
cout<<"\nSECOND TRANSFORMATION\n"; 
if(ch2==1) 
{ 
cout<<"Enter translation distances:"; 
cin>>tx>>ty; 
for(i=0;i<3;i++) 
{  a[i][i]=1; } 
a[0][2]=tx; 
a[1][2]=ty; 
} 
else if(ch2==2) 
{ 
cout<<"Enter rotation angle:"; 
cin>>theta; 
for(i=0;i<3;i++) 
{a[i][i]=1; 
} 
a[0][0]=cos(theta*PI/180); 
a[0][1]=-1*sin(theta*PI/180); 
a[1][0]=sin(theta*PI/180); 
a[1][1]=cos(theta*PI/180); 
} 
else if(ch2==3) 
{ 
cout<<"Enter scaling wrt x direction"; 
cin>>sx; 
cout<<"Enter scaling wrt y direction:"; 
cin>>sy; 
for(i=0;i<3;i++) 
{a[i][i]=1; 
} 
a[0][0]=sx; 
a[1][1]=sy; 
} 
else if(ch2==4) 
{ 
cout<<"\t1.Reflection wrt x axis\n2.Reflection wrt y axis\n3.Reflection wrt x=y\nEnter choice: "; 
cin>>rch; 
if(rch==1) 
{ 
for(i=0;i<3;i++) 
{a[i][i]=1; 
} 
a[1][1]=-1; 
} 
else if(rch==2) 
{ 
for(i=0;i<3;i++) 
{a[i][i]=1; 
} 
a[0][0]=-1; 
} 
else 
{ 
for(i=0;i<3;i++) 
{a[i][i]=1; 
} 
a[0][1]=1; 
a[1][0]=1; 
a[0][0]=0; 
a[1][1]=0; 
} 
} 
else if(ch2==5) 
{ 
cout<<"\t1.Shearing wrt x axis\n2.Shearing wrt y axis\nEnter choice: "; 
cin>>sch; 
if(sch==1) 
{ 
cout<<"Enter shear wrt x direction: "; 
cin>>shx; 
for(i=0;i<3;i++) 
{a[i][i]=1; 
} 
a[0][1]=shx; 
} 
else 
{ 
cout<<"Enter shear wrt y direction: "; 
cin>>shy; 
for(i=0;i<3;i++) 
{a[i][i]=1; 
} 
a[1][0]=shy; 
} 
} 
for(i=0;i<3;i++) 
for(j=0;j<3;j++) 
comp2[i][j]=a[i][j]; 
count=1; 
while(count<=4) 
{ 
if(count==1) 
{ 
px=x1; 
py=y1; 
} 
else if(count==2) 
{ 
px=x2; 
py=y2; 
} 
else if(count==3) 
{ 
px=x3; 
py=y3; 
} 
else { 
px=x4; 
py=y4; 
} 
b[0][0]=px; 
b[1][0]=py; 
b[2][0]=1; 
for(i=0;i<3;i++) 
{ 
for(j=0;j<3;j++) 
{ 
c[i][j]=0; 
for(k=0;k<3;k++) 
c[i][j]+=comp2[i][k]*comp1[k][j]; 
} 
} 
for(i=0;i<3;i++) 
{ 
for(j=0;j<1;j++) 
{ 
ans[i][j]=0; 
for(k=0;k<3;k++) 
ans[i][j]+=c[i][k]*b[k][j]; 
} 
} 
arr[l++]=ans[0][0]; 
arr[l++]=ans[1][0]; 
count++; 
} 
glBegin(GL_LINE_LOOP); 
glVertex2f(arr[0], arr[1]); 
glVertex2f(arr[2], arr[3]); 
glVertex2f(arr[4], arr[5]); 
glVertex2f(arr[6], arr[7]); 
glEnd(); 
glEnd(); 
glFlush(); 
} 
int main(int argc,char* argv[]) { 
glutInit(&argc,argv); 
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); 
glutInitWindowSize(640,480); 
glutCreateWindow("First Exercise"); 
glutDisplayFunc(myDisplay); 
myInit(); 
glutMainLoop(); 
return 1; 
} 









//win2view
#include<GLUT/glut.h>
#include<iostream>
#include<string.h>
usingnamespacestd;
voidmyInit() {
glClearColor(1.0,1.0,1.0,0.0);
glColor3f(0.0f,0.0f,0.0f);
glPointSize(10);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,640.0,0.0,640.0);
}
//Plot points only
voiddispPoint(int x, int y, intxcoor, intycoor){
glRasterPos2d(xcoor, ycoor);
stringprintX = to_string(x);
stringprintY = to_string(y);
printX = "(" + printX + "," + printY + ")";
for(int k = 0; k <printX.length(); k++) {
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, printX[k]);
    }
}

//Plot string only
voiddispString(string s, intxcoor, intycoor){
glRasterPos2d(xcoor, ycoor);
for(int k = 0; k <s.length(); k++) {
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, s[k]);
    }
}

voidmyDisplay() {
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_LINES);
glVertex2d(320, 0);
glVertex2d(320,640);
glVertex2d(0, 340);
glVertex2d(640,340);
glVertex2d(475, 50);
glVertex2d(475,300);
glVertex2d(350, 175);
glVertex2d(600,175);
glEnd();
float x1,y1,x2,y2,x3,y3,a,b,c,d,e,f,xvmin=350.0,xvmax=600.0,yvmin=50.0,yvmax=300.0,xwmin=0.0,xwmax=640.0,ywmin=0.0,ywmax=640.0;
cout<<"\nEnter the points";
cin>>x1>>y1>>x2>>y2>>x3>>y3;
glBegin(GL_TRIANGLES);
glVertex2d(x1,y1);
glVertex2d(x2,y2);
glVertex2d(x3,y3);
glEnd();

a=(x1-xwmin)*((xvmax-xvmin)/(xwmax-xwmin))+xvmin;
b=(y1-ywmin)*((yvmax-yvmin)/(ywmax-ywmin))+yvmin;
c=(x2-xwmin)*((xvmax-xvmin)/(xwmax-xwmin))+xvmin;
d=(y2-ywmin)*((yvmax-yvmin)/(ywmax-ywmin))+yvmin;
e=(x3-xwmin)*((xvmax-xvmin)/(xwmax-xwmin))+xvmin;
f=(y3-ywmin)*((yvmax-yvmin)/(ywmax-ywmin))+yvmin;
cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f;

glBegin(GL_LINE_LOOP);
glVertex2d(xvmin,yvmin);
glVertex2d(xvmax,yvmin);
glVertex2d(xvmax,yvmax);
glVertex2d(xvmin,yvmax);
glEnd();
glFlush();

glBegin(GL_TRIANGLES);
glVertex2d(a,b);
glVertex2d(c,d);
glVertex2d(e,f);
glEnd();
dispPoint(100, 100, 90, 85);
dispPoint(150, 300, 150, 310);
dispPoint(200, 100, 210, 90);
dispString("Window", 10, 630);
dispPoint(a, b, a-10, b-10);
dispPoint(c, d, c+5, d-3);
dispPoint(e, f, e+5, f-5);
dispString("Viewport", 340, 300);
glFlush();
}
int main(intargc,char* argv[]) {
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(640,480);
glutCreateWindow("First Exercise");
glutDisplayFunc(myDisplay);
myInit();
glutMainLoop();
return1;
}











//line

#include <GLUT/GLUT.h>
#include<math.h>
#include<stdio.h>
#include<iostream>

void display();
using namespace std;
float xmin=-100;
float ymin=-100;
float xmax=100;
float ymax=100;
float xd1,yd1,xd2,yd2;


void init(void)
{
    
    glClearColor(0.0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-300,300,-300,300);
    
}

int code(float x,float y)
{
    int c=0;
    if(y>ymax)c=8;
    if(y<ymin)c=4;
    if(x>xmax)c=c|2;
    if(x<xmin)c=c|1;
    return c;
}

void cohen_Line(float x1,float y1,float x2,float y2)
{
    int c1=code(x1,y1);
    int c2=code(x2,y2);
    float m=(y2-y1)/(x2-x1);
    while((c1|c2)>0)
    {
        if((c1 & c2)>0)
        {
            exit(0);
        }
        
        float xi=x1;float yi=y1;
        int c=c1;
        if(c==0)
        {
            c=c2;
            xi=x2;
            yi=y2;
        }
        float x,y;
        if((c & 8)>0)
        {
            y=ymax;
            x=xi+ 1.0/m*(ymax-yi);
        }
        else
            if((c & 4)>0)
            {
                y=ymin;
                x=xi+1.0/m*(ymin-yi);
            }
            else
                if((c & 2)>0)
                {
                    x=xmax;
                    y=yi+m*(xmax-xi);
                }
                else
                    if((c & 1)>0)
                    {
                        x=xmin;
                        y=yi+m*(xmin-xi);
                    }
        
        if(c==c1)
        {
            xd1=x;
            yd1=y;
            c1=code(xd1,yd1);
        }
        
        if(c==c2)
        {
            xd2=x;
            yd2=y;
            c2=code(xd2,yd2);
        }
    }
    
    display();
    
}

void mykey(unsigned char key,int x,int y)
{
    if(key=='c')
    {  cout<<"Hello";
        cohen_Line(xd1,yd1,xd2,yd2);
        glFlush();
    }
}
void display()
{
    
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,1.0,0.0);
    
    glBegin(GL_LINE_LOOP);
    glVertex2i(xmin,ymin);
    glVertex2i(xmin,ymax);
    glVertex2i(xmax,ymax);
    glVertex2i(xmax,ymin);
    glEnd();
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2i(xd1,yd1);
    glVertex2i(xd2,yd2);
    glEnd();
    glFlush();
}
int main(int argc,char** argv)
{
    printf("Enter line co-ordinates:");
    cin>>xd1>>yd1>>xd2>>yd2;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Clipping");
    glutDisplayFunc(display);
    glutKeyboardFunc(mykey);
    init();
    glutMainLoop();
    return 0;
}








//3DR
#include <GLUT/glut.h>
#include<iostream>
#include<math.h>
using namespace std;

float tx,ty,tz,a[4][4]={0},px,py,pz,b[4][1]={0},d[4][1];
int i,j,k,c=0;
float x[10]; //= {0,50,50,0,0,50,50,0};
float y[10]; //= {0,0,0,0,50,50,50,50};
float z[10]; //= {0,0,50,50,0,0,50,50};

void init()
{
    //glClearColor(1.0,1.0,1.0,1.0);
    //glColor3f(0.5f,0.5f,0.5f);
    glPointSize(3);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-500,500,-500,500,-500,500); //Setting up the Viewvolume
    glEnable(GL_DEPTH_TEST);
}

void matrixMul()
{
    for(i=0;i<4;++i)
    {
        for(j=0;j<1;++j)
        {
            d[i][j]=0;
            for(k=0;k<4;++k)
                d[i][j]+=a[i][k]*b[k][j];
        }
    }
}

void rotate(int opt)
{
    for(i=0;i<4;++i)
    {
        a[i][i]=1;
    }
    if(opt == 1)
    {
        a[1][1] = cos(1.0472);//60 degree in radians
        a[1][2] = -sin(1.0472);
        a[2][1] = -a[1][2];
        a[2][2] = a[1][1];
    }
    else if(opt == 2)
    {
        a[0][0] = cos(1.0472);//60 degree in radians
        a[0][2] = -sin(1.0472);
        a[2][0] = -a[0][2];
        a[2][2] = a[0][0];
    }
    
    else if(opt == 3)
    {
        a[0][0] = cos(1.0472);//60 degree in radians
        a[0][1] = -sin(1.0472);
        a[1][0] = -a[0][1];
        a[1][1] = a[0][0];
    }
    
    c = 0;
    while(c<8)
    {
        if(c==0)
        {
            px=x[0];
            py=y[0];
            pz=z[0];
        }
        else if(c==1)
        {
            px=x[1];
            py=y[1];
            pz=z[1];
        }
        if(c==2)
        {
            px=x[2];
            py=y[2];
            pz=z[2];
        }
        if(c==3)
        {
            px=x[3];
            py=y[3];
            pz=z[3];
            
        }
        if(c==4)
        {
            px=x[4];
            py=y[4];
            pz=z[4];
        }
        if(c==5)
        {
            px=x[5];
            py=y[5];
            pz=z[5];
        }
        if(c==6)
        {
            px=x[6];
            py=y[6];
            pz=z[6];
        }
        if(c==7)
        {
            px=x[7];
            py=y[7];
            pz=z[7];
        }
        b[0][0]=px;
        b[1][0]=py;
        b[2][0]=pz;
        b[3][0]=1;
        
        matrixMul();
        
        x[c]=d[0][0];
        y[c]=d[1][0];
        z[c]=d[2][0];
        c++;
    }
}

void dispFace(float x[], float y[], float z[])
{
    glColor3ub(255, 0, 0);
    glBegin(GL_QUADS);//bottom
    glVertex3f(x[0],y[0],z[0]);
    glVertex3f(x[1],y[1],z[1]);
    glVertex3f(x[2],y[2],z[2]);
    glVertex3f(x[3],y[3],z[3]);
    glEnd();
    glFlush();
    
    glColor3ub(0, 255, 0);
    glBegin(GL_QUADS);//top
    glVertex3f(x[4],y[4],z[4]);
    glVertex3f(x[5],y[5],z[5]);
    glVertex3f(x[6],y[6],z[6]);
    glVertex3f(x[7],y[7],z[7]);
    glEnd();
    glFlush();
    
    glColor3ub(0, 0, 255);
    glBegin(GL_QUADS);//front
    glVertex3f(x[3],y[3],z[3]);
    glVertex3f(x[7],y[7],z[7]);
    glVertex3f(x[6],y[6],z[6]);
    glVertex3f(x[2],y[2],z[2]);
    glEnd();
    glFlush();
    
    glColor3ub(255, 255, 0);
    glBegin(GL_QUADS);//right
    glVertex3f(x[2],y[2],z[2]);
    glVertex3f(x[1],y[1],z[1]);
    glVertex3f(x[5],y[5],z[5]);
    glVertex3f(x[6],y[6],z[6]);
    glEnd();
    glFlush();
    
    glColor3ub(0, 255, 255);
    glBegin(GL_QUADS);//back
    glVertex3f(x[0],y[0],z[0]);
    glVertex3f(x[1],y[1],z[1]);
    glVertex3f(x[5],y[5],z[5]);
    glVertex3f(x[4],y[4],z[4]);
    glEnd();
    glFlush();
    
    glColor3ub(255, 0, 255);
    glBegin(GL_QUADS);//left
    glVertex3f(x[0],y[0],z[0]);
    glVertex3f(x[3],y[3],z[3]);
    glVertex3f(x[7],y[7],z[7]);
    glVertex3f(x[4],y[4],z[4]);
    glEnd();
    glFlush();
}
void display()
{
    int opt = 1;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //int tx,ty,tz,a[4][4]={0},x[10],y[10],z[10],i,c=0,px,py,pz,b[4][1]={0},d[4][1],j,k;
    
    glBegin(GL_LINES);
    //x-axis
    glColor3ub(255, 0, 0);
    glVertex3f(-500, 0, 0);
    glVertex3f(500, 0, 0);
    //y-axis
    glColor3ub(0, 255, 0);
    glVertex3f(0, -500, 0);
    glVertex3f(0, 500, 0);
    //z-axis
    glColor3ub(0, 0, 255);
    glVertex3f(-0, 0, -500);
    glVertex3f(0, 0, 500);
    glEnd();
    
    //cout<<"enter the translation factor:";
    //cin>>tx>>ty>>tz;
    
    //cout<<"\nROTATION\n1.x-axis\n2.y-axis\n3.z-axis\nEnter option: ";
    //cin>>opt;
    
    x[0]=50;
    y[0]=50;
    z[0]=50;
    
    x[1]=100;
    y[1]=50;
    z[1]=50;
    
    x[2]=100;
    y[2]=50;
    z[2]=100;
    
    x[3]=50;
    y[3]=50;
    z[3]=100;
    
    x[4]=50;
    y[4]=100;
    z[4]=50;
    
    x[5]=100;
    y[5]=100;
    z[5]=50;
    
    x[6]=100;
    y[6]=100;
    z[6]=100;
    
    x[7]=50;
    y[7]=100;
    z[7]=100;
    
    dispFace(x, y, z);
    
    rotate(opt);
    
    dispFace(x, y, z);
    
    for(i=0;i<8;i++)
    {
        cout<<x[i]<<","<<y[i]<<","<<z[i]<<"\n";
    }
}


void keyboard(unsigned char key,int x,int y)
{
    switch(key)
    {
        case 'u':
        case 'U':
            glRotatef(-10.0,1.0,0.0,0.0);
            break;
        case 'd':
        case 'D':
            glRotatef(10.0,1.0,0.0,0.0);
            break;
        case 'l':
        case 'L':
            glRotatef(-10.0,0.0,1.0,0.0);
            break;
        case 'r':
        case 'R':
            glRotatef(10.0,0.0,1.0,0.0);
            break;
    }
    display();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,640);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_SINGLE);
    glutCreateWindow("3D Rotation along x-axis by 60 degrees");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();
    return 0;
}










//3DS

#include <GLUT/glut.h>
#include<iostream>
#include<math.h>
using namespace std;

float tx,ty,tz,a[4][4]={0},px,py,pz,b[4][1]={0},d[4][1];
int i,j,k,c=0;
float x[10]; //= {0,50,50,0,0,50,50,0};
float y[10]; //= {0,0,0,0,50,50,50,50};
float z[10]; //= {0,0,50,50,0,0,50,50};

void init()
{
    //glClearColor(1.0,1.0,1.0,1.0);
    //glColor3f(0.5f,0.5f,0.5f);
    glPointSize(3);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-500,500,-500,500,-500,500); //Setting up the Viewvolume
    glEnable(GL_DEPTH_TEST);
}

void matrixMul()
{
    for(i=0;i<4;++i)
    {
        for(j=0;j<1;++j)
        {
            d[i][j]=0;
            for(k=0;k<4;++k)
                d[i][j]+=a[i][k]*b[k][j];
        }
    }
}

void scale()
{
    for(i=0;i<4;++i)
    {
        a[i][i]=1;
    }

    a[0][0] = 1; //Scaling factor along x
    a[1][1] = 2; //Scaling factor along y
    a[2][2] = 3; //Scaling factor along z
    
    c = 0;
    while(c<8)
    {
        if(c==0)
        {
            px=x[0];
            py=y[0];
            pz=z[0];
        }
        else if(c==1)
        {
            px=x[1];
            py=y[1];
            pz=z[1];
        }
        if(c==2)
        {
            px=x[2];
            py=y[2];
            pz=z[2];
        }
        if(c==3)
        {
            px=x[3];
            py=y[3];
            pz=z[3];
            
        }
        if(c==4)
        {
            px=x[4];
            py=y[4];
            pz=z[4];
        }
        if(c==5)
        {
            px=x[5];
            py=y[5];
            pz=z[5];
        }
        if(c==6)
        {
            px=x[6];
            py=y[6];
            pz=z[6];
        }
        if(c==7)
        {
            px=x[7];
            py=y[7];
            pz=z[7];
        }
        b[0][0]=px;
        b[1][0]=py;
        b[2][0]=pz;
        b[3][0]=1;
        
        matrixMul();
        
        x[c]=d[0][0];
        y[c]=d[1][0];
        z[c]=d[2][0];
        c++;
    }
}

void dispFace(float x[], float y[], float z[])
{
    glColor3ub(255, 0, 0);
    glBegin(GL_QUADS);//bottom
    glVertex3f(x[0],y[0],z[0]);
    glVertex3f(x[1],y[1],z[1]);
    glVertex3f(x[2],y[2],z[2]);
    glVertex3f(x[3],y[3],z[3]);
    glEnd();
    glFlush();
    
    glColor3ub(0, 255, 0);
    glBegin(GL_QUADS);//top
    glVertex3f(x[4],y[4],z[4]);
    glVertex3f(x[5],y[5],z[5]);
    glVertex3f(x[6],y[6],z[6]);
    glVertex3f(x[7],y[7],z[7]);
    glEnd();
    glFlush();
    
    glColor3ub(0, 0, 255);
    glBegin(GL_QUADS);//front
    glVertex3f(x[3],y[3],z[3]);
    glVertex3f(x[7],y[7],z[7]);
    glVertex3f(x[6],y[6],z[6]);
    glVertex3f(x[2],y[2],z[2]);
    glEnd();
    glFlush();
    
    glColor3ub(255, 255, 0);
    glBegin(GL_QUADS);//right
    glVertex3f(x[2],y[2],z[2]);
    glVertex3f(x[1],y[1],z[1]);
    glVertex3f(x[5],y[5],z[5]);
    glVertex3f(x[6],y[6],z[6]);
    glEnd();
    glFlush();
    
    glColor3ub(0, 255, 255);
    glBegin(GL_QUADS);//back
    glVertex3f(x[0],y[0],z[0]);
    glVertex3f(x[1],y[1],z[1]);
    glVertex3f(x[5],y[5],z[5]);
    glVertex3f(x[4],y[4],z[4]);
    glEnd();
    glFlush();
    
    glColor3ub(255, 0, 255);
    glBegin(GL_QUADS);//left
    glVertex3f(x[0],y[0],z[0]);
    glVertex3f(x[3],y[3],z[3]);
    glVertex3f(x[7],y[7],z[7]);
    glVertex3f(x[4],y[4],z[4]);
    glEnd();
    glFlush();
}
void display()
{
    int opt = 1;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //int tx,ty,tz,a[4][4]={0},x[10],y[10],z[10],i,c=0,px,py,pz,b[4][1]={0},d[4][1],j,k;
    
    glBegin(GL_LINES);
    //x-axis
    glColor3ub(255, 0, 0);
    glVertex3f(-500, 0, 0);
    glVertex3f(500, 0, 0);
    //y-axis
    glColor3ub(0, 255, 0);
    glVertex3f(0, -500, 0);
    glVertex3f(0, 500, 0);
    //z-axis
    glColor3ub(0, 0, 255);
    glVertex3f(-0, 0, -500);
    glVertex3f(0, 0, 500);
    glEnd();
    
    //cout<<"enter the translation factor:";
    //cin>>tx>>ty>>tz;
    
    //cout<<"\nROTATION\n1.x-axis\n2.y-axis\n3.z-axis\nEnter option: ";
    //cin>>opt;
    
    x[0]=50;
    y[0]=50;
    z[0]=50;
    
    x[1]=100;
    y[1]=50;
    z[1]=50;
    
    x[2]=100;
    y[2]=50;
    z[2]=100;
    
    x[3]=50;
    y[3]=50;
    z[3]=100;
    
    x[4]=50;
    y[4]=100;
    z[4]=50;
    
    x[5]=100;
    y[5]=100;
    z[5]=50;
    
    x[6]=100;
    y[6]=100;
    z[6]=100;
    
    x[7]=50;
    y[7]=100;
    z[7]=100;
    
    dispFace(x, y, z);
    
    scale();
    
    dispFace(x, y, z);
    
    for(i=0;i<8;i++)
    {
        cout<<x[i]<<","<<y[i]<<","<<z[i]<<"\n";
    }
}


void keyboard(unsigned char key,int x,int y)
{
    switch(key)
    {
        case 'u':
        case 'U':
            glRotatef(-10.0,1.0,0.0,0.0);
            break;
        case 'd':
        case 'D':
            glRotatef(10.0,1.0,0.0,0.0);
            break;
        case 'l':
        case 'L':
            glRotatef(-10.0,0.0,1.0,0.0);
            break;
        case 'r':
        case 'R':
            glRotatef(10.0,0.0,1.0,0.0);
            break;
    }
    display();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,640);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_SINGLE);
    glutCreateWindow("3D Scaling by (2,3,4)");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();
    return 0;
}








//3DT

#include <GLUT/glut.h>
#include<iostream>
using namespace std;

int tx,ty,tz,a[4][4]={0},c=0,px,py,pz,b[4][1]={0},d[4][1],i,j,k;
int x[10] = {0,50,50,0,0,50,50,0};
int y[10] = {0,0,0,0,50,50,50,50};
int z[10] = {0,0,50,50,0,0,50,50};

void init()
{
    //glClearColor(1.0,1.0,1.0,1.0);
    //glColor3f(0.5f,0.5f,0.5f);
    glPointSize(3);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-500,500,-500,500,-500,500); //Setting up the Viewvolume
    glEnable(GL_DEPTH_TEST);
}

void matrixMul()
{
    for(i=0;i<4;++i)
    {
        for(j=0;j<1;++j)
        {
            d[i][j]=0;
            for(k=0;k<4;++k)
                d[i][j]+=a[i][k]*b[k][j];
        }
    }
}

void translate()
{
    c = 0;
    for(i=0;i<4;++i)
    {
        a[i][i]=1;
    }
    a[0][3]=100;
    a[1][3]=100;
    a[2][3]=100;
    while(c<8)
    {
        if(c==0)
        {
            px=x[0];
            py=y[0];
            pz=z[0];
        }
        else if(c==1)
        {
            px=x[1];
            py=y[1];
            pz=z[1];
        }
        if(c==2)
        {
            px=x[2];
            py=y[2];
            pz=z[2];
        }
        if(c==3)
        {
            px=x[3];
            py=y[3];
            pz=z[3];
            
        }
        if(c==4)
        {
            px=x[4];
            py=y[4];
            pz=z[4];
        }
        if(c==5)
        {
            px=x[5];
            py=y[5];
            pz=z[5];
        }
        if(c==6)
        {
            px=x[6];
            py=y[6];
            pz=z[6];
        }
        if(c==7)
        {
            px=x[7];
            py=y[7];
            pz=z[7];
        }
        b[0][0]=px;
        b[1][0]=py;
        b[2][0]=pz;
        b[3][0]=1;
        
        matrixMul();
        
        x[c]=d[0][0];
        y[c]=d[1][0];
        z[c]=d[2][0];
        c++;
    }
}

void dispFace(int x[], int y[], int z[])
{
    glColor3ub(255, 0, 0);
    glBegin(GL_QUADS);//bottom
    glVertex3f(x[0],y[0],z[0]);
    glVertex3f(x[1],y[1],z[1]);
    glVertex3f(x[2],y[2],z[2]);
    glVertex3f(x[3],y[3],z[3]);
    glEnd();
    
    glColor3ub(0, 255, 0);
    glBegin(GL_QUADS);//top
    glVertex3f(x[4],y[4],z[4]);
    glVertex3f(x[5],y[5],z[5]);
    glVertex3f(x[6],y[6],z[6]);
    glVertex3f(x[7],y[7],z[7]);
    glEnd();
    glFlush();
    
    glColor3ub(0, 0, 255);
    glBegin(GL_QUADS);//front
    glVertex3f(x[3],y[3],z[3]);
    glVertex3f(x[7],y[7],z[7]);
    glVertex3f(x[6],y[6],z[6]);
    glVertex3f(x[2],y[2],z[2]);
    glEnd();
    glFlush();
    
    glColor3ub(255, 255, 0);
    glBegin(GL_QUADS);//right
    glVertex3f(x[2],y[2],z[2]);
    glVertex3f(x[1],y[1],z[1]);
    glVertex3f(x[5],y[5],z[5]);
    glVertex3f(x[6],y[6],z[6]);
    glEnd();
    glFlush();
    
    glColor3ub(0, 255, 255);
    glBegin(GL_QUADS);//back
    glVertex3f(x[0],y[0],z[0]);
    glVertex3f(x[1],y[1],z[1]);
    glVertex3f(x[5],y[5],z[5]);
    glVertex3f(x[4],y[4],z[4]);
    glEnd();
    glFlush();
    
    glColor3ub(255, 0, 255);
    glBegin(GL_QUADS);//left
    glVertex3f(x[0],y[0],z[0]);
    glVertex3f(x[3],y[3],z[3]);
    glVertex3f(x[7],y[7],z[7]);
    glVertex3f(x[4],y[4],z[4]);
    glEnd();
    glFlush();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //int tx,ty,tz,a[4][4]={0},x[10],y[10],z[10],i,c=0,px,py,pz,b[4][1]={0},d[4][1],j,k;
    
    glBegin(GL_LINES);
    //x-axis
    glColor3ub(255, 0, 0);
    glVertex3f(-500, 0, 0);
    glVertex3f(500, 0, 0);
    //y-axis
    glColor3ub(0, 255, 0);
    glVertex3f(0, -500, 0);
    glVertex3f(0, 500, 0);
    //z-axis
    glColor3ub(0, 0, 255);
    glVertex3f(-0, 0, -500);
    glVertex3f(0, 0, 500);
    glEnd();
    
    //cout<<"enter the translation factor:";
    //cin>>tx>>ty>>tz;
    
    x[0]=0;
    y[0]=0;
    z[0]=0;
    
    x[1]=50;
    y[1]=0;
    z[1]=0;
    
    x[2]=50;
    y[2]=0;
    z[2]=50;
    
    x[3]=0;
    y[3]=0;
    z[3]=50;
    
    x[4]=0;
    y[4]=50;
    z[4]=0;
    
    x[5]=50;
    y[5]=50;
    z[5]=0;
    
    x[6]=50;
    y[6]=50;
    z[6]=50;
    
    x[7]=0;
    y[7]=50;
    z[7]=50;
    
    glColor3ub(255, 0, 255);
    dispFace(x, y, z);
    
    translate();
    
    glColor3ub(255, 255, 0);
    dispFace(x, y, z);
}


void keyboard(unsigned char key,int x,int y)
{
    switch(key)
    {
        case 'u':
        case 'U':
            glRotatef(-10.0,1.0,0.0,0.0);
            break;
        case 'd':
        case 'D':
            glRotatef(10.0,1.0,0.0,0.0);
            break;
        case 'l':
        case 'L':
            glRotatef(-10.0,0.0,1.0,0.0);
            break;
        case 'r':
        case 'R':
            glRotatef(10.0,0.0,1.0,0.0);
            break;
    }
    display();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,640);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_SINGLE);
    glutCreateWindow("3D Translation along (100,100,100)");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();
    return 0;
}









//3DP
#include <GL/glew.h>
#include<GL/freeglut.h>
#include<GL/gl.h>
#include<iostream>
using namespace std;
void init()
{
	glClearColor(1.0f,1.0f,1.0f,1.0f);
	glEnable(GL_DEPTH_TEST);
}

void display()
{

	int opt, size;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glColor3f(0.0f,0.0f,0.0f);
	cout << "\nEnter size:";
	cin >> size;
	cout << "\n1.Orthogonal\n2.Perspective\nChoose:";
	cin >> opt;
	if (opt == 1)
	{

		glOrtho(-250, 250, -250, 250, -250, 250); //Setting up the Viewvolume

		gluLookAt(100, 50, 100,   //Camera_x,Camera_y,Camera_z

			0, 0, 0,     //loot at orgin

			0, 1, 0);    // positive Y up vector


		glutSolidCube(size);
	}

	if (opt == 2)
	{
		gluPerspective(120.0, 1.0, 200.0, 30.0);

		gluLookAt(100, 50, 100,   

			0, 0, 0,     

			0, 1, 0);    


		glutSolidCube(size);
	}

	glFlush();

}


int main(int argc, char **argv)

{

	glutInit(&argc, argv);

	glutInitWindowSize(640, 480);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_SINGLE);

	glutCreateWindow("CUBES");

	glutDisplayFunc(display);

	init();

	glutMainLoop();

	return 0;

}








//3DSC

#include<GL/glew.h>
#include<GL/freeglut.h>
#include<GL/gl.h>
#include<iostream>

using namespace std;

void init() {
	glClearColor(1.0f,1.0f,1.0f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-500,500,-500,500,-500,500);
	gluLookAt(100,50,100,
		0,0,0,
		0,1,0
		);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_COLOR_MATERIAL);

    // Create light components
    GLfloat ambientLight[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat diffuseLight[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat specularLight[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat position[] = { 70.0, 100.0, 200.0, 0.0 };
    glShadeModel(GL_SMOOTH);
    
    // Assign created components to GL_LIGHT0
    //glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
   	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    //glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    //glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    float color[] = { 1.0f, 0.0f, 0.0f, 1.0f };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //glGenerateMipmap(GL_TEXTURE_2D);
    float pixels[] = {
        1.0f, 1.0f, 1.0f,   1.0f, 1.0f, 1.0f,
        0.0f, 1.0f, 0.0f,   1.0f, 1.0f, 1.0f
    };
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 2, 2, 0, GL_RGB, GL_FLOAT, pixels);


}

void myDisplay() {
	glClearColor(1.0f,1.0f,1.0f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_QUADS);
	glColor3f(0.4f,0.0f,1.0f);
	glVertex3d(0,0,0); glTexCoord2f(1, 0);
	glVertex3d(500,0,0); glTexCoord2f(0, 1);
	glVertex3d(500,500,0); glTexCoord2f(1, 0);
	glVertex3d(0,500,0); glTexCoord2f(0, 1);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.6f,0.0f,1.0f);
	glVertex3d(0,0,0);  glTexCoord2f(1, 0);
	glVertex3d(0,0,500); glTexCoord2f(0, 1);
	glVertex3d(0,500,500); glTexCoord2f(1, 0);
	glVertex3d(0,500,0); glTexCoord2f(0, 1);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5f,0.1f,1.0f);
	glVertex3d(0,0,0); glTexCoord2f(1, 0);
	glVertex3d(0,0,500); glTexCoord2f(0, 1);
	glVertex3d(500,0,500); glTexCoord2f(1, 0);
	glVertex3d(500,0,0); glTexCoord2f(0, 1);
	glEnd();


	glPushMatrix();
	glTranslatef(200,200,100);
	//glRotatef(30, 0, 0, 0.7);
	glColor3ub(0,255,0);
	glutSolidSphere(100,100,100);  glTexCoord2f(1,0);
	glPopMatrix();

	glFlush();
}

int main(int argc,char* argv[]) {
	glutInit(&argc,argv);
	glutInitWindowSize(500,500);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH);
	glutCreateWindow("3D Scene");
	glutDisplayFunc(myDisplay);
	init();
	glutMainLoop();
	return 0;
}







//wind
#include <GLUT/glut.h>
#include <OpenGL/OpenGL.h>
#include <math.h>
#include <sstream>
#include <unistd.h>
using namespace std;
int a=100,b=0,r=10;
float pie=3.14159;
class Point {
public:
    int x;
    int y;
    Point(int a, int b)
    {
        x=a;
        y=b;
    }
};
void circle(int xc, int yc, int r, bool shade)
{
    glBegin(GL_POINTS);
    int x=0, y=r, pk=1-r;
    //main algo
    while(x<=y)
    {
        glVertex2d(x+xc, y+yc);
        glVertex2d(y+xc, x+yc);
        glVertex2d((x*-1)+xc, y+yc);
        
        glVertex2d((y*-1)+xc, x+yc);
        glVertex2d(x+xc, (y*-1)+yc);
        glVertex2d(y+xc, (x*-1)+yc);
        glVertex2d((x*-1)+xc, (y*-1)+yc);
        glVertex2d((y*-1)+xc, (x*-1)+yc);
        x++;
        if(pk>=0)
        {
            y--;
            pk=pk+(2*x)-(2*y)+1;
        }
        else{
            pk=pk+(2*x)+1;
        }
    }
    if(shade)
    {
        for(int a=-r; a<=r; a++)
        {
            for(int b=-r; b<=r; b++)
            {
                if(a*a+b*b-r*r<0)
                    glVertex2d(a+xc, b+yc);
            }
        }
    }
    glEnd();
}
Point rotate(Point p, double angle){
    double T[3][3], P[3], tmp[3];
    P[0]=p.x;
    P[1]=p.y;
    P[2]=1;
    T[0][0]=cos(angle);
    T[0][1]=-sin(angle);
    T[0][2]=0;
    T[1][0]=sin(angle);
    T[1][1]=cos(angle);
    T[1][2]=0;
    T[2][0]=0;
    T[2][1]=0;
    T[2][2]=1;
    //
    for(int k=0; k<3; k++)
    {
        tmp[k]=0;
        for(int i=0;i<3; i++)
        {
            tmp[k]+=T[k][i]*P[i];
        }
    }
    //
    p.x=round(tmp[0]);
    p.y=round(tmp[1]);
    return p;
}
Point A(0,100);
Point B=rotate(A, pie);
Point C=rotate(A, pie/2);
Point D=rotate(C, pie);
void myInit(){
    
    glClearColor(0.0,1.0,1.0,0.0);
    glColor3f(0.0f,0.0f,0.0f);
    glPointSize(1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200,200,-200,200);
}

void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex2d(200, -200);
    glVertex2d(200, -50);
    glVertex2d(-200, -50);
    glVertex2d(-200, -200);
    glEnd();
    glColor3f(1.0f,1.0f,0.0f);
    circle(120,100,15,true);
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2d(A.x,A.y);
    glVertex2d(B.x,B.y);
    glVertex2d(C.x,C.y);
    glVertex2d(D.x,D.y);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2d(0, 20);
    glVertex2d(-20, -200);
    glVertex2d(20, -200);
    glEnd();
    A=rotate(A,pie/18);
    B=rotate(B,pie/18);
    C=rotate(C,pie/18);
    D=rotate(D,pie/18);
    usleep(30000);
    glutPostRedisplay();
    glFlush();
    
}

int main(int argc,char * argv[]) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutInitWindowSize(400,400);
    glutCreateWindow("left to right");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 1;
}






//sun

#include<iostream>
#include <GL/glut.h>
#include <math.h>
#include <sstream>
#include <unistd.h>
using namespace std;
//int a=0,b=-20,r=7,h=0,v=3,z=1;
int theta=0;
float g=55,r=200/90;
class Point
{
public:
    double x,y;
    Point(int x,int y)
    {
        this->x=x;
        this->y=y;
    }
};
void circle(int xc, int yc, int r, bool shade)
{
    glBegin(GL_POINTS);
    int x=0, y=r, pk=1-r;
    //main algo
    while(x<=y)
    {
        glVertex2d(x+xc, y+yc);
        glVertex2d(y+xc, x+yc);
        glVertex2d((x*-1)+xc, y+yc);
        
        glVertex2d((y*-1)+xc, x+yc);
        glVertex2d(x+xc, (y*-1)+yc);
        glVertex2d(y+xc, (x*-1)+yc);
        glVertex2d((x*-1)+xc, (y*-1)+yc);
        glVertex2d((y*-1)+xc, (x*-1)+yc);
        x++;
        if(pk>=0)
        {
            y--;
            pk=pk+(2*x)-(2*y)+1;
        }
        else{
            pk=pk+(2*x)+1;
        }
    }
    if(shade)
    {
        for(int a=-r; a<=r; a++)
        {
            for(int b=-r; b<=r; b++)
            {
                if(a*a+b*b-r*r<0)
                    glVertex2d(a+xc, b+yc);
            }
        }
    }
    glEnd();
}

void myInit(){
    gluOrtho2D(-200,200,-200,200);
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0f,0.0f,0.0f);
    glPointSize(5);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
}
//focus of para 0,150
Point a(-150,0);

void sunrise()
{	
	glColor3ub(255,round(g),0);
	
	
	cout<<"hello";
	glPushMatrix();
	glRotatef(-theta,0,0,1);
	circle(a.x,a.y,20,true);
	glPopMatrix();
	theta +=1;
	if(theta==360)
		theta=0;
	g+=r;
	if(theta%90==0)
		r=-r;
	usleep(15000);
	glutPostRedisplay();
}
void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
	sunrise();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex2d(-190,0);
    glVertex2d(190,0);
    glVertex2d(190,-200);
    glVertex2d(-190,-200);
    glEnd();
    glFlush();
    

    
}

int main(int argc,char * argv[]) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutInitWindowSize(400,400);
    glutCreateWindow("left to right");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 1;
}











//solar

#include<GLUT/glut.h>
#include<unistd.h>
#include <iostream>
using namespace std;
int angle=0,a=0,angle1=0,ang=0;
void myInit()
{
    glEnable(GL_DEPTH);
    
}
void circle(int xc, int yc, int r, bool shade)
{
    glBegin(GL_POINTS);
    int x=0, y=r, pk=1-r;
    //main algo
    while(x<=y)
    {
        glVertex3d(x+xc,0, y+yc);
        glVertex3d(y+xc,0, x+yc);
        glVertex3d((x*-1)+xc,0, y+yc);
        
        glVertex3d((y*-1)+xc,0, x+yc);
        glVertex3d(x+xc,0, (y*-1)+yc);
        glVertex3d(y+xc,0, (x*-1)+yc);
        glVertex3d((x*-1)+xc, 0,(y*-1)+yc);
        glVertex3d((y*-1)+xc,0, (x*-1)+yc);
        x++;
        if(pk>=0)
        {
            y--;
            pk=pk+(2*x)-(2*y)+1;
        }
        else{
            pk=pk+(2*x)+1;
        }
    }
    if(shade)
    {
        for(int a=-r; a<=r; a++)
        {
            for(int b=-r; b<=r; b++)
            {
                if(a*a+b*b-r*r<0)
                    glVertex2d(a+xc, b+yc);
            }
        }
    }
    glEnd();
}
void display()
{
    
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
     glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-320, 320, -240, 240, -500, 500);
    gluLookAt(40, 30, 15, 0, 0, 0, 0, 1, 0);
  
    glColor3f(1.0, 0.0, 0.0);
    glRotatef(angle1, 1, 0, 0);
     glutSolidSphere(30, 20, 10);

    glPushMatrix();
    glColor3f(0.4, 1.0, 0.0);
    circle(0,0,50,false);
      glRotatef(a, 0, 1, 0);
     glTranslatef(-50, 0, 0);
    glutSolidSphere(5, 20, 10);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 0.0, 0.5);
    circle(0,0,80,false);
      glRotatef(angle, 0, 1, 0);
    glTranslatef(-80, 0, 0);
    glutSolidSphere(10, 20, 10);
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.7);
    circle(0,0,100,false);
    glRotatef(ang, 0, 1, 0);
    glTranslatef(-100, 0, 0);
    glutSolidSphere(20, 20, 10);
    glPopMatrix();
    angle+=2;
    angle=angle%360;
    a+=3;
    a=a%360;
    ang+=1;
    ang=ang%360;
    usleep(10000);
    glutPostRedisplay();
    glFlush();
}
void key(unsigned char k,int x,int y)
{
    if(k=='r')
    {
        angle1+=10;
        angle1%=360;
    }
    glutPostRedisplay();
}
int main(int argc, char * argv[]) {
    glutInit(&argc,argv);
    glutInitWindowSize(1000,1000);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH );
    glutCreateWindow("CUBE");
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    myInit();
    
    glutMainLoop();
    return 0;
    
}








//pend
#include<unistd.h>
#include<GLUT/glut.h>
#include<math.h>
#include <iostream>
#include<sstream>
using namespace std;
double pi=3.14159;
int x=-50;
int l=100,y;
bool flag=false;
int c=0;
class Point
{
public:
    int x,y;
    Point()
    {
    }
    Point(int x1,int y1)
    {
        x=x1;
        y=y1;
    }
};
Point rotate(Point P,double angle)
{
    double t[3][3],p[3],result[3]={0};
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(i!=j)
                t[i][j]=0;
            else
                t[i][j]=1;
    t[0][0]=cos(angle);
    t[0][1]=-sin(angle);
    t[1][0]=sin(angle);
    t[1][1]=cos(angle);
    p[0]=P.x;
    p[1]=P.y;
    p[2]=1;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            result[i]+=t[i][j]*p[j];
    P.x=round(result[0]);
    P.y=round(result[1]);
    return P;
}
void myInit()
{
    gluOrtho2D(-200, 200,-200 , 200);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void circle(int xc,int yc,int r,bool shade)
{
    int x=0,y=r,p=1-r;
    glBegin(GL_POINTS);
    while(x<=y)
    {
        glVertex2d(-x+xc, -y+yc);
        glVertex2d(x+xc, -y+yc);
        glVertex2d(-x+xc, y+yc);
        glVertex2d(x+xc, y+yc);
        glVertex2d(-y+xc, -x+yc);
         glVertex2d(-y+xc, x+yc);
         glVertex2d(y+xc, -x+yc);
         glVertex2d(y+xc, x+yc);
        x++;
        if(p>=0)
        {
            y--;
            p=p+2*x-2*y+1;
        }
        else
            p=p+2*x+1;
    }
    if(shade)
    {
        for(int a=-r;a<=r;a++)
            for(int b=-r;b<=r;b++)
                if(a*a+b*b-r*r<0)
                {
                    glVertex2d(a+xc, b+yc);
                }
    }
    glEnd();
}
int cy,nl=l+10;
Point A(100,0);
Point B=rotate(A,pi);
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    y=round(sqrt(l*l-x*x));
    cy=round(sqrt(nl*nl-x*x));
    if(c==10&&x==0)
    {
        glVertex2d(0,0);
        glVertex2d(x,-y);
        glVertex2d(A.x,A.y);
        glVertex2d(B.x,B.y);
        glEnd();
        glColor3f(0.0, 0.0, 0.0);
        circle(x,-y,10,true);
        flag=true;
    }
    if(!flag)
    {
        glVertex2d(0,0);
        glVertex2d(x,-y);
    glVertex2d(A.x,A.y);
   
    glVertex2d(B.x,B.y);
    glEnd();
    /*stringstream c1;
    string co;
    c1<<'('<<B.x<<','<<B.y<<')';
    c1>>co;
    glRasterPos2d(B.x, B.y);
    for(int i=0;i<co.length();i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, co[i]);
    }*/
    glColor3f(0.0, 0.0, 0.0);
    circle(x,-y,10,true);
    if(c%2==0)
        x++;
    else
        x--;
        cout<<'('<<x<<','<<c<<')'<<endl;
    if(x==50)
    {
        c++;
    }
    if(x==-50)
    {
        c++;
    }
    }
    if(c>=5&&c<8)
        usleep(30000);
    if(c>=8)
        usleep(50000);
    if(flag)
        goto a;
    glutPostRedisplay();
a:
    glFlush();
}


int main(int argc,char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutInitWindowSize(680, 400);
    glutCreateWindow("Pendulum");
    glutDisplayFunc(display);
    myInit();
    glutMainLoop();
    return 0;
}












//tap
#include <GL/glut.h>
#include <stdio.h>
#include <time.h>

int x1, y1, x2, y2,i=0;
int pntX1, pntY1, r;
void myInit() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

void draw_pixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void draw_line(int x1, int x2, int y1, int y2)
{
    int dx,dy,p=-1,flag=0;
    int tempx=x1,tempy=y1;
    dx=x2-x1;
    dy=y2-y1;
    draw_pixel(tempx,tempy);
    while(tempx<=x2)
    {
        if(dx>=dy)
        {
            if(flag==0)
            {
                flag=1;
                p=2*dy-dx;
            }
            else if(flag==1)
            {
                if(p<0)
                {
                    p=p+(2*dy);
                    draw_pixel(tempx++,tempy);
                }
                if(p>=0)
                {
                    p=p+(2*dy-2*dx);
                    draw_pixel(tempx++,tempy++);
                }
            }
        }
    }
}
void idle()
{
	glutPostRedisplay();
}
void delay(float secs)
{
	float end=clock()/CLOCKS_PER_SEC +secs;
	while((clock()/CLOCKS_PER_SEC) < end);
}
void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x+pntX1, y+pntY1);
	glEnd();
}
void midPointCircleAlgo()
{
	int x = 0;
	int y = r;
	float decision = 5/4 - r;
	plot(x, y);

	while (y > x)
	{
		if (decision < 0)
		{
			x++; 
			decision += 2*x+1;
		}
		else
		{
			y--;
			x++;
			decision += 2*(x-y)+1;
		}
		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);
		plot(y, x);
		plot(-y, x);
		plot(y, -x);
		plot(-y, -x);
	}

}
void myDisplay() {
    //draw_line(20, 100, 20, 100);
    //draw_line(180, 100, 20,100);
    glClear(GL_COLOR_BUFFER_BIT);
    if(i==50)
    {
		exit(0);
	}
	//Bucket
    glBegin(GL_LINES);
    glPushMatrix();
    glColor3f(1,1,1);
	glVertex2d(20,80);
    glVertex2d(20,20);
    glVertex2d(20,20);
    glVertex2d(80,20);
    glVertex2d(80,20);
    glVertex2d(80,80);
    glPopMatrix();
    glEnd();
    //Water
    glBegin(GL_QUADS);
    glPushMatrix();
    glColor3f(0,0,1);
    glVertex2d(20,30+i);
    glVertex2d(20,20);
    glVertex2d(79,20);
    glVertex2d(79,30+i);
    glPopMatrix();
    glEnd();
    //Tap1
    glPushMatrix();
    glTranslated(20,0,0);
    glBegin(GL_QUADS);
	glColor3f(1,0,0);
    glVertex2d(40,150);
    glVertex2d(40,140);
    glVertex2d(60,140);
    glVertex2d(60,150);
    glTranslated(0,0,0);
    glEnd();
    glPopMatrix();
    //Tap2:
    glPushMatrix();
    glTranslated(20,0,0);
    glBegin(GL_QUADS);
	glColor3f(1,0,0);
    glVertex2d(50,130);
    glVertex2d(100,130);
    glVertex2d(100,140);
    glVertex2d(50,140);
    glEnd();
    glPopMatrix();
    //Tap3:
    glPushMatrix();
    glTranslated(20,0,0);
    glBegin(GL_QUADS);
	glColor3f(1,0,0);
    glVertex2d(30,120);
    glVertex2d(50,120);
    glVertex2d(50,140);
    glVertex2d(30,140);
    glEnd();
    glPopMatrix();
    if(i%2==0)
    {
		glColor3f(0,0,1);
		pntX1=60;
		pntY1=110;
		r=10;
		midPointCircleAlgo();
	}
	else
	{
		glColor3f(0,0,1);
		pntX1=60;
		pntY1=85;
		r=10;
		midPointCircleAlgo();
	}
    glFlush();
    i++;
    delay(1);
}

int main(int argc, char **argv) {
    
    //printf( "Enter (x1, y1, x2, y2)\n");
    //scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bresenham's Line Drawing");
    myInit();
    glutDisplayFunc(myDisplay);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}









//3dcube

#include <GLUT/glut.h>

void init()
{
   glEnable(GL_DEPTH_TEST);

}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-320,320,-240,240,-50,50); //Setting up the Viewvolume
    
    //Setting the camera position or the viewer's position.
    gluLookAt(10,5,10,   //Camera_x,Camera_y,Camera_z
              0,0,0,     //loot at orgin
              0,1,0);    // positive Y up vector
    
   glColor3ub(255,0,255); //Setting the Color for the Cube
   glutSolidCube(50);
    glFlush();
   
}


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_SINGLE);
    glutCreateWindow("CUBES");
    
    glutDisplayFunc(display);
    
    init();
    
    glutMainLoop();
    return 0;
}
