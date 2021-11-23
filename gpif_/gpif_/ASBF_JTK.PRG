* † -> Š‘

set safe off
*set console on
set console off
clear

close data

************


sele 1
*use  rj_
use  asbf_j

sele 2
*use  ks_
use  asbf_k
zap


sele asbf_j
goto top

LOCATE  for .T.

**

do while .T.

  if eof()
	exit
  endif

do recxx

sele asbf_j
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

sele asbf_j
scat memvar 

sele asbf_k

**

append blank

repl asbf_kdata   with m.asbf_jdata
repl asbf_kdokk   with m.asbf_jdokk
repl asbf_kdokn   with m.asbf_jdokn
repl asbf_kdokd   with m.asbf_jdokd
repl asbf_kto    with m.asbf_jto

repl asbf_ks     with m.asbf_jdb
repl asbf_ksn    with m.asbf_jdbn
repl asbf_kks    with m.asbf_jkr
repl asbf_kksn   with m.asbf_jkrn

repl asbf_kdb   with m.asbf_jrub
repl asbf_kkr   with 0

******
append blank

repl asbf_kdata   with m.asbf_jdata
repl asbf_kdokk   with m.asbf_jdokk
repl asbf_kdokn   with m.asbf_jdokn
repl asbf_kdokd   with m.asbf_jdokd
repl asbf_kto     with m.asbf_jto


repl asbf_ks     with m.asbf_jkr
repl asbf_ksn    with m.asbf_jkrn
repl asbf_kks    with m.asbf_jdb
repl asbf_kksn   with m.asbf_jdbn

repl asbf_kkr   with m.asbf_jrub

repl asbf_kdb   with 0


return
***************************
***************************
