void DrawLightCol(bool draw_the_box)
{

    //
    //********************************************************************//
    //               Draw objects which can be selected
    //   **************************************************************   //
    //

      int viewport[4];
      SDL_GetMouseState(&mousex, &mousey);
      UINT NameBuffer[50];
      glSelectBuffer(50,NameBuffer);

    if(!draw_the_box){

      glGetIntegerv(GL_VIEWPORT, viewport);
      glMatrixMode(GL_PROJECTION);

      glPushMatrix();
      glLoadIdentity();

      gluPickMatrix( 
	 (double) mousex, viewport[3]-(double) mousey, 5.0, 5.0, viewport);

      (void)glRenderMode(GL_SELECT);

      glInitNames();  //Ignored unless in GL_SELECT 
    }

      if(draw_the_box)OrthoMode(-1, 1, 1, -1);  //calls glOrtho (see Init.h)

      // Box for  four vertical sliders
      double w1, h1, w2, h2;
      double Top, Right;   // For panel
      double Right1, Top1; //For button 
      double Right2, Top2; //For button 
      double Right3, Top3; //For button 
      double Right4, Top4; //For button 

     //From trial and error
     //  Zenith slide bar button, bottom1=Bottom+TopMargin
     //  Azimuth slide bar button, bottom1=Bottom+BottomMargin
     //  Button far left =Left+LeftMargin
     //  Button Far right=Left+RightMargin
     //
     //  Image size is 676 wide 434 hide
      w1=360./800.*2.0;
      h1=180./600.*2.0;

      Right=LeftC+w1;
      Top=BottomC+h1;

      glDisable(GL_LIGHTING);  //control panels wont see lighting

      glColor3ub(255,255,255);

      if(!draw_the_box)glPushName(10);

      glBlendFunc(GL_ONE,GL_ZERO);
      glBindTexture(GL_TEXTURE_2D,gl_Texture[7]);
      glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(LeftC, Top); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(LeftC ,BottomC ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right, BottomC); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Right , Top); // Top right
      glEnd();
      glColor3ub(255,255,255);  //set back colour  */


