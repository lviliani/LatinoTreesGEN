Example
====

copy test file:

    cp  /afs/cern.ch/user/g/govoni/work/public/HIG-RunIIWinter15GenOnly-00001_60.root /tmp/amassiro/
    
run on test file:

    cmsRun gendumper_cfg.py   inputFiles=file:/tmp/amassiro/HIG-RunIIWinter15GenOnly-00001_60.root       outputFile=/tmp/amassiro/HIG-RunIIWinter15GenOnly_dump_tree.root

Plot:

    r99t /tmp/amassiro/HIG-RunIIWinter15GenOnly_dump_tree.root Draw.cxx


