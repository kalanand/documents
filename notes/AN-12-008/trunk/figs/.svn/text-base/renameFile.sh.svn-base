#!/bin/tcsh

# convert all eps figures in this directory to pdf

foreach datafile ( `ls TMVA_*.root_*.png` ) 
        set fname = `echo $datafile | awk '{sub(".root",""); print $0}'` 
	echo "submitting: mv $datafile $fname" 
        mv $datafile $fname	 
    end
    echo ""



