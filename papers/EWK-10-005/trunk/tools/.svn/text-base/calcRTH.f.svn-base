      program calcRTH
c======================================================================
c
c compute the ratios of CMS measurements to theory
c Note: luminosity errors are ignored.
c
c======================================================================
      implicit none
      real*8 xcms,ecms,xthy,ethy,rat,err,errex,errth
      real*8 stat,syst,prec,eacc
      common /comrth/ xcms,ecms,xthy,ethy,stat,syst,prec,
     * rat,errex,errth,err,eacc
c
      write(6,10)
      write(6,38)
c
      xcms = 9.9508
      stat = 0.0725
      syst = 0.2260
      eacc = 0.1659
      xthy = 10.44
      ethy = 0.52
      call docalc
      write(6,40) 'W all ',prec,rat,errex,errth,err
c
      xcms = 5.8594
      stat = 0.0587
      syst = 0.1270
      eacc = 0.1096
      xthy = 6.15
      ethy = 0.29
      call docalc
      write(6,40) 'W plus',prec,rat,errex,errth,err
c
      xcms = 4.0921
      stat = 0.0464
      syst = 0.1039
      eacc = 0.0883
      xthy = 4.29
      ethy = 0.23
      call docalc
      write(6,40) 'Wminus',prec,rat,errex,errth,err
c
      xcms = 0.9310
      stat = 0.0259
      syst = 0.0144
      eacc = 0.0180
      xthy = 0.97
      ethy = 0.04
      call docalc
      write(6,40) 'Z     ',prec,rat,errex,errth,err
c
      xcms = 10.6384
      stat = 0.2781
      syst = 0.2353
      eacc = 0.1708
      xthy = 10.74
      ethy = 0.04
      call docalc
      write(6,40) 'W/Z   ',prec,rat,errex,errth,err
c
      xcms = 1.4332
      stat = 0.0202
      syst = 0.0368
      eacc = 0.0334
      xthy = 1.43
      ethy = 0.04
      call docalc
      write(6,40) 'W+/W- ',prec,rat,errex,errth,err
      stop
 10   format(/,10x,'Calculate CMS/Theory Ratios',/)
 38   format(' channel   precn    CMS/Th     (ex)      (th)',
     *   '       (tot)',/,1x,58('-'))
 40   format(a8,2x,f7.4,2x,f7.4,
     *  ' +/-',f7.4,
     *  ' +/-',f7.4,
     *  ' +/-',f7.4)
c 40   format(a8,2x,'ex prec=',f7.4,2x,
c     *  'Ratio(CMS/Th) = ',f7.4,
c     *  ' +/-',f7.4,'(ex)',
c     *  ' +/-',f7.4,'(th)',
c     *  ' +/-',f7.4,'(tot)')
      end

      subroutine docalc
c----------------------------------------------------------------------      
      implicit none
      real*8 xcms,ecms,xthy,ethy,rat,err,errex,errth
      real*8 stat,syst,prec,eacc
      common /comrth/ xcms,ecms,xthy,ethy,stat,syst,prec,
     * rat,errex,errth,err,eacc
      ecms = sqrt(stat**2+syst**2+eacc**2)
      prec = ecms/xcms
      rat = xcms/xthy
      errex = rat * prec
      errth = rat * (ethy/xthy)
      err = sqrt(errex**2+errth**2)
      end
