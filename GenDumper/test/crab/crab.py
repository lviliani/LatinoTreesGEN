from WMCore.Configuration import Configuration
config = Configuration()

config.section_('General')
config.General.transferOutputs = True
config.General.requestName = 'MC_ggH13TeV'

config.section_('JobType')
config.JobType.pluginName  = 'Analysis'
config.JobType.psetName    = '../gendumper_cfg.py'
config.JobType.outputFiles = ['GEN_MC_ggHww.root']
config.JobType.pyCfgParams = ['outputFile=GEN_MC_ggHww.root']
config.JobType.allowNonProductionCMSSW = True  # To fix cmssw releases

config.section_('Data')
config.Data.inputDataset = '/GluGluHToWWTo2L2Nu_M125_13TeV_amcatnloFXFX_pythia8/RunIIWinter15GenOnly-MCRUN2_71_V1-v1/GEN'
config.Data.splitting    = 'FileBased'  #'LumiBased'
config.Data.unitsPerJob  = 10  # Since files based, 10 files per job
config.Data.inputDBS     = 'https://cmsweb.cern.ch/dbs/prod/global/DBSReader/'
config.Data.outLFN       = '/store/group/phys_higgs/cmshww/amassiro/RunII/MCstudies/'

config.section_('Site')
config.Site.storageSite = 'T2_CH_CERN'

#/GluGluHToWWTo2L2Nu_M125_13TeV_amcatnloFXFX_pythia8/RunIIWinter15GenOnly-MCRUN2_71_V1-v1/
#/GluGluHToWWTo2L2Nu_M125_13TeV_powheg_pythia8/RunIIWinter15GenOnly-MCRUN2_71_V1-v1/ 