geigemapc README-mac

[build / ビルド]
$ cd mac
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

[set periodic run]
以下のどちらかのファイルを作る
(自分のアカウントでログイン中に実行する場合)
~/Library/LaunchAgents/com.drumsoft.geigermapc.plist
(起動時は常にrootが実行する場合)
/Library/LaunchDeamon/com.drumsoft.geigermapc.plist

ファイルの中身は以下

<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
	<key>Label</key>
	<string>com.drumsoft.geigermapc.plist</string>
	<key>WorkingDirectory</key>
	<string>{任意のパス}</string>
	<key>Program</key>
	<string>./geigermapc.pl</string>
	<key>StartCalendarInterval</key>
	<dict/>
</dict>
</plist>

設定ファイルを読み込ませる
launchctl load ~/Library/LaunchAgents/com.drumsoft.geigermapc.plist
launchctl load /Library/LaunchDeamon/com.drumsoft.geigermapc.plist

