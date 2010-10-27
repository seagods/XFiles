void DrawFlipperBox(bool draw_the_box)
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
      glBindTexture(GL_TEXTURE_2D,gl_Texture[16]);
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

             for(int i=0; i<iwnumb; i++){
               for(int j=0;j<idtotal[i];j++){
                  if(!draw_the_box)glPushName(2+i+j*iwnumb);
                       if(flippit[i][j]){
                         glBindTexture(GL_TEXTURE_2D,gl_Texture[10]);}
                       else{
                         glBindTexture(GL_TEXTURE_2D,gl_Texture[11]);}
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left+0.1*(j+1), Top-0.081*(i+1)); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left+0.1*(j+1) , Top-0.081*(i+1)-h2); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Left+0.1*(j+1)+w2, Top-0.081*(i+1)-h2); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Left+0.1*(j+1)+w2, Top-0.081*(i+1)); // Top right
      glEnd();
                   if(!draw_the_box)glPopName();
                     }
                  }

      glEnable(GL_LIGHTING);

       PerspectiveMode();
  


      glEnable(GL_LIGHTING);

       PerspectiveMode();

      if(!draw_the_box){
         glPopMatrix();
         glFlush();
         int hits=glRenderMode(GL_RENDER);
	// cout << " number of hits =" << hits << endl;
         ProcessHitsFB(hits, NameBuffer );
       }
       
}

void ProcessHitsFB(int hits, UINT  Buffer[]){
	 UINT* ptr_toBuffer;
	 UINT i,j;
	 UINT names;

         bool** checked;
         checked=new bool*[iwnumb];
         for(int i=0;i< iwnumb;i++){
          checked[i]=new bool[idtotal[i]]; 
          for(int j=0; j<idtotal[i]; j++){
             checked[i][j]=false;
         }}
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
            int checkerkount;
            for(int k=0; k<iwnumb; k++){
            for(int l=0; l<idtotal[k]; l++){
              checkerkount=2+k+l*iwnumb;
          //    cout <<" k and l are " << k <<"  "<< l << endl;
          //    cout << j << " " << *ptr_toBuffer << "  " << checkerkount << endl;
              if(j==1 && *ptr_toBuffer==checkerkount)checked[k][l]=true;
              }}
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


		  Left_Left=Left+LeftMargin;
		  Left_Right=Left+RightMargin;

	  }



          for(int i=0; i<iwnumb;i++){
          for(int j=0; j<idtotal[i];j++){
	  if(mousedown && firstmousedown && checked[i][j]){
                if(flippit[i][j]){
                   flippit[i][j]=false;
                }
                else{
                   flippit[i][j]=true;
		  }
                firstmousedown=false;
          }
          }}

         for(int i=0;i< iwnumb;i++){
          delete[] checked[i];
          checked[i]=NULL;
         }

         delete[] checked;
         checked=NULL;
         

}

