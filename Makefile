######################################################################
# Makefile for building Pythia's ROOT examples.
# Axel Naumann, 2011-03-03
######################################################################

# Need this to get SHAREDSUFFIX (e.g. dylib or so)
-include ../config.mk

# A few variables used in this Makefile:
EX           := hist tree
EXE          := $(addsuffix .exe,$(EX))
PYTHIA8      ?= $(PWD)/..
STATICLIB    := $(PYTHIA8)/lib/libpythia8.a
SHAREDLIB    := $(PYTHIA8)/lib/libpythia8.$(SHAREDSUFFIX)
DICTCXXFLAGS := -I$(PYTHIA8)/include 
ROOTCXXFLAGS := $(DICTCXXFLAGS) $(shell root-config --cflags)

# Libraries to include if GZIP support is enabled
ifeq (x$(ENABLEGZIP),xyes)
LIBGZIP=-L$(BOOSTLIBLOCATION) -lboost_iostreams -L$(ZLIBLOCATION) -lz
endif

# LDFLAGS1 for static library, LDFLAGS2 for shared library
LDFLAGS1 := $(shell root-config --ldflags --glibs) \
  -L$(PYTHIA8)/lib/archive -lpythia8 $(LIBGZIP)
LDFLAGS2 := $(shell root-config --ldflags --glibs) \
  -L$(PYTHIA8)/lib -lpythia8 $(LIBGZIP)
  
#  -L$(PYTHIA8)/lib/archive -lpythia8 -llhapdfdummy $(LIBGZIP)
#  -L$(PYTHIA8)/lib -lpythia8 -llhapdfdummy $(LIBGZIP)

# Default target; make examples (but not shared dictionary)
all: $(EX)

# Rule to build hist example. Needs static PYTHIA 8 library
hist: $(STATICLIB) hist.cc
	$(CXX) $(ROOTCXXFLAGS) $@.cc -o $@.exe $(LDFLAGS1)

# Rule to build tree example. Needs dictionary to be built and
# static PYTHIA 8 library
tree: $(STATICLIB) tree.cc
	rootcint -f treeDict.cc -c $(DICTCXXFLAGS) pythiaROOT.h pythiaLinkdef.h 
	$(CXX) $(ROOTCXXFLAGS) treeDict.cc $@.cc -o $@.exe $(LDFLAGS1)

tree_sep_B: $(STATICLIB) tree_sep_B.cc
	rootcint -f treeDict.cc -c $(DICTCXXFLAGS) pythiaROOT.h pythiaLinkdef.h 
	$(CXX) $(ROOTCXXFLAGS) treeDict.cc $@.cc -o $@.exe $(LDFLAGS1)

tree_sandbox: $(STATICLIB) tree_sandbox.cc
	rootcint -f treeDict.cc -c $(DICTCXXFLAGS) pythiaROOT.h pythiaLinkdef.h 
	$(CXX) $(ROOTCXXFLAGS) treeDict.cc $@.cc -o $@.exe $(LDFLAGS1)
	

tree_auto_OS: $(STATICLIB) tree_auto_OS.cc
	rootcint -f treeDict.cc -c $(DICTCXXFLAGS) pythiaROOT.h pythiaLinkdef.h 
	$(CXX) $(ROOTCXXFLAGS) treeDict.cc $@.cc -o $@.exe $(LDFLAGS1)
tree_auto_SS: $(STATICLIB) tree_auto_SS.cc
	rootcint -f treeDict.cc -c $(DICTCXXFLAGS) pythiaROOT.h pythiaLinkdef.h 
	$(CXX) $(ROOTCXXFLAGS) treeDict.cc $@.cc -o $@.exe $(LDFLAGS1)
	
HNL_gun_SS: $(STATICLIB) HNL_gun_SS.cc
	rootcint -f treeDict.cc -c $(DICTCXXFLAGS) pythiaROOT.h pythiaLinkdef.h 
	$(CXX) $(ROOTCXXFLAGS) treeDict.cc $@.cc -o $@.exe $(LDFLAGS1)
	
HNL_gun_OS: $(STATICLIB) HNL_gun_OS.cc
	rootcint -f treeDict.cc -c $(DICTCXXFLAGS) pythiaROOT.h pythiaLinkdef.h 
	$(CXX) $(ROOTCXXFLAGS) treeDict.cc $@.cc -o $@.exe $(LDFLAGS1)
	
B_gun_SS: $(STATICLIB) B_gun_SS.cc
	rootcint -f treeDict.cc -c $(DICTCXXFLAGS) pythiaROOT.h pythiaLinkdef.h 
	$(CXX) $(ROOTCXXFLAGS) treeDict.cc $@.cc -o $@.exe $(LDFLAGS1)
B_gun_SS_3body: $(STATICLIB) B_gun_SS.cc
	rootcint -f treeDict.cc -c $(DICTCXXFLAGS) pythiaROOT.h pythiaLinkdef.h 
	$(CXX) $(ROOTCXXFLAGS) treeDict.cc $@.cc -o $@.exe $(LDFLAGS1)

