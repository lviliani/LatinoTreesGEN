Plot tools
====

Calculate weights for aMC@NLO

    cd /tmp/amassiro/
    eosmount eos eos
    cd -
    
    ls /tmp/amassiro/eos/cms/store/group/phys_higgs/cmshww/amassiro/RunII/GenDumper/
    
    # create list of files
    
    # 25 ns
    ls  --color=none  /tmp/amassiro/eos/cms/store/group/phys_higgs/cmshww/amassiro/RunII/GenDumper/ | \
        awk '{print "ls --color=none /tmp/amassiro/eos/cms/store/group/phys_higgs/cmshww/amassiro/RunII/GenDumper/"$1"/*25ns*/*/*/GEN*.root &> "$1".txt"}' | /bin/sh
        
    # analyse list of files
    ls  --color=none /tmp/amassiro/eos/cms/store/group/phys_higgs/cmshww/amassiro/RunII/GenDumper/ | \
        awk '{print "root -l -q -b count.cxx\\\(\\\""$1".txt\\\"\\\)"}' | /bin/sh
    
    # 50 ns
    ls  --color=none  /tmp/amassiro/eos/cms/store/group/phys_higgs/cmshww/amassiro/RunII/GenDumper/ | \
        awk '{print "ls --color=none /tmp/amassiro/eos/cms/store/group/phys_higgs/cmshww/amassiro/RunII/GenDumper/"$1"/*50ns*/*/*/GEN*.root &> "$1".txt"}' | /bin/sh
        
    # analyse list of files
    ls  --color=none /tmp/amassiro/eos/cms/store/group/phys_higgs/cmshww/amassiro/RunII/GenDumper/ | \
        awk '{print "root -l -q -b count.cxx\\\(\\\""$1".txt\\\"\\\)"}' | /bin/sh
    
    
    
        