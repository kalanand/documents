#include <iostream>
#include <stdlib.h>
#include <cassert>
#include <vector>
#include <map>

#include "TFile.h"
#include "TProfile.h"
#include "TH1F.h"
#include <TF1.h>
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

TCanvas* nice_qcd(int iV=0 )
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

  // canvas name
  TString cname;
  TString ctitle;

  // legend position and scale;
  float xl_  = 0.;
  float yl_  = 0.;
  float scalel_ = 0.075;

// --------------------------------------------------------------

  TFile *my_file = new TFile("histos_qcd.root");

  if (iV==0) { 

// QCD Templates MC

    TH1D *h_iso = (TH1D*)my_file->Get("METQCD_MC_Iso");      // MC prediction for Isolated region
    TH1D *h_plain = (TH1D*)my_file->Get("METQCD_MC_Inv");    // Plain inversion
    TH1D *h_corr = (TH1D*)my_file->Get("METQCD_MC_InvC");    // Inversion corrected
    TH1D *h_plus = (TH1D*)my_file->Get("METQCD_MC_InvP");    // Inversion corrected with alpha+0.08
    TH1D *h_minus = (TH1D*)my_file->Get("METQCD_MC_InvM");   // Inversion corrected with alpha-0.08
    
    h_iso->Rebin(2);
    h_plus->Rebin(2);
    h_minus->Rebin(2);
    h_corr->Rebin(2);
    h_plain->Rebin(2);
    
    float nentries_iso = h_iso->GetEntries();
    float nentries_noiso = h_plain->GetEntries();
 
    unsigned int nbin_x;
    nbin_x = h_iso->GetNbinsX();
    float bin_w = h_iso->GetXaxis()->GetBinWidth(-1);
    float xbins[nbin_x];
    float xbins_l[nbin_x];
    float xbins_u[nbin_x];
    float met_iso[nbin_x];
    float met_plus[nbin_x];
    float met_minus[nbin_x];
    float met_upper[nbin_x];
    float met_lower[nbin_x];
    float met_corr[nbin_x];
    float met_plain[nbin_x];
 
    for (unsigned int kx=0; kx<nbin_x; kx++) {
      met_iso[kx]=0.;
      met_plus[kx]=0.;
      met_minus[kx]=0.;
      met_upper[kx]=0.;
      met_lower[kx]=0.;
      met_corr[kx]=0.;
      met_plain[kx]=0.;
    }
    for (unsigned int kx=0; kx<nbin_x; kx++) {
      xbins[kx]=h_iso->GetXaxis()->GetBinCenter(kx+1);
      xbins_l[kx]=bin_w/2.;
      xbins_u[kx]=bin_w/2.;
 
      met_iso[kx]=h_iso->GetBinContent(kx+1)*100./nentries_iso;
      met_plus[kx]=h_plus->GetBinContent(kx+1)*100./nentries_noiso;
      met_minus[kx]=h_minus->GetBinContent(kx+1)*100./nentries_noiso;
      met_corr[kx]=h_corr->GetBinContent(kx+1)*100./nentries_noiso;
      met_plain[kx]=h_plain->GetBinContent(kx+1)*100./nentries_noiso;
      if (met_plus[kx]> met_minus[kx]) {
          met_upper[kx]=met_plus[kx]-met_corr[kx];
          met_lower[kx]=met_corr[kx]-met_minus[kx];
      }
      else {
          met_upper[kx]= met_minus[kx]-met_corr[kx];
          met_lower[kx]=met_corr[kx]-met_plus[kx];
      }
    }

    h_iso->Sumw2();
    h_plain->Sumw2();
    h_corr->Sumw2();
    h_plus->Sumw2();
    h_minus->Sumw2();
  
    h_iso->Scale(100./nentries_iso);
    h_plain->Scale(100./nentries_noiso);
    h_corr->Scale(100./nentries_noiso);
    h_plus->Scale(100./nentries_noiso);
    h_minus->Scale(100./nentries_noiso);
  
    TGraphAsymmErrors* ygr = new TGraphAsymmErrors(nbin_x,xbins,met_corr,xbins_l,xbins_u,met_lower,met_upper);
  
// All stuff is ready 

// --------------------------------------------------------------------
    cname = "qcd_template_MC";
    xtitle = "#slash{E}_{T} [GeV]";
    ytitle = "fraction of events/4 GeV [%]";
   
    nbin_ = 20;
    xmin_ = 0.;
    xmax_ = 80.;
 
    ymin_ = 0.;
    ymax_ = 30.;
 
    markerSize = 1.2;
 
    xl_ = 0.38;
    yl_ = 0.50;
 
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
    
    // a dummy histogram with the correct x axis
    // Warning: setTDRstyle() must be called before
    TH1F* h_= new TH1F( "bidon", "bidon", nbin_, xmin_, xmax_ );
    TAxis* ax_ = h_->GetXaxis();
    TAxis* ay_ = h_->GetYaxis();
    
    ax_->SetTitle(xtitle);
    ax_->CenterTitle();
    ax_->SetNdivisions(ndivx);
    ax_->SetTitleOffset(1.0);
 
    ay_->SetTitle(ytitle);
    ay_->CenterTitle();
    ay_->SetNdivisions(ndivy);
    ay_->SetTitleOffset(titleOffset);
    ay_->SetLabelOffset(0.015);
 
    ygr->SetFillColor(kRed-7);
    ygr->SetLineColor(2);
    ygr->SetFillStyle(3001);
 
    h_iso->SetLineWidth(2);
 
    h_plus->SetLineColor(kRed-7);
    h_minus->SetLineColor(kRed-7);
 
    h_corr->SetMarkerStyle(20);
    h_corr->SetMarkerColor(1);
    h_corr->SetMarkerSize(1.2);
 
    h_plain->SetLineColor(4);
    h_plain->SetLineWidth(3);
    h_plain->SetLineStyle(2);
 
    //
    // now plotting
    //  
    c_->Draw();
    c_->cd();
    
    h_->GetYaxis()->SetRangeUser(ymin_+0.001*(ymax_-ymin_),ymax_);
    h_->Draw("hist");
 
    ygr->Draw("2");
 
// We don't draw explicitely the templates obtained using alpha+-0.08 to avoid confusion
//  h_plus->Draw("HISTO SAME");
//  h_minus->Draw("HISTO SAME");

    h_plain->Draw("HIST SAME");
  
    h_corr->Draw("X0 E SAME");
  
    h_iso->Draw("Histo SAME");
  
    int nChan=4;
   
    float dxl_ = scalel_*3.5;
    float dyl_ = scalel_*(nChan+0.5);
  
    TLegend* legend=new TLegend(xl_,yl_,xl_+dxl_,yl_+dyl_);
    legend->SetTextFont(42);
    legend->SetTextSize(0.035);
    legend->SetLineColor(0);
    legend->SetFillColor(0);
    
    legend->AddEntry(h_iso,"QCD, isolated","L");
    legend->AddEntry(h_corr,"QCD, nonisolated, corrected","EP");
    legend->AddEntry(h_plain,"QCD, nonisolated","L");
    legend->AddEntry(ygr,"syst. uncert.","F");
  
  
    legend->Draw("same");
  
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
//  float txtY2 = 0.83;
    float txtY2 = 0.87;
    
    TLatex latex;
    latex.SetNDC();
    latex.SetTextFont(txtFont);
    
    latex.SetTextSize(txtSize1);    
    latex.SetTextAlign(31); // align right
    latex.DrawLatex(txtX1,txtY1,"CMS Simulation");

// No need to give luminosity, it is all MC

    latex.SetTextAlign(31); // align right
    latex.SetTextSize(txtSize2);
//  latex.DrawLatex(txtX2,txtY2,"36 pb^{-1}  at  #sqrt{s} = 7 TeV");
    latex.DrawLatex(txtX2,txtY2,"36 pb^{-1}  at #sqrt{s} = 7 TeV");
  }

  c_->cd();

  return c_;

