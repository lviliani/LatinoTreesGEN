#define Analyzer_cxx
#include "Analyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

#include <TGraph.h>
#include <TH1.h>
#include "TLegend.h"
#include <iostream>
#include "TLorentzVector.h"
#include "TEfficiency.h"
#include <algorithm>
#include "TAxis.h"

//TString FileName = "TTbar_Incl_10000";
//TString FileName = "TTbarLL_10000";
TString FileName = "WW_50ns";

///////////////////////////////////
TCanvas* drawHisto(TH1F* h1, TString PicName, TString xTitle){
TCanvas *c1=new TCanvas("c1","c1",600,400);
//h1->Sumw2();
h1 -> SetLineColor(kRed+2);
//h1 -> SetMinimum(0.);
//h1 -> SetMinimum(-10.);
//h1->SetAxisRange(0., 30.,"Y");
//h1->GetYaxis()->SetRangeUser(-10.,40.);

if(FileName == "WW_50ns")h1->SetTitle("WW background 50 ns");

h1 -> GetYaxis()->SetTitle("Entries");
//h1 -> GetXaxis()->SetTitle("lepton 1: p_{T} [GeV/c]");
h1 -> GetXaxis()->SetTitle(xTitle);

h1->GetXaxis()->SetTitleOffset(1.1);
h1->GetYaxis()->SetTitleOffset(1.1);
h1->GetXaxis()->SetTitleSize(0.05);
h1->GetYaxis()->SetTitleSize(0.05);
h1->GetXaxis()->SetLabelSize(0.05);
h1->GetYaxis()->SetLabelSize(0.05);
h1->SetLineWidth(2);
c1->SetBottomMargin(0.15);
c1->SetLeftMargin(0.15);
Float_t Branching = 1.;
if(FileName == "TTbar_Incl_10000") Branching = 1.;
if(FileName == "TTbarLL_10000") Branching = 0.107;//0.109*0.109*(3+2*3) e, mu, tau in 2L2nu sample originally
h1-> Scale(Branching);
h1 -> Draw();
TLegend *legendPt = new TLegend(0.40,0.65,0.76,0.82);
   legendPt->AddEntry(h1,"test","l");
      //h1->AddEntry(h1,Form("VBF Sel.: %6.0f events", h1->GetEntries()),"l");
      //legendPt->Draw();
      //TString PicName = "lhe_pt1";
      c1->SaveAs(FileName+"_"+PicName+".png");
      //cout << "Test" << endl;

return c1;

//delete c1;
}

