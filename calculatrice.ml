let rec n_token string n = 
  if n = 0 then
    (* On cherche le premier token *)
    let i = ref 0 in
    while !i < String.length string && string.[!i] <> ' ' do
      i := !i + 1
    done;
    String.sub string 0 !i
  else
    (* On avance pour ignorer les espaces initiaux *)
    let i = ref 0 in
    while !i < String.length string && string.[!i] = ' ' do
      i := !i + 1
    done;
    (* Maintenant, on est au début du premier token actuel *)
    let start = !i in
    while !i < String.length string && string.[!i] <> ' ' do
      i := !i + 1
    done;
    (* Passer au token suivant en diminuant n de 1 *)
    if !i < String.length string then
      n_token (String.sub string (!i + 1) (String.length string - (!i + 1))) (n - 1)
    else
      ""  (* Retourne une chaîne vide si le n-ième token n'existe pas *)

let moi = "moi1 moi2 moi3"
let moi1 = n_token moi 0  (* Devrait retourner "moi1" *)
let moi2 = n_token moi 1  (* Devrait retourner "moi2" *)
let moi3 = n_token moi 2  (* Devrait retourner "moi3" *) 
                          
(* Fonction principale *)
let calculatrice string = 
  (* Fonction récursive pour analyser et évaluer l'expression *)
  let rec calculatrice_rec string n =
    (* Récupère le token actuel *)
    let actual_token = n_token string n in
    (* Si le token est vide, retourne 0 par défaut *)
    if actual_token = "" then
      0
    (* Si le token est "+", additionne les deux tokens suivants *)
    else if actual_token = "+" then
      (calculatrice_rec string (n + 1)) + (calculatrice_rec string (n + 2))
    (* Si le token est "-", soustrait le deuxième token du premier *)
    else if actual_token = "-" then
      (calculatrice_rec string (n + 1)) - (calculatrice_rec string (n + 2))
    (* Si le token est "*", multiplie les deux tokens suivants *)
    else if actual_token = "*" then
      (calculatrice_rec string (n + 1)) * (calculatrice_rec string (n + 2))
    (* Si le token est "/", divise le premier token par le second *)
    else if actual_token = "/" then
      let denominator = calculatrice_rec string (n + 2) in
      (* Vérifie que le dénominateur n'est pas zéro pour éviter une erreur de division *)
      if denominator = 0 then
        failwith "Division by zero"  (* Lève une erreur si division par zéro *)
      else
        (calculatrice_rec string (n + 1)) / denominator
    else
      (* Si le token est un nombre, le convertit en entier *)
      try int_of_string actual_token
      (* Si le token n'est pas un nombre valide, lève une erreur *)
      with Failure _ -> failwith ("Invalid token: " ^ actual_token)
  in
  (* Appelle la fonction récursive pour évaluer l'expression à partir du premier token *)
  calculatrice_rec string 0

(* Exemple d'utilisation *)
let expression = "+ 3 * 28 4"  (* Ceci représente : 3 + (2 * 4) *)
let result = calculatrice expression  (* Évalue l'expression et stocke le résultat *)
