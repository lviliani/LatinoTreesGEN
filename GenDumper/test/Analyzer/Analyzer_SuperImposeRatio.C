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

TCanvas* drawHisto(TH1F* h_Incl, TH1F* h_LL, TString PicName, TString xTitle, TH1F* ratio, TH1F* line){

        gStyle->SetOptStat(0);
        gStyle->SetOptFit(1);
        gStyle->SetPalette(1);
        gStyle->SetOptTitle(0);

TCanvas *c1=new TCanvas("c1","c1",800,600);

TPad *pad1 = new TPad("pad1", "pad1", 0.02, 0.35, 0.98, 0.98);
pad1->SetBottomMargin(0.02);
pad1->SetLeftMargin(0.15);
pad1->Draw();
pad1->cd();

h_Incl -> GetYaxis()->SetTitle("Entries");
h_Incl -> GetXaxis()->SetTitle("");

h_Incl->GetXaxis()->SetTitleOffset(1.1);
h_Incl->GetYaxis()->SetTitleOffset(1.1);
h_Incl->GetXaxis()->SetTitleSize(0.05);
h_Incl->GetYaxis()->SetTitleSize(0.05);
h_Incl->GetXaxis()->SetLabelSize(0.05);
h_Incl->GetYaxis()->SetLabelSize(0.05);
h_Incl->SetMinimum(0);

h_Incl -> SetLineColor(kRed);
h_Incl->SetLineWidth(2);
h_Incl->SetStats(0);

h_LL -> SetLineColor(kBlue+2);
h_LL->SetLineWidth(2);
h_LL->SetStats(0);

c1->SetBottomMargin(0.15);
c1->SetLeftMargin(0.15);

h_Incl -> Draw();
h_LL -> Draw("same");

TLegend *legendPt = new TLegend(0.60,0.75,0.96,0.92);
   legendPt->AddEntry(h_Incl,"TTbar Inclusive","l");
   legendPt->AddEntry(h_LL,"TTbar 2L & 2#nu","l");
   legendPt->Draw();

c1->cd();
TPad *pad2 = new TPad("pad2", "pad2", 0.02, 0.01, 0.98, 0.29);
pad2->SetBottomMargin(0.44);
pad2->SetTopMargin   (0.03);
pad2->SetLeftMargin   (0.15);
pad2->Draw();
pad2->cd();

ratio->SetLineColor(kBlack);
ratio->Divide(h_LL);
ratio->SetMarkerStyle(21);
ratio->Draw("ep");
ratio->SetMaximum(2.0);
ratio->SetMinimum(0.0);

line->Fill(1);
line->SetLineColor(kRed);
line->SetLineStyle(2);
line->Draw("same");

ratio->GetYaxis()->SetTitle("Incl./2L&2#nu");
ratio->GetYaxis()->SetTitleSize(18);
ratio->GetYaxis()->SetTitleFont(43);
ratio->GetYaxis()->SetTitleOffset(1.6);
ratio->GetYaxis()->SetLabelFont(43);
ratio->GetYaxis()->SetLabelSize(18);
ratio->GetYaxis()->SetNdivisions(505);

ratio->GetXaxis()->SetTitle(xTitle);
ratio->GetXaxis()->SetTitleSize(20);
ratio->GetXaxis()->SetTitleFont(43);
ratio->GetXaxis()->SetTitleOffset(1.1);
ratio->GetXaxis()->SetLabelFont(43);
ratio->GetXaxis()->SetLabelSize(18);
ratio->SetStats(0);

c1->SaveAs("SuperImpose_"+PicName+"_v2.png");
return c1;
}

