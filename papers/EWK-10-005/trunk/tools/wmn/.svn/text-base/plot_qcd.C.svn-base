
void plot_qcd()
{
  gROOT->LoadMacro("tdrstyle.C");
  setTDRStyle();
  gInterpreter->AddIncludePath("/afs/cern.ch/cms/slc5_ia32_gcc434/lcg/roofit/5.26.00-cms5/include");
  gInterpreter->Load("/afs/cern.ch/cms/slc5_ia32_gcc434/lcg/roofit/5.26.00-cms5/lib/libRooFitCore.so") ;
  using namespace RooFit ;

  gROOT->LoadMacro("nice_qcd.C++");
  for( int iV=0; iV<2; iV++ )
    // QCD template plots
    {
      TCanvas* canv_ = nice_qcd(iV);
      if( canv_!=0 ) {canv_->Print(".pdf");canv_->Print(".gif");canv_->Print(".root");}
    }

}

