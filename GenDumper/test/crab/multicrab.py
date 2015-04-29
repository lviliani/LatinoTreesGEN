import os
from WMCore.Configuration import Configuration
config = Configuration()

pyCfgParams = ['outputFile=GEN_MC_ggHww.root']

config.section_('General')
config.General.transferOutputs = True
config.General.requestName = 'MC_ggH13TeV_multi'

config.section_('JobType')
config.JobType.psetName    = '../gendumper_cfg.py'
config.JobType.pluginName = 'Analysis'
config.JobType.outputFiles = ['GEN_MC_ggHww.root']

# to fix cmssw releases
config.JobType.allowNonProductionCMSSW = True

config.section_('Data')    
config.Data.unitsPerJob = 10   # since files based, 10 files per job
config.Data.inputDBS = 'https://cmsweb.cern.ch/dbs/prod/global/DBSReader/'
config.Data.splitting = 'FileBased'    #'LumiBased'
config.Data.outLFN = '/store/group/phys_higgs/cmshww/amassiro/RunII/MCstudies/'

config.section_('Site')
config.Site.storageSite = 'T2_CH_CERN'



if __name__ == '__main__':

    from CRABAPI.RawCommand import crabCommand

    # Make sure you set this parameter (here or above in the config it does not matter)
    config.General.workArea = 'crab_projects_29Apr'

    def submit(config):
        res = crabCommand('submit', config = config)

    #########    From now on that's what users should modify: this is the a-la-CRAB2 configuration part.
   
    # samples to be analysed
                   
    config.General.requestName = 'powheg'
    config.Data.inputDataset = '/GluGluHToWWTo2L2Nu_M125_13TeV_powheg_pythia8/RunIIWinter15GenOnly-MCRUN2_71_V1-v1/GEN'
    config.JobType.pyCfgParams = list(pyCfgParams)
    #config.JobType.pyCfgParams.extend(['label=DYll', 'id=12345', 'scale=1.23'])
    submit(config)

    config.General.requestName = 'aMCatNLO'
    config.Data.inputDataset = '/GluGluHToWWTo2L2Nu_M125_13TeV_amcatnloFXFX_pythia8/RunIIWinter15GenOnly-MCRUN2_71_V1-v1/GEN'
    config.JobType.pyCfgParams = list(pyCfgParams)
    #config.JobType.pyCfgParams.extend(['label=DYll', 'id=12345', 'scale=1.23'])
    submit(config)



