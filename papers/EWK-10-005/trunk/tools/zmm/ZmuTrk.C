#include <iostream>
#include <stdlib.h>
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
#include "TGraphAsymmErrors.h"
#include "TGaxis.h"
#include "RooHist.h"

using namespace std;
bool use_chi = true;



TCanvas* plotting36GT( bool logScale=false ) 
{

  std::cout << "plotting mu + track " << std::endl;
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

  // root file, where the data is
  TString fname("root/");

  // histogram limits, in linear and logarithmic
  int nbin_(100);
  float xmin_(0.), xmax_(0.); 
  float ymin_(0.), ymax_(0.); 
  float yminl_(0.), ymaxl_(0.); 

  // titles and axis, marker size
  TString xtitle;
  TString ytitle;
  int ndivx(510);
  int ndivy(510);
  float markerSize(0.);
  float titleOffset(1.);

  float r0_ = 1.;
  float dr_ = 0.3;
  if( use_chi )
    {
      r0_ = 0.;
      dr_ = 7.5;
      //dr_ = 3.0;
    }

  // canvas name
  TString cname("");
  TString ctitle;

  // legend position and scale;
  float xl_  = 0.;
  float yl_  = 0.; 	   
  float scalel_ = 0.0;

  {
    if( logScale )
      //      fname += "Zmumu_40-200_36pb";
      fname += "Zmutrk_36pb";
    else
      fname += "Zmutrk_36pb";

    if( logScale )
      {
	lineWidth1 = 1;
	lineWidth2 = 1;
      }
    
    channels.push_back("Zmumu"); 
    hnames.push_back("   Z #rightarrow #mu^{+}#mu^{-}"); 
    type.push_back("Signal"); 
    
    bool revert(false);
    if( logScale )
      {
 	if( revert )
 	  {
 	    channels.push_back("EWK");          
 	    hnames.push_back("   EWK");                
	    type.push_back("EWK"); 
	    
 	    channels.push_back("tt");              
 	    hnames.push_back("   t#bar{t}");         
	    type.push_back("ttbar"); 

	     	    channels.push_back("QCD");              
	     	    hnames.push_back("   QCD");              
	    	    type.push_back("QCD"); 
 	  }
 	else
 	  {
 	    channels.push_back("EWK");          
 	    hnames.push_back("   EWK");                
	    type.push_back("EWK"); 
	    
 	    channels.push_back("tt");              
 	    hnames.push_back("   t#bar{t}");         
	    type.push_back("ttbar"); 
	    
	    channels.push_back("QCD");              
	     	    hnames.push_back("   QCD");              
	    	    type.push_back("QCD"); 	  
	      
 	  }
       }
    
    if( !logScale )
      {
	// lin scale
	xmin_ = 60;
	xmax_ = 120;
	ymin_ = 0.01;
	ymax_ = 2100;

  }
    else
      {	
	// log scale
	xmin_ = 40;
	xmax_ = 200;
	yminl_ = 0.08;
	ymaxl_ = 3000;

      }

    xtitle = "M(#mu^{+}#mu^{-})    [GeV]";
    ytitle = "number of events /";    


    ndivx = 504;
    if( logScale )
      {
	ytitle += "4 GeV";
	ndivy = 510;
      }
    else
      {
	ytitle += " GeV";
	ndivy = 506;
      }
    
    if( logScale )
      {
	markerSize = 0.48;
      }
    else
      {	
	markerSize = 0.75;
      }
    
    cname += "Zmutrk";
    ctitle = "Z to trk";
    
    if( logScale )
      {
	xl_ = 0.60;
	yl_ = 0.50;
	scalel_ = 0.065;
      }
    else
      {
	xl_ = 0.22;
	yl_ = 0.50;
	scalel_ = 0.072;
      }
  }

  if( logScale ) cname += "MuTrk_log";
  else           cname += "MuTrkNotInThePAPER_lin";

  //Open the root file containing histograms and graphs
  fname += ".root";
  TFile* f_ = TFile::Open(fname,"READ");

  TCanvas* c_ = new TCanvas(cname,ctitle,300,300,479,510);
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
  ax_->SetTitleOffset(1.0);
  ax_->SetNdivisions(ndivx);

  ay_->SetTitle(ytitle);
  ay_->CenterTitle();
  ay_->SetNdivisions(ndivy);
  ay_->SetTitleOffset(titleOffset);
  ay_->SetLabelOffset(0.015);

  // fetch histograms and dress them
  vector<TH1F*> histos;

  size_t nChan=channels.size();   
  for( size_t ii=0;ii<nChan;ii++)
    {
      TH1F* tmp = (TH1F*)f_->Get(channels[ii]);      
      tmp->SetFillColor( fillColor_[type[ii]] );
      tmp->SetLineColor( lineColor_[type[ii]] );
      tmp->SetLineWidth( lineWidth2 );
      histos.push_back(tmp);
    }

  //
  // stack histograms
  //
  TH1* h_stack = (TH1*) histos[nChan-1]->Clone();
  h_stack -> Reset();

  TString stackName_ = TString("Mll");
  vector<TH1*> listOfStackedHists;
  for( size_t ii=0; ii<nChan; ii++ )
    {
      TH1* hh_ = (TH1*) histos[nChan-ii-1]->Clone();

      stackName_ += "_";
      stackName_ += hh_->GetName();	  	  

      TAxis* xaxis = h_stack->GetXaxis();
      for( int iBin=1; iBin<=xaxis->GetNbins(); iBin++ )
	{
	  hh_ -> AddBinContent( iBin, h_stack->GetBinContent( iBin ) );
	}        

      hh_->SetName( stackName_ );
      delete h_stack;
      h_stack = hh_;
      listOfStackedHists.push_back( (TH1*)hh_->Clone() );
    }
  delete h_stack;
  
  TH1* totalHisto = listOfStackedHists[nChan-1];

  // colors the stacked histogram
  totalHisto->SetLineColor( lineColor_["Signal"] );
  totalHisto->SetLineWidth( lineWidth1 );
  
  // The data points are presented as a TGraph 
  // - error bars indicate the Poisson confidence interval at 68%
  // - bins with zero entry are removed
  TH1* hdata = (TH1*) f_->Get("hdata");
  // hdata->Sumw2();
  //hdata->Rebin(2);
  RooHist* roohist;
  TGraphAsymmErrors* dataGraph;

  roohist = new RooHist((*hdata));

  int Nn0=0;
  vector<double> vY;
  vector<double> vX;
  vector<double > veY;
  vector<double > veX;
  vector<double> tmp(0,2);

  for(int ip=0;ip<roohist->GetN();ip++) 
    {
      double Y,X;
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
  dataGraph->SetMarkerSize(markerSize);

  TGraph* dummyGraph = (TGraph*) dataGraph->Clone("dummyGraph");
  dummyGraph->SetLineColor(0);
  dummyGraph->SetMarkerSize(1.5*markerSize);

  // Remove the horizontal bars (at Michael's request)
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

  if( logScale )
    {
      p_->SetLogy(true);
    }
  else
    {
      p_->SetLogy(false);
    }

  if( !logScale )
    {
      h_->GetYaxis()->SetRangeUser(ymin_+0.001*(ymax_-ymin_),ymax_);
    }
  else
    {
      h_->GetYaxis()->SetRangeUser(yminl_,ymaxl_);
    }

  h_->Draw();

  float dxl_ = scalel_*3.5;
  float dyl_ = scalel_*1.8;
  if( logScale )
    {
      dxl_ = scalel_*4;
      dyl_ = scalel_*3.4;
    }
  TLegend* legend=new TLegend(xl_,yl_,xl_+dxl_,yl_+dyl_);
  legend->SetLineColor(0);
  legend->SetFillColor(0);
  legend->SetTextFont(42);
  legend->SetTextSize(0.048);
  
  legend->AddEntry(dummyGraph,"   data","pl");      
  if( logScale )
    {
      legend->AddEntry(dummyGraph,"       ","0");
    }
  for(size_t ii=0;ii<nChan;ii++) 
    {
      legend->AddEntry(histos[ii],hnames[ii],"f");
    }
  legend->Draw("same");

  totalHisto->Draw("same");

  for( size_t ii=0; ii<nChan; ii++ )
    {
      //  listOfStackedHists[nChan-ii-1]->Sumw2();   
      listOfStackedHists[nChan-ii-1]->Rebin(1.);
      listOfStackedHists[nChan-ii-1]->Scale(1.);
      listOfStackedHists[nChan-ii-1]->Draw("Same");
    }

  // draw the data points
  dataGraph->Draw("PE");

  // redraw axis
  p_->RedrawAxis();

  //lumi pad, cms prelim pad etc..
  {
    int txtFont = 42;  // bold is 62
    float txtSize1 = 0.055;
    float txtX1 = 0.91;
    float txtY1 = 0.935;

    float txtSize2 = 0.05;
    float txtX2 = 0.85;
    float txtY2 = 0.83;
    
    // TEST FOR THE NAME ZMT, ZMMNONISO, ZMS
    float txtSize3 = 0.055;
    float txtX3 = 0.25;
    float txtY3 = 0.935;

    TLatex latex;
    latex.SetNDC();
    latex.SetTextFont(txtFont);
    
    latex.SetTextSize(txtSize1);    
    latex.SetTextAlign(31); // align right
    latex.DrawLatex(txtX1,txtY1,"CMS");

    latex.SetTextAlign(31); // align right
    latex.SetTextSize(txtSize2);
    latex.DrawLatex(txtX2,txtY2,"36 pb^{-1}  at  #sqrt{s} = 7 TeV");

    latex.SetTextAlign(21); // align left???
    latex.SetTextSize(txtSize3);
    latex.DrawLatex(txtX3,txtY3,"global muon plus track");
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

  return c_;
}

