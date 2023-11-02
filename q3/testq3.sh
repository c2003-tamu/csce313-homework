echo
echo "TEST 1"
echo 
g++ *.cpp;
rm tests/testout.txt
touch tests/testout.txt
./a.out tests/test1.txt;
cat tests/testout.txt;



echo
echo "TEST 2"
echo
rm tests/testout.txt;
touch tests/testout.txt
./a.out tests/test2.txt;
cat tests/testout.txt;
echo;

echo "hello, world" > tests/test1.txt
echo "howdy, y'all" > tests/test2.txt