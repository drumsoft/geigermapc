geigemapc README-linux

libusb 1.0 または libudev ライブラリとヘッダが必要なので、
libusb-devel-1.0.*, libusb-1.0.*-dev, libudev-dev, libudev-devel といった名前の
パッケージをインストールしておく

[build / ビルド]
$ cd linux
$ make
$ cd ..

[setting / 設定]
geigermapc.pl をエディタで開き 'id', 'key' を編集する

[test / テスト実行]
$ perl geigermapc.pl

送信したデータは以下のURLで確認できる
http://drumsoft.com/gm/?action=Table&id={自分のID}

[install / インストール]
{任意のパス} にインストールする
$ cp geigermapc.pl read-usb-geiger {任意のパス}
$ chmod a+x {任意のパス}/geigermapc.pl {任意のパス}/read-usb-geiger

[set periodic run / 定期実行の設定]












Making install in libusb
make[1]: Entering directory `/home/hrk/src/libusb-1.0.8/libusb'
make[2]: Entering directory `/home/hrk/src/libusb-1.0.8/libusb'
test -z "/usr/local/lib" || /bin/mkdir -p "/usr/local/lib"
 /bin/sh ../libtool   --mode=install /usr/bin/install -c   libusb-1.0.la '/usr/local/lib'
libtool: install: /usr/bin/install -c .libs/libusb-1.0.so.0.0.0 /usr/local/lib/libusb-1.0.so.0.0.0
libtool: install: (cd /usr/local/lib && { ln -s -f libusb-1.0.so.0.0.0 libusb-1.0.so.0 || { rm -f libusb-1.0.so.0 && ln -s libusb-1.0.so.0.0.0 libusb-1.0.so.0; }; })
libtool: install: (cd /usr/local/lib && { ln -s -f libusb-1.0.so.0.0.0 libusb-1.0.so || { rm -f libusb-1.0.so && ln -s libusb-1.0.so.0.0.0 libusb-1.0.so; }; })
libtool: install: /usr/bin/install -c .libs/libusb-1.0.lai /usr/local/lib/libusb-1.0.la
libtool: install: /usr/bin/install -c .libs/libusb-1.0.a /usr/local/lib/libusb-1.0.a
libtool: install: chmod 644 /usr/local/lib/libusb-1.0.a
libtool: install: ranlib /usr/local/lib/libusb-1.0.a
libtool: finish: PATH="/usr/bin:/bin:/sbin" ldconfig -n /usr/local/lib
----------------------------------------------------------------------
Libraries have been installed in:
   /usr/local/lib

If you ever happen to want to link against installed libraries
in a given directory, LIBDIR, you must either use libtool, and
specify the full pathname of the library, or use the `-LLIBDIR'
flag during linking and do at least one of the following:
   - add LIBDIR to the `LD_LIBRARY_PATH' environment variable
     during execution
   - add LIBDIR to the `LD_RUN_PATH' environment variable
     during linking
   - use the `-Wl,-rpath -Wl,LIBDIR' linker flag
   - have your system administrator add LIBDIR to `/etc/ld.so.conf'

See any operating system documentation about shared libraries for
more information, such as the ld(1) and ld.so(8) manual pages.
----------------------------------------------------------------------
test -z "/usr/local/include/libusb-1.0" || /bin/mkdir -p "/usr/local/include/libusb-1.0"
 /usr/bin/install -c -m 644 libusb.h '/usr/local/include/libusb-1.0'
make[2]: Leaving directory `/home/hrk/src/libusb-1.0.8/libusb'
make[1]: Leaving directory `/home/hrk/src/libusb-1.0.8/libusb'
Making install in doc
make[1]: Entering directory `/home/hrk/src/libusb-1.0.8/doc'
make[2]: Entering directory `/home/hrk/src/libusb-1.0.8/doc'
make[2]: Nothing to be done for `install-exec-am'.
make[2]: Nothing to be done for `install-data-am'.
make[2]: Leaving directory `/home/hrk/src/libusb-1.0.8/doc'
make[1]: Leaving directory `/home/hrk/src/libusb-1.0.8/doc'
make[1]: Entering directory `/home/hrk/src/libusb-1.0.8'
make[2]: Entering directory `/home/hrk/src/libusb-1.0.8'
make[2]: Nothing to be done for `install-exec-am'.
test -z "/usr/local/lib/pkgconfig" || /bin/mkdir -p "/usr/local/lib/pkgconfig"
 /usr/bin/install -c -m 644 libusb-1.0.pc '/usr/local/lib/pkgconfig'
make[2]: Leaving directory `/home/hrk/src/libusb-1.0.8'
make[1]: Leaving directory `/home/hrk/src/libusb-1.0.8'


$ export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig
$ make

$ sudo emacs  /etc/ld.so.conf
	/usr/local/lib を最後に追加
$ sudo /sbin/ldconfig
