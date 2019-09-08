#docker run -e keymap=mkdev -e keyboard=ergodox_ez --rm -v $('pwd'):/qmk:rw edasque/qmk_firmware make handwired/dactyl_manuform/4x6:mkdev
docker run --rm -v "$PWD":/qmk_firmware qmkfm/qmk_firmware make handwired/dactyl_manuform/4x6:mkdev
