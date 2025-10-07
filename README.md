## argon : simple language and compiler

basic syntax:

```argon
# comments start with '#'

# variable declaration and initialization
let x = num 12
let y = dec 99.9
let c = alp 'a'
let s = text "hello world"

# printing to console
print : x       # prints 12
print : y c s   # prints 99.9 a hello world

# operators
let h = x + y
let j = x - y
let k = x * y
let l = x / y

# function declaration
$add num
    num a
    num b
    ret a + b
end

# function call
let v = @add : x y

# conditional
if x > 0
    print : x
else
    let z = num 0
    print : z
end
