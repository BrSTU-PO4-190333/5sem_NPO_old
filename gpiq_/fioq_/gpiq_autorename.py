gpi_path1 = "mkoq_" # Тут что заменить, например, mkoq_cdsff.cpp
gpi_path2 = "gpiq_" # Тут что хотим видеть, например, gpiq_cdsff.cpp

# = = = = = = = = = = = = = = = =

print(" %-32s %32s" % ("=Галанин П. И.=", "=gpiq_autorename="))

import os
for root, dirs, files in os.walk("."):  
    for gpi_filename in files:
        gpi_s = gpi_filename
        gpi_s = gpi_s.replace(gpi_path1, gpi_path2)
        os.rename(gpi_filename, gpi_s)
        print(" gpiq_autorename Rename: %s => %s" % (gpi_filename, gpi_s))
