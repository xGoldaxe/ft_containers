#! /usr/bin/bash
#cmds
mkdir="/usr/bin/mkdir"
rm="/usr/bin/rm -f"
diff="/usr/bin/diff"
wc="/usr/bin/wc"
make="/usr/bin/make"
valgrind="/usr/bin/valgrind"

COMPILFLAG="-std=c++98"
CPPFLAGS="-Wall -Wextra -Werror -I."
LIBNAME="container.a"
PATH="../container.a"
CPP="/usr/bin/c++"

TESTPATH="../tests/"
BASEPATH=$TESTPATH
FOLDER_PATH=""

PASS=0
NB_TEST=0

# COLORS
NONE="\033[0m"
CL_LINE="\033[2K"
B_RED="\033[1;31m"
B_GREEN="\033[1;32m"
B_MAGENTA="\033[1;35m"
B_CYAN="\033[1;36m"

cd ".."
$make "relib" > /dev/null
cd "tester"

#flags
re_flag=0
debug_flag=0
argv=""

#modular routers
modular_no() {

    if [ "$1" == "valgrind" ] ; then
        valgrind=""
    else
        #base case
        echo "#FLAG --no:" "\"$1\"" "is not valid!"
    fi
}

#arg router
for var in "$@"
do
    arrModular=(${var//=/ })

    if [ "$var" == "--re" ] ; then
        re_flag=1
    elif [ "$var" == "--debug" ] ; then
        debug_flag=1
    elif [ "${arrModular[0]}" == "--no" ] ; then
        modular_no "${arrModular[1]}"
    elif [ "${arrModular[0]}" == "--folder" ] ; then
        TESTPATH+=${arrModular[1]}
        FOLDER_PATH="${arrModular[1]}/"
    elif [ "${arrModular[0]}" == "--COMPILFLAG" ] ; then
        COMPILFLAG=${arrModular[1]}
    elif [ "$var" == "--leak-check=full" ] ; then
        valgrind="/usr/bin/valgrind --leak-check=full"
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
    #tests percentage
    ((NB_TEST++))

    # args
    TEST=$1

    TEST="${TEST%.*}"
    TEST="${TEST##*tests/}"

    NAME="${TEST##*/}"
    NAME="${TEST%.test*}"

    # for each test
    MAINPATH="${BASEPATH}${TEST}.cpp"
    EXECPATH="./execs/${TEST}"
    OUTFILEPATH="outfile/${NAME}.out"

    #execution flags ===========================================
    exec_flags $MAINPATH
    #execution flags ===========================================


    # declare -i i=0
    # while [ ! -f "$EXECPATH" ] ; do
    #     $CPP $CPPFLAGS $COMPILFLAG $PATH $MAINPATH -o $EXECPATH
    #     i=$(( i + 1 ))
    #     if [ $i -gt 5 ] ;then
    #         echo "Can't compile, now exiting ..."
    #         exit 1
    #     fi
    # done

    if [ ! -f "$EXECPATH" ] ; then
        $CPP $CPPFLAGS $E_COMPILFLAG $PATH $MAINPATH -o $EXECPATH
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
        #replace
        find_up "$(/usr/bin/dirname "$MAINPATH")" "replace.sh"
        /usr/bin/bash $REPLACE_PATH $FTMAINPATH
    fi
    # replace

    EXECPATH="./execs/${TEST}_ft"
    OUTFILEPATHFT="outfile/${NAME}_ft.out"
    i=$(( 0 ))
    # while [ ! -f "$EXECPATH" ] ; do
    #     $CPP $CPPFLAGS $COMPILFLAG $PATH $MAINPATH -o $EXECPATH
    #     i=$(( i + 1 ))
    #     if [ $i -gt 5 ] ;then
    #         echo "Can't compile, now exiting."
    #         exit 1
    #     fi
    # done
     #execution flags ===========================================
    exec_flags $FTMAINPATH
    #execution flags ===========================================

    if [ ! -f "$EXECPATH" ] ; then
        $CPP $CPPFLAGS $E_COMPILFLAG $PATH $FTMAINPATH -o $EXECPATH
    fi
    if [ "${2}" == "--debug" ]; then
        $valgrind $EXECPATH
    else
        $valgrind $EXECPATH > $OUTFILEPATHFT 2> outfile/.errors
    fi

    DIFFPATH="diff/${NAME}.diff"
    if [ $debug_flag -ne 0 ]; then
        return
    fi

    $diff $OUTFILEPATH $OUTFILEPATHFT > $DIFFPATH
    CONDITION=$($wc -l < $DIFFPATH)

    if [ $CONDITION -eq 0 ]
    then

        if [[ "$valgrind" == "" ]] ; then
            echo "✅ [" $NAME "] -OK"
            ((PASS++))
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
                    ((PASS++))
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

find_up () {
    path=$1

    while [[ "$path" != "." && "$path" != ".." && "$path" != "" ]]; do
        if [ -f "$path/replace.sh" ]; then
            REPLACE_PATH="$path/replace.sh"
            break
        fi
        path="$(/usr/bin/dirname "$path")"
    done
}

exec_flags() {
    E_PATH=$1
    E_COMPILFLAG=$COMPILFLAG
    E_ARGS=`/usr/bin/grep E_ARGS $E_PATH`
    IFS=' ' read -ra E_ARGS <<< "$E_ARGS"

    if [ "$E_ARGS" != "" ]; then
        if [ ${E_ARGS[1]} == "E_ARGS" ]; then
            for (( n=0; n < ${#E_ARGS[*]}; n++))
            do
                var="${E_ARGS[n]}"
                arrModular=(${var//=/ })

                if [ "${arrModular[0]}" == "--COMPILFLAG" ] ; then
                    E_COMPILFLAG=${arrModular[1]}
                    E_COMPILFLAG+="="
                    E_COMPILFLAG+=${arrModular[2]}
                fi
            done
        fi
    fi
}

#launch one test
if [ "$argv" != "" ]; then
    MAINPATH="${TESTPATH}${argv}"
    if [ ! -f "${MAINPATH}.test.cpp" ] ; then
        echo "This test doesn't exist!: $argv"
        exit 0
    fi
    if [ $re_flag -eq 1 ] ; then
        $rm "tests_ft/${FOLDER_PATH}${argv}.test_ft.cpp" "execs/${FOLDER_PATH}${argv}.test_ft" "execs/${FOLDER_PATH}${argv}.test"
    fi
    if [ $debug_flag -eq 1 ] ; then
        $rm -r tests_ft/${FOLDER_PATH}${argv}.test_ft.cpp execs/${FOLDER_PATH}${argv}.test execs/${FOLDER_PATH}${argv}.test_ft
        do_test "${MAINPATH}.test.cpp" "--debug"
    else
        do_test "${MAINPATH}.test.cpp"
    fi
    exit 0
fi

printf "$B_CYAN       =============================       \n"
printf "======== PLEVEQUE TESTER FRAMEWORK ========\n"
printf "       =============================       $NONE\n"

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

printf "\n$B_GREEN"
if [ $PASS -eq $NB_TEST ] ; then
    printf "          -- ALL TESTS SUCCEED --          "
else
    printf "============== PASS: %d/%d =============" $PASS $NB_TEST
fi