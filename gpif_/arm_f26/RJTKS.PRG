* † -> Š‘

set safe off
*set console on
set console off
clear

close data

************


sele 1
use  rj_

sele 2
use  ks_
zap


sele rj_
goto top

LOCATE  for .T.

**

do while .T.

  if eof()
	exit
  endif

do recxx

sele rj_
skip

enddo

**

close data
***********

clear


return
**************************************************
**************************************************
proc recxx

sele rj_
scat memvar 

sele ks_

**

append blank

repl ks_data   with m.rj_data
repl ks_dokt   with m.rj_dokt
repl ks_dokn   with m.rj_dokn
repl ks_txt    with m.rj_txt

repl ks_s     with m.rj_db
repl ks_ks    with m.rj_kr

repl ks_db   with m.rj_summa
repl ks_kr   with 0

******
append blank

repl ks_data   with m.rj_data
repl ks_dokt   with m.rj_dokt
repl ks_dokn   with m.rj_dokn
repl ks_txt    with m.rj_txt


repl ks_s     with m.rj_kr
repl ks_ks    with m.rj_db

repl ks_kr   with m.rj_summa

repl ks_db   with 0


return
***************************
***************************
