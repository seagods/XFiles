
void numbers_xy(){

        bool verbose=false;

	double xdiffexp,ydiffexp;

	if(verbose)cout << "xminexp=" << xminexp << endl;
	if(verbose)cout << "xexp=" << xexp << endl;

	xdiffexp=xminexp-xexp; ydiffexp=yminexp-yexp;

	if(verbose)cout <<"difference is " << xdiffexp << endl;

	if(xdiffexp>2.0)xaddsubtract=true; if(ydiffexp>2.0)yaddsubtract=true;

        xsubtract=0.0; ysubtract=0.0;

        if(verbose)cout << "xmin_scale=" << xmin_scale << endl;


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

        if(verbose)cout << "xsubtract=" << xsubtract << endl;

        xminshift=xmin-xsubtract;  yminshift=ymin-ysubtract;

        if(verbose)cout << "xmin-xsubtract=" << xmin-xsubtract << endl;
        if(verbose)cout << "xmax-xsubtract=" << xmax-xsubtract << endl;
        if(verbose)cout << "xrange_scale=" << xrange_scale << endl;

        double epsilon=.01;

        if(xrange_scale <=1.4+epsilon){
		xstep_scale=0.2;
		smallticksx=4;
	}
        if(xrange_scale >1.4+epsilon  &&  xrange_scale<=2.0+epsilon){
		xstep_scale=0.25;
		smallticksx=5;
	}
        if(xrange_scale >2.0+epsilon &&  xrange_scale<=4.0+epsilon){
		xstep_scale=0.5;
		smallticksx=5;
	}
        if(xrange_scale >4.0+epsilon &&  xrange_scale<=8.0+epsilon){
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
        if(yrange_scale >2.0+epsilon &&  yrange_scale<=4.0+epsilon){
		ystep_scale=0.5;
		smallticksy=5;
	}
        if(yrange_scale >4.0+epsilon &&  yrange_scale<=8.0+epsilon){
		ystep_scale=1.0;
		smallticksy=4;
	}
        if(yrange_scale >8.0+epsilon){
		ystep_scale=2.0; 
		smallticksy=4;
	}

        xstep=xstep_scale*xfact;    ystep=ystep_scale*yfact;
        xstep2=xstep/((double)smallticksx);   ystep2=ystep/((double)smallticksy);

        if(verbose)cout << "xstep_scale=" << xstep_scale << endl;
        if(verbose)cout << "xstep=" << xstep << endl;

        x_start=ceil(xminshift/xstep)*xstep;  y_start=ceil(yminshift/ystep)*ystep;
//        x_start2=ceil(xminshift/xstep2)*xstep2;  y_start2=ceil(yminshift/ystep2)*ystep2;
 
        if(verbose)cout << "x_start=" << x_start << endl;

        ixnumb=0;  iynumb=0; ixnumb2=0; iynumb2=0;
        xnumbers[0]=x_start;  ynumbers[0]=y_start;
        xnumbers2[0]=x_start-xstep;  ynumbers2[0]=y_start-ystep;

        double xstop, ystop;
        xstop=(xminshift+xrange*(1.0+epsilon));   ystop=(yminshift+yrange*(1.0+epsilon));
        x_start2=xnumbers2[0];  y_start2=ynumbers2[0];
 

        while(xnumbers[ixnumb]<=xstop ){
             ixnumb++;
             xnumbers[ixnumb]=x_start+ixnumb*xstep;
             if(verbose)cout   <<"ixnumb=" << ixnumb 
      <<  "  x number is now " << xnumbers[ixnumb] << endl;
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

        if(verbose)cout << "number of values is " << ixnumb << endl;

        for(int i=0; i<ixnumb;i++){
           ostringstream  xout;
        //   cout << xout << endl;  //checked, there is no memory leak in doing this
           if(fabs(xnumbers[i])>100.0 || fabs(xnumbers[i])<0.01 && xnumbers[i]!=0.0)
                 xout << setprecision(2) << scientific;
           xout << xnumbers[i];
           xstrings[i]=xout.str();
           if(verbose)cout << "i=" << i << "  xnumbers=" << xnumbers[i] << endl;
           if(verbose)cout << "x string=" << xstrings[i] << endl;
          }
             
        for(int i=0; i<iynumb;i++){
           ostringstream  yout;
           if(fabs(ynumbers[i])>100.0 || fabs(ynumbers[i])<0.01 && ynumbers[i]!=0.0)
                 yout << setprecision(2) << scientific;
           yout << ynumbers[i];
           ystrings[i]=yout.str();
          }


}
