{
  //===========================================================================
  // plotting macro:
  //
  // W and Z cross section measurements as a function of collider energy.
  //
  //      simply enter:    root.exe WZsigmas.C
  //      Will create two files WZsigmas.pdf and WZsigmas.png
  //
  // run-time options:
  //   makePDFPNG : whether to actually create pdf & png files (slow)
  //   plotATLAS : whether to include the ATLAS points
  //
  // M. Schmitt, Northwestern, 6-July-2010
  //  4-Oct-2010: update with 2.88 pb-1 numbers
  // 24-Nov-2010: fix UA1,UA2, convert to nb.  
  //===========================================================================
  c1 = new TCanvas("c1","cross sections");

  //
  // set options
  //
  Bool_t plotATLAS = false;
  Bool_t makePDFPNG = true;

  // declarations
  Int_t n = 1;
  Float_t rts[n];
  Float_t ex[n];
  Float_t csW[n];
  Float_t errW[n];
  Float_t csWP[n];
  Float_t errWP[n];
  Float_t csWN[n];
  Float_t errWN[n];
  Float_t csZ[n];
  Float_t errZ[n];
  Float_t RWZ[n];
  Float_t errR[n];
  double stat = 0.;
  double syst = 0.;
  double lum  = 0.;
  double theo = 0.;
  double lum_unc = 0.04;
  //
  // CMS
  //
  rts[0] = 7.;// + 0.2;
  if (plotATLAS) {rts[0] += 0.2;}  // offset needed for seeing points
  //
  ex[0] = 0.001;
  csW[0] = 10307.;
  stat   =    20.;
  syst   =    93.;
  lum    = lum_unc * csW[0];
  errW[0] = sqrt( stat*stat + syst*syst + theo*theo + lum*lum );
  //
  csZ[0] = 975.0;
  stat =     6.;
  syst =     7.;
  lum  = lum_unc * csZ[0];
  errZ[0] = sqrt( stat*stat + syst*syst + theo*theo + lum*lum );
  //
  RWZ[0] = 10.54;
  stat =    0.07;
  syst =    0.08;
  errR[0] = sqrt( stat*stat + syst*syst + theo*theo);
  //
  csWP[0] = 6040.;
  stat =      15.;
  syst =      56.;
  lum  = lum_unc * csWP[0];
  errWP[0] = sqrt( stat*stat + syst*syst + theo*theo + lum*lum );
  //
  csWN[0] = 4261.;
  stat =      13.;
  syst =      42.;
  lum  = lum_unc * csWN[0];
  errWN[0] = sqrt( stat*stat + syst*syst + theo*theo + lum*lum );

  // convert to nb
  csZ[0]   /= 1000.;
  csW[0]   /= 1000.;
  csWP[0]  /= 1000.;
  csWN[0]  /= 1000.;
  errZ[0]  /= 1000.;
  errW[0]  /= 1000.;
  errWP[0] /= 1000.;
  errWN[0] /= 1000.;

  grWCMS = new TGraphErrors(n,rts,csW,ex,errW);
  grWCMS->SetTitle("CMS W");
  grWCMS->SetMarkerColor(2);
  grWCMS->SetLineWidth(2);
  grWCMS->SetLineColor(2);
  grWCMS->SetMarkerStyle(20);
  grWCMS->SetMarkerSize(0.9);

   
  grZCMS = new TGraphErrors(n,rts,csZ,ex,errZ);
  grZCMS->SetTitle("CMS Z");
  grZCMS->SetMarkerColor(2);
  grZCMS->SetLineWidth(2);
  grZCMS->SetLineColor(2);
  grZCMS->SetMarkerStyle(24);
  grZCMS->SetMarkerSize(0.9);

  grWPCMS = new TGraphErrors(n,rts,csWP,ex,errWP);
  grWPCMS->SetTitle("CMS WP");
  grWPCMS->SetMarkerColor(2);
  grWPCMS->SetLineWidth(2);
  grWPCMS->SetLineColor(2);
  grWPCMS->SetMarkerStyle(20);
  grWPCMS->SetMarkerSize(0.9);
   
  grWNCMS = new TGraphErrors(n,rts,csWN,ex,errWN);
  grWNCMS->SetTitle("CMS WN");
  grWNCMS->SetMarkerColor(2);
  grWNCMS->SetLineWidth(2);
  grWNCMS->SetLineColor(2);
  grWNCMS->SetMarkerStyle(20);
  grWNCMS->SetMarkerSize(0.9);
   
  //
  // ATLAS   
  // http://arXiv.org/abs/1010.2130
  //
  rts[0] = 7.;
  if (plotATLAS) {rts[0] -= 0.2;} // offset needed to see points
  //
  ex[0] = 0.001;
  csW[0] =  9960.;
  stat   =   230.;
  syst   =   500.;
  lum    =  1100.;
  errW[0] = sqrt( stat*stat + syst*syst + theo*theo + lum*lum );
  //
  csZ[0] = 820.0;
  stat =    60.;
  syst =    50.;
  lum  =    90.;
  errZ[0] = sqrt( stat*stat + syst*syst + theo*theo + lum*lum );
  //
  RWZ[0] = 10.241;
  stat = 0.247;
  syst = 0.384;
  errR[0] = sqrt( stat*stat + syst*syst + theo*theo);
  //
  csWP[0] = 5930.;
  stat =     170.;
  syst =     300.;
  lum  =     650.;
  errWP[0] = sqrt( stat*stat + syst*syst + theo*theo + lum*lum );
  //
  csWN[0] = 4000.;
  stat =     150.;
  syst =     200.;
  lum  =     440.;
  errWN[0] = sqrt( stat*stat + syst*syst + theo*theo + lum*lum );

  // convert to nb
  csZ[0]   /= 1000.;
  csW[0]   /= 1000.;
  csWP[0]  /= 1000.;
  csWN[0]  /= 1000.;
  errZ[0]  /= 1000.;
  errW[0]  /= 1000.;
  errWP[0] /= 1000.;
  errWN[0] /= 1000.;

  grWATLAS = new TGraphErrors(n,rts,csW,ex,errW);
  grWATLAS->SetTitle("ATLAS W");
  grWATLAS->SetMarkerColor(8);
  grWATLAS->SetLineWidth(2);
  grWATLAS->SetLineColor(8);
  grWATLAS->SetMarkerStyle(20);
  grWATLAS->SetMarkerSize(0.9);

   
  grZATLAS = new TGraphErrors(n,rts,csZ,ex,errZ);
  grZATLAS->SetTitle("ATLAS Z");
  grZATLAS->SetMarkerColor(8);
  grZATLAS->SetLineWidth(2);
  grZATLAS->SetLineColor(8);
  grZATLAS->SetMarkerStyle(24);
  grZATLAS->SetMarkerSize(0.9);

  grWPATLAS = new TGraphErrors(n,rts,csWP,ex,errWP);
  grWPATLAS->SetTitle("ATLAS WP");
  grWPATLAS->SetMarkerColor(8);
  grWPATLAS->SetLineWidth(2);
  grWPATLAS->SetLineColor(8);
  grWPATLAS->SetMarkerStyle(20);
  grWPATLAS->SetMarkerSize(0.9);
   
  grWNATLAS = new TGraphErrors(n,rts,csWN,ex,errWN);
  grWNATLAS->SetTitle("ATLAS WN");
  grWNATLAS->SetMarkerColor(8);
  grWNATLAS->SetLineWidth(2);
  grWNATLAS->SetLineColor(8);
  grWNATLAS->SetMarkerStyle(20);
  grWNATLAS->SetMarkerSize(0.9);



  //
  // PHENIX
  // arXiv: 1009.0505
  //
  rts[0] = 0.5;
  ex[0] = 0.001;
  //
  csWP[0] = 144.1;
  stat =     21.2;
  syst =      6.8.;
  lum  =   0.15 * csWP[0];
  errWP[0] = sqrt( stat*stat + syst*syst + theo*theo + lum*lum );
  //
  csWN[0] = 31.7;
  stat    = 12.1;
  syst    =  9.2;
  lum     = 0.15 * csWN[0];
  errWN[0] = sqrt( stat*stat + syst*syst + theo*theo + lum*lum );

  // convert to nb
  csWP[0]  /= 1000.;
  csWN[0]  /= 1000.;
  errWP[0] /= 1000.;
  errWN[0] /= 1000.;

  grWPPHENIX = new TGraphErrors(n,rts,csWP,ex,errWP);
  grWPPHENIX->SetTitle("PHENIX WP");
  grWPPHENIX->SetMarkerColor(2);
  grWPPHENIX->SetLineWidth(2);
  grWPPHENIX->SetLineColor(2);
  grWPPHENIX->SetMarkerStyle(20);
  grWPPHENIX->SetMarkerSize(0.9);
   
  grWNPHENIX = new TGraphErrors(n,rts,csWN,ex,errWN);
  grWNPHENIX->SetTitle("PHENIX WN");
  grWNPHENIX->SetMarkerColor(2);
  grWNPHENIX->SetLineWidth(2);
  grWNPHENIX->SetLineColor(2);
  grWNPHENIX->SetMarkerStyle(20);
  grWNPHENIX->SetMarkerSize(0.9);
   





  //
  // CDF Run II
  //
  // PRL 94 (2005) 091803
  rts[0] = 1.96;
  ex[0] = 0.001;
  csW[0] = 2775.;
  stat = 10.;
  syst = 15.;
  lum  = 167.;
  errW[0] = sqrt( stat*stat + syst*syst + lum*lum );
  csZ[0] = 254.0;
  stat = 3.3;
  syst = 4.6;
  lum  = 15.2;
  errZ[0] = sqrt( stat*stat + syst*syst + lum*lum );
  RWZ[0] = 10.92;
  stat = 0.15;
  syst = 0.14;
  errR[0] = sqrt( stat*stat + syst*syst);

  // convert to nb
  csZ[0]   /= 1000.;
  csW[0]   /= 1000.;
  errZ[0]  /= 1000.;
  errW[0]  /= 1000.;

  grWCDF = new TGraphErrors(n,rts,csW,ex,errW);
  grWCDF->SetTitle("CDF II W");
  grWCDF->SetMarkerColor(1);
  grWCDF->SetMarkerStyle(20);
  grWCDF->SetMarkerSize(0.9);
  
  grZCDF = new TGraphErrors(n,rts,csZ,ex,errZ);
  grZCDF->SetTitle("CDF II Z");
  grZCDF->SetMarkerColor(1);
  grZCDF->SetMarkerStyle(24);
  grZCDF->SetMarkerSize(0.9);
   
  //
  // D0 Run I
  //
  // PRD 61 (2000) 072001
  rts[0] = 1.8;
  ex[0] = 0.001;
  csW[0] = 2310.;
  stat = 10.;
  syst = 50.;
  lum  = 100.;
  errW[0] = sqrt( stat*stat + syst*syst + lum*lum );
  csZ[0] = 221.0;
  stat = 3.;
  syst = 4.;
  lum  = 10.;
  errZ[0] = sqrt( stat*stat + syst*syst + lum*lum );
  RWZ[0] = 10.43;
  stat = 0.15;
  syst = 0.20;
  errR[0] = sqrt( stat*stat + syst*syst);

  // convert to nb
  csZ[0]   /= 1000.;
  csW[0]   /= 1000.;
  errZ[0]  /= 1000.;
  errW[0]  /= 1000.;

  grWD0 = new TGraphErrors(n,rts,csW,ex,errW);
  grWD0->SetTitle("D0 I W");
  grWD0->SetMarkerColor(1);
  grWD0->SetMarkerStyle(21);
  grWD0->SetMarkerSize(0.9);

  grZD0 = new TGraphErrors(n,rts,csZ,ex,errZ);
  grZD0->SetTitle("D0 I Z");
  grZD0->SetMarkerColor(1);
  grZD0->SetMarkerStyle(25);
  grZD0->SetMarkerSize(0.9);
   
  //
  // UA2
  //
  // Z. Phys. C47 (1990) p.11
  rts[0] = 0.630;
  ex[0] = 0.001;
  csW[0] = 660.;
  stat = 15.;
  syst = 37.;
  lum  = 0.;
  errW[0] = sqrt( stat*stat + syst*syst + lum*lum );
  csZ[0] = 70.4;
  stat = 5.5;
  syst = 4.0;
  lum  = 0.;
  errZ[0] = sqrt( stat*stat + syst*syst + lum*lum );
  RWZ[0] = 2.30;
  stat = 0.77;
  syst = 0.25;
  errR[0] = sqrt( stat*stat + syst*syst);

  // convert to nb
  csZ[0]   /= 1000.;
  csW[0]   /= 1000.;
  errZ[0]  /= 1000.;
  errW[0]  /= 1000.;

  grWUA2 = new TGraphErrors(n,rts,csW,ex,errW);
  grWUA2->SetTitle("UA2 W");
  grWUA2->SetMarkerColor(1);
  grWUA2->SetMarkerStyle(22);
  grWUA2->SetMarkerSize(0.9);

  grZUA2 = new TGraphErrors(n,rts,csZ,ex,errZ);
  grZUA2->SetTitle("UA2 Z");
  grZUA2->SetMarkerColor(1);
  grZUA2->SetMarkerStyle(26);
  grZUA2->SetMarkerSize(0.9);

  //
  // UA1
  //
  // Z. Phys. C44 (1989) 15.
  rts[0] = 0.630;
  ex[0] = 0.001;
  csW[0] = 630.;
  stat = 40.;
  syst = 10.;
  lum  = 0.;
  errW[0] = sqrt( stat*stat + syst*syst + lum*lum );
  csZ[0] = 70.;
  stat = 12.;
  syst = 0.20;
  lum  = 0.;
  errZ[0] = sqrt( stat*stat + syst*syst + lum*lum );
  RWZ[0] = -1.;
  stat = 1.;
  syst = 1.;
  errR[0] = sqrt( stat*stat + syst*syst);

  // convert to nb
  csZ[0]   /= 1000.;
  csW[0]   /= 1000.;
  errZ[0]  /= 1000.;
  errW[0]  /= 1000.;

  grWUA1 = new TGraphErrors(n,rts,csW,ex,errW);
  grWUA1->SetTitle("UA1 W");
  grWUA1->SetMarkerColor(1);
  grWUA1->SetMarkerStyle(29);
  grWUA1->SetMarkerSize(0.9);

  grZUA1 = new TGraphErrors(n,rts,csZ,ex,errZ);
  grZUA1->SetTitle("UA1 Z");
  grZUA1->SetMarkerColor(1);
  grZUA1->SetMarkerStyle(30);
  grZUA1->SetMarkerSize(0.9);
   
  //
  // theory curves
  //
  // from Giulio Lenzi
  //
  /*--------------------------------------------------------

 ppbar:

Energy              Z                                 W-                                W+
500        45868.10 + 1647.86 - 1138.33       235396.01 + 8221.80 - 6494.89     
235547.50 + 7810.82 - 7008.10 
700        77325.39 + 2489.40 - 1832.86       398429.20 + 12360.64 - 9678.81    
398399.97 + 12183.04 - 9649.49
1000       119953.55 + 3351.49 - 2753.88      626677.43 + 16986.85 - 12963.71   
627224.15 + 15250.08 - 14680.24
1400       173615.31 + 4141.43 - 3621.40      919368.68 + 20593.77 - 17527.57   
919645.06 + 19653.62 - 18071.74
3000       392940.24 + 8029.79 - 5916.10      2104471.95 + 40384.46 - 33948.49  
2103337.73 + 44050.51 - 29759.76

pp:
Energy              Z                                 W-                                 W+
3000       338131.34 + 7298.24 - 5763.35     1443365.36 + 32699.45 - 28515.93   
2322984.02 + 52428.03 - 37592.27
5000       640346.62 + 13007.13 - 9767.54    2791283.06 + 62491.67 - 49378.95   
4138688.76 + 89912.67 - 66157.58
7000       949277.02 + 20003.11 - 13375.32   4180328.21 + 84106.48 - 70776.93   
5935443.82 + 125116.95 - 97107.21
10000      1416441.13 + 28962.92 - 20799.72  6280739.78 + 115056.96 - 111296.06 
8579164.86 + 165284.75 - 149423.39
14000      2037515.51 + 39964.02 - 33317.92  9062406.16 + 183981.50 - 152528.91 
11986835.40 + 254025.44 - 194849

--------------------------------------------------------*/

  Double_t ecmTHb[5];
  Double_t sigmaZTHb[5];
  Double_t sigmaWTHb[5];
  Double_t sigmaWPTHb[5];
  Double_t sigmaWMTHb[5];

  Double_t sigmaZTHb_L[5];
  Double_t sigmaWTHb_L[5];
  Double_t sigmaWPTHb_L[5];
  Double_t sigmaWMTHb_L[5];
  Double_t sigmaZTHb_U[5];
  Double_t sigmaWTHb_U[5];
  Double_t sigmaWPTHb_U[5];
  Double_t sigmaWMTHb_U[5];

  ecmTHb[0] = 0.5;
  ecmTHb[1] = 0.7;
  ecmTHb[2] = 1.;
  ecmTHb[3] = 1.4;
  ecmTHb[4] = 3.;

  sigmaZTHb[0] = 45868.10 ; // + 1647.86 - 1138.33       
  sigmaWPTHb[0] = 235396.01; //  + 8221.80 - 6494.89     
  sigmaWMTHb[0] = 235547.50; //  + 7810.82 - 7008.10 

  sigmaZTHb[1] = 77325.39 ; // + 2489.40 - 1832.86       
  sigmaWPTHb[1] = 398429.20; //  + 12360.64 - 9678.81    
  sigmaWMTHb[1] = 398399.97; //  + 12183.04 - 9649.49

  sigmaZTHb[2] = 119953.55; //  + 3351.49 - 2753.88      
  sigmaWPTHb[2] = 626677.43; //  + 16986.85 - 12963.71   
  sigmaWMTHb[2] = 627224.15; //  + 15250.08 - 14680.24

  sigmaZTHb[3] = 173615.31; //  + 4141.43 - 3621.40      
  sigmaWPTHb[3] = 919368.68; //  + 20593.77 - 17527.57   
  sigmaWMTHb[3] = 919645.06; //  + 19653.62 - 18071.74

  sigmaZTHb[4] = 392940.24; //  + 8029.79 - 5916.10      
  sigmaWPTHb[4] = 2104471.95; // + 40384.46 - 33948.49  
  sigmaWMTHb[4] = 2103337.73; // + 44050.51 - 29759.76


  sigmaZTHb_U[0]  =   sigmaZTHb[0]  + 1647.86 ; 
  sigmaWPTHb_U[0] =   sigmaWPTHb[0] + 8221.80 ;
  sigmaWMTHb_U[0] =   sigmaWMTHb[0] + 7810.82 ;

  sigmaZTHb_U[1]  =   sigmaZTHb[1] + 2489.40 ;
  sigmaWPTHb_U[1] =   sigmaWPTHb[1] + 12360.64 ;
  sigmaWMTHb_U[1] =   sigmaWMTHb[1] + 12183.04 ;

  sigmaZTHb_U[2]  =   sigmaZTHb[2] + 3351.49 ;
  sigmaWPTHb_U[2] =   sigmaWPTHb[2] + 16986.85 ;
  sigmaWMTHb_U[2] =   sigmaWMTHb[2] + 15250.08 ;

  sigmaZTHb_U[3]  =   sigmaZTHb[3] + 4141.43 ;
  sigmaWPTHb_U[3] =   sigmaWPTHb[3] + 20593.77 ;
  sigmaWMTHb_U[3] =   sigmaWMTHb[3] + 19653.62 ;

  sigmaZTHb_U[4]  =   sigmaZTHb[4] + 8029.79 ;
  sigmaWPTHb_U[4] =   sigmaWPTHb[4] + 40384.46 ;
  sigmaWMTHb_U[4] =   sigmaWMTHb[4] + 44050.51 ;



  sigmaZTHb_L[0]  =   sigmaZTHb[0]  - 1138.33       ;
  sigmaWPTHb_L[0] =   sigmaWPTHb[0] - 6494.89     ;
  sigmaWMTHb_L[0] =   sigmaWMTHb[0] - 7008.10 ;

  sigmaZTHb_L[1]  =   sigmaZTHb[1]  - 1832.86       ;
  sigmaWPTHb_L[1] =   sigmaWPTHb[1] - 9678.81    ;
  sigmaWMTHb_L[1] =   sigmaWMTHb[1] - 9649.49;

  sigmaZTHb_L[2]  =   sigmaZTHb[2]  - 2753.88      ;
  sigmaWPTHb_L[2] =   sigmaWPTHb[2] - 12963.71   ;
  sigmaWMTHb_L[2] =   sigmaWMTHb[2] - 14680.24;

  sigmaZTHb_L[3]  =   sigmaZTHb[3]  - 3621.40      ;
  sigmaWPTHb_L[3] =   sigmaWPTHb[3] - 17527.57   ;
  sigmaWMTHb_L[3] =   sigmaWMTHb[3] - 18071.74;

  sigmaZTHb_L[4]  =   sigmaZTHb[4]  - 5916.10      ;
  sigmaWPTHb_L[4] =   sigmaWPTHb[4] - 33948.49  ;
  sigmaWMTHb_L[4] =   sigmaWMTHb[4] - 29759.76;

  for (int i=0; i<5; i++) {
    sigmaZTHb[i]  /= 1000000.;
    sigmaWPTHb[i] /= 1000000.;
    sigmaWMTHb[i] /= 1000000.;
    sigmaWTHb[i] = (sigmaWPTHb[i]+sigmaWMTHb[i]);
    sigmaZTHb_L[i] /= 1000000.;
    sigmaWTHb_L[i] = (sigmaWPTHb_L[i]+sigmaWMTHb_L[i]) / 1000.;
    sigmaZTHb_U[i] /= 1000000.;
    sigmaWTHb_U[i] = (sigmaWPTHb_U[i]+sigmaWMTHb_U[i]) / 1000.;
  }

  Double_t ecmTH[5];
  Double_t sigmaZTH[5];
  Double_t sigmaWTH[5];
  Double_t sigmaWPTH[5];
  Double_t sigmaWMTH[5];

  ecmTH[0] = 3.;
  ecmTH[1] = 5.;
  ecmTH[2] = 7.;
  ecmTH[3] = 10.;
  ecmTH[4] = 14.;

  Double_t georgeCorrZ  = 1.0218303;
  Double_t georgeCorrWp = 1.0361483;
  Double_t georgeCorrWm = 1.0262352;


  sigmaZTH[0] = georgeCorrZ*338131.34 ;
  sigmaZTH[1] = georgeCorrZ*640346.62 ;
  sigmaZTH[2] = georgeCorrZ*949277.02 ;
  sigmaZTH[3] = georgeCorrZ*1416441.13 ;
  sigmaZTH[4] = georgeCorrZ*2037515.51 ;

  sigmaWMTH[0] = georgeCorrWm*1443365.36 ; // + 32699.45 - 28515.93   
  sigmaWPTH[0] = georgeCorrWp*2322984.02 ; // + 52428.03 - 37592.27

  sigmaWMTH[1] = georgeCorrWm*2791283.06 ; // + 62491.67 - 49378.95   
  sigmaWPTH[1] = georgeCorrWp*4138688.76 ; // + 89912.67 - 66157.58

  sigmaWMTH[2] = georgeCorrWm*4180328.21 ; // + 84106.48 - 70776.93   
  sigmaWPTH[2] = georgeCorrWp*5935443.82 ; // + 125116.95 - 97107.21

  sigmaWMTH[3] = georgeCorrWm*6280739.78 ; // + 115056.96 - 111296.06 
  sigmaWPTH[3] = georgeCorrWp*8579164.86 ; // + 165284.75 - 149423.39

  sigmaWMTH[4] = georgeCorrWm*9062406.16 ; // + 183981.50 - 152528.91 
  sigmaWPTH[4] = georgeCorrWp*11986835.4 ; // + 254025.44 - 194849

  for (int i=0; i<5; i++) {
    sigmaZTH[i]  /= 1000000.;
    sigmaWPTH[i] /= 1000000.;
    sigmaWMTH[i] /= 1000000.;
    sigmaWTH[i] = (sigmaWPTH[i]+sigmaWMTH[i]) ;
  }


  crvZTHb = new TGraph(5,ecmTHb,sigmaZTHb);
  crvZTHb->SetLineColor(4);
  crvZTHb->SetLineWidth(2);

  crvWTHb = new TGraph(5,ecmTHb,sigmaWTHb);
  crvWTHb->SetLineColor(4);
  crvWTHb->SetLineWidth(2);

  crvWPTH = new TGraph(5,ecmTH,sigmaWPTH);
  crvWPTH->SetLineColor(4);
  crvWPTH->SetLineWidth(2);

  crvWMTH = new TGraph(5,ecmTH,sigmaWMTH);
  crvWMTH->SetLineColor(4);
  crvWMTH->SetLineWidth(2);

  crvWTHb_L = new TGraph(5,ecmTHb,sigmaWTHb_L);
  crvWTHb_L->SetLineColor(3);
  crvWTHb_L->SetLineWidth(1);

  crvWTHb_U = new TGraph(5,ecmTHb,sigmaWTHb_U);
  crvWTHb_U->SetLineColor(3);
  crvWTHb_U->SetLineWidth(1);

  crvZTH = new TGraph(5,ecmTH,sigmaZTH);
  crvZTH->SetLineColor(4);
  crvZTH->SetLineWidth(2);

  crvWTH = new TGraph(5,ecmTH,sigmaWTH);
  crvWTH->SetLineColor(4);
  crvWTH->SetLineWidth(2);


  //====================================================
  // make the plot
  //====================================================

  if (plotATLAS) {
    printf("  ** Include ATLAS points ** \n");
  } else {
    printf("  ** Do not include ATLAS points ** \n");
  }

  //  hpx = new TH2F("hpx",";Collider energy (TeV);#sigma #times BR (pb)",3,0.35,25.,2,30.,25500.);
  hpx = new TH2F("hpx",";Collider energy (TeV);#sigma #times B (nb)",3,0.35,25.,2,0.03,25.500);

  gStyle->SetOptStat(0);
  gStyle->SetLineColor(1);
  gStyle->SetHistFillStyle(1001);
  gStyle->SetHistFillColor(92);
  gStyle->SetHistLineWidth(2); 
  gStyle->SetHistLineColor(2);
  gStyle->SetFrameFillColor(4000);
  gStyle->SetTitleW(0.55);
  gStyle->SetTitleH(0.07);
  gPad->SetFillColor(4000);
  c1->SetFillStyle(0);
  c1->SetLogx();
  c1->SetLogy();
  hpx->UseCurrentStyle();

  hpx->SetStats(kFALSE);
  hpx->Draw();

  TLegend *legend = new TLegend(0.15,0.6,0.48,0.88);
  legend->AddEntry(grWCMS,  "CMS, 36 pb^{-1}, 2010","p");
  if (plotATLAS) {
  legend->AddEntry(grWATLAS,"ATLAS, 0.34 pb^{-1}, 2010","p");
  }
  legend->AddEntry(grWCDF,"CDF Run II","p");
  legend->AddEntry(grWD0,"D0 Run I","p");
  legend->AddEntry(grWUA2,"UA2","p");
  legend->AddEntry(grWUA1,"UA1","p");
  legend->SetBorderSize(0);
  legend->SetFillColor(4000);
  legend->Draw();

  crvZTHb->Draw("C");
  crvWTHb->Draw("C");
  //  crvWTHb_L->Draw("C");
  //  crvWTHb_U->Draw("C");
  crvZTH->Draw("C");
  crvWTH->Draw("C");
  crvWPTH->Draw("C");
  crvWMTH->Draw("C");

  grWCMS->Draw("P");
  grWPCMS->Draw("P");
  grWNCMS->Draw("P");
  if (plotATLAS) {
  grWATLAS->Draw("P");
  grWPATLAS->Draw("P");
  grWNATLAS->Draw("P");
  }
  grWCDF->Draw("P");
  grWD0->Draw("P");
  grWUA2->Draw("P");
  grWUA1->Draw("P");

  //  grWPPHENIX->Draw("P");
  //  grWNPHENIX->Draw("P");


  grZCMS->Draw("P");
  if (plotATLAS) {
  grZATLAS->Draw("P");
  }
  grZCDF->Draw("P");
  grZD0->Draw("P");
  grZUA2->Draw("P");
  grZUA1->Draw("P");

  //
  // labels
  //

  TPaveText *Wlnu = new TPaveText(15.,18.000,24.,24.900);
  Wlnu->AddText("W #rightarrow l#nu");
  Wlnu->SetTextAlign(12);
  Wlnu->SetFillColor(4000);
  Wlnu->SetTextColor(1);
  Wlnu->SetBorderSize(0);
  Wlnu->Draw();

  TPaveText *WPlnu = new TPaveText(15.,9.800,24.,16.000);
  WPlnu->AddText("W^{+} #rightarrow l^{+}#nu");
  WPlnu->SetTextAlign(12);
  WPlnu->SetFillColor(4000);
  WPlnu->SetTextColor(1);
  WPlnu->SetBorderSize(0);
  WPlnu->Draw();

  TPaveText *WNlnu = new TPaveText(15.,7.000,24.,9.800);
  WNlnu->AddText("W^{-} #rightarrow l^{-}#nu");
  WNlnu->SetTextAlign(12);
  WNlnu->SetFillColor(4000);
  WNlnu->SetTextColor(1);
  WNlnu->SetBorderSize(0);
  WNlnu->Draw();

  TPaveText *Zll = new TPaveText(15.,1.800,24.,2.500);
  Zll->AddText("Z #rightarrow l^{+}l^{-}");
  Zll->SetTextAlign(12);
  Zll->SetFillColor(4000);
  Zll->SetTextColor(1);
  Zll->SetBorderSize(0);
  Zll->Draw();

  TPaveText *Theory = new TPaveText(2.,0.040,24.,0.080);
  Theory->AddText("Theory: FEWZ and MSTW08 NNLO PDFs");
  Theory->SetTextAlign(12);
  Theory->SetFillColor(4000);
  Theory->SetTextColor(4);
  Theory->SetBorderSize(0);
  Theory->Draw();

  TPaveText *ppbar = new TPaveText(1.,0.280,1.4,0.500);
  ppbar->AddText("p#bar{p}");
  ppbar->SetTextAlign(12);
  ppbar->SetFillColor(4000);
  ppbar->SetTextColor(4);
  ppbar->SetBorderSize(0);
  ppbar->Draw();

  TPaveText *pp = new TPaveText(4.,0.900,6.,1.700);
  pp->AddText("pp");
  pp->SetTextAlign(12);
  pp->SetFillColor(4000);
  pp->SetTextColor(4);
  pp->SetBorderSize(0);
  pp->Draw();

  if (makePDFPNG) {
    printf("  ** Printing PDF,PNG (takes a while) ** \n");
    c1->Update();
    c1->Print("WZsigmas.pdf");
    c1->Print("WZsigmas.png");
  } else {
    printf("  ** Not Printing PDF,PNG ** \n");
  }

}
