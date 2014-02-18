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
#include "TMarker.h"
#include "TGraphAsymmErrors.h"
#include "TGraphErrors.h"
#include "TLine.h"
#include "TPolyLine.h"

using namespace std;

class LEPError
{
  TString _name;

public:

  float lo;
  float hi;
  bool  asymm;
  int   status;  // 0:inactive; 1:in-quadrature; 2:linearly

  void setName( const char* name ) { _name=name; } 
  TString name() const { return _name; }
  float err() const 
  {
    if( status==0 ) return 0;
    if( asymm ) return 0.5*(lo+hi);
    return lo;
  }
  bool ok() const { return status>0; }
  float errlo() const 
  {
    if( status==0 ) return 0;
    return lo;
  }
  float errhi() const 
  {
    if( status==0 ) return 0;
    return hi;
  }
  
  LEPError( const char* name, float err=0 ) 
    : _name(name), lo(err), hi(err), asymm(false), status(0) {}
  LEPError( const char* name, float errlo, float errhi ) 
    : _name(name), lo(errlo), hi(errhi), asymm(true), status(0) {}
  ~LEPError() {}

};


class LEPEntry
{
private:

  TString    _name;
  TString    _unit;
  float       _val;

  LEPError _stat;
  LEPError _syst;
  LEPError _theo;
  LEPError _lumi;

  int    _ndigit;

  int     _marker;
  float     _size;
  int      _color;
  int    _txtfont;
  float  _txtsize;
  float _txtalign;
  
  TGraphAsymmErrors*  _gtot;
  TGraphAsymmErrors* _gcomb;
  TGraphAsymmErrors*  _gexp;
  TGraphAsymmErrors* _gstat;
  TMarker*            _mval;

  float _x1, _y1;
  float _x2, _y2;
  float _dy;

  bool   _writeresult;
  float   _scale;
  
  int _lineWidth;

public:

  LEPEntry( const char* name=0, const char* unit=0 );
  ~LEPEntry();

  void setVal( float val=0 );
  void setValAndErrors( float val=0, float stat=0, float syst=0, 
			float theo=0, float lumierror=0.11 );
  void setStat( float stat );
  void setSyst( float syst );
  void setListOfSyst( vector<float> syst );
  void setTheo( float theo );
  void setLumi( float lumi, bool relative=true );
  void setAsymmStat( float statlo, float statup );
  void setAsymmSyst( float systlo, float systup );
  void setAsymmTheo( float theolo, float theoup );
  void setNdigit( int ndigit=3 ) { _ndigit = ndigit; }
  void setStyle( int marker=kFullCircle, float size=0.8, int color=kBlack, 
		 int txtfont=42, float txtsize=0.8, int txtalign=11,
		 int lineWidth=2 );
  void setX( float x1, float x2=0 ) { _x1=x1; _x2=x2; }
  void setY( float y1, float y2=0 ) { _y1=y1; _y2=y2; }
  void setDY( float dy ) { _dy=dy; }
  //  void setXandY( float x, float y ) { setX(x); setY(y); }
  //  void setXYandDY( float x, float y, float dy ) { setXandY(x,y); setDY(dy); }
  void setStatName( const char* name ) { _stat.setName(name); }
  void setSystName( const char* name ) { _syst.setName(name); }
  void setTheoName( const char* name ) { _theo.setName(name); }
  void setLumiName( const char* name ) { _lumi.setName(name); }
  void setScale( float scale ) { _scale=scale; }
  
  void writeResult( int yes=1 ) 
  { 
    if( yes ) _writeresult=true; 
    else      _writeresult=false; 
  }

  TString result();

  void draw();
  
};

LEPEntry::LEPEntry( const char* name, const char* unit )
  : _name(name), _unit(unit), _stat("stat"), _syst("syst"), _theo("theo"), _lumi("lumi"),
    _x1(0), _y1(0), 
    _x2(0), _y2(0), 
    _dy(0), 
    _writeresult(false), _scale(0.8), _lineWidth(2)
{
  _val=0;
  setStyle();
  setNdigit();
}


LEPEntry::~LEPEntry() {}

void 
LEPEntry::setVal( float val )
{
  _val=val;
}

void 
LEPEntry::setValAndErrors( float val, float stat, float syst, 
			   float theo, float lumi )
{
  setVal(val);
  setStat(stat);
  setSyst(syst);
  setTheo(theo);
  setLumi(lumi);
}

