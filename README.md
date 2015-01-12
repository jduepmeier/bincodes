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
-c, --checksum        adds the checksum to the barcode.
-e, --encoding <char> sets the encoding for the barcode. See encodings for valid ones.
-d, --debug <int>     sets the debug level (ERROR = 0; WARNING = 1; DEBUG = 2; INFO = 3).
-b, --bar <char>      character that represents the bars.
-s, --space <char>    character that represents the spaces.
-w, --width <int>     width that represents an element
-h, --help            show this usage.
```
# encodings

Valid encodings are:
* 39      - code39
* ean     - european article number
* upc     - upc == 12-digit ean
* isbn    - isbn numbers (still EAN13)
* 128     - code128 (a,b,c: autoselection)
* 128c    - code128 (compact form for digets)
* 128b    - code128, full printable ascii
* i25     - interleaved 2 of 5 (only digits)
* 128raw  - raw code 128 (by Leonid A. Broukhis)
* cbr     - Codebar (by Leonid A. Broukhis)
* msi     - MSI (by Leonid A. Broukhis)
* pls     - Plessey (by Leonid A. Broukhis)
* 93      - code93 (by Nathan D. Holmes)

# examples

```
./bincodes test (outputs the binary representation of test encoded in code39)
./bincodes -b \# -s - -w 2 test (outputs the binary repressentation of test encoded in code39 with # as bar character, - as space and every bit is represented as two characters.
