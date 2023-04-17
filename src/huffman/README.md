# Huffman
The `./testfiles` folder is ignored through gitignore, as it might contain large files.
Use the following command in the root directory of this repository populate it or create your own testfiles.

`make`

If you want to do testing using larger files aswell, you can generate these using:

`make big`

Files with random bytes won't be able to be compressed by much, that is normal.
Instead, try something like a text file (or any other file with lower entropy), the LICENSE in the root of this repository for example.
