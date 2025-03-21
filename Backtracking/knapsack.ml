type objet = { value : float; weight : float}

let exemple = [
    {value = 10.; weight = 0.5};
    {value = 10.; weight = 1.5};
    {value = 7.; weight = 0.3};
    {value = 10.; weight = 0.3};
    {value = 7.; weight = 0.3};
    {value = 3.; weight = 0.2};
  ]

let poisson lambda =
  let coin = Random.float 1. in
  -1. /. lambda *. log coin

let objet_alea () =
  { value = Random.float 1.; weight = poisson 5.}

let rec instance_alea n =
  if n = 0 then []
  else objet_alea () :: instance_alea (n-1)


let is_valid x  p  pm = ((x.weight +. p) <= pm)
let rec value ob_l = match ob_l with
    | [] -> 0.
    | hd :: tl -> hd.value +. (value tl)

let rec objet_taken p v ob_t ob_l pm = match ob_l with
    | [] -> []
    | hd :: tl ->
       if (is_valid hd p pm)
       then let x = (objet_taken (p +. hd.weight) (v +. hd.value) (hd :: ob_t) tl pm)
            in
            if v > value x then ob_t
            else x
       else objet_taken (p +. hd.weight) (v +. hd.value) (ob_t) tl pm

let x = objet_taken 0. 0. [] exemple 2.1
