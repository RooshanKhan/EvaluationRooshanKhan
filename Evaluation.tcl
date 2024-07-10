#Case 1: Divisor is greater than Dividend
set a 30
set b 60
set Ans1 [expr $a / $b]
set Ans2 [expr $a % $b]
puts "Quotient of 30/60 =$Ans1\n"
puts "Remainder of 30/60 =$Ans2\n"

#Case 2: Divisor is smaller than Dividend
set a 30
set b 15
set Ans1 [expr $a / $b]
set Ans2 [expr $a % $b]
puts "Quotient of 30/60 =$Ans1\n"
puts "Remainder of 30/60 =$Ans2\n"

#Case 3: Divisor is equal to Dividend
set a 30
set b 30
set Ans1 [expr $a / $b]
set Ans2 [expr $a % $b]
puts "Quotient of 30/60 =$Ans1\n"
puts "Remainder of 30/60 =$Ans2\n"

#Case 4: Divisor is Zero
set a 30
set b 0
set Ans1 [expr $a / $b]
set Ans2 [expr $a % $b]
puts "Quotient of 30/ =$Ans1\n"
puts "Remainder of 30/60 =$Ans2\n"
