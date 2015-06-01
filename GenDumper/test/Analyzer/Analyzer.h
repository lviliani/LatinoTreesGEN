//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed May 27 17:22:08 2015 by ROOT version 6.02/05
// from TTree myTree/myTree
// found on file: TTbarLL_10000.root
//////////////////////////////////////////////////////////

#ifndef Analyzer_h
#define Analyzer_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"

class Analyzer {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Float_t         pt1;
   Float_t         pt2;
   Float_t         eta1;
   Float_t         eta2;
   Float_t         phi1;
   Float_t         phi2;
   Float_t         lhept1;
   Float_t         lhept2;
   Float_t         lheeta1;
   Float_t         lheeta2;
   Float_t         lhephi1;
   Float_t         lhephi2;
   Float_t         pt3;
   Float_t         pt4;
   Float_t         eta3;
   Float_t         eta4;
   Float_t         phi3;
   Float_t         phi4;
   Float_t         lhept3;
   Float_t         lhept4;
   Float_t         lheeta3;
   Float_t         lheeta4;
   Float_t         lhephi3;
   Float_t         lhephi4;
   Int_t           pdgid1;
   Int_t           pdgid2;
   Int_t           pdgid3;
   Int_t           pdgid4;
   Float_t         status1;
   Float_t         status2;
   Float_t         status3;
   Float_t         status4;
   Int_t           lhepdgid1;
   Int_t           lhepdgid2;
   Int_t           lhepdgid3;
   Int_t           lhepdgid4;
   Float_t         nu_pt1;
   Float_t         nu_pt2;
   Float_t         nu_pt3;
   Float_t         nu_pt4;
   Float_t         nu_eta1;
   Float_t         nu_eta2;
   Float_t         nu_eta3;
   Float_t         nu_eta4;
   Float_t         nu_phi1;
   Float_t         nu_phi2;
   Float_t         nu_phi3;
   Float_t         nu_phi4;
   Int_t           nu_pdgid1;
   Int_t           nu_pdgid2;
   Int_t           nu_pdgid3;
   Int_t           nu_pdgid4;
   Float_t         nu_lhept1;
   Float_t         nu_lhept2;
   Float_t         nu_lheeta1;
   Float_t         nu_lheeta2;
   Float_t         nu_lhephi1;
   Float_t         nu_lhephi2;
   Int_t           nu_lhepdgid1;
   Int_t           nu_lhepdgid2;
   Int_t           nu_lhepdgid3;
   Int_t           nu_lhepdgid4;
   Float_t         nu_lhept3;
   Float_t         nu_lhept4;
   Float_t         nu_lheeta3;
   Float_t         nu_lheeta4;
   Float_t         nu_lhephi3;
   Float_t         nu_lhephi4;
   vector<float>   *std_vector_leptonGen_pt;
   Int_t           njet;
   Float_t         jetpt1;
   Float_t         jetpt2;
   Float_t         jetpt3;
   Float_t         jetpt4;
   Float_t         jeteta1;
   Float_t         jeteta2;
   Float_t         jeteta3;
   Float_t         jeteta4;
   Float_t         jetphi1;
   Float_t         jetphi2;
   Float_t         jetphi3;
   Float_t         jetphi4;
   Float_t         lhejetpt1;
   Float_t         lhejetpt2;
   Float_t         lhejetpt3;
   Float_t         lhejetpt4;
   Float_t         lhejeteta1;
   Float_t         lhejeteta2;
   Float_t         lhejeteta3;
   Float_t         lhejeteta4;
   Float_t         lhejetphi1;
   Float_t         lhejetphi2;
   Float_t         lhejetphi3;
   Float_t         lhejetphi4;
   Float_t         w00;
   Float_t         w01;
   Float_t         w10;
   Float_t         w11;
   Float_t         w12;
   Float_t         w21;
   Float_t         w22;
   vector<double>  *weightsLHE;
   Double_t        weightNominalLHE;
   vector<double>  *weights;
   Double_t        weightSM;

