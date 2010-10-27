void DrawLogicBox(bool draw_the_box)
{

    //
    //********************************************************************//
    //               Draw objects which can be selected
    //   **************************************************************   //
    //

      int viewport[4];
      SDL_GetMouseState(&mousex, &mousey);
      UINT NameBuffer[50];
      glSelectBuffer(50,NameBuffer); //PushName goes in NameBuffer

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

      // Box for three horizontal  sliders
      double w1, h1, w2, h2;
      double Top, Right;   // For panel
      double Right1, Top1; //For button 
      double Right2, Top2; //For button 
      double Right3, Top3; //For button 

     //From trial and error
     //  Zenith slide bar button, bottom1=Bottom+TopMargin
     //  Azimuth slide bar button, bottom1=Bottom+BottomMargin
     //  Button far left =Left+LeftMargin
     //  Button Far right=Left+RightMargin
     //
     //  Image size is 716 wide 499 high
      w1=716./((double)WIDTH);
      h1=499./((double)HEIGHT);

      Right=Left+w1;
      Top=Bottom+h1;

      glDisable(GL_LIGHTING);  //so control panels wont see lighting

      glColor3ub(255,255,255);

      if(!draw_the_box)glPushName(1);  //the whole kaboodle

      glBlendFunc(GL_ONE,GL_ZERO);
      glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
      glBindTexture(GL_TEXTURE_2D,gl_Texture[9]);
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left, Top); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left ,Bottom ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right, Bottom); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Right , Top); // Top right
      glEnd();
      glColor3ub(255,255,255);  //set back colour  */


