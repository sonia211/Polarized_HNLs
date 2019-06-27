#include "Pythia8/Pythia.h"
//#include "ReadablePart.cc"

// ROOT, for saving Pythia events as trees in a file.
#include "TTree.h"
#include "TFile.h"

#include <fstream>
#include <iomanip>
#include <TChain.h>
#include <TList.h>
#include <TRatioPlot.h>
#include <cmath>
#include <TH2.h>
#include <TH1.h>
#include <TF1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include <stdlib.h>
#include <string>
#include <stdlib.h>
#include "TApplication.h"
#include <iostream>
#include <sys/types.h>
#include <dirent.h>
#include <climits>
#include <stdio.h>
#include <TAxis.h>
#include <TROOT.h>
#include <stdio.h>
#include <TFile.h>
#include <TString.h>
#include <iostream>
#include <TSystem.h>
//#include "Event.hpp"
#include <TCanvas.h>
#include <TH1.h>
#include <TH2.h>
#include <TLine.h>
#include <algorithm>
#include <TGraphErrors.h>
#include <TLegend.h>
#include <glob.h>
#include <TCut.h>
#include <vector>

#include <TLorentzVector.h>
#include <TVector3.h>


using namespace Pythia8;

double pi=3.141592;

// Functions declaration
std::vector<std::vector<double>> file_to_vec(string filename);


