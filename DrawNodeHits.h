void DrawNodeHits(bool draw_the_box)
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
      gluPickMatrix( (double) mousex, viewport[3]-(double) mousey, 5.0, 5.0, viewport);
      (void)glRenderMode(GL_SELECT);
      glInitNames();  //Ignored unless in GL_SELECT 
    }

      if(draw_the_box)OrthoMode(-1, 1, 1, -1);  //calls glOrtho (see Init.h)

      double w1, h1;
      double Top, Right;   // For panel
  
      w1=340./800.*2.0;
      h1=417./600.*2.0;

      Right=Left+w1;
      Top=Bottom+h1;

      glDisable(GL_LIGHTING);  //so control panels wont see lighting

      glColor3ub(255,255,255);
      //Main Triangle Box
      if(!draw_the_box)glPushName(1);
      glBlendFunc(GL_ONE,GL_ZERO);
      glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
      glBindTexture(GL_TEXTURE_2D,gl_Texture[32]);
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left, Top); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left ,Bottom ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Right, Bottom); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Right, Top); // Top right
      glEnd();


      int lengthlist=NodeTris[ipicked]->GetLength();
      ostringstream oss[lengthlist+1];
      string Output[lengthlist+1];
      oss[0] << "Node=" << ipicked;
      Output[0]=oss[0].str();
      if(draw_the_box){
        glColor3ub(0,0,0);  //set colour  black 
        glRasterPos2f(Left+.25, Bottom+.82);
        font10->draw(Output[0].c_str());      
      glColor3ub(255,255,255);  //set back colour   
      }

    int nstream=1;
    int current_tri;
    int i1,i2,i3;
    bool found;
    ListNode* Head;
    ListNode* Tail;
    Head=NodeTris[ipicked]->GetHead();
    Tail=NodeTris[ipicked]->GetTail();
    while(Head->GetNextPtr() != Tail){
       found=false;
       Head=Head->GetNextPtr();
       current_tri=*Head->GetDatumPtr();
       i1=Triangles[current_tri].Get1();
       i2=Triangles[current_tri].Get2();
       i3=Triangles[current_tri].Get3();
       if(i1==ipicked){
         found=true;
         oss[nstream] << "is Node 1 of Triangle " << current_tri;
         Output[nstream]=oss[nstream].str();
       }
       if(i2==ipicked){
         found=true;
         oss[nstream] << "is Node 2 of Triangle " << current_tri;
         Output[nstream]=oss[nstream].str();
       }
       if(i3==ipicked){
         found=true;
         oss[nstream] << "is Node 3 of Triangle "  << current_tri;
         Output[nstream]=oss[nstream].str();
       }
       if(!found){
          cout << "failed in DrawNodeHits " << endl;  exit(1);}

       nstream++;
    }
    if(draw_the_box){
    for(int i=1; i<lengthlist+1; i++){
        glColor3ub(0,0,0);  //set colour  black 
        glRasterPos2f(Left+.15, Bottom+.82-i*.07);
        font10->draw(Output[i].c_str());      
    }
      glColor3ub(255,255,255);  //set back colour   
    }
    
      

