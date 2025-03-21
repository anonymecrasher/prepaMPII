type ('a , 'b) association = {cle : 'a; valeur : 'b}

let add  (k : 'a) (v : 'b) (l : ('a, 'b) association list)
    : ('a , 'b) association list =
  {cle = k ; valeur = v} :: l

let rec find (k : 'a) (l : ('a, 'b) association list)
    : 'b option = match l with
  | [] -> None
  | h :: q -> if h.cle = k then Some h.valeur
              else find k q

let rec remove (k : 'a) (l : ('a, 'b) association list)
    : ('a, 'b) association list =
  match l with
    | [] -> []
    | h :: q -> if h.cle = k then remove k q
                else h :: remove k q

let mem (k: 'a) (l : ('a, 'b) association list) = find k l <> None

let rec iter (f : 'a -> 'b -> unit) (tab : ('a * 'b) list) : unit =
  match tab with
  | [] -> ()
  | t :: q -> (f t.cle t.valeur ; iter f q)

let modulo = 13
let basis = 256

let rec hash u i m =
  if m = 0 then 0
  else
    let hash' = hash u i (m -1) in
    let  last = int_of_char u.[i + m - 1] in
    (hash' * basis + last) mod modulo

let h str = hash str 0 (String.length str)
(*
let hashtbl = Array.make modulo None

exception Not_found
let hashtbl_find htab k v =
  let hk = h k in
  match htab.(hk) with 
  | None -> raise Not_found
  | Some a -> if a.cle = k then a.valeur
              else raise Not_found

exception Existing_key
let hashtbl_add htab k v =
  let hk = h k in
  match htab.(hk) with
  | Some a when a.cle <> k -> raise Existing_key
  | _ -> htab.(hk) <- Some {cle = k; valeur = v}
*)
let hashtbl = Array.make modulo []

exception Not_found
let hashtbl_find htab k v =
  let hk = h k in
  match find k htab.(hk) with
  | Some v -> v
  | None -> raise Not_found

exception Existing_key
let hashtbl_add htab k v =
  let hk = h k in
  htab.(hk) <- add k v htab.(hk)


let test = [|"père noël"; "SAMU" ; "Pompiers"; "Police" ; "Renseignements" ; "Secours"|]


let doublons tab = 
  let htab = hashtbl_init () in
  let rec loop_from i =
    try hashtbl_find tab.(i), i
    with Not_found -> hashtbl_add htab tab.(i) i;
                      loop_from (i+1)
  in
  try loop_from 0
  with _ -> raise Not_found

(*
for i to n do 




done 

*)
