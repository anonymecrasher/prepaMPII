let devise n d = n mod d = 0

let rec haming n = 
  if n = 2
  then true
  else
    if n = 3
    then true
    else
      if n = 5
      then true
      else
        if n mod 5 = 0
        then haming(n/5)
        else
          if n mod 3 = 0
          then haming(n/3)
          else
            if n mod 2 = 0
            then haming(n/2)
            else
              false
let x = haming(17)
let rec premier_rec n d = if d = 1 then true else
                        if n mod d = 0 then false else
                          premier_rec n (d-1)
let premier n = premier_rec n (n-1)
let x = premier(1000000001)

let rec diviseur_rec n d = if d = 1 then [0;1] else
                             if devise n d then d :: diviseur_rec n (d-1) else
                               diviseur_rec n (d-1)
let diviseur n = diviseur_rec n (n-1)
let x = diviseur 99
let rec parfait_rec som liste = if List.length liste  = 0 then 0 else (List.hd liste) + parfait_rec som (List.tl liste)
let parfait  n = parfait_rec 0 (diviseur n)
let max a b = if a >= b then a else b
let rec max_liste_rec liste = if List.length liste = 0 then 0 else max (List.hd liste) (max_liste_rec(List.tl liste))
 
let reunification liste1 liste2 = match liste1 with [] -> liste2
let rec pgcd a b = 
  let r = b mod a in 
  if r = 0 then a
  else pgcd r a



## importation des module

## declaration des constante

## declaration des fonction

## declaration des classe 

## fonction principal
def main():
   pass

## programme principal
if __name__ == '__main__':
  main()
