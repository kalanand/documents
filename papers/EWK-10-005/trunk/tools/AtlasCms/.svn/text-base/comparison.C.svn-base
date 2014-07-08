#include <iostream>
#include <stdlib.h>
#include <cassert>
#include <vector>
#include <map>

#include "TFile.h"
#include "TH1F.h"
#include "TString.h"
#include "TFrame.h"
#include "THStack.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TStyle.h"
#include "TPad.h"
#include "TCanvas.h"
#include "TArrow.h"
#include "TGraphAsymmErrors.h"
#include "TGaxis.h"
#include "TColor.h"
#include "TMarker.h"
#include "RooHist.h"

#include "LEPEntry.C"

using namespace std;

bool includeVjet = true;

TCanvas* comparison( int imode )
{
  TString titleX;
  double x0;
  double xmin;
  double xmax;
  
  float xlow = 6.5;
  float xhi = 16.5;
  float xpos1_ = 6.8;
  float xpos2_ = 11.6;
  int ndigit_ = 2;
  if( imode==0 )
    {
      ndigit_ = 2;
      xlow = 6.5;
      xhi  = 16.5;
      xpos1_ = 6.8;
      xpos2_ = 11.4;
      titleX = "[ #sigma #times B ]( W )   [nb]";
      x0   = 10.44;  
      xmin = x0-0.52;
      xmax = x0+0.52;
    }
  else if( imode==1 )
    {
      ndigit_ = 3;
      xlow = 0.61;
      xhi  = 1.58;
      xpos1_ = 0.62;
      xpos2_ = 1.05;
      titleX = "[ #sigma #times B ]( Z )   [nb]";
      x0   = 0.97;  
      xmin = x0-0.04;
      xmax = x0+0.04;
    }

  vector<TString> mode;
  vector<float>   val;
  vector<float>   stat;
  vector<float>   syst;
  vector<float>   exp;
  vector<float>   theo;
  vector<float>   lumi;
  vector<int> mrkStyle;
  vector<int> mrkCol;
  vector<float> mrkSize;

  float markerSize_ = 1.1;
  int nSigBR = -1;

  if( imode==0 )
    {
      {
	mode.push_back("ATLAS W-electron");
	val.push_back(10.551);
	stat.push_back(0.032);
	syst.push_back(0.300);
	theo.push_back(0.316);
	lumi.push_back(0.359);
	mrkStyle.push_back(kFullCircle);
	mrkCol.push_back(kRed);
	mrkSize.push_back(markerSize_);
      }
      {
	mode.push_back("ATLAS W-muon");
	val.push_back(10.322);
	stat.push_back(0.030);
	syst.push_back(0.249);
	theo.push_back(0.310);
	lumi.push_back(0.377);
	mrkStyle.push_back(kFullCircle);
	mrkCol.push_back(kRed);
	mrkSize.push_back(markerSize_);
      }
      {
	mode.push_back("ATLAS W-combined");
	val.push_back(10.391);
	stat.push_back(0.022);
	syst.push_back(0.238);
	theo.push_back(0.312);
	lumi.push_back(0.353);
	mrkStyle.push_back(kFullCircle);
	mrkCol.push_back(kRed);
	mrkSize.push_back(markerSize_);
      }
      {
	mode.push_back("CMS W-electron");
	val.push_back(10.48);
	stat.push_back(0.03);
	syst.push_back(0.15);
	theo.push_back(0.09);
	lumi.push_back(0.42);
	mrkStyle.push_back(kFullCircle);
	mrkCol.push_back(kRed);
	mrkSize.push_back(markerSize_);
      }
      {
	mode.push_back("CMS W-muon");
	val.push_back(10.18);
	stat.push_back(0.03);
	syst.push_back(0.12);
	theo.push_back(0.11);
	lumi.push_back(0.41);
	mrkStyle.push_back(kFullCircle);
	mrkCol.push_back(kRed);
	mrkSize.push_back(markerSize_);
      }
      {
	mode.push_back("CMS W-combined");
	val.push_back(10.31);
	stat.push_back(0.02);
	syst.push_back(0.09);
	theo.push_back(0.10);
	lumi.push_back(0.41);
	mrkStyle.push_back(kFullCircle);
	mrkCol.push_back(kRed);
	mrkSize.push_back(markerSize_);
      }
    }
  else if( imode==1 )
    {
      {
	mode.push_back("ATLAS Z-electron");
	val.push_back(0.972);
	stat.push_back(0.010);
	syst.push_back(0.034);
	theo.push_back(0.038);
	lumi.push_back(0.033);
	mrkStyle.push_back(kFullCircle);
	mrkCol.push_back(kRed);
	mrkSize.push_back(markerSize_);
      }
      {
	mode.push_back("ATLAS Z-muon");
	val.push_back(0.941);
	stat.push_back(0.008);
	syst.push_back(0.011);
	theo.push_back(0.037);
	lumi.push_back(0.032);
	mrkStyle.push_back(kFullCircle);
	mrkCol.push_back(kRed);
	mrkSize.push_back(markerSize_);
      }
      {
	mode.push_back("ATLAS Z-combined");
	val.push_back( 0.945);
	stat.push_back(0.006);
	syst.push_back(0.011);
	theo.push_back(0.038);
	lumi.push_back(0.032);
	mrkStyle.push_back(kFullCircle);
	mrkCol.push_back(kRed);
	mrkSize.push_back(markerSize_);
      }
      {
	mode.push_back("CMS Z-electron");
	val.push_back( 0.992);
	stat.push_back(0.011);
	syst.push_back(0.018);
	theo.push_back(0.016);
	lumi.push_back(0.040);
	mrkStyle.push_back(kFullCircle);
	mrkCol.push_back(kRed);
	mrkSize.push_back(markerSize_);
      }
      {
	mode.push_back("CMS Z-muon");
	val.push_back( 0.968);
	stat.push_back(0.008);
	syst.push_back(0.007);
	theo.push_back(0.019);
	lumi.push_back(0.039);
	mrkStyle.push_back(kFullCircle);
	mrkCol.push_back(kRed);
	mrkSize.push_back(markerSize_);
      }
      {
	mode.push_back("CMS Z-combined");
	val.push_back( 0.975);
	stat.push_back(0.007);
	syst.push_back(0.007);
	theo.push_back(0.018);
	lumi.push_back(0.039);
	mrkStyle.push_back(kFullCircle);
	mrkCol.push_back(kRed);
	mrkSize.push_back(markerSize_);
      }
    }


  size_t nMode = mode.size();

  // text2
  size_t ntxt = 0;
  TString txt[3];
  float txtSize[3];
  float txtX[3];
  float txtY[3];
  int   txtAlign[3];
  int   txtFont[3];
  
  txt[0] = "ATLAS / CMS";
  txtSize[0] = 0.050;
  txtX[0] = 0.06;
  txtY[0] = 0.955;
  txtAlign[0] = 11;
  txtFont[0] = 42;
  
  txt[1] = "36 pb^{-1}  at  #sqrt{s} = 7 TeV";
  txtSize[1] = 0.045;
  txtX[1] = 0.94;
  txtY[1] = 0.955;
  txtAlign[1] = 31;
  txtFont[1] = 42;

  int W_ = 1000;
  int H_ = 750;
  float leftMargin(0.06);
  float rightMargin(0.06);
  float topMargin(0.06);
  float bottomMargin(0.13);
  float titleSizeX = 0.05;
  float titleOffsetX = 1.1;
  int ndivx = 6;

  gStyle->SetTickLength( 0.9*gStyle->GetTickLength("X"), "X" );
  gStyle->SetEndErrorSize(7);

  TCanvas *c_ = new TCanvas("lep", "lep",50,50,W_,H_);
  c_->SetHighLightColor(2);
  c_->SetFillColor(0);
  c_->SetBorderMode(0);
  c_->SetBorderSize(2);
  c_->SetTickx(1);
  c_->SetTicky(0);
  c_->SetLeftMargin(leftMargin);
  c_->SetRightMargin(rightMargin);
  c_->SetTopMargin(topMargin);
  c_->SetBottomMargin(bottomMargin);
  c_->SetFrameBorderMode(0);
  c_->SetFrameBorderMode(0);

   
  TH1F* dum_ = new TH1F("dumplot","dumplot",100,xlow,xhi);
  //  TH1F* dum_ = new TH1F("dumplot","dumplot",100,6.5,16.5);



  dum_->SetMinimum(0.);
  dum_->SetMaximum(1.);
  dum_->SetDirectory(0);
  dum_->SetStats(0);

  TAxis* ax_ =  dum_->GetXaxis();
  TAxis* ay_ =  dum_->GetYaxis();

  ax_->SetTitle(titleX);
  ax_->SetLabelFont(42);
  ax_->SetLabelOffset(0.007);
  ax_->SetLabelSize(0.05);
  ax_->SetTitleSize(titleSizeX);
  ax_->SetTitleOffset(titleOffsetX);
  ax_->SetTitleFont(42);
  ax_->CenterTitle();
  ax_->SetNdivisions(ndivx);

  ay_->SetTitle("");
  ay_->SetLabelFont(42);
  ay_->SetLabelOffset(99);
  ay_->SetLabelSize(0);
  ay_->SetTitleSize(0);
  ay_->SetTitleOffset(99);
  ay_->SetTitleFont(42);
  ay_->SetNdivisions(0);

  c_->cd();     
  dum_->Draw("");
  //  return c_;

//   //  size_t nMode = 20;
  float y0_ = 0.08;  
  float dy_ = (1-2*0.04)/nMode;
  float txtsize_ = 0.04;
  float scale_ = 0.75;
  int result_ = 1;
  int align_ = 11;

  {
    int lineWidth1 = 3;
    //    int bandFillColor  = kCyan-10;
    //    int bandFillColor2 = kCyan;
    int bandFillColor  = kYellow-9;
    //    int bandFillColor  = kYellow-4;
    int bandFillColor2 = kOrange;
    int bandFillStyleV = 1001;
    int bandFillStyleV2 = 3256;
    int bandLineColor = kMagenta;
    int bandLineStyle = kSolid;
//     {
//       TLatex ltx;
//       ltx.SetTextFont(42);
//       ltx.SetTextSize(0.03);    
//       ltx.SetTextColor(kBlue);    
//       ltx.SetTextAlign(11); 
//       ltx.DrawLatex(1.05,0.96,"lumi. uncertainty: #pm4%");
//     }

    double ymin = 0;
    double ymax = 1;

    //    double ymin2 = y0_+(nMode-nSigBR-1.5)*dy_;
    double ymin2 = 0;
    double ymax2 = 1;

    float eps_ = 0;

    // draw the theory band
    TGraph* vBand;
    TLine* vLineMin;
    TLine* vLineMax;
    TLine* vLine0;

    vBand = new TGraph(5);
    vBand->SetPoint(0,xmin+eps_,ymin2+eps_);
    vBand->SetPoint(1,xmin+eps_,ymax2-eps_);
    vBand->SetPoint(2,xmax-eps_,ymax2-eps_);
    vBand->SetPoint(3,xmax-eps_,ymin2+eps_);
    vBand->SetPoint(4,xmin+eps_,ymin2+eps_);
    vLineMin = new TLine(xmin,ymin,xmin,ymax);
    vLine0   = new TLine(x0,ymin+eps_,x0,ymax-eps_);
    vLineMax = new TLine(xmax,ymin,xmax,ymax);

    vBand->SetFillStyle(bandFillStyleV);
    vBand->SetFillColor(bandFillColor);
    vBand->DrawClone("F");
    vBand->SetFillStyle(bandFillStyleV2);
    vBand->SetFillColor(bandFillColor2);
    vBand->DrawClone("F");

    vLine0->SetLineColor(bandLineColor);
    vLine0->SetLineStyle(bandLineStyle);
    vLine0->SetLineWidth(lineWidth1);

    vLine0->DrawClone();
  }

  //  float eps_ = 0.04;
  //  float lumi_ = 0; // or 0.11?

  for( size_t ii=0; ii< nMode; ii++ )
    {
      LEPEntry entry( mode[ii] );
      entry.setNdigit( ndigit_ );
      entry.setVal(  val[ii] );
      // this is a trick: using Stat and Syst for Exp and Theo
      entry.setStat( stat[ii] );
      entry.setSyst( syst[ii] );
      entry.setTheo( theo[ii] );
      if( ii<3 )     entry.setTheoName("acc");
      entry.setLumi( lumi[ii], false  );
      entry.setStyle( mrkStyle[ii], mrkSize[ii], mrkCol[ii], 
		      42, txtsize_, align_, 3 );
      entry.setX( xpos1_, xpos2_ );
      //      entry.setX( xpos1_, xpos2_ );
      float ypos_ = y0_+(nMode-ii-1)*dy_;
      entry.setY( ypos_, ypos_ ); 
      //    entry.setDY( 0.2*dy_ ); 
      entry.setScale( scale_ );
      entry.writeResult(result_);
      entry.draw();
    }
  //lumi pad, cms prelim pad etc..
  {    
    TLatex latex;
    latex.SetNDC();    
    for( size_t ii=0; ii<ntxt; ii++ )
      { 
	latex.SetTextFont(txtFont[ii]);
	latex.SetTextSize(txtSize[ii]);    
	latex.SetTextAlign(txtAlign[ii]); 
	latex.DrawLatex(txtX[ii],txtY[ii],txt[ii]);
      }
  }
  c_->RedrawAxis();
  c_->GetFrame()->Draw();

  return c_;
}

