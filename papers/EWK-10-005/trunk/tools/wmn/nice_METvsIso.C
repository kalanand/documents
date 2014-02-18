#if !defined(__CINT__) || defined(__MAKECINT__)

#include <TROOT.h>
#include <TH1.h>
#include <TH2.h>
#include <TLegend.h>
#include <TSystem.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TList.h>
#include <TFrame.h>
#include <TPostScript.h>
#include <TPaveLabel.h>
#include <TLatex.h>
#include <TText.h>
#include <TMath.h>
#include <TF1.h>
#include <TF2.h>
#include <TProfile.h>
#include <TFile.h>
#include <TPaveStats.h>
#include <TGaxis.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include <TGraphAsymmErrors.h>
#include <TMultiGraph.h>
#include <TColor.h>

#include <TArrow.h>
#include <TLine.h>

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

#include <TColor.h>
#endif

TCanvas* theCanvas;

//------------------------------------------------------------------------
TCanvas * nice_METvsIso()
{
  // canvas name
  TString cname;
  TString ctitle;

  cname = "MET_vs_Iso";
  ctitle = "MET_vs_Iso";

  TFile *my_file = new TFile("histos_qcd.root");
//my_file->ls();

  
  TProfile *MET_vs_Iso_QCD = (TProfile*)my_file->Get("MET_vs_Iso_QCD");
  TProfile *MET_vs_Iso_Data = (TProfile*)my_file->Get("MET_vs_Iso_Data");

  TF1 *myfit_QCD = new TF1("myfit_QCD","[0]*(1.+([1]*x))");
  TF1 *myfit_data = new TF1("myfit_data","[0]*(1.+([1]*x))");

  TCanvas* theCanvas = new TCanvas(cname,ctitle,300,300,479,510);
  theCanvas->UseCurrentStyle();
  theCanvas->SetLeftMargin(  87./479 );
  theCanvas->SetRightMargin( 42./479 );
  theCanvas->SetTopMargin(  30./510 );
  theCanvas->SetBottomMargin( 80./510 );
  theCanvas->SetFillColor(0);
  theCanvas->SetTickx(1);
  theCanvas->SetTicky(1);
  theCanvas->SetFrameFillStyle(0);
  theCanvas->SetFrameLineWidth(2);
  theCanvas->SetFrameBorderMode(0);

  theCanvas->Draw();
  theCanvas->cd();

//MET_vs_Iso_QCD->SetName("QCD MC");
  MET_vs_Iso_QCD->SetLineColor(2);
  MET_vs_Iso_QCD->SetLineWidth(2);
  MET_vs_Iso_QCD->SetMarkerStyle(24);
  MET_vs_Iso_QCD->SetMarkerColor(kRed);
  MET_vs_Iso_QCD->SetMarkerSize(1.1);
  MET_vs_Iso_QCD->GetXaxis()->SetRangeUser(0.,5.);
  MET_vs_Iso_QCD->GetYaxis()->SetRangeUser(0.,40.);
  MET_vs_Iso_QCD->GetYaxis()->SetTitle("#LT#slash{E}_{T}#GT [GeV]");
  MET_vs_Iso_QCD->GetYaxis()->CenterTitle();
  MET_vs_Iso_QCD->GetXaxis()->SetTitle("I^{rel}_{comb}");
  MET_vs_Iso_QCD->GetXaxis()->CenterTitle();

  MET_vs_Iso_QCD->Draw("e");

//MET_vs_Iso_Data->SetName("Data");
  MET_vs_Iso_Data->SetLineColor(kBlue);
  MET_vs_Iso_Data->SetMarkerStyle(25);
  MET_vs_Iso_Data->SetMarkerColor(kBlue);
  MET_vs_Iso_Data->SetMarkerSize(1.1);
  MET_vs_Iso_Data->Draw("e,Sames");

  MET_vs_Iso_QCD->Fit("myfit_QCD","NR","e",0.2,3.);
  myfit_QCD->SetLineColor(kRed);
  myfit_QCD->SetLineWidth(2);
  myfit_QCD->SetRange(0.2,3.);
  myfit_QCD->Draw("sames");

  MET_vs_Iso_Data->Fit("myfit_data","NR","e",0.2,3.);
  myfit_data->SetLineColor(kBlue);
  myfit_data->SetLineWidth(2);
  myfit_data->SetRange(0.2,3.);
  myfit_data->Draw("sames");

  int nChan=2;

  float  xl_ = 0.55;
  float  yl_ = 0.20;
  float scalel_ = 0.075;
  float dxl_ = scalel_*3.5;
  float dyl_ = scalel_*(nChan+0.5);

  TLegend* legend=new TLegend(xl_,yl_,xl_+dxl_,yl_+dyl_);
  legend->SetBorderSize(0);
  legend->SetTextFont(42);
  legend->SetTextSize(0.04);
  legend->SetLineColor(0);
  legend->SetFillColor(0);

  legend->AddEntry(MET_vs_Iso_Data,"data","EP");
  legend->AddEntry(MET_vs_Iso_QCD,"QCD simulation","EP");

  legend->Draw();

 // redraw axis
  theCanvas->RedrawAxis();


  //lumi pad, cms prelim pad etc..
  {
    int txtFont = 42;
    float txtSize1 = 0.055;
    float txtX1 = 0.91;
    float txtY1 = 0.95;

    float txtSize2 = 0.05;
    float txtX2 = 0.85;
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

  theCanvas->Update();
  theCanvas->cd();

  return theCanvas;


}


