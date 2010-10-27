
#include "/usr/include/gltt/FTBitmapFont.h"
#include "/usr/include/gltt/FTEngine.h"
#include "/usr/include/gltt/FTFace.h"
#include "/usr/include/gltt/FTFont.h"
#include "/usr/include/gltt/FTGlyphBitmap.h"
#include "/usr/include/gltt/FTGlyph.h"
#include "/usr/include/gltt/FTGlyphPixmap.h"
#include "/usr/include/gltt/FTGlyphVectorizer.h"
#include "/usr/include/gltt/FTInstance.h"
#include "/usr/include/gltt/FTPixmapFont.h"


#include "/usr/include/gltt/GLTTBitmapFont.h"
#include "/usr/include/gltt/GLTTFont.h"
#include "/usr/include/gltt/GLTTOutlineFont.h"
#include "/usr/include/gltt/GLTTPixmapFont.h"
#include "/usr/include/gltt/GLTTboolean.h"
#include "/usr/include/gltt/GLTTGlyphPolygonizer.h"
#include "/usr/include/gltt/GLTTGlyphPolygonizerHandler.h"
#include "/usr/include/gltt/GLTTGlyphTriangulator.h"
#include "/usr/include/gltt/GLTTminmax.h"

FTFace face1;
FTFace face2;
FTFace face3;
FTFace face4;
FTFace face5;
FTFace face6;
FTFace face7;
FTFace face8;
FTFace face9;
//times
int iface1=face1.open("/usr/share/fonts/TTF/times/Timeg.ttf");
//times italic
int iface2=face2.open("/usr/share/fonts/TTF/times/Timegi.ttf");
//times bold
int iface3=face3.open("/usr/share/fonts/TTF/times/Timegbd.ttf");
//times bold italic
int iface4=face4.open("/usr/share/fonts/TTF/times/Timegibd.ttf");
//Greek!
int iface5=face5.open("/usr/share/fonts/TTF/Fonts-Linux/slgrrg__.ttf");
//latex maths 
int iface6=face6.open("/usr/share/fonts/TTF/texcm/cmex10.ttf");
int iface7=face7.open("/usr/share/fonts/TTF/texcm/cmmi10.ttf");
int iface8=face8.open("/usr/share/fonts/TTF/texcm/cmr10.ttf");
int iface9=face9.open("/usr/share/fonts/TTF/texcm/cmsy10.ttf");

GLTTFont font1(&face1);    //constructor for font
GLTTFont font2(&face2);    //constructor for font
GLTTFont font3(&face3);    //constructor for font
GLTTFont font4(&face4);    //constructor for font
GLTTFont font5(&face5);    //constructor for font
GLTTFont font6(&face6);    //constructor for font
GLTTFont font7(&face7);    //constructor for font
GLTTFont font8(&face8);    //constructor for font
GLTTFont font9(&face9);    //constructor for font

//Also, can use GLTTOutlineFont, GLTTPixmapFont, GLTTBitmapFonts eg:

FTFace face10;
FTFace face11;
FTFace face12;
FTFace face13;
int iface10=face10.open("/usr/share/fonts/TTF/times/Timeg.ttf");
int iface11=face11.open("/usr/share/fonts/TTF/times/Timeg.ttf");
int iface12=face12.open("/usr/share/fonts/TTF/times/Timeg.ttf");
int iface13=face13.open("/usr/share/fonts/TTF/times/Timeg.ttf");
GLTTBitmapFont font10(&face10);
GLTTFont font11(&face11);  //for different point sizes
GLTTFont font12(&face12);
GLTTFont font13(&face12);

