
const int maxlights=8;  //DO NOT CHANGE
// GL_MAX_LIGHTS is not just an unsigned int
// glGetIntegerv(GL_MAX_LIGHTS,&maxlights);
// can check in main prog that
// gives you 8, byt GL_MAX_LIGHTS is 3377!

const USHORT ilights=1;  // number of lights, MAXIMUM ALLOWED=8
const USHORT imats=20;  // number of materials, including lines as well as facets.

#define GeoPos 5000

const int MAX_TEXTURES=300;
unsigned int gl_Texture[MAX_TEXTURES];

int ilite,imat,iplot;

int testplot; // for testing individual points, lines, triangles etc
int testsurf; // for testing individual points, lines, triangles etc

DWORD MYLIGHTS[maxlights];

D3Dvec Geodesy[GeoPos];
//
int Geokount;

double TotalSide=30000.0;  // Length of the big square

bool helpscreen=false; bool lightpos=false; bool lightcol=false;
bool matcol=false; bool drawscreen=true; bool LIGHTS=true;
bool logicbox=false; bool movetext=false; bool legendplot=true; 
bool stylechange=false; 
bool flipperbox=false; bool** flippit; int* idtotal;

bool tleg=true,tlpos=false,tlcol=false,tmatcol=false,tlogbox=false,
tmove=false,tflip=false,tstyle=false; //for copies of legendplot etc

//  for drawing light position box
double Left=-0.8, Bottom=-0.8;  // For Boxes
//  for drawing light colour box
double LeftC=-0.7, BottomC=-0.7;  // For Boxes
//  for material colour box
double LeftM=-0.6, BottomM=-0.6;  // For Boxes
//  for Plotit text position box
double LeftDT=-0.6, BottomDT=-0.6;  // For Boxes
//  for Plotit colour/style box
double LeftPC1=-0.6, BottomPC1=-0.6;  // For Boxes
//  for moving Legend
double LeftLeg=0.65, TopLeg=0.65;  // For Boxes
double LeftLegStart, TopLegStart;

//light pos box

double LeftMargin=0.075; double RightMargin=0.72;
double BottomMargin=0.11; double MiddleMarge1=0.27; double TopMargin=0.43;


double Left_Left=Left+LeftMargin, Left_Right=Left+RightMargin;  //extreme values

double Bottom1=Bottom+BottomMargin;  //slide bars bottom to top
double Bottom2=Bottom+MiddleMarge1; double Bottom3=Bottom+TopMargin;

// for moving whole box around
double LeftStart, BottomStart; double LeftStartC, BottomStartC;
double LeftStartM, BottomStartM;  double LeftStartDT, BottomStartDT;
double LeftStartPC1, BottomStartPC1;


bool mouse_slide=false;

float gLightPosition[4];
double AzimStart, ZenStart, rhoStart;
double Zen[maxlights], Az[maxlights], Rho[maxlights];
double CosZen,CosAz,SinZen,SinAz;
double zenangle[maxlights],azimangle[maxlights],rhovalue[maxlights];
double Left1[maxlights], Left2[maxlights], Left3[maxlights];      //initialise in Init()

double LeftNum=0.61, BottomNum=0.55, LeftArrow=0.70
, BottomDownArrow=0.55, BottomUpArrow=0.61;

double L_Dist_Scale=20000; // slidebar for light distance values are 0-20000
double L_Inf=19500; // Set to infinity if above this value

//for Drawing light colour box
//

double Left1C=LeftC+0.07; double Left2C=LeftC+0.19;
double Left3C=LeftC+0.31; double Left4C=LeftC+0.44;

double Left1CStart, Left2CStart, Left3CStart, Left4CStart;

double xbox[4], ybox[6], xboxStart[4], yboxStart[6];  //For DrawTextMove.h Arrows

double BottomCMargin=0.06;
double TopCMargin=0.45;

// diffuse, ambient, specular for Light and Material
const USHORT Lprops=3, Mprops=3;
int lprop, mprop;
 

double Bottom1C[maxlights][Lprops], Bottom2C[maxlights][Lprops]
       , Bottom3C[maxlights][Lprops], Bottom4C[maxlights][Lprops];

double RedLslide[maxlights][Lprops],GreenLslide[maxlights][Lprops]
       ,BlueLslide[maxlights][Lprops],AlphaLslide[maxlights][Lprops];

double RedL[maxlights][Lprops],GreenL[maxlights][Lprops]
       ,BlueL[maxlights][Lprops],AlphaL[maxlights][Lprops];

double RedLStart,GreenLStart,BlueLStart, AlphaLStart;

double Bottom_BottomC=BottomC+BottomCMargin;
double Bottom_TopC=BottomC+TopCMargin;

double LeftNumC1=0.55, BottomNumC1=0.28, LeftArrowC1=0.80
, BottomDownArrowC1=0.28, BottomUpArrowC1=0.34;

