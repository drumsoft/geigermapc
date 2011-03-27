geigermapc

[概要]
GIGERMAP用 USB-GEIGER 測定値送信ソフトウェア

以下の2つにわかれています。
read-usb-geiger  USB-GEIGEIの測定値を読み出すプログラム
geigermapc.pl    測定値を GEIGERMAP に送るperlスクリプト

[実行環境]
read-usb-geiger
	hidapi http://www.signal11.us/oss/hidapi/
	をビルド・動作させられる環境が必要です。
geigermapc.pl
	下記モジュールを使用します。
		LWP
		Digest::SHA1
		CGI

[ビルド,インストール,定期実行]
各プラットフォーム別の情報は以下のファイルをご覧下さい。

README-linux
README-mac
README-windows

