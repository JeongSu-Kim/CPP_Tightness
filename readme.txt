 作品名　　：Tightness
 Work Name
 作成期間　：約二週間
 Time Frame

-----------------------------------------------------------------------------
 プログラム作品の開発環境についてご記入ください
 What was the development environment used for your program?
-----------------------------------------------------------------------------
・動作確認したOS名とそのバージョン
  Used OS
  　Windows 7 Professional 64bit

・開発に使用したライブラリ、ミドルウェアとそのバージョン
  Used Library/Middleware
  　無

・開発に使用したエンジンのバージョン
  Used Engine
  　無

・開発に使用した開発環境のバージョン
  Used Development Environment
  　Visual Studio 2015 Community


-----------------------------------------------------------------------------
 どうしてそのプログラムを作ろうと思いましたか？
 Why did you create this program?
-----------------------------------------------------------------------------
韓国のとあるウェブトゥーンにテトリスをパロディーしたタイトネスと言う
ゲームが出てそれを作ってみました。
同じコードでテトリスとテトロミノの代わりにペントミノを使うペントリス
も作りました。


-----------------------------------------------------------------------------
 プログラムを作成する上で注意した事は？
 What were you careful about?
-----------------------------------------------------------------------------
最初から様々なバージョンのブロックで実行できるように作ろうとしました。
ブロックの種類、最大の大きさ、ローテートタイプさえ入れたらほかのタイプの
ブロックで実行できるように作りました。

-----------------------------------------------------------------------------
 プログラムを作成する上で大変だった所は？
 What did you find difficult?
-----------------------------------------------------------------------------
どんなタイプのブロックでも同じように回転できるようにrotateBlock関数を
作りましたが、二つだけのパターンがあるブロックも同じ形で位置が違くなる
問題がありました。
90度だけではなく回転しない、－90度回転するrotateTypeを追加して解決
しました。

-----------------------------------------------------------------------------
 力をいれて作った部分で、「プログラム上」で特に注意してみてもらいたい所は？
 What points do you want us particulary focus on your work?
-----------------------------------------------------------------------------
ベースになるblock classはブロックを使う他のゲームにも使えるように作りました。
pでストップ、zでキップ、vでプレヴューができます。

-----------------------------------------------------------------------------
 参考にしたソースファイルがあるのなら、 どの様なところを参考にしましたか？
 またその部分のファイル名を書いてください。
 If you took some source codes as reference, what part of them did you use? 
 Please also tell us the filename of that part.
-----------------------------------------------------------------------------

※ 注意 - Note - ※
他の人が作成したライブラリ、関数等を使っている場合は、
その部分を「別ファイル」に分けて、そのファイル名を書いてください。
If you are using a library or function created by someone else,
please put those parts in a separeted file and write the corresponding filename.

 ＜以下のような場合が該当します＞
　*　他人の作った関数を使用した場合
　*　何かを参考にし参考元のソースが半分以上残っている場合
　*　フリーのライブラリを使用した場合（ライブラリ名を明記してください。）
　*　他人の作ったライブラリを使用した場合（ライブラリ名を明記してください。）
　*　「チーム」で作成した作品の場合
　　（自分の担当した箇所やソースファイル名がわかるよう明記してください。）
For example:
　*　If you use a function made by others
　*　If you take something in reference and the referenced source represent more than half
　*　If you use a free library (please write the library name)
　*　If you use a library made by others (please write the library name)
　*　If the work is made in a team
     (please describe the source file name and points that you were in charge of)