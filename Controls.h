void HandleKeyPress(SDL_keysym *whatkey)
{ 
             int igetscreen;

             char filestring[]="screenshot.bmp";



             switch(whatkey->sym)
             {
                 case SDLK_ESCAPE:
                   SDL_Quit();
                   exit(0);
                   break;
                 case  SDLK_UP:
                   upPressed=true;
                   if( whatkey->mod & KMOD_CTRL)
                   {
                   upPressed =false;
                   ctrl_upPressed=true;
                   }
                   if( whatkey->mod & KMOD_SHIFT){
                   upPressed =false;
                   shift_upPressed=true;
                   }
                   break;
		 case  SDLK_DOWN:
                   downPressed=true;
                   if( whatkey->mod & KMOD_CTRL)
                   {
                   downPressed =false;
                   ctrl_downPressed=true;
                   }
                   if( whatkey->mod & KMOD_SHIFT){
                   downPressed =false;
                   shift_downPressed=true;
                   }
                   break;
                 case SDLK_LEFT:
                   leftPressed=true;
                   if( whatkey->mod & KMOD_CTRL)
                   {
                   leftPressed =false;
                   ctrl_leftPressed=true;
                   }
                   if( whatkey->mod & KMOD_SHIFT){
                   leftPressed =false;
                   shift_leftPressed=true;
                   }
                   break;
                 case SDLK_RIGHT:
                   rightPressed=true;
                   if( whatkey->mod & KMOD_CTRL)
                   {
                   rightPressed =false;
                   ctrl_rightPressed=true;
                   }
                   if( whatkey->mod & KMOD_SHIFT){
                   rightPressed =false;
                   shift_rightPressed=true;
                   }
                 default:
                   break;
		 case SDLK_F1:
		   if(helpscreen==false){
			   helpscreen=true;}
		   else {
			   helpscreen=false;}
		   break;
                 case SDLK_F2:
                   if(MouseOn==true)
                     {
                      MouseOn=false;
		      SDL_ShowCursor(1);
                     }
                     else
                    {
                      MouseOn=true;
		      SDL_ShowCursor(0);
                    }
                    break;
		 case SDLK_F3:
		   if(LIGHTS==false)
		   {
			   LIGHTS=true;
		   }
		   else {
			   LIGHTS=false;
	            }
		    break;
                   case SDLK_F4:
		   if(legendplot==false)
		   {
                           lightpos=false; lightcol=false, matcol=false; stylechange=false;
                           logicbox=false; movetext=false; flipperbox=false;
			   legendplot=true;
                           MouseOn=false;
		           SDL_ShowCursor(1);
		   }
		   else {
			   legendplot=false;
                           MouseOn=true;
                           lightpos=tlpos; lightcol=tlcol; matcol=tmatcol; stylechange=tstyle;
                           logicbox=tlogbox; movetext=tmove; flipperbox=tflip;
		           if(hidemousecursor)SDL_ShowCursor(0);
	            }
		    break;
		   case SDLK_F5:
		   if(stylechange==false)
		   {
                           lightpos=false; lightcol=false, matcol=false; legendplot=false;
                           logicbox=false; movetext=false; flipperbox=false;
			   stylechange=true;
                           MouseOn=false;
		           SDL_ShowCursor(1);
 
		   }
		   else {
			   stylechange=false;
                           MouseOn=true;
                           lightpos=tlpos; lightcol=tlcol; matcol=tmatcol; legendplot=tleg;
                           logicbox=tlogbox; movetext=tmove; flipperbox=tflip;
		           if(hidemousecursor)SDL_ShowCursor(0);
	            }
		    break;
		 case SDLK_F6:
		   if(lightpos==false)
		   {
			   lightpos=true;
                           MouseOn=false;
                           stylechange=false; lightcol=false; matcol=false; legendplot=false;
                           logicbox=false; movetext=false; flipperbox=false;
		           SDL_ShowCursor(1);
		   }
		   else {
			   lightpos=false;
                           MouseOn=true;
                           stylechange=tstyle; lightcol=tlcol; matcol=tmatcol; legendplot=tleg;
                           logicbox=tlogbox; movetext=tmove; flipperbox=tflip;
		           if(hidemousecursor)SDL_ShowCursor(0);
	            }
		    break;
		 case SDLK_F7:
		   if(lightcol==false)
		   {
			   lightcol=true;
                           MouseOn=false;
                           stylechange=false; lightpos=false, matcol=false; legendplot=false;
                           logicbox=false; movetext=false; flipperbox=false;
		           SDL_ShowCursor(1);
		   }
		   else {
			   lightcol=false;
                           MouseOn=true;
                           stylechange=tstyle; lightpos=tlpos; matcol=tmatcol; legendplot=tleg;
                           logicbox=tlogbox; movetext=tmove; flipperbox=tflip;
		           if(hidemousecursor)SDL_ShowCursor(0);
	            }
		    break;
		 case SDLK_F8:
		   if(matcol==false)
		   {
			   matcol=true;
                           MouseOn=false;
                           stylechange=false; lightpos=false, lightcol=false; legendplot=false;
                           logicbox=false; movetext=false; flipperbox=false;
		           SDL_ShowCursor(1);
		   }
		   else {
			   matcol=false;
                           MouseOn=true;
                           stylechange=tstyle; lightpos=tlpos; lightcol=tlcol; legendplot=tleg;
                           logicbox=tlogbox; movetext=tmove; flipperbox=tflip;
		           if(hidemousecursor)SDL_ShowCursor(0);
	            }
		    break;
		 case SDLK_F9:
		   if(logicbox==false)
		   {
			   logicbox=true;
                           MouseOn=false;
                           stylechange=false; lightpos=false, lightcol=false; legendplot=false;
                           matcol=false; movetext=false; flipperbox=false;
		           SDL_ShowCursor(1);
		   }
		   else {
			   logicbox=false;
                           MouseOn=true;
                           stylechange=tstyle; lightpos=tlpos; lightcol=tlcol; legendplot=tleg;
                           tmatcol=matcol; movetext=tmove; flipperbox=tflip;
		           if(hidemousecursor)SDL_ShowCursor(0);
	            }
		    break;
		   case SDLK_F10:
		   if(movetext==false)
		   {
			   movetext=true;
                           MouseOn=false;
                           stylechange=false; lightpos=false, lightcol=false; legendplot=false;
                           logicbox=false; logicbox=false; flipperbox=false;
		           SDL_ShowCursor(1);
		   }
		   else {
			   movetext=false;
                           MouseOn=true;
                           stylechange=tstyle; lightpos=tlpos; lightcol=tlcol; legendplot=tleg;
                           tmatcol=matcol; logicbox=tlogbox; flipperbox=tflip;
		           if(hidemousecursor)SDL_ShowCursor(0);
	            }
		    break;
                 case SDLK_F11:
                   igetscreen=Screenshot(MainWindow, filestring);
		   break;
                 case SDLK_F12:
                   post_Pressed=true;
                   break; 
		 case SDLK_a:
		   a_Pressed=true;
		   break;
		 case SDLK_b:
		   b_Pressed=true;
		   break;
		 case SDLK_c:
                   if(c_Pressed){
                   c_Pressed=false;}
                   else{
		   c_Pressed=true;}
		   break;
		 case SDLK_f:
                   if( whatkey->mod & KMOD_SHIFT){
                   ToggleFullScreen();
                   }
                   else{
		   if(flipperbox==false)
		   {
			   flipperbox=true;
                           MouseOn=false;
		           SDL_ShowCursor(1);
                           legendplot=false;
		   }
		   else {
			   flipperbox=false;
                           legendplot=true;
                           MouseOn=true;
                           lightpos=tlpos; lightcol=tlcol; matcol=tmatcol; stylechange=tstyle;
                           logicbox=tlogbox; movetext=tmove; flipperbox=tflip;
		           if(hidemousecursor)SDL_ShowCursor(0);
	            }}
		    break;
 		 case SDLK_g:
                   if(g_Pressed){
                   g_Pressed=false;}
                   else{
		   g_Pressed=true;}
		   break;
 		 case SDLK_l:
		   l_Pressed=true;
		   break;
		 case SDLK_t:
		   if(PickTri){   //toggle picking triangles/nodes
			   PickTri=false;}
		   else{
			   PickTri=true;}
                   if(t_Pressed){
                   t_Pressed=false;}
                   else{
		   t_Pressed=true;}
		   break;

		 case SDLK_z:
		   z_Pressed=true;
		   break;
                 case SDLK_1:
                   testplot++;
                   break;
                 case SDLK_2:
                   testplot--;
                   break;


             }
}

