ANS=0
l=()
regex='^([A][N][S]|[0-9]+)\s([+]|[-]|[*]|[/]|[%])\s([A][N][S]|[0-9]+)'

while true;
do
    arrow=">> "
    read -p "$arrow" input
    string="$input"
    if [ "$input" == "EXIT" ]; then
        break
    fi
    if [ "$string" == "HIST" ]; then
        for element in "${l[@]}"; do
            echo "$element"
        done
    fi
    if [[ $string =~ $regex ]]; then
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
        if [[ "$string" == *"/ 0" ]] || [[ "$string" == *"% 0" ]]; then
            echo "MATH ERROR"
        else
            # change a to ANS
            if [ $a == "ANS" ]; then
                a=$ANS
                fi
            # change b to ANS
            if [ $b == "ANS" ]; then
                b=$ANS
                fi
            #evaluate
            if [[ "$c" == "/" ]]; then
                ANS=$(echo "$a / $b" | bc -l)
                string="$string = $ANS"
            elif [[ "$c" == "%" ]]; then
                ANS=$(echo "$a / $b" | bc)
                string="$string = $ANS"
            else 
                ANS=$(echo "$a $c $b" | bc)
                string="$string = $ANS"
            fi

            #insert to list l for HIST
            if [ ${#l[@]} == 5 ]; then
                unset l[0]
                l+=("$string")
            else
                l+=("$string")
            fi
            echo $ANS
        fi
    else
        if [ "$input" != "HIST" ]; then
            echo "SYNTAX ERROR"
        fi
    fi
done