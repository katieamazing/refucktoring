#!/usr/bin/expect

spawn ./dds
expect "Ok"

send "OLD LANDER.BAS\n"
expect "Ok"
send "RUN\n"

proc play_some_turns { fuel_per_turn turns } {
    for {set i 0} {$i < $turns} {incr i} {
        expect {
            "No cheating please!  Fuel must be >= 0." {
                puts "CHEAT!"
                break
            }
            "You have crashed." {
                puts "CRASHED!"
                break
            }
            "Sorry, you have not got that much fuel!" {
                puts "OUTAFUEL!"
                break
            }
            "Congratulations!  This was a very good landing." {
                puts "LANDED!"
                break
            }
            "How much fuel will you use?" {
                send "$fuel_per_turn\n"
            }
        }
    }
}

play_some_turns 0 12
play_some_turns 470 1
expect "Do you want to play again? (0 = no, 1 = yes)"
send "1\n"
play_some_turns 1 13
play_some_turns 415 1
expect "Do you want to play again? (0 = no, 1 = yes)"
send "1\n"
play_some_turns 2 13
play_some_turns 415 1
expect "Do you want to play again? (0 = no, 1 = yes)"
send "1\n"
play_some_turns 4 13
play_some_turns 415 1
expect "Do you want to play again? (0 = no, 1 = yes)"
send "1\n"
play_some_turns 8 14
play_some_turns 350 1
expect "Do you want to play again? (0 = no, 1 = yes)"
send "1\n"
play_some_turns 16 19
play_some_turns 160 1
expect "Do you want to play again? (0 = no, 1 = yes)"
send "0\n"
expect "Have a nice day."
send "BYE\n"
