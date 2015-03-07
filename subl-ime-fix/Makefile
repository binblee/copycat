imfix: sublime_imfix.c
	gcc -shared -o libsublime-imfix.so sublime_imfix.c  `pkg-config --libs --cflags gtk+-2.0` -fPIC

install:
	sudo cp libsublime-imfix.so /opt/sublime_text/libsublime-imfix.so
	sudo mv /usr/bin/subl /usr/bin/subl.original
	sudo cp subl /usr/bin/
	sudo mv /usr/share/applications/sublime_text.desktop /usr/share/applications/sublime_text.desktop.original
	sudo cp sublime_text.desktop /usr/share/applications/