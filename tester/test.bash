#! /usr/bin/bash
#cmds
mkdir="/usr/bin/mkdir"
rm="/usr/bin/rm -f"
diff="/usr/bin/diff"
wc="/usr/bin/wc"
make="/usr/bin/make"
valgrind="/usr/bin/valgrind"


CPPFLAGS="-Wall -Wextra -Werror -I. -std=c++98"
LIBNAME="container.a"
PATH="../container.a"
CPP="/usr/bin/c++"

TESTPATH="../tests/"

PASS=0
NB_TEST=0

cd ".."
$make "relib" > /dev/null
cd "tester"

# create folders
$rm -r outfile diff


if [ "$1" == "--no=valgrind" ] ; then
    valgrind=""
fi

if [ "$1" == "re" ]; then
   $rm -r tests_ft execs
fi

if [ "$2" == "--debug" ]; then
   $rm -r tests_ft execs
fi

$mkdir -p outfile diff tests_ft execs
/usr/bin/rsync --quiet -av -f"+ */" -f"- *" "$TESTPATH" "outfile"
/usr/bin/rsync --quiet -av -f"+ */" -f"- *" "$TESTPATH" "execs"
/usr/bin/rsync --quiet -av -f"+ */" -f"- *" "$TESTPATH" "diff"
/usr/bin/rsync --quiet -av -f"+ */" -f"- *" "$TESTPATH" "tests_ft"


do_test() {
    # args
    TEST=$1

    TEST="${TEST%.*}"
    TEST="${TEST##*tests/}"

    NAME="${TEST##*/}"
    NAME="${TEST%.test*}"

    # for each test
    MAINPATH="${TESTPATH}${TEST}.cpp"
    EXECPATH="./execs/${TEST}"
    OUTFILEPATH="outfile/${NAME}.out"

    if [ ! -f "$EXECPATH" ] ; then
        $CPP $CPPFLAGS $PATH $MAINPATH -o $EXECPATH
    fi
    if [ "${2}" == "--debug" ]; then
        $valgrind $EXECPATH
        echo "<---------------->"
    else
        $valgrind $EXECPATH > $OUTFILEPATH 2> outfile/.errors
    fi


    # replace
    FTMAINPATH="tests_ft/${TEST}_ft.cpp"
    if [[ ! -f "$FTMAINPATH" ]]; then
        /bin/cp $MAINPATH $FTMAINPATH
        /usr/bin/sed -i -- 's/std::vector/ft::vector/g' $FTMAINPATH
        /usr/bin/sed -i -- 's/std::reverse_iterator/ft::reverse_iterator/g' $FTMAINPATH
    fi
    # replace

    EXECPATH="./execs/${TEST}_ft"
    OUTFILEPATHFT="outfile/${NAME}_ft.out"
    if [ ! -f "$EXECPATH" ] ; then
        $CPP $CPPFLAGS $PATH $FTMAINPATH -o $EXECPATH
    fi
    if [ "${2}" == "--debug" ]; then
        $valgrind $EXECPATH
        exit 0
    else
        $valgrind $EXECPATH > $OUTFILEPATHFT 2> outfile/.errors
    fi

    DIFFPATH="diff/${NAME}.diff"
    $diff $OUTFILEPATH $OUTFILEPATHFT > $DIFFPATH

    CONDITION=$($wc -l < $DIFFPATH)

    if [ $CONDITION -eq 0 ]
    then

        if [[ "$valgrind" == "" ]] ; then
            echo "✅ [" $NAME "] -OK"
        else
            #valgrind error
            CONDITION=`/usr/bin/cat outfile/.errors | /usr/bin/grep "ERROR SUMMARY:" | /usr/bin/awk '{ print $4}' `
            if [[ "$CONDITION" == "0" ]]
            then
                #leak
                CONDITION=`/usr/bin/cat outfile/.errors | /usr/bin/grep "All heap blocks were freed -- no leaks are possible" `
                if [[ "$CONDITION" != "" ]]
                then
                    echo "✅ [" $NAME "] -OK"
                else
                    echo "❌ [" $NAME "] -KO (leak)"
                fi
                #leak

            else
                echo "❌ [" $NAME "] -KO (valgrind)"
            fi
            # valgrind error
        fi

    else
        echo "❌ [" $NAME "] -KO"
    fi
    # for each
}

#launch one test
if [ "$1" != "re" ] && [ "$1" != "" ] && [ "$1" != "--no=valgrind" ]; then
    if [ ! -f "${TESTPATH}${1}.test.cpp" ] ; then
        echo "This test doesn't exist!"
        exit 0
    fi
    if [ "$2" == "re" ] ; then
        $rm "tests_ft/${1}.test_ft.cpp" "execs/${1}.test_ft" "execs/${1}.test"
    fi
    if [ "$2" == "--debug" ] ; then
        if [ "$3" == "--no=valgrind" ] ; then
            valgrind=""
        fi
        do_test "${1}.test.cpp" "--debug"
    else
        do_test "${1}.test.cpp"
    fi
    exit 0
fi

printf "=========VECTOR=========\n\n"

FILES=`/usr/bin/ls ${TESTPATH}*.cpp`
FILES_R=`/usr/bin/ls ${TESTPATH}*/*.cpp`
FILES+="$FILES_R"

for TEST in $FILES
do
    do_test $TEST

done

printf "\n=======END  VECTOR=======\n"