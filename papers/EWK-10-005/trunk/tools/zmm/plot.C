

void plotGG()
{
  

  gROOT->LoadMacro("ZmumuGolden.C+");
  
  for( int iL=0; iL<2; iL++ )
    {
      bool logScale= (iL==1);
      
      TCanvas* canvGG_ = plotting36GG( logScale );
      if( canvGG_!=0 ) canvGG_->Print(".pdf");
    }
}


void plotGT()  
{

  gROOT->LoadMacro("ZmuTrk.C+");
  for( int iL=0; iL<2; iL++ )
    {
      bool logScale= (iL==1);
      
      TCanvas* canvGT_ = plotting36GT( logScale );
      if( canvGT_!=0 ) canvGT_->Print(".pdf");
    }
  
}

void plotGS()  
{
  gROOT->LoadMacro("ZmuSta.C+");
  for( int iL=0; iL<2; iL++ )
    {
      bool logScale= (iL==1);
      
      TCanvas* canvGS_ = plotting36GS( logScale );
      if( canvGS_!=0 ) canvGS_->Print(".pdf");
    }
} 

void plotGN()  
{
  gROOT->LoadMacro("ZmumuNoIso.C+");

  for( int iL=0; iL<2; iL++ )
    {
      bool logScale= (iL==1);
    
      TCanvas* canvGN_ = plotting36GN( logScale );
      if( canvGN_!=0 ) canvGN_->Print(".pdf");
    }
}


void plot()  
{

  gROOT->LoadMacro("tdrstyle.C");
  setTDRStyle();

  plotGG();
  plotGT();
  plotGS();
  plotGN();



}
