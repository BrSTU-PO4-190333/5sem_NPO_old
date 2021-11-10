print(" %-32s %32s" % ("=Галанин П. И.=", "=gpi_autorename="))

import os
for root, dirs, files in os.walk("."):  
    for filename in files:
        s = filename
        s = s.replace("ASBF_", "GPIF_")
        os.rename(filename, s)
        print(" gpi_autorename Rename: %s => %s" % (filename, s))
