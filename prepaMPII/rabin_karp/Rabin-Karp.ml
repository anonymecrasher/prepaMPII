
let rec pow b n modulo = if n = 0 then 1 else (b * (pow b (n-1) modulo)) mod modulo
let basis = 256
let modulo = 1 lsl 31 - 1
let text = "J'ai mis mon chapeau sur ma tête !"
let pat = "peau"


let is_occurence (text : string) (pat : string) (i : int) : bool =
  let rec aux j =
    if j = String.length pat
    then true
    else if (String.get text (i+j)) <> (String.get pat j) then false
    else aux (j + 1)
  in
  aux 0

let rec hash u i m =
  if m = 0 then 0
  else
    let hash' = hash u i (m - 1) in
    let last = int_of_char u.[i + m - 1] in
    (hash' * basis + last) mod modulo

let update h u0 um bn =
  (h * basis - int_of_char u0 * bn + int_of_char um) mod modulo

let search text pat =
  try
    let cpt = ref 0 in
    let n = String.length text in
    let m = String.length pat in
    let h_pat = hash pat 0 m in
    let h = ref (hash text 0 m) in
    let bm = pow basis m modulo in
    let occ i = print_int i;print_newline (); incr cpt in
    if h_pat = !h && is_occurence text pat 0
    then occ 0;
    for i = 0 to n - m do
      h := update !h text.[i - 1] text.[i - 1 + m] bm;
      if h_pat = !h && is_occurence text pat i
      then occ i
    done;
    !cpt
  with _ -> 0

let rec read_file f acc =
  try
    let l = input_line f in
    read_file f (l :: acc)
  with End_of_file -> List.rev acc

let () =
  let filename = Sys.argv.(2) in
  let pattern = Sys.argv.(1) in
  let f = open_in filename in
  let text = read_file f [] in
  close_in f;
  List.iter (fun l -> if search l pattern > 0 then print_endline l) text
