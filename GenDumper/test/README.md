Example
====

copy test file:

    cp  /afs/cern.ch/user/g/govoni/work/public/HIG-RunIIWinter15GenOnly-00001_60.root /tmp/amassiro/
    
run on test file:

    cmsRun gendumper_cfg.py   inputFiles=file:/tmp/amassiro/HIG-RunIIWinter15GenOnly-00001_60.root       outputFile=/tmp/amassiro/HIG-RunIIWinter15GenOnly_dump_tree.root

    cmsRun gendumper_cfg.py   inputFiles=/store/mc/RunIIWinter15GenOnly/TTJets_13TeV-amcatnloFXFX-pythia8_TESTDrop/GEN/15March2015_15March15_MCRUN2_71_V1-v1/10000/180BFD9B-CDD0-E411-9330-0CC47A13D09C.root  \
                              outputFile=/tmp/amassiro/TT_dump_tree.root

    
Plot:

    r99t /tmp/amassiro/HIG-RunIIWinter15GenOnly_dump_tree.root Draw.cxx


