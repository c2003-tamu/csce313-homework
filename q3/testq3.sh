g++ *.cpp;
rm tests/testout.txt
./a.out tests/test1.txt;
cat tests/testout.txt;
rm tests/testout.txt;
./a.out tests/test2.txt;
cat tests/testout.txt;
echo "hello, world" > tests/test1.txt
echo "howdy, y'all" > tests/test2.txt