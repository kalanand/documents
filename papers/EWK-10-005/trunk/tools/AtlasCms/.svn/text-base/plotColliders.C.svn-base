pl//
// W and Z cross section versus collider energy
//  and comparison ATLAS/CMS at sqrt(s)=7 TeV
//      Figure for EWK-10-002
// Authors: Michael Schmitt, Gautier Hamel de Monchenault
// 

void plotMichael();
void plotGautier();
void
drawBand( float _xmin, float _xmax, float _ymin, float _ymax,
	  int color1, int color2, int lw, int fs, const char* opt );
void abLabel( const char* label, float posx, float posy, float size=0.04 ); 

void plotColliders()
{
  gROOT->LoadMacro("tdrstyle.C");
  setTDRStyle();
  gStyle->SetTickLength( 1.5*gStyle->GetTickLength("Y"), "Y" );

  // dimensions
  float  _t(40), _b(70), _g(100), _d(42), _h(140), _w(700);
  float  _t1(40), _b1(200), _l1(180), _r1(10);
  float  _r2 =  70;
  float  _b2 = _b1;
  float  _t2 = _t1;
  float  _l2 = _l1;
  float   _W = 1000;
  float   _H = 600;

  // latex text
  TText* txt_ = new TLatex();

  // canvas
  TCanvas* _canv=new TCanvas( "compareColliders", "Compare Colliders", 
			      0, 0, _W, _H );  
  
  //
  // First pad
  //
  float xlim_ = 0.70;
  float scale1_ = xlim_/_W;
  TPad* pad1_ = new TPad( "pad1", "pad2", 
			  0, 0, xlim_, 1,
			  kWhite, 0, 0 );

  pad1_->SetBottomMargin(  _b1*scale1_ );
  pad1_->SetTopMargin(     _t1*scale1_ );
  pad1_->SetRightMargin(   _r1*scale1_ );
  pad1_->SetLeftMargin(    _l1*scale1_ ); 
  pad1_->SetFillColor(0);
  pad1_->SetTickx(1);
  pad1_->SetTicky(1);
  pad1_->SetLogx();
  pad1_->SetLogy();
  pad1_->SetFrameFillStyle(0);
  pad1_->SetFrameLineWidth(2);
  pad1_->SetFrameBorderMode(0);

  pad1_->Draw();
  pad1_->cd();

  // prepare histogram for Michael's plot
  TH2* _hist1 = new TH2F("bidon","bidon",100,0.3,30,100,0.03,30);
  TAxis* _ax1 = _hist1->GetXaxis();
  TAxis* _ay1 = _hist1->GetYaxis();
  _ax1->SetLabelOffset(99);
  _ax1->SetTitleSize(0.06);
  _ax1->SetTitleOffset(1.0);
  _ax1->SetTitle("Collider Energy [TeV]");
  _ay1->SetTitle("#sigma #times B  [nb]");
  _ay1->SetTitleSize(0.060);
  _ay1->SetTitleOffset(0.9);
  _ay1->SetLabelSize(0.055);
  _hist1->Draw();

  // draw Michael's plot
  plotMichael();

  // draw axis labels
  float xlab_ = 65;
  float ylab_ = 60;
  float ytxt_ = 0.027;
  txt_->SetTextAngle(0);
  txt_->SetTextAlign(23);
  txt_->SetTextFont(42);
  txt_->SetTextSize( xlab_*scale1_ );
  float energy = 0.5;
  txt_->SetText(energy,ytxt_,Form("%-2.1f",energy)); txt_->DrawClone();
  energy = 1;
  txt_->SetText(energy,ytxt_,Form("%-1.0f",energy)); txt_->DrawClone();
  energy = 2;
  txt_->SetText(energy,ytxt_,Form("%-1.0f",energy)); txt_->DrawClone();
  energy = 5;
  txt_->SetText(energy,ytxt_,Form("%-1.0f",energy)); txt_->DrawClone();
  energy = 7;
  txt_->SetText(energy,ytxt_,Form("%-1.0f",energy)); txt_->DrawClone();
  energy = 10;
  txt_->SetText(energy,ytxt_,Form("%-1.0f",energy)); txt_->DrawClone();
  energy = 20;
  txt_->SetText(energy,ytxt_,Form("%-2.0f",energy)); txt_->DrawClone();
  energy = 16;

  // plot the particle 
//   txt_->SetTextAngle(0);
//   txt_->SetTextAlign(12);
//   txt_->SetTextFont(42);
//   txt_->SetTextSize( 60*scale1_ );
//   txt_->SetText(energy,22,"W");     txt_->DrawClone();
//   txt_->SetText(energy,14,"W^{+}"); txt_->DrawClone();
//   txt_->SetText(energy,9,"W^{-}");  txt_->DrawClone();
//  txt_->SetText(energy,2.2,"Z");    txt_->DrawClone();

  //
  //  abLabel( "(a)", 0.60, 0.18, 0.05 );
  abLabel( "(a)", 0.90, 0.40, 0.05 );

  _canv->cd();

  //
  // now second pad
  //
  float scale2_ = xlim_/(1-xlim_);
  float scale3_ = 1./xlim_/xlim_;
  TPad* pad2_ = new TPad( "pad2", "pad2", 
			  xlim_, 0, 1, 1,
			  kWhite, 0, 0 );
  pad2_->SetBottomMargin(  _b2*scale1_ );
  pad2_->SetTopMargin(     _t2*scale1_ );
  pad2_->SetRightMargin(   _r2*scale1_*scale2_ );
  pad2_->SetLeftMargin(    _l2*scale1_*scale2_ ); 
  pad2_->SetFillColor(0);
  pad2_->SetTickx(0);
  pad2_->SetTicky(1);
  pad2_->SetLogy();
  pad2_->SetFrameFillStyle(0);
  pad2_->SetFrameLineWidth(2);
  pad2_->SetFrameBorderMode(0);
  pad2_->Draw();
  pad2_->cd();

  // Prepare histogram for Gautier's plot
  TH2* _hist2 = new TH2F("bidon2","bidon2",3,0,3,100,0.5,20);
  TAxis* _ax2 = _hist2->GetXaxis();
  TAxis* _ay2 = _hist2->GetYaxis();
  _ax2->SetLabelOffset(99);
  _ax2->SetNdivisions(0);
  _ax2->SetTitleSize(0);
  _ax2->SetTitleOffset(99);
  _ay2->SetLabelOffset(99);
  _ay2->SetTitleSize(0);
  _ay2->SetTitleOffset(99);
  _ay2->SetLabelSize(0);
  
  _hist2->Draw();

  // draw energy
  txt_->SetTextFont(42);
  txt_->SetTextAlign(22);
  txt_->SetTextSize(100*scale1_);
  txt_->SetTextFont(42);
  txt_->SetTextAlign(23);
  txt_->SetTextSize(xlab_*scale1_*scale3_);
  txt_->SetText(1.5,0.47,"7 TeV");
  txt_->DrawClone();

  // draw vertical axis labels
  float lab2_ = -0.1;
  txt_->SetTextAlign(32);
  txt_->SetTextSize(ylab_*scale1_*scale3_);
  txt_->SetText(lab2_,0.5,"0.5"); txt_->DrawClone();
  for( int ii=1; ii<=10; ii++ )
    {
      if( ii==6 || ii==8 || ii==9 ) continue;
      txt_->SetText(lab2_,ii,Form("%d",ii)); txt_->DrawClone();
    }
  txt_->SetText(lab2_,20,Form("%d",20)); txt_->DrawClone();

  // draw vertical axis title
  txt_->SetTextSize( 80*scale1_*scale3_);
  txt_->SetText(-1,20,"#sigma #times B  [nb]");
  txt_->SetTextFont(42);
  bool rotate(false);
  if( rotate )
    {
      txt_->SetTextAngle(270);
      txt_->SetTextAlign(12);
    }
  else
    {
      txt_->SetTextAngle(90);
      txt_->SetTextAlign(32);
    }
  txt_->DrawClone();

  // write experiment information
  txt_->SetTextAngle(0);
  txt_->SetTextAlign(22);
  txt_->SetTextFont(62);
  txt_->SetTextSize( 50*scale1_*scale3_);
  txt_->SetText(0.9,16,"ATLAS");
  txt_->DrawClone();
  txt_->SetText(2.2,16,"CMS");
  txt_->DrawClone();
  txt_->SetTextFont(42);
  txt_->SetTextSize( 40*scale1_*scale3_);
  txt_->SetText(0.9,13.2,"35 pb^{-1}");
  txt_->DrawClone();
  txt_->SetText(2.2,13.2,"36 pb^{-1}");
  txt_->DrawClone();

  // draw theory bands
  float _eps1 = 0.02;
  float _eps2 = 0.02;
  float _xmin=0+_eps1;
  float _xmax=3-_eps2;
  gStyle->SetHatchesSpacing(0.5);
  gStyle->SetHatchesLineWidth(1);
  int fillStyle = 3354;
  const char* opt = "FSame";
  txt_->SetTextAlign(12);
  txt_->SetTextSize(50*scale1_*scale3_);
  TLine* l_ = new TLine( _xmin, 0, _xmax, 0 );
  l_->SetLineWidth(1);
  l_->SetLineColor( kBlue );
  float xbos_=3.1;

  // W
  float _y0 = 10.44;
  float _ey0 = 0.31;
  float _ymin = _y0 - _ey0;
  float _ymax = _y0 + _ey0;
  drawBand( _xmin, _xmax, _ymin, _ymax, kBlue-10, kBlue, 2, fillStyle, "FSame");
  l_->SetY1(_y0); l_->SetY2(_y0); l_->DrawClone();
  txt_->SetText(xbos_+0.05,_y0,"W");  txt_->DrawClone();

  // Z
  float _y0 =  0.97;
  float _ey0 = 0.03;
  float _ymin = _y0 - _ey0;
  float _ymax = _y0 + _ey0;
  drawBand( _xmin, _xmax, _ymin, _ymax, kBlue-10, kBlue, 2, fillStyle, "FSame");
  l_->SetY1(_y0); l_->SetY2(_y0); l_->DrawClone();
  txt_->SetText(xbos_+0.05,_y0,"Z");  txt_->DrawClone();

  // W-
  float _y0 = 4.29;
  float _ey0 = 0.17;
  float _ymin = _y0 - _ey0;
  float _ymax = _y0 + _ey0;
  drawBand( _xmin, _xmax, _ymin, _ymax, kBlue-10, kBlue, 2, fillStyle, "FSame");
  l_->SetY1(_y0); l_->SetY2(_y0); l_->DrawClone();
  txt_->SetText(xbos_,_y0,"W^{-}");  txt_->DrawClone();

  // W+
  float _y0 = 6.15;
  float _ey0 = 0.22;
  float _ymin = _y0 - _ey0;
  float _ymax = _y0 + _ey0;
  drawBand( _xmin, _xmax, _ymin, _ymax, kBlue-10, kBlue, 2, fillStyle, "FSame");
  l_->SetY1(_y0); l_->SetY2(_y0); l_->DrawClone();
  txt_->SetText(xbos_,_y0,"W^{+}");  txt_->DrawClone();

  // draw the luminosity box
  // CMS lumi bar
//   txt_->SetTextSize(40*scale1_*scale3_);
//   txt_->SetTextColor(kRed);
//   _xmin = 1.85;
//   _xmax = _xmin+0.3;
//   _ymax = 2.8*(1+0.04);
//   _ymin = 2.8*(1-0.04);
//   drawBand( _xmin, _xmax, _ymin, _ymax, kRed-10, kRed-10, 3, fillStyle, "FSame");
//   txt_->SetTextAlign(21);
//   txt_->SetText(0.5*(_xmin+_xmax),_ymax*1.05,"lumi.");
//   txt_->DrawClone();
//   _ymin = 2.8;
//   _ymax = 2.8*(1+0.04);
//   drawBand( _xmin, _xmax, _ymin, _ymax, kRed, kRed, 1, fillStyle, "LSame");
//   _ymin = 2.8*(1-0.04);
//   _ymax = 2.8;
//   drawBand( _xmin, _xmax, _ymin, _ymax, kRed, kRed, 1, fillStyle, "LSame");
//   txt_->SetTextAlign(23);
//   txt_->SetText(0.5*(_xmin+_xmax),_ymin*0.95,"#pm 4%");
//   txt_->DrawClone();

  // ATLAS lumi bar
//   txt_->SetTextSize(40*scale1_*scale3_);
//   txt_->SetTextColor(kGreen+3);
//   _xmin = 0.85;
//   _xmax = _xmin+0.3;
//   _ymax = 2.8*(1+0.034);
//   _ymin = 2.8*(1-0.034);
//   drawBand( _xmin, _xmax, _ymin, _ymax, kGreen+3-10, kGreen+3-10, 3, fillStyle, "FSame");
//   txt_->SetTextAlign(21);
//   txt_->SetText(0.5*(_xmin+_xmax),_ymax*1.05,"lumi.");
//   txt_->DrawClone();
//   _ymin = 2.8;
//   _ymax = 2.8*(1+0.034);
//   drawBand( _xmin, _xmax, _ymin, _ymax, kGreen+3, kGreen+3, 1, fillStyle, "LSame");
//   _ymin = 2.8*(1-0.034);
//   _ymax = 2.8;
//   drawBand( _xmin, _xmax, _ymin, _ymax, kGreen+3, kGreen+3, 1, fillStyle, "LSame");
//   txt_->SetTextAlign(23);
//   txt_->SetText(0.5*(_xmin+_xmax),_ymin*0.95,"#pm 3.4%");
//   txt_->DrawClone();

  // draw Gautier's plot
  plotGautier();

  //  abLabel( "(b)", 0.65, 0.175, 0.09 );
  abLabel( "(b)", 0.5, 0.40, 0.09 );

  //
  _canv->cd();

  return;

}

