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
    fileNames = cms.untracked.vstring('root://cmsxrootd.fnal.gov//store/mc/RunIIWinter15GS/TT_TuneCUETP8M1_13TeV-powheg-pythia8/GEN-SIM/MCRUN2_71_V1-v1/10000/00004E38-D5C7-E411-8F03-0025905B8610.root',
                                      'root://cmsxrootd.fnal.gov//store/mc/RunIIWinter15GS/TT_TuneCUETP8M1_13TeV-powheg-pythia8/GEN-SIM/MCRUN2_71_V1-v1/10000/0061B320-F9C7-E411-ADCC-0025904B2018.root',
                                      'root://cmsxrootd.fnal.gov//store/mc/RunIIWinter15GS/TT_TuneCUETP8M1_13TeV-powheg-pythia8/GEN-SIM/MCRUN2_71_V1-v1/10000/00800509-D7C7-E411-BE5D-00266CFFA204.root',
                                      'root://cmsxrootd.fnal.gov//store/mc/RunIIWinter15GS/TT_TuneCUETP8M1_13TeV-powheg-pythia8/GEN-SIM/MCRUN2_71_V1-v1/10000/00E79439-28C8-E411-BBC3-B083FED429D6.root')
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
