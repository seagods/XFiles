void DrawLightPos(bool draw_the_box)
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
     //  Image size is 676 wide 434 high
      w1=340./800.*2.0;
      h1=217./600.*2.0;

      Right=Left+w1;
      Top=Bottom+h1;

      glDisable(GL_LIGHTING);  //so control panels wont see lighting

      glColor3ub(255,255,255);

      if(!draw_the_box)glPushName(1);

      glBlendFunc(GL_ONE,GL_ZERO);
      glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
      glBindTexture(GL_TEXTURE_2D,gl_Texture[1]);
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
             //slider for zenith

	     w2=30./800.*2.0;
	     h2=30./600.*2.0;

	     Bottom1=Bottom+TopMargin;
	     Right1=Left1[ilite]+w2;
             Top1=Bottom1+h2;
	     if(draw_the_box){
      glBlendFunc(GL_DST_COLOR,GL_ZERO);
      glBindTexture(GL_TEXTURE_2D,gl_Texture[2]);  }

      if(!draw_the_box)glPushName(2);   // Box 1  Button 1 
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left1[ilite], Top1); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left1[ilite] ,Bottom1 ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right1, Bottom1); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Right1 , Top1); // Top right
      glEnd();
      if(!draw_the_box)glPopName();   // Box 1  Button 1 popped
  

      //Then the bright red button!
      //slide button for  zenith
	     if(draw_the_box){
      glBlendFunc(GL_ONE,GL_ONE);
      glBindTexture(GL_TEXTURE_2D,gl_Texture[3]); }

      if(!draw_the_box)glPushName(3);   // Give it a name anyway
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left1[ilite], Top1); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left1[ilite] ,Bottom1 ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right1, Bottom1); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Right1 , Top1); // Top right
      glEnd();

      if(!draw_the_box)glPopName();   // Zen box   popped
      //**********************************************************************

      //slide button azimumth
      //
		     Bottom2=Bottom+MiddleMarge1;
	             Right2=Left2[ilite]+w2;
		     Top2=Bottom2+h2;
		     if(draw_the_box){
      glBlendFunc(GL_DST_COLOR,GL_ZERO);
      glBindTexture(GL_TEXTURE_2D,gl_Texture[2]); }

      if(!draw_the_box)glPushName(4);   // Box 1  Button 2
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left2[ilite], Top2); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left2[ilite] ,Bottom2 ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right2, Bottom2); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Right2 , Top2); // Top right
      glEnd();
      if(!draw_the_box)glPopName();   // Box 1  Button 2 popped

	     if(draw_the_box){
      glBlendFunc(GL_ONE,GL_ONE);
      glBindTexture(GL_TEXTURE_2D,gl_Texture[3]);  }

      if(!draw_the_box)glPushName(5);   // Give it a name anyway
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left2[ilite], Top2); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left2[ilite] ,Bottom2 ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right2, Bottom2); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Right2 , Top2); // Top right
      glEnd();
      if(!draw_the_box)glPopName();   //  azim box popped
      //**********************************************************************

      //slide button rho
      //
		     Bottom3=Bottom+BottomMargin;
	             Right3=Left3[ilite]+w2;
		     Top3=Bottom3+h2;
		     if(draw_the_box){
      glBlendFunc(GL_DST_COLOR,GL_ZERO);
      glBindTexture(GL_TEXTURE_2D,gl_Texture[2]); }

      if(!draw_the_box)glPushName(6);   // Box 1  Button 3
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left3[ilite], Top3); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left3[ilite] ,Bottom3 ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right3, Bottom3); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Right3 , Top3); // Top right
      glEnd();
      if(!draw_the_box)glPopName();   // Box 1  Button 3 popped

	     if(draw_the_box){
      glBlendFunc(GL_ONE,GL_ONE);
      glBindTexture(GL_TEXTURE_2D,gl_Texture[3]);  }

      if(!draw_the_box)glPushName(7);   // Give it a name anyway
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left3[ilite], Top3); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left3[ilite] ,Bottom3 ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right3, Bottom3); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Right3 , Top3); // Top right
      glEnd();
      if(!draw_the_box)glPopName();   //  rho box popped
      //**********************************************************************

      glBlendFunc(GL_ONE,GL_ZERO);

      glBindTexture(GL_TEXTURE_2D,gl_Texture[4]);  // White background for text
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left+LeftNum, Bottom+BottomNum+0.1); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left+LeftNum,Bottom+BottomNum ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Left+LeftNum+0.1, Bottom+BottomNum); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Left+LeftNum+0.1 , Bottom+BottomNum+0.1); // Top right
      glEnd(); 



      glBindTexture(GL_TEXTURE_2D,gl_Texture[6]);  //Arrows
      if(!draw_the_box)glPushName(8);
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left+LeftArrow, Bottom+BottomDownArrow+0.05); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left+LeftArrow,Bottom+BottomDownArrow ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Left+LeftArrow+0.07, Bottom+BottomDownArrow); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Left+LeftArrow+0.07 , Bottom+BottomDownArrow+0.05); // Top right
      glEnd(); 
      if(!draw_the_box)glPopName();

      glBindTexture(GL_TEXTURE_2D,gl_Texture[5]);
      if(!draw_the_box)glPushName(9);
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left+LeftArrow, Bottom+BottomUpArrow+0.05); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left+LeftArrow,Bottom+BottomUpArrow ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Left+LeftArrow+0.07, Bottom+BottomUpArrow); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Left+LeftArrow+0.07 , Bottom+BottomUpArrow+0.05); // Top right
      glEnd(); 
      if(!draw_the_box)glPopName();
 
      glColor3ub(0, 0, 255); // It ignores colour! Why?

      glRasterPos2f(Left+LeftNum+0.03, Bottom+BottomNum+0.03);  //text position     
