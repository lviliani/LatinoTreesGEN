import FWCore.ParameterSet.Config as cms
from FWCore.ParameterSet.VarParsing import VarParsing

options = VarParsing ('analysis')

# add a list of strings for events to process
options.parseArguments()


process = cms.Process("SimpleGenDumper")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 10000

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(10000) )
#process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
#process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(options.maxEvents) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    #fileNames = cms.untracked.vstring (options.inputFiles),
    #fileNames = cms.untracked.vstring('file:/tmp/amassiro/WW1Mevents_TUNE_NoUE_2.root')
    fileNames = cms.untracked.vstring('root://cmsxrootd.fnal.gov//store/mc/RunIIWinter15GS/TTTo2L2Nu_13TeV-powheg/GEN-SIM/MCRUN2_71_V1-v2/00000/00201DF3-20F0-E411-976D-008CFA197A70.root',
                                      'root://cmsxrootd.fnal.gov//store/mc/RunIIWinter15GS/TTTo2L2Nu_13TeV-powheg/GEN-SIM/MCRUN2_71_V1-v2/00000/00223A0C-E5EE-E411-92A5-008CFA05E874.root',
                                      'root://cmsxrootd.fnal.gov//store/mc/RunIIWinter15GS/TTTo2L2Nu_13TeV-powheg/GEN-SIM/MCRUN2_71_V1-v2/00000/002CE757-00EF-E411-B368-008CFA0A58B0.root')
)

process.TFileService = cms.Service("TFileService",
      #fileName = cms.string("/tmp/amassiro/WW1Mevents_TUNE_NoUE_2_dump_tree.root"),
      fileName = cms.string (options.outputFile),
      closeFileFast = cms.untracked.bool(True)
)

process.Analyzer = cms.EDAnalyzer('GenDumper',
     GenJetCollection       = cms.InputTag("ak5GenJets"),
     GenParticlesCollection = cms.InputTag("genParticles"),
     mcLHEEventInfoTag      = cms.InputTag("externalLHEProducer"),
     #mcLHEEventInfoTag      = cms.InputTag("source"),
     genEvtInfoTag          = cms.InputTag("generator"), 
     dumpWeights            = cms.untracked.bool(False),
     debug                  = cms.untracked.bool(False)
)



process.p = cms.Path(process.Analyzer)
