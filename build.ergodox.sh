#docker run -e keymap=mk_dev -e keyboard=ergodox_ez --rm -v $('pwd'):/qmk:rw edasque/qmk_firmware
docker run -e KEYMAP=mk_dev -e KEYBOARD=ergodox_ez --rm -v $('pwd'):/qmk:rw edasque/qmk_firmware
