CRAB3
====

See details here:

    https://twiki.cern.ch/twiki/bin/view/CMSPublic/WorkBookCRAB3Tutorial#CRAB_configuration_parameters
    https://twiki.cern.ch/twiki/bin/view/CMSPublic/CRAB3ConfigurationFile

Check if you have writing permissions:

    source /cvmfs/cms.cern.ch/crab3/crab.sh
    source /cvmfs/cms.cern.ch/crab3/crab.csh
    
    crab checkwrite --site=T2_CH_CERN
    crab checkwrite --site=T2_CH_CERN --lfn=/store/group/phys_higgs/cmshww/amassiro/RunII/test/


MultiCRAB
====

    python multicrab.py samples/samples_spring15.py
    
    python multicrab.py crab_projects_2Aug status
    python multicrab.py crab_projects_2Aug resubmit
    
    python multicrab.py crab_projects_11Aug status
    python multicrab.py crab_projects_11Aug resubmit
    
    crab status
    
    crab status folder_name
