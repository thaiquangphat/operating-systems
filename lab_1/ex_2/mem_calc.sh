ANS=0
hist_count=0
regex='^([A][N][S]|[0-9]+)\s([+]|[-]|[*]|[/]|[%])\s([A][N][S]|[0-9]+)'

IFS= read -r hist_count < hist_cnt

while true;
do
    arrow=">> "
    read -p "$arrow" input
    string="$input"
    if [ "$input" == "EXIT" ]; then
        break
    fi
    if [ "$string" == "HIST" ]; then
        while IFS= read -r line; do
            echo "$line"
        done < hist
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
            IFS= read -r ANS < ans
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
                echo "$ANS" > ans
                string="$string = $ANS"
            elif [[ "$c" == "%" ]]; then
                ANS=$(echo "$a / $b" | bc)
                echo "$ANS" > ans
                string="$string = $ANS"
            else 
                ANS=$(echo "$a $c $b" | bc)
                echo "$ANS" > ans
                string="$string = $ANS"
            fi

            #insert to text file hist
            echo "$string" >> hist
            echo $ANS
            if [ $hist_count == 5 ]; then
                # read from second line of hist
                flag=0
                while IFS= read -r line; do
                    if [ $flag == 1 ]; then
                        echo "$line" >> hist_tmp
                    else 
                        ((flag += 1))
                    fi
                done < hist
                # clear hist file
                echo -n > hist
                # read back to hist file
                while IFS= read -r line; do
                    echo "$line" >> hist
                done < hist_tmp
                echo -n > hist_tmp 
            else
                ((hist_count += 1))
            fi
            echo "$hist_count" > hist_cnt
        fi
    else
        if [ "$input" != "HIST" ]; then
            echo "SYNTAX ERROR"
        fi
    fi
done