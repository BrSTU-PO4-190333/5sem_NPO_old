gpi_path1 = "ASBF_" # Тут что меняем
gpi_path2 = "GPIF_" # Тут на что меняем
# = = = = = = = = = = = = = = = =

print(" %-32s %32s" % ("=Галанин П. И.=", "=gpif_autorename="))

import os
for root, dirs, files in os.walk("."):  
    for gpi_filename in files:
        gpi_s = gpi_filename
        gpi_s = gpi_s.replace(gpi_path1, gpi_path2)
        os.rename(gpi_filename, gpi_s)
        print(" gpif_autorename: %s => %s" % (gpi_filename, gpi_s))
