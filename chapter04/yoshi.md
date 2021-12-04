### 4-7, 4-8
#### 問
- gccのマニュアルを読み, preprocesser だけを実行して前処理を終えたプログラムを読むこのできるファイルに保存してみましょう.何が変更されるでしょうか？
- 4-8ではアセンブリ言語のファイルをみてみましょう

#### 答
- gccのマニュアルを見る.
```
$ gcc --help
OPTIONS:
-E                      Only run the preprocessor
...
-S                      Only run preprocess and compilation steps
...
-o <file>               Write output to <file>
```

- -E option で preprocessorのみ走らせることができる.
```
g++ -E -o hello_preprocessor hello.cpp
```
- また, バイナリコードから確かにhelloworldできた
```
$ g++ -o hello hello.cpp
$ ./hello
Hello world.
```

- アセンブリコードもみてみる
```
g++ -S -o hello_compiled hello.cpp
```