// End QCD templates from MC
  }

  if (iV==1) { 
// QCD templates from Data

    TH1D *h_MC = (TH1D*)my_file->Get("mc");                   // QCD MC prediction for the isolated region
    TH1D *h_plain = (TH1D*)my_file->Get("corrected_plain");   // Data: despite the name it is not corrected, plain inversion only
    TH1D *h_corr = (TH1D*)my_file->Get("corrected_optimal");  // Data: corrected with alpha from fit
    TH1D *h_plus = (TH1D*)my_file->Get("corrected_plus");     // Data: corrected with alpha+0.08
    TH1D *h_minus = (TH1D*)my_file->Get("corrected_minus");   // Data: corrected with alpha-0.08
  
    h_MC->Rebin(2);
    h_plus->Rebin(2);
    h_minus->Rebin(2);
    h_corr->Rebin(2);
    h_plain->Rebin(2);
  
    h_corr->SetStats(0); // By unknown reasons (to me) the stat box is always drawn unless I disable it explicitely

    unsigned int nbin_x;
    nbin_x = h_MC->GetNbinsX();
    float bin_w = h_MC->GetXaxis()->GetBinWidth(-1);
    float xbins[nbin_x];
    float xbins_l[nbin_x];
    float xbins_u[nbin_x];
    float met_MC[nbin_x];
    float met_plus[nbin_x];
    float met_minus[nbin_x];
    float met_upper[nbin_x];
    float met_lower[nbin_x];
    float met_corr[nbin_x];
  
    for (unsigned int kx=0; kx<nbin_x; kx++) {
      met_MC[kx]=0.;
      met_plus[kx]=0.;
      met_minus[kx]=0.;
      met_upper[kx]=0.;
      met_lower[kx]=0.;
      met_corr[kx]=0.;
    }
    for (unsigned int kx=0; kx<nbin_x; kx++) {
      xbins[kx]=h_MC->GetXaxis()->GetBinCenter(kx+1);
      xbins_l[kx]=bin_w/2.;
      xbins_u[kx]=bin_w/2.;
  
      met_MC[kx]=h_MC->GetBinContent(kx+1);
      met_plus[kx]=h_plus->GetBinContent(kx+1);
      met_minus[kx]=h_minus->GetBinContent(kx+1);
      met_corr[kx]=h_corr->GetBinContent(kx+1);
      if (met_plus[kx]> met_minus[kx]) {
          met_upper[kx]=met_plus[kx]-met_corr[kx];
          met_lower[kx]=met_corr[kx]-met_minus[kx];
      }
      else {
          met_upper[kx]= met_minus[kx]-met_corr[kx];
          met_lower[kx]=met_corr[kx]-met_plus[kx];
      }
    }

    TGraphAsymmErrors* ygr = new TGraphAsymmErrors(nbin_x,xbins,met_corr,xbins_l,xbins_u,met_lower,met_upper);

// All stuff is ready 

// --------------------------------------------------------------------
    cname = "qcd_template_DATA";
    xtitle = "#slash{E}_{T} [GeV]";
    ytitle = "fraction of events/4 GeV [%]";
  
    nbin_ = 20;
    xmin_ = 0.;
    xmax_ = 80.;
 
    ymin_ = 0.;
    ymax_ = 30.;
 
    markerSize = 1.2;
 
    xl_ = 0.38;
    yl_ = 0.50;
 
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
   
  // a dummy histogram with the correct x axis
  // Warning: setTDRstyle() must be called before
    TH1F* h_= new TH1F( "bidon", "bidon", nbin_, xmin_, xmax_ );
    TAxis* ax_ = h_->GetXaxis();
    TAxis* ay_ = h_->GetYaxis();
    
    ax_->SetTitle(xtitle);
    ax_->CenterTitle();
    ax_->SetNdivisions(ndivx);
    ax_->SetTitleOffset(1.0);
  
    ay_->SetTitle(ytitle);
    ay_->CenterTitle();
    ay_->SetNdivisions(ndivy);
    ay_->SetTitleOffset(titleOffset);
    ay_->SetLabelOffset(0.015);
  
    ygr->SetFillColor(kRed-7);
    ygr->SetLineColor(2);
    ygr->SetFillStyle(3001);
  
    h_MC->SetLineWidth(2);
  
    h_plus->SetLineColor(kRed-7);
    h_minus->SetLineColor(kRed-7);
  
    h_corr->SetMarkerStyle(20);
    h_corr->SetMarkerColor(1);
    h_corr->SetMarkerSize(1.2);
  
    h_plain->SetLineColor(4);
    h_plain->SetLineWidth(3);
    h_plain->SetLineStyle(2);
//     h_plain->SetMarkerStyle(21);
//     h_plain->SetMarkerColor(4);
//     h_plain->SetMarkerSize(1.2);
  

  //
  // now plotting
  //  
    c_->Draw();
    c_->cd();
  
    h_->GetYaxis()->SetRangeUser(ymin_+0.001*(ymax_-ymin_),ymax_);
    h_->Draw("hist");

    ygr->Draw("2");

// We don't draw explicitely the templates obtained using alpha+-0.08 to avoid confusion
//h_plus->Draw("HISTO SAME");
//h_minus->Draw("HISTO SAME");

//    h_plain->Draw("X0 E SAME");
    h_plain->Draw("HISTO SAME");

    h_MC->Draw("Histo SAME");

    h_corr->Draw("X0 E SAME");

    int nChan=4;
 
    float dxl_ = scalel_*3.5;
    float dyl_ = scalel_*(nChan+0.5);

    TLegend* legend=new TLegend(xl_,yl_,xl_+dxl_,yl_+dyl_);
    legend->SetTextFont(42);
    legend->SetTextSize(0.035);
    legend->SetLineColor(0);
    legend->SetFillColor(0);
  
    legend->AddEntry(h_MC,"QCD simulation, isolated","LP");
    legend->AddEntry(h_corr,"data, nonisolated, corrected","EP");
    legend->AddEntry(h_plain,"data, nonisolated","L");
    legend->AddEntry(ygr,"syst. uncert.","F");

    legend->Draw("same");

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
//    float txtY2 = 0.83;
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

// End QCD templates from Data
  }

}

