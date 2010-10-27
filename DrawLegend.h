void DrawLegend(bool draw_the_box)
{

#define LINE0 0xFFFF
#define LINE1 0x0101
#define LINE2 0x00FF
#define LINE3 0x1C47
#define LINE4 0x3F07



    //
    //********************************************************************//
    //               Draw objects which can be selected
    //   **************************************************************   //
    //

      int viewport[4];
      SDL_GetMouseState(&mousex, &mousey);
      UINT NameBuffer[50];
      glSelectBuffer(50,NameBuffer);

     // post_Pressed=true;
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

      if(draw_the_box){
            float scalefac=1.0;
            OrthoMode(-scalefac, scalefac, scalefac, -scalefac);
          //  OrthoMode(-1, 1, 1, -1);  //calls glOrtho (see Init.h)
            glRasterPos2f(0.0,0.0);
       }

      // Box for  four vertical sliders
      double w1, h1, w2, h2;
      double Bottom, Right;   // For panel

      w1=120./800.*2.0;
      h1=300./600.*2.0;

      float xgl;
      int igl;

      h1=nplots*.2;

      Right=LeftLeg+w1;
      Bottom=TopLeg-h1;

      glDisable(GL_LIGHTING);  //control panels wont see lighting
      glColor3ub(0,0,0);  //set back colour to black for text */
      glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
      float  Topshift=0.1;

      if(post_Pressed){
        glDisable(GL_TEXTURE_2D);
	      xgl=1.0;
	      glLineWidth(1.0);
	      igl=gl2psLineWidth(xgl);
      glColor3ub(0,0,0);
      glBegin(GL_LINES);
        glVertex2f(LeftLeg,TopLeg); glVertex2f(LeftLeg,TopLeg-h1);
        glVertex2f(LeftLeg,TopLeg-h1); glVertex2f(LeftLeg+w1,TopLeg-h1);
        glVertex2f(LeftLeg+w1,TopLeg-h1); glVertex2f(LeftLeg+w1,TopLeg);
        glVertex2f(LeftLeg+w1,TopLeg); glVertex2f(LeftLeg,TopLeg);
      glEnd();
      glColor3ub(255,255,255);
      glBegin(GL_QUADS);
	     glVertex2f(LeftLeg, TopLeg); 
	     glVertex2f(LeftLeg,Bottom); // Bottom Left
	     glVertex2f(Right, Bottom); // Bottom right
	     glVertex2f(Right , TopLeg); // Top right
      glEnd();
        glEnable(GL_TEXTURE_2D);
      }


      if(!post_Pressed){
      glBlendFunc(GL_ONE,GL_ZERO);
      glBindTexture(GL_TEXTURE_2D,gl_Texture[16]);
      glColor3ub(255,255,255);  //for bitmap if drawn
      if(!draw_the_box)glPushName(30);
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	  //  glVertex2f(LeftLeg, TopLeg+nplots*.1); 
	    glVertex2f(LeftLeg, TopLeg); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	  //  glVertex2f(LeftLeg,Bottom+nplots*.1); // Bottom Left
	     glVertex2f(LeftLeg,Bottom); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	  //   glVertex2f(Right, Bottom+nplots*.1); // Bottom right
	     glVertex2f(Right, Bottom); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	  //   glVertex2f(Right , TopLeg+nplots*.1); // Top right
	     glVertex2f(Right , TopLeg); // Top right
      glEnd();
      if(!draw_the_box)glPopName();
      }    //get no text in postscript legend if post_Pressed

      glColor3ub(0,0,0);  //set back colour to black for text */
      glDisable(GL_TEXTURE_2D);  //otherwise line colours mucked up
      for(int i=0; i<nplots; i++){

 	     if(LIGHTS){
              //aint gonna happen
               cout << "LIGHTS MUST BE SET TO FALSE FOR PLOTIT" << endl;
               exit(0);
	     }
	     else
	     {
	            glColor3ub((int)(255*RedPC1[*(ncol+i)][1]),
                   (int)(255*GreenPC1[*(ncol+i)][1]),(int)(255*BluePC1[*(ncol+i)][1]));
	}  //endif for LIGHTS

          glLineWidth((float)*(npoint+i));
	  igl=gl2psLineWidth((float)*(npoint+i));

          if(*(ntype+i)==0){ //plot lines
// the 1 is a stretch factor (dont strectch)

          if(*(nstyle+i)==0)glLineStipple(1,LINE0);
          if(*(nstyle+i)==1)glLineStipple(1,LINE1);
          if(*(nstyle+i)==2)glLineStipple(1,LINE2);
          if(*(nstyle+i)==3)glLineStipple(1,LINE3);
          if(*(nstyle+i)==4)glLineStipple(1,LINE4);

      glEnable(GL_LINE_STIPPLE);
      gl2psEnable(GL2PS_LINE_STIPPLE);
      gl2psEnable(GL_BLEND);

          double x1,y1,x2,y2;
          x1=LeftLeg+w1*.1;  x2=LeftLeg+w1*.9;
          y1=TopLeg-Topshift-.15*i-.05; y2=y1;
          glBegin(GL_LINES);
              glVertex3d(x1,y1,0.0);
              glVertex3d(x2,y2,0.0);
          glEnd();
      glDisable(GL_LINE_STIPPLE);
      gl2psDisable(GL_LINE_STIPPLE);
      gl2psDisable(GL_BLEND);
      }

       if(*(ntype+i)==1){ //plot points
         glPointSize((float)*(npoint+i));
	 gl2psPointSize((float)*(npoint+i));
          glBegin(GL_POINTS);
              double x1,y1,x2,y2;
              x1=LeftLeg+w1/2.0; y1=TopLeg-Topshift-.15*i-.05;
              glVertex3d(x1,y1,0.0);
          glEnd();
      }
      }   // end nplots loop

     glColor3ub(0,0,0);
     glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

/*       Works on 32 bit
     for(int i=0; i<nplots; i++){
           glRasterPos2f(LeftLeg+0.05, TopLeg-Topshift-i*0.15);
           glPushMatrix();
           font10->(LegendStrings[i].c_str()); 
           glPopMatrix();
      }
*/


      PerspectiveMode();

      //Hell, can't get text to print in OrthoMode(-1, 1, 1, -1); 
      //so if we need postscript, have to do this
  //    if(post_Pressed){
  //
  //  Now have to do this always in 64 bit
      float scalefac=200.0;
      OrthoMode(-scalefac, scalefac, scalefac, -scalefac);
      glRasterPos2f(0.0,0.0);
      glTranslated(scalefac*(LeftLeg+0.05),scalefac*(TopLeg-Topshift),0.0);
      for(int i=0;i<nplots;i++){
        glPushMatrix();
        font11->draw(LegendStrings[i].c_str());
        glPopMatrix();
        glTranslated(0.0,-0.15*scalefac,0.0);

      }
  //    }

      PerspectiveMode();



      glEnable(GL_LIGHTING);


      if(!draw_the_box){
         glPopMatrix();
         glFlush();
         int hits=glRenderMode(GL_RENDER);
	// cout << " number of hits =" << hits << endl;
         ProcessHitsLeg(hits, NameBuffer );
       }
       
      glEnable(GL_TEXTURE_2D);
}

void ProcessHitsLeg(int hits, UINT  Buffer[]){
	 UINT* ptr_toBuffer;
	 UINT i,j;
	 UINT names;

	 bool boxonly=false;

         if(hits>=1)boxonly=true;

          SDL_GetMouseState(&mousex, &mousey);
	  if(mousedown && boxonly){
	//	  cout << firstmousedown << "  first mouse down?" << endl;
	          if(mouse_slide){ firstmousedown=true; mouse_slide=false;}
		  if(firstmousedown){
			  firstmousedown=false;
			  xstart=mousex;
			  ystart=mousey;

			  TopLegStart=TopLeg;
			  LeftLegStart=LeftLeg;
		  }
		  double ex, why;
		  ex=(double)(mousex-xstart)/( (double)WIDTH);
		  why=(double)(mousey-ystart)/( (double)HEIGHT);

		  LeftLeg=LeftLegStart+ex*2.0;
                  TopLeg=TopLegStart-why*2.0;

            } //endif box only


}

