Plot tools
====

Calculate weights for aMC@NLO

    cd /tmp/amassiro/
    eosmount eos eos
    cd -
    
    ls /tmp/amassiro/eos/cms/store/group/phys_higgs/cmshww/amassiro/RunII/GenDumper/
    
    # create list of files
    
    ls  --color=none  /tmp/amassiro/eos/cms/store/group/phys_higgs/cmshww/amassiro/RunII/GenDumper/ | \
        awk '{print "ls --color=none /tmp/amassiro/eos/cms/store/group/phys_higgs/cmshww/amassiro/RunII/GenDumper/"$1"/*/*/*/GEN*.root &> "$1".txt"}' | /bin/sh
        
    # analyse list of files
    ls  --color=none /tmp/amassiro/eos/cms/store/group/phys_higgs/cmshww/amassiro/RunII/GenDumper/ | \
        awk '{print "root -l -q -b count.cxx\\\(\\\""$1".txt\\\"\\\)"}' | /bin/sh
    
    
        