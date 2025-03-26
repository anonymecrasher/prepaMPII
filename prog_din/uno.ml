type couleur = Jaune | Bleu | Rouge | Vert | Noir;;
type carte = int * couleur;;

let color_of_int n = match n with
  | 0 -> Jaune
  | 1 -> Bleu
  | 2 -> Rouge
  | 3 -> Vert
  | 4 -> Noir
  | _ -> assert false;;

let rand_carte () =
  let c = Random.int 41 in
  (c mod 10, color_of_int (c/10));;

let rec rand_main n =
  if n = 0 then [] else rand_carte ()::rand_main (n-1);;

let exemple = rand_main 7;;

let compatible (n1, c1) (n2, c2) =
  c1 = Noir || c2 = Noir || n1 = n2 || c1 == c2

let solve_sorted =
  let mem = Hashtbl.create 100 in
  let rec solve_aux (top ,main : carte * carte list) =
    try Hashtbl.find mem (top, main)
    with Not_found ->
          let res = match main with
            | [] -> 0
            | c :: q when compatible top c ->
               max
                 (1 + solve_aux (c, q))         (* ajout de c dans la suite *)
                 (solve_aux (top, q))           (* on n'ajoute pas c  *)
            | _ :: q -> solve_aux (top, q)      (* on n'ajoute pas c  *)
          in
          Hashtbl.add mem (top,main) res ; res
  in
  fun main -> solve_aux ((0, Noir), main)

(*
  let solve_sorted =
    let rec solve_aux (top,main) = match main with
      | [] -> 0
      | c :: q when compatible top c ->
        max
          (1 + solve_aux (c, q))         (* ajout de c dans la suite *)
          (solve_aux (top, p))           (* on n'ajoute pas c  *)
      | _ :: q -> solve_aux (top, q)     (* on n'ajoute pas c  *)
    in
    fun main -> solve_aux ((0, Noir), main)
*)

let rec regroupe avant apres = match avant with
  | [] -> apres
  | x :: avant' -> regroupe avant' (x :: apres)

let all_extract l =
  let rec extract_aux avant = function
    | [] -> []
    | x :: apres -> (x, regroupe avant apres) :: extract_aux (x :: avant) apres
  in extract_aux [] l

let rec maximum = function
  | [] -> 0
  | t :: q -> max t (maximum q)

let solve hand =
  let mem = Hashtbl.create 42 in
  let rec solve_aux instance =
    try Hashtbl.find mem instance
    with Not_found ->
      let res = match instance with
        | (_,[]) -> 0
        | (top,hand) ->
           let sous_problemes = all_extract hand in
           let ss_pb_comp =
             List.filter (fun (c, q) -> compatible top c) sous_problemes in
           let sol_ss_pb =
             List.map solve_aux ss_pb_comp in
           1 + maximum sol_ss_pb
      in Hashtbl.add mem instance res; res
  in
  solve_aux ((0, Noir), hand)