void HandleKeyRelease(SDL_keysym *whatkey)
{ 
             switch(whatkey->sym)
             {
                 case  SDLK_UP:
                   upPressed=false;
                   shift_upPressed=false;
                   ctrl_upPressed=false;
                   break;
		 case  SDLK_DOWN:
                   downPressed=false;
                   shift_downPressed=false;
                   ctrl_downPressed=false;
                   break;
                 case SDLK_LEFT:
                   leftPressed=false;
                   shift_leftPressed=false;
                   ctrl_leftPressed=false;
                   break;
                 case SDLK_RIGHT:
                   rightPressed=false;
                   shift_rightPressed=false;
                   ctrl_rightPressed=false;
                   break;
                 default:
                   break;
		 case SDLK_a:
		   a_Pressed=false;
		   break;
		 case SDLK_b:
		   b_Pressed=false;
		   break;
		 case SDLK_z:
		   z_Pressed=false;
		   break;
                 case SDLK_F12:
                   post_Pressed=false;
                   break; 
             }
}

void CheckMove(CCam & Camera1)
{
    //assumes no-one does ctrl and shift together!
             
    if(leftPressed){
	    if(tethered){
	    if(exwhyzed)Camera1.CamRotatePos1(angspeed); //cam spins left 
	    if(boom)Camera1.CamRotateBoomPos1(angspeed); //cam spins left 
	    }

    if(staked)Camera1.CamRotateView1(-angspeed);

    if(freedom){
	    if(wander){
	    Camera1.CamRotateView1(-angspeed);}

            if(flight){
		    if(aeroplane){
			    Camera1.CamPlaneRoll(-angspeed);
		    }
                    else
		    {
			    Camera1.CamRotateView1(-angspeed);
		    }
	    }
    }
    }//endif leftpressed

    if(rightPressed){
	    if(tethered){
	    if(exwhyzed)Camera1.CamRotatePos1(-angspeed); 
	    if(boom)    Camera1.CamRotateBoomPos1(-angspeed); 
	    }

    if(staked)Camera1.CamRotateView1(angspeed);

    if(freedom){
	    if(wander)
	    Camera1.CamRotateView1(angspeed);

            if(flight){
		    if(aeroplane){
			    Camera1.CamPlaneRoll(angspeed);}
                    else{
			    Camera1.CamRotateView1(angspeed);
		    }
	    }
    }
    } //endif rightpressed

    if(upPressed){
	    if(tethered){
	       if(exwhyzed)Camera1.CamRotatePos2(angspeed); 
	       if(boom)    Camera1.CamRotateBoomPos2(angspeed); 
	    }

            if(staked)  Camera1.CamRotateView2(-angspeed);


            if(freedom){
	    if(wander){
	        Camera1.CamMove(speed);  //always xyz
		    }
	    else  //assumes flight if not wander
		    {
			if(aeroplane){
			Camera1.CamPlanePitch(angspeed);}
			else{
                        Camera1.CamRotateView2(angspeed);}
		    }
             }
    }
    if(downPressed){

	    if(tethered){
	       if(exwhyzed)Camera1.CamRotatePos2(-angspeed); 
	       if(boom)    Camera1.CamRotateBoomPos2(-angspeed);
	    }

            if(staked)  Camera1.CamRotateView2(angspeed);

            if(freedom){
	    if(wander){
	        Camera1.CamMove(-speed);
		    }
	    else{   //assumes flight if not wander
			if(aeroplane){
			Camera1.CamPlanePitch(-angspeed);}
			else{
                        Camera1.CamRotateView2(-angspeed);}
	    }
            }
    }

    if(staked){
       if(shift_upPressed)Camera1.CamUpDown(speed);
       if(shift_downPressed)Camera1.CamUpDown(-speed);
    }
    else
    {
      if(tethered){
        if(shift_leftPressed)Camera1.CamRotateView1(-angspeed); 
        if(shift_rightPressed)Camera1.CamRotateView1(angspeed); 
        if(shift_upPressed)Camera1.CamRotateView2(angspeed);
        if(shift_downPressed)Camera1.CamRotateView2(-angspeed);
    }
      else // assumes freedom!
      {
        if(shift_leftPressed)Camera1.CamRotatePos1(-angspeed); 
        if(shift_rightPressed)Camera1.CamRotatePos1(angspeed); 
	if(wander){// up arrow look 
        if(shift_upPressed)Camera1.CamRotateView2(-angspeed); 
        if(shift_downPressed)Camera1.CamRotateView2(angspeed); }
	if(flight){// down arrow, joystick back, plane goes up 
        if(shift_upPressed)Camera1.CamRotateView2(angspeed); 
        if(shift_downPressed)Camera1.CamRotateView2(-angspeed); }
    }
    }

    if(ctrl_leftPressed)
	    if(boom){
		    Camera1.CamBoomSpin(angspeed);}
	    else{
		    Camera1.CamStrafe(speed);}

    if(ctrl_rightPressed)
	    if(boom){
		    Camera1.CamBoomSpin(-angspeed);}
            else{
		    Camera1.CamStrafe(-speed);}

    if(tethered){
       if(ctrl_upPressed)Camera1.CamZoom(speed);
       if(ctrl_downPressed)Camera1.CamZoom(-speed);
    }
    else{
       if(ctrl_upPressed)Camera1.CamUpDown(speed);
       if(ctrl_downPressed)Camera1.CamUpDown(-speed);
    }



    if(post_Pressed){

    FILE *fp=fopen("MyFileName.ps","wb");
    GLint buffsize=0;
    GLint state=GL2PS_OVERFLOW;
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);

    while(state==GL2PS_OVERFLOW){
       buffsize+=1024*1024;
//     could use GL2PS_USE_CURRENT_VIEWPORT,
       int ips=gl2psBeginPage("MyTitle","MyProducer",viewport,
               GL2PS_PS,GL2PS_BSP_SORT,GL2PS_SILENT | 
	       GL2PS_SIMPLE_LINE_OFFSET | GL2PS_BEST_ROOT,GL_RGBA,0,NULL,
               0,0,0,buffsize,fp,"MyFileName.ps");
       RenderScene(Camera1);
       state=gl2psEndPage();

       }  //end while loop
      fclose(fp);
    } // end post_Pressed


    if(flight){
	    //keep flying
	    Camera1.CamMove(speed);
    }




}