void 
LEPEntry::setStat( float stat )
{
  _stat.asymm=false;
  _stat.lo=stat;
  _stat.hi=stat;
  _stat.status=1;
}

void 
LEPEntry::setSyst( float syst )
{
  _syst.asymm=false;
  _syst.lo=syst;
  _syst.hi=syst;
  _syst.status=1;
}

void 
LEPEntry::setListOfSyst( vector<float> syst )
{
  float syst_(0);
  for( size_t ii=0; ii<syst.size(); ii++ )
    {
      syst_ += pow( syst[ii], 2 );
    }
  setSyst( sqrt( syst_ ) );
}

void 
LEPEntry::setTheo( float theo )
{
  _theo.asymm=false;
  _theo.lo=theo;
  _theo.hi=theo;
  _theo.status=1;
}

void 
LEPEntry::setAsymmStat( float statlo, float stathi )
{
  _stat.asymm=true;
  _stat.lo=statlo;
  _stat.hi=stathi;
  _stat.status=1;
}

void 
LEPEntry::setAsymmSyst( float systlo, float systhi )
{
  _syst.asymm=true;
  _syst.lo=systlo;
  _syst.hi=systhi;
  _syst.status=1;
}

void 
LEPEntry::setAsymmTheo( float theolo, float theohi )
{
  _theo.asymm=true;
  _theo.lo=theolo;
  _theo.hi=theohi;
  _theo.status=1;
}
  
void 
LEPEntry::setLumi( float lumi, bool relative )
{
  float lumi_(lumi);
  if( relative ) lumi_*=_val;
  _lumi.asymm=false;
  _lumi.lo=lumi_;
  _lumi.hi=lumi_;
  _lumi.status=2;
}
  
void 
LEPEntry::setStyle( int marker, float size, int color, 
		    int txtfont, float txtsize, int txtalign, int lineWidth )
{
  _marker   = marker;
  _size     = size;
  _color    = color;
  _txtfont  = txtfont;
  _txtsize  = txtsize;
  _txtalign = txtalign;
  _lineWidth = lineWidth;
}

TString 
LEPEntry::result()
{
  char    line_[512];
  TString str_;
  TString pmstr_(" #pm ");
  TString format_("%-4.");
  format_ += _ndigit;
  format_ += "f";
  TString  valstr_;
  TString statstr_;
  TString syststr_;
  TString theostr_;
  TString lumistr_;

  sprintf( line_, format_.Data(), _val );
  valstr_ = line_;
  str_ = valstr_;

  if( _stat.ok() )
    {
      if( !_stat.asymm )
	{
	  sprintf( line_, format_.Data(), _stat.lo );
	}
      else
	{
	  sprintf( line_, "#scale[0.7]{#splitline{+%-4.3f}{-%-4.3f}}#lower[0.3]{#scale[0.9]{ stat}}", 
		   _stat.hi, _stat.lo );
	}
      
      statstr_ = line_;
      str_ = str_ + pmstr_ + statstr_;
      str_ += "#lower[0.3]{#scale[0.9]{ ";
      str_ += _stat.name();
      str_ += "}}";
    }      

  if( _syst.ok() )
    {
      if( !_syst.asymm )
	{
	  sprintf( line_, format_.Data(), _syst.lo );
	}
      else 
	{
	  sprintf( line_, "#scale[0.7]{#splitline{+%-4.3f}{- %-4.3f}}#lower[0.3]{#scale[0.9]{ syst}}", _syst.hi, _syst.lo );
	}
      syststr_ = line_;
	  str_ += pmstr_;
	  str_ += syststr_;
	  str_ += "#lower[0.3]{#scale[0.9]{ ";
	  str_ += _syst.name();
	  str_ += "}}";
    }
  

  if( _theo.ok() )
    {
      if( !_theo.asymm )
	{
	  sprintf( line_, format_.Data(), _theo.lo );
	}
      else 
	{
	  sprintf( line_, "#scale[0.7]{#splitline{+%-4.3f}{- %-4.3f}}#lower[0.3]{#scale[0.9]{ syst}}", _theo.hi, _theo.lo );
	}
      theostr_ = line_;
	  str_ += pmstr_;
	  str_ += theostr_;
	  str_ += "#lower[0.3]{#scale[0.9]{ ";
	  str_ += _theo.name();
	  str_ += "}}";
    }
  
  if( _lumi.ok() )
    {
      sprintf( line_, format_.Data(), _lumi.err() );
      lumistr_ = line_;
      lumistr_ += "#lower[0.3]{#scale[0.9]{ ";
      lumistr_ += _lumi.name();
      lumistr_ += "}}";
      str_ += pmstr_ + lumistr_;
    }

  str_ += _unit;

  return str_;
}

