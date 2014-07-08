#include <iostream>
#include <stdlib.h>
#include <cassert>
#include <vector>
#include <map>

#include "TFile.h"
#include "TH1F.h"
#include "TString.h"
#include "THStack.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TStyle.h"
#include "TPad.h"
#include "TCanvas.h"
#include "TArrow.h"
#include "TGraphAsymmErrors.h"
#include "TGaxis.h"
#include "RooHist.h"

bool use_chi = true;
bool useArrow = true;

TCanvas* WmunuOthers( int iV=0 )
{
  TGaxis::SetMaxDigits(3);
  double intLumi(36);

  // channels, ordered as in the legend
  vector<TString> channels;  
  vector<TString> hnames;
  vector<TString> type;

  map<TString,int> fillColor_;
  map<TString,int> lineColor_;
  int lineWidth1(2);
  int lineWidth2(1);

  bool salamanderStyle=true; 
  if( salamanderStyle )
    {
      lineWidth1 = 2;
      lineWidth2 = 1;

      fillColor_["Signal"] = kOrange-2;
      lineColor_["Signal"] = kOrange+3;
      
      fillColor_["EWK"] = kOrange+7;
      lineColor_["EWK"] = kOrange+3;
      
      fillColor_["QCD"] = kViolet-5;
      lineColor_["QCD"] = kViolet+3;
      
      fillColor_["ttbar"] = kRed+2;
      lineColor_["ttbar"] = kRed+4;
      
      fillColor_["gamma+jet"] = kMagenta+4;
      lineColor_["gamma+jet"] = kViolet+3;
    }
  else
    {
      lineWidth1 = 2;
      lineWidth2 = 2;

      fillColor_["Signal"] = kPink+6;
      lineColor_["Signal"] = kMagenta+3;
      
      fillColor_["EWK"] = kAzure+8;
      lineColor_["EWK"] = kAzure+4;
      
      fillColor_["QCD"] = kYellow-7;
      lineColor_["QCD"] = kYellow+4;
      
      fillColor_["ttbar"] = kGreen;
      lineColor_["ttbar"] = kGreen+2;
      
      fillColor_["gamma+jet"] = kOrange;
      lineColor_["gamma+jet"] = kOrange+2;
    }

  // log scale?
  bool logScaleY=false;
  bool logScaleX=false;


  // rebin?
  int rb = 1; 

  // histogram limits, in linear and logarithmic
  int nbin_(0);
  float xmin_(0.), xmax_(0.); 
  float ymin_(0.), ymax_(0.); 
  float yminl_(0.), ymaxl_(0.); 
   // arrows
   float xmin_ar_(0.);
   float xmax_ar_(0.);
   float ymin_ar_(0.);
   float ymax_ar_(0.);
   float arr_size_(0.);


   float xmin_box(0.);
   float xmax_box(0.);
   float ymin_box(0.);
   float ymax_box(0.);

   // Line

   float xmin_line_(0.);
   float xmax_line_(0.);
   float ymin_line_(0.);
   float ymax_line_(0.);


  // titles and axis, marker size
  TString xtitle;
  TString ytitle;
  int ndivx(510);
  int ndivy(510);
  float markerSize(1.);
  float titleOffsetY(1.00);
  float titleOffsetX(1.00);

  float r0_ = 1.;
  float dr_ = 0.3;
  if( use_chi )
    {
      r0_ = 0.;
      dr_ = 7.5;
    }

  // canvas name
  TString cname;
  TString ctitle;

  // legend position and scale;
  float xl_  = 0.;
  float yl_  = 0.;
  float scalel_ = 0.075;

  // root file, where the data is
  //  TString fname("../Results/");
  TString fname = "./Wmunu_Fit_pfMet";
  TString dataHistName("data");
  double factor;
  // ***
  // Only the following is specific 
  if( iV==6 || iV==7 || iV==20 || iV ==22 || iV==21 || iV==23)
    {  
      if( iV==6 || iV==20 || iV==22)
	{
	  // MET plots in linear scale (inclusive)
	  if(iV==20) fname = "../Results/Wmunu_PLUS_pfMet";
	  else if(iV==22) fname = "../Results/Wmunu_MINUS_pfMet";
	  logScaleY = false;
	  
	  ctitle = "W to mu-nu analysis - MET linear scale";
	  
	  dataHistName = "DataMET";
	  
	  channels.push_back("WTemplateMET"); 
	  if(iV==6) {cname="Wmn_MET";hnames.push_back("MC W #rightarrow #mu#nu"); factor=1;}
	  else if(iV==20) {cname="Wmn_MET_plus";hnames.push_back("MC W^{+} #rightarrow #mu^{+}#nu"); factor=3./5.;}
	  else {cname="Wmn_MET_minus";hnames.push_back("MC W^{-} #rightarrow #mu^{-}#nu");factor=2./5.;}
	  type.push_back("Signal"); 
      

// 	  channels.push_back("NonQCDMET");                  
// 	  hnames.push_back("  EWK+t#bar{t}"); 
// 	  type.push_back("EWK"); 

// 	  channels.push_back("QCDMET");                  
// 	  hnames.push_back("  QCD"); 
// 	  type.push_back("QCD"); 

	  nbin_ = 80;
	  xmin_ = 0.;
	  xmax_ = 80.;

	  xtitle = "#slash{E}_{T} [GeV]";
	  ytitle = "number of events / 2 GeV";
	  ndivx = 506;
	  ndivy = 506;

	  markerSize = 1.1;

	  ymin_ = 0.;
	  xl_ = 0.6;
	  yl_ = 0.53;
	  
	  //ymax_ = 500.*intLumi*factor;
	  if(iV==6) ymax_ = 15e3;
	  else ymax_ = 10e3;
	}
      else if( iV==7 || iV==21 || iV==23)
	{
	  // MET plots in log scale (inclusive)
	  
	  logScaleY = true;
	  if(iV==21) fname = "../Results/Wmunu_PLUS_pfMet";
	  else if(iV==23) fname = "../Results/Wmunu_MINUS_pfMet";
	  
	  ctitle = "W to mu-nu analysis - MET log scale";

	  dataHistName = "DataMET";

	  channels.push_back("WTemplateMET"); 
	  if(iV==7) {cname="Wmn_MET";hnames.push_back("  W #rightarrow #mu#nu");}
	  else if(iV==21) {cname="Wmn_MET_plus";hnames.push_back("  W^{+} #rightarrow #mu^{+}#nu");}
	  else {cname="Wmn_MET_minus";hnames.push_back("  W^{-} #rightarrow #mu^{-}#nu");}
	  type.push_back("Signal"); 
      
// 	  channels.push_back("EWKMET");                  
// 	  hnames.push_back("  EWK"); 
// 	  type.push_back("EWK"); 

// 	  channels.push_back("TTbar_MCMET");                  
// 	  hnames.push_back("  t#bar{t}"); 
// 	  type.push_back("ttbar"); 
	  
// 	  channels.push_back("QCDMET");                  
// 	  hnames.push_back("  QCD"); 
// 	  type.push_back("QCD"); 

	  nbin_ = 200;
	  xmin_ = 0.;
	  xmax_ = 200.;

	  xtitle = "#slash{E}_{T} [GeV]";
	  ytitle = "number of events / 2 GeV";
	  ndivx = 506;
	  ndivy = 506;

	  markerSize = 0.9;

	  yminl_ = 0.05;
	  ymaxl_ = 2000.*intLumi;
	  xl_ = 0.6;
	  yl_ = 0.43;
	  
	}
    }
  else if( iV==8 || iV==9 )
    {
      if( iV==8 )
	{cname="pt";
	  // pT plots in linear scale (inclusive)
	  
	  logScaleY = false;
	  
	  ctitle = "W to mu-nu analysis - pT linear scale";

	  dataHistName = "DataPT";

	  channels.push_back("WTemplatePT"); 
	  hnames.push_back("MC W #rightarrow #mu#nu"); 
	  type.push_back("Signal"); 
      
// 	  channels.push_back("NonQCDPT");                  
// 	  hnames.push_back("  EWK+t#bar{t}"); 
// 	  type.push_back("EWK"); 

// 	  channels.push_back("QCDPT");                  
// 	  hnames.push_back("  QCD"); 
// 	  type.push_back("QCD"); 

	  nbin_ = 60;
	  xmin_ = 20.;
	  xmax_ = 80.;

	  xtitle = "p_{T}(#mu) [GeV]";
	  ytitle = "number of events / 2 GeV";
	  ndivx = 506;
	  ndivy = 506;

	  markerSize = 1.1;

	  ymin_ = 0.;
	  ymax_ = 500.*intLumi;
	  xl_ = 0.6;
	  yl_ = 0.53;

	}
      else if( iV==9 )
	{cname="pt";
	  // pT plots in log scale (inclusive)

	  logScaleY = true;

	  ctitle = "W to mu-nu analysis - pT log scale";

	  dataHistName = "DataPT";

	  channels.push_back("WTemplatePT"); 
	  hnames.push_back("MC W #rightarrow #mu#nu"); 
	  type.push_back("Signal"); 
      
// 	  channels.push_back("EWKPT");                  
// 	  hnames.push_back("  EWK"); 
// 	  type.push_back("EWK"); 

// 	  channels.push_back("TTbar_MCPT");                  
// 	  hnames.push_back("  t#bar{t}"); 
// 	  type.push_back("ttbar"); 

// 	  channels.push_back("QCDPT");                  
// 	  hnames.push_back("  QCD"); 
// 	  type.push_back("QCD"); 

	  nbin_ = 80;
	  xmin_ = 20.;
	  xmax_ = 100.;

	  xtitle = "p_{T}(#mu) [GeV]";
	  ytitle = "number of events / 2 GeV";
	  ndivx = 506;
	  ndivy = 506;

	  markerSize = 0.9;

	  yminl_ = 0.1;
	  ymaxl_ = 30000.*intLumi;
	  xl_ = 0.6;
	  yl_ = 0.45;

	}
    }
  else if( iV==13 || iV==14 )
    {
      if( iV==13 )
	{cname="ptw";
	  // pT plots in linear scale (inclusive)

	  logScaleY = false;

	  ctitle = "W to mu-nu analysis - W pT linear scale";

	  dataHistName = "DataPTW";

	  channels.push_back("WTemplatePTW"); 
	  hnames.push_back("MC W #rightarrow #mu#nu"); 
	  type.push_back("Signal"); 
      
// 	  channels.push_back("NonQCDPTW");                  
// 	  hnames.push_back("  EWK+t#bar{t}"); 
// 	  type.push_back("EWK"); 

// 	  channels.push_back("QCDPTW");                  
// 	  hnames.push_back("  QCD"); 
// 	  type.push_back("QCD"); 

	  nbin_ = 80;
	  xmin_ = 0.;
	  xmax_ = 80.;

	  xtitle = "p_{T}(W) [GeV]";
	  ytitle = "number of events / 2 GeV";
	  ndivx = 506;
	  ndivy = 506;

	  markerSize = 1.1;

	  ymin_ = 0.;
	  ymax_ = 500.*intLumi;
	  xl_ = 0.6;
	  yl_ = 0.53;

	}
      else if( iV==14 )
	{cname="ptw";
	  // pT plots in log scale (inclusive)
	  
	  logScaleY = true;

	  ctitle = "W to mu-nu analysis - pT log scale";

	  dataHistName = "DataPTW";

	  channels.push_back("WTemplatePTW"); 
	  hnames.push_back("MC W #rightarrow #mu#nu"); 
	  type.push_back("Signal"); 
      
// 	  channels.push_back("EWKPTW");                  
// 	  hnames.push_back("  EWK"); 
// 	  type.push_back("EWK"); 

// 	  channels.push_back("TTbar_MCPTW");                  
// 	  hnames.push_back("  t#bar{t}"); 
// 	  type.push_back("ttbar"); 

// 	  channels.push_back("QCDPTW");                  
// 	  hnames.push_back("  QCD"); 
// 	  type.push_back("QCD"); 

	  nbin_ = 100;
	  xmin_ = 0.;
	  xmax_ = 100.;

	  xtitle = "p_{T}(W) [GeV]";
	  ytitle = "number of events / 2 GeV";
	  ndivx = 506;
	  ndivy = 506;

	  markerSize = 0.9;

	  yminl_ = 0.1;
	  ymaxl_ = 45000.*intLumi;
	  xl_ = 0.6;
	  yl_ = 0.48;
	  
	}
    }
  else if( iV==10 || iV==11 || iV==12 )
    {
      if( iV==10 )
	{cname="iso";
	  // isolation plot in linear scale 
	  
	  logScaleY = false;

	  ctitle = "W to mu-nu analysis - isolation, linear scale";

	  dataHistName = "DataISO";

	  channels.push_back("WTemplateISO"); 
	  hnames.push_back("MC W #rightarrow #mu#nu"); 
	  type.push_back("Signal"); 
      
// 	  channels.push_back("NonQCDISO");                  
// 	  hnames.push_back("  EWK+t#bar{t}"); 
// 	  type.push_back("EWK"); 

// 	  channels.push_back("QCDISO");                  
// 	  hnames.push_back("  QCD"); 
// 	  type.push_back("QCD"); 

	  nbin_ = 25;
	  xmin_ = 0.;
	  xmax_ = 0.5;

	  xtitle = "I^{rel}_{comb}";
	  ytitle = "number of events";
      //ytitle = "CMS preliminary";
	  ndivx = 506;
	  ndivy = 506;

	  markerSize = 1.1;

	  titleOffsetY = 1.5;

	  ymin_ = 0.;
	  ymax_ = 5000.*intLumi;
	  xl_ = 0.6;
	  yl_ = 0.53;

	}
      else if( iV==11 )
	{cname="iso";
	  // isolation plot in log scale 
	  
	  logScaleY = true;

	  ctitle = "W to mu-nu analysis - isolation, log scale";

	  dataHistName = "DataISO";

	  channels.push_back("WTemplateISO"); 
	  hnames.push_back("MC W #rightarrow #mu#nu"); 
	  type.push_back("Signal"); 
      
// 	  channels.push_back("EWKISO");                  
// 	  hnames.push_back("  EWK"); 
// 	  type.push_back("EWK"); 

// 	  channels.push_back("TTbar_MCISO");                  
// 	  hnames.push_back("  t#bar{t}"); 
// 	  type.push_back("ttbar"); 

// 	  channels.push_back("QCDISO");                  
// 	  hnames.push_back("  QCD"); 
// 	  type.push_back("QCD"); 

	  nbin_ = 25;
	  xmin_ = 0.;
	  xmax_ = 0.5;

	  xtitle = "I^{rel}_{comb}";
	  ytitle = "number of events";
      //ytitle = "CMS preliminary";
	  ndivx = 506;
	  ndivy = 506;

	  markerSize = 0.9;

	  yminl_ = 50;
	  ymaxl_ = 30000.*intLumi;
	  xl_ = 0.6;
	  yl_ = 0.45;

	}
      else if( iV==12 )
	{cname="iso2";
	  // isolation plot in log scale 
	  
	  logScaleX = true;
	  logScaleY = true;

	  ctitle = "W to mu-nu analysis - isolation, log scale";
	  dataHistName = "DataISO";

	  channels.push_back("WTemplateISO"); 
	  hnames.push_back("MC W #rightarrow #mu#nu"); 
	  type.push_back("Signal"); 
      
// 	  channels.push_back("EWKISO");                  
// 	  hnames.push_back("  EWK"); 
// 	  type.push_back("EWK"); 

// 	  channels.push_back("TTbar_MCISO");                  
// 	  hnames.push_back("  t#bar{t}"); 
// 	  type.push_back("ttbar"); 

// 	  channels.push_back("QCDISO");                  
// 	  hnames.push_back("  QCD"); 
// 	  type.push_back("QCD"); 
	  
	  nbin_ = 200;
	  xmin_ = 0.;
	  xmax_ = 0.5;
	  
	  xtitle = "I^{rel}_{comb}";
	  ytitle = "number of events";
	  ndivx = 506;
	  ndivy = 506;
	  
	  markerSize = 0.9;
	  
	  yminl_ = 1;
	  ymaxl_ = 4000000.*intLumi;
	  xl_ = 0.6;
	  yl_ = 0.45;
	  
	}
      
      
      
    }
  else if( iV==15 )
    {cname="acop";
      // pT plots in linear scale (inclusive)
      
      logScaleY = false;
      
      ctitle = "W to mu-nu analysis - acop linear scale";
      
      dataHistName = "DataACOP";
      
      channels.push_back("WTemplateACOP"); 
      hnames.push_back("MC W #rightarrow #mu#nu"); 
      type.push_back("Signal"); 
      
  //     channels.push_back("NonQCDACOP");                  
//       hnames.push_back("  EWK+t#bar{t}"); 
//       type.push_back("EWK"); 
      
//       channels.push_back("QCDACOP");                  
//       hnames.push_back("  QCD"); 
//       type.push_back("QCD"); 
      
      nbin_ = 60;
      xmin_ = 0;
      xmax_ = 3.14;
      
      xtitle = "acop";
      ytitle = "number of events";
      ndivx = 506;
      ndivy = 506;
      
      markerSize = 1.1;
      
      ymin_ = 0.;
      ymax_ = 400.*intLumi;
      xl_ = 0.6;
      yl_ = 0.53;
      
    }
  else if( iV==16 )
    {cname="eta";
      
      // pT plots in linear scale (inclusive)
      
      logScaleY = false;
      
      ctitle = "W to mu-nu analysis - eta linear scale";
      
      dataHistName = "DataETA";
      
      channels.push_back("WTemplateETA"); 
      hnames.push_back("MC W #rightarrow #mu#nu"); 
      type.push_back("Signal"); 
      
 //      channels.push_back("NonQCDETA");                  
//       hnames.push_back("  EWK+t#bar{t}"); 
//       type.push_back("EWK"); 
      
//       channels.push_back("QCDETA");                  
//       hnames.push_back("  QCD"); 
//       type.push_back("QCD"); 
      
//    nbin_ = 60;
//    xmin_ = -3;
//    xmax_ = 3;
      
      nbin_ = 70;
      xmin_ = -2.1;
      xmax_ = 2.1;

//    xtitle = "eta";
      xtitle = "#eta(#mu)";
      ytitle = "number of events";
      ndivx = 506;
      ndivy = 506;
      
      markerSize = 1.1;
      
      ymin_ = 0.;
      ymax_ = 120.*intLumi;
      xl_ = 0.25;
      yl_ = 0.63;
      
    }
  else if( iV==17 )
    {cname="ptw_minus";
      fname = "../Results/Wmunu_MINUS_pfMet";
      // pT plots in linear scale (inclusive)
      
      logScaleY = false;
      
      ctitle = "W to mu-nu analysis - eta linear scale";
      
      dataHistName = "DataPTW";
      
      channels.push_back("WTemplatePTW"); 
      hnames.push_back("MC W^{-} #rightarrow #mu^{-}#nu"); 
      type.push_back("Signal"); 
      
 //      channels.push_back("NonQCDPTW");                  
//       hnames.push_back("  EWK+t#bar{t}"); 
//       type.push_back("EWK"); 
      
//       channels.push_back("QCDPTW");                  
//       hnames.push_back("  QCD"); 
//       type.push_back("QCD"); 
      
      nbin_ = 100;
      xmin_ = 0;
      xmax_ = 100;
      
      xtitle = "W pt (GeV)";
      ytitle = "number of events / 2 GeV";
      ndivx = 506;
      ndivy = 506;
      
      markerSize = 1.1;
      
      ymin_ = 0.;
      ymax_ = 200.*intLumi;
      xl_ = 0.6;
      yl_ = 0.53;
      
    }
  else if( iV==18 )
    {cname="ptw_plus";
      fname = "../Results/Wmunu_PLUS_pfMet";
      // pT plots in linear scale (inclusive)
      
      logScaleY = false;
      
      ctitle = "W to mu-nu analysis - eta linear scale";
      
      dataHistName = "DataPTW";
      
      channels.push_back("WTemplatePTW"); 
      hnames.push_back("MC W^{+} #rightarrow #mu^{+}#nu"); 
      type.push_back("Signal"); 
      
 //      channels.push_back("NonQCDPTW");                  
//       hnames.push_back("  EWK+t#bar{t}"); 
//       type.push_back("EWK"); 
      
//       channels.push_back("QCDPTW");                  
//       hnames.push_back("  QCD"); 
//       type.push_back("QCD"); 
      
      nbin_ = 100;
      xmin_ = 0;
      xmax_ = 100;
      
      xtitle = "W pt (GeV)";
      ytitle = "number of events / 2 GeV";
      ndivx = 506;
      ndivy = 506;
      
      markerSize = 1.1;
      
      ymin_ = 0.;
      ymax_ = 300.*intLumi;
      xl_ = 0.6;
      yl_ = 0.53;
      
    }
  else if( iV==19 )
    {cname="phi";
      //fname = "../Results/Wmunu__pfMet.root";
      // pT plots in linear scale (inclusive)
      
      logScaleY = false;
      
      ctitle = "W to mu-nu analysis - phi linear scale";
      
      dataHistName = "DataPHI";
      
      channels.push_back("WTemplatePHI"); 
      hnames.push_back("MC W #rightarrow #mu#nu"); 
      type.push_back("Signal"); 
      
 //      channels.push_back("NonQCDPHI");                  
//       hnames.push_back("  EWK+t#bar{t}"); 
//       type.push_back("EWK"); 
      
//       channels.push_back("QCDPHI");                  
//       hnames.push_back("  QCD"); 
//       type.push_back("QCD"); 
      
      nbin_ = 60;
      xmin_ = -3.5;
      xmax_ = 3.5;
      
      xtitle = "Phi";
      ytitle = "number of events";
      ndivx = 506;
      ndivy = 506;
      
      markerSize = 1.1;
      
      ymin_ = 0.;
      ymax_ = 100.*intLumi;
      xl_ = 0.25;
      yl_ = 0.63;
      
    }
  else if( iV==31 )
    {cname="dxy";
      //fname = "../Results/Wmunu__pfMet.root";
      // pT plots in linear scale (inclusive)
      
      logScaleY = true;
      
      ctitle = "W to mu-nu analysis - dxy linear scale";
      
      dataHistName = "Datadxy";
      
      channels.push_back("WTemplatedxy"); 
      hnames.push_back("MC W #rightarrow #mu#nu"); 
      type.push_back("Signal"); 
      
   //    channels.push_back("NonQCDdxy");                  
//       hnames.push_back("  EWK+t#bar{t}"); 
//       type.push_back("EWK"); 
      
//       channels.push_back("QCDdxy");                  
//       hnames.push_back("  QCD"); 
//       type.push_back("QCD"); 
      
      nbin_ = 20;
      xmin_ = 0.;
      xmax_ = 1.;
      
      xtitle = "d_{xy} [cm]";
      ytitle = "number of events/0.05 cm";
      ndivx = 506;
      ndivy = 506;
      
      markerSize = 1.2;
      
      titleOffsetY = 1.5;

      ymin_ = 0.;
      ymax_ = 180000.;
      xl_ = 0.57;
      yl_ = 0.64;

      yminl_ = 0.1;
      ymaxl_ = 300000.;

      
      xmin_ar_ = 0.2;
      xmin_box = xmin_ar_;
      xmax_box = xmin_box -0.04;
      ymin_box = 100;
      ymax_box = 2000;

      xmax_ar_ = xmin_ar_ +(xmax_box - xmin_box)*2;
      ymin_ar_ = exp((log(ymin_box) + log(ymax_box))/2.);
      ymax_ar_ = ymin_ar_;
      arr_size_ = 0.025;

      xmin_line_ = 0.;
      xmax_line_ = 1.;
      ymin_line_ = 3.;
      ymax_line_ = 3.;
    }
  else if( iV==32 )
    {cname="chi2";
      //fname = "../Results/Wmunu__pfMet.root";
      // pT plots in linear scale (inclusive)
      
      logScaleY = true;
      
      ctitle = "W to mu-nu analysis - chi2 linear scale";
      
      dataHistName = "Datachi2";
      
      channels.push_back("WTemplatechi2"); 
      hnames.push_back("MC W #rightarrow #mu#nu"); 
      type.push_back("Signal"); 
      
   //    channels.push_back("NonQCDchi2");                  
//       hnames.push_back("  EWK+t#bar{t}"); 
//       type.push_back("EWK"); 
      
//       channels.push_back("QCDchi2");                  
//       hnames.push_back("  QCD"); 
//       type.push_back("QCD"); 
      
      nbin_ = 25;
      xmin_ = 0.;
      xmax_ = 25.;
      
      xtitle = "#chi^{2}/ndof";
      ytitle = "number of events";
      ndivx = 506;
      ndivy = 506;
      
      markerSize = 1.1;

      titleOffsetY = 1.5;
      
      ymin_ = 0.;
      ymax_ = 150000.;
      xl_ = 0.57;
      yl_ = 0.64;
      yminl_ = 1.;
      ymaxl_ = 200000.;
      

      xmin_ar_ = 10;
      xmin_box = xmin_ar_;
      xmax_box = xmin_box -1;
      ymin_box = 300;
      ymax_box = 3000;

      xmax_ar_ = xmin_ar_ +(xmax_box - xmin_box)*2;
      ymin_ar_ = exp((log(ymin_box) + log(ymax_box))/2.);
      ymax_ar_ = ymin_ar_;
      arr_size_ = 0.025;

      
    }
  else if( iV==33 )
    {cname="ntkhits";
      //fname = "../Results/Wmunu__pfMet.root";
      // pT plots in linear scale (inclusive)
      
      logScaleY = false;
      
      ctitle = "W to mu-nu analysis - ntk linear scale";
      
      dataHistName = "DataNTRACKER";
      
      channels.push_back("WTemplateNTRACKER"); 
      hnames.push_back("MC W #rightarrow #mu#nu"); 
      type.push_back("Signal"); 
      
  //     channels.push_back("NonQCDNTRACKER");                  
//       hnames.push_back("  EWK+t#bar{t}"); 
//       type.push_back("EWK"); 
      
//       channels.push_back("QCDNTRACKER");                  
//       hnames.push_back("  QCD"); 
//       type.push_back("QCD"); 
      
      nbin_ = 25;
      xmin_ = 5. - 0.5;
      xmax_ = 30. -0.5;
      
      xtitle = "number of tracker hits";
      ytitle = "number of events";
      ndivx = 506;
      ndivy = 506;
      
      markerSize = 1.1;
      
      titleOffsetY = 1.5;


      ymin_ = 0.;
      ymax_ = 35000.;
      xl_ = 0.17;
      yl_ = 0.64;

      xmin_ar_ = 10.5;
      xmin_box = xmin_ar_;
      xmax_box = xmin_box +1;
      ymin_box = 8000;
      ymax_box = 15000;

      xmax_ar_ = xmin_ar_ +(xmax_box - xmin_box)*2;
      ymin_ar_ = (ymin_box + ymax_box)/2.;
      ymax_ar_ = ymin_ar_;
      arr_size_ = 0.025;
      
    }
  else if( iV==34 )
    {cname="npixel";
      //fname = "../Results/Wmunu__pfMet.root";
      // pT plots in linear scale (inclusive)
      TGaxis::SetMaxDigits(4);
      logScaleY = false;
      
      ctitle = "W to mu-nu analysis - npixel linear scale";
      
      dataHistName = "DataNPIXEL";
      
      channels.push_back("WTemplateNPIXEL"); 
      hnames.push_back("MC W #rightarrow #mu#nu"); 
      type.push_back("Signal"); 
      
  //     channels.push_back("NonQCDNPIXEL");                  
//       hnames.push_back("  EWK+t#bar{t}"); 
//       type.push_back("EWK"); 
      
//       channels.push_back("QCDNPIXEL");                  
//       hnames.push_back("  QCD"); 
//       type.push_back("QCD"); 
      
      nbin_ = 8;
      xmin_ = 0. - 0.5;
      xmax_ = 8. - 0.5;
      
      xtitle = "number of pixel hits";
      ytitle = "number of events";
      ndivx = 506;
      ndivy = 506;
      
      markerSize = 1.2;

      titleOffsetY = 1.5;
      
      ymin_ = 0.;
      ymax_ = 135000.;
      xl_ = 0.57;
      yl_ = 0.64;

      xmin_ar_ = 0.5;
      xmin_box = xmin_ar_;
      xmax_box = xmin_box +0.4;
      ymin_box = 30000;
      ymax_box = 60000;

      xmax_ar_ = xmin_ar_ +(xmax_box - xmin_box)*2;
      ymin_ar_ = (ymin_box + ymax_box)/2.;
      ymax_ar_ = ymin_ar_;
      arr_size_ = 0.025;

    }
  else if( iV==35 )
    {cname="nmuons";
      //fname = "../Results/Wmunu__pfMet.root";
      // pT plots in linear scale (inclusive)
      
      logScaleY = false;
      
      ctitle = "W to mu-nu analysis - nmuons linear scale";
      
      dataHistName = "DataNMUONS";
      
      channels.push_back("WTemplateNMUONS"); 
      hnames.push_back("MC W #rightarrow #mu#nu"); 
      type.push_back("Signal"); 
      
   //    channels.push_back("NonQCDNMUONS");                  
//       hnames.push_back("  EWK+t#bar{t}"); 
//       type.push_back("EWK"); 
      
//       channels.push_back("QCDNMUONS");                  
//       hnames.push_back("  QCD"); 
//       type.push_back("QCD"); 
      
      nbin_ = 60;
      xmin_ = 0.  - 0.5;
      xmax_ = 60. - 0.5;
      
      xtitle = "number of muon det. hits";
      ytitle = "number of events";
      ndivx = 506;
      ndivy = 506;
      
      titleOffsetY = 1.5;

      markerSize = 1.1;
      
      ymin_ = 0.;
      ymax_ = 13000.;
      xl_ = 0.57;
      yl_ = 0.64;
 
      xmin_ar_ = 0.5;
      xmin_box = xmin_ar_;
      xmax_box = xmin_box +3;
      ymin_box = 2000;
      ymax_box = 5000;

      xmax_ar_ = xmin_ar_ +(xmax_box - xmin_box)*2;
      ymin_ar_ = (ymin_box + ymax_box)/2.;
      ymax_ar_ = ymin_ar_;
      arr_size_ = 0.025;

    }
  else if( iV==36 )
    {cname="nmatches";
      //fname = "../Results/Wmunu__pfMet.root";
      // pT plots in linear scale (inclusive)
      
      logScaleY = false;
      
      ctitle = "W to mu-nu analysis - nmatches linear scale";
      
      dataHistName = "DataNMATCHED";
      
      channels.push_back("WTemplateNMATCHED"); 
      hnames.push_back("MC W #rightarrow #mu#nu"); 
      type.push_back("Signal"); 
      
//       channels.push_back("NonQCDNMATCHED");                  
//       hnames.push_back("  EWK+t#bar{t}"); 
//       type.push_back("EWK"); 
      
//       channels.push_back("QCDNMATCHED");                  
//       hnames.push_back("  QCD"); 
//       type.push_back("QCD"); 
      
      nbin_ = 10;
      xmin_ = 0. - 0.5;
      xmax_ = 10. - 0.5;
      
      //      xtitle = "number of muon segments";
      xtitle = "number of muon stations";
      ytitle = "number of events";
      ndivx = 506;
      ndivy = 506;
      
      titleOffsetY = 1.5;


      markerSize = 1.2;
      
      ymin_ = 0.;
      ymax_ = 110000.;
      xl_ = 0.57;
      yl_ = 0.64;
      

      xmin_ar_ = 1.5;
      xmin_box = xmin_ar_;
      xmax_box = xmin_box +0.4;
      ymin_box = 32000;
      ymax_box = 58000;

      xmax_ar_ = xmin_ar_ +(xmax_box - xmin_box)*2;
      ymin_ar_ = (ymin_box + ymax_box)/2.;
      ymax_ar_ = ymin_ar_;
      arr_size_ = 0.025;

    }
   
  int nChan=channels.size();
  
  // open the root file containing histograms and graphs
  fname += ".root";
  TFile* f_ = TFile::Open(fname,"READ");
  
  // the canvas
  if( logScaleY ) cname += "_log";
//else            cname += "_lin";
  TCanvas* c_=new TCanvas(cname,ctitle,300,300,479,510);
  c_->SetLeftMargin(  87./479 );
  c_->SetRightMargin( 42./479 );
  c_->SetTopMargin(  30./510 );
  c_->SetBottomMargin( 80./510 ); 
  c_->SetFillColor(0);
  c_->SetTickx(1);
  c_->SetTicky(1);
  c_->SetFrameFillStyle(0);
  c_->SetFrameLineWidth(2);
  c_->SetFrameBorderMode(0);
  Double_t scale = 4;
  Double_t wbin = 42*scale;
  Double_t left  = 8*scale;
  Double_t right = 5*scale;
  Double_t h1 = 135*scale;
  Double_t h2 = 45*scale;
  Double_t top1 = 15*scale;
  Double_t bot1 = 3*scale;
  Double_t top2 = 3*scale;
  //  Double_t bot1 = 0*scale;
  //  Double_t top2 = 0*scale;
  Double_t bot2 = 80*scale;
  Double_t W = left + wbin + right;
  Double_t H = h1 + h2;
  Double_t s[2] = {1, h1/h2 };
  
  TPad* pad[2];
  pad[0] = new TPad( "top", "top", 
 //    0, h2/H, 1, 1,
       0, 0, 1, 1,
		     kWhite,0,0);
  pad[0]->SetLeftMargin(  left/W );
  pad[0]->SetRightMargin( right/W );
//pad[0]->SetTopMargin(  top1/H );
  pad[0]->SetTopMargin(  top1/h1 );
//pad[0]->SetBottomMargin( bot1/H );
  pad[0]->SetBottomMargin( 0.150 );

  pad[1] = new TPad( "bottom", "bottom", 
		     0, 0, 1, h2/H,
		     kWhite,0,0);
  pad[1]->SetLeftMargin(  left/W );
  pad[1]->SetRightMargin( right/W );
  pad[1]->SetTopMargin(  top2/H );
  pad[1]->SetBottomMargin( bot2/H );
  pad[1]->SetGridy();

  for( int ii=0; ii<2; ii++ )
    {
      pad[ii]->SetFillColor(0);
      pad[ii]->SetTickx(1);
      pad[ii]->SetTicky(1);
      pad[ii]->SetFrameFillStyle(0);
      pad[ii]->SetFrameLineWidth(2);
      pad[ii]->SetFrameBorderMode(0);
      pad[ii]->SetFrameFillStyle(0);
      pad[ii]->SetFrameLineWidth(2);
      pad[ii]->SetFrameBorderMode(0);
    }
  

  // a dummy histogram with the correct x axis
  // Warning: setTDRstyle() must be called before
  cout << nbin_<<endl;
  TH1F* h_= new TH1F( "bidon", "bidon", nbin_, xmin_, xmax_ );
  TAxis* ax_ = h_->GetXaxis();
  TAxis* ay_ = h_->GetYaxis();
  
  ax_->SetTitle(xtitle);
  cout << " title " << xtitle << endl;
  ax_->SetNdivisions(ndivx);
  ax_->SetTitleOffset(titleOffsetX*1.1);
  ax_->SetTitleSize(0.8*ax_->GetTitleSize());
  ax_->CenterTitle(kFALSE);

  ay_->SetTitle(ytitle);
  ay_->CenterTitle(kFALSE);
  ay_->SetNdivisions(ndivy);
  ay_->SetTitleOffset(titleOffsetY);
  ay_->SetTitleSize(0.8*ay_->GetTitleSize());
  ay_->SetLabelOffset(0.015);

  // fetch histograms and dress them
  vector<TH1F*> histos;
  TH1* hdata = (TH1*) f_->Get( dataHistName );  

  for( int ii=0; ii<nChan; ii++ )
    {
      TH1F* tmp1 = (TH1F*)f_->Get(channels[ii]);
      tmp1->Scale(hdata->Integral()/tmp1->Integral());
      double offset = 0.5;
      if(iV==32 || iV == 31) offset = 0;
      TH1F* tmp = new TH1F(tmp1->GetName(), tmp1->GetTitle(), tmp1->GetNbinsX(), tmp1->GetXaxis()->GetXmin()-offset, tmp1->GetXaxis()->GetXmax()-offset);
      for(int i = 1; i <= tmp1->GetNbinsX(); ++i) {
	tmp->SetBinContent(i, tmp1->GetBinContent(i));
      }

      tmp->Rebin(rb);
      tmp->SetStats(kFALSE);
      //      tmp->UseCurrentStyle();
      tmp->SetFillStyle( 1001 );
      tmp->SetFillColor( fillColor_[type[ii]] );
      tmp->SetLineColor( lineColor_[type[ii]] );
      tmp->SetLineWidth( lineWidth2 );
      histos.push_back(tmp);
    }

  TH1* h_sig = (TH1*) histos[0]->Clone();
  h_sig->SetFillStyle(0);
  h_sig->SetLineColor(lineColor_["Signal"]);
  h_sig->SetLineWidth( 2 );
  h_sig->SetLineStyle( kDashed );
  TH1* h_tot = (TH1*) histos[0]->Clone();
  h_tot->SetFillStyle(0);

  //
  // stack histogram
  //
  THStack* stackedHisto=new THStack("stackedHisto","XXX");
  TH1F* totalHisto(0);
  for(int ii=0;ii<nChan;ii++) 
    {
      stackedHisto->Add(histos[nChan-ii-1],"ah");
      
      if(ii==0)
	{
	  totalHisto = (TH1F*)histos[ii]->Clone();
	}
      else
	{
	  totalHisto->Add(histos[ii]);
	}
    }
  
  // colors the stacked histogram
  totalHisto->SetLineColor( lineColor_["Signal"] );
  totalHisto->SetFillColor( 0 );
  totalHisto->SetLineWidth( lineWidth1 );
  
    TLine *line = new TLine(xmin_line_,ymin_line_,xmax_line_,ymax_line_);
    line->SetLineWidth(2);
    line->SetLineStyle(2);
  TArrow * arrow = 0;
  TBox *bbox = 0;
  TLine *lline = 0;
  if(useArrow) {
    arrow = new TArrow(xmin_box,ymax_box,xmin_box,ymin_box,arr_size_,">");    
  } else{
    arrow = new TArrow(xmin_ar_,ymin_ar_,xmax_ar_,ymax_ar_,0.03,">");
    bbox = new TBox(xmin_box, ymin_box, xmax_box, ymax_box);
    bbox->SetFillStyle(3445);
    bbox->SetFillColor(kBlue);
    bbox->SetLineWidth(0);
    gStyle->SetHatchesLineWidth(2);
    float xxl = xmin_box;
    lline = new TLine(xxl,ymin_box,xxl,ymax_box);
    lline->SetLineColor(kBlue);
    lline->SetLineWidth(3);
  }
  arrow->SetLineWidth(3);
  arrow->SetLineColor(kBlue);
  // The data points are presented as a TGraph 
  // possibly a TGraph with asymmetric errors where
  // - error bars indicate the Poisson confidence interval at 68%
  // - bins with zero entry are removed
  //  TGraphAsymmErrors* dataGraph = (TGraphAsymmErrors*)f_->Get("data");
  // The data points are presented as a TGraph 
  // possibly a TGraph with asymmetric errors where
  // - error bars indicate the Poisson confidence interval at 68%
  // - bins with zero entry are removed
  assert( hdata );
  hdata->Rebin(rb);

  RooHist* roohist;
  TGraphAsymmErrors* dataGraph;

  roohist = new RooHist((*hdata));

  int Nn0=0;
  vector<double> vY;
  vector<double> vX;
  vector<double > veY;
  vector<double > veX;
  vector<double> tmp(0,2);

  for(int ip=0;ip<roohist->GetN();ip++) {
    double Y,X;
    //    double eY[2],eX[2];
    roohist->GetPoint(ip,X,Y);

    if(Y!=0) 
      {
	Nn0++;
	
	vY.push_back(Y);
	double offset = 0.5;
	if(iV==32 || iV == 31) offset = 0;
	vX.push_back(X-offset);
	veX.push_back( roohist->GetErrorXlow(ip) );
	veX.push_back( roohist->GetErrorXhigh(ip) );
	veY.push_back( roohist->GetErrorYlow(ip) );
	veY.push_back( roohist->GetErrorYhigh(ip) );
      }
  }
  dataGraph=new TGraphAsymmErrors(Nn0);
  for(int ip=0;ip<Nn0;ip++) 
    {
      dataGraph->SetPoint(ip,vX[ip],vY[ip]);
      dataGraph->SetPointError(ip,veX[ip*2],veX[ip*2+1],veY[ip*2],veY[ip*2+1]);
    }
  
  dataGraph->SetName("data");
  dataGraph->SetMarkerStyle(kFullCircle);
  dataGraph->SetMarkerColor(kBlack);
  dataGraph->SetMarkerSize(markerSize);
  
  TGraph* dummyGraph = (TGraph*) dataGraph->Clone("dummyGraph");
  dummyGraph->SetLineColor(0);
  dummyGraph->SetMarkerSize(1.5*markerSize);

  // Remove the null bins
  double x_(0), y_(0);
  for( int ii=0; ii<dataGraph->GetN(); ii++ )
    {
      dataGraph->SetPointEXlow(ii,0);
      dataGraph->SetPointEXhigh(ii,0);
      dataGraph->GetPoint(ii,x_,y_ );
      if( y_==0 )
	{
	  dataGraph->RemovePoint( ii );
	  ii--;
	}	  
    }

  // get the ratio data/fit
  TGraphAsymmErrors* ratioGraph = (TGraphAsymmErrors*) dataGraph->Clone("ratio");
  TH1* hfit = totalHisto;
  for( int ii=0; ii<dataGraph->GetN(); ii++ )
    {
      dataGraph->GetPoint(ii,x_,y_ );
      ratioGraph->SetPointEYlow(ii,0);
      ratioGraph->SetPointEYhigh(ii,0);
      ratioGraph->SetPoint(ii,x_,0 );
      double eyl_ = dataGraph->GetErrorYlow(ii);
      double eyh_ = dataGraph->GetErrorYhigh(ii);
      int jj = hfit->FindBin(x_);
      float fit_ = hfit->GetBinContent( jj );
      if( fit_>0 )
	{
	  if( use_chi )
	    {
	      ratioGraph->SetPointEYlow(ii,eyl_/sqrt(fit_));
	      ratioGraph->SetPointEYhigh(ii,eyh_/sqrt(fit_));
	      ratioGraph->SetPoint(ii,x_,(y_-fit_)/sqrt(fit_) );
	    }
	  else
	    {
	      ratioGraph->SetPointEYlow(ii,eyl_/fit_);
	      ratioGraph->SetPointEYhigh(ii,eyh_/fit_);
	      ratioGraph->SetPoint(ii,x_,y_/fit_ );
	    }
	}
      //      cout << ii << " ratio=" << ratioGraph->GetY()[ii] 
      //       	   << "+" << ratioGraph->GetEYhigh()[ii] 
      //	   << "-" << ratioGraph->GetEYlow()[ii] << endl;
    }
  
  TH1* hratio_ = (TH1*) h_->Clone("hratio");
//ax_->SetLabelOffset(99);
//ax_->SetTitleOffset(99);

  //
  // now plotting
  //  
  c_->Draw();
  c_->cd();

  TPad* p_ = pad[0];
  p_->Draw();
  p_->cd();

  if( logScaleY )
    {
      p_->SetLogy(true);
      c_->SetLogy(true);
    }
  else
    {
      p_->SetLogy(false);
      c_->SetLogy(false);
    }
  
  if( !logScaleY )
    {
      h_->GetYaxis()->SetRangeUser(ymin_+0.001*(ymax_-ymin_),rb*ymax_);
    }
  else
    {
      h_->GetYaxis()->SetRangeUser(yminl_,rb*ymaxl_);
    }

  h_->Draw("hist");
  
  float dxl_ = scalel_*3.5;
  float dyl_ = scalel_*(nChan+0.5);
  TLegend* legend=new TLegend(xl_,yl_,xl_+dxl_,yl_+dyl_);
  legend->SetTextFont(42);
  legend->SetTextSize(0.045);
  legend->SetLineColor(0);
  legend->SetFillColor(0);
  
  legend->AddEntry(dummyGraph,"  data","pl");
  legend->AddEntry(dummyGraph,"      ","0"); // skip a line

  for( int ii=0; ii<nChan; ii++ ) 
    {
      legend->AddEntry(histos[ii],hnames[ii],"f");
    }
  if(iV==33)
    legend->Draw("same");

  stackedHisto->Draw("samehist");
//h_sig->Draw("samehist");
  totalHisto->Draw("samehist");

  if(useArrow) {
    arrow->Draw("");
  }else{
    arrow->Draw("");
    bbox->Draw();
    lline->Draw();
  }
  if (iV==31) line->Draw("");

  // draw the data points
  dataGraph->Draw("PE");

  // redraw axis
  p_->RedrawAxis();
//c_->RedrawAxis();

  //lumi pad, cms prelim pad etc..
  {
    int txtFont = 42;
    float txtSize1 = 0.055;
    float txtX1 = 0.91;
    float txtY1 = 0.90;

    float txtSize2 = 0.05;
    float txtX2 = 0.85;
    float txtY2 = 0.82;
    
    TLatex latex;
    latex.SetNDC();
    latex.SetTextFont(txtFont);
    
    latex.SetTextSize(txtSize1);    
    latex.SetTextAlign(31); // align right
//  latex.DrawLatex(txtX1,txtY1,"CMS preliminary");
    latex.DrawLatex(txtX1,txtY1,"CMS");

    latex.SetTextAlign(31); // align right
    latex.SetTextSize(txtSize2);
    latex.DrawLatex(txtX2,txtY2,"36 pb^{-1}  at  #sqrt{s} = 7 TeV");
  }

  c_->cd();
/*   
  p_ = pad[1];
  p_->Draw();
  p_->cd();

  TAxis* xratio_ = hratio_->GetXaxis();
  TAxis* yratio_ = hratio_->GetYaxis();

  yratio_->SetRangeUser(r0_-0.9999*dr_,r0_+0.9999*dr_);
  yratio_->SetLabelSize( s[1]*yratio_->GetLabelSize() );
  yratio_->SetTitleSize( s[1]*yratio_->GetTitleSize() );
  yratio_->SetLabelOffset( yratio_->GetLabelOffset() );
  yratio_->SetTitleOffset( yratio_->GetTitleOffset()/s[1] );
  if( use_chi )
    {
      yratio_->SetTitle("#chi");
      yratio_->SetNdivisions(4);
    }
  else
    {
      yratio_->SetTitle("data/fit");
      yratio_->SetNdivisions(3);
    }

  xratio_->SetLabelSize( s[1]*xratio_->GetLabelSize() );
  xratio_->SetTitleSize( s[1]*xratio_->GetTitleSize() );
  xratio_->SetTitleOffset( 1.0 );
  xratio_->CenterTitle();
  xratio_->SetLabelOffset( xratio_->GetLabelOffset()*s[1] );
  xratio_->SetTickLength( xratio_->GetTickLength()*s[1] );

  hratio_->Draw();
  ratioGraph->SetMarkerSize( ratioGraph->GetMarkerSize()*1. );
  ratioGraph->SetLineColor( kBlack );

  ratioGraph->SetMarkerColor( kGray+2 );
  ratioGraph->SetMarkerStyle( kFullCircle );
  ratioGraph->DrawClone("PE");
  ratioGraph->SetMarkerColor( kBlack );
  ratioGraph->SetMarkerStyle( kOpenCircle );
  ratioGraph->DrawClone("PE");
  p_->RedrawAxis();

  c_->cd();
  
*/
  return c_;
}