double LeftNumC2=0.60, BottomNumC2=0.10, LeftArrowC2=0.72
, BottomDownArrowC2=0.10, BottomUpArrowC2=0.16;

// box for material properties and colour

double Left1M=LeftM+0.05; double Left2M=LeftM+0.16;
double Left3M=LeftM+0.27; double Left4M=LeftM+0.375;
double Left5M=LeftM+0.475;

double Left1PC1=LeftPC1+0.46; double Left2PC1=LeftPC1+0.58;
double Left3PC1=LeftPC1+0.7; 

double BottomMMargin=0.06; double TopMMargin=0.45;
double BottomPC1Margin=0.13; double TopPC1Margin=0.40;

double Bottom_BottomM=BottomM+BottomMMargin;   //material
double Bottom_TopM=BottomM+TopMMargin;

double Bottom_BottomPC1=BottomPC1+BottomPC1Margin;
double Bottom_TopPC1=BottomPC1+TopPC1Margin;

double Left1MStart, Left2MStart, Left3MStart, Left4MStart,Left5MStart; // five slide bars

double Left1PC1Start, Left2PC1Start, Left3PC1Start;

double  Bottom1M[imats][Mprops], Bottom2M[imats][Mprops]
       ,Bottom3M[imats][Mprops], Bottom4M[imats][Mprops]
       ,Bottom5M[imats][Mprops];

double  Bottom1PC1[nplotsmax][Mprops], Bottom2PC1[nplotsmax][Mprops]   //naughty!
       ,Bottom3PC1[nplotsmax][Mprops];

double RedMslide[imats][Mprops],GreenMslide[imats][Mprops]
       ,BlueMslide[imats][Mprops],AlphaMslide[imats][Mprops]
       ,ShineMslide[imats][Mprops];

double RedPC1slide[nplotsmax][Mprops],GreenPC1slide[nplotsmax][Mprops]
       ,BluePC1slide[nplotsmax][Mprops];

double RedM[imats][Mprops],GreenM[imats][Mprops]
       ,BlueM[imats][Mprops],AlphaM[imats][Mprops],ShineM[imats][Mprops];

double RedPC1[nplotsmax][Mprops],GreenPC1[nplotsmax][Mprops]
       ,BluePC1[nplotsmax][Mprops],AlphaPC1[nplotsmax][Mprops],ShinePC1[nplotsmax][Mprops];



double RedMStart,GreenMStart,BlueMStart, AlphaMStart,ShineMStart;

double RedPC1Start,GreenPC1Start,BluePC1Start;

double LeftNumM1=0.55, BottomNumM1=0.28, LeftArrowM1=0.80
, BottomDownArrowM1=0.29, BottomUpArrowM1=0.34;

double LeftNumM2=0.60, BottomNumM2=0.10, LeftArrowM2=0.72
, BottomDownArrowM2=0.11, BottomUpArrowM2=0.15;

double LeftNumPC11=0.08, BottomNumPC11=0.38, LeftArrowPC11=0.25
, BottomDownArrowPC11=0.37, BottomUpArrowPC11=0.40;

double LeftNumPC12=0.08, BottomNumPC12=0.25, LeftArrowPC12=0.25
, BottomDownArrowPC12=0.25, BottomUpArrowPC12=0.28;


double LeftNumPC13=0.08, BottomNumPC13=0.13, LeftArrowPC13=0.25
, BottomDownArrowPC13=0.12, BottomUpArrowPC13=0.15;



//logic check boxes

double LeftL1=0.1, LeftL2=0.5;
double TopL1=.92, TopL2=0.72, TopL3=0.52, TopL4=0.32, TopL5=.12;

const double pi=acos(-1.0);
const double twopi=2.0*pi;
const double convert=180.0/pi;
//

/**********************************************************************/
//D3Dvec *Cross;  //if running out of memory do it in renderscene instead
// Now have global Normals instead

char *cstrval=(char*)malloc(50);

bool upPressed=false; bool ctrl_upPressed=false; bool shift_upPressed=false;
bool downPressed=false; bool ctrl_downPressed=false; bool shift_downPressed=false;
bool leftPressed=false; bool ctrl_leftPressed=false; bool shift_leftPressed=false;
bool rightPressed=false; bool ctrl_rightPressed=false; bool shift_rightPressed=false;

bool post_Pressed=false; bool a_Pressed; bool z_Pressed;
bool b_Pressed=false; bool c_Pressed=false; bool  g_Pressed=false;
bool t_Pressed=false; bool  l_Pressed=false;

bool MouseOn=true; bool mousedown=false; bool firstmousedown=true;

// box for material properties and colour
int mousex, mousey; 
//periodic bcs
int xstart, ystart;


//BITMAP FONTS
//
UINT base;