void Analyzer_SuperImposeRatio(){

        gStyle->SetOptStat(0);
        gStyle->SetOptFit(1);
        gStyle->SetPalette(1);
        gStyle->SetOptTitle(0);

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

TH1F *ratio_LHE_pt1 = (TH1F*)h_Incl_LHE_pt1->Clone("ratio");
TH1F *ratio_LHE_pt2 = (TH1F*)h_Incl_LHE_pt2->Clone("ratio");
TH1F *ratio_LHE_eta1 = (TH1F*)h_Incl_LHE_eta1->Clone("ratio");
TH1F *ratio_LHE_eta2 = (TH1F*)h_Incl_LHE_eta2->Clone("ratio");
TH1F *ratio_LHE_phi1 = (TH1F*)h_Incl_LHE_phi1->Clone("ratio");
TH1F *ratio_LHE_phi2 = (TH1F*)h_Incl_LHE_phi2->Clone("ratio");
TH1F *ratio_LHE_higgsM = (TH1F*)h_Incl_LHE_higgsM->Clone("ratio");
TH1F *ratio_LHE_mll = (TH1F*)h_Incl_LHE_mll->Clone("ratio");

TH1F *line_LHE_pt1 = new TH1F("line1","line1",1,0,400);
TH1F *line_LHE_pt2 = new TH1F("line2","line2",1,0,400);
TH1F *line_LHE_eta1 = new TH1F("line3","line3",1,-8,8);
TH1F *line_LHE_eta2 = new TH1F("line4","line4",1,-8,8);
TH1F *line_LHE_phi1 = new TH1F("line5","line5",1,-3.15,3.15);
TH1F *line_LHE_phi2 = new TH1F("line6","line6",1,-3.15,3.15);
TH1F *line_LHE_higgsM = new TH1F("line7","line7",1,0,700);
TH1F *line_LHE_mll = new TH1F("line8","line8",1,0,400);


TString PicNameInput = "lhe_pt1";
TString xTitleInput = "lepton 1: p_{T} [GeV/c]";
drawHisto(h_Incl_LHE_pt1, h_LL_LHE_pt1, PicNameInput, xTitleInput, ratio_LHE_pt1, line_LHE_pt1);

PicNameInput = "lhe_pt2";
xTitleInput = "lepton 2: p_{T} [GeV/c]";
drawHisto(h_Incl_LHE_pt2, h_LL_LHE_pt2, PicNameInput, xTitleInput, ratio_LHE_pt2, line_LHE_pt2);

PicNameInput = "lhe_eta1";
xTitleInput = "lepton 1: #eta ";
drawHisto(h_Incl_LHE_eta1, h_LL_LHE_eta1, PicNameInput, xTitleInput, ratio_LHE_eta1, line_LHE_eta1);

PicNameInput = "lhe_eta2";
xTitleInput = "lepton 2: #eta";
drawHisto(h_Incl_LHE_eta2, h_LL_LHE_eta2, PicNameInput, xTitleInput, ratio_LHE_eta2, line_LHE_eta2);

PicNameInput = "lhe_phi1";
xTitleInput = "lepton 1: #phi";
drawHisto(h_Incl_LHE_phi1, h_LL_LHE_phi1, PicNameInput, xTitleInput, ratio_LHE_phi1, line_LHE_phi1);

PicNameInput = "lhe_phi2";
xTitleInput = "lepton 2: #phi";
drawHisto(h_Incl_LHE_phi2, h_LL_LHE_phi2, PicNameInput, xTitleInput, ratio_LHE_phi2, line_LHE_phi2);

PicNameInput = "lhe_higgsM";
xTitleInput = "mH (2 lepotons + 2 neutrinos) [GeV/c^{2}]";
drawHisto(h_Incl_LHE_higgsM, h_LL_LHE_higgsM, PicNameInput, xTitleInput, ratio_LHE_higgsM, line_LHE_higgsM);

PicNameInput = "lhe_mll";
xTitleInput = "m_{ll} [GeV/c^{2}]";
drawHisto(h_Incl_LHE_mll, h_LL_LHE_mll, PicNameInput, xTitleInput, ratio_LHE_mll, line_LHE_mll);
}