/************************************************************************/

	     w2=30./((double)WIDTH);
	     h2=30./((double)HEIGHT);

	     if(draw_the_box){
		     if(freedom){
      glBindTexture(GL_TEXTURE_2D,gl_Texture[10]);}
	     else{  
      glBindTexture(GL_TEXTURE_2D,gl_Texture[11]);  }
	     }

      if(!draw_the_box)glPushName(2);   //  CheckBox freedom
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left+LeftL1*w1, Bottom+TopL1*h1); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left+LeftL1*w1 ,Bottom+TopL1*h1-h2); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Left+LeftL1*w1+w2, Bottom+TopL1*h1-h2); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Left+LeftL1*w1+w2, Bottom+TopL1*h1); // Top right
      glEnd();
      if(!draw_the_box)glPopName();   // Box 1  Button 1 popped

	     if(draw_the_box){
		     if(tethered){
      glBindTexture(GL_TEXTURE_2D,gl_Texture[10]);}
	     else{  
      glBindTexture(GL_TEXTURE_2D,gl_Texture[11]);  }
	     }

      if(!draw_the_box)glPushName(3);   //  CheckBox tethered
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left+LeftL1*w1, Bottom+TopL2*h1); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left+LeftL1*w1 ,Bottom+TopL2*h1-h2); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Left+LeftL1*w1+w2, Bottom+TopL2*h1-h2); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Left+LeftL1*w1+w2, Bottom+TopL2*h1); // Top right
      glEnd();
      if(!draw_the_box)glPopName();   // Box 1  Button 1 popped

	     if(draw_the_box){
		     if(staked){
      glBindTexture(GL_TEXTURE_2D,gl_Texture[10]);}
	     else{  
      glBindTexture(GL_TEXTURE_2D,gl_Texture[11]);  }
	     }

      if(!draw_the_box)glPushName(4);   //  CheckBox staked
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left+LeftL1*w1, Bottom+TopL3*h1); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left+LeftL1*w1 ,Bottom+TopL3*h1-h2); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Left+LeftL1*w1+w2, Bottom+TopL3*h1-h2); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Left+LeftL1*w1+w2, Bottom+TopL3*h1); // Top right
      glEnd();
      if(!draw_the_box)glPopName();   // Box 1  Button 1 popped

	     if(draw_the_box){
		     if(wander){
      glBindTexture(GL_TEXTURE_2D,gl_Texture[10]);}
	     else{  
      glBindTexture(GL_TEXTURE_2D,gl_Texture[11]);  }
	     }

      if(!draw_the_box)glPushName(5);   //  CheckBox wander
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left+LeftL1*w1, Bottom+TopL4*h1); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left+LeftL1*w1 ,Bottom+TopL4*h1-h2); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Left+LeftL1*w1+w2, Bottom+TopL4*h1-h2); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Left+LeftL1*w1+w2, Bottom+TopL4*h1); // Top right
      glEnd();
      if(!draw_the_box)glPopName();   // Box 1  Button 1 popped

	     if(draw_the_box){
		     if(flight){
      glBindTexture(GL_TEXTURE_2D,gl_Texture[10]);}
	     else{  
      glBindTexture(GL_TEXTURE_2D,gl_Texture[11]);  }
	     }

      if(!draw_the_box)glPushName(6);   //  CheckBox flight
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left+LeftL1*w1, Bottom+TopL5*h1); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left+LeftL1*w1 ,Bottom+TopL5*h1-h2); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Left+LeftL1*w1+w2, Bottom+TopL5*h1-h2); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Left+LeftL1*w1+w2, Bottom+TopL5*h1); // Top right
      glEnd();
      if(!draw_the_box)glPopName();   // Box 1  Button 1 popped

	     if(draw_the_box){
		     if(aeroplane){
      glBindTexture(GL_TEXTURE_2D,gl_Texture[10]);}
	     else{  
      glBindTexture(GL_TEXTURE_2D,gl_Texture[11]);  }
	     }
      if(!draw_the_box)glPushName(7);   //  CheckBox flight
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left+LeftL2*w1, Bottom+TopL1*h1); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left+LeftL2*w1 ,Bottom+TopL1*h1-h2); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Left+LeftL2*w1+w2, Bottom+TopL1*h1-h2); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Left+LeftL2*w1+w2, Bottom+TopL1*h1); // Top right
      glEnd();
      if(!draw_the_box)glPopName();   // Box 1  Button 1 popped


	     if(draw_the_box){
		     if(exwhyzed){
      glBindTexture(GL_TEXTURE_2D,gl_Texture[10]);}
	     else{  
      glBindTexture(GL_TEXTURE_2D,gl_Texture[11]);  }
	     }
      if(!draw_the_box)glPushName(8);   //  CheckBox flight
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left+LeftL2*w1, Bottom+TopL2*h1); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left+LeftL2*w1 ,Bottom+TopL2*h1-h2); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Left+LeftL2*w1+w2, Bottom+TopL2*h1-h2); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Left+LeftL2*w1+w2, Bottom+TopL2*h1); // Top right
      glEnd();
      if(!draw_the_box)glPopName();   // Box 1  Button 1 popped

	     if(draw_the_box){
		     if(boom){
      glBindTexture(GL_TEXTURE_2D,gl_Texture[10]);}
	     else{  
      glBindTexture(GL_TEXTURE_2D,gl_Texture[11]);  }
	     }
      if(!draw_the_box)glPushName(9);   //  CheckBox flight
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left+LeftL2*w1, Bottom+TopL3*h1); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left+LeftL2*w1 ,Bottom+TopL3*h1-h2); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Left+LeftL2*w1+w2, Bottom+TopL3*h1-h2); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Left+LeftL2*w1+w2, Bottom+TopL3*h1); // Top right
      glEnd();
      if(!draw_the_box)glPopName();   // Box 1  Button 1 popped

	     if(draw_the_box){
		     if(Picking){
      glBindTexture(GL_TEXTURE_2D,gl_Texture[10]);}
	     else{  
      glBindTexture(GL_TEXTURE_2D,gl_Texture[11]);  }
	     }
      if(!draw_the_box)glPushName(10);   //  CheckBox flight
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left+LeftL2*w1, Bottom+TopL4*h1); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left+LeftL2*w1 ,Bottom+TopL4*h1-h2); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Left+LeftL2*w1+w2, Bottom+TopL4*h1-h2); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Left+LeftL2*w1+w2, Bottom+TopL4*h1); // Top right
      glEnd();
      if(!draw_the_box)glPopName();   // Box 1  Button 1 popped


      glEnable(GL_LIGHTING);

       PerspectiveMode();
  


      glEnable(GL_LIGHTING);

       PerspectiveMode();

      if(!draw_the_box){
         glPopMatrix();
         glFlush();
         int hits=glRenderMode(GL_RENDER);
	// cout << " number of hits =" << hits << endl;
         ProcessHitsLB(hits, NameBuffer );
       }
       
}

