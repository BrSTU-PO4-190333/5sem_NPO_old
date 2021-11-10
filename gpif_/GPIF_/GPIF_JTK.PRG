* † -> Š‘

set safe off
*set console on
set console off
clear

close data

************


sele 1
*use  rj_
use  gpif_j

sele 2
*use  ks_
use  gpif_k
zap


sele gpif_j
goto top

LOCATE  for .T.

**

do while .T.

  if eof()
	exit
  endif

do recxx

sele gpif_j
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

sele gpif_j
scat memvar 

sele gpif_k

**

append blank

repl gpif_kdata   with m.gpif_jdata
repl gpif_kdokk   with m.gpif_jdokk
repl gpif_kdokn   with m.gpif_jdokn
repl gpif_kdokd   with m.gpif_jdokd
repl gpif_kto    with m.gpif_jto

repl gpif_ks     with m.gpif_jdb
repl gpif_ksn    with m.gpif_jdbn
repl gpif_kks    with m.gpif_jkr
repl gpif_kksn   with m.gpif_jkrn

repl gpif_kdb   with m.gpif_jrub
repl gpif_kkr   with 0

******
append blank

repl gpif_kdata   with m.gpif_jdata
repl gpif_kdokk   with m.gpif_jdokk
repl gpif_kdokn   with m.gpif_jdokn
repl gpif_kdokd   with m.gpif_jdokd
repl gpif_kto     with m.gpif_jto


repl gpif_ks     with m.gpif_jkr
repl gpif_ksn    with m.gpif_jkrn
repl gpif_kks    with m.gpif_jdb
repl gpif_kksn   with m.gpif_jdbn

repl gpif_kkr   with m.gpif_jrub

repl gpif_kdb   with 0


return
***************************
***************************