   // List of branches
   TBranch        *b_pt1;   //!
   TBranch        *b_pt2;   //!
   TBranch        *b_eta1;   //!
   TBranch        *b_eta2;   //!
   TBranch        *b_phi1;   //!
   TBranch        *b_phi2;   //!
   TBranch        *b_lhept1;   //!
   TBranch        *b_lhept2;   //!
   TBranch        *b_lheeta1;   //!
   TBranch        *b_lheeta2;   //!
   TBranch        *b_lhephi1;   //!
   TBranch        *b_lhephi2;   //!
   TBranch        *b_pt3;   //!
   TBranch        *b_pt4;   //!
   TBranch        *b_eta3;   //!
   TBranch        *b_eta4;   //!
   TBranch        *b_phi3;   //!
   TBranch        *b_phi4;   //!
   TBranch        *b_lhept3;   //!
   TBranch        *b_lhept4;   //!
   TBranch        *b_lheeta3;   //!
   TBranch        *b_lheeta4;   //!
   TBranch        *b_lhephi3;   //!
   TBranch        *b_lhephi4;   //!
   TBranch        *b_pdgid1;   //!
   TBranch        *b_pdgid2;   //!
   TBranch        *b_pdgid3;   //!
   TBranch        *b_pdgid4;   //!
   TBranch        *b_status1;   //!
   TBranch        *b_status2;   //!
   TBranch        *b_status3;   //!
   TBranch        *b_status4;   //!
   TBranch        *b_lhepdgid1;   //!
   TBranch        *b_lhepdgid2;   //!
   TBranch        *b_lhepdgid3;   //!
   TBranch        *b_lhepdgid4;   //!
   TBranch        *b_nu_pt1;   //!
   TBranch        *b_nu_pt2;   //!
   TBranch        *b_nu_pt3;   //!
   TBranch        *b_nu_pt4;   //!
   TBranch        *b_nu_eta1;   //!
   TBranch        *b_nu_eta2;   //!
   TBranch        *b_nu_eta3;   //!
   TBranch        *b_nu_eta4;   //!
   TBranch        *b_nu_phi1;   //!
   TBranch        *b_nu_phi2;   //!
   TBranch        *b_nu_phi3;   //!
   TBranch        *b_nu_phi4;   //!
   TBranch        *b_nu_pdgid1;   //!
   TBranch        *b_nu_pdgid2;   //!
   TBranch        *b_nu_pdgid3;   //!
   TBranch        *b_nu_pdgid4;   //!
   TBranch        *b_nu_lhept1;   //!
   TBranch        *b_nu_lhept2;   //!
   TBranch        *b_nu_lheeta1;   //!
   TBranch        *b_nu_lheeta2;   //!
   TBranch        *b_nu_lhephi1;   //!
   TBranch        *b_nu_lhephi2;   //!
   TBranch        *b_nu_lhepdgid1;   //!
   TBranch        *b_nu_lhepdgid2;   //!
   TBranch        *b_nu_lhepdgid3;   //!
   TBranch        *b_nu_lhepdgid4;   //!
   TBranch        *b_nu_lhept3;   //!
   TBranch        *b_nu_lhept4;   //!
   TBranch        *b_nu_lheeta3;   //!
   TBranch        *b_nu_lheeta4;   //!
   TBranch        *b_nu_lhephi3;   //!
   TBranch        *b_nu_lhephi4;   //!
   TBranch        *b_std_vector_leptonGen_pt;   //!
   TBranch        *b_njet;   //!
   TBranch        *b_jetpt1;   //!
   TBranch        *b_jetpt2;   //!
   TBranch        *b_jetpt3;   //!
   TBranch        *b_jetpt4;   //!
   TBranch        *b_jeteta1;   //!
   TBranch        *b_jeteta2;   //!
   TBranch        *b_jeteta3;   //!
   TBranch        *b_jeteta4;   //!
   TBranch        *b_jetphi1;   //!
   TBranch        *b_jetphi2;   //!
   TBranch        *b_jetphi3;   //!
   TBranch        *b_jetphi4;   //!
   TBranch        *b_lhejetpt1;   //!
   TBranch        *b_lhejetpt2;   //!
   TBranch        *b_lhejetpt3;   //!
   TBranch        *b_lhejetpt4;   //!
   TBranch        *b_lhejeteta1;   //!
   TBranch        *b_lhejeteta2;   //!
   TBranch        *b_lhejeteta3;   //!
   TBranch        *b_lhejeteta4;   //!
   TBranch        *b_lhejetphi1;   //!
   TBranch        *b_lhejetphi2;   //!
   TBranch        *b_lhejetphi3;   //!
   TBranch        *b_lhejetphi4;   //!
   TBranch        *b_w00;   //!
   TBranch        *b_w01;   //!
   TBranch        *b_w10;   //!
   TBranch        *b_w11;   //!
   TBranch        *b_w12;   //!
   TBranch        *b_w21;   //!
   TBranch        *b_w22;   //!
   TBranch        *b_weightsLHE;   //!
   TBranch        *b_weightNominalLHE;   //!
   TBranch        *b_weights;   //!
   TBranch        *b_weightSM;   //!