/*

      if(draw_the_box){
      oss[0] << ipicked;
      oss[1] << Triangles[ipicked].Get1();
      oss[2] << Triangles[ipicked].Get2();
      oss[3] << Triangles[ipicked].Get3();

      if(!Triangles[ipicked].GetN()){
         cout << "Triangle " << ipicked <<  "  has no neighbours!" << endl; 
         exit(1); }


      if(Triangles[ipicked].GetN1()>=0){
      oss[4] << Triangles[ipicked].GetN1();}
      else{
      oss[4] << NULL;}

      if(Triangles[ipicked].GetN2()>=0){
      oss[5] << Triangles[ipicked].GetN2();}
      else{
      oss[5] << NULL;}

      if(Triangles[ipicked].GetN3()>=0){
      oss[6] << Triangles[ipicked].GetN3();}
      else{
      oss[6] << NULL;}
      } //endif draw the box


      if(draw_the_box){
 
      for(int is=0; is<7; is++){
        Output[is]=oss[is].str();
    //    cout << "is=" << is << "  " << Output[is].c_str() << endl;
       }}

//    Triangle
      glBindTexture(GL_TEXTURE_2D,gl_Texture[4]);
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left+.25, Bottom+.67); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left+.25, Bottom+.62 ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Left+.45, Bottom+0.62); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Left+.45, Bottom+.67); // Top right
      glEnd(); 

      if(draw_the_box){
        glColor3ub(0,0,0);  //set colour  black 
        glRasterPos2f(Left+.25+.03, Bottom+.62);
        font10->draw(Output[0].c_str());      
      glColor3ub(255,255,255);  //set back colour   
      }

//    Node1
      glBindTexture(GL_TEXTURE_2D,gl_Texture[4]);
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left+.25, Bottom+.57); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left+.25, Bottom+.52 ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Left+.45, Bottom+0.52); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Left+.45, Bottom+.57); // Top right
      glEnd(); 
      if(draw_the_box){
        glColor3ub(0,0,0);  //set colour  black 
        glRasterPos2f(Left+.25+.03, Bottom+.52);
        font10->draw(Output[1].c_str());   
      glColor3ub(255,255,255);  //set back colour      
      }
//    Node2
      glBindTexture(GL_TEXTURE_2D,gl_Texture[4]);
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left+.25, Bottom+.49); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left+.25, Bottom+.44 ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Left+.45, Bottom+0.44); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Left+.45, Bottom+.49); // Top right
      glEnd(); 
      if(draw_the_box){
        glColor3ub(0,0,0);  //set colour  black  
        glRasterPos2f(Left+.25+.03, Bottom+.44);
        font10->draw(Output[2].c_str());   
      glColor3ub(255,255,255);  //set back colour        
      }
//    Node 3
      glBindTexture(GL_TEXTURE_2D,gl_Texture[4]);
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left+.25, Bottom+.41); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left+.25, Bottom+.36 ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Left+.45, Bottom+0.36); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Left+.45, Bottom+.41); // Top right
      glEnd(); 
      if(draw_the_box){
        glColor3ub(0,0,0);  //set colour black 
        glRasterPos2f(Left+.25+.03, Bottom+.36);
        font10->draw(Output[3].c_str());   
      glColor3ub(255,255,255);  //set back colour       
      }


//    Neighbour 1
      glBindTexture(GL_TEXTURE_2D,gl_Texture[4]);
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left+.55, Bottom+.29); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left+.55, Bottom+.24 ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Left+.75, Bottom+0.24); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Left+.75, Bottom+.29); // Top right
      glEnd(); 
      if(draw_the_box){
        glColor3ub(0,0,0);  //set colour black 
        glRasterPos2f(Left+.55+.03, Bottom+.24);
        font10->draw(Output[4].c_str());   
      glColor3ub(255,255,255);  //set back colour       
      }


//    Neighbour 2
      glBindTexture(GL_TEXTURE_2D,gl_Texture[4]);
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left+.55, Bottom+.21); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left+.55, Bottom+.16 ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Left+.75, Bottom+0.16); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Left+.75, Bottom+.21); // Top right
      glEnd(); 
      if(draw_the_box){
        glColor3ub(0,0,0);  //set colour black 
        glRasterPos2f(Left+.55+.03, Bottom+.16);
        font10->draw(Output[5].c_str());   
      glColor3ub(255,255,255);  //set back colour        
      }

//    Neighbour 3
      glBindTexture(GL_TEXTURE_2D,gl_Texture[4]);
      glBegin(GL_QUADS);
	     if(draw_the_box)glTexCoord2f(0.0, 1.0); //top left U,V=0,0
	     glVertex2f(Left+.55, Bottom+.14); 
	     if(draw_the_box)glTexCoord2f(0.0, 0.0); // Bottom Left
	     glVertex2f(Left+.55, Bottom+.09 ); // Bottom Left
	     if(draw_the_box)glTexCoord2f(1.0, 0.0); // Bottom  right
	     glVertex2f(Left+.75, Bottom+0.09); // Bottom right
	     if(draw_the_box)glTexCoord2f(1.0, 1.0); // Top right
	     glVertex2f(Left+.75, Bottom+.14); // Top right
      glEnd(); 
      if(draw_the_box){
        glColor3ub(0,0,0);  //set colour black 
        glRasterPos2f(Left+.55+.03, Bottom+.09);
        font10->draw(Output[6].c_str());   
      glColor3ub(255,255,255);  //set back colour        
      }


/************************************************************************/

      if(!draw_the_box)glPopName();   // Box 1  popped

      glEnable(GL_LIGHTING);

       PerspectiveMode();

      if(!draw_the_box){
         glPopMatrix();
         glFlush();
         int hits=glRenderMode(GL_RENDER);
	// cout << " number of hits =" << hits << endl;
         ProcessNBoxHits(hits, NameBuffer );
       }
       
}

void ProcessNBoxHits(int hits, UINT  Buffer[]){
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

	  }


}

