let pieces = [5;4;3;1]

let rec minimum = function
  | [] -> failwith "Liste vide"
  | [t] -> t
  | a :: b :: c ->  minimum (min a b :: c)

(* let minimum = Foldleft *)


let rendu =
  let mem = Hashtbl.create 1 in
  Hashtbl.add mem 0 0; (* ne depend pas de l'argument du rendu est execute 1 seule fois a la declaration de la fonction *)

  let rec rendu_aux somme =
    try Hashtbl.find mem somme
    with
    | Not_found ->
       let sous_problemes =
         List.map (fun c -> somme - c) pieces in
       let sous_problemes =
         List.filter (fun x -> x >= 0) sous_problemes in
       let res_sous_problemes =
         List.map rendu_aux sous_problemes in
       let res = 1 + minimum res_sous_problemes in
       Hashtbl.add mem somme res; res
  in
  rendu_aux
