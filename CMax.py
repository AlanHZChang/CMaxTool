import os
import sys

# The function is too simple to work 
# Limited use at CMax ONLY (only 1 source file is supported)
def build_mk (dirname, filename):
    
    print 'Processing Android.mk:' + filename
    mkfile = os.path.join (dirname, filename)
    mk = open (mkfile, 'r')
    
    src_file_list       = list ()
    local_module_name   = ''
    
    while True:
        line = mk.readline ()
        if not line:
            break
        
        tokenList = line.split (':=')
        if len(tokenList) == 0:
            continue;
        
        if (tokenList[0].strip() == 'LOCAL_MODULE'):
            local_module_name = tokenList[1].strip()
            print '\tLOCAL_MODULE: ' + local_module_name
        elif (tokenList[0].strip() == 'LOCAL_SRC_FILES'):        
            src_file_list.append (tokenList[1].strip())
            print '\tLOCAL_SRC_FILES: ' + tokenList[1].strip()
            
    mk.close ()
    
    # error check
    if ((local_module_name == '') or (len (src_file_list) == 0)):        
        return
    elif len (src_file_list) > 1:
        print 'Exception happens -> no more lazy way'
        sys.exit (0);
    
    # calling build script
    print '\tBuilding: ' + local_module_name
    file_tokens = src_file_list[0].split('.')
    os.system ('build_cmd.bat ' + os.path.join(dirname, file_tokens[0]) + ' ' + local_module_name)
    
    # clean up    
    os.system ('del /Q ' + dirname + '\*.o')
    os.system ('del /Q ' + dirname + '\*.d')
            

#-------------------------------------------------------------------------------
# main routine starts here
#-------------------------------------------------------------------------------
# Step 1. traverse the directories
for dirname, dirnames, filenames in os.walk('.'):
    # I just DONT care about the subfolders.
    # print path to all subdirectories first.
    #for subdirname in dirnames:
    #    print os.path.join(dirname, subdirname)

    # print path to all filenames.
    for filename in filenames:        
        if filename == 'Android.mk':            
            build_mk (dirname, filename)            
        else:
            continue                          