int main() {
	
	TString FILENAME0 = "./trees/tree_Bgun_OS_25.root";
	TString FILENAME1 = "./trees/tree_Bgun_SS.root";
	TString FILENAME2 = "./trees/tree_Bgun_OS.root";
	//TString FILENAME3 = "./trees/tree_Bgun_SS.root";
//TString FILENAME4 = "./trees/tree_Bgun_SS.root";


	TString T1s = "Tgrandmother";
	TString T2s = "Tmother";
	TString T3s = "Tdaughters";
	
	
	TFile *F0 = new TFile(FILENAME0, "UPDATE");
	TTree *T0 = new TTree(); TTree *T20 = new TTree(); TTree *T30 = new TTree();
	F0->GetObject(T1s, T0); F0->GetObject(T2s, T20); F0->GetObject(T3s, T30);
	T0->AddFriend(T20); T0->AddFriend(T30);
	
	TFile *F1 = new TFile(FILENAME1, "UPDATE");
	TTree *T1 = new TTree(); TTree *T21 = new TTree(); TTree *T31 = new TTree();
	F1->GetObject(T1s, T1); F1->GetObject(T2s, T21); F1->GetObject(T3s, T31);
	T1->AddFriend(T21); T1->AddFriend(T31);
	
	TFile *F2 = new TFile(FILENAME2, "UPDATE");
	TTree *T2 = new TTree(); TTree *T22 = new TTree(); TTree *T32 = new TTree();
	F2->GetObject(T1s, T2); F2->GetObject(T2s, T22); F2->GetObject(T3s, T32);
	T2->AddFriend(T22); T2->AddFriend(T32);
	
	
	// B restframe
	
	TCanvas *c1A = new TCanvas("c1A","c",800,600);
	TH1D* h1A_0 = new TH1D("h1A_0", "", 100, 1.1, 2.7); 
	TH1D* h1A_1 = new TH1D("h1A_1", "", 100, 1.1, 2.7); 
	TH1D* h1A_2 = new TH1D("h1A_2", "", 100, 1.1, 2.7); 
	
	TCanvas *c1B = new TCanvas("c1B","c",800,600);
	TH1D* h1B_0 = new TH1D("h1B_0", "", 100, 0., 1.8); 
	TH1D* h1B_1 = new TH1D("h1B_1", "", 100, 0., 1.8); 
	TH1D* h1B_2 = new TH1D("h1B_2", "", 100, 0., 1.8); 
	
	
	TCanvas *c2A = new TCanvas("c2A","c",800,600);
	TH1D* h2A_0 = new TH1D("h2A_0", "", 100, 1.1, 2.7); 
	TH1D* h2A_1 = new TH1D("h2A_1", "", 100, 1.1, 2.7); 
	TH1D* h2A_2 = new TH1D("h2A_2", "", 100, 1.1, 2.7); 

	
	TCanvas *c2B = new TCanvas("c2B","c",800,600);
	TH1D* h2B_0 = new TH1D("h2B_0", "", 100, 0., 1.8); 
	TH1D* h2B_1 = new TH1D("h2B_1", "", 100, 0., 1.8); 
	TH1D* h2B_2 = new TH1D("h2B_2", "", 100, 0., 1.8); 

	
	TCanvas *c3 = new TCanvas("c3","c",800,600);
	TH1D* h3_0 = new TH1D("h3_0", "", 50, 0., pi); 
	TH1D* h3_1 = new TH1D("h3_1", "", 50, 0., pi); 
	TH1D* h3_2 = new TH1D("h3_2", "", 50, 0., pi); 
	TH1D* h3_3 = new TH1D("h3_3", "", 50, 0., 6.); 
	TH1D* h3_4 = new TH1D("h3_4", "", 50, 0., 6.); 
	
	// HNL rest frame
	
	TCanvas *c4 = new TCanvas("c4","c",800,600);
	TH1D* h4_0 = new TH1D("h4_0", "", 50, -1., 1.);
	TH1D* h4_1 = new TH1D("h4_1", "", 50, -1., 1.);
	TH1D* h4_2 = new TH1D("h4_2", "", 50, -1., 1.);
	TH1D* h4_3 = new TH1D("h4_3", "", 50, -1., pi);
	TH1D* h4_4 = new TH1D("h4_4", "", 50, -1., pi);
	
	//pz
	TCanvas *c5 = new TCanvas("c5","c",800,600);
	TH1D* h5_0 = new TH1D("h5_0", "", 100, -3.5, 3.5); 
	TH1D* h5_1 = new TH1D("h5_1", "", 100, -3.5, 3.5); 
	TH1D* h5_2 = new TH1D("h5_2", "", 100, -3.5, 3.5); 
	TH1D* h5_3 = new TH1D("h5_3", "", 100, 0., 360.);
	TH1D* h5_4 = new TH1D("h5_4", "", 100, 0., 360.);
	
	//px
	TCanvas *c6 = new TCanvas("c6","c",800,600);
	TH1D* h6_0 = new TH1D("h6_0", "", 35, -3.5, 3.5); 
	TH1D* h6_1 = new TH1D("h6_1", "", 35, -3.5, 3.5); 
	TH1D* h6_2 = new TH1D("h6_2", "", 35, -3.5, 3.5); 
	TH1D* h6_3 = new TH1D("h6_3", "", 35, -3.5, 3.5); 
	TH1D* h6_4 = new TH1D("h6_4", "", 35, -3.5, 3.5); 
	
	//
	TCanvas *c7 = new TCanvas("c7","c",800,600);
	TH1D* h7_0 = new TH1D("h7_0", "", 50, 0., 17.);
	TH1D* h7_1 = new TH1D("h7_1", "", 50, 0., 17.);
	TH1D* h7_2 = new TH1D("h7_2", "", 50, 0., 17.);
	TH1D* h7_3 = new TH1D("h7_3", "", 50, 0., 180.);
	TH1D* h7_4 = new TH1D("h7_74", "", 50, 0., 180.);
	
	
	Double_t B_PX, B_PY, B_PZ, B_E;
	Double_t N_PX, N_PY, N_PZ, N_E;
	Double_t pi_PX, pi_PY, pi_PZ, pi_PT, pi_E;
	Double_t mu1_PX, mu1_PY, mu1_PZ, mu1_E;
	Double_t mu2_PX, mu2_PY, mu2_PZ, mu2_PT, mu2_E;
	
	Double_t mReco;
	
	int e0=T0->GetEntries();
	int e1=T1->GetEntries();
	int e2=T2->GetEntries();
	
	vector<int> vec = {e0,e1,e2};
	int nent = *std::min_element(vec.begin(), vec.end());
	//nent = *nent;
	
	for(int cnt=0; cnt<nent ;cnt++){
		T0->GetEntry(cnt);
		
		T0->SetBranchAddress("B_PX",&B_PX);
		T0->SetBranchAddress("B_PY",&B_PY);
		T0->SetBranchAddress("B_PZ",&B_PZ);
		T0->SetBranchAddress("B_E",&B_E);
		
		T0->SetBranchAddress("N_PX",&N_PX);
		T0->SetBranchAddress("N_PY",&N_PY);
		T0->SetBranchAddress("N_PZ",&N_PZ);
		T0->SetBranchAddress("N_E",&N_E);
		
		
		T0->SetBranchAddress("mu1_PX",&mu1_PX);
		T0->SetBranchAddress("mu1_PY",&mu1_PY);
		T0->SetBranchAddress("mu1_PZ",&mu1_PZ);
		T0->SetBranchAddress("mu1_E",&mu1_E);
		
		
		// -----------------------------------------
		
		T0->SetBranchAddress("pi_PX",&pi_PX);
		T0->SetBranchAddress("pi_PY",&pi_PY);
		T0->SetBranchAddress("pi_PZ",&pi_PZ);
		T0->SetBranchAddress("pi_PT",&pi_PT);
		T0->SetBranchAddress("pi_E",&pi_E);
		
		T0->SetBranchAddress("mu2_PX",&mu2_PX);
		T0->SetBranchAddress("mu2_PY",&mu2_PY);
		T0->SetBranchAddress("mu2_PZ",&mu2_PZ);
		T0->SetBranchAddress("mu2_PT",&mu2_PT);
		T0->SetBranchAddress("mu2_E",&mu2_E);

		TLorentzVector B_P(B_PX, B_PY, B_PZ, B_E);
		TLorentzVector N_P(N_PX, N_PY, N_PZ, N_E);
		TLorentzVector pi_P(pi_PX, pi_PY, pi_PZ, pi_E);
		TLorentzVector mu1_P(mu1_PX, mu1_PY, mu1_PZ, mu1_E);
		TLorentzVector mu2_P(mu2_PX, mu2_PY, mu2_PZ, mu2_E);
		
		TVector3 N_p = N_P.Vect();
		
		TVector3 B_P_Boost = B_P.BoostVector();
		TVector3 N_P_Boost = N_P.BoostVector();
		
		TLorentzVector mu12_P = mu1_P+mu2_P;
		h7_0->Fill(5.279*5.279 - 3.5*3.5 - mu12_P.Mag2());
		
		// In N restframe frame
		
		mu1_P.Boost(-N_P_Boost);
		mu2_P.Boost(-N_P_Boost);
		pi_P.Boost(-N_P_Boost);
		
		h4_0->Fill(mu2_P.CosTheta());
		h5_0->Fill(mu2_PZ);
		h6_0->Fill(mu2_PX);
		
		// In B restframe frame such that HNL traves along z
		
		mu1_P.Boost(N_P_Boost);	mu1_P.Boost(-B_P_Boost);	
		mu2_P.Boost(N_P_Boost);	mu2_P.Boost(-B_P_Boost);
		pi_P.Boost(N_P_Boost);	pi_P.Boost(-B_P_Boost);
		
		
			// Rotation to align HNL with z
			mu1_P.RotateZ(-1*N_P.Phi());	mu1_P.RotateY(-1*N_P.Theta());
			mu2_P.RotateZ(-1*N_P.Phi());	mu2_P.RotateY(-1*N_P.Theta());
			pi_P.RotateZ(-1*N_P.Phi());		pi_P.RotateY(-1*N_P.Theta());
		
		
		h1A_0->Fill(mu2_P.E());
		h1B_0->Fill(mu2_P.Perp());
		h2A_0->Fill(pi_P.E());
		h2B_0->Fill(pi_P.Perp());
		h3_0->Fill(mu1_P.Angle(mu2_P.Vect()));
	
	}
	
	//T1
	
	
	Double_t t;
	
	for(int cnt=0; cnt<nent; cnt++){
		T1->GetEntry(cnt);
		
		T1->SetBranchAddress("B_PX",&B_PX);
		T1->SetBranchAddress("B_PY",&B_PY);
		T1->SetBranchAddress("B_PZ",&B_PZ);
		T1->SetBranchAddress("B_E",&B_E);
		
		T1->SetBranchAddress("N_PX",&N_PX);
		T1->SetBranchAddress("N_PY",&N_PY);
		T1->SetBranchAddress("N_PZ",&N_PZ);
		T1->SetBranchAddress("N_E",&N_E);
		
	
		T1->SetBranchAddress("mu1_PX",&mu1_PX);
		T1->SetBranchAddress("mu1_PY",&mu1_PY);
		T1->SetBranchAddress("mu1_PZ",&mu1_PZ);
		T1->SetBranchAddress("mu1_E",&mu1_E);

		
		// -----------------------------------------
		
		T1->SetBranchAddress("pi_PX",&pi_PX);
		T1->SetBranchAddress("pi_PY",&pi_PY);
		T1->SetBranchAddress("pi_PZ",&pi_PZ);
		T1->SetBranchAddress("pi_PT",&pi_PT);
		T1->SetBranchAddress("pi_E",&pi_E);
		
		T1->SetBranchAddress("mu2_PX",&mu2_PX);
		T1->SetBranchAddress("mu2_PY",&mu2_PY);
		T1->SetBranchAddress("mu2_PZ",&mu2_PZ);
		T1->SetBranchAddress("mu2_PT",&mu2_PT);
		T1->SetBranchAddress("mu2_E",&mu2_E);

		TLorentzVector B_P(B_PX, B_PY, B_PZ, B_E);
		TLorentzVector N_P(N_PX, N_PY, N_PZ, N_E);
		TLorentzVector pi_P(pi_PX, pi_PY, pi_PZ, pi_E);
		TLorentzVector mu1_P(mu1_PX, mu1_PY, mu1_PZ, mu1_E);
		TLorentzVector mu2_P(mu2_PX, mu2_PY, mu2_PZ, mu2_E);
		
		TVector3 N_p = N_P.Vect();
		
		TVector3 B_P_Boost = B_P.BoostVector();
		TVector3 N_P_Boost = N_P.BoostVector();
		
		TLorentzVector mu12_P = mu1_P+mu2_P;
		h7_1->Fill(5.279*5.279 - 3.5*3.5-mu12_P.Mag2());
		
		// In N restframe frame
		
		mu1_P.Boost(-N_P_Boost);
		mu2_P.Boost(-N_P_Boost);
		pi_P.Boost(-N_P_Boost);
		
		h4_1->Fill(mu2_P.CosTheta());
		h5_1->Fill(mu2_P.Z());
		h6_1->Fill(mu2_P.X());
		
		// In B restframe frame such that HNL traves along z
		
		mu1_P.Boost(N_P_Boost);	mu1_P.Boost(-B_P_Boost);	
		mu2_P.Boost(N_P_Boost);	mu2_P.Boost(-B_P_Boost);
		pi_P.Boost(N_P_Boost);	pi_P.Boost(-B_P_Boost);
		
			// Rotation to align HNL with z
			
			mu1_P.RotateZ(-1*N_P.Phi());	mu1_P.RotateY(-1*N_P.Theta());
			mu2_P.RotateZ(-1*N_P.Phi());	mu2_P.RotateY(-1*N_P.Theta());
			pi_P.RotateZ(-1*N_P.Phi());	pi_P.RotateY(-1*N_P.Theta());
		
		
		//h1A_1->Fill(mu2_P.E());
		h1A_1->Fill(mu2_P.E());
		h1B_1->Fill(mu2_P.Perp());
		h2A_1->Fill(pi_P.E());
		h2B_1->Fill(pi_P.Perp());
		h3_1->Fill(mu1_P.Angle(mu2_P.Vect()));
	}
	
	
	//T2
	for(int cnt=0; cnt<nent; cnt++){
		
		T2->GetEntry(cnt);
		
		T2->SetBranchAddress("B_PX",&B_PX);
		T2->SetBranchAddress("B_PY",&B_PY);
		T2->SetBranchAddress("B_PZ",&B_PZ);
		T2->SetBranchAddress("B_E",&B_E);
		
		T2->SetBranchAddress("N_PX",&N_PX);
		T2->SetBranchAddress("N_PY",&N_PY);
		T2->SetBranchAddress("N_PZ",&N_PZ);
		T2->SetBranchAddress("N_E",&N_E);
		
		T2->SetBranchAddress("mu1_PX",&mu1_PX);
		T2->SetBranchAddress("mu1_PY",&mu1_PY);
		T2->SetBranchAddress("mu1_PZ",&mu1_PZ);
		T2->SetBranchAddress("mu1_E",&mu1_E);
		
		
		// -----------------------------------------
		
		T2->SetBranchAddress("pi_PX",&pi_PX);
		T2->SetBranchAddress("pi_PY",&pi_PY);
		T2->SetBranchAddress("pi_PZ",&pi_PZ);
		T2->SetBranchAddress("pi_PT",&pi_PT);
		T2->SetBranchAddress("pi_E",&pi_E);
		
		T2->SetBranchAddress("mu2_PX",&mu2_PX);
		T2->SetBranchAddress("mu2_PY",&mu2_PY);
		T2->SetBranchAddress("mu2_PZ",&mu2_PZ);
		T2->SetBranchAddress("mu2_PT",&mu2_PT);
		T2->SetBranchAddress("mu2_E",&mu2_E);

		TLorentzVector B_P(B_PX, B_PY, B_PZ, B_E);
		TLorentzVector N_P(N_PX, N_PY, N_PZ, N_E);
		TLorentzVector pi_P(pi_PX, pi_PY, pi_PZ, pi_E);
		TLorentzVector mu1_P(mu1_PX, mu1_PY, mu1_PZ, mu1_E);
		TLorentzVector mu2_P(mu2_PX, mu2_PY, mu2_PZ, mu2_E);
		

		TVector3 N_p = N_P.Vect();
		
		
		TVector3 B_P_Boost = B_P.BoostVector();
		TVector3 N_P_Boost = N_P.BoostVector();
		
		
		TLorentzVector mu12_P = mu1_P+mu2_P;
		h7_2->Fill(5.279*5.279 - 3.5*3.5-mu12_P.Mag2());
		
		// In N restframe frame
		
		mu1_P.Boost(-N_P_Boost);
		mu2_P.Boost(-N_P_Boost);
		pi_P.Boost(-N_P_Boost);
		
		h4_2->Fill(mu2_P.CosTheta());
		h5_2->Fill(mu2_P.Z());
		h6_2->Fill(mu2_P.X());
		
		// In B restframe frame such that HNL traves along z
		
		mu1_P.Boost(N_P_Boost);	mu1_P.Boost(-B_P_Boost);	
		mu2_P.Boost(N_P_Boost);	mu2_P.Boost(-B_P_Boost);
		pi_P.Boost(N_P_Boost);	pi_P.Boost(-B_P_Boost);
		
			// Rotation to align HNL with z
			
			mu1_P.RotateZ(-1*N_P.Phi());	mu1_P.RotateY(-1*N_P.Theta());
			mu2_P.RotateZ(-1*N_P.Phi());	mu2_P.RotateY(-1*N_P.Theta());
			pi_P.RotateZ(-1*N_P.Phi());	pi_P.RotateY(-1*N_P.Theta());
		
		
		h1A_2->Fill(mu2_P.E());
		h1B_2->Fill(mu2_P.Perp());
		h2A_2->Fill(pi_P.E());
		h2B_2->Fill(pi_P.Perp());
		h3_2->Fill(mu1_P.Angle(mu2_P.Vect()));
	}
	
	

	TString ODIRNAME = "./_CROSSCHECKS_B_GUN";

	/** c1A ************************************************************/
	c1A->cd();
	
	h1A_1->GetXaxis()->SetTitle("E(#mu_{2}) in B restframe [GeV]");
	h1A_0->SetLineColor(kOrange-3); 	 h1A_0->SetFillColor(kOrange-3);    h1A_0->SetFillStyle(3002); h1A_0->SetLineWidth(2); 	h1A_0->SetStats(0);
	h1A_1->SetLineColor(kCyan-3); 	 h1A_1->SetFillColor(kCyan-3);    h1A_1->SetFillStyle(3325); h1A_1->SetLineWidth(2); 	h1A_1->SetStats(0);
	h1A_2->SetLineColor(kBlue-3); 	 h1A_2->SetFillColor(kBlue-3);    h1A_2->SetFillStyle(3352); h1A_2->SetLineWidth(2); 	h1A_2->SetStats(0);
	//h1_3->SetLineColor(kMagenta-3); 	 h1_3->SetFillColor(kMagenta-3);    h1_3->SetFillStyle(3016); h1_3->SetLineWidth(2); h1_3->SetStats(0);
	//h1_4->SetLineColor(kBlue); 	 h1_4->SetFillColor(kBlue);    h1_4->SetFillStyle(3352); h1_4->SetLineWidth(2); h1_4->SetStats(0);
	
	h1A_0->Scale(1/h1A_0->Integral("width"));
	h1A_1->Scale(1/h1A_1->Integral("width"));
	h1A_2->Scale(1/h1A_2->Integral("width"));
	h1A_1->Draw("HIST");
	h1A_0->Draw("HISTSAME");
	h1A_2->Draw("HISTSAME");
	//h1A_2->Draw("HISTSAME");
	//h1A_3->Draw("HISTSAME");
		
	auto legend1a = new TLegend(0.42,0.68,0.65,0.9);
	
	legend1a->AddEntry(h1A_0,"OS with #lambda(N)=0","L");	
	legend1a->AddEntry(h1A_1,"OS #Leftrightarrow #lambda(N)=+1","L");	
	legend1a->AddEntry(h1A_2,"SS #Leftrightarrow #lambda(N)=-1","L");
	//legend->AddEntry(h1_4,"split, tau, pol -1","L");
	//legend->AddEntry(h1_2,"split, Higgs, no pol","L");
	
	legend1a->Draw();
	c1A->SaveAs(ODIRNAME+"/H1A.root");
	c1A->SaveAs(ODIRNAME+"/H1A.pdf");
	
	
	/** c1B ************************************************************/
	c1B->cd();
	h1B_1->GetXaxis()->SetTitle("p_{T} (#mu_{2}) in B restframe [GeV/c]");
	h1B_0->SetLineColor(kOrange-3); 	 h1B_0->SetFillColor(kOrange-3);    h1B_0->SetFillStyle(3002); h1B_1->SetLineWidth(2); 	h1B_0->SetStats(0);
	h1B_1->SetLineColor(kCyan-3); 	 h1B_1->SetFillColor(kCyan-3);    h1B_1->SetFillStyle(3325); h1B_1->SetLineWidth(2); 	h1B_1->SetStats(0);
	h1B_2->SetLineColor(kBlue-3); 	 h1B_2->SetFillColor(kBlue-3);    h1B_2->SetFillStyle(3352); h1B_2->SetLineWidth(2); 	h1B_2->SetStats(0);
	//h1_3->SetLineColor(kMagenta-3); 	 h1_3->SetFillColor(kMagenta-3);    h1_3->SetFillStyle(3016); h1_3->SetLineWidth(2); h1_3->SetStats(0);
	//h1_4->SetLineColor(kBlue); 	 h1_4->SetFillColor(kBlue);    h1_4->SetFillStyle(3352); h1_4->SetLineWidth(2); h1_4->SetStats(0);
	
	h1B_0->Scale(1/h1B_0->Integral("width"));
	h1B_1->Scale(1/h1B_1->Integral("width"));
	h1B_2->Scale(1/h1B_2->Integral("width"));
	h1B_1->Draw("HIST");
	h1B_0->Draw("HISTSAME");
	h1B_2->Draw("HISTSAME");
	//h1A_2->Draw("HISTSAME");
	//h1A_3->Draw("HISTSAME");
	
	
	auto legend1b = new TLegend(0.42,0.68,0.65,0.9);

	legend1b->AddEntry(h1B_0,"OS with #lambda(N)=0","L");	
	legend1b->AddEntry(h1B_1,"OS #Leftrightarrow #lambda(N)=+1","L");	
	legend1b->AddEntry(h1B_2,"SS #Leftrightarrow #lambda(N)=-1","L");
	//legend->AddEntry(h1_4,"split, tau, pol -1","L");
	//legend->AddEntry(h1_2,"split, Higgs, no pol","L");
	
	legend1b->Draw();
	
	c1B->SaveAs(ODIRNAME+"/H1B.root");
	c1B->SaveAs(ODIRNAME+"/H1B.pdf");
	
	
	/** c2A ************************************************************/
	c2A->cd();
	h2A_1->GetXaxis()->SetTitle("E(#pi) in B restframe [GeV]");
	h2A_0->SetLineColor(kOrange-3); 	 h2A_0->SetFillColor(kOrange-3);    h2A_0->SetFillStyle(3002); h1A_0->SetLineWidth(2); 	h2A_0->SetStats(0);
	h2A_1->SetLineColor(kCyan-3); 	 h2A_1->SetFillColor(kCyan-3);    h2A_1->SetFillStyle(3325); h2A_1->SetLineWidth(2); 	h2A_1->SetStats(0);
	h2A_2->SetLineColor(kBlue-3); 	 h2A_2->SetFillColor(kBlue-3);    h2A_2->SetFillStyle(3352); h2A_2->SetLineWidth(2); 	h2A_2->SetStats(0);
	//h1_3->SetLineColor(kMagenta-3); 	 h1_3->SetFillColor(kMagenta-3);    h1_3->SetFillStyle(3016); h1_3->SetLineWidth(2); h1_3->SetStats(0);
	//h1_4->SetLineColor(kBlue); 	 h1_4->SetFillColor(kBlue);    h1_4->SetFillStyle(3352); h1_4->SetLineWidth(2); h1_4->SetStats(0);
	
	h2A_0->Scale(1/h2A_0->Integral("width"));
	h2A_1->Scale(1/h2A_1->Integral("width"));
	h2A_2->Scale(1/h2A_2->Integral("width"));
	h2A_1->Draw("HIST");
	h2A_0->Draw("HISTSAME");
	h2A_2->Draw("HISTSAME");
	//h1A_2->Draw("HISTSAME");
	//h1A_3->Draw("HISTSAME");
	
	auto legend2a = new TLegend(0.42,0.68,0.65,0.9);
	legend2a->AddEntry(h2A_0,"OS with #lambda(N)=0","L");	
	legend2a->AddEntry(h2A_1,"OS #Leftrightarrow #lambda(N)=+1","L");	
	legend2a->AddEntry(h2A_2,"SS #Leftrightarrow #lambda(N)=-1","L");
	//legend->AddEntry(h1_4,"split, tau, pol -1","L");
	//legend->AddEntry(h1_2,"split, Higgs, no pol","L");
	
	legend2a->Draw();
	c2A->SaveAs(ODIRNAME+"/H2A.root");
	c2A->SaveAs(ODIRNAME+"/H2A.pdf");
	
	
	/** c2B ************************************************************/
	c2B->cd();
	h2B_1->GetXaxis()->SetTitle("p_{T}(#pi) in B restframe [GeV]");
	h2B_0->SetLineColor(kOrange-3); 	 h2B_0->SetFillColor(kOrange-3);    h2B_0->SetFillStyle(3002); h2B_0->SetLineWidth(2); 	h2B_0->SetStats(0);
	h2B_1->SetLineColor(kCyan-3); 	 h2B_1->SetFillColor(kCyan-3);    h2B_1->SetFillStyle(3325); h2B_1->SetLineWidth(2); 	h2B_1->SetStats(0);
	h2B_2->SetLineColor(kBlue-3); 	 h2B_2->SetFillColor(kBlue-3);    h2B_2->SetFillStyle(3352); h2B_2->SetLineWidth(2); 	h2B_2->SetStats(0);
	//h1_3->SetLineColor(kMagenta-3); 	 h1_3->SetFillColor(kMagenta-3);    h1_3->SetFillStyle(3016); h1_3->SetLineWidth(2); h1_3->SetStats(0);
	//h1_4->SetLineColor(kBlue); 	 h1_4->SetFillColor(kBlue);    h1_4->SetFillStyle(3352); h1_4->SetLineWidth(2); h1_4->SetStats(0);
	
	h2B_0->Scale(1/h2B_0->Integral("width"));
	h2B_1->Scale(1/h2B_1->Integral("width"));
	h2B_2->Scale(1/h2B_2->Integral("width"));
	h2B_1->Draw("HIST");
	h2B_0->Draw("HISTSAME");
	h2B_2->Draw("HISTSAME");
	//h1A_2->Draw("HISTSAME");
	//h1A_3->Draw("HISTSAME");
	
	
	auto legend2b = new TLegend(0.42,0.68,0.65,0.9);
	legend2b->AddEntry(h2B_0,"OS with #lambda(N)=0","L");	
	legend2b->AddEntry(h2B_1,"OS #Leftrightarrow #lambda(N)=+1","L");	
	legend2b->AddEntry(h2B_2,"SS #Leftrightarrow #lambda(N)=-1","L");
	//legend->AddEntry(h1_4,"split, tau, pol -1","L");
	//legend->AddEntry(h1_2,"split, Higgs, no pol","L");
	
	legend2b->Draw();
	c2B->SaveAs(ODIRNAME+"/H2B.root");
	c2B->SaveAs(ODIRNAME+"/H2B.pdf");
	
	
	/** c3 ************************************************************/
	c3->cd();
	h3_1->GetXaxis()->SetTitle("Angle between #mu_{1} and #mu_{2} in B restframe");
	h3_0->SetLineColor(kOrange-3); 	 h3_0->SetFillColor(kOrange-3);    h3_0->SetFillStyle(3002); h3_0->SetLineWidth(2); 	h3_0->SetStats(0);
	h3_1->SetLineColor(kCyan-3); 	 h3_1->SetFillColor(kCyan-3);    h3_1->SetFillStyle(3325); h3_1->SetLineWidth(2); 	h3_1->SetStats(0);
	h3_2->SetLineColor(kBlue-3); 	 h3_2->SetFillColor(kBlue-3);    h3_2->SetFillStyle(3352); h3_2->SetLineWidth(2); 	h3_2->SetStats(0);
	//h1_3->SetLineColor(kMagenta-3); 	 h1_3->SetFillColor(kMagenta-3);    h1_3->SetFillStyle(3016); h1_3->SetLineWidth(2); h1_3->SetStats(0);
	//h1_4->SetLineColor(kBlue); 	 h1_4->SetFillColor(kBlue);    h1_4->SetFillStyle(3352); h1_4->SetLineWidth(2); h1_4->SetStats(0);
	
	h3_0->Scale(1/h3_0->Integral("width"));
	h3_1->Scale(1/h3_1->Integral("width"));
	h3_2->Scale(1/h3_2->Integral("width"));
	h3_2->Draw("HIST");
	h3_0->Draw("HISTSAME");
	h3_1->Draw("HISTSAME");
	//h1A_2->Draw("HISTSAME");
	//h1A_3->Draw("HISTSAME");
	
	
	auto legend3 = new TLegend(0.42,0.68,0.65,0.9);
	legend3->AddEntry(h3_0,"OS with #lambda(N)=0","L");	
	legend3->AddEntry(h3_1,"OS #Leftrightarrow #lambda(N)=+1","L");	
	legend3->AddEntry(h3_2,"SS #Leftrightarrow #lambda(N)=-1","L");
	//legend->AddEntry(h1_4,"split, tau, pol -1","L");
	//legend->AddEntry(h1_2,"split, Higgs, no pol","L");
	
	legend3->Draw();
	c3->SaveAs(ODIRNAME+"/H3.root");
	c3->SaveAs(ODIRNAME+"/H3.pdf");
	
	/** c4 ************************************************************/
	c4->cd();
	h4_1->GetXaxis()->SetTitle("cos#theta_{#mu_{2}}");
	h4_0->SetLineColor(kOrange-3); 	 h4_0->SetFillColor(kOrange-3);    h4_0->SetFillStyle(3002); h4_0->SetLineWidth(2); 	h4_0->SetStats(0);
	h4_1->SetLineColor(kCyan-3); 	 h4_1->SetFillColor(kCyan-3);    h4_1->SetFillStyle(3325); h4_1->SetLineWidth(2); 	h4_1->SetStats(0);
	h4_2->SetLineColor(kBlue-3); 	 h4_2->SetFillColor(kBlue-3);    h4_2->SetFillStyle(3352); h4_2->SetLineWidth(2); 	h4_2->SetStats(0);
	//h1_3->SetLineColor(kMagenta-3); 	 h1_3->SetFillColor(kMagenta-3);    h1_3->SetFillStyle(3016); h1_3->SetLineWidth(2); h1_3->SetStats(0);
	//h1_4->SetLineColor(kBlue); 	 h1_4->SetFillColor(kBlue);    h1_4->SetFillStyle(3352); h1_4->SetLineWidth(2); h1_4->SetStats(0);
	
	h4_0->Scale(1/h4_0->Integral("width"));
	h4_1->Scale(1/h4_1->Integral("width"));
	h4_2->Scale(1/h4_2->Integral("width"));
	h4_0->Draw("HIST");
	h4_1->Draw("HISTSAME");
	h4_2->Draw("HISTSAME");
	//h1A_2->Draw("HISTSAME");
	//h1A_3->Draw("HISTSAME");
	
	
	auto legend4 = new TLegend(0.42,0.68,0.65,0.9);

	legend4->AddEntry(h4_0,"OS with #lambda(N)=0","L");	
	legend4->AddEntry(h4_1,"OS #Leftrightarrow #lambda(N)=+1","L");	
	legend4->AddEntry(h4_2,"SS #Leftrightarrow #lambda(N)=-1","L");
	//legend->AddEntry(h1_4,"split, tau, pol -1","L");
	//legend->AddEntry(h1_2,"split, Higgs, no pol","L");
	
	legend4->Draw();
	c4->SaveAs(ODIRNAME+"/H4.root");
	c4->SaveAs(ODIRNAME+"/H4.pdf");
	
	/** c5 ************************************************************/
	c5->cd();
	h5_1->GetXaxis()->SetTitle("p_{z} of mu_{2} in HNL restframe");
	h5_0->SetLineColor(kOrange-3); 	 h5_0->SetFillColor(kOrange-3);    h5_0->SetFillStyle(3002); h5_0->SetLineWidth(2); 	h5_0->SetStats(0);
	h5_1->SetLineColor(kCyan-3); 	 h5_1->SetFillColor(kCyan-3);    h5_1->SetFillStyle(3325); h5_1->SetLineWidth(2); 	h5_1->SetStats(0);
	h5_2->SetLineColor(kBlue-3); 	 h5_2->SetFillColor(kBlue-3);    h5_2->SetFillStyle(3352); h5_2->SetLineWidth(2); 	h5_2->SetStats(0);
	//h1_3->SetLineColor(kMagenta-3); 	 h1_3->SetFillColor(kMagenta-3);    h1_3->SetFillStyle(3016); h1_3->SetLineWidth(2); h1_3->SetStats(0);
	//h1_4->SetLineColor(kBlue); 	 h1_4->SetFillColor(kBlue);    h1_4->SetFillStyle(3352); h1_4->SetLineWidth(2); h1_4->SetStats(0);
	
	h5_0->Scale(1/h5_1->Integral("width"));
	h5_1->Scale(1/h5_1->Integral("width"));
	h5_2->Scale(1/h5_2->Integral("width"));
	h5_1->Draw("HIST");
	h5_0->Draw("HISTSAME");
	h5_2->Draw("HISTSAME");
	//h1A_2->Draw("HISTSAME");
	//h1A_3->Draw("HISTSAME");
	
	
	auto legend5 = new TLegend(0.75,0.7,0.9,0.9);
	legend5->AddEntry(h5_0,"OS with #lambda(N)=0","L");	
	legend5->AddEntry(h5_1,"OS #Leftrightarrow #lambda(N)=+1","L");	
	legend5->AddEntry(h5_2,"SS #Leftrightarrow #lambda(N)=-1","L");
	//legend->AddEntry(h1_4,"split, tau, pol -1","L");
	//legend->AddEntry(h1_2,"split, Higgs, no pol","L");
	
	legend5->Draw();
	c5->SaveAs(ODIRNAME+"/H5.root");
	c5->SaveAs(ODIRNAME+"/H5.pdf");
	
	/** c6 ************************************************************/
	c6->cd();
	h6_1->GetXaxis()->SetTitle("p_{x} of mu_{2} in HNL restframe");
	h6_0->SetLineColor(kOrange-3); 	 h6_0->SetFillColor(kOrange-3);    h6_0->SetFillStyle(3002); h6_0->SetLineWidth(2); 	h6_0->SetStats(0);
	h6_1->SetLineColor(kCyan-3); 	 h6_1->SetFillColor(kCyan-3);    h6_1->SetFillStyle(3325); h6_1->SetLineWidth(2); 	h6_1->SetStats(0);
	h6_2->SetLineColor(kBlue-3); 	 h6_2->SetFillColor(kBlue-3);    h6_2->SetFillStyle(3352); h6_2->SetLineWidth(2); 	h6_2->SetStats(0);
	//h1_3->SetLineColor(kMagenta-3); 	 h1_3->SetFillColor(kMagenta-3);    h1_3->SetFillStyle(3016); h1_3->SetLineWidth(2); h1_3->SetStats(0);
	//h1_4->SetLineColor(kBlue); 	 h1_4->SetFillColor(kBlue);    h1_4->SetFillStyle(3352); h1_4->SetLineWidth(2); h1_4->SetStats(0);
	
	h6_0->Scale(1/h6_0->Integral("width"));
	h6_1->Scale(1/h6_1->Integral("width"));
	h6_2->Scale(1/h6_2->Integral("width"));
	h6_0->Draw("HIST");
	h6_1->Draw("HISTSAME");
	h6_2->Draw("HISTSAME");
	//h1A_2->Draw("HISTSAME");
	//h1A_3->Draw("HISTSAME");
	
	auto legend6 = new TLegend(0.75,0.7,0.9,0.9);
	legend6->AddEntry(h6_0,"OS with #lambda(N)=0","L");	
	legend6->AddEntry(h6_1,"OS #Leftrightarrow #lambda(N)=+1","L");	
	legend6->AddEntry(h6_2,"SS #Leftrightarrow #lambda(N)=-1","L");
	//legend->AddEntry(h1_4,"split, tau, pol -1","L");
	//legend->AddEntry(h1_2,"split, Higgs, no pol","L");
	
	legend6->Draw();
	c6->SaveAs(ODIRNAME+"/H6.root");
	c6->SaveAs(ODIRNAME+"/H6.pdf");
	
	
	
	/** s12 ************************************************************/
	c7->cd();
	h7_1->GetXaxis()->SetTitle("M_^{2}_{B}-M_^{2}_{N}-s_{12}");
	h7_0->SetLineColor(kOrange-3); 	 h7_0->SetFillColor(kOrange-3);    h7_0->SetFillStyle(3002); h7_0->SetLineWidth(2); 	h7_0->SetStats(0);
	h7_1->SetLineColor(kCyan-3); 	 h7_1->SetFillColor(kCyan-3);    h7_1->SetFillStyle(3325); h7_1->SetLineWidth(2); 	h7_1->SetStats(0);
	h7_2->SetLineColor(kBlue-3); 	 h7_2->SetFillColor(kBlue-3);    h7_2->SetFillStyle(3352); h7_2->SetLineWidth(2); 	h7_2->SetStats(0);
	//h1_3->SetLineColor(kMagenta-3); 	 h1_3->SetFillColor(kMagenta-3);    h1_3->SetFillStyle(3016); h1_3->SetLineWidth(2); h1_3->SetStats(0);
	//h1_4->SetLineColor(kBlue); 	 h1_4->SetFillColor(kBlue);    h1_4->SetFillStyle(3352); h1_4->SetLineWidth(2); h1_4->SetStats(0);
	
	h7_0->Scale(1/h7_0->Integral("width"));
	h7_1->Scale(1/h7_1->Integral("width"));
	h7_2->Scale(1/h7_2->Integral("width"));
	h7_1->Draw("HIST");
	h7_0->Draw("HISTSAME");
	h7_2->Draw("HISTSAME");
	//h1A_2->Draw("HISTSAME");
	//h1A_3->Draw("HISTSAME");
	
	auto legend7 = new TLegend(0.75,0.7,0.9,0.9);
	legend7->AddEntry(h7_0,"OS with #lambda(N)=0","L");	
	legend7->AddEntry(h7_1,"OS #Leftrightarrow #lambda(N)=+1","L");	
	legend7->AddEntry(h7_2,"SS #Leftrightarrow #lambda(N)=-1","L");
	//legend->AddEntry(h1_4,"split, tau, pol -1","L");
	//legend->AddEntry(h1_2,"split, Higgs, no pol","L");
	
	legend6->Draw();
	c7->SaveAs(ODIRNAME+"/S12.root");
	c7->SaveAs(ODIRNAME+"/S12.pdf");
	
	
	
}

void split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

std::vector<std::vector<double> > file_to_vec(std::string filename){
	std::vector<std::vector<double> > br_vec(24,std::vector<double>(9, 0));
	std::ifstream file_br(filename);
	std::string line;
	int i1(0);
	while (std::getline(file_br, line)){

        std::vector<std::string> row_values;
        split(line, ' ', row_values);
        for (int i2(0); i2<row_values.size(); i2++){
			std::string v=row_values[i2];
			br_vec[i1][i2]=atof(v.c_str());
		}
		i1++;
	}

	return br_vec;
}
	

