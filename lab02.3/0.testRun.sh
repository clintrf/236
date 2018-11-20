g++ -g -Wall -Werror -std=c++11 *.cpp -o database;

./database in.1.txt; echo in.1.txt; diff -s in.key.1.txt in.out.in.1.txt;
./database in.2.txt; echo in.2.txt; diff -s in.key.2.txt in.out.in.2.txt;
./database in.3.txt; echo in.3.txt; diff -s in.key.3.txt in.out.in.3.txt;
./database in.4.txt; echo in.4.txt; diff -s in.key.4.txt in.out.in.4.txt;
./database in.5.txt; echo in.5.txt; diff -s in.key.5.txt in.out.in.5.txt;
./database in.6.txt; echo in.6.txt; diff -s in.key.6.txt in.out.in.6.txt;
./database in.7.txt; echo in.7.txt; diff -s in.key.7.txt in.out.in.7.txt;
./database in.8.txt; echo in.8.txt; diff -s in.key.8.txt in.out.in.8.txt;
./database in.9.txt; echo in.9.txt; diff -s in.key.9.txt in.out.in.9.txt;
./database in.10.txt; echo in.10.txt; diff -s in.key.10.txt in.out.in.10.txt;
./database in.11.txt; echo in.11.txt; diff -s in.key.11.txt in.out.in.11.txt;

