void DrawMatCol(bool draw_the_box)
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

      Right=LeftM+w1;
      Top=BottomM+h1;

      glDisable(GL_LIGHTING);  //control panels wont see lighting

      glColor3ub(255,255,255);

      if(!draw_the_box)glPushName(30);

      glBlendFunc(GL_ONE,GL_ZERO);
      glBindTexture(GL_TEXTURE_2D,gl_Texture[8]);
      glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(LeftM, Top); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(LeftM ,BottomM ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right, BottomM); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Right , Top); // Top right
      glEnd();
      glColor3ub(255,255,255);  //set back colour  */


/*******************************************************************************/
      //slide button red
	     w2=30./800.*2.0;
	     h2=30./600.*2.0;

	     Right1=Left1M+w2;
             Top1=Bottom1M[imat][mprop]+h2;

	     if(draw_the_box){
      glBlendFunc(GL_DST_COLOR,GL_ZERO);
      glBindTexture(GL_TEXTURE_2D,gl_Texture[2]);  }

      if(!draw_the_box)glPushName(31);  
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left1M, Top1); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left1M ,Bottom1M[imat][mprop] ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right1, Bottom1M[imat][mprop]); // Bottom right
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
	     glVertex2f(Left1M, Top1); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left1M ,Bottom1M[imat][mprop] ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right1, Bottom1M[imat][mprop]); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Right1 , Top1); // Top right
      glEnd();

      if(!draw_the_box)glPopName();   // red  box   popped
      //**********************************************************************

      //slide button green
      //
	             Right2=Left2M+w2;
		     Top2=Bottom2M[imat][mprop]+h2;
		     if(draw_the_box){
      glBlendFunc(GL_DST_COLOR,GL_ZERO);
      glBindTexture(GL_TEXTURE_2D,gl_Texture[2]); }

      if(!draw_the_box)glPushName(33);   // Box 1  Button 2
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left2M, Top2); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left2M ,Bottom2M[imat][mprop]); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right2, Bottom2M[imat][mprop]); // Bottom right
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
	     glVertex2f(Left2M, Top2); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left2M ,Bottom2M[imat][mprop]); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right2, Bottom2M[imat][mprop]); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Right2 , Top2); // Top right
      glEnd();
      if(!draw_the_box)glPopName();   //   green box popped
      //**********************************************************************

      //slide button blue
      //
	             Right3=Left3M+w2;
		     Top3=Bottom3M[imat][mprop]+h2;
		     if(draw_the_box){
      glBlendFunc(GL_DST_COLOR,GL_ZERO);
      glBindTexture(GL_TEXTURE_2D,gl_Texture[2]); }

      if(!draw_the_box)glPushName(35);   // Box 1  Button 3
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left3M, Top3); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left3M ,Bottom3M[imat][mprop]); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right3, Bottom3M[imat][mprop]); // Bottom right
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
	     glVertex2f(Left3M, Top3); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left3M ,Bottom3M[imat][mprop]); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right3, Bottom3M[imat][mprop]); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Right3 , Top3); // Top right
      glEnd();
      if(!draw_the_box)glPopName();   //   blue box popped
      //**********************************************************************


      //slide button alpha
      //
	             Right4=Left4M+w2;
		     Top4=Bottom4M[imat][mprop]+h2;
		     if(draw_the_box){
      glBlendFunc(GL_DST_COLOR,GL_ZERO);
      glBindTexture(GL_TEXTURE_2D,gl_Texture[2]); }

      if(!draw_the_box)glPushName(37);   // Box 1  Button 4
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left4M, Top4); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left4M ,Bottom4M[imat][mprop] ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right4, Bottom4M[imat][mprop]); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Right4 , Top4); // Top right
      glEnd();
      if(!draw_the_box)glPopName();   // Box 1  Button 4 popped

	     if(draw_the_box){
      glBlendFunc(GL_ONE,GL_ONE);
      glBindTexture(GL_TEXTURE_2D,gl_Texture[3]);  }

      if(!draw_the_box)glPushName(38);   // Give it a name anyway
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left4M, Top4); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left4M ,Bottom4M[imat][mprop]); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right4, Bottom4M[imat][mprop]); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Right4 , Top4); // Top right
      glEnd();
      if(!draw_the_box)glPopName();   //   alpha box popped
      //**********************************************************************

      //**********************************************************************


      //slide button shine
      //
	             Right5=Left5M+w2;
		     Top5=Bottom5M[imat][mprop]+h2;
		     if(draw_the_box){
      glBlendFunc(GL_DST_COLOR,GL_ZERO);
      glBindTexture(GL_TEXTURE_2D,gl_Texture[2]); }

      if(!draw_the_box)glPushName(39);   // Box 1  Button 5

      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left5M, Top5); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left5M ,Bottom5M[imat][mprop] ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right5, Bottom5M[imat][mprop]); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Right5 , Top5); // Top right
      glEnd();
      if(!draw_the_box)glPopName();   // Box 1  Button 5 popped

	     if(draw_the_box){
      glBlendFunc(GL_ONE,GL_ONE);
      glBindTexture(GL_TEXTURE_2D,gl_Texture[3]);  }

      if(!draw_the_box)glPushName(40);   // Give it a name anyway
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left5M, Top5); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left5M ,Bottom5M[imat][mprop]); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right5, Bottom5M[imat][mprop]); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Right5 , Top5); // Top right
      glEnd();
      if(!draw_the_box)glPopName();   //   shine  box popped
      //**********************************************************************

      //textbox for material component
      glBlendFunc(GL_ONE,GL_ZERO);

      glBindTexture(GL_TEXTURE_2D,gl_Texture[4]);
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(LeftM+LeftNumM1, BottomM+BottomNumM1+0.1); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(LeftM+LeftNumM1,BottomM+BottomNumM1 ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(LeftM+LeftNumM1+0.2, BottomM+BottomNumM1); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(LeftM+LeftNumM1+0.2 , BottomM+BottomNumM1+0.1); // Top right
      glEnd(); 


      //two arrow boxes for material component
      glBindTexture(GL_TEXTURE_2D,gl_Texture[5]);
      if(!draw_the_box)glPushName(41);
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(LeftM+LeftArrowM1, BottomM+BottomDownArrowM1+0.05); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(LeftM+LeftArrowM1,BottomM+BottomDownArrowM1 ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(LeftM+LeftArrowM1+0.07, BottomM+BottomDownArrowM1); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(LeftM+LeftArrowM1+0.07 , BottomM+BottomDownArrowM1+0.05); // Top right
      glEnd(); 
      if(!draw_the_box)glPopName();


      glBindTexture(GL_TEXTURE_2D,gl_Texture[6]);
      if(!draw_the_box)glPushName(42);
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(LeftM+LeftArrowM1, BottomM+BottomUpArrowM1+0.05); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(LeftM+LeftArrowM1,BottomM+BottomUpArrowM1 ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(LeftM+LeftArrowM1+0.07, BottomM+BottomUpArrowM1); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(LeftM+LeftArrowM1+0.07 , BottomM+BottomUpArrowM1+0.05); // Top right
      glEnd(); 
      if(!draw_the_box)glPopName();

      //textbox for material component
      glBlendFunc(GL_ONE,GL_ZERO);

      glBindTexture(GL_TEXTURE_2D,gl_Texture[4]);
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(LeftM+LeftNumM2, BottomM+BottomNumM2+0.1); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(LeftM+LeftNumM2,BottomM+BottomNumM2 ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(LeftM+LeftNumM2+0.1, BottomM+BottomNumM2); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(LeftM+LeftNumM2+0.1 , BottomM+BottomNumM2+0.1); // Top right
      glEnd(); 


      //two arrow boxes for material number
      glBindTexture(GL_TEXTURE_2D,gl_Texture[5]);
      if(!draw_the_box)glPushName(43);
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(LeftM+LeftArrowM2, BottomM+BottomDownArrowM2+0.05); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(LeftM+LeftArrowM2,BottomM+BottomDownArrowM2 ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(LeftM+LeftArrowM2+0.07, BottomM+BottomDownArrowM2); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(LeftM+LeftArrowM2+0.07 , BottomM+BottomDownArrowM2+0.05); // Top right
      glEnd(); 
      if(!draw_the_box)glPopName();

      glBindTexture(GL_TEXTURE_2D,gl_Texture[6]);
      if(!draw_the_box)glPushName(44);
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(LeftM+LeftArrowM2, BottomM+BottomUpArrowM2+0.05); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(LeftM+LeftArrowM2,BottomM+BottomUpArrowM2 ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(LeftM+LeftArrowM2+0.07, BottomM+BottomUpArrowM2); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(LeftM+LeftArrowM2+0.07 , BottomM+BottomUpArrowM2+0.05); // Top right
      glEnd(); 
      if(!draw_the_box)glPopName();

       
      glColor3ub(0, 0, 255); // It ignores colour! Why?

// dont use glPrint  (now stripped out altogether along with buildFont etc
  /*    char mytext[256]; //see glPrint in Init.h
      for(int ic=0; ic < 256; ic++)
	     mytext[ic]='\0'; 
  */
      string MatComp;
      ostringstream oss;
      if(mprop==0)oss << "Ambient ";
      if(mprop==1)oss << "Diffuse ";
      if(mprop==2)oss << "Specular";
       MatComp=oss.str();

  //    if(imat <10)mytext[1]='\0';
   //   if(imat <10)LightNum[1]='\0';
   //   if(imat <100)mytext[2]='\0';
   //   if(imat <100)LightNum[2]='\0';

      /*
int ic=0;
      while(MatComp[ic] != '\0'){
	      mytext[ic]=MatComp[ic];
              ic++;}
       */

      glRasterPos2f(LeftM+LeftNumM1+0.03, BottomM+BottomNumM1+0.03);       
    //  glPrint(mytext, 0.0);
      font10->draw(MatComp.c_str());

      string MatNum;
      ostringstream oss2;
      oss2 << imat;
      MatNum=oss2.str();
/*
      if(imat <10)mytext[1]='\0';
      if(imat <10)MatNum[1]='\0';
      if(imat <100)mytext[2]='\0';
      if(imat <100)MatNum[2]='\0';

      ic=0;
      while(MatNum[ic] != '\0'){
	      mytext[ic]=MatNum[ic];
              ic++;}
*/

      glRasterPos2f(LeftM+LeftNumM2+0.03, BottomM+BottomNumM2+0.03);       
     // glPrint(mytext, 0.0);

      font10->draw(MatNum.c_str());

      if(!draw_the_box)glPopName();   // Box 1  popped

      glEnable(GL_LIGHTING);

       PerspectiveMode();

      if(!draw_the_box){
         glPopMatrix();
         glFlush();
         int hits=glRenderMode(GL_RENDER);
	// cout << " number of hits =" << hits << endl;
         ProcessHitsMC(hits, NameBuffer );
       }
       
}

void ProcessHitsMC(int hits, UINT  Buffer[]){
	 UINT* ptr_toBuffer;
	 UINT i,j;
	 UINT names;

	 bool boxonly=false;
	 bool box_slider1=false;
	 bool box_slider2=false;
	 bool box_slider3=false;
	 bool box_slider4=false;
	 bool box_slider5=false;
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
			  if(j==1 && *ptr_toBuffer==31)box_slider1=true;
			  if(j==1 && *ptr_toBuffer==33)box_slider2=true;
			  if(j==1 && *ptr_toBuffer==35)box_slider3=true;
			  if(j==1 && *ptr_toBuffer==37)box_slider4=true;
			  if(j==1 && *ptr_toBuffer==39)box_slider5=true;
			  if(j==1 && *ptr_toBuffer==41)arrow_down1=true;
			  if(j==1 && *ptr_toBuffer==42)arrow_up1=true;
			  if(j==1 && *ptr_toBuffer==43)arrow_down2=true;
			  if(j==1 && *ptr_toBuffer==44)arrow_up2=true;
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

			  BottomStartM=BottomM;
			  LeftStartM=LeftM;
			  Left1MStart=Left1M;
			  Left2MStart=Left2M;
			  Left3MStart=Left3M;
			  Left4MStart=Left4M;
			  Left5MStart=Left5M;
		  }
		  double ex, why;
		  ex=(double)(mousex-xstart)/( (double)WIDTH);
		  why=(double)(mousey-ystart)/( (double)HEIGHT);

		  LeftM=LeftStartM+ex*2.0;
		  BottomM=BottomStartM-2.0*why;

		  Left1M=Left1MStart+ex*2.0;
		  Left2M=Left2MStart+ex*2.0;
		  Left3M=Left3MStart+ex*2.0;
		  Left4M=Left4MStart+ex*2.0;
		  Left5M=Left5MStart+ex*2.0;

	//	  cout << "xs  ys  " << xstart <<  "  " <<ystart << endl;
	//	  cout << "xm  ym  " <<  mousex <<  "  " << mousey << endl;
	//	  cout << "LS BS  " << LeftStart << "  " << BottomStart << endl;
	//	  cout << "L B  " << Left << "  " << Bottom << endl;
	//
	//	  // of box moves move Left of all the lights and each slidebar

		  Bottom_BottomM=BottomM+BottomMMargin;
		  Bottom_TopM=BottomM+TopMMargin;
                  for(int im=0; im < imats; im++){
			  for(int mp=0; mp < Mprops; mp++){
		  Bottom1M[imat][mp]=Bottom_BottomM+RedMslide[imat][mp];
		  Bottom2M[imat][mp]=Bottom_BottomM+GreenMslide[imat][mp];
		  Bottom3M[imat][mp]=Bottom_BottomM+BlueMslide[imat][mp];
		  Bottom4M[imat][mp]=Bottom_BottomM+AlphaMslide[imat][mp];
		  Bottom5M[imat][mp]=Bottom_BottomM+ShineMslide[imat][mp];
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
			  RedMStart=RedMslide[imat][mprop];
		  }
		  double why;
		  why=(double)(mousey-ystart)/( (double)HEIGHT);
	//	  cout << "Left1 before=" << Left1 << endl;
		  RedMslide[imat][mprop]=RedMStart
			                 -why*2.0; //Redslide isn't the Red value

                  if(RedMslide[imat][mprop]<0.0)RedMslide[imat][mprop]=0.0;
                  if(RedMslide[imat][mprop]>Bottom_TopM-Bottom_BottomM)
                              RedMslide[imat][mprop]=Bottom_TopM-Bottom_BottomM;

		  RedM[imat][mprop]=RedMslide[imat][mprop]
			  /(Bottom_TopM-Bottom_BottomM); // Red is!

		  Bottom1M[imat][mprop]=Bottom_BottomM+RedMslide[imat][mprop];
			  }
	  if( mousedown && box_slider2){
		  mouse_slide=true;  //if we drag mouse pointer off the button by
		                     //moving to fast, boxonly needs to know.
		  if(firstmousedown){
			  firstmousedown=false;
			  xstart=mousex;
			  ystart=mousey;
			  GreenMStart=GreenMslide[imat][mprop];
		  }
		  double why;
		  why=(double)(mousey-ystart)/( (double)HEIGHT);
	//	  cout << "Left1 before=" << Left1 << endl;
		  GreenMslide[imat][mprop]=GreenMStart
			                 -why*2.0; //Greenslide isn't the  Green value

                  if(GreenMslide[imat][mprop]<0.0)GreenMslide[imat][mprop]=0.0;
                  if(GreenMslide[imat][mprop]>Bottom_TopM-Bottom_BottomM)
                              GreenMslide[imat][mprop]=Bottom_TopM-Bottom_BottomM;


		  GreenM[imat][mprop]=GreenMslide[imat][mprop]
			  /(Bottom_TopM-Bottom_BottomM); // Green is!

		  Bottom2M[imat][mprop]=Bottom_BottomM+GreenMslide[imat][mprop];
			  }

	  if( mousedown && box_slider3){
		  mouse_slide=true;  //if we drag mouse pointer off the button by
		                     //moving to fast, boxonly needs to know.
		  if(firstmousedown){
			  firstmousedown=false;
			  xstart=mousex;
			  ystart=mousey;
			  BlueMStart=BlueMslide[imat][mprop];
		  }
		  double why;
		  why=(double)(mousey-ystart)/( (double)HEIGHT);
	//	  cout << "Left1 before=" << Left1 << endl;
		  BlueMslide[imat][mprop]=BlueMStart
			                 -why*2.0; //Blueslide isn't the Blue value

                  if(BlueMslide[imat][mprop]<0.0)BlueMslide[imat][mprop]=0.0;
                  if(BlueMslide[imat][mprop]>Bottom_TopM-Bottom_BottomM)
                              BlueMslide[imat][mprop]=Bottom_TopM-Bottom_BottomM;


		  BlueM[imat][mprop]=BlueMslide[imat][mprop]
			  /(Bottom_TopM-Bottom_BottomM); // Blue is!

		  Bottom3M[imat][mprop]=Bottom_BottomM+BlueMslide[imat][mprop];
			  }

	  if( mousedown && box_slider4){
		  mouse_slide=true;  //if we drag mouse pointer off the button by
		                     //moving to fast, boxonly needs to know.
		  if(firstmousedown){
			  firstmousedown=false;
			  xstart=mousex;
			  ystart=mousey;
			  AlphaMStart=AlphaMslide[imat][mprop];
		  }
		  double why;
		  why=(double)(mousey-ystart)/( (double)HEIGHT);
	//	  cout << "Left1 before=" << Left1 << endl;
		  AlphaMslide[imat][mprop]=AlphaMStart
			                 -why*2.0; //Alpha slide isn't the alpha value


                  if(AlphaMslide[imat][mprop]<0.0)AlphaMslide[imat][mprop]=0.0;
                  if(AlphaMslide[imat][mprop]>Bottom_TopM-Bottom_BottomM)
                              AlphaMslide[imat][mprop]=Bottom_TopM-Bottom_BottomM;


		  AlphaM[imat][mprop]=AlphaMslide[imat][mprop]
			  /(Bottom_TopM-Bottom_BottomM); // Alpha is!

		  Bottom4M[imat][mprop]=Bottom_BottomM+AlphaMslide[imat][mprop];
			  }

	  if( mousedown && box_slider5){
		  mouse_slide=true;  //if we drag mouse pointer off the button by
		                     //moving to fast, boxonly needs to know.
		  if(firstmousedown){
			  firstmousedown=false;
			  xstart=mousex;
			  ystart=mousey;
			  ShineMStart=ShineMslide[imat][mprop];
		  }
		  double why;
		  why=(double)(mousey-ystart)/( (double)HEIGHT);
	//	  cout << "Left1 before=" << Left1 << endl;
		  ShineMslide[imat][mprop]=ShineMStart
			                 -why*2.0; // Shine slide isn't the alpha value

                  if(ShineMslide[imat][mprop]<0.0)ShineMslide[imat][mprop]=0.0;
                  if(ShineMslide[imat][mprop]>Bottom_TopM-Bottom_BottomM)
                              ShineMslide[imat][mprop]=Bottom_TopM-Bottom_BottomM;

		  ShineM[imat][mprop]=ShineMslide[imat][mprop]
			  /(Bottom_TopM-Bottom_BottomM)*127.; // Shine is!

		  Bottom5M[imat][mprop]=Bottom_BottomM+ShineMslide[imat][mprop];
			  }

	  if(mousedown && firstmousedown && arrow_up1){
		  mprop+=1;   //imat =0, mats-1
		  if(mprop >= Lprops)mprop=Lprops-1; 
	          firstmousedown=false;
	  }
	  if(mousedown && firstmousedown && arrow_down1){
		  mprop-=1;
		  if(mprop < 0)mprop=0;
	          firstmousedown=false;
	  }

	  if(mousedown && firstmousedown && arrow_up2){
		  imat+=1;   //imat =0, imats-1
		  if(imat >= imats)imat=imats-1; 
	          firstmousedown=false;
	  }
	  if(mousedown && firstmousedown && arrow_down2){
		  imat-=1;
		  if(imat < 0)imat=0;
	          firstmousedown=false;
	  }

}

