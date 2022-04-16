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

#flags
re_flag=0
debug_flag=0
argv=""

for var in "$@"
do
    if [ "$var" == "--no=valgrind" ] ; then
        valgrind=""
    elif [ "$var" == "--re" ] ; then
        re_flag=1
    elif [ "$var" == "--debug" ] ; then
        debug_flag=1
    else
        argv=$var
    fi
done


# create folders
$rm -r outfile diff

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

    declare -i i=0
    # while [ ! -f "$EXECPATH" ] ; do
    #     $CPP $CPPFLAGS $PATH $MAINPATH -o $EXECPATH
    #     i=$(( i + 1 ))
    #     if [ $i -gt 5 ] ;then
    #         echo "Can't compile, now exiting ..."
    #         exit 1
    #     fi
    # done
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
    FOLDER_PATH="$(/usr/bin/dirname "${TEST}")"
    # cat 
    FTMAINPATH="tests_ft/${TEST}_ft.cpp"
    if [[ ! -f "$FTMAINPATH" ]]; then
        /bin/touch $FTMAINPATH
        echo "#include \"../ft.hpp\"" >> $FTMAINPATH
        /bin/cat $MAINPATH >> $FTMAINPATH
        /usr/bin/sed -i -- 's/std::vector/ft::vector/g' $FTMAINPATH
        /usr/bin/sed -i -- 's/std::reverse_iterator/ft::reverse_iterator/g' $FTMAINPATH
        /usr/bin/sed -i -- 's/std::map/ft::map/g' $FTMAINPATH
    fi
    # replace

    EXECPATH="./execs/${TEST}_ft"
    OUTFILEPATHFT="outfile/${NAME}_ft.out"
    i=$(( 0 ))
    # while [ ! -f "$EXECPATH" ] ; do
    #     $CPP $CPPFLAGS $PATH $MAINPATH -o $EXECPATH
    #     i=$(( i + 1 ))
    #     if [ $i -gt 5 ] ;then
    #         echo "Can't compile, now exiting."
    #         exit 1
    #     fi
    # done
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
if [ "$argv" != "" ]; then
    if [ ! -f "${TESTPATH}${argv}.test.cpp" ] ; then
        echo "This test doesn't exist!"
        exit 0
    fi
    if [ $re_flag -eq 1 ] ; then
        $rm "tests_ft/${argv}.test_ft.cpp" "execs/${argv}.test_ft" "execs/${argv}.test"
    fi
    if [ $debug_flag -eq 1 ] ; then
        $rm -r tests_ft/${argv}.test_ft.cpp execs/${argv}.test execs/${argv}.test_ft
        do_test "${argv}.test.cpp" "--debug"
    else
        do_test "${argv}.test.cpp"
    fi
    exit 0
fi

printf "=========TESTS=========\n\n"

FILES=`/usr/bin/find ${TESTPATH} -name "*.cpp"`

echo $FILES_R

if [ $re_flag -eq 1 ] ;then
    $rm -r tests_ft execs
    $mkdir -p tests_ft execs
    /usr/bin/rsync --quiet -av -f"+ */" -f"- *" "$TESTPATH" "execs"
    /usr/bin/rsync --quiet -av -f"+ */" -f"- *" "$TESTPATH" "tests_ft"
fi

for TEST in $FILES
do
    do_test $TEST

done

printf "\n=======END  TESTS=======\n"