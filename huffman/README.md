# Huffman
the testfiles folder is unpopulated and not staged through gitignore, as it might contain large files.
use the following command to populate it or create your own testfiles.

``dd if=/dev/urandom of=10K-random.img count=1K``

dd if=/dev/urandom of=10K-random.img count=1M``

...

files with random bytes wont be able to be compressed byy much, that is normal.
Instead try something like a text file. The LICENSE in the root of this repo for example.
