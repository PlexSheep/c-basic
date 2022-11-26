# Huffman
The `./testfiles` folder is ignored through gitignore, as it might contain large files.
Use the following command to populate it or create your own testfiles.

``dd if=/dev/urandom of=10K-random.img count=1K``

``dd if=/dev/urandom of=10K-random.img count=1M``

``dd if=/dev/urandom of=10K-random.img count=1G``

...

Files with random bytes won't be able to be compressed by much, that is normal.
Instead, try something like a text file (or any other file with lower entropy), the LICENSE in the root of this repository for example.