   Analyzer(TTree *tree=0);
   virtual ~Analyzer();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef Analyzer_cxx
Analyzer::Analyzer(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.

   //TString FileName = "TTbar_Incl_10000";
   //TString FileName = "TTbarLL_10000";
   TString FileName = "WW_50ns";
   TString FileName_1 = FileName+".root";

   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(Form("%s",FileName_1.Data()));
      if (!f || !f->IsOpen()) {
         f = new TFile(Form("%s",FileName_1.Data()));
      }
      TDirectory * dir = (TDirectory*)f->Get(Form("%s:/Analyzer",FileName_1.Data()));
      dir->GetObject("myTree",tree);

   }
   Init(tree);
}
Analyzer::~Analyzer()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Analyzer::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Analyzer::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void Analyzer::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   std_vector_leptonGen_pt = 0;
   weightsLHE = 0;
   weights = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("pt1", &pt1, &b_pt1);
   fChain->SetBranchAddress("pt2", &pt2, &b_pt2);
   fChain->SetBranchAddress("eta1", &eta1, &b_eta1);
   fChain->SetBranchAddress("eta2", &eta2, &b_eta2);
   fChain->SetBranchAddress("phi1", &phi1, &b_phi1);
   fChain->SetBranchAddress("phi2", &phi2, &b_phi2);
   fChain->SetBranchAddress("lhept1", &lhept1, &b_lhept1);
   fChain->SetBranchAddress("lhept2", &lhept2, &b_lhept2);
   fChain->SetBranchAddress("lheeta1", &lheeta1, &b_lheeta1);
   fChain->SetBranchAddress("lheeta2", &lheeta2, &b_lheeta2);
   fChain->SetBranchAddress("lhephi1", &lhephi1, &b_lhephi1);
   fChain->SetBranchAddress("lhephi2", &lhephi2, &b_lhephi2);
   fChain->SetBranchAddress("pt3", &pt3, &b_pt3);
   fChain->SetBranchAddress("pt4", &pt4, &b_pt4);
   fChain->SetBranchAddress("eta3", &eta3, &b_eta3);
   fChain->SetBranchAddress("eta4", &eta4, &b_eta4);
   fChain->SetBranchAddress("phi3", &phi3, &b_phi3);
   fChain->SetBranchAddress("phi4", &phi4, &b_phi4);
   fChain->SetBranchAddress("lhept3", &lhept3, &b_lhept3);
   fChain->SetBranchAddress("lhept4", &lhept4, &b_lhept4);
   fChain->SetBranchAddress("lheeta3", &lheeta3, &b_lheeta3);
   fChain->SetBranchAddress("lheeta4", &lheeta4, &b_lheeta4);
   fChain->SetBranchAddress("lhephi3", &lhephi3, &b_lhephi3);
   fChain->SetBranchAddress("lhephi4", &lhephi4, &b_lhephi4);
   fChain->SetBranchAddress("pdgid1", &pdgid1, &b_pdgid1);
   fChain->SetBranchAddress("pdgid2", &pdgid2, &b_pdgid2);
   fChain->SetBranchAddress("pdgid3", &pdgid3, &b_pdgid3);
   fChain->SetBranchAddress("pdgid4", &pdgid4, &b_pdgid4);
   fChain->SetBranchAddress("status1", &status1, &b_status1);
   fChain->SetBranchAddress("status2", &status2, &b_status2);
   fChain->SetBranchAddress("status3", &status3, &b_status3);
   fChain->SetBranchAddress("status4", &status4, &b_status4);
   fChain->SetBranchAddress("lhepdgid1", &lhepdgid1, &b_lhepdgid1);
   fChain->SetBranchAddress("lhepdgid2", &lhepdgid2, &b_lhepdgid2);
   fChain->SetBranchAddress("lhepdgid3", &lhepdgid3, &b_lhepdgid3);
   fChain->SetBranchAddress("lhepdgid4", &lhepdgid4, &b_lhepdgid4);
   fChain->SetBranchAddress("nu_pt1", &nu_pt1, &b_nu_pt1);
   fChain->SetBranchAddress("nu_pt2", &nu_pt2, &b_nu_pt2);
   fChain->SetBranchAddress("nu_pt3", &nu_pt3, &b_nu_pt3);
   fChain->SetBranchAddress("nu_pt4", &nu_pt4, &b_nu_pt4);
   fChain->SetBranchAddress("nu_eta1", &nu_eta1, &b_nu_eta1);
   fChain->SetBranchAddress("nu_eta2", &nu_eta2, &b_nu_eta2);
   fChain->SetBranchAddress("nu_eta3", &nu_eta3, &b_nu_eta3);
   fChain->SetBranchAddress("nu_eta4", &nu_eta4, &b_nu_eta4);
   fChain->SetBranchAddress("nu_phi1", &nu_phi1, &b_nu_phi1);
   fChain->SetBranchAddress("nu_phi2", &nu_phi2, &b_nu_phi2);
   fChain->SetBranchAddress("nu_phi3", &nu_phi3, &b_nu_phi3);
   fChain->SetBranchAddress("nu_phi4", &nu_phi4, &b_nu_phi4);
   fChain->SetBranchAddress("nu_pdgid1", &nu_pdgid1, &b_nu_pdgid1);
   fChain->SetBranchAddress("nu_pdgid2", &nu_pdgid2, &b_nu_pdgid2);
   fChain->SetBranchAddress("nu_pdgid3", &nu_pdgid3, &b_nu_pdgid3);
   fChain->SetBranchAddress("nu_pdgid4", &nu_pdgid4, &b_nu_pdgid4);
   fChain->SetBranchAddress("nu_lhept1", &nu_lhept1, &b_nu_lhept1);
   fChain->SetBranchAddress("nu_lhept2", &nu_lhept2, &b_nu_lhept2);
   fChain->SetBranchAddress("nu_lheeta1", &nu_lheeta1, &b_nu_lheeta1);
   fChain->SetBranchAddress("nu_lheeta2", &nu_lheeta2, &b_nu_lheeta2);
   fChain->SetBranchAddress("nu_lhephi1", &nu_lhephi1, &b_nu_lhephi1);
   fChain->SetBranchAddress("nu_lhephi2", &nu_lhephi2, &b_nu_lhephi2);
   fChain->SetBranchAddress("nu_lhepdgid1", &nu_lhepdgid1, &b_nu_lhepdgid1);
   fChain->SetBranchAddress("nu_lhepdgid2", &nu_lhepdgid2, &b_nu_lhepdgid2);
   fChain->SetBranchAddress("nu_lhepdgid3", &nu_lhepdgid3, &b_nu_lhepdgid3);
   fChain->SetBranchAddress("nu_lhepdgid4", &nu_lhepdgid4, &b_nu_lhepdgid4);
   fChain->SetBranchAddress("nu_lhept3", &nu_lhept3, &b_nu_lhept3);
   fChain->SetBranchAddress("nu_lhept4", &nu_lhept4, &b_nu_lhept4);
   fChain->SetBranchAddress("nu_lheeta3", &nu_lheeta3, &b_nu_lheeta3);
   fChain->SetBranchAddress("nu_lheeta4", &nu_lheeta4, &b_nu_lheeta4);
   fChain->SetBranchAddress("nu_lhephi3", &nu_lhephi3, &b_nu_lhephi3);
   fChain->SetBranchAddress("nu_lhephi4", &nu_lhephi4, &b_nu_lhephi4);
   fChain->SetBranchAddress("std_vector_leptonGen_pt", &std_vector_leptonGen_pt, &b_std_vector_leptonGen_pt);
   fChain->SetBranchAddress("njet", &njet, &b_njet);
   fChain->SetBranchAddress("jetpt1", &jetpt1, &b_jetpt1);
   fChain->SetBranchAddress("jetpt2", &jetpt2, &b_jetpt2);
   fChain->SetBranchAddress("jetpt3", &jetpt3, &b_jetpt3);
   fChain->SetBranchAddress("jetpt4", &jetpt4, &b_jetpt4);
   fChain->SetBranchAddress("jeteta1", &jeteta1, &b_jeteta1);
   fChain->SetBranchAddress("jeteta2", &jeteta2, &b_jeteta2);
   fChain->SetBranchAddress("jeteta3", &jeteta3, &b_jeteta3);
   fChain->SetBranchAddress("jeteta4", &jeteta4, &b_jeteta4);
   fChain->SetBranchAddress("jetphi1", &jetphi1, &b_jetphi1);
   fChain->SetBranchAddress("jetphi2", &jetphi2, &b_jetphi2);
   fChain->SetBranchAddress("jetphi3", &jetphi3, &b_jetphi3);
   fChain->SetBranchAddress("jetphi4", &jetphi4, &b_jetphi4);
   fChain->SetBranchAddress("lhejetpt1", &lhejetpt1, &b_lhejetpt1);
   fChain->SetBranchAddress("lhejetpt2", &lhejetpt2, &b_lhejetpt2);
   fChain->SetBranchAddress("lhejetpt3", &lhejetpt3, &b_lhejetpt3);
   fChain->SetBranchAddress("lhejetpt4", &lhejetpt4, &b_lhejetpt4);
   fChain->SetBranchAddress("lhejeteta1", &lhejeteta1, &b_lhejeteta1);
   fChain->SetBranchAddress("lhejeteta2", &lhejeteta2, &b_lhejeteta2);
   fChain->SetBranchAddress("lhejeteta3", &lhejeteta3, &b_lhejeteta3);
   fChain->SetBranchAddress("lhejeteta4", &lhejeteta4, &b_lhejeteta4);
   fChain->SetBranchAddress("lhejetphi1", &lhejetphi1, &b_lhejetphi1);
   fChain->SetBranchAddress("lhejetphi2", &lhejetphi2, &b_lhejetphi2);
   fChain->SetBranchAddress("lhejetphi3", &lhejetphi3, &b_lhejetphi3);
   fChain->SetBranchAddress("lhejetphi4", &lhejetphi4, &b_lhejetphi4);
   fChain->SetBranchAddress("w00", &w00, &b_w00);
   fChain->SetBranchAddress("w01", &w01, &b_w01);
   fChain->SetBranchAddress("w10", &w10, &b_w10);
   fChain->SetBranchAddress("w11", &w11, &b_w11);
   fChain->SetBranchAddress("w12", &w12, &b_w12);
   fChain->SetBranchAddress("w21", &w21, &b_w21);
   fChain->SetBranchAddress("w22", &w22, &b_w22);
   fChain->SetBranchAddress("weightsLHE", &weightsLHE, &b_weightsLHE);
   fChain->SetBranchAddress("weightNominalLHE", &weightNominalLHE, &b_weightNominalLHE);
   fChain->SetBranchAddress("weights", &weights, &b_weights);
   fChain->SetBranchAddress("weightSM", &weightSM, &b_weightSM);
   Notify();
}

Bool_t Analyzer::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Analyzer::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Analyzer::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Analyzer_cxx
