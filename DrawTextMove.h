void DrawTextMove(bool draw_the_box)
{

    //
    //********************************************************************//
    //               Draw objects which can be selected
    //   **************************************************************   //
    //
    // selection mode shrinks to a small viewport with 4 boundaries - hence viewport[4]

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

      Right=LeftDT+w1;
      Top=BottomDT+h1;

      glDisable(GL_LIGHTING);  //control panels wont see lighting

      glColor3ub(255,255,255);

      if(!draw_the_box)glPushName(30);

      glBlendFunc(GL_ONE,GL_ZERO);
      glBindTexture(GL_TEXTURE_2D,gl_Texture[12]);
      glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(LeftDT, Top); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(LeftDT ,BottomDT ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right, BottomDT); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Right , Top); // Top right
      glEnd();
      glColor3ub(255,255,255);  //set back colour  */


      double xbox[4], ybox[6];

      xbox[0]=.55; xbox[1]=.63; xbox[2]=.71; xbox[3]=.79;

      ybox[0]=.06; ybox[1]=.15; ybox[2]=.24; ybox[3]=.33; ybox[4]=.42; ybox[5]=.51;


      int boxcount=0;

      for(int i=0; i<6; i++){
        for(int j=0; j<4; j++){
           boxcount++;
      //Arrow boxus 
      if(j==0)glBindTexture(GL_TEXTURE_2D,gl_Texture[13]);  //left
      if(j==1)glBindTexture(GL_TEXTURE_2D,gl_Texture[14]);  //right
      if(j==2)glBindTexture(GL_TEXTURE_2D,gl_Texture[6]);   //up 
      if(j==3)glBindTexture(GL_TEXTURE_2D,gl_Texture[5]);   //down

      if(!draw_the_box)glPushName(40+boxcount);
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(LeftDT+xbox[j], BottomDT+ybox[i]+0.05); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(LeftDT+xbox[j],BottomDT+ybox[i]); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(LeftDT+xbox[j]+0.07, BottomDT+ybox[i]); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(LeftDT+xbox[j]+0.07 , BottomDT+ybox[i]+0.05); // Top right
      glEnd(); 
      if(!draw_the_box)glPopName();

       }}

       
      glColor3ub(0, 0, 255); // It ignores colour! Why?

 
      if(!draw_the_box)glPopName();   // Box 1  popped

      glEnable(GL_LIGHTING);

       PerspectiveMode();

      if(!draw_the_box){
         glPopMatrix();
         glFlush();
         int hits=glRenderMode(GL_RENDER);
	// cout << " number of hits =" << hits << endl;
         ProcessHitsDT(hits, NameBuffer );
       }
       
}

void ProcessHitsDT(int hits, UINT  Buffer[]){
	 UINT* ptr_toBuffer;
	 UINT i,j;
	 UINT names;

	 bool boxonly=false;

	 bool arrows[24];
            for(int i=0; i<24;i++){
                   arrows[i]=false;}

	 ptr_toBuffer=Buffer;
	// if(hits>0)cout << "hits=" <<hits << endl;
	 for(int i=0; i< hits; i++){
		 if(hits==1)boxonly=true;

		  names=*ptr_toBuffer;  //contains number of names for hit
		 // cout <<" number of names  for hit  " << i+1 << " is "   << names << endl;

		  ptr_toBuffer++;    //z1=(float)*ptr_toBuffer/0x7fffffff 
		  ptr_toBuffer++;    //z2=(float)*ptr_toBuffer/0x7fffffff 

		  ptr_toBuffer++;
		//  cout << "i=" << i << "  The name is " << endl;
		  for(j=0; j< names; j++){
			//  cout <<   "j= " << j << "  " << *ptr_toBuffer << "  "  << endl;
                          int iarrow=0;
                          for(int k=0; k<24; k++){
                             iarrow++;
                    //         if(j==1)cout << *ptr_toBuffer << endl;
                             if(j==1 && *ptr_toBuffer==40+iarrow)
                              {arrows[k]=true;
    //   cout  << j << "  " << *ptr_toBuffer << "  "  << 40+iarrow << "  k=" << k << endl;
                              }
		           }  // end k loop
		          ptr_toBuffer++;  //name of child objects of name
                  } //end j loop
	//
	}  // end loop for hits
          SDL_GetMouseState(&mousex, &mousey);
	  if(mousedown && boxonly){
	//	  cout << firstmousedown << "  first mouse down?" << endl;

		  if(firstmousedown){
			  firstmousedown=false;
			  xstart=mousex;
			  ystart=mousey;
			  BottomStartDT=BottomDT;
			  LeftStartDT=LeftDT;
                          for(int i=0; i<4; i++){
			     xboxStart[i]=xbox[i];}
                           for(int i=0; i<6; i++){
			     yboxStart[i]=ybox[i];}
		  }
		  double ex, why;
		  ex=(double)(mousex-xstart)/( (double)WIDTH);
		  why=(double)(mousey-ystart)/( (double)HEIGHT);

		  LeftDT=LeftStartDT+ex*2.0;
		  BottomDT=BottomStartDT-2.0*why;

                 for(int i=0; i<4; i++){
	            xbox[i]=xboxStart[i]+ex*2.0;}
                 for(int i=0; i<6; i++){
	           ybox[i]=yboxStart[i]-2.0*why;}


	           } //end move whole kaboodle
 

//              k=0 is bottom left arrow, k=24 top right
                for(int k=0;k<24;k++){
                if(mousedown && firstmousedown && arrows[k]){

                   if(k==20)shift1+=10;  if(k==21)shift1-=10;  //all x numbers left-right
                   if(k==22)shift3+=10;  if(k==23)shift3-=10;   //upper x axis up/down

                   if(k==16)shift1+=10;  if(k==17)shift1-=10;   //all x numbers left/right
                   if(k==18)shift4+=10;  if(k==19)shift4-=10;   //lower x numbers up/down

                   if(k==12)shift5+=10;  if(k==13)shift5-=10;   //left y numbers left/right
                   if(k==14)shift2-=10;  if(k==15)shift2+=10;  //all y numbers up/down

                   if(k==8)shift6+=10;  if(k==9)shift6-=10;   //right y numbers left/right
                   if(k==10)shift2-=10;  if(k==11)shift2+=10;   // all y numbers up/down 

                   if(k==4)shift7+=10;  if(k==5)shift7-=10;      //xtext
                   if(k==6)shift8-=10;  if(k==7)shift8+=10;

               //  cout << "shifts " << k << "  " <<  shift9 << "  "  << shift10 << endl;

                   if(k==0)shift9-=10;  if(k==1)shift9+=10;    //y text
                   if(k==2)shift10-=10;  if(k==3)shift10+=10; 
                    }

                }
                firstmousedown=false;






}