/*******************************************************************************/
      //slide button red
	     w2=30./800.*2.0;
	     h2=30./600.*2.0;

	     Right1=Left1C+w2;
             Top1=Bottom1C[ilite][lprop]+h2;

	     if(draw_the_box){
      glBlendFunc(GL_DST_COLOR,GL_ZERO);
      glBindTexture(GL_TEXTURE_2D,gl_Texture[2]);  }

      if(!draw_the_box)glPushName(11);  
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left1C, Top1); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left1C ,Bottom1C[ilite][lprop] ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right1, Bottom1C[ilite][lprop]); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Right1 , Top1); // Top right
      glEnd();
      if(!draw_the_box)glPopName();   // Box 1  Button 1 popped
  

      //Then the bright red button!
      //slide button for  zenith
	     if(draw_the_box){
      glBlendFunc(GL_ONE,GL_ONE);
      glBindTexture(GL_TEXTURE_2D,gl_Texture[3]); }

      if(!draw_the_box)glPushName(12);   // Give it a name anyway
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left1C, Top1); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left1C ,Bottom1C[ilite][lprop] ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right1, Bottom1C[ilite][lprop]); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Right1 , Top1); // Top right
      glEnd();

      if(!draw_the_box)glPopName();   // red  box   popped
      //**********************************************************************

      //slide button green
      //
	             Right2=Left2C+w2;
		     Top2=Bottom2C[ilite][lprop]+h2;
		     if(draw_the_box){
      glBlendFunc(GL_DST_COLOR,GL_ZERO);
      glBindTexture(GL_TEXTURE_2D,gl_Texture[2]); }

      if(!draw_the_box)glPushName(13);   // Box 1  Button 2
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left2C, Top2); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left2C ,Bottom2C[ilite][lprop]); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right2, Bottom2C[ilite][lprop]); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Right2 , Top2); // Top right
      glEnd();
      if(!draw_the_box)glPopName();   // Box 1  Button 2 popped

	     if(draw_the_box){
      glBlendFunc(GL_ONE,GL_ONE);
      glBindTexture(GL_TEXTURE_2D,gl_Texture[3]);  }

      if(!draw_the_box)glPushName(14);   // Give it a name anyway
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left2C, Top2); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left2C ,Bottom2C[ilite][lprop]); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right2, Bottom2C[ilite][lprop]); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Right2 , Top2); // Top right
      glEnd();
      if(!draw_the_box)glPopName();   //   green box popped
      //**********************************************************************

      //slide button blue
      //
	             Right3=Left3C+w2;
		     Top3=Bottom3C[ilite][lprop]+h2;
		     if(draw_the_box){
      glBlendFunc(GL_DST_COLOR,GL_ZERO);
      glBindTexture(GL_TEXTURE_2D,gl_Texture[2]); }

      if(!draw_the_box)glPushName(15);   // Box 1  Button 3
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left3C, Top3); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left3C ,Bottom3C[ilite][lprop]); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right3, Bottom3C[ilite][lprop]); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Right3 , Top3); // Top right
      glEnd();
      if(!draw_the_box)glPopName();   // Box 1  Button 3 popped

	     if(draw_the_box){
      glBlendFunc(GL_ONE,GL_ONE);
      glBindTexture(GL_TEXTURE_2D,gl_Texture[3]);  }

      if(!draw_the_box)glPushName(16);   // Give it a name anyway
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left3C, Top3); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left3C ,Bottom3C[ilite][lprop]); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right3, Bottom3C[ilite][lprop]); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Right3 , Top3); // Top right
      glEnd();
      if(!draw_the_box)glPopName();   //   blue box popped
      //**********************************************************************


      //slide button alpha
      //
	             Right4=Left4C+w2;
		     Top4=Bottom4C[ilite][lprop]+h2;
		     if(draw_the_box){
      glBlendFunc(GL_DST_COLOR,GL_ZERO);
      glBindTexture(GL_TEXTURE_2D,gl_Texture[2]); }

      if(!draw_the_box)glPushName(17);   // Box 1  Button 3
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left4C, Top4); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left4C ,Bottom4C[ilite][lprop] ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right4, Bottom4C[ilite][lprop]); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Right4 , Top4); // Top right
      glEnd();
      if(!draw_the_box)glPopName();   // Box 1  Button 3 popped

	     if(draw_the_box){
      glBlendFunc(GL_ONE,GL_ONE);
      glBindTexture(GL_TEXTURE_2D,gl_Texture[3]);  }

      if(!draw_the_box)glPushName(18);   // Give it a name anyway
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left4C, Top4); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left4C ,Bottom4C[ilite][lprop]); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right4, Bottom4C[ilite][lprop]); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Right4 , Top4); // Top right
      glEnd();
      if(!draw_the_box)glPopName();   //   alpha box popped
      //**********************************************************************


      //textbox for light component
      glBlendFunc(GL_ONE,GL_ZERO);

      glBindTexture(GL_TEXTURE_2D,gl_Texture[4]);
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(LeftC+LeftNumC1, BottomC+BottomNumC1+0.1); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(LeftC+LeftNumC1,BottomC+BottomNumC1 ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(LeftC+LeftNumC1+0.25, BottomC+BottomNumC1); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(LeftC+LeftNumC1+0.25 , BottomC+BottomNumC1+0.1); // Top right
      glEnd(); 


      //two arrow boxes for light component
      glBindTexture(GL_TEXTURE_2D,gl_Texture[5]);
      if(!draw_the_box)glPushName(19);
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(LeftC+LeftArrowC1, BottomC+BottomDownArrowC1+0.05); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(LeftC+LeftArrowC1,BottomC+BottomDownArrowC1 ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(LeftC+LeftArrowC1+0.07, BottomC+BottomDownArrowC1); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(LeftC+LeftArrowC1+0.07 , BottomC+BottomDownArrowC1+0.05); // Top right
      glEnd(); 
      if(!draw_the_box)glPopName();


      glBindTexture(GL_TEXTURE_2D,gl_Texture[6]);
      if(!draw_the_box)glPushName(20);
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(LeftC+LeftArrowC1, BottomC+BottomUpArrowC1+0.05); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(LeftC+LeftArrowC1,BottomC+BottomUpArrowC1 ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(LeftC+LeftArrowC1+0.07, BottomC+BottomUpArrowC1); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(LeftC+LeftArrowC1+0.07 , BottomC+BottomUpArrowC1+0.05); // Top right
      glEnd(); 
      if(!draw_the_box)glPopName();

      //textbox for light number
      glBlendFunc(GL_ONE,GL_ZERO);

      glBindTexture(GL_TEXTURE_2D,gl_Texture[4]);
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(LeftC+LeftNumC2, BottomC+BottomNumC2+0.1); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(LeftC+LeftNumC2,BottomC+BottomNumC2 ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(LeftC+LeftNumC2+0.1, BottomC+BottomNumC2); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(LeftC+LeftNumC2+0.1 , BottomC+BottomNumC2+0.1); // Top right
      glEnd(); 


      //two arrow boxes for light number
      glBindTexture(GL_TEXTURE_2D,gl_Texture[5]);
      if(!draw_the_box)glPushName(21);
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(LeftC+LeftArrowC2, BottomC+BottomDownArrowC2+0.05); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(LeftC+LeftArrowC2,BottomC+BottomDownArrowC2 ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(LeftC+LeftArrowC2+0.07, BottomC+BottomDownArrowC2); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(LeftC+LeftArrowC2+0.07 , BottomC+BottomDownArrowC2+0.05); // Top right
      glEnd(); 
      if(!draw_the_box)glPopName();

      glBindTexture(GL_TEXTURE_2D,gl_Texture[6]);
      if(!draw_the_box)glPushName(22);
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(LeftC+LeftArrowC2, BottomC+BottomUpArrowC2+0.05); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(LeftC+LeftArrowC2,BottomC+BottomUpArrowC2 ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(LeftC+LeftArrowC2+0.07, BottomC+BottomUpArrowC2); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(LeftC+LeftArrowC2+0.07 , BottomC+BottomUpArrowC2+0.05); // Top right
      glEnd(); 
      if(!draw_the_box)glPopName();

       
      glColor3ub(0, 0, 255); // It ignores colour! Why?

// no longure use glPrint!
    //  char mytext[256]; //see glPrint in Init.h
      //initialise, otherwise garbage beyond
      //in call to glPrint, and ever changing garbage
      //every time mytext goes out of scope as this function
      //finishes off and mytext is declared again 
/*
      for(int ic=0; ic < 256; ic++){
	     mytext[ic]='\0'; 
      }
*/
      string LightComp;
      ostringstream oss;
      if(lprop==0)oss << "Ambient ";
      if(lprop==1)oss << "Diffuse ";
      if(lprop==2)oss << "Specular";
      LightComp=oss.str();

  //    if(ilite <10)mytext[1]='\0';
   //   if(ilite <10)LightNum[1]='\0';
   //   if(ilite <100)mytext[2]='\0';
   //   if(ilite <100)LightNum[2]='\0';

/*
      int ic=0;
      while(LightComp[ic] != '\0'){
	      mytext[ic]=LightComp[ic];
	      ic++;
      }
*/

      glRasterPos2f(LeftC+LeftNumC1+0.03, BottomC+BottomNumC1+0.03);       
 //     glPrint(mytext, 0.0);
        font10->draw(LightComp.c_str());

      string LightNum;
      ostringstream oss2;
      oss2 << ilite;
      LightNum=oss2.str();
/*
      if(ilite <10)mytext[1]='\0';
      if(ilite <10)LightNum[1]='\0';
      if(ilite <100)mytext[2]='\0';
      if(ilite <100)LightNum[2]='\0';

      ic=0;
      while(LightNum[ic] != '\0'){
	      mytext[ic]=LightNum[ic];
              ic++;}  */

      glRasterPos2f(LeftC+LeftNumC2+0.03, BottomC+BottomNumC2+0.03);       
   //   glPrint(mytext, 0.0);
      font10->draw(LightNum.c_str());


      if(!draw_the_box)glPopName();   // Box 1  popped

      glEnable(GL_LIGHTING);

       PerspectiveMode();

      if(!draw_the_box){
         glPopMatrix();
         glFlush();
         int hits=glRenderMode(GL_RENDER);
	// cout << " number of hits =" << hits << endl;
         ProcessHitsLC(hits, NameBuffer );
       }
       
}

void ProcessHitsLC(int hits, UINT  Buffer[]){
	 UINT* ptr_toBuffer;
	 UINT i,j;
	 UINT names;

	 bool boxonly=false;
	 bool box_slider1=false;
	 bool box_slider2=false;
	 bool box_slider3=false;
	 bool box_slider4=false;
	 bool arrow_up1=false;
	 bool arrow_down1=false;
	 bool arrow_up2=false;
	 bool arrow_down2=false;

	 ptr_toBuffer=Buffer;
	// if(hits>0)cout << "hits=" <<hits << endl;
	 for(int i=0; i< hits; i++){
		 if(hits==1)boxonly=true;

		  names=*ptr_toBuffer;  //contains number of names for hit
	//	  cout <<" number of names  for hit  " << i+1
		//	 << " is "   << names << endl;

		  ptr_toBuffer++;    //z1=(float)*ptr_toBuffer/0x7fffffff 
		  ptr_toBuffer++;    //z2=(float)*ptr_toBuffer/0x7fffffff 

		  ptr_toBuffer++;
		//  cout << "i=" << i << "  The name is " << endl;
		  for(j=0; j< names; j++){
			//  cout <<   "j= " << j << "  " << *ptr_toBuffer << "  ";
			  if(j==1 && *ptr_toBuffer==11)box_slider1=true;
			  if(j==1 && *ptr_toBuffer==13)box_slider2=true;
			  if(j==1 && *ptr_toBuffer==15)box_slider3=true;
			  if(j==1 && *ptr_toBuffer==17)box_slider4=true;
			  if(j==1 && *ptr_toBuffer==19)arrow_down1=true;
			  if(j==1 && *ptr_toBuffer==20)arrow_up1=true;
			  if(j==1 && *ptr_toBuffer==21)arrow_down2=true;
			  if(j==1 && *ptr_toBuffer==22)arrow_up2=true;
		          ptr_toBuffer++;  //name of child objects of name
		  }  
		//  cout << endl;  
		//  cout << " b , b s1,  b s2,  bs 3,  bs_4,   a_d,  a_u " << endl;
		 // cout <<   boxonly <<  "     " << box_slider1
		 //      << "      " << box_slider2
		  //     << "      " <<  box_slider3 
		  //     << "      " <<  box_slider4 
		   //    << "      " <<  arrow_down 
		  //     << "      " <<  arrow_up  << endl;

	//  cout <<"***********************************" << endl;
	//
	}  // end loop for hits
          SDL_GetMouseState(&mousex, &mousey);
	  if(mousedown && boxonly){
	//	  cout << firstmousedown << "  first mouse down?" << endl;
	          if(mouse_slide){ firstmousedown=true; mouse_slide=false;}
		  if(firstmousedown){
			  firstmousedown=false;
			  xstart=mousex;
			  ystart=mousey;
			  BottomStartC=BottomC;
			  LeftStartC=LeftC;
			  Left1CStart=Left1C;
			  Left2CStart=Left2C;
			  Left3CStart=Left3C;
			  Left4CStart=Left4C;
		  }
		  double ex, why;
		  ex=(double)(mousex-xstart)/( (double)WIDTH);
		  why=(double)(mousey-ystart)/( (double)HEIGHT);

		  LeftC=LeftStartC+ex*2.0;
		  BottomC=BottomStartC-2.0*why;

		  Left1C=Left1CStart+ex*2.0;
		  Left2C=Left2CStart+ex*2.0;
		  Left3C=Left3CStart+ex*2.0;
		  Left4C=Left4CStart+ex*2.0;

	//	  cout << "xs  ys  " << xstart <<  "  " <<ystart << endl;
	//	  cout << "xm  ym  " <<  mousex <<  "  " << mousey << endl;
	//	  cout << "LS BS  " << LeftStart << "  " << BottomStart << endl;
	//	  cout << "L B  " << Left << "  " << Bottom << endl;
	//
	//	  // of box moves move Left of all the lights and each slidebar

		  Bottom_BottomC=BottomC+BottomCMargin;
		  Bottom_TopC=BottomC+TopCMargin;
                  for(int il=0; il < ilights; il++){
			  for(int lp=0; lp<Lprops;lp++){
		  Bottom1C[il][lp]=Bottom_BottomC+RedLslide[il][lp];
		  Bottom2C[il][lp]=Bottom_BottomC+GreenLslide[il][lp];
		  Bottom3C[il][lp]=Bottom_BottomC+BlueLslide[il][lp];
		  Bottom4C[il][lp]=Bottom_BottomC+AlphaLslide[il][lp];
			  }
		  }

	//	  cout << ex << "  " << why << endl; 
	//	  cout << Left << "  " << Bottom << endl; 
	//	  cout << xstart << "  " << ystart << endl;
	//	  cout << mousey << "  " << ystart << endl; 
	//	  cout << "??????????????????????????????" << endl;
	  }
	  if( mousedown && box_slider1){
		  mouse_slide=true;  //if we drag mouse pointer off the button by
		                     //moving to fast, boxonly needs to know.
		  if(firstmousedown){
			  firstmousedown=false;
			  xstart=mousex;
			  ystart=mousey;
			  RedLStart=RedLslide[ilite][lprop];
		  }
		  double why;
		  why=(double)(mousey-ystart)/( (double)HEIGHT);
	//	  cout << "Left1 before=" << Left1 << endl;
		  RedLslide[ilite][lprop]=RedLStart
			                 -why*2.0; //Redslide isn't the Red value

                  if(RedLslide[ilite][lprop]<0.0)RedLslide[ilite][lprop]=0.0;
                  if(RedLslide[ilite][lprop]>Bottom_TopC-Bottom_BottomC)
                              RedLslide[ilite][lprop]=Bottom_TopC-Bottom_BottomC;

		  RedL[ilite][lprop]=RedLslide[ilite][lprop]
			  /(Bottom_TopC-Bottom_BottomC); // Red is!

		  Bottom1C[ilite][lprop]=Bottom_BottomC+RedLslide[ilite][lprop];

			  }
	  if( mousedown && box_slider2){
		  mouse_slide=true;  //if we drag mouse pointer off the button by
		                     //moving to fast, boxonly needs to know.
		  if(firstmousedown){
			  firstmousedown=false;
			  xstart=mousex;
			  ystart=mousey;
			  GreenLStart=GreenLslide[ilite][lprop];
		  }
		  double why;
		  why=(double)(mousey-ystart)/( (double)HEIGHT);
	//	  cout << "Left1 before=" << Left1 << endl;
		  GreenLslide[ilite][lprop]=GreenLStart
			                 -why*2.0; //Greenslide isn't the  Green value

                  if(GreenLslide[ilite][lprop]<0.0)GreenLslide[ilite][lprop]=0.0;
                  if(GreenLslide[ilite][lprop]>Bottom_TopC-Bottom_BottomC)
                              GreenLslide[ilite][lprop]=Bottom_TopC-Bottom_BottomC;


		  GreenL[ilite][lprop]=GreenLslide[ilite][lprop]
			  /(Bottom_TopC-Bottom_BottomC); // Green is!

		  Bottom2C[ilite][lprop]=Bottom_BottomC+GreenLslide[ilite][lprop];
			  }

	  if( mousedown && box_slider3){
		  mouse_slide=true;  //if we drag mouse pointer off the button by
		                     //moving to fast, boxonly needs to know.
		  if(firstmousedown){
			  firstmousedown=false;
			  xstart=mousex;
			  ystart=mousey;
			  BlueLStart=BlueLslide[ilite][lprop];
		  }
		  double why;
		  why=(double)(mousey-ystart)/( (double)HEIGHT);
	//	  cout << "Left1 before=" << Left1 << endl;
		  BlueLslide[ilite][lprop]=BlueLStart
			                 -why*2.0; //Blueslide isn't the Blue value

                  if(BlueLslide[ilite][lprop]<0.0)BlueLslide[ilite][lprop]=0.0;
                  if(BlueLslide[ilite][lprop]>Bottom_TopC-Bottom_BottomC)
                              BlueLslide[ilite][lprop]=Bottom_TopC-Bottom_BottomC;


		  BlueL[ilite][lprop]=BlueLslide[ilite][lprop]
			  /(Bottom_TopC-Bottom_BottomC); // Blue is!

		  Bottom3C[ilite][lprop]=Bottom_BottomC+BlueLslide[ilite][lprop];

			  }

	  if( mousedown && box_slider4){
		  mouse_slide=true;  //if we drag mouse pointer off the button by
		                     //moving to fast, boxonly needs to know.
		  if(firstmousedown){
			  firstmousedown=false;
			  xstart=mousex;
			  ystart=mousey;
			  AlphaLStart=AlphaLslide[ilite][lprop];
		  }
		  double why;
		  why=(double)(mousey-ystart)/( (double)HEIGHT);
	//	  cout << "Left1 before=" << Left1 << endl;
		  AlphaLslide[ilite][lprop]=AlphaLStart
			                 -why*2.0; //Alpha slide isn't the alpha value


                  if(AlphaLslide[ilite][lprop]<0.0)AlphaLslide[ilite][lprop]=0.0;
                  if(AlphaLslide[ilite][lprop]>Bottom_TopC-Bottom_BottomC)
                              AlphaLslide[ilite][lprop]=Bottom_TopC-Bottom_BottomC;


		  AlphaL[ilite][lprop]=AlphaLslide[ilite][lprop]
			  /(Bottom_TopC-Bottom_BottomC); // Alpha is!

		  Bottom4C[ilite][lprop]=Bottom_BottomC+AlphaLslide[ilite][lprop];

			  }

	  if(mousedown && firstmousedown && arrow_up1){
		  lprop+=1;   //ilite =0, ilights-1
		  if(lprop >= Lprops)lprop=Lprops-1; 
	          firstmousedown=false;
	  }
	  if(mousedown && firstmousedown && arrow_down1){
		  lprop-=1;
		  if(lprop < 0)lprop=0;
	          firstmousedown=false;
	  }

	  if(mousedown && firstmousedown && arrow_up2){
		  ilite+=1;   //ilite =0, ilights-1
		  if(ilite >= ilights)ilite=ilights-1; 
	          firstmousedown=false;
	  }
	  if(mousedown && firstmousedown && arrow_down2){
		  ilite-=1;
		  if(ilite < 0)ilite=0;
	          firstmousedown=false;
	  }

}

