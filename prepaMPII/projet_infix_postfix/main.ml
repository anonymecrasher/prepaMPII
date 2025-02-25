

let test_operation c =
  if c = '+' then 1        (* addition a + b : TODO*)
  else if c = '-' then 2   (* soustraction a - b : TODO*)
  else if c = '*' then 3   (* multiplication a * b : TODO *)
  else if c = '/' then 4   (* division a / b : TODO *)
  else if c = '^' then 5   (* exponentiation a ^ b : TODO *)
  else if c = "**" then 5  (* exponentiation a ** b : TODO *)
  else if c = "//" then 6  (* division entier a // b : TODO *)
  else if c = '%' then 7   (* modula a % b : TODO *)
  else if c = "==" then 8  (* egalite a == b : TODO *)
  else if c = "!=" then 9  (* inegalite a != b : TODO *)
  else if c = '>' then 10  (* superieur strict a > b : TODO *)
  else if c = ">=" then 11 (* superieur a >= b : TODO *)
  else if c = '<' then 12  (* inferieur strict a < b : TODO *)
  else if c = "<=" then 13 (* inferieur a <= b: TODO *)
  else if c = '&' then 14  (* ET logique (TYPE array) a = (TRUE,FALSE,TRUE) ; b = (TRUE,FALSE,FALSE) ; a & b ----> (TRUE,FALSE,FALSE) : TODO *)
  else if c = "&&" then 15 (* ET logique a && b : TODO *)
  else if c = '|' then 16  (* OU logique (TYPE array) a = (TRUE,FALSE,TRUE) ; b = (TRUE,FALSE,FALSE) ; & | b ----> (TRUE,FALSE,TRUE) : TODO *)
  else if c = "||" then 17 (* OU logique a || b : TODO *)
  else if c = '!' then 18  (* not logiqUE a != b : TODO *)
  else if c = "<-" then 19 (* i don't know surprise*)
  else if c = ':' then 20  (* begin and end of an array *)
  else if c = ';' then 21  (* separator of an array *)

let read () =
  let values = Stack.create () in
  let () =
    try while true do
          let l = read_line () in
          if test_operation

    done
    with End_of_file -> Stack.peek l