void
plotMichael()
{
  //
  // set options
  //
  Bool_t plotATLAS = false;
  Bool_t makePDFPNG = true;

  // declarations
  Int_t n = 1;
  Float_t rts[1];
  Float_t ex[1];
  Float_t csW[1];
  Float_t errW[1];
  Float_t csWP[1];
  Float_t errWP[1];
  Float_t csWN[1];
  Float_t errWN[1];
  Float_t csZ[1];
  Float_t errZ[1];
  Float_t RWZ[1];
  Float_t errR[1];
  double stat = 0.;
  double syst = 0.;
  double lum  = 0.;
  double theo = 0.;
  double lum_unc = 0.04;

  //
  // CMS (updated!)
  //
  //  rts[0] = 7. + 0.2;
  rts[0] = 7.;
  if (plotATLAS) {rts[0] += 0.2;}  // offset needed for seeing points
  //
  ex[0] = 0.001;
  csW[0] = 10307;
  stat   =  20.;
  syst   = 93.;
  lum    = lum_unc * csW[0];
  errW[0] = sqrt( stat*stat + syst*syst + theo*theo + lum*lum );
  //
  csZ[0] = 975.0;
  stat =    6.;
  syst =    7.;
  lum  = lum_unc * csZ[0];
  errZ[0] = sqrt( stat*stat + syst*syst + theo*theo + lum*lum );
  //
  RWZ[0] = 10.54;
  stat = 0.07;
  syst = 0.08;
  errR[0] = sqrt( stat*stat + syst*syst + theo*theo);
  //
  csWP[0] = 6040.;
  stat =  15.;
  syst = 56.;
  lum  = lum_unc * csWP[0];
  errWP[0] = sqrt( stat*stat + syst*syst + theo*theo + lum*lum );
  //
  csWN[0] = 4261.;
  stat =  13.;
  syst = 42.;
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
  grZCMS->SetMarkerStyle(20);
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
  grWATLAS->SetLineColor(kGreen+3);
  grWATLAS->SetLineWidth(2);
  grWATLAS->SetMarkerStyle(20);
   
  grZATLAS = new TGraphErrors(n,rts,csZ,ex,errZ);
  grZATLAS->SetTitle("ATLAS Z");
  grZATLAS->SetMarkerColor(8);
  //  grZATLAS->SetLineColor(kGreen+3);
  grZATLAS->SetLineColor(kBlue);
  grZATLAS->SetLineWidth(2);
  grZATLAS->SetMarkerStyle(20);

  grWPATLAS = new TGraphErrors(n,rts,csWP,ex,errWP);
  grWPATLAS->SetTitle("ATLAS WP");
  grWPATLAS->SetMarkerColor(8);
  grWPATLAS->SetLineColor(kGreen+3);
  grWPATLAS->SetLineWidth(2);
  grWPATLAS->SetMarkerStyle(20);
   
  grWNATLAS = new TGraphErrors(n,rts,csWN,ex,errWN);
  grWNATLAS->SetTitle("ATLAS WN");
  grWNATLAS->SetMarkerColor(8);
  grWNATLAS->SetLineColor(kGreen+3);
  grWNATLAS->SetLineWidth(2);
  grWNATLAS->SetMarkerStyle(20);


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
   
  grWNPHENIX = new TGraphErrors(n,rts,csWN,ex,errWN);
  grWNPHENIX->SetTitle("PHENIX WN");
  grWNPHENIX->SetMarkerColor(2);
  grWNPHENIX->SetLineWidth(2);
  grWNPHENIX->SetLineColor(2);
  grWNPHENIX->SetMarkerStyle(20);
   
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
  grWCDF->SetMarkerStyle(21);
  grWCDF->SetMarkerSize(1.0);
  grWCDF->SetLineWidth(2);
  

  grZCDF = new TGraphErrors(n,rts,csZ,ex,errZ);
  grZCDF->SetTitle("CDF II Z");
  grZCDF->SetMarkerColor(1);
  grZCDF->SetMarkerStyle(21);
  grZCDF->SetMarkerSize(1.0);
  grZCDF->SetLineWidth(2);
   
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
  grWD0->SetLineWidth(2);
  grWD0->SetMarkerStyle(25);
  grWD0->SetMarkerSize(1.0);

  grZD0 = new TGraphErrors(n,rts,csZ,ex,errZ);
  grZD0->SetTitle("D0 I Z");
  grZD0->SetMarkerColor(1);
  grZD0->SetMarkerSize(1.0);
  grZD0->SetLineWidth(2);
  grZD0->SetMarkerStyle(25);
   
  //
  // UA2
  //
  // Z. Phys. C47 (1990) p.11
  rts[0] = 0.630*1.030;
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
  grWUA2->SetMarkerSize(1.3);
  grWUA2->SetLineWidth(2);



  grZUA2 = new TGraphErrors(n,rts,csZ,ex,errZ);
  grZUA2->SetTitle("UA2 Z");
  grZUA2->SetMarkerColor(1);
  grZUA2->SetMarkerStyle(22);
  grZUA2->SetMarkerSize(1.3);
  grZUA2->SetLineWidth(2);

  //
  // UA1
  //
  // Z. Phys. C44 (1989) 15.
  rts[0] = 0.630/1.030;
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
  //  grWUA1->SetMarkerStyle(30);
  grWUA1->SetMarkerStyle(23);
  grWUA1->SetMarkerSize(1.3);
  grWUA1->SetLineWidth(2);

  grZUA1 = new TGraphErrors(n,rts,csZ,ex,errZ);
  grZUA1->SetTitle("UA1 Z");
  grZUA1->SetMarkerColor(1);
  //  grZUA1->SetMarkerStyle(30);
  grZUA1->SetMarkerStyle(23);
  grZUA1->SetMarkerSize(1.3);
  grZUA1->SetLineWidth(2);
   
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

//   //  hpx = new TH2F("hpx",";Collider energy (TeV);#sigma #times BR (pb)",3,0.35,25.,2,30.,25500.);
//   hpx = new TH2F("hpx",";Collider energy (TeV);#sigma #times B (nb)",3,0.35,25.,2,0.03,25.500);

//   gStyle->SetOptStat(0);
//   gStyle->SetLineColor(1);
//   gStyle->SetHistFillStyle(1001);
//   gStyle->SetHistFillColor(92);
//   gStyle->SetHistLineWidth(2); 
//   gStyle->SetHistLineColor(2);
//   gStyle->SetFrameFillColor(4000);
//   gStyle->SetTitleW(0.55);
//   gStyle->SetTitleH(0.07);
//   gPad->SetFillColor(4000);
//   c1->SetFillStyle(0);
//   c1->SetLogx();
//   c1->SetLogy();
//   hpx->UseCurrentStyle();

//   hpx->SetStats(kFALSE);
//   hpx->Draw();

//   TLegend *legend = new TLegend(0.15,0.6,0.48,0.88);
   TLegend *legend = new TLegend(0.17,0.67,0.50,0.92);
   legend->AddEntry(grWCMS,  "CMS, 36 pb^{-1}","p");
   if (plotATLAS) {
   legend->AddEntry(grWATLAS,"ATLAS, 0.34 pb^{-1}","p");
   }
   legend->AddEntry(grWCDF,"CDF Run II","p");
   legend->AddEntry(grWD0,"D0 Run I","p");
   legend->AddEntry(grWUA2,"UA2","p");
   legend->AddEntry(grWUA1,"UA1","p");
   legend->SetBorderSize(0);
   legend->SetFillColor(4000);
   legend->Draw();

  crvZTHb->DrawClone("C");
  crvWTHb->DrawClone("C");
  //  crvWTHb_L->DrawClone("C");
  //  crvWTHb_U->DrawClone("C");
  crvZTH->DrawClone("C");
  crvWTH->DrawClone("C");
  crvWPTH->DrawClone("C");
  crvWMTH->DrawClone("C");

  grWCMS->DrawClone("P");
  grWPCMS->DrawClone("P");
  grWNCMS->DrawClone("P");
  if (plotATLAS) {
  grWATLAS->DrawClone("P");
  grWPATLAS->DrawClone("P");
  grWNATLAS->DrawClone("P");
  }
  grWCDF->DrawClone("P");
  grWD0->DrawClone("P");
  grWUA2->DrawClone("P");
  grWUA1->DrawClone("P");

  //  grWPPHENIX->DrawClone("P");
  //  grWNPHENIX->DrawClone("P");


  grZCMS->DrawClone("P");
  if (plotATLAS) {
  grZATLAS->DrawClone("P");
  }
  grZCDF->DrawClone("P");
  grZD0->DrawClone("P");
  grZUA2->DrawClone("P");
  grZUA1->DrawClone("P");

  //
  // labels
  //

  TPaveText *Wlnu = new TPaveText(15.,18.000,24.,24.900);
  Wlnu->AddText("W #rightarrow l#nu");
  Wlnu->SetTextAlign(12);
  Wlnu->SetFillColor(4000);
  Wlnu->SetTextColor(1);
  Wlnu->SetBorderSize(0);
  Wlnu->SetTextSize(0.04);
  Wlnu->Draw();

  TPaveText *WPlnu = new TPaveText(15.,9.800,24.,16.000);
  WPlnu->AddText("W^{+} #rightarrow l^{+}#nu");
  WPlnu->SetTextAlign(12);
  WPlnu->SetFillColor(4000);
  WPlnu->SetTextColor(1);
  WPlnu->SetBorderSize(0);
  WPlnu->SetTextSize(0.04);
  WPlnu->Draw();

  TPaveText *WNlnu = new TPaveText(15.,7.000,24.,9.800);
  WNlnu->AddText("W^{-} #rightarrow l^{-}#nu");
  WNlnu->SetTextAlign(12);
  WNlnu->SetFillColor(4000);
  WNlnu->SetTextColor(1);
  WNlnu->SetBorderSize(0);
  WNlnu->SetTextSize(0.04);
  WNlnu->Draw();

  TPaveText *Zll = new TPaveText(15.,1.800,24.,2.500);
  Zll->AddText("Z #rightarrow l^{+}l^{-}");
  Zll->SetTextAlign(12);
  Zll->SetFillColor(4000);
  Zll->SetTextColor(1);
  Zll->SetBorderSize(0);
  Zll->SetTextSize(0.04);
  Zll->Draw();

  TPaveText *Theory = new TPaveText(2.,0.040,24.,0.080);
  //  TPaveText *Theory = new TPaveText(2.,0.10,24.,0.20);
  //  Theory->AddText("Theory: FEWZ and MSTW08 NNLO PDFs");
  Theory->AddText("Theory: NNLO, FEWZ and MSTW08 PDFs");
  Theory->SetTextAlign(12);
  Theory->SetFillColor(4000);
  Theory->SetTextColor(4);
  Theory->SetBorderSize(0);
  Theory->DrawClone();

  TPaveText *ppbar = new TPaveText(1.,0.280,1.4,0.500);
  ppbar->AddText("p#bar{p}");
  ppbar->SetTextAlign(12);
  ppbar->SetFillColor(4000);
  ppbar->SetTextColor(4);
  ppbar->SetBorderSize(0);
  ppbar->DrawClone();

  TPaveText *pp = new TPaveText(4.,0.900,6.,1.700);
  pp->AddText("pp");
  pp->SetTextAlign(12);
  pp->SetFillColor(4000);
  pp->SetTextColor(4);
  pp->SetBorderSize(0);
  pp->DrawClone();

  //   if (makePDFPNG) {
  //     printf("  ** Printing PDF,PNG (takes a while) ** \n");
  //     c1->Update();
  //     c1->Print("WZsigmas.pdf");
  //     c1->Print("WZsigmas.png");
  //   } else {
  //     printf("  ** Not Printing PDF,PNG ** \n");
  //   }
}