void
LEPEntry::draw()
{
  float  xval_[1];
  float  yval_[1];
  float    ey_[1];
  float estatup_[1];
  float eexpup_[1];
  float ecombup_[1];
  float etotup_[1];
  float estatlo_[1];
  float eexplo_[1];
  float ecomblo_[1];
  float etotlo_[1];
  
  xval_[0] = _val;
  yval_[0] = _y1;
  ey_[0] = 0;

  estatup_[0] = _stat.hi;
  eexpup_[0] = sqrt( pow( _stat.hi,2 ) + pow( _syst.hi,2 ) );
  ecombup_[0] = sqrt( pow( eexpup_[0],2 ) + pow( _theo.hi,2 ) );
  //GHM!!!
  etotup_[0]  = sqrt( pow( ecombup_[0],2 ) + pow(_lumi.hi,2 ) );
  
  estatlo_[0] = _stat.lo;
  eexplo_[0] = sqrt( pow( _stat.lo,2 ) + pow( _syst.lo,2 ) );      
  ecomblo_[0] = sqrt( pow( eexplo_[0],2 ) + pow( _theo.lo,2 ) );
  // GHM!!!  
  etotlo_[0] = sqrt( pow( ecomblo_[0],2 ) + pow(_lumi.lo,2 ) );
  
  if( _lumi.ok() )
    {
      TGraphAsymmErrors* gtot_  
	= new TGraphAsymmErrors( 1, xval_, yval_, etotlo_, etotup_, ey_, ey_ );
      //      gtot_->SetLineStyle( kSolid );
      gtot_->SetLineColor( kGreen );
      //      gtot_->SetLineWidth( _lineWidth );
      gtot_->SetLineWidth( 1 );
      gtot_->Draw();
    }
  if( _theo.ok() )
    {
      TGraphAsymmErrors* gcomb_ 
	= new TGraphAsymmErrors( 1, xval_, yval_, ecomblo_, ecombup_, ey_, ey_ );
      gcomb_->SetLineColor( kBlue );
      gcomb_->SetLineWidth( _lineWidth );
      gcomb_->DrawClone();
    }
  if( _syst.ok() )
    {
      TGraphAsymmErrors* gexp_ 
	= new TGraphAsymmErrors( 1, xval_, yval_, eexplo_, eexpup_, ey_, ey_ );
      gexp_->SetLineColor( kBlue );
      gexp_->SetLineWidth( _lineWidth );
      if( !_theo.ok() )      gexp_->DrawClone();
    }
  if( _stat.ok() )
    {
      TGraphAsymmErrors* gstat_ 
	= new TGraphAsymmErrors( 1, xval_, yval_, estatlo_, estatup_, ey_, ey_ );
      gstat_->SetMarkerSize( 0 );
      gstat_->SetLineColor( kBlack );
      gstat_->SetLineWidth( _lineWidth );
      gstat_->DrawClone();
    }

  TMarker* marker_ = new TMarker();
  marker_->SetMarkerStyle( _marker );
  marker_->SetMarkerSize( _size );
  marker_->SetMarkerColor( _color );
  marker_->DrawMarker( _val, _y1 );

  TString str_ = result();
  //  cout << str_ << endl;

  TLatex latex;
  //  latex.SetNDC();    
  latex.SetTextFont(_txtfont);
  latex.SetTextSize(_txtsize);    
  latex.SetTextAlign(_txtalign); 
  latex.DrawLatex(_x1,_y1+_dy,_name);
  if( _writeresult )
    {
      int sng_ = +1;
      if( _y2==0 ) 
	{
	  _x2 = _x1;
	  _y2 = _y1;
	  sng_ = -1;
	}
      latex.SetTextSize(_scale*_txtsize);    
      latex.SetTextAlign(_txtalign); 
      latex.DrawLatex(_x2,_y2+sng_*_dy,str_);
    }
}


