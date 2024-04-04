ANS=0
l=()
re='^[0-9]+$'

while true;
do
    echo -n ">> "
    read input
    string="$input"
    if [ "$input" == "EXIT" ]; then
        break
    fi
    a=${input% *}
    a=${a% *}
    input=${input#* }
    c=${input:0:1}
    input=${input#* }
    b=$input
    b=${b#* }
    # echo $a
    # echo $c
    # echo $b
    if [ "$string" == "HIST" ]; then
        for element in "${l[@]}"; do
            echo "$element"
        done
    elif [[ "$string" == *"/ 0" ]] || [[ "$string" == *"% 0" ]]; then
        echo "MATH ERROR"
    elif [[ "$c" != "+" ]] && [[ "$c" != "-" ]] && [[ "$c" != "*" ]] && [[ "$c" != "/" ]] && [[ "$c" != "%" ]]; then
        echo "SYNTAX ERROR"
    elif [ $a != "ANS" ] && ! [[ "$a" =~ $re ]] || [ $b != "ANS" ] && ! [[ "$b" =~ $re ]]; then
        echo "SYNTAX ERROR"
    else
        # echo "VALID"
        if [ $a == "ANS" ]; then
            a=$ANS
            fi
        if [ $b == "ANS" ]; then
            b=$ANS
            fi
        if [[ "$c" == "/" ]]; then
            ANS=$(echo "$a / $b" | bc -l)
            string="$string = $ANS"
            if [ ${#l[@]} == 5 ]; then
                unset l[0]
                l+=("$string")
            else
                l+=("$string")
            fi
            echo $ANS
        elif [[ "$c" == "%" ]]; then
            ANS=$(echo "$a / $b" | bc)
            string="$string = $ANS"
            if [ ${#l[@]} == 5 ]; then
                unset l[0]
                l+=("$string")
            else
                l+=("$string")
            fi
            echo $ANS
        else 
            ANS=$(echo "$a $c $b" | bc)
            string="$string = $ANS"
            if [ ${#l[@]} == 5 ]; then
                unset l[0]
                l+=("$string")
            else
                l+=("$string")
            fi
            echo $ANS
        fi
    fi
done