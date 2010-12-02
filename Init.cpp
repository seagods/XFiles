void Init(){
   InitialiseGL(WIDTH, HEIGHT);

   //  IMPORTANT  //
   // The width in pixels MUST be a whole number times 4! 
   // Otherwise the swapped image is garbage
   // don't know if it is gimp output (seems likely
   // as size=header file (54 bytes)+bytesperpix*width*height
   // is not right in ls -l unless width is a multiple of 4
   //
   // If not a multiple of 4, Load in gimp, then go 
   //  Image->Canvas-Size, adjust, then resize.
   //
   //  Also, just use a paintbrush in the Gimp for white edges
   char bitmap0[]="../../bitmaps/HelpScreen.bmp";
   char bitmap1[]="../../bitmaps/LightPos.bmp";
   char bitmap2[]="../../bitmaps/buttonmask.bmp";
   char bitmap3[]="../../bitmaps/button.bmp";
   char bitmap4[]="../../bitmaps/WhiteBack.bmp";
   char bitmap5[]="../../bitmaps/UpArrow.bmp";
   char bitmap6[]="../../bitmaps/DownArrow.bmp";
   char bitmap7[]="../../bitmaps/LightCol.bmp";
   char bitmap8[]="../../bitmaps/MatCol.bmp";
   char bitmap9[]="../../bitmaps/LogicBack.bmp";
   char bitmap10[]="../../bitmaps/GreenCheck.bmp";
   char bitmap11[]="../../bitmaps/RedCheck.bmp";
   char bitmap12[]="../../bitmaps/TextMove1.bmp";
   char bitmap13[]="../../bitmaps/LeftArrow.bmp";
   char bitmap14[]="../../bitmaps/RightArrow.bmp";
   char bitmap15[]="../../bitmaps/CurveMod.bmp";
   char bitmap16[]="../../bitmaps/LegendBack.bmp";
   char bitmap17[]="../../bitmaps/TextMove2.bmp";
   char bitmap18[]="../../bitmaps/Earth1.bmp";
   char bitmap19[]="../../bitmaps/Earth2.bmp";
   char bitmap20[]="../../bitmaps/Earth3.bmp";
   char bitmap31[]="../../bitmaps/TriBox.bmp";
   char bitmap32[]="../../bitmaps/NodeBox.bmp";

   CreateTexture(gl_Texture,bitmap0,0);
   CreateTexture(gl_Texture,bitmap1,1);
   CreateTexture(gl_Texture,bitmap2,2);
   CreateTexture(gl_Texture,bitmap3,3);
   CreateTexture(gl_Texture,bitmap4,4);
   CreateTexture(gl_Texture,bitmap5,5);
   CreateTexture(gl_Texture,bitmap6,6);
   CreateTexture(gl_Texture,bitmap7,7);
   CreateTexture(gl_Texture,bitmap8,8);
   CreateTexture(gl_Texture,bitmap9,9);
   CreateTexture(gl_Texture,bitmap10,10);
   CreateTexture(gl_Texture,bitmap11,11);
   CreateTexture(gl_Texture,bitmap12,12);
   CreateTexture(gl_Texture,bitmap13,13);
   CreateTexture(gl_Texture,bitmap14,14);
   CreateTexture(gl_Texture,bitmap15,15);
   CreateTexture(gl_Texture,bitmap16,16);
   CreateTexture(gl_Texture,bitmap17,17);
   CreateTexture(gl_Texture,bitmap18,18);
   CreateTexture(gl_Texture,bitmap19,19);
   CreateTexture(gl_Texture,bitmap20,20);

   CreateTexture(gl_Texture,bitmap31,31);
   CreateTexture(gl_Texture,bitmap32,32);



   //Material 0 is background
   //
   for(int mp=0; mp<Mprops; mp++){
    
   RedM[0][mp]=1.0;  //diffuse
   GreenM[0][mp]=1.0;
   BlueM[0][mp]=1.0;
   AlphaM[0][mp]=1.0;
   ShineM[0][mp]=127.0;

   RedMslide[0][mp]=RedM[0][mp]*(Bottom_TopM-Bottom_BottomM);
   GreenMslide[0][mp]=GreenM[0][mp]*(Bottom_TopM-Bottom_BottomM);
   BlueMslide[0][mp]=BlueM[0][mp]*(Bottom_TopM-Bottom_BottomM);
   AlphaMslide[0][mp]=AlphaM[0][mp]*(Bottom_TopM-Bottom_BottomM);
   ShineMslide[0][mp]=ShineM[0][mp]*(Bottom_TopM-Bottom_BottomM)/127.0;

   Bottom1M[0][mp]=Bottom_BottomM+RedMslide[0][mp];
   Bottom2M[0][mp]=Bottom_BottomM+GreenMslide[0][mp];
   Bottom3M[0][mp]=Bottom_BottomM+BlueMslide[0][mp];
   Bottom4M[0][mp]=Bottom_BottomM+AlphaMslide[0][mp];
   Bottom5M[0][mp]=Bottom_BottomM+ShineMslide[0][mp];
   }
   //other materials initialsied later
  



   glClearColor(RedM[0][0],GreenM[0][0],BlueM[0][0] ,AlphaM[0][0]);
   //background colour initialised

	  MYLIGHTS[0]=GL_LIGHT0;
	  MYLIGHTS[1]=GL_LIGHT1;
	  MYLIGHTS[2]=GL_LIGHT2;
	  MYLIGHTS[3]=GL_LIGHT3;
	  MYLIGHTS[4]=GL_LIGHT4;
	  MYLIGHTS[5]=GL_LIGHT5;
	  MYLIGHTS[6]=GL_LIGHT6;
	  MYLIGHTS[7]=GL_LIGHT7;

     //To specifiy a light we need to name them as follows
     // from GL_LIGHT0, GL_LIGHT1,GL_LIGHT2,... GL_LIGHTN.

     /* Second Argument can be
    GL_AMBIENT, GL_DIFFUSE,GL_SPECULAR,GL_POSITION,
    GL_SPOT_CUTTOFF, GL_SPOT_DIRECTION, GL_SPOT_EXPONENT,
    GL_CONSTANT_ATTENIATION, GL_LINEAR_ATTENUATION,
    GL_QUADRATIC_ATTENUATION   */
    //
    //
     for(int il=0;il<ilights;il++){
     RedL[il][0]=0.0;  
     GreenL[il][0]=0.0;  
     BlueL[il][0]=0.0;  
     AlphaL[il][0]=1.0;  
	     // light from all over
     RedL[il][1]=1.0;  
     GreenL[il][1]=1.0;  
     BlueL[il][1]=1.0;  
     AlphaL[il][1]=1.0;  
     // light component reflecting diffusely
     RedL[il][2]=1.0;  
     GreenL[il][2]=1.0;  
     BlueL[il][2]=1.0;  
     AlphaL[il][2]=1.0;  
     //light reflecting specularly
     //
     for(int lp=0;lp<Lprops;lp++){
        RedLslide[il][lp]=RedL[il][lp]*(Bottom_TopC-Bottom_BottomC);
	Bottom1C[il][lp]=Bottom_BottomC+RedLslide[il][lp];
     	GreenLslide[il][lp]=GreenL[il][lp]*(Bottom_TopC-Bottom_BottomC);
	Bottom2C[il][lp]=Bottom_BottomC+GreenLslide[il][lp];
        BlueLslide[il][lp]=BlueL[il][lp]*(Bottom_TopC-Bottom_BottomC);
	Bottom3C[il][lp]=Bottom_BottomC+BlueLslide[il][lp];
        AlphaLslide[il][lp]=AlphaL[il][lp]*(Bottom_TopC-Bottom_BottomC);
	Bottom4C[il][lp]=Bottom_BottomC+AlphaLslide[il][lp];
     }
     lprop=0;

     float ambient[4]={RedL[il][0], GreenL[il][0], BlueL[il][0], AlphaL[il][0]}; 
     float diffuse[4]={RedL[il][1], GreenL[il][1], BlueL[il][1], AlphaL[il][1]}; 
     float specular[4]={RedL[il][2], GreenL[il][2], BlueL[il][2], AlphaL[il][2]}; 


     glLightfv(MYLIGHTS[il],GL_AMBIENT, ambient);
     glLightfv(MYLIGHTS[il],GL_DIFFUSE, diffuse);
     glLightfv(MYLIGHTS[il],GL_SPECULAR, specular);

     Zen[il]=45.0;
     Az[il]=245.0;
     Rho[il]=6000.0;

     CosZen=cos(Zen[il]/convert);
     SinZen=sin(Zen[il]/convert);
     SinAz=sin(Az[il]/convert);
     CosAz=cos(Az[il]/convert);

     zenangle[il]=Zen[il]/180.*(Left_Right-Left_Left);
     azimangle[il]=Az[il]/360.*(Left_Right-Left_Left);
     rhovalue[il]=Rho[il]/L_Dist_Scale*(Left_Right-Left_Left);

     Left1[il]=Left_Left+zenangle[il];
     Left2[il]=Left_Left+azimangle[il];      //initialise
     Left3[il]=Left_Left+rhovalue[il];

     //pesky OpenGL coordinates
     //(check later gLightPosition, this is just initaialisation)
     gLightPosition[0]=Rho[il]*SinZen*CosAz;  //Pesky OpenGL coordinates
     gLightPosition[2]=-Rho[il]*SinZen*SinAz;
     gLightPosition[1]=Rho[il]*CosZen;
     gLightPosition[3]=1.0;   

     glLightfv(MYLIGHTS[il],GL_POSITION,gLightPosition);

     
     glEnable( MYLIGHTS[il] );
      }
     ilite=0;  //ilite is the current light being altered by slidebar


     double RedI[imats],GreenI[imats],BlueI[imats],AlphaI[imats],ShineI[imats];

     //hand pick initial colours
    // white for im=0;
     RedI[0]=1.0; GreenI[0]=1.0; BlueI[0]=1.0; AlphaI[0]=0.5; ShineI[0]=100.0;
     //black for im=1
     RedI[1]=0.0; GreenI[1]=0.0; BlueI[1]=0.0; AlphaI[1]=0.5; ShineI[1]=100.0;
     // Red1 for im=2;
     RedI[2]=0.7; GreenI[2]=0.0; BlueI[2]=0.0; AlphaI[2]=0.5; ShineI[2]=100.0;
     // Red2 for im=3;
     RedI[3]=1.0; GreenI[3]=0.0; BlueI[3]=0.0; AlphaI[3]=0.5; ShineI[3]=100.0;
     // Green1 for im=4;
     RedI[4]=0.0; GreenI[4]=0.7; BlueI[4]=0.0; AlphaI[4]=0.5; ShineI[4]=100.0;
     // Green2 for im=5;
     RedI[5]=0.0; GreenI[5]=1.0; BlueI[5]=0.0; AlphaI[5]=0.5; ShineI[5]=100.0;
     // Blue1 for im=6;
     RedI[6]=0.0; GreenI[6]=0.0; BlueI[6]=0.7; AlphaI[6]=0.5; ShineI[6]=100.0;
     // Blue2 for im=7;
     RedI[7]=0.0; GreenI[7]=1.0; BlueI[7]=1.0; AlphaI[7]=0.5; ShineI[7]=100.0;
     // Yellow1 for im=8;
     RedI[8]=0.7; GreenI[8]=0.7; BlueI[8]=0.0; AlphaI[8]=0.5; ShineI[8]=100.0;
     // Yellow2 for im=9;
     RedI[9]=1.0; GreenI[9]=1.0; BlueI[9]=0.0; AlphaI[9]=0.5; ShineI[9]=100.0;
     // last preset colour
     RedI[10]=1.0; GreenI[10]=0.0; BlueI[10]=1.0; AlphaI[10]=0.5; ShineI[10]=100.0;

     for(int i=11; i<imats; i++){  //initialise rest as grey
     RedI[i]=0.5; GreenI[i]=0.5; BlueI[i]=0.5; AlphaI[i]=0.5; ShineI[i]=100.0;}



     //recall material 0 is background, if we make imats bigger than 10
     //we make everything grey
     for(int im=1; im < imats; im++){
	     for(int mp=0; mp < Mprops; mp++){
     if(im<=10){
       RedM[im][mp]=RedI[im];
       GreenM[im][mp]=GreenI[im];
       BlueM[im][mp]=BlueI[im];
       AlphaM[im][mp]=AlphaI[im];
       ShineM[im][mp]=ShineI[im];

       RedMslide[im][mp]=RedM[im][mp]*(Bottom_TopM-Bottom_BottomM);
       Bottom1M[im][mp]=Bottom_BottomM+RedMslide[im][mp];
       GreenMslide[im][mp]=GreenM[im][mp]*(Bottom_TopM-Bottom_BottomM);
       Bottom2M[im][mp]=Bottom_BottomM+GreenMslide[im][mp];
       BlueMslide[im][mp]=BlueM[im][mp]*(Bottom_TopM-Bottom_BottomM);
       Bottom3M[im][mp]=Bottom_BottomM+BlueMslide[im][mp];
       AlphaMslide[im][mp]=AlphaM[im][mp]*(Bottom_TopM-Bottom_BottomM);
       Bottom4M[im][mp]=Bottom_BottomM+AlphaMslide[im][mp];
       ShineMslide[im][mp]=ShineM[im][mp]*(Bottom_TopM-Bottom_BottomM)/127.0;
       Bottom5M[im][mp]=Bottom_BottomM+ShineMslide[im][mp];
     }
     else
     {
       RedM[im][mp]=0.5;
       GreenM[im][mp]=0.5;
       BlueM[im][mp]=0.5;
       AlphaM[im][mp]=0.5;
       ShineM[im][mp]=127.0;
       RedMslide[im][mp]=RedM[im][mp]*(Bottom_TopM-Bottom_BottomM);
       Bottom1M[im][mp]=Bottom_BottomM+RedMslide[im][mp];
       GreenMslide[im][mp]=GreenM[im][mp]*(Bottom_TopM-Bottom_BottomM);
       Bottom2M[im][mp]=Bottom_BottomM+GreenMslide[im][mp];
       BlueMslide[im][mp]=BlueM[im][mp]*(Bottom_TopM-Bottom_BottomM);
       Bottom3M[im][mp]=Bottom_BottomM+BlueMslide[im][mp];
       AlphaMslide[im][mp]=AlphaM[im][mp]*(Bottom_TopM-Bottom_BottomM);
       Bottom4M[im][mp]=Bottom_BottomM+AlphaMslide[im][mp];
       ShineMslide[im][mp]=ShineM[im][mp]*(Bottom_TopM-Bottom_BottomM)/127.0;
       Bottom5M[im][mp]=Bottom_BottomM+ShineMslide[im][mp];
     }
	     }
     }


    for(int im=0; im < nplotsmax; im++){
	     for(int mp=0; mp < Mprops; mp++){
     if(im<=10){  //ten preset colours 0-9
       RedPC1[im][mp]=RedI[im];
       GreenPC1[im][mp]=GreenI[im];
       BluePC1[im][mp]=BlueI[im];
       AlphaPC1[im][mp]=AlphaI[im];
       ShinePC1[im][mp]=ShineI[im];

       RedPC1slide[im][mp]=RedPC1[im][mp]*(Bottom_TopPC1-Bottom_BottomPC1);
       Bottom1PC1[im][mp]=Bottom_BottomPC1+RedPC1slide[im][mp];
       GreenPC1slide[im][mp]=GreenPC1[im][mp]*(Bottom_TopPC1-Bottom_BottomPC1);
       Bottom2PC1[im][mp]=Bottom_BottomPC1+GreenPC1slide[im][mp];
       BluePC1slide[im][mp]=BluePC1[im][mp]*(Bottom_TopPC1-Bottom_BottomPC1);
       Bottom3PC1[im][mp]=Bottom_BottomPC1+BluePC1slide[im][mp];
     }
     else
     {
       RedPC1[im][mp]=0.5;
       GreenPC1[im][mp]=0.5;
       BluePC1[im][mp]=0.5;
       AlphaPC1[im][mp]=0.5;
       ShinePC1[im][mp]=127.0;

       RedPC1slide[im][mp]=RedPC1[im][mp]*(Bottom_TopPC1-Bottom_BottomPC1);
       Bottom1PC1[im][mp]=Bottom_BottomPC1+RedPC1slide[im][mp];
       GreenPC1slide[im][mp]=GreenPC1[im][mp]*(Bottom_TopPC1-Bottom_BottomPC1);
       Bottom2PC1[im][mp]=Bottom_BottomPC1+GreenPC1slide[im][mp];
       BluePC1slide[im][mp]=BluePC1[im][mp]*(Bottom_TopPC1-Bottom_BottomPC1);
       Bottom3PC1[im][mp]=Bottom_BottomPC1+BluePC1slide[im][mp];
     }
	     }
     }

     imat=0;
     mprop=0;
     iplot=0;

     testplot=-1;


//    OK, and now for FOG!

     if(foggy){
	float fogColor[4]= 
	{RedM[0][0],GreenM[0][0],BlueM[0][0],AlphaM[0][0]};
	glFogfv(GL_FOG_COLOR, fogColor);

        float g_FogDensity=2.0e-4;
	glFogi(GL_FOG_MODE, GL_EXP2);	
	glFogf(GL_FOG_DENSITY, g_FogDensity);
	glHint(GL_FOG_HINT, GL_DONT_CARE);				
        glFogf(GL_FOG_START, 10000.0);	
	glFogf(GL_FOG_END, 10000.1);	
	glEnable(GL_FOG);	
     }

     glEnable( GL_LIGHTING);


}

