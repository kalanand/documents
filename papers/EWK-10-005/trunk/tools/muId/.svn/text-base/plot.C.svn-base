
void plot()
{
  gROOT->LoadMacro("../tdrstyle.C");
  setTDRStyle();
  gInterpreter->AddIncludePath("/afs/cern.ch/cms/slc5_ia32_gcc434/lcg/roofit/5.26.00-cms5/include");
  gInterpreter->Load("/afs/cern.ch/cms/slc5_ia32_gcc434/lcg/roofit/5.26.00-cms5/lib/libRooFitCore.so") ;
  using namespace RooFit ;
  
//gROOT->LoadMacro("Wmunu.C++");

//for( int iV=0; iV<6; iV++ )
//  {
//    TCanvas* canv_ = Wmunu(iV);
//    if( canv_!=0 ) {canv_->Print(".pdf");canv_->Print(".gif");canv_->Print(".root");}
//  }
  gROOT->LoadMacro("WmunuOthers.C++");

//for( int iV=6; iV<24; iV++ )
  for( int iV=31; iV<37; iV++ )
//  if (iV!=6 || iV!=7 || iV!=20 || iV!=21 || iV!=22 || iV!=23) 
    // Only MET plots
    {
      TCanvas* canv_ = WmunuOthers(iV);
      if( canv_!=0 ) {canv_->Print(".pdf");canv_->Print(".gif");canv_->Print(".root");}
    }


}
