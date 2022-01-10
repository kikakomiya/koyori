# koyori

Koyori is a simple text editor created in C with GTK. It aims to be simple and fast but also elegant and sleek.

Please note that Koyori is very early in development.

Features to be implemented:
- Save/load
- Rich text
- Syntax highlighting


## Building

Currently the only OS I build this program is in Linux, so if you use Windows and are able to build the program with no errors, please submit a pull request.

The software required for building Koyori are:
- GNU make
- a C compiler (recommended LLVM clang or GNU GCC)
- GTK 4
- GLib
- Cairo
- Pango
- Harfbuzz
- GDK Pixbuf
- Graphene

Before running `make`, the resources.c file must be created. To do this, open a terminal and navigate to the `src` folder. From there, run `glib-compile-resources --sourcedir=../resources --target=resources.c --generate-source ../resources/about_window.xml`. Now you are able to run `make`.

If you require debugging symbols on the executable file for use with gdb or another debugger, compile Koyori with `make DEBUG=yes`. This will compile with the extra compiler flags of `-O0 -g`.

## Usage

For now Koyori can be run with `./koyori` after building, with support for `./koyori <file>` in order to open a file directly being planned.


## Licenses

Koyori is licensed under the ISC License, found in the LICENSE file or [here](https://opensource.org/licenses/ISC).

GTK is licensed under the GNU LGPLv2, found [here](https://www.gnu.org/licenses/old-licenses/lgpl-2.0.html).
