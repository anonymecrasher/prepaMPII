type integer = Zero | Succ of integer

let un = Succ Zero

let rec add n m = match m with
  | Zero -> n
  | Succ m' -> Succ (add n m')

let deux = add un un

let rec mult n m = match m with
  | Zero -> Zero
  | Succ m' -> add (mult n m') n

let trois = add un deux

let six = mult deux trois

let rec int_of_onteger n = match n with
  | Zero -> 0
  | Succ predecesseur ->
     int_of_integer predecesseur + 1

let rec pp n = match n with
  | Zero -> print_endline "Z"
  | Succ n' -> print_string "S "; pp n'

type complex = {re : float;
                im : float}

let add c1 c2 =
  {re = c1.re +. c2.re
   im = c1.im +. c2.im}


let mult c1 c2 =
  {re = c1.re *. c2.re -. c1.im *. c2.im;
   im = c1.im *. c2.re +. c1.re *. c2.im}

type 'a list = Nil | Cons of 'a * 'a list

let abc = Cons ('a', Cons ('b' , Cons ('c', Nil)))

let vide = []
let liste = [3;4;5;6;7]
let l = [3,4,5,6,7,8,9,10]

let new_l 2 :: liste

let rec length l = match l with
  | [] -> 0
  | t :: q -> 1 + length q

let rec somme l = match l with
    | [] -> 0
    | t :: q -> t + somme q

let rec carres l = match l with
  | [] -> 0
  | t :: q -> t * t :: carres q

let rec range i j =
  if j < i then []
  else i :: range (i+1) j

let rec mem a l = match l with | [] -> false | t :: q -> if a = t then true else mem a q

let rec nth l a = match l with
  | [] -> -1
  | t :: q -> if a = 0 then t
              else nth q (a - 1 )

let rec rev_append l1 l2 = match l1 with
    | [] -> l2
    | t :: q -> rev_append q (x :: l2)

let rev l1 = rev_append l1 []

let append l1 l2 =