B_gun_3body: $(STATICLIB) B_gun_3body.cc
	rootcint -f treeDict.cc -c $(DICTCXXFLAGS) pythiaROOT.h pythiaLinkdef.h 
	$(CXX) $(ROOTCXXFLAGS) treeDict.cc $@.cc -o $@.exe $(LDFLAGS1)

B_gun_OS: $(STATICLIB) B_gun_OS.cc
	rootcint -f treeDict.cc -c $(DICTCXXFLAGS) pythiaROOT.h pythiaLinkdef.h 
	$(CXX) $(ROOTCXXFLAGS) treeDict.cc $@.cc -o $@.exe $(LDFLAGS1)
B_gun_OS_3body: $(STATICLIB) B_gun_SS.cc
	rootcint -f treeDict.cc -c $(DICTCXXFLAGS) pythiaROOT.h pythiaLinkdef.h 
	$(CXX) $(ROOTCXXFLAGS) treeDict.cc $@.cc -o $@.exe $(LDFLAGS1)
	
histos_HNL_gun: $(STATICLIB) histos_HNL_gun.cc
	rootcint -f treeDict.cc -c $(DICTCXXFLAGS) pythiaROOT.h pythiaLinkdef.h 
	$(CXX) $(ROOTCXXFLAGS) treeDict.cc $@.cc -o $@.exe $(LDFLAGS1)
histos_B_gun: $(STATICLIB) histos_B_gun.cc
	rootcint -f treeDict.cc -c $(DICTCXXFLAGS) pythiaROOT.h pythiaLinkdef.h 
	$(CXX) $(ROOTCXXFLAGS) treeDict.cc $@.cc -o $@.exe $(LDFLAGS1)
histos_B_gun_3body: $(STATICLIB) histos_B_gun.cc
	rootcint -f treeDict.cc -c $(DICTCXXFLAGS) pythiaROOT.h pythiaLinkdef.h 
	$(CXX) $(ROOTCXXFLAGS) treeDict.cc $@.cc -o $@.exe $(LDFLAGS1)
	
analysis: $(STATICLIB) analysis.cc
	rootcint -f treeDict.cc -c $(DICTCXXFLAGS) pythiaROOT.h pythiaLinkdef.h 
	$(CXX) $(ROOTCXXFLAGS) treeDict.cc $@.cc -o $@.exe $(LDFLAGS1)

analysis2: $(STATICLIB) analysis2.cc
	rootcint -f treeDict.cc -c $(DICTCXXFLAGS) pythiaROOT.h pythiaLinkdef.h 
	$(CXX) $(ROOTCXXFLAGS) treeDict.cc $@.cc -o $@.exe $(LDFLAGS1)
analysis3: $(STATICLIB) analysis3.cc
	rootcint -f treeDict.cc -c $(DICTCXXFLAGS) pythiaROOT.h pythiaLinkdef.h 
	$(CXX) $(ROOTCXXFLAGS) treeDict.cc $@.cc -o $@.exe $(LDFLAGS1)
	
crosscheck_histos: $(STATICLIB) crosscheck_histos.cc
	rootcint -f treeDict.cc -c $(DICTCXXFLAGS) pythiaROOT.h pythiaLinkdef.h 
	$(CXX) $(ROOTCXXFLAGS) treeDict.cc $@.cc -o $@.exe $(LDFLAGS1)

mtau0_scan_v1: $(STATICLIB) mtau0_scan_v1.cc
	rootcint -f treeDict.cc -c $(DICTCXXFLAGS) pythiaROOT.h pythiaLinkdef.h
	$(CXX) $(ROOTCXXFLAGS) treeDict.cc $@.cc -o $@.exe $(LDFLAGS1)
#	rootcint -f treeDict.cc -c -p $(DICTCXXFLAGS) pythiaROOT.h pythiaLinkdef.h

mtau0_scan_v2: $(STATICLIB) mtau0_scan_v2.cc
	rootcint -f treeDict.cc -c $(DICTCXXFLAGS) pythiaROOT.h pythiaLinkdef.h
	$(CXX) $(ROOTCXXFLAGS) treeDict.cc $@.cc -o $@.exe $(LDFLAGS1)
#   rootcint -f treeDict.cc -c -p $(DICTCXXFLAGS) pythiaROOT.h pythiaLinkdef.h


# Rule to build full dictionary
dict: $(SHAREDLIB)
	rootcint -f pythiaDict.cc -c $(DICTCXXFLAGS) \
           -DPYTHIA8_COMPLETE_ROOT_DICTIONARY \
           pythiaROOT.h pythiaLinkdef.h
	$(CXX) -shared -fPIC -o pythiaDict.$(SHAREDSUFFIX) pythiaDict.cc \
         -DPYTHIA8_COMPLETE_ROOT_DICTIONARY \
         $(ROOTCXXFLAGS) $(LDFLAGS2)


# Error messages if PYTHIA libraries don't exist
$(STATICLIB):
	@echo "Error: PYTHIA 8 archive library must be built"
	@false
$(SHAREDLIB):
	@echo "Error: PYTHIA 8 shared library must be built"
	@false

# Clean up
clean:
	rm -f $(EXE) hist.root pythiaDict.* \
treeDict.cc treeDict.h pytree.root
