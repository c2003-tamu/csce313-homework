g++ *.cpp;
rm tests/testout.txt
./a.out tests/test1.txt;
cat tests/testout.txt;
rm tests/testout.txt
./a.out tests/test2.txt;
cat tests/testout.txt;