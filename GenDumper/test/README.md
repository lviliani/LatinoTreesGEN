Example
====

copy test file:

    cp  /afs/cern.ch/user/g/govoni/work/public/HIG-RunIIWinter15GenOnly-00001_60.root /tmp/amassiro/
    
run on test file:

    cmsRun gendumper_cfg.py   inputFiles=file:/tmp/amassiro/HIG-RunIIWinter15GenOnly-00001_60.root       outputFile=/tmp/amassiro/HIG-RunIIWinter15GenOnly_dump_tree.root

    cmsRun gendumper_cfg.py   inputFiles=/store/mc/RunIIWinter15GenOnly/TTJets_13TeV-amcatnloFXFX-pythia8_TESTDrop/GEN/15March2015_15March15_MCRUN2_71_V1-v1/10000/180BFD9B-CDD0-E411-9330-0CC47A13D09C.root  \
                              outputFile=/tmp/amassiro/TT_dump_tree.root

    cmsRun gendumper_cfg.py   inputFiles=root://xrootd.unl.edu//store/mc/RunIIWinter15GenOnly/GluGluHToWWTo2L2Nu_M125_13TeV_powheg_pythia8/GEN/MCRUN2_71_V1-v1/20000/00F4C749-3BD8-E411-9A57-D4AE526A0A7B.root  \
                              outputFile=/tmp/amassiro/powheg_dump_tree.root

    cmsRun gendumper_cfg.py   inputFiles=root://xrootd.unl.edu//store/mc/RunIIWinter15GenOnly/GluGluHToWWTo2L2Nu_M125_13TeV_amcatnloFXFX_pythia8/GEN/MCRUN2_71_V1-v1/20000/00FB06C4-AFDA-E411-876B-20CF305B060E.root  \
                              outputFile=/tmp/amassiro/amcatnlo_dump_tree.root
                        
                              
Plot:

    r99t /tmp/amassiro/HIG-RunIIWinter15GenOnly_dump_tree.root Draw.cxx

    r99t /tmp/amassiro/TT_dump_tree.root Draw.cxx

    r99t /tmp/amassiro/amcatnlo_dump_tree.root /tmp/amassiro/powheg_dump_tree.root DrawCompare.cxx\(\"pt1\",100,0,100\)
    r99t /tmp/amassiro/amcatnlo_dump_tree.root /tmp/amassiro/powheg_dump_tree.root DrawCompare.cxx\(\"njet\",6,0,6\)
    r99t /tmp/amassiro/amcatnlo_dump_tree.root /tmp/amassiro/powheg_dump_tree.root DrawCompare.cxx\(\"pt2\",100,0,100\)
    r99t /tmp/amassiro/amcatnlo_dump_tree.root /tmp/amassiro/powheg_dump_tree.root DrawCompare.cxx\(\"lhept1\",100,0,100\)
    
    