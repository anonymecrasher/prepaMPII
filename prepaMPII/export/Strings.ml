let (+^) arg1 arg2 = (String.make 1 arg1) ^ arg2

let rec mult str n = 
  if n = 0 then ""
  else str ^ (mult str (n-1))

let carre str n = 
  let rec carre_b str n c_n = 
    if n = 0 then ""
    else (mult str n) ^ "\n" ^ (carre_b str n  (c_n-1)) 
  in
  carre_b str n n

let pyramide str n = 
  let rec pyramide_b str n c_n =
    if n = 0 then ""
    else (mult str (n - c_n
