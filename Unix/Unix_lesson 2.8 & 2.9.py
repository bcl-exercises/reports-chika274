#Unix_lesson 2.8 & 2.9

##2-8
1. ls -lR > ls-lR
2. grep PI math.h  # 指定ファイルから、キーワードを含む行を検索する。（grep）
3. tail -50 ファイル名 | less
4. head -50 ファイル名 | less
5. cut -d ',' -f 2 ファイル名	(拡張子は.csv)	# 2行目はこれ　→　sed -n 2p ファイル名
6. paste data1.txt data2.txt

##2-9
1.sed -e "s/ //g" ファイル名
2.sed -e "s/     /$'\t'/g" ファイル名 > 保存先のファイル名	#Linuxでは実行できるはず‥‥  

