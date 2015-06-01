#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include<TMatrixD.h>
#include "TFile.h"

#include <TGraph.h>
#include <TH1.h>
#include "TLegend.h"
#include <iostream>
#include "TLorentzVector.h"
#include "TEfficiency.h"
#include <algorithm>
#include "TAxis.h"

TCanvas* drawHisto(TH1F* h_Incl, TH1F* h_LL, TString PicName, TString xTitle){


        gStyle->SetOptStat(0);
        gStyle->SetOptFit(1);
        gStyle->SetPalette(1);
        gStyle->SetOptTitle(0);
TCanvas *c1=new TCanvas("c1","c1",600,400);


//Float_t norm_Incl = 1./(h_Incl->Integral(1,(h_Incl->GetSize()))); // do like that to normalize to 1
//Float_t norm_LL = 1./(h_LL->Integral(1,(h_LL->GetSize()))); // do like that to normalize to 1
//h_Incl-> Scale(norm_Incl);
//h_LL-> Scale(norm_LL);

h_Incl -> GetYaxis()->SetTitle("Entries");
//h_Incl -> GetXaxis()->SetTitle("lepton 1: p_{T} [GeV/c]");
h_Incl -> GetXaxis()->SetTitle(xTitle);

h_Incl->GetXaxis()->SetTitleOffset(1.1);
h_Incl->GetYaxis()->SetTitleOffset(1.1);
h_Incl->GetXaxis()->SetTitleSize(0.05);
h_Incl->GetYaxis()->SetTitleSize(0.05);
h_Incl->GetXaxis()->SetLabelSize(0.05);
h_Incl->GetYaxis()->SetLabelSize(0.05);

h_Incl -> SetLineColor(kRed);
h_Incl->SetLineWidth(2);
h_LL -> SetLineColor(kBlue+2);
h_LL->SetLineWidth(2);

c1->SetBottomMargin(0.15);
c1->SetLeftMargin(0.15);
//Float_t Branching = 1.;
//if(FileName == "TTbar_Incl_10000") Branching = 1.;
//if(FileName == "TTbarLL_10000") Branching = 0.045;//e, mu (ee, mumu, emu) decays only, reject tau
//h_Incl-> Scale(Branching);
h_Incl -> Draw();
h_LL -> Draw("same");
//TLegend *legendPt = new TLegend(0.40,0.65,0.76,0.82);
TLegend *legendPt = new TLegend(0.60,0.75,0.96,0.92);
   legendPt->AddEntry(h_Incl,"TTbar Inclusive","l");
   legendPt->AddEntry(h_LL,"TTbar 2L & 2#nu","l");
      //h_Incl->AddEntry(h_Incl,Form("VBF Sel.: %6.0f events", h_Incl->GetEntries()),"l");
      legendPt->Draw();
      c1->SaveAs("SuperImpose_"+PicName+".png");
      return c1;
}

void Analyzer_SuperImpose(){

        //gROOT->Clear();
        gStyle->SetOptStat(0);
        gStyle->SetOptFit(1);
        gStyle->SetPalette(1);
        gStyle->SetOptTitle(0);

//TFile *f1 = new TFile(Form("/afs/cern.ch/user/j/jungmin/public/RECO_new/HistRECO_uvev_E8_SIB_1M_selNoTop_Mjj.root",Energy));
TFile *f_Incl = TFile::Open("TTbar_Incl_10000_out.root");
TFile *f_LL = TFile::Open("TTbarLL_10000_out.root");

TH1F* h_Incl_LHE_pt1 = (TH1F*)f_Incl->Get("h_LHE_pt1");
TH1F* h_Incl_LHE_pt2 = (TH1F*)f_Incl->Get("h_LHE_pt2");
TH1F* h_Incl_LHE_eta1 = (TH1F*)f_Incl->Get("h_LHE_eta1");
TH1F* h_Incl_LHE_eta2 = (TH1F*)f_Incl->Get("h_LHE_eta2");
TH1F* h_Incl_LHE_phi1 = (TH1F*)f_Incl->Get("h_LHE_phi1");
TH1F* h_Incl_LHE_phi2 = (TH1F*)f_Incl->Get("h_LHE_phi2");
TH1F* h_Incl_LHE_higgsM = (TH1F*)f_Incl->Get("h_LHE_higgsM");
TH1F* h_Incl_LHE_mll = (TH1F*)f_Incl->Get("h_LHE_mll");

TH1F* h_LL_LHE_pt1 = (TH1F*)f_LL->Get("h_LHE_pt1");
TH1F* h_LL_LHE_pt2 = (TH1F*)f_LL->Get("h_LHE_pt2");
TH1F* h_LL_LHE_eta1 = (TH1F*)f_LL->Get("h_LHE_eta1");
TH1F* h_LL_LHE_eta2 = (TH1F*)f_LL->Get("h_LHE_eta2");
TH1F* h_LL_LHE_phi1 = (TH1F*)f_LL->Get("h_LHE_phi1");
TH1F* h_LL_LHE_phi2 = (TH1F*)f_LL->Get("h_LHE_phi2");
TH1F* h_LL_LHE_higgsM = (TH1F*)f_LL->Get("h_LHE_higgsM");
TH1F* h_LL_LHE_mll = (TH1F*)f_LL->Get("h_LHE_mll");

TString PicNameInput = "lhe_pt1";
TString xTitleInput = "lepton 1: p_{T} [GeV/c]";
drawHisto(h_Incl_LHE_pt1, h_LL_LHE_pt1, PicNameInput, xTitleInput);

PicNameInput = "lhe_pt2";
xTitleInput = "lepton 2: p_{T} [GeV/c]";
drawHisto(h_Incl_LHE_pt2, h_LL_LHE_pt2, PicNameInput, xTitleInput);

PicNameInput = "lhe_eta1";
xTitleInput = "lepton 1: #eta ";
drawHisto(h_Incl_LHE_eta1, h_LL_LHE_eta1, PicNameInput, xTitleInput);

PicNameInput = "lhe_eta2";
xTitleInput = "lepton 2: #eta";
drawHisto(h_Incl_LHE_eta2, h_LL_LHE_eta2, PicNameInput, xTitleInput);

PicNameInput = "lhe_phi1";
xTitleInput = "lepton 1: #phi";
drawHisto(h_Incl_LHE_phi1, h_LL_LHE_phi1, PicNameInput, xTitleInput);

PicNameInput = "lhe_phi2";
xTitleInput = "lepton 2: #phi";
drawHisto(h_Incl_LHE_phi2, h_LL_LHE_phi2, PicNameInput, xTitleInput);

PicNameInput = "lhe_higgsM";
xTitleInput = "mH (2 lepotons + 2 neutrinos) [GeV/c^{2}]";
drawHisto(h_Incl_LHE_higgsM, h_LL_LHE_higgsM, PicNameInput, xTitleInput);

PicNameInput = "lhe_mll";
xTitleInput = "m_{ll} [GeV/c^{2}]";
drawHisto(h_Incl_LHE_mll, h_LL_LHE_mll, PicNameInput, xTitleInput);
}
