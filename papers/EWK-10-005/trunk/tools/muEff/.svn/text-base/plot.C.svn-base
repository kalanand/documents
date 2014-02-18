
void plot()
{
  gROOT->LoadMacro("tdrstyle.C");
  setTDRStyle();
  gInterpreter->AddIncludePath("/afs/cern.ch/cms/slc5_ia32_gcc434/lcg/roofit/5.26.00-cms5/include");
  gInterpreter->Load("/afs/cern.ch/cms/slc5_ia32_gcc434/lcg/roofit/5.26.00-cms5/lib/libRooFitCore.so") ;
  using namespace RooFit ;

  gROOT->LoadMacro("nice_eff.C++");

  for( int iV=0; iV<4; iV++ ) {
    TCanvas* canv_ = nice_eff(iV);
    if( canv_!=0 ) {canv_->Print(".pdf");canv_->Print(".gif");canv_->Print(".root");canv_->Print(".C");}
  }
}

