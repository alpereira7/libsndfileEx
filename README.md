The first thing is to install the library (I chose `libsndfile-1.0.28-w64-setup.exe` because I run Code::Blocks with the pre-installed MinGW `codeblocks-20.03mingw-setup.exe` that includes a 64bit compiler by default) and locate these three files:

> `sndfile.h` (for me it is located at `C:\Program Files\Mega-Nerd\libsndfile\include`)

> `libsndfile-1.lib` (for me `C:\Program Files\Mega-Nerd\libsndfile\lib`)

> `libsndfile-1.dll` (`C:\Program Files\Mega-Nerd\libsndfile\bin`)

Then you right click on your project and go to **Build options... > Search directories > Compiler** and add the address of `sndfile.h` directory.

[![compiler directory][1]][1]

Then, you go to **Build options... >Linker settings > Link libraries:** and add the address of `libsndfile-1.lib`.

[![link lib][2]][2]

Finally, you copy the `libsndfile-1.dll` next to where the `.exe` file will be created (for me it's in `MyProject\bin\Debug`).


*Credits [SO](https://stackoverflow.com/a/53298543/7105378).*

  [1]: https://i.stack.imgur.com/EA2SR.png
  [2]: https://i.stack.imgur.com/xaWnv.png
