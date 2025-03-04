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
