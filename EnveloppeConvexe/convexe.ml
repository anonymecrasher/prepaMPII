open Graphics

type point = int * int

let draw_point (x,y : point) : unit =
  (* dessine un point aux coordonnees x, y *)
  set_color blue;
  fill_circle x y 3;
  set_color black


let get_coord (() : unit) : point =
  (* Attends un clique et renvoie les coordonnees du point *)
  let st = wait_next_event [Button_down] in
  st.mouse_x, st.mouse_y

let rec add_point (p : point) (l : point list) : point list = match l with
  | t :: q when t >= p -> t :: add_point p q
  | l -> p :: l

let top_hull acc points = 

let dessine (l : point list) : unit =
  assert false

let main () =
  open_graph "";
  let points : point list ref = ref [] in
  while true do
    let x = get_coord() in
    draw_point x
  done

let () = main ()