void Analyzer::Loop()
{
//   In a ROOT session, you can do:
//      root> .L Analyzer.C
//      root> Analyzer t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

 TFile* Plots = new TFile (FileName+"_out.root","recreate");
  Plots->cd();

Float_t MaxBin_pt = 200.;
Float_t MaxBin_mH = 700.;
Float_t MaxBin_mll = 400.;

TH1F* h_LHE_pt1 = new TH1F("h_LHE_pt1","h_LHE_pt1",50,0.,MaxBin_pt);
TH1F* h_LHE_pt2 = new TH1F("h_LHE_pt2","h_LHE_pt2",50,0.,MaxBin_pt);
TH1F* h_LHE_eta1 = new TH1F("h_LHE_eta1","h_LHE_eta1",50,-8.,8.);
TH1F* h_LHE_eta2 = new TH1F("h_LHE_eta2","h_LHE_eta2",50,-8.,8.);
TH1F* h_LHE_phi1 = new TH1F("h_LHE_phi1","h_LHE_phi1",25,-3.15,3.15);
TH1F* h_LHE_phi2 = new TH1F("h_LHE_phi2","h_LHE_phi2",25,-3.15,3.15);
TH1F* h_LHE_higgsM = new TH1F("h_LHE_higgsM","LHE Higgs Mass",50,100.,MaxBin_mH);
TH1F* h_LHE_mll = new TH1F("h_LHE_mll","mll",50,0.,MaxBin_mll);

h_LHE_pt1->Sumw2();
h_LHE_pt2->Sumw2();
h_LHE_eta1->Sumw2();
h_LHE_eta2->Sumw2();
h_LHE_phi1->Sumw2();
h_LHE_phi2->Sumw2();
h_LHE_higgsM->Sumw2();
h_LHE_mll->Sumw2();
///////////////////////////////////
   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      //reject tau decay:
      if(abs(lhepdgid1) > 14 || lhepdgid1 == 0) continue;
      if(abs(lhepdgid2) > 14 || lhepdgid2 == 0) continue;
      if(abs(nu_lhepdgid1) > 15 || nu_lhepdgid1 == 0) continue;
      if(abs(nu_lhepdgid2) > 15 || nu_lhepdgid2 == 0) continue;

      TLorentzVector l1LHE;
      TLorentzVector l2LHE;
      TLorentzVector nu1LHE;
      TLorentzVector nu2LHE;
      l1LHE.SetPtEtaPhiM(lhept1, lheeta1, lhephi1, 0.);
      l2LHE.SetPtEtaPhiM(lhept2, lheeta2, lhephi2, 0.);
      nu1LHE.SetPtEtaPhiM(nu_lhept1, nu_lheeta1, nu_lhephi1, 0.);
      nu2LHE.SetPtEtaPhiM(nu_lhept2, nu_lheeta2, nu_lhephi2, 0.);

      TLorentzVector higgsLHE;
      higgsLHE = l1LHE + l2LHE + nu1LHE + nu2LHE;

      TLorentzVector llLHE;
      llLHE = l1LHE + l2LHE;

      if(lheeta1 > -90 && lheeta2 > -90 && nu_lheeta1 > -90 && nu_lheeta2 > -90){
        if(higgsLHE.M() < MaxBin_mH) {h_LHE_higgsM -> Fill(higgsLHE.M());}
        else {h_LHE_higgsM -> Fill(MaxBin_mH - 0.001);}
      }
      if(lheeta1 > -90 && lheeta2 > -90){
        if(llLHE.M() < MaxBin_mll) {h_LHE_mll -> Fill(llLHE.M());}
        else {h_LHE_mll -> Fill(MaxBin_mll - 0.001);}
      }


      if(lheeta1 > -90) {
        if (lhept1 < MaxBin_pt){h_LHE_pt1 -> Fill(lhept1);}
        else {h_LHE_pt1 -> Fill(MaxBin_pt-0.001);}
      }

      if(lheeta2 > -90) {
        if (lhept2 < MaxBin_pt){h_LHE_pt2 -> Fill(lhept2);}
        else {h_LHE_pt2 -> Fill(MaxBin_pt-0.001);}
      }
    h_LHE_eta1 -> Fill(lheeta1);
    h_LHE_eta2 -> Fill(lheeta2);
    h_LHE_phi1 -> Fill(lhephi1);
    h_LHE_phi2 -> Fill(lhephi2);
   }


   // gStyle->SetOptStat(0);
   // gStyle->SetOptFit(1);
    gStyle->SetPalette(1);
    gStyle->SetOptTitle(0);
    // gStyle->SetPadLeftMargin(0.14);

TString PicNameInput = "lhe_pt1";
TString xTitleInput = "lepton 1: p_{T} [GeV/c]";
drawHisto(h_LHE_pt1, PicNameInput, xTitleInput);

PicNameInput = "lhe_pt2";
xTitleInput = "lepton 2: p_{T} [GeV/c]";
drawHisto(h_LHE_pt2, PicNameInput, xTitleInput);

PicNameInput = "lhe_eta1";
xTitleInput = "lepton 1: #eta ";
drawHisto(h_LHE_eta1, PicNameInput, xTitleInput);

PicNameInput = "lhe_eta2";
xTitleInput = "lepton 2: #eta";
drawHisto(h_LHE_eta2, PicNameInput, xTitleInput);

PicNameInput = "lhe_phi1";
xTitleInput = "lepton 1: #phi";
drawHisto(h_LHE_phi1, PicNameInput, xTitleInput);

PicNameInput = "lhe_phi2";
xTitleInput = "lepton 2: #phi";
drawHisto(h_LHE_phi2, PicNameInput, xTitleInput);

PicNameInput = "lhe_higgsM";
xTitleInput = "mH (2 lepotons + 2 neutrinos) [GeV/c^{2}]";
drawHisto(h_LHE_higgsM, PicNameInput, xTitleInput);

PicNameInput = "lhe_mll";
xTitleInput = "m_{ll} [GeV/c^{2}]";
drawHisto(h_LHE_mll, PicNameInput, xTitleInput);

Plots->Write();
Plots->Close();

}
