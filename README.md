# bincodes
Using gnu barcode to transcode text to barcodes and displays it as binary format.

# requirements

You only need the gnu barcode (https://www.gnu.org/software/barcode/) tools.

# install

```
make
make install
```

# usage

```
-d, --debug <int>   sets the debug level (ERROR = 0; WARNING = 1; DEBUG = 2; INFO = 3).
-b, --bar <char>    character that represents the bars.
-s, --space <char>  character that represents the spaces.
-w, --width <int>   width that represents an element
-h, --help          show this usage.
```

# examples

```
./bincodes test (outputs the binary representation of test encoded in code39)
./bincodes -b \# -s - -w 2 test (outputs the binary repressentation of test encoded in code39 with # as bar character, - as space and every bit is represented as two characters.
