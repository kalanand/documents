#include <iostream>
#include <stdlib.h>
#include <cassert>
#include <vector>
#include <map>

#include "TFile.h"
#include "TH1F.h"
#include "TF1.h"
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
#include "TStyle.h"

bool use_chi = true;

TCanvas* nice_cosmics( )
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

  // log scale?
  bool logScaleY=true;

  // rebin?
  int rb = 1; 

  // histogram limits, in linear and logarithmic
  int nbin_(0);
  float xmin_(0.), xmax_(0.); 
  float ymin_(0.), ymax_(0.); 
  float yminl_(0.), ymaxl_(0.); 

  // titles and axis, marker size
  TString xtitle;
  TString ytitle;
  int ndivx(505);
  int ndivy(506);
  float markerSize(0.8);
  float titleOffset(1.1);

  float r0_ = 1.;
  float dr_ = 0.3;

  // canvas name
  TString cname;
  TString ctitle;

  // legend position and scale;
  float xl_  = 0.;
  float yl_  = 0.;
  float scalel_ = 0.075;
  float par_=0;

// -------------------------------------------------------------

  TFile *my_file = new TFile("saved_histos_cosmics.root");

  TH1D *hdxy = (TH1D*)my_file->Get("dxy");
  TF1 *myfit = new TF1("myfit","[0]");

  TF1 *myfit2 = new TF1("myfit2","[0]",0.,0.2);



// All stuff is ready 

// --------------------------------------------------------------------
  cname = "Wmn_cosmics";
  xtitle = "d_{xy} [cm]";
  ytitle = "number of events/0.05 cm";
 
  nbin_ = 20;
  xmin_ = 0.;
  xmax_ = 1.;

  ymin_ = 0.1;
  ymax_ = 300000.;

  markerSize = 1.2;

  xl_ = 0.5 ;
  yl_ = 0.60;

  TCanvas* c_=new TCanvas(cname,ctitle,300,300,600,450);
  c_->SetLeftMargin(  0.13 );
  c_->SetRightMargin( 0.06 );
  c_->SetTopMargin( 0.05882353); 
  c_->SetBottomMargin( 0.1568628);
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
  
  cout << " hola " << endl;
  // a dummy histogram with the correct x axis
  // Warning: setTDRstyle() must be called before
  TH1F* h_= new TH1F( "bidon", "bidon", nbin_, xmin_, xmax_ );
  TAxis* ax_ = h_->GetXaxis();
  TAxis* ay_ = h_->GetYaxis();
  
  ax_->SetTitle(xtitle);
  //  ax_->CenterTitle();
  ax_->SetNdivisions(ndivx);
  ax_->SetTitleOffset(1.);

  ay_->SetTitle(ytitle);
  //  ay_->CenterTitle();
  ay_->SetNdivisions(ndivy);
  ay_->SetTitleOffset(titleOffset);
  ay_->SetLabelOffset(0.015);

  hdxy->SetLineColor(1);
  hdxy->SetLineWidth(2);
  hdxy->SetMarkerStyle(20);
  hdxy->SetMarkerColor(1);
  hdxy->SetMarkerSize(1.2);
 

  //
  // now plotting
  //  
  c_->SetLogy(true);
  c_->Draw();
  c_->cd();
  
  h_->GetYaxis()->SetRangeUser(ymin_,ymax_);
  h_->Draw("hist");

  hdxy->Fit("myfit","NR","e",0.2,1.);

  par_ = myfit->GetParameter(0);
  myfit->SetLineColor(2);
  myfit->SetLineWidth(2);
  myfit->DrawCopy("SAME");

  hdxy->Draw("X0 E Same");

  myfit2->SetParameter(0,par_);
  myfit2->SetLineColor(2);
  myfit2->SetLineWidth(2);
  myfit2->SetLineStyle(2);
  myfit2->DrawCopy("SAME");

  

//TLine *line = new TLine(0.2,300000.,0.2,0.3);
  TLine *line = new TLine(0.2,par_,0.2,ymin_);
  line->SetLineWidth(2);
  line->SetLineStyle(2);
  line->Draw();

  TArrow *arrow = new TArrow(0.2,10000.,0.2,par_+6,0.04,">");
  arrow->SetLineWidth(3);
  arrow->SetLineColor(2);
  arrow->Draw();

  int nChan=1;
 
  float dxl_ = scalel_*3.5;
  float dyl_ = scalel_*(nChan+0.5);

  cout << scalel_ << " " << xl_ << " " << yl_ << endl;

  TLegend* legend=new TLegend(xl_,yl_,xl_+dxl_,yl_+dyl_);
  legend->SetTextFont(42);
  legend->SetTextSize(0.04);
  legend->SetLineColor(0);
  legend->SetFillColor(0);
  
  legend->AddEntry(hdxy,"Data","EP");

  //  legend->Draw("same");

  // redraw axis
  c_->RedrawAxis();
  
  //lumi pad, cms prelim pad etc..
  {
    int txtFont = 42;
    float txtSize1 = 0.055;
    float txtX1 = 0.91;
    float txtY1 = 0.95;

    float txtSize2 = 0.05;
    float txtX2 = 0.85;
    float txtY2 = 0.83;
    
    TLatex latex;
    latex.SetNDC();
    latex.SetTextFont(txtFont);
    
    latex.SetTextSize(txtSize1);    
    latex.SetTextAlign(31); // align right
    latex.DrawLatex(txtX1,txtY1,"CMS");

    latex.SetTextAlign(31); // align right
    latex.SetTextSize(txtSize2);
    latex.DrawLatex(txtX2,txtY2,"36 pb^{-1}  at  #sqrt{s} = 7 TeV");
  }
  
  c_->cd();

  c_->SaveAs("Wmn_cosmics.pdf");
  return c_;
}