void
plotGautier()
{
  gStyle->SetEndErrorSize(5);
  gStyle->SetMarkerSize(0.9);


  //  float posCMS = 2.1;
  //  float posAtlas = 1.4;
  float posCMS = 1.8;
  float posAtlas = 1.2;
  //
  // set options
  //
  Bool_t plotATLAS = true;

  // declarations
  Int_t n = 1;
  Float_t rts[1];
  Float_t ex[1];
  Float_t csW[1];
  Float_t errW[1];
  Float_t csWP[1];
  Float_t errWP[1];
  Float_t csWN[1];
  Float_t errWN[1];
  Float_t csZ[1];
  Float_t errZ[1];
  Float_t RWZ[1];
  Float_t errR[1];
  double stat = 0.;
  double syst = 0.;
  double lum  = 0.;
  double theo = 0.;
  double lum_unc = 0.04;


  //
  // CMS
  //
  rts[0] = posCMS;
  if (plotATLAS) {rts[0] += 0.2;}  // offset needed for seeing points
  //
  ex[0] = 0.001;
  csW[0] = 10307.;
  stat   =  20.;
  syst   = 93.;
  lum    = lum_unc * csW[0];
  errW[0] = sqrt( stat*stat + syst*syst + theo*theo + lum*lum );
  //
  csZ[0] = 975.0;
  stat =    6.;
  syst =    7.;
  lum  = lum_unc * csZ[0];
  errZ[0] = sqrt( stat*stat + syst*syst + theo*theo + lum*lum );
  //
  RWZ[0] = 10.54;
  stat = 0.07;
  syst = 0.08;
  errR[0] = sqrt( stat*stat + syst*syst + theo*theo);
  //
  csWP[0] = 6040.;
  stat =  15.;
  syst = 56.;
  lum  = lum_unc * csWP[0];
  errWP[0] = sqrt( stat*stat + syst*syst + theo*theo + lum*lum );
  //
  csWN[0] = 4261.;
  stat =  13.;
  syst = 42.;
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
   
  grZCMS = new TGraphErrors(n,rts,csZ,ex,errZ);
  grZCMS->SetTitle("CMS Z");
  grZCMS->SetMarkerColor(2);
  grZCMS->SetLineWidth(2);
  grZCMS->SetLineColor(2);
  grZCMS->SetMarkerStyle(20);

  grWPCMS = new TGraphErrors(n,rts,csWP,ex,errWP);
  grWPCMS->SetTitle("CMS WP");
  grWPCMS->SetMarkerColor(2);
  grWPCMS->SetLineWidth(2);
  grWPCMS->SetLineColor(2);
  grWPCMS->SetMarkerStyle(20);
   
  grWNCMS = new TGraphErrors(n,rts,csWN,ex,errWN);
  grWNCMS->SetTitle("CMS WN");
  grWNCMS->SetMarkerColor(2);
  grWNCMS->SetLineWidth(2);
  grWNCMS->SetLineColor(2);
  grWNCMS->SetMarkerStyle(20);
   
  //
  // ATLAS   
  // http://cdsweb.cern.ch/record/1338570
  //
 
  lum_unc = 0.034;

  rts[0] = posAtlas;
  if (plotATLAS) {rts[0] -= 0.2;} // offset needed to see points
  //
  ex[0] = 0.001;
  csW[0] =  10391.;
  stat   =   22.;
  syst   =   238;
  acc    =   312;
  lum    =  lum_unc * csW[0] ;
  errW[0] = sqrt( stat*stat + syst*syst + acc* acc + theo*theo + lum*lum );
  //
  csZ[0] = 945.0;
  stat =    6.;
  syst =    11.;
  acc = 38;
  lum  =    lum_unc * csZ[0];
  errZ[0] = sqrt( stat*stat + syst*syst + acc*acc + theo*theo + lum*lum );
  //
  RWZ[0] = 10.906;
  stat = 0.079;
  syst = 0.215;
  acc = 0.164;
  errR[0] = sqrt( stat*stat + syst*syst + acc*acc + theo*theo);
  //
  csWP[0] = 6257.;
  stat =     17.;
  syst =     152.;
  acc  =     188;
  lum  =     lum_unc * csWP[0];
  errWP[0] = sqrt( stat*stat + syst*syst + acc*acc + theo*theo + lum*lum );
  //
  csWN[0] = 4149.;
  stat =     14.;
  syst =     102.;
  acc =       124;
  lum  =     lum_unc * csWN[0];
  errWN[0] = sqrt( stat*stat + syst*syst + acc*acc + theo*theo + lum*lum );

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
  grWATLAS->SetMarkerColor(kGreen+2);
  grWATLAS->SetLineWidth(2);
  grWATLAS->SetLineColor(kGreen+2);
  grWATLAS->SetMarkerStyle(20);
   
  grZATLAS = new TGraphErrors(n,rts,csZ,ex,errZ);
  grZATLAS->SetTitle("ATLAS Z");
  grZATLAS->SetMarkerColor(kGreen+2);
  grZATLAS->SetLineWidth(2);
  grZATLAS->SetLineColor(kGreen+2);
  grZATLAS->SetMarkerStyle(20);

  grWPATLAS = new TGraphErrors(n,rts,csWP,ex,errWP);
  grWPATLAS->SetTitle("ATLAS WP");
  grWPATLAS->SetMarkerColor(kGreen+2);
  grWPATLAS->SetLineWidth(2);
  grWPATLAS->SetLineColor(kGreen+2);
  grWPATLAS->SetMarkerStyle(20);
   
  grWNATLAS = new TGraphErrors(n,rts,csWN,ex,errWN);
  grWNATLAS->SetTitle("ATLAS WN");
  grWNATLAS->SetMarkerColor(kGreen+2);
  grWNATLAS->SetLineWidth(2);
  grWNATLAS->SetLineColor(kGreen+2);
  grWNATLAS->SetMarkerStyle(20);


  //====================================================
  // make the plot
  //====================================================

  grWCMS->DrawClone("P");
  grWPCMS->DrawClone("P");
  grWNCMS->DrawClone("P");
  if (plotATLAS) {
  grWATLAS->DrawClone("P");
  grWPATLAS->DrawClone("P");
  grWNATLAS->DrawClone("P");
  }


  grZCMS->DrawClone("P");
  if (plotATLAS) {
  grZATLAS->DrawClone("P");
  }

}

void
drawBand( float _xmin, float _xmax, float _ymin, float _ymax,
	  int color1, int color2, int lw, int fs, const char* opt )
{
  Double_t xx_[5] = { _xmin, _xmax, _xmax, _xmin, _xmin };
  Double_t yy_[5] = { _ymin, _ymin, _ymax, _ymax, _ymin };
  TPolyLine* pl_ = new TPolyLine( 5, xx_, yy_ );
  pl_->SetFillStyle(fs);
  pl_->SetFillColor(color1);
  pl_->SetLineWidth(lw);
  pl_->SetLineColor(color2);
  pl_->DrawClone(opt);

}


void 
abLabel( const char* label, float posx, float posy, float size )
{
  TLatex latex;
  latex.SetNDC();
  latex.SetTextSize(size);

  latex.SetTextAlign(31); // align right
  //  latex.DrawLatex(0.90,0.96,"#sqrt{s} = 7 TeV");
  latex.DrawLatex(posx,posy,label);
} 
