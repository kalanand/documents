
void plotW()
{
  gROOT->LoadMacro("tdrstyle.C");
  setTDRStyle();

  gROOT->LoadMacro("plottingLEPStyle.C+");

  bool W_ok(true);
  bool Wp_ok(true);
  bool Wm_ok(true);
  bool WZ_ok(true);
  bool WpWm_ok(true);
  bool Z_ok(true);
  bool CMSTheory_ok(true);

  int ndigit(2);

  float size1 = 0.075;
  float size2 = 0.058;

  if(W_ok)
    {
      LEPStyle lep( "Results_W",
		    "#sigma( pp #rightarrow WX ) #times B( W #rightarrow l#nu )   [nb]",
		    0., 13., 506, "nb"
		    );
    
      lep.addEntry( "W #rightarrow e#nu", 
		    10.48, 0.03, 0.15, 0.09, 0.42,
		    kFullCircle,0.8,kBlack,ndigit ); 
      lep.addEntry( "W #rightarrow #mu#nu", 
		    10.18, 0.03, 0.12, 0.11, 0.41,
		    kFullCircle,0.8,kBlack,ndigit );
      lep.addEntry( "W #rightarrow l#nu #scale[0.7]{(combined)}", 
		    10.31, 0.02, 0.09, 0.10, 0.41,
		    kFullCircle,0.8,kBlack,ndigit );

      lep._y0   = 4.2;
      lep._eps2 = 0.27;
      lep._upDy = 2.;
      lep._dy = 0.2;


      lep._size1 = size1;
      lep._size2 = size2;
      lep.e_ = 0.07;
    
      lep.setTheoryBandAndLegend( 10.44, 0.2714, 0.2714,  // x, d-, d+
				  "#splitline{NNLO, FEWZ+MSTW08 prediction}{#scale[0.9]{ [with MSTW08NNLO 68% CL uncertainty]}}", 
				  4,0 ); 
      lep._intLumi = 0;
      lep._txtRight = "36 pb^{-1} at   #sqrt{s} = 7 TeV";
      lep.draw();
      lep.print();
    }
  if(Wp_ok)
    {
      LEPStyle lep( "Results_W_plus",
		    "#sigma( pp #rightarrow W^{ + }X ) #times B( W^{ + }#rightarrow l^{ + }#nu )   [nb]",
		    -1.5, 7.5, 506, "nb"		  );

      lep.addEntry( "W^{ + } #rightarrow e^{ + }#nu", 
		    6.15, 0.02, 0.10, 0.07, 0.25,
		    kFullCircle,0.8,kBlack,ndigit ); 
      lep.addEntry( "W^{ + } #rightarrow #mu^{ + }#nu", 
		    5.98, 0.02, 0.07, 0.08, 0.24, 
		    kFullCircle,0.8,kBlack,ndigit ); 
      lep.addEntry( "W^{ + } #rightarrow l^{ + }#nu   #scale[0.7]{(combined)}", 
		    6.04, 0.02, 0.06, 0.08, 0.24, 
		    kFullCircle,0.8,kBlack,ndigit ); 

      lep._y0   = 4.2;
      lep._eps2 = 0.27;
      lep._upDy = 2.;
      lep._dy = 0.2;

      lep._size1 = size1;
      lep._size2 = size2;
      lep.e_ = 0.07;

      lep.setTheoryBandAndLegend( 6.15, 0.1661, 0.1661,  // x, d-, d+
				  "#splitline{NNLO, FEWZ+MSTW08 prediction}{#scale[0.9]{ [with MSTW08NNLO 68% CL uncertainty]}}", 
				  5,0 ); 
      lep._intLumi = 0;
      lep._txtRight = "36 pb^{-1} at   #sqrt{s} = 7 TeV";

      lep.draw();
      lep.print();
    }
  if(Wm_ok)
    {
      LEPStyle lep( "Results_W_minus",
		    "#sigma( pp #rightarrow W^{ - }X ) #times B( W^{-}#rightarrow l^{ - }#bar{#nu} )   [nb]",
		    -1.5, 7.5, 506, "nb"
		    );

      lep.addEntry( "W^{ - } #rightarrow e^{ - }#bar{#nu}", 
		    4.34, 0.02, 0.07, 0.06, 0.17, 
		    kFullCircle,0.8,kBlack,ndigit ); 
      lep.addEntry( "W^{ - } #rightarrow #mu^{ - }#bar{#nu}", 
		    4.20, 0.02, 0.05, 0.07, 0.17,
		    kFullCircle,0.8,kBlack,ndigit ); 

      lep.addEntry( "W^{ - } #rightarrow l^{ - }#bar{#nu}   #scale[0.7]{(combined)}", 
		    4.26, 0.01, 0.04, 0.07, 0.17,
		    kFullCircle,0.8,kBlack,ndigit ); 

      lep._y0   = 4.2;
      lep._eps2 = 0.27;
      lep._upDy = 2.;
      lep._dy = 0.2;

      lep._size1 = size1;
      lep._size2 = size2;
      lep.e_ = 0.07;

      lep.setTheoryBandAndLegend( 4.29, 0.1073, 0.1073,  // x, d-, d+
				  "#splitline{NNLO, FEWZ+MSTW08 prediction}{#scale[0.9]{ [with MSTW08NNLO 68% CL uncertainty]}}", 
				  5,0 ); 
      lep._intLumi = 0;
      lep._txtRight = "36 pb^{-1} at   #sqrt{s} = 7 TeV";
      lep.draw();
      lep.print();
    }
  if(Z_ok)
    {
      int ndigit(3);

      LEPStyle lep( "Results_Z",
		    "#sigma( pp #rightarrow ZX ) #times B( Z #rightarrow ll )   [nb]",
		    0, 1.3, 506, "nb"		  );


      lep.addEntry( "Z #rightarrow ee", 
		    0.992, 0.011, 0.018, 0.016, 0.040, 
		    kFullCircle,0.8,kBlack,ndigit ); 
      lep.addEntry( "Z #rightarrow #mu#mu", 
		    0.968, 0.008, 0.007, 0.018, 0.039,
		    kFullCircle,0.8,kBlack,ndigit ); 
      lep.addEntry( "Z #rightarrow ll   #scale[0.7]{(combined)}", 
		    0.974, 0.007, 0.007, 0.018, 0.039,
		    kFullCircle,0.8,kBlack,ndigit ); 

      lep._y0   = 4.2;
      lep._eps2 = 0.27;
      lep._upDy = 2.;
      lep._dy = 0.2;

      lep._size1 = size1;
      lep._size2 = size2;
      lep.e_ = 0.07;

      lep.setTheoryBandAndLegend( 0.97, 0.0257, 0.0257,  // x, d-, d+
				  "#splitline{NNLO, FEWZ+MSTW08 prediction, 60-120 GeV}{#scale[0.9]{              [with MSTW08NNLO 68% CL uncertainty]}}", 
				  5,0 ); 
      lep._intLumi = 0;
      lep._txtRight = "36 pb^{-1} at   #sqrt{s} = 7 TeV";

      lep.draw();
      lep.print();
    }
  if(WZ_ok)
    {
      int ndigit(2);
      LEPStyle lep( "Results_R_WZ",
		    "R_{W/Z} = [ #sigma #times B ](W) / [ #sigma #times B ](Z)",
		    0, 14, 506
		    );

      lep.addEntry( "W #rightarrow e#nu,  Z #rightarrow ee", 
		    10.56, 0.12, 0.12, 0.15, 0.0,
		    kFullCircle,0.8,kBlack,ndigit ); 
      lep.addEntry( "W #rightarrow #mu#nu,  Z #rightarrow #mu#mu", 
		    10.52, 0.09, 0.10, 0.17, 0.0, 
		    kFullCircle,0.8,kBlack,ndigit ); 
      lep.addEntry( "W #rightarrow l#nu,  Z #rightarrow ll   #scale[0.7]{(combined)}", 
		    10.54, 0.07, 0.08, 0.16, 0.0,
		    kFullCircle,0.8,kBlack,ndigit ); 

 
      lep._y0   = 4.2;
      lep._eps2 = 0.27;
      lep._upDy = 2.;
      lep._dy = 0.2;

      lep._size1 = size1;
      lep._size2 = size2;
      lep.e_ = 0.07;

      lep.setTheoryBandAndLegend( 10.74, 0.043, 0.043,  // x, d-, d+
				  "#splitline{NNLO, FEWZ+MSTW08 prediction}{#scale[0.9]{ [with MSTW08NNLO 68% CL uncertainty]}}", 
				  0,2 );  // number of blanks
      lep._intLumi = 0;
      lep._txtRight = "36 pb^{-1} at   #sqrt{s} = 7 TeV";
      lep.draw();
      lep.print();
    }
  if(WpWm_ok)
    {
      int ndigit(3);

      LEPStyle lep( "Results_R_WpWm",
		    "R_{+/-} =  [ #sigma #times B ](W^{ + }) / [ #sigma #times B ](W^{ - })",
		    0, 1.8, 506
		    );


      lep.addEntry( "W #rightarrow e#nu", 
		    1.418, 0.008, 0.022, 0.029, 0.0, 
		    kFullCircle,0.8,kBlack,ndigit ); 
      lep.addEntry( "W #rightarrow #mu#nu", 
		    1.423, 0.008, 0.019, 0.030, 0.0,
		    kFullCircle,0.8,kBlack,ndigit ); 
      lep.addEntry( "W #rightarrow l#nu   #scale[0.7]{(combined)}", 
		    1.421, 0.006, 0.014, 0.029, 0.0, 
		    kFullCircle,0.8,kBlack,ndigit ); 

      lep._y0   = 4.2;
      lep._eps2 = 0.27;
      lep._upDy = 2.;
      lep._dy = 0.25;

      lep._size1 = size1;
      lep._size2 = size2;
      lep.e_ = 0.07;

      lep.setTheoryBandAndLegend( 1.43, 0.0136, 0.0136,  // x, d-, d+
				  "#splitline{NNLO, FEWZ+MSTW08 prediction}{#scale[0.9]{ [with MSTW08NNLO 68% CL uncertainty]}}", 
				  0,0 ); 
      lep._intLumi = 0;
      lep._txtRight = "36 pb^{-1} at   #sqrt{s} = 7 TeV";
      lep.draw();
      lep.print();
    }
  if(CMSTheory_ok)
    {
      int ndigit_(3);
    
      LEPStyle lep( "Results_ratioTheory",
		    "Ratio (CMS/Theory)",
		    0.6, 1.55, 506
		    );
      lep.addEntry( "#sigma #times B ( W )", 
		    0.987, 0.009, 0.028, 0.0, 
		    kFullSquare,1.5,kRed , ndigit_ );
      lep.addEntry( "#sigma #times B ( W^{+} )", 
		    0.982, 0.009, 0.030, 0.0, 
		    kFullTriangleUp,1.5,kRed , ndigit_ );
      lep.addEntry( "#sigma #times B ( W^{-} )", 
		    0.993, 0.010, 0.029, 0.0, 
		    kFullTriangleDown,1.5,kRed , ndigit_ );
      lep.addEntry( "#sigma #times B ( Z )", 
		    1.002, 0.010, 0.032, 0.0, 
		    kFullCircle,1.5,kRed , ndigit_ );
      lep.addEntry( "R_{W/Z}", 
		    0.981, 0.010, 0.015, 0.0, 
		    kFullCircle,1.5,kBlue , ndigit_ );
      lep.addEntry( "R_{+/-}", 
		    0.990, 0.011, 0.023, 0.0, 
		    kFullSquare,1.5,kBlue , ndigit_ );

      lep._firstError = "exp.";
      lep._secondError = "th.";
      lep._specifyPlacement = true;
      lep._align1 = 22;
      lep._align2 = 12;
      lep._xx1 = 0.75;
      lep._xx2 = 1.15;
      lep._size1 = 0.06;
      lep._size2 = 0.06;
      lep._centerTitle = true;
      lep._intLumi = 0;
      lep._txtRight = "36 pb^{-1} at   #sqrt{s} = 7 TeV";
      lep._extraBand = true;
      lep._xmin2 = 1 - 0.04;
      lep._xmax2 = 1 + 0.04;
      lep._ymin2 = 2.5;
      lep._ymax2 = 6.5;
      lep._bandFillStyle = 3352;
      lep._bandFillColor = kOrange;

      lep._h = 70;
      lep._y0   = 4.2;
      lep._eps2 = 0.07;
      lep._upDy = 1;
      lep._dy = 0.2;


      lep.setTheoryBandAndLegend( 1.0, 0., 0.);  // x, d-, d+

      lep.draw();
      lep.addText("lumi. uncertainty:", 0.89,6.6,11,0.03, 0, kBlue );
      lep.addText("#pm 4%",     1.11,6.6,31,0.03, 0, kBlue );
      lep.print();
    }
}