/*
      char mytext[256]; //see glPrint in Init.h
      for(int ic=0; ic < 256; ic++)
	     mytext[ic]='\0'; 
*/
      string LightNum;
      ostringstream oss;
      oss << ilite;
      LightNum=oss.str();

      font10->draw(LightNum.c_str());

/*
      if(ilite <10)mytext[1]='\0';
      if(ilite <10)LightNum[1]='\0';
      if(ilite <100)mytext[2]='\0';
      if(ilite <100)LightNum[2]='\0';

      int ic=0;
      while(LightNum[ic] != '\0'){
	      mytext[ic]=LightNum[ic];
              ic++;}

      glPrint(mytext, 0.0);
      */


      if(!draw_the_box)glPopName();   // Box 1  popped

      glEnable(GL_LIGHTING);

       PerspectiveMode();

      if(!draw_the_box){
         glPopMatrix();
         glFlush();
         int hits=glRenderMode(GL_RENDER);
	// cout << " number of hits =" << hits << endl;
         ProcessHitsLP(hits, NameBuffer );
       }
       
}

void ProcessHitsLP(int hits, UINT  Buffer[]){
	 UINT* ptr_toBuffer;
	 UINT i,j;
	 UINT names;

	 bool boxonly=false;
	 bool box_slider1=false;
	 bool box_slider2=false;
	 bool box_slider3=false;
	 bool arrow_up=false;
	 bool arrow_down=false;

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
			  if(j==1 && *ptr_toBuffer==2)box_slider1=true;
			  if(j==1 && *ptr_toBuffer==4)box_slider2=true;
			  if(j==1 && *ptr_toBuffer==6)box_slider3=true;
			  if(j==1 && *ptr_toBuffer==8)arrow_down=true;
			  if(j==1 && *ptr_toBuffer==9)arrow_up=true;
		          ptr_toBuffer++;  //name of child objects of name
		  }  
	//	  cout << endl;  
	//	  cout << " b , b s1,  b s2,  bs 3,  a_d,  a_u " << endl;
	//	  cout <<   boxonly <<  "     " << box_slider1
	//	       << "      " << box_slider2
	//	       << "      " <<  box_slider3 
	//	       << "      " <<  arrow_down 
	//	       << "      " <<  arrow_up  << endl;

	//  cout <<"***********************************" << endl;
	//
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

	//	  cout << "xs  ys  " << xstart <<  "  " <<ystart << endl;
	//	  cout << "xm  ym  " <<  mousex <<  "  " << mousey << endl;
	//	  cout << "LS BS  " << LeftStart << "  " << BottomStart << endl;
	//	  cout << "L B  " << Left << "  " << Bottom << endl;
	//
	//	  // of box moves move Left of all the lights and each slidebar

		  Left_Left=Left+LeftMargin;
		  Left_Right=Left+RightMargin;
                  for(int il=0; il < ilights; il++){
		  Left1[il]=Left_Left+zenangle[il];
		  Left2[il]=Left_Left+azimangle[il];
		  Left3[il]=Left_Left+rhovalue[il]; 
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
			  ZenStart=zenangle[ilite];
		  }
		  double ex;
		  ex=(double)(mousex-xstart)/( (double)WIDTH);
	//	  cout << "Left1 before=" << Left1 << endl;
		  zenangle[ilite]=ZenStart+ex*2.0; //zenangle isn't the zenith angle

                  if(zenangle[ilite]<0.0)zenangle[ilite]=0.0;
                  if(zenangle[ilite]>Left_Right-Left_Left)
                              zenangle[ilite]=Left_Right-Left_Left;

		  Zen[ilite]=zenangle[ilite]/(Left_Right-Left_Left)*180.0; // Zen is

		  Left1[ilite]=Left_Left+zenangle[ilite];

			  }
	  if( mousedown && box_slider2){
		  mouse_slide=true;  //if we drag mouse pointer off the button by
		                     //moving to fast, boxonly needs to know.
		  if(firstmousedown){
			  firstmousedown=false;
			  xstart=mousex;
			  ystart=mousey;
			  AzimStart=azimangle[ilite];
		  }
		  double ex;
		  ex=(double)(mousex-xstart)/( (double)WIDTH);

		  azimangle[ilite]=AzimStart+ex*2.0;  //azimangle isn't the azimuth angle


                  if(azimangle[ilite]<0.0)azimangle[ilite]=0.0;
                  if(azimangle[ilite]>Left_Right-Left_Left)
                              azimangle[ilite]=Left_Right-Left_Left;

		  Az[ilite]=azimangle[ilite]/(Left_Right-Left_Left)*360.0; // Az is!

		  Left2[ilite]=Left_Left+azimangle[ilite];

			  }


	  if( mousedown && box_slider3){
		  mouse_slide=true;  //if we drag mouse pointer off the button by
		                     //moving to fast, boxonly needs to know.
		  if(firstmousedown){
			  firstmousedown=false;
			  xstart=mousex;
			  ystart=mousey;
			  rhoStart=rhovalue[ilite];
		  }
		  double ex;
		  ex=(double)(mousex-xstart)/( (double)WIDTH);

		  rhovalue[ilite]=rhoStart+ex*2.0; 
		  //rho value isn't the distance
		  Rho[ilite]=rhovalue[ilite]/(Left_Right-Left_Left)*L_Dist_Scale; 
		  // Rho  is!

		  Left3[ilite]=Left_Left+rhovalue[ilite];
		  if(Left3[ilite] < Left_Left)Left3[ilite]=Left_Left;
		  if(Left3[ilite] > Left_Right)Left3[ilite]=Left_Right;
			  }

	  if(mousedown && firstmousedown && arrow_up){
		  ilite+=1;   //ilite =0, ilights-1
		  if(ilite >= ilights)ilite=ilights-1; 
	          firstmousedown=false;
	  }
	  if(mousedown && firstmousedown && arrow_down){
		  ilite-=1;
		  if(ilite < 0)ilite=0;
	          firstmousedown=false;
	  }

}

