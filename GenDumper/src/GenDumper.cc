// -*- C++ -*-
//
// Package:    GenDumper
// Class:      GenDumper
// 
/**\class GenDumper GenDumper.cc UEPS/GenDumper/src/GenDumper.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Andrea Massironi,42 2-027,+41227662346,
//         Created:  lun feb 10 17:03:36 CET 2014
// $Id$
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"


//---- for auto-tree
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "TTree.h"



//---- for GenParticles
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
// #include "DataFormats/Candidate/interface/Candidate.h"

//---- for GenJets
#include "DataFormats/JetReco/interface/GenJet.h" 

//---- for DeltaR
#include "Math/VectorUtil.h"
//---- for DeltaPhi
#include "DataFormats/Math/interface/deltaPhi.h"

//---- for LHE information
#include "SimDataFormats/GeneratorProducts/interface/LHEEventProduct.h"
#include "SimDataFormats/GeneratorProducts/interface/LHERunInfoProduct.h"
#include "SimDataFormats/GeneratorProducts/interface/LHEXMLStringProduct.h"
#include <fstream> 

//---- TLorentzVector
#include "TLorentzVector.h"

//---- to get weights
#include "SimDataFormats/GeneratorProducts/interface/GenEventInfoProduct.h"

//
// class declaration
//

class GenDumper : public edm::EDAnalyzer {
   public:
      explicit GenDumper(const edm::ParameterSet&);
      ~GenDumper();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


   private:
      virtual void beginJob() ;
      virtual void analyze(const edm::Event&, const edm::EventSetup&);
      virtual void endJob() ;

      virtual void beginRun(edm::Run const&, edm::EventSetup const&);
      virtual void endRun(edm::Run const&, edm::EventSetup const&);
      virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);
      virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);
      bool isJetALepton(float phi, float eta, edm::Handle<reco::GenParticleCollection> genParticles);
      bool isJetALepton(float phi, float eta, lhef::HEPEUP LHEhepeup);

      // ----------member data ---------------------------
      edm::InputTag GenJetCollection_;
      edm::InputTag GenParticlesCollection_;
      edm::InputTag mcLHEEventInfoTag_;
      edm::InputTag genEvtInfoTag_;
      bool dumpWeights_;
      bool _debug;
      
      
      TTree* myTree_;
      //---- lepton
      float pt_[10];
      float eta_[10];
      float phi_[10];
      float lhept_[10];
      float lheeta_[10];
      float lhephi_[10];

      //---- jets
      int njet_;
      float jetpt_[10];
      float jeteta_[10];
      float jetphi_[10];
      float lhejetpt_[10];
      float lhejeteta_[10];
      float lhejetphi_[10];

      //---- MC qcd scale
      std::vector <double> _weightsLHE;
      double _weightNominalLHE;
      std::vector <double> _weights;
      double _weightSM;
      float w00_;
      float w01_;
      float w10_;
      float w11_;
      float w12_;
      float w21_;
      float w22_;

};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
GenDumper::GenDumper(const edm::ParameterSet& iConfig)

{
 //now do what ever initialization is needed
 GenJetCollection_       = iConfig.getParameter<edm::InputTag>("GenJetCollection");
 GenParticlesCollection_ = iConfig.getParameter<edm::InputTag>("GenParticlesCollection");
 mcLHEEventInfoTag_      = iConfig.getParameter<edm::InputTag>("mcLHEEventInfoTag");
 genEvtInfoTag_          = iConfig.getParameter<edm::InputTag>("genEvtInfoTag");
 dumpWeights_            = iConfig.getUntrackedParameter< bool >("dumpWeights",false);
 _debug                  = iConfig.getUntrackedParameter< bool >("debug",false);
 
 
 edm::Service<TFileService> fs ;
 myTree_ = fs -> make <TTree>("myTree","myTree");

 myTree_ -> Branch("pt1", &pt_[0], "pt1/F");
 myTree_ -> Branch("pt2", &pt_[1], "pt2/F");
 myTree_ -> Branch("eta1", &eta_[0], "eta1/F");
 myTree_ -> Branch("eta2", &eta_[1], "eta2/F");
 myTree_ -> Branch("phi1", &phi_[0], "phi1/F");
 myTree_ -> Branch("phi2", &phi_[1], "phi2/F");
 myTree_ -> Branch("lhept1", &lhept_[0], "lhept1/F");
 myTree_ -> Branch("lhept2", &lhept_[1], "lhept2/F");
 myTree_ -> Branch("lheeta1", &lheeta_[0], "lheeta1/F");
 myTree_ -> Branch("lheeta2", &lheeta_[1], "lheeta2/F");
 myTree_ -> Branch("lhephi1", &lhephi_[0], "lhephi1/F");
 myTree_ -> Branch("lhephi2", &lhephi_[1], "lhephi2/F");
 myTree_ -> Branch("pt3", &pt_[2], "pt3/F");
 myTree_ -> Branch("pt4", &pt_[3], "pt4/F");
 myTree_ -> Branch("eta3", &eta_[2], "eta3/F");
 myTree_ -> Branch("eta4", &eta_[3], "eta4/F");
 myTree_ -> Branch("phi3", &phi_[2], "phi3/F");
 myTree_ -> Branch("phi4", &phi_[3], "phi4/F");
 myTree_ -> Branch("lhept3", &lhept_[2], "lhept3/F");
 myTree_ -> Branch("lhept4", &lhept_[3], "lhept4/F");
 myTree_ -> Branch("lheeta3", &lheeta_[2], "lheeta3/F");
 myTree_ -> Branch("lheeta4", &lheeta_[3], "lheeta4/F");
 myTree_ -> Branch("lhephi3", &lhephi_[2], "lhephi3/F");
 myTree_ -> Branch("lhephi4", &lhephi_[3], "lhephi4/F");
 
 myTree_ -> Branch("njet", &njet_, "njet/I");
 myTree_ -> Branch("jetpt1", &jetpt_[0], "jetpt1/F");
 myTree_ -> Branch("jetpt2", &jetpt_[1], "jetpt2/F");
 myTree_ -> Branch("jetpt3", &jetpt_[2], "jetpt3/F");
 myTree_ -> Branch("jetpt4", &jetpt_[3], "jetpt4/F");
 myTree_ -> Branch("jeteta1", &jeteta_[0], "jeteta1/F");
 myTree_ -> Branch("jeteta2", &jeteta_[1], "jeteta2/F");
 myTree_ -> Branch("jeteta3", &jeteta_[2], "jeteta3/F");
 myTree_ -> Branch("jeteta4", &jeteta_[3], "jeteta4/F");
 myTree_ -> Branch("jetphi1", &jetphi_[0], "jetphi1/F");
 myTree_ -> Branch("jetphi2", &jetphi_[1], "jetphi2/F");
 myTree_ -> Branch("jetphi3", &jetphi_[2], "jetphi3/F");
 myTree_ -> Branch("jetphi4", &jetphi_[3], "jetphi4/F");

 
 myTree_ -> Branch("lhejetpt1", &lhejetpt_[0], "lhejetpt1/F");
 myTree_ -> Branch("lhejetpt2", &lhejetpt_[1], "lhejetpt2/F");
 myTree_ -> Branch("lhejetpt3", &lhejetpt_[2], "lhejetpt3/F");
 myTree_ -> Branch("lhejetpt4", &lhejetpt_[3], "lhejetpt4/F");
 myTree_ -> Branch("lhejeteta1", &lhejeteta_[0], "lhejeteta1/F");
 myTree_ -> Branch("lhejeteta2", &lhejeteta_[1], "lhejeteta2/F");
 myTree_ -> Branch("lhejeteta3", &lhejeteta_[2], "lhejeteta3/F");
 myTree_ -> Branch("lhejeteta4", &lhejeteta_[3], "lhejeteta4/F");
 myTree_ -> Branch("lhejetphi1", &lhejetphi_[0], "lhejetphi1/F");
 myTree_ -> Branch("lhejetphi2", &lhejetphi_[1], "lhejetphi2/F");
 myTree_ -> Branch("lhejetphi3", &lhejetphi_[2], "lhejetphi3/F");
 myTree_ -> Branch("lhejetphi4", &lhejetphi_[3], "lhejetphi4/F");

 myTree_ -> Branch("w00", &w00_, "w00/F");
 myTree_ -> Branch("w01", &w01_, "w01/F");
 myTree_ -> Branch("w10", &w10_, "w10/F");
 myTree_ -> Branch("w11", &w11_, "w11/F");
 myTree_ -> Branch("w12", &w12_, "w12/F");
 myTree_ -> Branch("w21", &w21_, "w21/F");
 myTree_ -> Branch("w22", &w22_, "w22/F");
 
 myTree_ -> Branch("weightsLHE", "std::vector<double>", &_weightsLHE);
 myTree_ -> Branch("weightNominalLHE", &_weightNominalLHE, "weightNominalLHE/D");
 myTree_ -> Branch("weights", "std::vector<double>", &_weights);
 myTree_ -> Branch("weightSM", &_weightSM, "weightSM/D");
 
 
}


GenDumper::~GenDumper()
{

   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void GenDumper::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup) {

 edm::Handle<GenEventInfoProduct> genEvtInfo;
 iEvent.getByLabel( genEvtInfoTag_, genEvtInfo );
 
 edm::Handle<reco::GenParticleCollection> genParticles;
 iEvent.getByLabel(GenParticlesCollection_,genParticles);

 edm::Handle<reco::GenJetCollection> genJet;
 iEvent.getByLabel(GenJetCollection_,genJet);

 edm::Handle<LHEEventProduct> productLHEHandle;
 iEvent.getByLabel(mcLHEEventInfoTag_, productLHEHandle);

 lhef::HEPEUP LHEhepeup = (*(productLHEHandle.product())).hepeup();

 
 
//  const int nup_ = LHEhepeup.NUP; 
//  const std::vector<int> idup_ = LHEhepeup.IDUP;
//  const std::vector<lhef::HEPEUP::FiveVector> pup_ = LHEhepeup.PUP;
//  
//  std::cout << "Number of particles = " << nup_ << std::endl;
//  
//  if ( productLHEHandle->pdf() != NULL ) {
//   std::cout << "PDF scale = " << std::setw(14) << std::fixed << productLHEHandle->pdf()->scalePDF << std::endl;  
//   std::cout << "PDF 1 : id = " << std::setw(14) << std::fixed << productLHEHandle->pdf()->id.first 
//   << " x = " << std::setw(14) << std::fixed << productLHEHandle->pdf()->x.first 
//   << " xPDF = " << std::setw(14) << std::fixed << productLHEHandle->pdf()->xPDF.first << std::endl;  
//   std::cout << "PDF 2 : id = " << std::setw(14) << std::fixed << productLHEHandle->pdf()->id.second 
//   << " x = " << std::setw(14) << std::fixed << productLHEHandle->pdf()->x.second 
//   << " xPDF = " << std::setw(14) << std::fixed << productLHEHandle->pdf()->xPDF.second << std::endl;  
//  }
//  
//  for ( unsigned int icount = 0 ; icount < (unsigned int)nup_; icount++ ) {
//   
//   std::cout << "# " << std::setw(14) << std::fixed << icount 
//   << std::setw(14) << std::fixed << idup_[icount] 
//   << std::setw(14) << std::fixed << (pup_[icount])[0] 
//   << std::setw(14) << std::fixed << (pup_[icount])[1] 
//   << std::setw(14) << std::fixed << (pup_[icount])[2] 
//   << std::setw(14) << std::fixed << (pup_[icount])[3] 
//   << std::setw(14) << std::fixed << (pup_[icount])[4] 
//   << std::endl;
//  }
//  if( productLHEHandle->weights().size() ) {
//   std::cout << "weights:" << std::endl;
//   for ( size_t iwgt = 0; iwgt < productLHEHandle->weights().size(); ++iwgt ) {
//    const LHEEventProduct::WGT& wgt = productLHEHandle->weights().at(iwgt);
//    std::cout << "\t" << wgt.id << ' ' 
//    << std::scientific << wgt.wgt << std::endl;
//   }
//  }
 

 for (int i=0; i<4; i++) {
  pt_[i]  = 0;
  eta_[i]  = -99;
  phi_[i]  = -99;
 }

  for (int i=0; i<4; i++) {
  jetpt_[i]  = 0;
  jeteta_[i] = -99;
  jetphi_[i] = -99;
 }

 njet_ = 0;
 int itcount = 0;
 for (reco::GenJetCollection::const_iterator genJetIter=genJet->begin(); genJetIter!=genJet->end(); genJetIter++){
  float phi = genJetIter->phi();
  float pt  = genJetIter->pt();
  float eta = genJetIter->eta();

//   bool isLepton = isJetALepton(phi,eta,genParticles);
  bool isLepton = isJetALepton(phi,eta,LHEhepeup);

  if (isLepton == false) {

   if (itcount < 4) {
    jetpt_[itcount]  = pt;
    jeteta_[itcount] = eta;
    jetphi_[itcount] = phi;
   }
   if (pt > 30) njet_++;
   itcount++;
  }
 }

 //---- gen leptons
 itcount = 0;
 for (reco::GenParticleCollection::const_iterator genPart = genParticles->begin(); genPart != genParticles->end(); genPart++){
  int id = abs(genPart->pdgId());
  if (id == 11 || id == 13 || id == 15) { //---- e/mu/tau
   if (itcount < 4) {
    pt_[itcount]  = genPart->pt();
    eta_[itcount] = genPart->eta();
    phi_[itcount] = genPart->phi();
   }
   itcount++;
  }
 }

 //---- LHE information ----

 for (int i=0; i<4; i++) {
  lhept_[i]  = 0;
  lheeta_[i] = -99;
  lhephi_[i] = -99;
 }

 for (int i=0; i<4; i++) {
  lhejetpt_[i]  = 0;
  lhejeteta_[i] = -99;
  lhejetphi_[i] = -99;
 }

 itcount = 0;
 // loop over particles in the event
 for (unsigned int iPart = 0 ; iPart < LHEhepeup.IDUP.size (); ++iPart) {
  // outgoing particles
  if (LHEhepeup.ISTUP.at (iPart) == 1) {
   int type = abs (LHEhepeup.IDUP.at (iPart)) ;
//     if (type < 7) {
   //-----      quarks       or     gluons
   if ((type < 9 && type > 0) || type == 21) {
    float pt = (
               sqrt (
                    LHEhepeup.PUP.at (iPart) [0] * LHEhepeup.PUP.at (iPart) [0] + // px
                    LHEhepeup.PUP.at (iPart) [1] * LHEhepeup.PUP.at (iPart) [1]  // py
                    )
              );
    if (itcount < 4) {
     lhejetpt_[itcount]  = pt;
    }
//     std::cout << "     itcount = " << itcount << " pt = " << pt << std::endl;
    itcount++;
   }
  }
 }


 itcount = 0;
 // loop over particles in the event
 for (unsigned int iPart = 0 ; iPart < LHEhepeup.IDUP.size (); ++iPart) {
  // outgoing particles
  if (LHEhepeup.ISTUP.at (iPart) == 1) {
   int type = abs (LHEhepeup.IDUP.at (iPart)) ;
   //-----      leptons
   if (type == 11 || type == 13 || type == 15) {
    TLorentzVector dummy (
                         LHEhepeup.PUP.at (iPart) [0], // px
                         LHEhepeup.PUP.at (iPart) [1], // py
                         LHEhepeup.PUP.at (iPart) [2], // pz
                         LHEhepeup.PUP.at (iPart) [3] // E
                         ) ;

    if (itcount < 4) {
     lhept_[itcount]   = dummy.Pt();
     lheeta_[itcount]  = dummy.Eta();
     lhephi_[itcount]  = dummy.Phi();
    }
    itcount++;
   }
  }
 }


 //---- See https://twiki.cern.ch/twiki/bin/view/CMSPublic/SWGuideDataFormatGeneratorInterface
 //---- weights: from EventInfo and from LHE
 
 std::vector<double> evtWeights = genEvtInfo->weights();
 _weightSM = genEvtInfo->weight();
 
 for (unsigned int iWeight = 0; iWeight < evtWeights.size(); iWeight++) {
  if (_debug) std::cout << " evtWeights[" << iWeight << "] = " << evtWeights.at(iWeight) << std::endl;
  _weights.push_back(evtWeights.at(iWeight));
 }
 if (_debug) std::cout << " weightSM = " << _weightSM << std::endl;
 
 
 unsigned int num_whichWeight = productLHEHandle->weights().size();
 for (unsigned int iWeight = 0; iWeight < num_whichWeight; iWeight++) {
  _weightsLHE.push_back( productLHEHandle->weights()[iWeight].wgt/productLHEHandle->originalXWGTUP() ); 
  if (_debug) std::cout << " weightLHE[" << iWeight << "] = " << productLHEHandle->weights()[iWeight].wgt << std::endl;
 }
 _weightNominalLHE = productLHEHandle->originalXWGTUP();
 
 if (_debug) std::cout << " weightNominalLHE = " << _weightNominalLHE << std::endl;
 if (_debug) std::cout << " ---------- " << std::endl;
 
 //---- old style weights, encoded in the "comments" with "#"
 if (dumpWeights_) {
  //---- QCD scale
  std::vector<std::string> comments_LHE;
  std::vector<float> comments_LHE_weight;
  std::vector<float> comments_LHE_rfac;
  std::vector<float> comments_LHE_ffac;
  //---- mu mu weight
  std::map < std::pair<float, float>, float > weights;
  
  std::vector<std::string>::const_iterator it_end = (*(productLHEHandle.product())).comments_end();
  std::vector<std::string>::const_iterator it = (*(productLHEHandle.product())).comments_begin();
  for(; it != it_end; it++) {
   comments_LHE.push_back (*it);
  }
  
  for (unsigned int iComm = 0; iComm<comments_LHE.size(); iComm++) {
   /// #new weight,renfact,facfact,pdf1,pdf2 32.2346904790193 1.00000000000000 1.00000000000000 11000 11000 lha
   std::stringstream line( comments_LHE.at(iComm) );
   std::string dummy;
   line >> dummy; // #new weight,renfact,facfact,pdf1,pdf2
   line >> dummy;
   float dummy_float;
   line >> dummy_float; // 32.2346904790193
   comments_LHE_weight.push_back(dummy_float);
   float dummy_float_weight = dummy_float;
   line >> dummy_float; // 1.00000000000000
   comments_LHE_rfac.push_back(dummy_float);
   float dummy_float_mu1 = dummy_float;
   line >> dummy_float; // 1.00000000000000
   comments_LHE_ffac.push_back(dummy_float);
   float dummy_float_mu2 = dummy_float;
   std::pair <float, float> mumu(dummy_float_mu1,dummy_float_mu2);
   weights[mumu] = dummy_float_weight;
  }
  
  w00_ = weights[std::pair<float, float>(0.5, 0.5)];
  w10_ = weights[std::pair<float, float>(1.0, 0.5)];
  w01_ = weights[std::pair<float, float>(0.5, 1.0)];
  w12_ = weights[std::pair<float, float>(1.0, 2.0)];
  w21_ = weights[std::pair<float, float>(2.0, 1.0)];
  w22_ = weights[std::pair<float, float>(2.0, 2.0)];
  w11_ = weights[std::pair<float, float>(1.0, 1.0)];
  
 }
 
 
 myTree_->Fill();
}



bool GenDumper::isJetALepton(float phi, float eta, lhef::HEPEUP LHEhepeup) {
 bool isIt = false;
 for (unsigned int iPart = 0 ; iPart < LHEhepeup.IDUP.size (); ++iPart) {
  // outgoing particles
  if (LHEhepeup.ISTUP.at (iPart) == 1) {
   int type = abs (LHEhepeup.IDUP.at (iPart)) ;
   //-----      leptons
   if (type == 11 || type == 13 || type == 15) {
    TLorentzVector dummy (
                         LHEhepeup.PUP.at (iPart) [0], // px
                         LHEhepeup.PUP.at (iPart) [1], // py
                         LHEhepeup.PUP.at (iPart) [2], // pz
                         LHEhepeup.PUP.at (iPart) [3] // E
                         ) ;

    float phig = dummy.Phi();
    float etag = dummy.Eta();

    float deltaR = sqrt(reco::deltaPhi(phig,phi)*reco::deltaPhi(phig,phi) + (etag-eta)*(etag-eta));
    if (deltaR < 0.1) {
     isIt = true;
    }
   }
  }
 }
 return isIt;
}


bool GenDumper::isJetALepton(float phi, float eta, edm::Handle<reco::GenParticleCollection> genParticles) {
 bool isIt = false;
 for (reco::GenParticleCollection::const_iterator genPart = genParticles->begin(); genPart != genParticles->end(); genPart++){
  int id = abs(genPart->pdgId());
  if (id == 11 || id == 13 || id == 15) { //---- e/mu/tau

   float phig = genPart->phi();
   float etag = genPart->eta();

   float deltaR = sqrt(reco::deltaPhi(phig,phi)*reco::deltaPhi(phig,phi) + (etag-eta)*(etag-eta));
   if (deltaR < 0.1) {
    isIt = true;
   }
  }
 }
 return isIt;
}



// ------------ method called once each job just before starting event loop  ------------
void 
GenDumper::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
GenDumper::endJob() 
{
}

// ------------ method called when starting to processes a run  ------------
void GenDumper::beginRun(edm::Run const& iRun, edm::EventSetup const&) {
 edm::Handle<LHERunInfoProduct> run;
//  LHERunInfoProduct        "externalLHEProducer"   ""                "LHE"     
//  edmDumpEventContent  /tmp/amassiro/180BFD9B-CDD0-E411-9330-0CC47A13D09C.root --run 
 
 typedef std::vector<LHERunInfoProduct::Header>::const_iterator headers_const_iterator;
 
 iRun.getByLabel( "externalLHEProducer", run );
 
 LHERunInfoProduct myLHERunInfoProduct = *(run.product());
 
 for (headers_const_iterator iter=myLHERunInfoProduct.headers_begin(); iter!=myLHERunInfoProduct.headers_end(); iter++){
  std::cout << iter->tag() << std::endl;
  std::vector<std::string> lines = iter->lines();
  for (unsigned int iLine = 0; iLine<lines.size(); iLine++) {
   std::cout << lines.at(iLine);
  }
 }
 
 
 
 const lhef::HEPRUP thisHeprup_ = run->heprup();
 std::cout << "HEPRUP \n" << std::endl;
 std::cout << "IDBMUP " << std::setw(14) << std::fixed << thisHeprup_.IDBMUP.first;
 std::cout << std::setw(14) << std::fixed << thisHeprup_.IDBMUP.second << std::endl;
 std::cout << "EBMUP " << std::setw(14) << std::fixed << thisHeprup_.EBMUP.first;
 std::cout << std::setw(14) << std::fixed << thisHeprup_.EBMUP.second << std::endl;
 std::cout << "PDFGUP " << std::setw(14) << std::fixed << thisHeprup_.PDFGUP.first;
 std::cout << std::setw(14) << std::fixed << thisHeprup_.PDFGUP.second << std::endl;
 std::cout << "PDFSUP " << std::setw(14) << std::fixed << thisHeprup_.PDFSUP.first;
 std::cout << std::setw(14) << std::fixed << thisHeprup_.PDFSUP.second << std::endl;
 std::cout << "IDWTUP " << std::setw(14) << std::fixed << thisHeprup_.IDWTUP << std::endl;
 std::cout << "NPRUP " << std::setw(14) << std::fixed << thisHeprup_.NPRUP << std::endl;
 std::cout << " XSECUP " << std::setw(14) << std::fixed;
 std::cout << " XERRUP " << std::setw(14) << std::fixed;
 std::cout << " XMAXUP " << std::setw(14) << std::fixed;
 std::cout << " LPRUP " << std::setw(14) << std::fixed << std::endl;
 for ( unsigned int iSize = 0 ; iSize < thisHeprup_.XSECUP.size() ; iSize++ ) {
  std::cout << std::setw(14) << std::fixed << thisHeprup_.XSECUP[iSize];
  std::cout << std::setw(14) << std::fixed << thisHeprup_.XERRUP[iSize];
  std::cout << std::setw(14) << std::fixed << thisHeprup_.XMAXUP[iSize];
  std::cout << std::setw(14) << std::fixed << thisHeprup_.LPRUP[iSize];
  std::cout << std::endl;
 }
 std::cout << " " << std::endl;
 
 
 
 
//  edm::Handle< LHEXMLStringProduct > LHEAscii;
//  
// //  iRun.getByLabel(edm::InputTag('externalLHEProducer','LHEScriptOutput'),LHEAscii);
//  iRun.getByLabel(mcLHEEventInfoTag_,LHEAscii);
//  
//  const std::vector<std::string>& lheOutputs = LHEAscii->getStrings();
//  
//  unsigned int iout = 0;
//  
//  std::string lheFileName_ = "ciao.txt";
//  
//  size_t lastdot = lheFileName_.find_last_of(".");
//  std::string basename = lheFileName_.substr(0, lastdot);
//  std::string extension = lastdot != std::string::npos ?  lheFileName_.substr(lastdot+1, std::string::npos) : "";
//  
//  for (unsigned int i = 0; i < lheOutputs.size(); ++i){
//   std::ofstream outfile;
//   if (iout == 0)
//    outfile.open (lheFileName_.c_str(), std::ofstream::out | std::ofstream::app);
//   else {
//    std::stringstream fname;
//    fname << basename << "_" << iout ;
//    if (extension != "")
//     fname << "." << extension;
//    outfile.open (fname.str().c_str(), std::ofstream::out | std::ofstream::app);
//   }
//   outfile << lheOutputs[i];
//   outfile.close();
//   ++iout;
//  }
//  
//  for (unsigned int i = 0; i < LHEAscii->getCompressed().size(); ++i){
//   std::ofstream outfile;
//   if (iout == 0)
//    outfile.open (lheFileName_.c_str(), std::ofstream::out | std::ofstream::app);
//   else {
//    std::stringstream fname;
//    fname << basename << "_" << iout ;
//    if (extension != "")
//     fname << "." << extension;
//    outfile.open (fname.str().c_str(), std::ofstream::out | std::ofstream::app);
//   }
//   LHEAscii->writeCompressedContent(outfile,i);
//   outfile.close();
//   ++iout;
//  }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
}

// ------------ method called when ending the processing of a run  ------------
void 
GenDumper::endRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when starting to processes a luminosity block  ------------
void 
GenDumper::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a luminosity block  ------------
void 
GenDumper::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
GenDumper::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(GenDumper);