void ProcessHitsLB(int hits, UINT  Buffer[]){
	 UINT* ptr_toBuffer;
	 UINT i,j;
	 UINT names;

	 bool checkfree=false;
	 bool checktethered=false;
	 bool checkstaked=false;
	 bool checkwander=false;
	 bool checkflight=false;
	 bool checkaeroplane=false;
	 bool checkboom=false;
	 bool checkexwhyzed=false;
	 bool checkpicking=false;
	 bool boxonly=false;

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
			  if(j==1 && *ptr_toBuffer==2)checkfree=true;
			  if(j==1 && *ptr_toBuffer==3)checktethered=true;
			  if(j==1 && *ptr_toBuffer==4)checkstaked=true;
			  if(j==1 && *ptr_toBuffer==5)checkwander=true;
			  if(j==1 && *ptr_toBuffer==6)checkflight=true;
			  if(j==1 && *ptr_toBuffer==7)checkaeroplane=true;
			  if(j==1 && *ptr_toBuffer==8)checkexwhyzed=true;
			  if(j==1 && *ptr_toBuffer==9)checkboom=true;
			  if(j==1 && *ptr_toBuffer==10)checkpicking=true;
		          ptr_toBuffer++;  //name of child objects of name
		  }  
	}  // end loop for hits
          SDL_GetMouseState(&mousex, &mousey);
	  if(mousedown && boxonly){

	          if(mouse_slide){ firstmousedown=true; mouse_slide=false;}
		  if(firstmousedown){
			  firstmousedown=false;
			  xstart=mousex;
			  ystart=mousey;
			  BottomStart=Bottom;
			  LeftStart=Left;
		  }
		  double ex, why;
		  ex=(double)(mousex-xstart)/( (double)WIDTH);
		  why=(double)(mousey-ystart)/( (double)HEIGHT);

		  Left=LeftStart+ex*2.0;
		  Bottom=BottomStart-why*2.0;

/*
		  Left_Left=Left+LeftMargin;
		  Left_Right=Left+RightMargin;
                  for(int il=0; il < ilights; il++){
		  Left1[il]=Left_Left+zenangle[il];
		  Left2[il]=Left_Left+azimangle[il];
		  Left3[il]=Left_Left+rhovalue[il]; 
		  }
*/

	  }
	  if(mousedown && firstmousedown && checkfree){
		  if(freedom){
			  tethered=true;
			  freedom=false;

			  staked=false;
			  wander=false;
			  aeroplane=false;
			  exwhyzed=true;
			  boom=false;
		  }
		  else
		  {
			  freedom=true;
			  tethered=false;   //set all defaults

			  staked=false;
			  wander=true;
			  aeroplane=false;
			  exwhyzed=true;
			  boom=false;
		  }
	  }

	  if(mousedown && firstmousedown && checktethered){
		  if(tethered){
			  tethered=false;
			  freedom=true;

			  staked=false;
			  exwhyzed=true;
			  wander=true;
			  aeroplane=false;
			  boom=false;
		  }
		  else
		  {
			  tethered=true;   //set all defaults
			  freedom=false;

			  exwhyzed=true;
			  boom=false;
			  staked=false;
			  wander=false;
			  aeroplane=false;
		  }
	          firstmousedown=false;
	  }

	  if(mousedown && firstmousedown && checkstaked){
		  if(staked){
			  staked=false;
			  freedom=true;

			  tethered=false;
			  exwhyzed=true;
			  boom=false;
			  wander=true;
			  aeroplane=false;
		  }
		  else
		  {
			  staked=true;
			  freedom=false;   //set all defaults

			  tethered=false;
			  wander=false;
			  exwhyzed=true;
			  boom=false;
			  aeroplane=false;
		  }
	          firstmousedown=false;
	  }

	  if(mousedown && firstmousedown && checkwander){
		  if(freedom){
		  if(wander){
			  wander=false;
			  flight=true;
		  }
		  else
		  {
			  wander=true;
			  flight=false;   //set all defaults
		  }
	          firstmousedown=false;}
	  }

	  if(mousedown && firstmousedown && checkflight){
		  if(freedom){
		  if(flight){
			  flight=false;
			  wander=true;
			  exwhyzed=true;
		  }
		  else
		  {
			  flight=true;   
			  wander=false;
			  exwhyzed=true;
		  }
	          firstmousedown=false;}
	  }

	  if(mousedown && firstmousedown && checkaeroplane){
		  if(flight){
		  if(aeroplane){
			  aeroplane=false;
			  exwhyzed=true;
		  }
		  else
		  {
			  exwhyzed=false;
			  aeroplane=true;   //set all defaults
		  }
	          firstmousedown=false;}
	  }


	  if(mousedown && firstmousedown && checkexwhyzed){
                  if(!staked  && !wander){
		  if(exwhyzed){
			  exwhyzed=false;
			  if(tethered)boom=true;
			  if(freedom)aeroplane=true;
		  }
		  else
		  {
			  exwhyzed=true;
			  if(tethered)boom=false;
			  if(freedom)aeroplane=false;
		  }
	          firstmousedown=false;}
	  }

	  if(mousedown && firstmousedown && checkboom){
		  if(tethered){
		  if(boom){
			  boom=false;
			  exwhyzed=true;
		  }
		  else
		  {
			  boom=true;
			  exwhyzed=false;
		  }
	          firstmousedown=false;}
	  }

	  if(mousedown && firstmousedown && checkpicking){
		  if(Picking){
			  Picking=false;
		  }
		  else
		  {
			  Picking=true;
		  }
	          firstmousedown=false;
	  }


}

