# Polarized_HNLs

1) In the pythia8240 directory:

Pyhtia8 configuration (with LHCb's lb-run):
  LbLogin -c x86_64-slc6-gcc62-opt
  lb-run ROOT bash
  
  ./configure --with-root=$ROOTCONFIG --enable-shared
  make
  
2) Add the archive library:
  cd lib
  mkdir archive
  cp libpythia.a ./archive
  
3) Download in a subdirectory the files "B_gun.cc", "B_gun_3body.cc" (running the simulation and store "raw" TTrees with kinematics, "Makefile" and "histos_B_gun.cc" (able to compare several TTrees and make more specifici histogrames using raw TTrees)

  3.1. Simulation files
  B_gun.cc : simulation of B+ -> mu+ N(-> mu-+ pi+-)
  To execute:
        make B_gun
        ./B_gun.exe
  B_gun_3body.cc : simulation of B+ -> pi0 mu+ N(-> mu-+ pi+-)
        make B_gun_3body
        ./B_gun_3body.exe
    
  The decays can be changed in definition lines.
  The HNL id can be set to 15 (polarization handling) or 25 (flat PS)
  
  The code create a file "tree_Bgun.root", containing 3 TTrees : Tgrandmother (the B), Tmother (mu1, (meson) and N) and Tdaughter (mu2 and pi). This file can be further read by histos_Bgun.cc.
  
  /!\ The file histos_Bgun.cc and histos_Bgun_3body.cc work with specific tree names, so the TTrees have to be renamed properly in function of the chosen options of the simulation.
  
  
