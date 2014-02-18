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

TCanvas* Wmunu( int iV=0 )
{
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);

  TGaxis::SetMaxDigits(3);

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

  // rebin?
  int rb = 5; 

  // histogram limits, in linear and logarithmic
  int nbin_(0);
  float xmin_(0.), xmax_(0.); 
  float ymin_(0.), ymax_(0.); 
  float yminl_(0.), ymaxl_(0.); 

  // titles and axis, marker size
  TString xtitle;
  TString ytitle;
  int ndivx(510);
  int ndivy(510);
  float markerSize(1.);
  float titleOffset(1.00);

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
  TString fname("./");
  TString dataHistName("data");

  cout << iV << endl;

  // ***
  // Only the following is specific 
  if( iV>=0 && iV<6 )
    {
      xtitle = "M_{T} [GeV]";
       //	  ytitle = "number of events / 2 GeV";
      ytitle = "number of events / ";
      if( rb==2 ) ytitle += "2";
      else if( rb==4 ) ytitle += "4";
      else if( rb==5 ) ytitle += "5";
      else ytitle += "1";
      ytitle += " GeV";

      fname += "Wmunu";

      dataHistName = "Data";
	  
      channels.push_back("WTemplate"); 
      if( iV==0 || iV==3 )
	{
	  hnames.push_back("  W #rightarrow #mu#nu"); 
	  fname += "_Fit_pfMet";
	  cname = "Wmn_MT";
	}
      else if( iV==1 || iV==4 )
	{
	  hnames.push_back("  W^{+} #rightarrow #mu^{+}#nu");  
	  fname += "_PLUS_pfMet";
	  cname += "Wmn_MT_plus";
	}
      else if( iV==2 || iV==5 )
	{
	  hnames.push_back("  W^{-} #rightarrow #mu^{-}#bar{#nu}");  
	  fname += "_MINUS_pfMet";
	  cname += "Wmn_MT_minus";
	}
      type.push_back("Signal"); 
 
      //      if( rb==2 )       cname += "_b4";
      //      else              cname += "_b2";

      if( iV>=0 && iV<3 )
	{
	  // MT plots in linear scale (0:inclusive, 1:plus, 2:minus)
	  
	  logScaleY = false;
	  
	  ctitle = "W to mu-nu analysis - MT linear scale";
	        
	  channels.push_back("NonQCD");                  
	  hnames.push_back("  EWK+t#bar{t}"); 
	  type.push_back("EWK"); 
	  
	  channels.push_back("QCD");                  
	  hnames.push_back("  QCD"); 
	  type.push_back("QCD"); 
	  
	  nbin_ = 150;
	  xmin_ = 0.;
	  xmax_ = 150.;
	  

	  ndivx = 506;
	  ndivy = 506;
	  
// markerSize = 1.1;
	  markerSize = 1.4;
	  
	  ymin_ = 0.;
	  ymax_ = 5500.;
	  xl_ = 0.20;
	  yl_ = 0.50;
	  
	  if( iV!=0 ) ymax_ = 2500.;

	}
      else if( iV>=3 && iV<6 )
	{
	  // MT plots in log scale (0:inclusive, 1:plus, 2:minus)
	  
	  logScaleY = true;
	  
	  ctitle = "W to mu-nu analysis - MT log scale";
	  
	  dataHistName = "Data";
	  
	  channels.push_back("EWK");                  
	  hnames.push_back("  EWK"); 
	  type.push_back("EWK"); 
	  
	  channels.push_back("TTbar_MC");                  
	  hnames.push_back("  t#bar{t}"); 
	  type.push_back("ttbar"); 
	  
	  channels.push_back("QCD");                  
	  hnames.push_back("  QCD"); 
	  type.push_back("QCD"); 
	  
	  nbin_ = 200;
	  xmin_ = 0.;
	  xmax_ = 200.;
	  
	  //ytitle = "number of events / 2 GeV";
	  ndivx = 506;
	  ndivy = 506;
	  
// markerSize = 0.9;
	  markerSize = 1.0;
	  
	  yminl_ = 0.5;
	  ymaxl_ = 10000.;
	  xl_ = 0.65;
	  yl_ = 0.43;
	  scalel_ = 0.060;	  
	  if( iV!=3 ) ymaxl_ = 30000.;
	}
    }
  

  int nChan=channels.size();
   
  // open the root file containing histograms and graphs
  fname += ".root";
  TFile* f_ = TFile::Open(fname,"READ");
  
  // the canvas
  if( logScaleY ) cname += "_log";

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
		     0, h2/H, 1, 1,
		     kWhite,0,0);
  pad[0]->SetLeftMargin(  left/W );
  pad[0]->SetRightMargin( right/W );
  pad[0]->SetTopMargin(  top1/H );
  pad[0]->SetBottomMargin( bot1/H );

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
  TH1F* h_= new TH1F( "bidon", "bidon", nbin_, xmin_, xmax_ );
  TAxis* ax_ = h_->GetXaxis();
  TAxis* ay_ = h_->GetYaxis();
  
  ax_->SetTitle(xtitle);
  ax_->CenterTitle();
  ax_->SetNdivisions(ndivx);
  ax_->SetTitleOffset(1.0);
  ax_->SetTitleSize( 1.4*ax_->GetTitleSize() );
  ax_->SetLabelSize( 1.2*ax_->GetLabelSize() );

  ay_->SetTitle(ytitle);
  ay_->CenterTitle();
  ay_->SetNdivisions(ndivy);
  /*if(logScaleY) */ titleOffset *=1.1;
  ay_->SetTitleOffset(titleOffset);
  ay_->SetLabelOffset(0.015);
  ay_->SetLabelSize( 1.2*ay_->GetLabelSize() );
  ay_->SetTitleSize( 1.4*ay_->GetTitleSize() );

  // fetch histograms and dress them
  vector<TH1F*> histos;
  for( int ii=0; ii<nChan; ii++ )
    {
      TH1F* tmp = (TH1F*)f_->Get(channels[ii]);
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
  
  // The data points are presented as a TGraph 
  // possibly a TGraph with asymmetric errors where
  // - error bars indicate the Poisson confidence interval at 68%
  // - bins with zero entry are removed
  //  TGraphAsymmErrors* dataGraph = (TGraphAsymmErrors*)f_->Get("data");
  // The data points are presented as a TGraph 
  // possibly a TGraph with asymmetric errors where
  // - error bars indicate the Poisson confidence interval at 68%
  // - bins with zero entry are removed
  TH1* hdata = (TH1*) f_->Get( dataHistName );  
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
	vX.push_back(X);
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
  if(logScaleY) markerSize *= 0.65;
  else markerSize *= 0.7;
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
  ax_->SetLabelOffset(99);
  ax_->SetTitleOffset(99);

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
    }
  else
    {
      p_->SetLogy(false);
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
  legend->Draw("same");

  stackedHisto->Draw("samehist");
  h_sig->Draw("samehist");
  totalHisto->Draw("samehist");

  // draw the data points
  dataGraph->Draw("PE");

  // redraw axis
  p_->RedrawAxis();

  //lumi pad, cms prelim pad etc..
  {
    int txtFont = 42;
    float txtSize1 = 0.055;
    float txtX1 = 0.91;
    float txtY1 = 0.935;

    float txtSize2 = 0.05;
    float txtX2 = 0.85;
    float txtY2 = 0.83;
    
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
//ratioGraph->SetMarkerSize( ratioGraph->GetMarkerSize()*1.0 );
  ratioGraph->SetMarkerSize( ratioGraph->GetMarkerSize()*0.8 );
  ratioGraph->SetLineColor( kBlack );

  ratioGraph->SetMarkerColor( kGray+2 );
  ratioGraph->SetMarkerStyle( kFullCircle );
  ratioGraph->DrawClone("PE");
  ratioGraph->SetMarkerColor( kBlack );
  ratioGraph->SetMarkerStyle( kOpenCircle );
  ratioGraph->DrawClone("PE");

  p_->RedrawAxis();

  c_->cd();

  c_->SaveAs("plot.pdf");
  return c_;
}

