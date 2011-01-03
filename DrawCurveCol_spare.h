void DrawCurveCol(bool draw_the_box)
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
      double Right5, Top5; //For button 

     //From trial and error
     //  Zenith slide bar button, bottom1=Bottom+TopMargin
     //  Azimuth slide bar button, bottom1=Bottom+BottomMargin
     //  Button far left =Left+LeftMargin
     //  Button Far right=Left+RightMargin
     //
     //  Image size is 676 wide 434 hide
      w1=360./800.*2.0;
      h1=180./600.*2.0;

      Right=LeftPC1+w1;
      Top=BottomPC1+h1;

      glDisable(GL_LIGHTING);  //control panels wont see lighting

      glColor3ub(255,255,255);

      if(!draw_the_box)glPushName(30);

      glBlendFunc(GL_ONE,GL_ZERO);
      glBindTexture(GL_TEXTURE_2D,gl_Texture[15]);
      glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(LeftPC1, Top); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(LeftPC1 ,BottomPC1 ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right, BottomPC1); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Right , Top); // Top right
      glEnd();
      glColor3ub(255,255,255);  //set back colour  */


/*******************************************************************************/
      //slide button red
	     w2=30./800.*2.0;
	     h2=30./600.*2.0;

	     Right1=Left1PC1+w2;
             Top1=Bottom1PC1[*(ncol+iplot)][1]+h2;

	     if(draw_the_box){
      glBlendFunc(GL_DST_COLOR,GL_ZERO);
      glBindTexture(GL_TEXTURE_2D,gl_Texture[2]);  }

      if(!draw_the_box)glPushName(31);  
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left1PC1, Top1); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left1PC1 ,Bottom1PC1[*(ncol+iplot)][1] ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right1, Bottom1PC1[*(ncol+iplot)][1]); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Right1 , Top1); // Top right
      glEnd();
      if(!draw_the_box)glPopName();   // Box 1  Button 1 popped
  

      //Then the bright red button!
	     if(draw_the_box){
      glBlendFunc(GL_ONE,GL_ONE);
      glBindTexture(GL_TEXTURE_2D,gl_Texture[3]); }

      if(!draw_the_box)glPushName(32);   // Give it a name anyway
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left1PC1, Top1); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left1PC1 ,Bottom1PC1[*(ncol+iplot)][1] ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right1, Bottom1PC1[*(ncol+iplot)][1]); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Right1 , Top1); // Top right
      glEnd();

      if(!draw_the_box)glPopName();   // red  box   popped
      //**********************************************************************
      //slide button green
      //
	     Right2=Left2PC1+w2;
	     Top2=Bottom2PC1[*(ncol+iplot)][1]+h2;
		     if(draw_the_box){
      glBlendFunc(GL_DST_COLOR,GL_ZERO);
      glBindTexture(GL_TEXTURE_2D,gl_Texture[2]); }

      if(!draw_the_box)glPushName(33);   // Box 1  Button 2
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left2PC1, Top2); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left2PC1 ,Bottom2PC1[*(ncol+iplot)][1]); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right2, Bottom2PC1[*(ncol+iplot)][1]); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Right2 , Top2); // Top right
      glEnd();
      if(!draw_the_box)glPopName();   // Box 1  Button 2 popped

	     if(draw_the_box){
      glBlendFunc(GL_ONE,GL_ONE);
      glBindTexture(GL_TEXTURE_2D,gl_Texture[3]);  }

      if(!draw_the_box)glPushName(34);   // Give it a name anyway
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left2PC1, Top2); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left2PC1 ,Bottom2PC1[*(ncol+iplot)][1]); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right2, Bottom2PC1[*(ncol+iplot)][1]); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Right2 , Top2); // Top right
      glEnd();
      if(!draw_the_box)glPopName();   //   green box popped
      //**********************************************************************

      //slide button blue
      //
	      Right3=Left3PC1+w2;
	      Top3=Bottom3PC1[*(ncol+iplot)][1]+h2;
		     if(draw_the_box){
      glBlendFunc(GL_DST_COLOR,GL_ZERO);
      glBindTexture(GL_TEXTURE_2D,gl_Texture[2]); }

      if(!draw_the_box)glPushName(35);   // Box 1  Button 3
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left3PC1, Top3); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left3PC1 ,Bottom3PC1[*(ncol+iplot)][1]); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right3, Bottom3PC1[*(ncol+iplot)][1]); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Right3 , Top3); // Top right
      glEnd();
      if(!draw_the_box)glPopName();   // Box 1  Button 3 popped

	     if(draw_the_box){
      glBlendFunc(GL_ONE,GL_ONE);
      glBindTexture(GL_TEXTURE_2D,gl_Texture[3]);  }

      if(!draw_the_box)glPushName(36);   // Give it a name anyway
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left3PC1, Top3); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left3PC1 ,Bottom3PC1[*(ncol+iplot)][1]); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right3, Bottom3PC1[*(ncol+iplot)][1]); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Right3 , Top3); // Top right
      glEnd();
      if(!draw_the_box)glPopName();   //   blue box popped
      //**********************************************************************

      //textbox for curve number
      glBlendFunc(GL_ONE,GL_ZERO);

      glBindTexture(GL_TEXTURE_2D,gl_Texture[4]);
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(LeftPC1+LeftNumPC11, BottomPC1+BottomNumPC11+0.06); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(LeftPC1+LeftNumPC11,BottomPC1+BottomNumPC11 ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(LeftPC1+LeftNumPC11+0.1, BottomPC1+BottomNumPC11); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(LeftPC1+LeftNumPC11+0.1 , BottomPC1+BottomNumPC11+0.06); // Top right
      glEnd(); 


      //two arrow boxes for curve number
      glBindTexture(GL_TEXTURE_2D,gl_Texture[6]);
      if(!draw_the_box)glPushName(41);
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(LeftPC1+LeftArrowPC11, BottomPC1+BottomDownArrowPC11+0.04); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(LeftPC1+LeftArrowPC11,BottomPC1+BottomDownArrowPC11 ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(LeftPC1+LeftArrowPC11+0.06, BottomPC1+BottomDownArrowPC11); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(LeftPC1+LeftArrowPC11+0.06 , BottomPC1+BottomDownArrowPC11+0.04); // Top right
      glEnd(); 
      if(!draw_the_box)glPopName();


      glBindTexture(GL_TEXTURE_2D,gl_Texture[5]);
      if(!draw_the_box)glPushName(42);
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(LeftPC1+LeftArrowPC11, BottomPC1+BottomUpArrowPC11+0.04); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(LeftPC1+LeftArrowPC11,BottomPC1+BottomUpArrowPC11 ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(LeftPC1+LeftArrowPC11+0.06, BottomPC1+BottomUpArrowPC11); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(LeftPC1+LeftArrowPC11+0.06 , BottomPC1+BottomUpArrowPC11+0.04); // Top right
      glEnd(); 
      if(!draw_the_box)glPopName();



      //textbox for curve style
      glBlendFunc(GL_ONE,GL_ZERO);

      glBindTexture(GL_TEXTURE_2D,gl_Texture[4]);
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(LeftPC1+LeftNumPC12, BottomPC1+BottomNumPC12+0.06); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(LeftPC1+LeftNumPC12,BottomPC1+BottomNumPC12 ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(LeftPC1+LeftNumPC12+0.1, BottomPC1+BottomNumPC12); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(LeftPC1+LeftNumPC12+0.1 , BottomPC1+BottomNumPC12+0.06); // Top right
      glEnd(); 


      //two arrow boxes for curve style
      glBindTexture(GL_TEXTURE_2D,gl_Texture[6]);
      if(!draw_the_box)glPushName(51);
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(LeftPC1+LeftArrowPC12, BottomPC1+BottomDownArrowPC12+0.04); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(LeftPC1+LeftArrowPC12,BottomPC1+BottomDownArrowPC12 ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(LeftPC1+LeftArrowPC12+0.06, BottomPC1+BottomDownArrowPC12); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(LeftPC1+LeftArrowPC12+0.06 , BottomPC1+BottomDownArrowPC12+0.04); // Top right
      glEnd(); 
      if(!draw_the_box)glPopName();


      glBindTexture(GL_TEXTURE_2D,gl_Texture[5]);
      if(!draw_the_box)glPushName(52);
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(LeftPC1+LeftArrowPC12, BottomPC1+BottomUpArrowPC12+0.04); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(LeftPC1+LeftArrowPC12,BottomPC1+BottomUpArrowPC12 ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(LeftPC1+LeftArrowPC12+0.06, BottomPC1+BottomUpArrowPC12); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(LeftPC1+LeftArrowPC12+0.06 , BottomPC1+BottomUpArrowPC12+0.04); // Top right
      glEnd(); 
      if(!draw_the_box)glPopName();


      //textbox for point size
      glBlendFunc(GL_ONE,GL_ZERO);

      glBindTexture(GL_TEXTURE_2D,gl_Texture[4]);
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(LeftPC1+LeftNumPC13, BottomPC1+BottomNumPC13+0.06); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(LeftPC1+LeftNumPC13,BottomPC1+BottomNumPC13 ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(LeftPC1+LeftNumPC13+0.1, BottomPC1+BottomNumPC13); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(LeftPC1+LeftNumPC13+0.1 , BottomPC1+BottomNumPC13+0.06); // Top right
      glEnd(); 


      //two arrow boxes for [oint size
      glBindTexture(GL_TEXTURE_2D,gl_Texture[6]);
      if(!draw_the_box)glPushName(61);
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(LeftPC1+LeftArrowPC13, BottomPC1+BottomDownArrowPC13+0.04); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(LeftPC1+LeftArrowPC13,BottomPC1+BottomDownArrowPC13 ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(LeftPC1+LeftArrowPC13+0.06, BottomPC1+BottomDownArrowPC13); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(LeftPC1+LeftArrowPC13+0.06 , BottomPC1+BottomDownArrowPC13+0.04); // Top right
      glEnd(); 
      if(!draw_the_box)glPopName();


      glBindTexture(GL_TEXTURE_2D,gl_Texture[5]);
      if(!draw_the_box)glPushName(62);
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(LeftPC1+LeftArrowPC13, BottomPC1+BottomUpArrowPC13+0.04); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(LeftPC1+LeftArrowPC13,BottomPC1+BottomUpArrowPC13 ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(LeftPC1+LeftArrowPC13+0.06, BottomPC1+BottomUpArrowPC13); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(LeftPC1+LeftArrowPC13+0.06 , BottomPC1+BottomUpArrowPC13+0.04); // Top right
      glEnd(); 

      //checkbox for points/lines
      if(!draw_the_box)glPopName();

	     if(draw_the_box){
		     if(*(ntype+iplot)==0){
      glBindTexture(GL_TEXTURE_2D,gl_Texture[10]);}
	     else{  
      glBindTexture(GL_TEXTURE_2D,gl_Texture[11]);  }
	     }

      if(!draw_the_box)glPushName(70);   // 
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(LeftPC1+0.17, BottomPC1+0.08); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(LeftPC1+0.17 ,BottomPC1+0.03); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(LeftPC1+0.22, BottomPC1+.03); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(LeftPC1+0.22, BottomPC1+.08); // Top right
      glEnd();
      if(!draw_the_box)glPopName();   // checkbox popped

     //write the numbers
      glColor3ub(0,0,0);
     {
         ostringstream oss; string numberstring;
         oss <<  iplot;
         numberstring=oss.str();
         glRasterPos2f(LeftPC1+0.1,Top-.21);
         font10->draw(numberstring.c_str());
      }
     {
         ostringstream oss; string numberstring;
         oss <<  *(nstyle+iplot);
         numberstring=oss.str();
         glRasterPos2f(LeftPC1+0.1,Top-.34);
         font10->draw(numberstring.c_str());
      }
     {
         ostringstream oss; string numberstring;
         oss <<  *(npoint+iplot);
         numberstring=oss.str();
         glRasterPos2f(LeftPC1+0.1,Top-.47);
         font10->draw(numberstring.c_str());
      }
         



      if(!draw_the_box)glPopName();   // Box 1  popped

      glEnable(GL_LIGHTING);

       PerspectiveMode();

      if(!draw_the_box){
         glPopMatrix();
         glFlush();
         int hits=glRenderMode(GL_RENDER);
	// cout << " number of hits =" << hits << endl;
         ProcessHitsPC1(hits, NameBuffer );
       }
       
}

void ProcessHitsPC1(int hits, UINT  Buffer[]){
	 UINT* ptr_toBuffer;
	 UINT i,j;
	 UINT names;

	 bool boxonly=false;
	 bool box_slider1=false;
	 bool box_slider2=false;
	 bool box_slider3=false;
	 bool arrow_up1=false;
	 bool arrow_down1=false;
	 bool arrow_up2=false;
	 bool arrow_down2=false;
	 bool arrow_up3=false;
	 bool arrow_down3=false;
         bool checkbox=false;


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
			  if(j==1 && *ptr_toBuffer==31)box_slider1=true;
			  if(j==1 && *ptr_toBuffer==33)box_slider2=true;
			  if(j==1 && *ptr_toBuffer==35)box_slider3=true;
			  if(j==1 && *ptr_toBuffer==41)arrow_down1=true;
			  if(j==1 && *ptr_toBuffer==42)arrow_up1=true;
			  if(j==1 && *ptr_toBuffer==51)arrow_down2=true;
			  if(j==1 && *ptr_toBuffer==52)arrow_up2=true;
			  if(j==1 && *ptr_toBuffer==61)arrow_down3=true;
			  if(j==1 && *ptr_toBuffer==62)arrow_up3=true;
			  if(j==1 && *ptr_toBuffer==70)checkbox=true;

		          ptr_toBuffer++;  //name of child objects of name
		  }  
	}  // end loop for hits

          SDL_GetMouseState(&mousex, &mousey);
	  if(mousedown && boxonly){
	//	  cout << firstmousedown << "  first mouse down?" << endl;
	          if(mouse_slide){ firstmousedown=true; mouse_slide=false;}
		  if(firstmousedown){
			  firstmousedown=false;
			  xstart=mousex;
			  ystart=mousey;

			  BottomStartPC1=BottomPC1;
			  LeftStartPC1=LeftPC1;
			  Left1PC1Start=Left1PC1;
			  Left2PC1Start=Left2PC1;
			  Left3PC1Start=Left3PC1;
		  }
		  double ex, why;
		  ex=(double)(mousex-xstart)/( (double)WIDTH);
		  why=(double)(mousey-ystart)/( (double)HEIGHT);

		  LeftPC1=LeftStartPC1+ex*2.0;
		  BottomPC1=BottomStartPC1-2.0*why;

		  Left1PC1=Left1PC1Start+ex*2.0;
		  Left2PC1=Left2PC1Start+ex*2.0;
		  Left3PC1=Left3PC1Start+ex*2.0;

		  Bottom_BottomPC1=BottomPC1+BottomPC1Margin;
		  Bottom_TopPC1=BottomPC1+TopPC1Margin;

                  for(int im=0; im <= nplots; im++){
			  for(int mp=0; mp < Mprops; mp++){
		  Bottom1PC1[im][mp]=Bottom_BottomPC1+RedPC1slide[im][mp];
		  Bottom2PC1[im][mp]=Bottom_BottomPC1+GreenPC1slide[im][mp];
		  Bottom3PC1[im][mp]=Bottom_BottomPC1+BluePC1slide[im][mp];
			  }
		  }
            } //endif box only

          //now for slide bars

        //  cout << box_slider1 << box_slider2 << box_slider3 << endl;
	  if( mousedown && box_slider1){
		  mouse_slide=true;  //if we drag mouse pointer off the button by
		                     //moving to fast, boxonly needs to know.
		  if(firstmousedown){
			  firstmousedown=false;
			  xstart=mousex;
			  ystart=mousey;
			  RedPC1Start=RedPC1slide[*(ncol+iplot)][1];
		  }
		  double why;
		  why=(double)(mousey-ystart)/( (double)HEIGHT);
	//	  cout << "Left1 before=" << Left1 << endl;
		  RedPC1slide[*(ncol+iplot)][1]=RedPC1Start
			                 -why*2.0; //Redslide isn't the Red value

                  //slide[*(ncol+iplot)] varies between
                  //0 and Top
                  if(RedPC1slide[*(ncol+iplot)][1]<0.0)RedPC1slide[*(ncol+iplot)][1]=0.0;
                  if(RedPC1slide[*(ncol+iplot)][1]>Bottom_TopPC1-Bottom_BottomPC1)
                              RedPC1slide[*(ncol+iplot)][1]=Bottom_TopPC1-Bottom_BottomPC1;

		  RedPC1[*(ncol+iplot)][1]=RedPC1slide[*(ncol+iplot)][1]
			  /(Bottom_TopPC1-Bottom_BottomPC1); 

		  Bottom1PC1[*(ncol+iplot)][1]=Bottom_BottomPC1+RedPC1slide[*(ncol+iplot)][1];
			  }

	  if( mousedown && box_slider2){
		  mouse_slide=true;  //if we drag mouse pointer off the button by
		                     //moving to fast, boxonly needs to know.
		  if(firstmousedown){
			  firstmousedown=false;
			  xstart=mousex;
			  ystart=mousey;
			  GreenPC1Start=GreenPC1slide[*(ncol+iplot)][1];
		  }
		  double why;
		  why=(double)(mousey-ystart)/( (double)HEIGHT);
                 
		  GreenPC1slide[*(ncol+iplot)][1]=GreenPC1Start
			                 -why*2.0; //Greenslide isn't the  Green value

                  if(GreenPC1slide[*(ncol+iplot)][1]<0.0)GreenPC1slide[*(ncol+iplot)][1]=0.0;
                  if(GreenPC1slide[*(ncol+iplot)][1]>Bottom_TopPC1-Bottom_BottomPC1)
                              GreenPC1slide[*(ncol+iplot)][1]=Bottom_TopPC1-Bottom_BottomPC1;


		  GreenPC1[*(ncol+iplot)][1]=GreenPC1slide[*(ncol+iplot)][1]
			  /(Bottom_TopPC1-Bottom_BottomPC1); // Green is!

		  Bottom2PC1[*(ncol+iplot)][1]=Bottom_BottomPC1+GreenPC1slide[*(ncol+iplot)][1];

			  }

	  if( mousedown && box_slider3){
		  mouse_slide=true;  //if we drag mouse pointer off the button by
		                     //moving to fast, boxonly needs to know.
		  if(firstmousedown){
			  firstmousedown=false;
			  xstart=mousex;
			  ystart=mousey;
			  BluePC1Start=BluePC1slide[*(ncol+iplot)][1];
		  }
		  double why;
		  why=(double)(mousey-ystart)/( (double)HEIGHT);
	//	  cout << "Left1 before=" << Left1 << endl;


		  BluePC1slide[*(ncol+iplot)][1]=BluePC1Start
			                 -why*2.0; //Blueslide isn't the Blue value

                  if(BluePC1slide[*(ncol+iplot)][1]<0.0)BluePC1slide[*(ncol+iplot)][1]=0.0;
                  if(BluePC1slide[*(ncol+iplot)][1]>Bottom_TopPC1-Bottom_BottomPC1)
                              BluePC1slide[*(ncol+iplot)][1]=Bottom_TopPC1-Bottom_BottomPC1;

		  BluePC1[*(ncol+iplot)][1]=BluePC1slide[*(ncol+iplot)][1]
			  /(Bottom_TopPC1-Bottom_BottomPC1); // Blue is!
	//		  /(Bottom_TopM-Bottom_BottomM); // Blue is!


		  Bottom3PC1[*(ncol+iplot)][1]=Bottom_BottomPC1+BluePC1slide[*(ncol+iplot)][1];
			  }
           cout << "iplot=" << iplot <<  "  " << *(ncol+iplot) << endl;


	  if(mousedown && firstmousedown && arrow_up1){
                  cout << "a " << iplot << " " << nplots << endl;
		  iplot+=1;  
		  if(iplot >= nplots)iplot=nplots-1; 
                  cout << "b " << iplot << " " << nplots << endl;
	          firstmousedown=false; 
                  
	  }
	  if(mousedown && firstmousedown && arrow_down1){
                  cout << "c " << iplot << " " << nplots << endl;
		  iplot-=1;
		  if(iplot < 0)iplot=0;
                  cout << "d " << iplot << " " << nplots << endl;
	          firstmousedown=false;
	  }
	  if(mousedown && firstmousedown && arrow_up2){
		  *(nstyle+iplot)+=1;   //imat =0, mats-1
		  if( *(nstyle+iplot) >4  )*(nstyle+iplot)-=1; 
	          firstmousedown=false;
	  }
	  if(mousedown && firstmousedown && arrow_down2){
		  *(nstyle+iplot)-=1;
		  if(*(nstyle+iplot) < 0)*(nstyle+iplot)=0;
	          firstmousedown=false;
	  }
	  if(mousedown && firstmousedown && arrow_up3){
		  *(npoint+iplot)+=1;   //imat =0, mats-1
		  if(*(npoint+iplot)>10 )*(npoint+iplot)-=1; 
	          firstmousedown=false;
	  }
	  if(mousedown && firstmousedown && arrow_down3){
		  *(npoint+iplot)-=1;
		  if(*(npoint+iplot) < 0)*(npoint+iplot)=0;
	          firstmousedown=false;
	  }

	  if(mousedown && firstmousedown && checkbox){
               if(*(ntype+iplot)==0){
                    *(ntype+iplot)=1;}
                   else{
                    *(ntype+iplot)=0;}
                 firstmousedown=false;
               }

}

