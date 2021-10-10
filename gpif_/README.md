## Installing programs

1. Installing [DOSBox](https://www.dosbox.com/).
1. Copy `U:/VT&PM/EU_EI/PIN/arm_f26/F.ARJ/*` to `r:/FPD26`.

## Russification of DOSBOX on Windows

1. Open start.
1. Open `DOSBox@`/`DOSBox @ Options` (where `@` - version).
1. Change the line in the file `dosbox@.conf` (where `@` - version):
```conf
[dos]
#keyboardlayout=auto
keyboardlayout=ru
```

## Automatic launch of FoxPro when opening DOSBox

1. Open start.
1. Open `DOSBox-@`/`DOSBox @ Options` (where `@` - version).
1. Change the line in the file `dosbox-@.conf` (where `@` - version):
```conf
[autoexec]
mount r: r:\
r:
cd FPD26
foxpro
```

## Opening a project in FoxPro

1. Copy `U:/VT&PM/EU_EI/PIN/bbd/ASBF0422.ARJ/*` to `r:/gpif_/`.
1. Click on `Program`.
1. Click on `Do... ^D`.
1. Click on `[..]`.
1. Click on `GPIF_`.
1. Click on `ASBF_MEN.MPR`.
