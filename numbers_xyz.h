
void numbers_xyz(){

        bool verbose=false;

	double xdiffexp,ydiffexp,zdiffexp;


	xdiffexp=xminexp-xexp; ydiffexp=yminexp-yexp; zdiffexp=zminexp-zexp;

	if(xdiffexp>2.0)xaddsubtract=true; if(ydiffexp>2.0)yaddsubtract=true;
	if(zdiffexp>2.0)zaddsubtract=true; 

        xsubtract=0.0; ysubtract=0.0, zsubtract=0.0;

           double ordmag;
           //xmin is this many times

          if(xaddsubtract){
           ordmag=pow(10.0,xminexp-xexp-2);
           xsubtract=floor(xmin_scale*ordmag);
           xsubtract=xsubtract/ordmag;
           xsubtract=xsubtract*pow(10.0,xminexp);
           }

          if(yaddsubtract){
           ordmag=pow(10.0,yminexp-yexp-2);
           ysubtract=floor(ymin_scale*ordmag);
           ysubtract=ysubtract/ordmag;
           ysubtract=ysubtract*pow(10.0,yminexp);
           }

          if(zaddsubtract){
           ordmag=pow(10.0,zminexp-zexp-2);
           zsubtract=floor(zmin_scale*ordmag);
           zsubtract=zsubtract/ordmag;
           zsubtract=zsubtract*pow(10.0,zminexp);
           }

        xminshift=xmin-xsubtract;  yminshift=ymin-ysubtract, zminshift=zmin-zsubtract;

        double epsilon=.01;

        if(xrange_scale <=1.4+epsilon){
		xstep_scale=0.2;
		smallticksx=4;
	}
        if(xrange_scale >1.4+epsilon  &&  xrange_scale<=2.0+epsilon){
		xstep_scale=0.25;
		smallticksx=5;
	}
        if(xrange_scale >2.0+epsilon &&  xrange_scale<=5.0+epsilon){
		xstep_scale=0.5;
		smallticksx=5;
	}
        if(xrange_scale >5.0+epsilon &&  xrange_scale<=8.0+epsilon){
		xstep_scale=1.0;
		smallticksx=4;
	}
        if(xrange_scale >8.0+epsilon){
		xstep_scale=2.0; 
		smallticksx=4;
	}


        if(yrange_scale <=1.4+epsilon){
		ystep_scale=0.2;
		smallticksy=4;
	}
        if(yrange_scale >1.4+epsilon  &&  yrange_scale<=2.0+epsilon){
		ystep_scale=0.25;
		smallticksy=5;
	}
        if(yrange_scale >2.0+epsilon &&  yrange_scale<=5.0+epsilon){
		ystep_scale=0.5;
		smallticksy=5;
	}
        if(yrange_scale >5.0+epsilon &&  yrange_scale<=8.0+epsilon){
		ystep_scale=1.0;
		smallticksy=4;
	}
        if(yrange_scale >8.0+epsilon){
		ystep_scale=2.0; 
		smallticksy=4;
	}

        if(zrange_scale <=1.4+epsilon){
		zstep_scale=0.2;
		smallticksz=4;
	}
        if(zrange_scale >1.4+epsilon  &&  zrange_scale<=2.0+epsilon){
		zstep_scale=0.25;
		smallticksz=5;
	}
        if(zrange_scale >2.0+epsilon &&  zrange_scale<=5.0+epsilon){
		zstep_scale=0.5;
		smallticksz=5;
	}
        if(zrange_scale >5.0+epsilon &&  zrange_scale<=8.0+epsilon){
		zstep_scale=1.0;
		smallticksz=4;
	}
        if(zrange_scale >8.0+epsilon){
		zstep_scale=2.0; 
		smallticksz=4;
	}

        xstep=xstep_scale*xfact;ystep=ystep_scale*yfact;zstep=zstep_scale*zfact;
        xstep2=xstep/((double)smallticksx);   ystep2=ystep/((double)smallticksy);
        zstep2=zstep/((double)smallticksz);

        x_start=ceil(xminshift/xstep)*xstep;  y_start=ceil(yminshift/ystep)*ystep;
        z_start=ceil(zminshift/zstep)*zstep;  
 

        ixnumb=0;  iynumb=0; iznumb=0;  ixnumb2=0; iynumb2=0, iznumb2=0;
        xnumbers[0]=x_start;  ynumbers[0]=y_start; znumbers[0]=z_start;
        xnumbers2[0]=x_start-xstep;  ynumbers2[0]=y_start-ystep;
        znumbers2[0]=z_start-zstep;
        double xstop, ystop, zstop;
        xstop=(xminshift+xrange*(1.0+epsilon));   ystop=(yminshift+yrange*(1.0+epsilon));
        zstop=(zminshift+zrange*(1.0+epsilon));
        x_start2=xnumbers2[0];  y_start2=ynumbers2[0]; z_start2=znumbers2[0];
 

        while(xnumbers[ixnumb]<=xstop ){
             ixnumb++;
             xnumbers[ixnumb]=x_start+ixnumb*xstep;
        }
        while(xnumbers2[ixnumb2]<=xstop ){
             ixnumb2++;
             xnumbers2[ixnumb2]=x_start2+ixnumb2*xstep2;
        }
        while(ynumbers[iynumb]<=ystop ){
             iynumb++;
             ynumbers[iynumb]=y_start+iynumb*ystep;
        }
        while(ynumbers2[iynumb2]<=ystop ){
             iynumb2++;
             ynumbers2[iynumb2]=y_start2+iynumb2*ystep2;
        }
        while(znumbers[iznumb]<=zstop ){
             iznumb++;
             znumbers[iznumb]=z_start+iznumb*zstep;
        }
        while(znumbers2[iznumb2]<=zstop ){
             iznumb2++;
             znumbers2[iznumb2]=z_start2+iznumb2*zstep2;
        }

        if(fabs(xnumbers[0])>1000.0 || fabs(xnumbers[ixnumb-1]) >1000.0){
                 xtimesdiv=true;}
        if(fabs(xnumbers[0])<0.01 && fabs(xnumbers[ixnumb-1]) <0.01){
                 xtimesdiv=true;}
        for(int i=0; i<ixnumb;i++){
           ostringstream  xout;
         //  xout << setprecision(2) << fixed;
           if(xtimesdiv){
                xout << xnumbers[i]/xfact;}
           else{
                xout << xnumbers[i];}
           xstrings[i]=xout.str();
           if(verbose)cout << "i=" << i << "  xnumbers=" << xnumbers[i] << endl;
           if(verbose)cout << "x string=" << xstrings[i] << endl;
          }


        if(fabs(ynumbers[0])>1000.0 || fabs(ynumbers[iynumb-1]) >1000.0){
                 ytimesdiv=true;}
        if(fabs(ynumbers[0])<0.01 && fabs(ynumbers[iynumb-1]) <0.01){
                 ytimesdiv=true;}
        for(int i=0; i<iynumb;i++){
           ostringstream  yout;
         //  yout << setprecision(2) << fixed;
           if(ytimesdiv){
                yout << ynumbers[i]/yfact;}
           else{
                yout << ynumbers[i];}
           ystrings[i]=yout.str();
           if(verbose)cout << "i=" << i << "  ynumbers=" << ynumbers[i] << endl;
           if(verbose)cout << "y string=" << ystrings[i] << endl;
          }

        if(fabs(znumbers[0])>1000.0 || fabs(znumbers[iznumb-1]) >1000.0){
                 ztimesdiv=true;}
        if(fabs(znumbers[0])<0.01 && fabs(znumbers[iznumb-1]) <0.01){
                 ztimesdiv=true;}
        for(int i=0; i<iznumb;i++){
           ostringstream  zout;
         //  yout << setprecision(2) << fixed;
           if(ztimesdiv){
                zout << znumbers[i]/zfact;}
           else{
                zout << znumbers[i];}
           zstrings[i]=zout.str();
           if(verbose)cout << "i=" << i << "  znumbers=" << znumbers[i] << endl;
           if(verbose)cout << "z string=" << zstrings[i] << endl;
          }


/*
        for(int i=0; i<ixnumb;i++){
           ostringstream  xout;
        //   cout << xout << endl;  //checked, there is no memory leak in doing this
           if(fabs(xnumbers[i])>1000.0 || fabs(xnumbers[i])<0.01 && xnumbers[i]!=0.0)
                 xout << setprecision(2) << scientific;
           xout << xnumbers[i];
           xstrings[i]=xout.str();
          }
             
        for(int i=0; i<iynumb;i++){
           ostringstream  yout;
           if(fabs(ynumbers[i])>100.0 || fabs(ynumbers[i])<0.01 && ynumbers[i]!=0.0)
                 yout << setprecision(2) << scientific;
           yout << ynumbers[i];
           ystrings[i]=yout.str();
          }
             
        for(int i=0; i<iznumb;i++){
           ostringstream  zout;
           if(fabs(znumbers[i])>100.0 || fabs(znumbers[i])<0.01 && znumbers[i]!=0.0)
                 zout << setprecision(2) << scientific;
           zout << znumbers[i];
           zstrings[i]=zout.str();
          }
*/

}
