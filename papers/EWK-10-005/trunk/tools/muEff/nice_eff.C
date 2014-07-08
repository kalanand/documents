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

TCanvas* nice_eff(int iV=0 )
{
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
  bool logScaleY=false;

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
  int ndivx(510);
  int ndivy(510);
  float titleOffset(1.5);

  float r0_ = 1.;
  float dr_ = 0.3;

  // canvas name
  TString cname;
  TString ctitle;

  // legend position and scale;
  float xl_  = 0.;
  float yl_  = 0.;
  float scalel_ = 0.075;

// --------------------------------------------------------------

  TFile *my_file = new TFile("ZMuMuTag_and_Probe_eff.root");
  my_file->ls();

  TH1D *heff_MC_eta = (TH1D*)my_file->Get("heff_MC_eta");
  TH1D *heff_data_eta = (TH1D*)my_file->Get("heff_data_eta");
  TH1D *hrho_eta = (TH1D*)my_file->Get("hrho_eta");
  TH1D *heff_MC_pt = (TH1D*)my_file->Get("heff_MC_pt");
  TH1D *heff_data_pt = (TH1D*)my_file->Get("heff_data_pt");
  TH1D *hrho_pt = (TH1D*)my_file->Get("hrho_pt");
  
// All stuff is ready 

// --------------------------------------------------------------------

  if (iV == 0 ) {
    cname = "eff_in_eta";
    xtitle = "#eta(#mu)";
    ytitle = "#varepsilon";
    nbin_ = 72;
    xmin_ = -2.16;
    xmax_ = 2.16;
    ymin_ = 0.5;
    ymax_ = 1.01;
  }
  else if (iV == 1) { 
    cname = "rho_in_eta";
    xtitle = "#eta(#mu)";
    ytitle = "#rho";
    nbin_ = 72;
    xmin_ = -2.16;
    xmax_ = 2.16;
    ymin_ = 0.78;
    ymax_ = 1.08;
  }
  else if (iV == 2) { 
    cname = "eff_in_pt";
    xtitle = "p_{T}(#mu) [GeV]";
    ytitle = "#varepsilon";
    nbin_ = 10;
    xmin_ = 0.;
    xmax_ = 100.;
    ymin_ = 0.7;
    ymax_ = 1.0;
  }
  else if (iV == 3) { 
    cname = "rho_in_pt";
    xtitle = "p_{T}(#mu) [GeV]";
    ytitle = "#rho";
    nbin_ = 10;
    xmin_ = 0.;
    xmax_ = 100.;
    ymin_ = 0.85;
    ymax_ = 1.05;
  }
 
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
  
  cout << " hola " << endl;
  // a dummy histogram with the correct x axis
  // Warning: setTDRstyle() must be called before
  TH1F* h_= new TH1F( "bidon", "bidon", nbin_, xmin_, xmax_ );
  TAxis* ax_ = h_->GetXaxis();
  TAxis* ay_ = h_->GetYaxis();
  
  ax_->SetTitle(xtitle);
  //  ax_->CenterTitle();
  ax_->SetNdivisions(ndivx);
  ax_->SetTitleOffset(1.0);

  ay_->SetTitle(ytitle);
  //  ay_->CenterTitle();
  ay_->SetNdivisions(ndivy);
  ay_->SetTitleOffset(titleOffset);
  ay_->SetLabelOffset(0.015);

// ------------------------
//
// now plotting
//  
  c_->Draw();
  c_->cd();
  
  h_->GetYaxis()->SetRangeUser(ymin_,ymax_);
  h_->Draw("hist");

  if (iV==0) {

    heff_MC_eta->SetMarkerStyle(23);
    heff_MC_eta->SetMarkerSize(0.9);

    heff_data_eta->SetMarkerStyle(24);
    heff_data_eta->SetMarkerColor(2);
    heff_data_eta->SetLineColor(2);
    heff_data_eta->SetLineWidth(2);
    heff_data_eta->SetMarkerSize(0.9);
 
    xl_ = 0.55;
    yl_ = 0.20;
 
    heff_MC_eta->Draw("X0 E SAME");
    heff_data_eta->Draw("X0 E SAME");
 
    int nChan=2;
  
    float dxl_ = scalel_*3.5;
    float dyl_ = scalel_*(nChan+0.5);
 
    TLegend* legend=new TLegend(xl_,yl_,xl_+dxl_,yl_+dyl_);
    legend->SetTextFont(42);
    legend->SetTextSize(0.045);
    legend->SetLineColor(0);
    legend->SetFillColor(0);
    
    legend->AddEntry(heff_data_eta,"data","EP");
    legend->AddEntry(heff_MC_eta,"MC Z/#gamma* #rightarrow #mu#mu","EP");

    legend->Draw("same");
  }
  else if (iV ==1) {

    hrho_eta->SetMarkerStyle(20);
    hrho_eta->SetMarkerSize(0.9);
 
    hrho_eta->Draw("X0 E SAME");
  } 
  else if (iV ==2) {

    heff_MC_pt->SetMarkerStyle(23);
    heff_MC_pt->SetMarkerSize(0.9);

    heff_data_pt->SetMarkerStyle(24);
    heff_data_pt->SetMarkerColor(2);
    heff_data_pt->SetLineColor(2);
    heff_data_pt->SetLineWidth(2);
    heff_data_pt->SetMarkerSize(0.9);
 
    xl_ = 0.55;
    yl_ = 0.20;
 
    heff_MC_pt->Draw("X0 E SAME");
    heff_data_pt->Draw("X0 E SAME");
 
    int nChan=2;
  
    float dxl_ = scalel_*3.5;
    float dyl_ = scalel_*(nChan+0.5);
 
    TLegend* legend=new TLegend(xl_,yl_,xl_+dxl_,yl_+dyl_);
    legend->SetTextFont(42);
    legend->SetTextSize(0.045);
    legend->SetLineColor(0);
    legend->SetFillColor(0);
    
    legend->AddEntry(heff_data_pt,"data","EP");
    legend->AddEntry(heff_MC_pt,"MC Z/#gamma* #rightarrow #mu#mu","EP");

    legend->Draw("same");

  } 
  else if (iV ==3) {

    hrho_pt->SetMarkerStyle(20);
    hrho_pt->SetMarkerSize(0.9);
 
    hrho_pt->Draw("X0 E SAME");

  } 

  // redraw axis
  c_->RedrawAxis();

  //lumi pad, cms prelim pad etc..
  {
    int txtFont = 42;
    float txtSize1 = 0.055;
    float txtX1 = 0.91;
    float txtY1 = 0.95;

    float txtSize2 = 0.05;
    float txtX2 = 0.80;
    float txtY2 = 0.87;
    
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

  return c_;
}

